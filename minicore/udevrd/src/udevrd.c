

#ifndef MLIB
#include "../../../syntaxcheck.h"
#endif

#include "udevrd.conf.h"
#include "log.h"


void usage(){
		writes("udevrd [-c configfile] [-e] [-h] [-d] [-B]\n\
\n\
The daemon handles devices in /dev.\n\
\n\
Please have a look into the configfile for the possible options.\n\
\n\
arguments:\n\
 -h  show this help\n\
 -d  write verbose output to stdout/stderr\n\
 -dd write more verbose output to stdout/stderr\n\
 -B  daemonize (detach from parent)\n\
 -c  configfile\n\
     use another file than the default ("COMPILEDCONFIG")\n\
 -e  use the embedded configfile\n\
 \n\
The configuration has to be compiled with udevrd-update.sh\n\
Please have a look into the readme for further information.\n\
\n\
(c) 2021 Michael (misc) Myer, AGPLv3\n\
Based on minilib (c) 2012-2021 misc.\n\
" );

		exit(0);
}


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
// removed devices



// set by the signal handler
// used to communicate with the main loop
enum _signalled { NOACTION, SIG_EXIT, SIG_RELOAD_CONFIG, SIG_LOAD_EMBEDDEDCONFIG } signalled;



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
        // dynamic string section starts here
		char stringsstart[0];
} notify_dirs;

typedef struct _globals {
		dev* devices;
		conf *config;
		watchdir_patterns* watchdirlist;
		notify_dirs *ino_dirs;
		char *configfile;
		char *argv0; // needed to load embedded config
		char *mapping;
		int embeddedconfig;
		int mappingsize;
		int configfd;
		int nfd;
} globals;


