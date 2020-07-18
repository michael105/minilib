#if 0
mini_start
mini_writes
mini_open
mini_read
mini_select
mini_exit_errno

mini_usleep

#mini_syscalls

#mini_buf 256
#mini_printf
#mini_itodec
#globals_on_stack

#LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/06
// BSD license

void usage(){
		writes("Usage: catc file\n");
		writes("Read a char from 'file',\n"
						"create 'file' if it doesn't exit,\n"
						"block until another process has written the char\n");
		exit(1);
}

int main(int argc, char *argv[]){
	if (argc != 2) {
			usage();
	}
	
	int fd = open( argv[1], O_RDWR|O_CREAT, 0664 );

	if ( fd<0 ){
			exit_errno(fd);
	}

	char b[2];

	int r = 0;

	r = read(fd,b,1);

	while ( r == 0 ){
			usleep(100000); // 1/10 second
			r = read(fd,b,1);

			//int notify; // inotifyfd
	/*		fd_set rs;
			FD_ZERO (&rs);
			FD_SET(fd,&rs); // no ork
			r = select(1,&rs,0,0,0); */
	}
	write(STDOUT_FILENO,b,1);
	write(STDOUT_FILENO,"\n",1);

	return(r);
}


