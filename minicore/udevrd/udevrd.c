#if 0
mini_start;mini_writes;mini_open;mini_read;mini_exit_errno;mini_usleep
mini_strlcpy;mini_strcpy;mini_strncpy;mini_strdup;mini_stpcpy;
mini_group_write
mini_group_printf
mini_itohex;
mini_itoHEX;


mini_die_if;mini_dies_if;mini_die;mini_dief;mini_mmap

mini_dirbuf;mini_opendir;mini_readdir;mini_dirbuf_malloc malloc_brk;
mini_malloc_brk;mini_free;
mini_execl

mini_match

mini_sigaction
mini_ansicolors;mini_shortcolornames

mini_snprintfs
mini_stpncpy
mini_stplcpy

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
#include "log.h"

//extern char* _binary_udevrd_conf_bin_start;
//extern char* _binary_udevrd_conf_bin_end;

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
// embed config


// done
// reload config on SIGUSR1
// execute
// notify_dirs->grow (mmap)
// dir patterns


int do_reload_config;
int load_embedded_config;
int do_exit;



// how many directories per (preallocated) page
// -> (PAGESIZE/16) = 256 for 4kB pages.
// each path can be in the medium (PAGESIZE-4*256 - 20)/256 Bytes.
// The notify dirlist ist dynamically grown.
#define NOTIFY_DIRS (PAGESIZE/16)

// contains the nfd / directory keys
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
}


const char* ino_dir_get( int num, globals *data ){
		notify_dirs *nod = data->ino_dirs;
		num-=nod->subtract;
		
		if ( num<0 ) // happens for inotify_rm_watch events
				return(0); // closing the inotify fd didn't work out here
		// so every watch needs to be removed. :/

		dbgf("Get ino: %d\n", num ); 
		 while( ( num >= nod->max-1) ){ // or addr > map
				 num-= (nod->max-1);
				 if ( nod->next ){
					 	nod = nod->next;
				 } else { // append
						 //die(-14,"No such ino_dir");
						 return(0);
				 }
		 }

		dbgs( "Got: ", RED, getaddr( nod->path[num] ), NORM );
		return( getaddr( nod->path[num] ) );
}

void ino_dir_destroy( globals *data ){
		notify_dirs *nod = data->ino_dirs;
		for (int a = nod->subtract;ino_dir_get(a,data);a++){
				dbgf(CYAN"remove: %d\n"NORM, a );
				inotify_rm_watch(data->nfd,a);
		}
		do {
				dbg("unmap");
				char *tmp = (char*) nod;
				nod = nod->next;
				munmap( tmp, PAGESIZE );
		} while ( nod );
}

