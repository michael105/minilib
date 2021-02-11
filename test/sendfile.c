#if 0
mini_buf 256
mini_start
mini_open
mini_printf
mini_itodec
mini_atoi
mini_fork
mini_INCLUDESRC
return
#endif

int main(int argc, char**argv){
		int fd = open( "hello.c", O_RDONLY );
		long int offset = 20;
		sendfile(STDOUT_FILENO,fd,&offset,19);
		while ( sendfile(STDOUT_FILENO,fd,0,16) > 0 );

		return(0);
}
