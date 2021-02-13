#if 0
mini_start;mini_writes;mini_open;mini_read;mini_exit_errno;mini_usleep
mini_strlcpy;mini_strcpy;mini_strncpy;mini_strdup;mini_stpcpy;
mini_group_write
mini_group_printf

mini_die_if;mini_dies_if;mini_die;mini_dief;mini_mmap

mini_dirbuf;mini_opendir;mini_readdir;mini_dirbuf_malloc malloc_brk;
mini_malloc_brk;mini_free;
mini_execl

mini_match

mini_sigaction
mini_ansicolors;mini_shortcolornames

mini_buf 512

source common.conf

HEADERGUARDS
OPTFLAG -Os
#STRIPFLAG
#LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

#include "udevrd.conf.h"

/*

(c) 2021 AGPLv3 (misc)
Based on minilib, (c) 2012-2021, 'Fair use by attribution'
Michael (misc) Myer (misc.myer@zoho.com, www.github.com/michael105)

Please have a look into the accompanying files LICENSE.agpl and LICENSE.minilib
for the exact licensing terms.


  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

*/

// todo:
// log
// dev down
// removed devices
// argument parsing ( -c, -d, -B )

// dir patterns

// done
// reload config on SIGUSR1
// execute
// notify_dirs->grow (mmap)

int do_reload_config;
int do_exit;

// contains the nfd / directory keys
#define NOTIFY_DIRS 4
typedef struct _notify_dirs{
		p_rel path[NOTIFY_DIRS];
		struct _notify_dirs* next;
		int max;
		int subtract;
		char stringsstart;
} notify_dirs;

typedef struct _globals {
		dev* devices;
		conf *config;
		watchdir_patterns* watchdirlist;
		notify_dirs *ino_dirs;
		char *configfile;
		char *mapping;
		int mappingsize;
		int configfd;
		int nfd;
} globals;