void ino_dir_init( globals *data ){
		data->ino_dirs = mmap( 0, PAGESIZE, PROT_READ|PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		data->ino_dirs->max = NOTIFY_DIRS;
		data->ino_dirs->next = 0; // for clarity
		setaddr( data->ino_dirs->path[0], data->ino_dirs->stringsstart );
}


const char* ino_dir_get( int num, globals *data ){
		notify_dirs *nod = data->ino_dirs;
		num-=nod->subtract;
		
		if ( num<0 ) // happens for inotify_rm_watch events
				return(0); // closing the inotify fd didn't work out here
		// so every watch needs to be removed when reloading the config :/

		 while( ( num >= nod->max-1) ){ // or addr > map
				 num-= (nod->max-1);
				 if ( nod->next ){
					 	nod = nod->next;
				 } else { // append
						 //die(-14,"No such ino_dir");
						 return(0);
				 }
		 }

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
		setaddr( nod->path[0], nod->stringsstart );
		return(nod);
}

// append a path. num MUST be sequential
void ino_dir_add( int num, const char* path, globals *data ){

		notify_dirs *nod = data->ino_dirs;
		
		if ( !nod->subtract ){
				nod->subtract = num;
		}
		num-= nod->subtract;

		 while( ( num >= nod->max-1) ){
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
				nod->max = num+1; // addr > map
                num = 0;
				nod = ino_dir_addmapping(nod);
		}


		char *p = stpcpy( getstr( nod->path[num] ), path );
		p++;
		setaddr(nod->path[num+1],p);
		//dbgs( "appended: ", getaddr( nod->path[num] ) );
}



// returns 0 on error
int apply_dev_rule( const char* fullpath, struct stat *st, dev *device, globals *data ){

		logs(2,"apply rule to ",fullpath);
		struct stat ststat;
		if ( !st ){
				if ( lstat( fullpath, &ststat ) != 0 ){
						warnings("Couldn't stat ",fullpath);
						return(0);
				}
				st = &ststat;
		}

		if ( (st->st_mode & 0777) != device->access ){
				logf(3,"chmod: %o",device->access);
				warns_if(chmod( fullpath, device->access ), "Couldn't set access rights for ",fullpath);
		}

		if ( (st->st_uid != device->owner ) || ( st->st_gid != device->group ) ){
				logf(3,"change id: %d:%d",device->owner,device->group);
				warns_if(chown( fullpath, device->owner, device->group ), "Couldn't change owner of ",fullpath);
		}

		char *s = getstr( device->p_link );
		if ( s[0] ){ // len > 0
				logs( 3, "link: ", fullpath, " - ", s );
				// TODO: unlink old link
				warns_if(symlink( fullpath, s ),"Couldn't create symbolic link: ",fullpath," -> ",s);
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
				if ( lstat( path, &ststat ) != 0 ){
						warnings("Couldn't stat ",path);
						return(0);
				}
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

		logs(3,"Add watch to ",path);
		int ir = inotify_add_watch(data->nfd, path, IN_CREATE );
		if ( ir<=0 ){ 
				warnings("Couldn't add an inotify watch to ", path );
		} else {
		//data->ino_dirs->path[ir] = (char*)strdup( path );
				ino_dir_add(ir, path, data); 
				dbgf("inotify fd: %d\n", ir );
		}
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
				if ( lstat( path, &ststat ) != 0 ){
						warnings("Couldn't stat ",path);
						return(0);
				}		
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
								int r = 1; // no recursions, just scan the directory
								if ( d->matchmode & 04000000 )
										r=maxdepth;
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
				if ( lstat( pathname, &st ) != 0 ){
						logs(3, "Couldn't stat ",pathname);
						continue;
				}

				if ( callback )
						callback(pathname, &st, maxdepth, data);
		}

		free(dir);
		return(1);
}

// seek to embedded config
int seekfile(int fd,int *offset){
	int size = lseek( fd, 0, SEEK_END );
	int fsize = lseek( fd, size-8, SEEK_SET );
	int len,c;
	read(fd,(char*)&len,4);
	int r = read(fd,(char*)&c,4);

	//fprintf(stderr,"len: %d\n",len);
	if ( r!=4 || ( len > fsize ) || c!=0x5041 ){
		return(-1);
	}

	lseek( fd, size-8-len, SEEK_SET );
	*offset = size-8-len;
	return(len);
}


// return 0 on success
int load_config( globals *gl ){
		
		log(1,"Load config");
	
		char *mapping = 0;
		int fd;

		struct stat ststat;


		if ( !gl->embeddedconfig ){
		
				logs(2,"load ",gl->configfile);
				fd = open( gl->configfile, O_RDONLY, 0 );
				if( fd<0 ){
						errors( "Couldn't open config: ", gl->configfile );
						return(fd);
				}
	
				// prevent raceconditions
				flock(fd,LOCK_EX);

				fstat(fd, &ststat );
				dbgf("Size: %d\n", ststat.st_size);

				mapping = mmap(0,ststat.st_size, PROT_READ, MAP_PRIVATE|MAP_POPULATE, fd, 0 );
				gl->mappingsize = ststat.st_size;

		} else { // use embedded config
				log(2,"Load embedded config");
				fd = open( gl->argv0, O_RDONLY, 0 );
				if( fd<0 ){
						errors( "Couldn't load an embedded config." );
						return(fd);
				}
	
				// prevent raceconditions
				flock(fd,LOCK_EX);

				int offset;
				int len = seekfile(fd,&offset);
				if ( len<0 ){
						error("Error. No configuration embedded.\n");
						exit(-1);
				}
				// prevent raceconditions
				flock(fd,LOCK_EX);

				dbgf("offset: %d  len: %d\n",offset,len);
				mapping = mmap(0,len, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0 );
				gl->mappingsize = len;

				int l;
				char *p = mapping;
				do {
					l=len;
					if ( len > 4096 )
						l=4096;
					l=read(fd,mapping,l);
					len-=l;
					p+=4096;
				} while ( len>0 && l );

		}

		if ( mapping<=(POINTER)0 ){
				errors( "Couldn't map into memory" );
				close(fd);
				return( (int)(POINTER)mapping );
		}

				dbgf( "mgc: %x\n", *(int*)mapping );

		if ( *(int*)mapping != MAGICINT ){
				munmap(mapping, ststat.st_size);
				close(fd);
				error( "The configuration doesn't look correct." );
				return(-14);
		}


		// check end of configfile
		dev *d;
		for ( dev *d2 = firstdev(mapping); d2; d2=nextdev(d) )
				d = d2;

		if ( *(int*)(getaddr(d->p_next)+sizeof(p_rel)) != MAGICINT ){
				munmap(mapping, ststat.st_size);
				close(fd);
				error( "The configuration is scrambled." );
				return(-14);
		}


		gl->devices = firstdev(mapping);
		gl->config = getconfig(mapping);
		//gl->watchdirlist=(watchdir_patterns*)getaddr(gl->config->p_watchdirlist);
		gl->configfd = fd;
		gl->mapping = mapping;

		log(2,"Configuration loaded\n");
		flock(fd,LOCK_UN);

		return(0);
}

// return 1, when reloading the config gives an error
int reload_config( globals *global ){
		
		log(1,"Load configuration");

		globals tmp;
		memcpy(&tmp,global,sizeof(globals));
		if ( load_config( &tmp ) ){
				error("Couldn't reload the configuration.");
				return(1);
		}

		munmap(global->mapping,global->mappingsize);
		close(global->configfd);

		memcpy(global,&tmp,sizeof(globals));

		ino_dir_destroy( global );
		
#if 0
		// didn't work out here.
		// adding the same watches again 
		// gave no notifications. (?)
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
		watch_dir( getstr(global->config->p_devpath), global );

		// traverse the entire dev hierarchy and apply matching rules
		traverse_dir( getstr(global->config->p_devpath),global->config->maxrecursion,&dev_cb,&watch_dir, global );


		return(0);
}


// handle SIGUSR1
// reload config
void sighandler( int signal ){
		switch (signal){ 
				case SIGUSR1:
						log(2,"sigusr1");
						//do_reload_config = 1; // reload config
						signalled = SIG_RELOAD_CONFIG;
						break;
				case SIGUSR2:
						log(2,"sigusr2");
						//load_embedded_config = 1; // reload config
						signalled = SIG_LOAD_EMBEDDEDCONFIG;
						break;

				case SIGTERM:
						log(2,"Got SIGTERM");
						//do_exit = 1;
				case SIGINT:
						log(2,"Got SIGNAL - exit");
						//do_exit = 1;
						signalled = SIG_EXIT;
						break;
		}
}


int main( int argc, char **argv ){
		
		// init globals
		globals data;
		data.configfile = COMPILEDCONFIG;
		data.embeddedconfig = 0;
		data.argv0 = argv[0]; // needed for the embedded config
	
		// set by the signal handler
		signalled = 0;

		// parse arguments
		int loglevel = 1;
		int daemonize = 0;
		for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
				for ( const char *arg = argv[0]+1; *arg!= 0; arg++ ){
						if ( *arg == 'c' ){
								*argv++;
								if ( !*argv ){
										error("missing filename for '-c'\n");
										usage();
								}
								data.configfile = *argv;
								break; // continue with the next argv (outer loop)
						} else {
								switch ( *arg ){
								case 'e':
										data.embeddedconfig = 1;
										continue;
								case 'd':
										loglevel++;
										continue;
								case 'B':
										daemonize = 1;
										continue;

								default:
										eprints( "Unknown option: ", *argv, "\n\n" );
								case 'h':
										usage();
								}
						}
				}
		}

		// Optionally daemonize
		if ( daemonize ){
				writes("Daemonize\n");

				int pid = fork();
				die_if( (pid < 0), EXIT_FAILURE, "Couldn't fork" );
				if (pid > 0)
						exit(EXIT_SUCCESS);

				// become session leader
				die_if( (setsid() < 0), EXIT_FAILURE, "Couldn't become session leader");

				pid = fork();
				die_if( (pid < 0), EXIT_FAILURE, "Couldn't fork" );
				if (pid > 0)
						exit(EXIT_SUCCESS);

				umask(0);

				// Change working directory 
				// doesn't work out with argv0 for the embedded config
				//chdir("/");
		}
		
		// init logging
		initlog(KERNEL|STDOUT,"udevrd",3);
		setloglevel(KERNEL,1);
		setloglevel(STDOUT,loglevel);

		log(1,"Starting udevrd");

		if ( daemonize ){
				log(1,"Detach from terminal");
				// close stdin,err,out
				close(2);
				close(1);
				close(0);
		}

		log(3,"arguments parsed");

		// Load configuration
		int r;
		die_if( (r = load_config(&data) ) != 0, r, "Unable to load the configuration. exit" );
	
		// setup signal handlers
		struct sigaction sa;
		sigfillset(&sa.sa_mask);
		sa.sa_flags = 0;
		sa.sa_handler = sighandler;

		if ( sigaction (SIGUSR1, &sa, 0) || sigaction (SIGTERM, &sa, 0) ||
				  sigaction (SIGUSR2, &sa, 0) || sigaction (SIGINT, &sa, 0) )
				error("Couldn't setup signal handler");
		// continue anyways.
		// The signal handlers do trigger reloading the configuration and exit -
		// we can live without that


		// initiate inotify
		int nfd; // inotifyfd
		nfd = inotify_init();
		die_if ( nfd<0,nfd,"Couldn't initiate inotify. No kernel support?" );

		data.nfd = nfd;

		ino_dir_init(&data);
		notify_dirs *nod = data.ino_dirs;

		// watch devpath
		watch_dir( getstr(data.config->p_devpath), &data );

		// traverse the entire dev hierarchy and apply matching rules
		traverse_dir( getstr(data.config->p_devpath),data.config->maxrecursion,&dev_cb,&watch_dir, &data );

		log(1,"Running.");

#define BUFLEN 1024
		char buf[BUFLEN];
		dbg("Ok");
		const struct inotify_event *e;
		char path[PATH_MAX];

		// ========== main loop 
		while ( 1 ){
				// read inotify events
				while ( (r=read(nfd,buf,BUFLEN)) <= 0 ){
						// got signal or another interruption (r<=0)
						switch ( signalled ){
								case SIG_EXIT:
										log(1,"Exit");
										goto exitloop;

								case SIG_LOAD_EMBEDDEDCONFIG:
										log(1,"Signalled - Load embedded config");
										data.embeddedconfig = 1;
										reload_config( &data );
										signalled = 0;
										break;
								case SIG_RELOAD_CONFIG:// got sigusr1
										log(1,"Signalled - Load config");
										data.embeddedconfig = 0;
										reload_config( &data );
										signalled = 0;
										break;

								default: // another interruption
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

exitloop:
		// exit
		log(1,"Exit.\n");
		return(0);
}