notify_dirs *ino_dir_addmapping( notify_dirs* nod ){
		nod->next = (notify_dirs*)mmap( 0, PAGESIZE, PROT_READ|PROT_WRITE, 
						MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		nod = nod->next;
		nod->max = NOTIFY_DIRS;
		setaddr( nod->path[0], &nod->stringsstart );
		return(nod);
}

void ino_dir_add( int num, const char* path, globals *data ){

		notify_dirs *nod = data->ino_dirs;
		dbgf("Append ino: %d - %s\n", num, path ); 
		if ( !nod->subtract ){
				nod->subtract = num;
		}
		num-= nod->subtract;
		dbgf("Append ino2: %d - %s\n", num, path ); 

		 while( ( num >= nod->max-1) ){
				dbgf("num: %d  max: %d\n", num, nod->max );
				 num-=nod->max-1;
				 if ( nod->next ){
					 	nod = nod->next;
				 } else { // append
						 dbg(RED"append mmap"NORM);
						 //goto newmap;
						 nod = ino_dir_addmapping(nod);
						 break;
				 }
		 }
		if ( nod->path[num+1] )
				dief(0,"ino_dirs: num %d already used!\n",num);
	
		if ( (int)( (nod->path[num] - sizeof(notify_dirs)) + sizeof(p_rel) + strlen(path))>= PAGESIZE ) {  

				dbg(RED"mmap"NORM);
				dbgf("num: %d  max: %d  nod->path: %d\n", num, nod->max, nod->path[num] );
					nod->max = num+1; // addr > map
					num = 0;
//newmap:
				nod = ino_dir_addmapping(nod);

				dbgf("num: %d  max: %d  nod->path: %d\n", num, nod->max, nod->path[num] );
		}


		char *p = stpcpy( getaddr( nod->path[num] ), path );
		p++;
		setaddr(nod->path[num+1],p);
		dbgs( "appended: ", getaddr( nod->path[num] ) );
}



// returns 0 on error
int apply_dev_rule( const char* fullpath, struct stat *st, dev *device, globals *data ){

		logs(2,"apply rule to ",fullpath);
		struct stat ststat;
		if ( !st ){
				if ( lstat( fullpath, &ststat ) != 0 )
						return(0);
				st = &ststat;
		}

		if ( (st->st_mode & 0777) != device->access ){
				logf(3,"chmod: %o\n",device->access);
				warnif(chmod( fullpath, device->access ), "Couldn't set access rights");
		}

		if ( (st->st_uid != device->owner ) || ( st->st_gid != device->group ) ){
				logf(3,"change id: %d:%d\n",device->owner,device->group);
				warnif(chown( fullpath, device->owner, device->group ), "Couldn't change owner");
		}

		char *s = getstr( device->p_link );
		if ( s[0] ){ // len > 0
				logs( 3, "link: ", fullpath, " - ", s );
				warnif(symlink( fullpath, s ),"Couldn't create symbolic link");
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
				logs(2,"Execute: ", buf );
				int pid = vfork();
				if ( pid == 0 ){
						if ( setgid( device->exec_gid ) )
								warning("Couldn't set the gid");
						if ( setuid( device->exec_uid ) )
								warning("Couldn't set the uid");

						execl( "/bin/sh", "/bin/sh", "-c", buf, (char*)0 );
						warnings("Couldn't execute ", buf );
						_exit(1);
				}
		}
}

#define MODMASK 0170000
// returns a matching device rule or zero
dev* get_dev_rule( const char* path, struct stat *st, globals *data ){

		struct stat ststat;
		if ( !st ){
				if ( lstat( path, &ststat ) != 0 )
						return(0);
				st = &ststat;
				dbgf("stat in devrule: %s  %o  %x\n",path,st->st_mode,st->st_mode);
		}

		for ( dev* device = data->devices; device; device=nextdev(device) ){
				if ( match( (char*)path, getstr(device->p_match),0) ){ // pattern match
						dbgf(LGREEN" st_mode: %X  matchmode: %X  pattern:%s\n"NORM,
										st->st_mode,device->matchmode, getaddr(device->p_match));

						if (device->matchmode & 040000000){ // matchall (*)
								dbg("matchall");
								return(device);
						}

						if ( !(( st->st_mode & MODMASK ) ^ S_IFDIR )){ // is a directory
								dbg("isdir");
								if ( !((device->matchmode & MODMASK ) ^ S_IFDIR ) ){
										dbgs(LBLUE"matched, directory: ",path,NORM);
										return( device );
								}
						} else { // not a directory

								dbg("no mcdir");
								if (device->matchmode & 020000000){ // matchall but dir (x)
										dbg("x");
										return(device);
								}

								if (device->matchmode & 010000000){ // match dev (block|char)
										if ( st->st_mode & 060000 ){ // block or char
												dbg("match dev");
												return(device);
										}
								}

								if ( ((device->matchmode & MODMASK ) ^ S_IFDIR ) ){ // don't match for dir
										if ( !((st->st_mode & MODMASK) ^ ( device->matchmode & MODMASK )) ){ // match ino type
												dbgs(CYAN"matched: ",path,NORM);
												dbgf(" st_mode: %x  matchmode: %x\n",st->st_mode,device->matchmode);
												return( device );
										}
								}
						}
				} // pattern match
		} // for
		dbg(MAGENTA"No Match"NORM);

		return(0);
}


int watch_dir(const char* path, globals *data){

		dbgs("Add watch to ",path);
		int ir = inotify_add_watch(data->nfd, path, IN_CREATE );
		if ( ir<0 ){ 
				warnings("Couldn't add an inotify watch for ", path );
		}
		//data->ino_dirs->path[ir] = (char*)strdup( path );
		ino_dir_add(ir, path, data); 
		dbgf("inotify fd: %d\n", ir );
		return( ir );
}

int traverse_dir( const char* path, int maxdepth, 
				dev*(*callback)(const char* path,struct stat *st,int maxdepth,globals *data), 
				int(*dir_callback)(const char* path,globals *data), 
				globals *data);


dev* dev_cb(const char* path, struct stat *st, int maxdepth, globals *data){
		dbgs(" cb: ",path);

		struct stat ststat;
		if ( !st ){
				if ( lstat( path, &ststat ) != 0 )
						return(0);
				st = &ststat;
				dbgf("stat in callback %s  %o  %x\n",path,st->st_mode,st->st_mode);
		}

		dev *d = get_dev_rule( path, st, data );
		if ( d ){
				logs(2, LGREEN"matched rule: ", getstr(d->p_match),NORM);
				dbgf("matchmode: %x\n",d->matchmode);
				//if ( d->matchmode & st->st_mode ){
						if ( !((st->st_mode & MODMASK ) ^ S_IFDIR )){ // is dir
								dbgs( "cb dir: ",path);

								if ( d->matchmode & 01000000 ) 
										apply_dev_rule( path, st, d, data );

								if ( maxdepth == 0 )
										return(d);
								watch_dir(path,data);
								int r = 1;
								if ( d->matchmode & 04000000 )
										r=-1;
								if ( d->matchmode & 06000000 )
										traverse_dir( path, r, &dev_cb, &watch_dir, data ); 

						} else {
								apply_dev_rule( path, st, d, data );
						}
				//}
		}

		return(d);
}



int traverse_dir( const char* path, int maxdepth, 
				dev*(*callback)(const char* path,struct stat *st,int maxdepth,globals *data), 
				int(*dir_callback)(const char* path,globals *data), 
				globals *data){
		
		if ( maxdepth == 0 )
				return(0);
		maxdepth--;

		DIR *dir = opendir( path );
		dbgs("opendir: ",path);
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
				if ( lstat( pathname, &st ) != 0 )
						continue;

				if ( callback )
						callback(pathname, &st, maxdepth, data);
		}

		free(dir);
		return(1);
}

