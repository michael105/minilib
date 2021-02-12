#if 0
mini_start
mini_writes
mini_open
mini_read
mini_exit_errno

mini_usleep
mini_strlcpy
mini_strcpy
mini_strdup
mini_stpcpy

mini_group_write
mini_group_printf

mini_die_if
mini_dies_if

mini_mmap

mini_dirbuf
mini_opendir
mini_readdir
mini_dirbuf_malloc malloc_brk
mini_malloc_brk
mini_free

mini_match

mini_sigaction


# needed that "big" for the notifyfd/pathname array. fix it.
mini_buf 4096

HEADERGUARDS
OPTFLAG -Os
#STRIPFLAG
#LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

#include "udevrd.conf.h"


// todo:
// log
// notify_dirs->grow
// execute
// dev down
// reload config on SIGUSR1
// removed devices


// contains the nfd / directory keys
#define NOTIFY_DIRS 64
typedef struct _notify_dirs{
		char* path[NOTIFY_DIRS];
		struct _notify_dirs* next;
		int max;
} notify_dirs;


typedef struct _globals {
		dev* devices;
		conf *config;
		notify_dirs *ino_dirs;
		char *configfile;
		char *mapping;
		int mappingsize;
		int configfd;
		int nfd;
} globals;

globals *global;



// returns 0 on error
int apply_dev_rule( const char* path, struct stat *st, dev *device, globals *data ){

		struct stat ststat;
		if ( !st ){
				if ( stat( path, &ststat ) != 0 )
						return(0);
				st = &ststat;
		}

		if ( (st->st_mode & 0777) != device->access ){
				printsl("mode differs");
				chmod( path, device->access );
		}

		if ( (st->st_uid != device->owner ) || ( st->st_gid != device->group ) ){
				writesl("gid");
				chown( path, device->owner, device->group );
		}


		return(1);
}

// apply rules on creation
void dev_action( const char* path, dev* device, globals *data ){
		char *s = getstr( device->p_exec );
		if ( s[0] ){ // len > 0
				printsl("Execute: ", s, " ", path );
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


int dev_cb(const char* path, struct stat *st, globals *data){
		printsl(" cb: ",path);
		dev *d = get_dev_rule( path, data );
		if ( d )
				apply_dev_rule( path, st, d, data );

		return(1);
}


int watch_dir(const char* path, globals *data){

		printsl("Add watch to ",path);
		int ir = inotify_add_watch(data->nfd, path, IN_CREATE );
		if ( ir<0 ){ 
				eprintsl("Couldn't add an inotify watch for ", path );
		}
		data->ino_dirs->path[ir] = strdup( path );
		printf("inotify fd: %d\n", ir );
		return( ir );
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
				if ( !(st.st_mode & S_IFDIR) ){ // node, file or link
						if ( callback )
								callback(pathname, &st, data);
						continue;
				}

				printsl("Directory: ",de->d_name);
				if ( dir_callback )
						dir_callback(pathname, data);

				traverse_dir( pathname, maxdepth-1, callback, dir_callback, data );

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
		if ( *(int*)mapping != 0x76656475 ){
				munmap(mapping, ststat.st_size);
				close(fd);
				eprintsl( "The configuration file doesn't look correct.\n", configfile );
				return(-14);
		}

		gl->devices = firstdev(mapping);
		gl->config = getconfig(mapping);
		gl->configfd = fd;
		gl->mapping = mapping;
		gl->mappingsize = ststat.st_size;

		writesl("ok\n");
		return(0);
}

// return 1, when reloading the config gives an error
int reload_config(){

		globals tmp;
		memcpy(&tmp,global,sizeof(globals));
		if ( load_config( global->configfile, &tmp ) ){
				ewritesl("Couldn't update the config");
				return(1);
		}

		munmap(global->mapping,global->mappingsize);
		close(global->configfd);

		memcpy(global,&tmp,sizeof(globals));
		return(0);
}


// handle SIGUSR1
// reload config
void sigusr1( int signal ){
		writesl("sigusr1");
		reload_config();
}


int main( int argc, char **argv ){
		
		// read configuration
		char *configfile = CONFIGFILE;
	
		globals data;
		global = &data;
		int r;
	
		die_if( (r = load_config(configfile, &data) ) != 0, r, "Error. exit" );

		// initiate inotify
		int nfd; // inotifyfd
		nfd = inotify_init();
		die_if ( nfd<0,nfd,"Couldn't initiate inotify. No kernel support?" );

		// init globals
		data.nfd = nfd;
		data.configfile = configfile;
		notify_dirs nod;
		nod.max = NOTIFY_DIRS;
		nod.next = 0;
		data.ino_dirs = &nod;


		// watch devpath
		watch_dir( getstr(data.config->p_devpath), &data );

		// traverse the entire dev hierarchy and apply matching rules
		traverse_dir( getstr(data.config->p_devpath),10,&dev_cb,&watch_dir, &data );

		// setup signal handler
		struct sigaction sa;

		sigfillset(&sa.sa_mask);
		sa.sa_flags = 0;
		sa.sa_handler = sigusr1;

		if ( sigaction (SIGUSR1, &sa, 0) )
				ewrites("Couldn't install signal handler");
		// continue anyways.
		//

#define BUFLEN 1024
		char buf[BUFLEN];
		writesl("Ok");
		const struct inotify_event *e;
		char path[PATH_MAX];

		while ( 1 ){
				while ( (r=read(nfd,buf,BUFLEN)) <= 0 ){
						//printf("r: %d\n",r);
						usleep(10000); // ~ 1/100 second delay.
				}

				// loop over events
				for ( char *p = buf; p < buf+r;	p += sizeof(struct inotify_event) + e->len) {
						e = (const struct inotify_event *) p;
						printsl( "event: ", e->name );
						char *c = stpcpy( path, nod.path[e->wd] );
						*c = '/';
						c++;
						strcpy( c, e->name );
						if ( e->mask & IN_ISDIR ){
								writesl("  directory");
								watch_dir( path, &data );
						} else {
								writesl("  file");
								dev* d = get_dev_rule( path, &data );
								if ( d ){ //match
										apply_dev_rule( path, 0, d, &data );
										dev_action( path, d, &data );
								}
						}
				}

		}

		// shouldn't get here.
		die( r, "error reading inotify events" );
}

