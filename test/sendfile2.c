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
	 int fd = open( "tmp.txt", O_RDWR|O_CREAT );
	 int fd2 = open( "hello.c", O_RDONLY );
		//long int offset = 20;
		//sendfile(STDOUT_FILENO,fd,&offset,19);
		//while ( sendfile(fd,0,0,1) ); // doesnt ork. stdin.
		while ( sendfile(fd,fd2,0,10) );

		return(0);
}