// return 0 on success
int load_config( const char* configfile, globals *gl ){
		log(1,"load config");
		int fd = open( configfile, O_RDONLY, 0 );
		if( fd<0 ){
				errors( "Couldn't open config: ", configfile );
				return(fd);
		}
		// prevent raceconditions
		flock(fd,LOCK_EX);

		struct stat ststat;
		fstat(fd, &ststat );
		dbgf("Size: %d\n", ststat.st_size);
	
		char* mapping = mmap(0,ststat.st_size, PROT_READ, MAP_PRIVATE|MAP_POPULATE, fd, 0 );
		if ( mapping<=(POINTER)0 ){
				errors( "Couldn't map into memory" );
				close(fd);
				return( (int)(POINTER)mapping );
		}

		dbgf( "mgc: %x\n", *(int*)mapping );
		if ( *(int*)mapping != MAGICINT ){
				munmap(mapping, ststat.st_size);
				close(fd);
				errors( "The configuration file doesn't look correct.\n", configfile );
				return(-14);
		}


		// check end of configfile
		dev *d;
		for ( dev *d2 = firstdev(mapping); d2; d2=nextdev(d) )
				d = d2;

		if ( *(int*)(getaddr(d->p_next)+sizeof(p_rel)) != MAGICINT ){
				munmap(mapping, ststat.st_size);
				close(fd);
				errors( "The configuration file is scrambled.\n", configfile );
				return(-14);
		}


		gl->devices = firstdev(mapping);
		gl->config = getconfig(mapping);
		//gl->watchdirlist=(watchdir_patterns*)getaddr(gl->config->p_watchdirlist);
		gl->configfd = fd;
		gl->mapping = mapping;
		gl->mappingsize = ststat.st_size;

		log(2,"Configuration loaded\n");
		flock(fd,LOCK_UN);

		return(0);
}

