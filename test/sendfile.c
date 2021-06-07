#if 0
mini_buf 256
mini_start
mini_open
mini_printf
mini_itodec
mini_atoi
mini_fork
mini_sendfile
mini_printf
mini_itodec
mini_errno
mini_INCLUDESRC
return
#endif

int main(int argc, char**argv){
		int fd = open( "hello.c", O_RDONLY );
		printf("fd: %d\n",fd);
		long int offset = 20;
		// doesnt ork here. (errno 22)
		int r = sendfile(STDOUT_FILENO,fd,&offset,19);
		printf("r: %d\n",r);
		printf("errno: %d\n",errno);
		while ( (sendfile(STDOUT_FILENO,fd,0,20)) > 0 );
		fsync(STDOUT_FILENO);

		return(0);
}