void ino_dir_init( globals *data ){
		data->ino_dirs = mmap( 0, PAGESIZE, PROT_READ|PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		data->ino_dirs->max = NOTIFY_DIRS;
		data->ino_dirs->next = 0; // for clarity
		setaddr( data->ino_dirs->path[0], &data->ino_dirs->stringsstart );
		//setaddr( data->ino_dirs->path[1], &data->ino_dirs->stringsstart );
}


const char* ino_dir_get( int num, globals *data ){
		notify_dirs *nod = data->ino_dirs;
		num-=nod->subtract;
		
		if ( num<0 ) // happens for inotify_rm_watch events
				return(0); // closing the inotify fd didn't work out here
		// so every watch needs to be removed. :/

		printf("Get ino: %d\n", num ); 
		 while( ( num >= nod->max-1) ){ // or addr > map
				 num-= (nod->max-1);
				 if ( nod->next ){
					 	nod = nod->next;
				 } else { // append
						 //die(-14,"No such ino_dir");
						 return(0);
				 }
		 }

		eprintsl( "Got: ", RED, getaddr( nod->path[num] ), NORM );
		return( getaddr( nod->path[num] ) );
}

void ino_dir_destroy( globals *data ){
		notify_dirs *nod = data->ino_dirs;
		for (int a = nod->subtract;ino_dir_get(a,data);a++){
				printf(CYAN"remove: %d\n"NORM, a );
				inotify_rm_watch(data->nfd,a);
		}
		do {
				ewritesl("unmap");
				char *tmp = (char*) nod;
				nod = nod->next;
				munmap( tmp, PAGESIZE );
		} while ( nod );
}

void ino_dir_add( int num, const char* path, globals *data ){

		notify_dirs *nod = data->ino_dirs;
		printf("Append ino: %d - %s\n", num, path ); 
		if ( !nod->subtract ){
				nod->subtract = num;
		}
		num-= nod->subtract;
		printf("Append ino2: %d - %s\n", num, path ); 
		 while( ( num >= nod->max-1) ){ // or addr > map
				 num-= (nod->max-1);
				 if ( nod->next ){
					 	nod = nod->next;
				 } else { // append
						 ewritesl(RED"append mmap"NORM);
						 nod->next = (notify_dirs*)mmap( 0, PAGESIZE, PROT_READ|PROT_WRITE, 
										MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
						 nod = nod->next;
						 nod->max = NOTIFY_DIRS;
						 setaddr( nod->path[0], &nod->stringsstart );
						 break;
				 }
		 }
		if ( nod->path[num+1] )
				dief(0,"ino_dirs: num %d already used!\n",num);

		char *p = stpcpy( getaddr( nod->path[num] ), path );
		p++;
		setaddr(nod->path[num+1],p);
		eprintsl( "appended: ", getaddr( nod->path[num] ) );
}



// returns 0 on error
int apply_dev_rule( const char* fullpath, struct stat *st, dev *device, globals *data ){

		struct stat ststat;
		if ( !st ){
				if ( stat( fullpath, &ststat ) != 0 )
						return(0);
				st = &ststat;
		}

		if ( (st->st_mode & 0777) != device->access ){
				writesl("mode differs");
				chmod( fullpath, device->access );
		}

		if ( (st->st_uid != device->owner ) || ( st->st_gid != device->group ) ){
				writesl("gid");
				chown( fullpath, device->owner, device->group );
		}

		char *s = getstr( device->p_link );
		if ( s[0] ){ // len > 0
				printsl( "link: :", fullpath, " - ", s );
				symlink( fullpath, s );
		}

		return(1);
}

// apply rules on creation
void dev_action( const char* path, dev* device, globals *data ){
		char *s = getstr( device->p_exec );
		if ( s[0] ){ // len > 0
				char buf[256];
				char *p = stpcpy(buf,s);
				*p = ' ';p++;
				strncpy(p,path,(buf+256)-p);
				printsl("Execute: ", buf );
				int pid = vfork();
				if ( pid == 0 ){
						execl( "/bin/sh", "/bin/sh", "-c", buf, (char*)0 );
						eprintsl("Couldn't execute ", buf );
						_exit(1);
				}
		}
}

// returns a matching device rule or zero
dev* get_dev_rule( const char* path, globals *data ){

			for ( dev* device = data->devices; device; device=nextdev(device) ){
				if ( match( (char*)path, getstr(device->p_match),0) ){
						printsl("matched: ",path);
						return( device );
				}
			}

			return(0);
}


int watch_dir(const char* path, globals *data){

		printsl("Add watch to ",path);
		int ir = inotify_add_watch(data->nfd, path, IN_CREATE );
		if ( ir<0 ){ 
				eprintsl("Couldn't add an inotify watch for ", path );
		}
		//data->ino_dirs->path[ir] = (char*)strdup( path );
		ino_dir_add(ir, path, data); 
		printf("inotify fd: %d\n", ir );
		return( ir );
}


int dev_cb(const char* path, struct stat *st, globals *data){
		printsl(" cb: ",path);
		dev *d = get_dev_rule( path, data );
		if ( d ){
				if ( d->matchmode & st->st_mode ){
						if ( d->matchmode & st->st_mode & S_IFDIR ){
								printsl( "cb dir: ",path);
						} else {
								apply_dev_rule( path, st, d, data );
						}
				}
		}

		return(1);
}



int traverse_dir( const char* path, int maxdepth, 
				int(*callback)(const char* path,struct stat *st,globals *data), 
				int(*dir_callback)(const char* path,globals *data), 
				globals *data){
		
		if ( maxdepth-1 == 0 )
				return(0);

		DIR *dir = opendir( path );
		printsl("opendir: ",path);
		if ( !dir )
				return(0);

		struct dirent *de;
		char pathname[PATH_MAX];
		char *p = stpcpy(pathname, path);
		*p='/';
		p++;

		while( ( de = readdir( dir ) ) ){
				//printsl("Path: ",de->d_name);
				if ( de->d_name[0] == '.' ) // skip ., .. and .hidden dirs
						continue;

				struct stat st;
				strcpy( p, de->d_name );
				if ( stat( pathname, &st ) != 0 )
						continue;
				//if ( !(st.st_mode & S_IFDIR) ){ // node, file or link
				if ( callback )
						callback(pathname, &st, data);
				//		continue;
				//}

				if ( st.st_mode & S_IFDIR ){ // node, file or link
						printsl("Directory: ",de->d_name);
						if ( dir_callback )
								dir_callback(pathname, data);
						traverse_dir( pathname, maxdepth-1, callback, dir_callback, data );
				}

		}

		free(dir);
		return(1);
}

// return 0 on success
int load_config( const char* configfile, globals *gl ){

		int fd = open( configfile, O_RDONLY, 0 );
		if( fd<0 ){
				eprintsl( "Couldn't open ", configfile );
				return(fd);
		}

		struct stat ststat;
		fstat(fd, &ststat );
		printf("Size: %d\n", ststat.st_size);
	
		char* mapping = mmap(0,ststat.st_size, PROT_READ, MAP_PRIVATE|MAP_POPULATE, fd, 0 );
		if ( mapping<=(POINTER)0 ){
				ewrites( "Couldn't map into memory" );
				close(fd);
				return( (int)(POINTER)mapping );
		}

		printf( "mgc: %x\n", *(int*)mapping );
		if ( *(int*)mapping != MAGICINT ){
				munmap(mapping, ststat.st_size);
				close(fd);
				eprintsl( "The configuration file doesn't look correct.\n", configfile );
				return(-14);
		}


		// check end of configfile
		dev *d;
		for ( dev *d2 = firstdev(mapping); d2; d2=nextdev(d) )
				d = d2;

		if ( *(int*)(getaddr(d->p_next)+sizeof(p_rel)) != MAGICINT ){
				munmap(mapping, ststat.st_size);
				close(fd);
				eprintsl( "The configuration file is scrambled.\n", configfile );
				return(-14);
		}


		gl->devices = firstdev(mapping);
		gl->config = getconfig(mapping);
		//gl->watchdirlist=(watchdir_patterns*)getaddr(gl->config->p_watchdirlist);
		gl->configfd = fd;
		gl->mapping = mapping;
		gl->mappingsize = ststat.st_size;

		writesl("Configuration loaded\n");
		return(0);
}

// return 1, when reloading the config gives an error
int reload_config( globals *global ){

		globals tmp;
		memcpy(&tmp,global,sizeof(globals));
		if ( load_config( global->configfile, &tmp ) ){
				ewritesl("Couldn't update the config");
				return(1);
		}

		munmap(global->mapping,global->mappingsize);
		close(global->configfd);

		memcpy(global,&tmp,sizeof(globals));

		ino_dir_destroy( global );
		printf("nfd: %d\n",global->nfd);
		//close(global->nfd);

		//int nfd; // inotifyfd
		//nfd = inotify_init();
		//die_if ( nfd<0,nfd,"Couldn't reinitiate inotify." );

		// init globals
		//global->nfd = nfd;
		//printf("nfd: %d\n",global->nfd);

		ino_dir_init(global);

		// watch devpath
		//watch_dir( getstr(global->config->p_devpath), global );

		// traverse the entire dev hierarchy and apply matching rules
		//traverse_dir( getstr(global->config->p_devpath),10,&dev_cb,&watch_dir, global );


		return(0);
}


// handle SIGUSR1
// reload config
void sighandler( int signal ){
		switch (signal){ 
				case SIGUSR1:
						writesl("sigusr1");
						do_reload_config = 1; // reload config
						break;
				case SIGTERM:
						writesl("Got SIGTERM");
						do_exit = 1;
						break;
		}
}


int main( int argc, char **argv ){
		
		// read configuration
		char *configfile = COMPILEDCONFIG;
	
		// set by the signal handler
		do_reload_config = 0;
		do_exit = 0;


		globals data;
		//global = &data;
		int r;
	
		die_if( (r = load_config(configfile, &data) ) != 0, r, "Error. exit" );

		// initiate inotify
		int nfd; // inotifyfd
		nfd = inotify_init();
		die_if ( nfd<0,nfd,"Couldn't initiate inotify. No kernel support?" );

		// init globals
		data.nfd = nfd;
		data.configfile = configfile;
		//notify_dirs nod;
		//nod.max = NOTIFY_DIRS;
		//nod.next = 0;
		//data.ino_dirs = &nod;
		ino_dir_init(&data);
		notify_dirs *nod = data.ino_dirs;


		// watch devpath
		watch_dir( getstr(data.config->p_devpath), &data );

		// traverse the entire dev hierarchy and apply matching rules
		traverse_dir( getstr(data.config->p_devpath),10,&dev_cb,&watch_dir, &data );

		// setup signal handler
		struct sigaction sa;

		sigfillset(&sa.sa_mask);
		sa.sa_flags = 0;
		sa.sa_handler = sighandler;

		if ( sigaction (SIGUSR1, &sa, 0) || sigaction (SIGTERM, &sa, 0) )
				ewrites("Couldn't install signal handler");
		// continue anyways.

		

#define BUFLEN 1024
		char buf[BUFLEN];
		writesl("Ok");
		const struct inotify_event *e;
		char path[PATH_MAX];

		while ( !do_exit ){

				while ( (r=read(nfd,buf,BUFLEN)) <= 0 ){
						// got signal or another interruption
						if ( do_exit )
								break;

						if ( do_reload_config ){ // got sigusr1
								reload_config( &data );
								do_reload_config = 0;

								// watch devpath
								watch_dir( getstr(data.config->p_devpath), &data );

								// traverse the entire dev hierarchy and apply matching rules
								traverse_dir( getstr(data.config->p_devpath),10,&dev_cb,&watch_dir, &data );


						} else {
										usleep(100000); // ~ 1/10 second delay.
						}
				}

				// loop over events
				for ( char *p = buf; p < buf+r;	p += sizeof(struct inotify_event) + e->len) {
						e = (const struct inotify_event *) p;
						if ( e->wd < data.ino_dirs->subtract )
								continue; // got an event of a removed watch
						printsl( "event: ", e->name );
						//char *c = stpcpy( path, nod.path[e->wd] );
						char *c = stpcpy( path, ino_dir_get(e->wd,&data) );
						//char *c = "              ";
						*c = '/';
						c++;
						strcpy( c, e->name );
						if ( e->mask & IN_ISDIR ){
								writesl("  directory");
								watch_dir( path, &data );
						} 
						writesl(" matching ");
						dev* d = get_dev_rule( path, &data );
						if ( d ){ //match
								apply_dev_rule( path, 0, d, &data );
								dev_action( path, d, &data );
						}
				}

		}

		// exit
		writesl("Got SIGTERM. Exit.\n");
		return(0);
}