// return 1, when reloading the config gives an error
int reload_config( globals *global ){

		globals tmp;
		memcpy(&tmp,global,sizeof(globals));
		if ( load_config( global->configfile, &tmp ) ){
				warning("Couldn't reload the config");
				return(1);
		}

		munmap(global->mapping,global->mappingsize);
		close(global->configfd);

		memcpy(global,&tmp,sizeof(globals));

		ino_dir_destroy( global );
		
#if 0
		printf("nfd: %d\n",global->nfd);

		close(global->nfd);

		int nfd; // inotifyfd
		nfd = inotify_init();
		die_if ( nfd<0,nfd,"Couldn't reinitiate inotify." );

		// init globals
		global->nfd = nfd;
		printf("nfd: %d\n",global->nfd);
#endif

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
						log(2,"sigusr1");
						do_reload_config = 1; // reload config
						break;
				case SIGUSR2:
						log(2,"sigusr2");
						load_embedded_config = 1; // reload config
						break;

				case SIGTERM:
						log(2,"Got SIGTERM");
						do_exit = 1;
						break;
				case SIGINT:
						log(2,"Got SIGINT");
						do_exit = 1;
						break;
		}
}


int main( int argc, char **argv ){

		initlog(KERNEL|STDOUT,"udevrd",3);
		setloglevel(KERNEL,1);
		setloglevel(STDOUT,3);

		log(1,"Starting udevrd");
		
		// read configuration
		char *configfile = COMPILEDCONFIG;

		if ( argc>2 ){
				if ( argv[1][0] == '-' && argv[1][1] == 'c' )
						configfile = argv[2];
		}
	
		// set by the signal handler
		do_reload_config = 0;
		load_embedded_config = 0;
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

		if ( sigaction (SIGUSR1, &sa, 0) || sigaction (SIGTERM, &sa, 0) ||
				  sigaction (SIGUSR2, &sa, 0) || sigaction (SIGINT, &sa, 0) )
				ewrites("Couldn't install signal handler");
		// continue anyways.

		

#define BUFLEN 1024
		char buf[BUFLEN];
		dbg("Ok");
		const struct inotify_event *e;
		char path[PATH_MAX];

		while ( !do_exit ){

				while ( (r=read(nfd,buf,BUFLEN)) <= 0 ){
						// got signal or another interruption
						if ( do_exit )
								break;

#if 0
						if ( load_embedded_config ){
								char* mapping = _binary_udevrd_conf_bin_start;
								data.devices = firstdev(mapping);
								data.config = getconfig(mapping);
								data.configfd = 0;
								data.mapping = mapping;
								data.mappingsize = 0;
								load_embedded_config = 0;
						}
#endif



						if ( do_reload_config ){ // got sigusr1
								log(2,"Reload configuration");
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

						dbgs( "event: ", e->name );
						char *c = stpcpy( path, ino_dir_get(e->wd,&data) );
						*c = '/';
						c++;
						strcpy( c, e->name );
						dbg(" matching ");

						dev* d = dev_cb( path, 0, -1, &data ); // todo. wrong. slightly
						if ( d ){ //match
								dbg("back");
								//apply_dev_rule( path, 0, d, &data );
								dev_action( path, d, &data );
						}
				}

		}

		// exit
		log(1,"Exit.\n");
		return(0);
}

