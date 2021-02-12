#if 0
mini_start
mini_writes
mini_open
mini_read
mini_exit_errno

mini_usleep
mini_strlcpy
mini_strcpy
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

mini_buf 256

HEADERGUARDS
OPTFLAG -Os
#STRIPFLAG
#LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

#include "udevrd.conf.h"

typedef struct _cbdata {
		dev* devices;
		conf *config;
		int nfd;
} cbdata;


int apply_dev_rule( const char* path, struct stat *st, dev *devices ){
		
		struct stat ststat;

		for ( dev* device = devices; device; device=nextdev(device) ){
				if ( match( path, getstr(device->p_match),0) ){
						printsl("matched: ",path);
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

		}


		return(1);
}


int dev_cb(const char* path, struct stat *st, void *data){
		printsl(" cb: ",path);
		cbdata *d = (cbdata*)data;
		return( apply_dev_rule( path, st, d->devices ) );
}


int traverse_dir( const char* path, int maxdepth, 
				int(*callback)(const char* path,struct stat *st,void *userdata), 
				int(*dir_callback)(const char* path,struct stat *st,void *userdata), 
				void *userdata){
		
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
				if ( de->d_name[0] == '.' )
						continue;

				struct stat st;
				strcpy( p, de->d_name );
				if ( stat( pathname, &st ) != 0 )
						continue;
				if ( !(st.st_mode & S_IFDIR) ){
						if ( callback )
								callback(pathname, &st, userdata);
						continue;
				}

				printsl("Directory: ",de->d_name);
				if ( dir_callback )
						dir_callback(pathname, &st, userdata);

				traverse_dir( pathname, maxdepth-1, callback, dir_callback, userdata );

		}
		
		free(dir);
		return(1);
}



int main( int argc, char **argv ){
		
		// read configuration
		char *configfile = CONFIGFILE;

		int fd = open( configfile, O_RDONLY, 0 );
		dies_if( fd<0, fd, "Couldn't open ", configfile );

		struct stat ststat;
		fstat(fd, &ststat );
		printf("Size: %d\n", ststat.st_size);
	
		char* mapping = mmap(0,ststat.st_size, PROT_READ, MAP_PRIVATE|MAP_POPULATE, fd, 0 );
		die_if( mapping<=(POINTER)0, (int)(POINTER)mapping, "Couldn't map into memory");

		printf( "mgc: %x\n", *(int*)mapping );
		die_if ( *(int*)mapping != 0x76656475, -14, "The configuration file doesn't look correct." );

		writesl("ok\n");

		conf* config = getconfig(mapping); 
		dev* device = firstdev(mapping);
	
		// add inotifywatches for devpath
		int nfd; // inotifyfd
		nfd = inotify_init();
		die_if ( nfd<0,nfd,"Couldn't initiate inotify. No kernel support?" );
		int ir = inotify_add_watch(nfd, DEVPATH, IN_CREATE );
		die_if ( ir<0, ir, "Couldn't add an inotify watch for "DEVPATH );

		cbdata data;
		data.devices = device;
		data.nfd = nfd;
		traverse_dir( getstr(config->p_devpath),10,&dev_cb,0, &data );

#define BUFLEN 512
		char buf[BUFLEN];
		writesl("Ok");
		printf("ir: %d\n",ir);
		int r;
		const struct inotify_event *e;

		while ( (r=read(nfd,buf,BUFLEN)) > 0 ){
				printf("r: %d\n",r);

				// loop over events
				for ( char *p = buf; p < buf+r;	p += sizeof(struct inotify_event) + e->len) {
						e = (const struct inotify_event *) p;
						printsl( "event: ", e->name );
						if ( e->mask & IN_ISDIR )
								writesl("  directory")
						else
								writesl("  file");
				}

				

				usleep(100000); // 1/10 second prevent spinning
		}

		// shouldn't get here.
		die( r, "error reading inotify events" );

}

