#if 0
mini_start
mini_writes
mini_open
mini_read
mini_select
mini_exit_errno
mini_atoi

mini_usleep
mini_strtol

mini_syscalls

mini_buf 256
mini_printf
mini_itodec
#globals_on_stack

HEADERGUARDS
OPTFLAG -O0
#LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/06
// public domain / BSD 3clause

void usage(){
		writes("Usage: waitfor [-r] [-t timeout] file\n");
		writes("Read a char from 'file',\n"
						"create 'file' if it doesn't exit,\n"
						"block until another process has written the char\n");
		exit(1);
}

int main(int argc, char *argv[]){
	if (argc < 2) {
			usage();
	}
	char *fn = argv[1];
	int flags = 0;
	int t=-1;
	int mode = 0664; // rw rw r

// define to something other for parsing the docu
#ifndef OPT
#define OPT(flag,desc) case flag:
#endif

	for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
			for ( char *c = argv[0]+1; *c != 0; c++ ){
					switch ( *c ){
							OPT('h',show usage)
									usage();
							OPT('r',clear old file (truncate it))
												flags = O_TRUNC;
												break;
							OPT('t',set timeout in seconds) 
												*argv++;
												if ( !*argv )
														usage();
												t = strtol(*argv,0,0);
												t*=10;
												break;
							OPT('a',file attribute mask for creation as number. (default: 0664,rw rw r))
												*argv++;
												if ( !*argv )
														usage();
												mode = strtol(*argv,0,0);
												break;


					}
			}
	}

	if ( !*argv )
			usage();

	int fd = open( argv[0], O_RDWR|O_CREAT|flags, mode );

	if ( fd<0 ){
			exit_errno(fd);
	}

	char b[1];
	char buf[256];

	int r = 0;

	r = read(fd,b,1);
	int nfd; // inotifyfd
	nfd = sys_inotify_init();
	if ( nfd<0 ){
			exit_errno(nfd);
	}

	int ir = sys_inotify_add_watch(nfd, argv[0], IN_MODIFY );
	//int ir = sys_inotify_add_watch(nfd, argv[0], IN_MODIFY | IN_OPEN );
	if ( ir<0 ){
			exit_errno(ir);
	}


	//fd_set rs;
	//FD_ZERO (&rs);
	//FD_SET(nfd,&rs); //


	while ( r == 0 && ( t!=0 ) ){
			//r = poll(&rs,0,-1);
			writes("loop\n");
			//int a = select(fd+1, &rs,0,0,0);
			int l = read(nfd,buf,256);
			printf("l: %d\n",l);
			
			r = read(fd,b,1);
			if ( t>0 )
				t--;
			
			//usleep(100000); // 1/10 second

	}
	write(STDOUT_FILENO,b,1);
	write(STDOUT_FILENO,"\n",1);

	return(nfd);
	return(r?0:11); // 0 on success, 11 on timeout (errno 'try again')
}


