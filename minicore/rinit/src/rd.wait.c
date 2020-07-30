#if 0
mini_start
mini_writes
mini_open
mini_read
mini_exit_errno

mini_usleep
mini_strncpy

HEADERGUARDS
OPTFLAG -Os
LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

		// misc 2020/06
		// public domain / BSD 3clause
		//

#define SERVICEPATH "/rd/run/"

void usage(){
		writes("Usage: rd.wait service\n");
		writes("Wait until 'service' has been started\n");
		exit(1);
}

int main(int argc, char *argv[]){
		if (argc < 2) {
				usage();
		}
	char fn[256] = SERVICEPATH;
	strncpy(fn+sizeof(SERVICEPATH)-1,argv[1],256-sizeof(SERVICEPATH));

	int fd = open( fn, O_RDWR|O_CREAT, 0664 );

	if ( fd<0 ){
			exit_errno(fd);
	}

	char b[1];
	char buf[64];

	int r = 0;

	r = read(fd,b,1);
	if ( r > 0 )
			return(0);

	int nfd; // inotifyfd
	nfd = inotify_init();
	if ( nfd<0 ){
			exit_errno(nfd);
	}

	int ir = inotify_add_watch(nfd, fn, IN_MODIFY );

	if ( ir<0 ){
			exit_errno(ir);
	}

	while ( r == 0 ){
			usleep(100000); // 1/10 second
			read(nfd,buf,64);
			r = read(fd,b,1);
	}

	return(0);
}

