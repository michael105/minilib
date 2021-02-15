#if 0
mini_start
mini_open
mini_close
mini_write
mini_writes
mini_ewrites
mini_read
mini_group_printf
mini_buf 1024
mini_GETOPTS
#LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
OPTFLAG -Os
return
#endif

// append, extract or replace data.
// read from stdin;
// write to stdout.

void writefile(int fd){
	char buf[4096];
	int l, len=0;
	while ( l=read(0,buf,4096) ){
		write(fd,buf,l);
		len+=l;
	}
	//fprintf(stderr,"wrote: %d\n",len);
	write(fd,(char*)&len,4);
	write(fd,"AP\0\0",4);
	close(fd);
}

int seekfile(int fd,int trunc){
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
	if ( trunc )
		ftruncate( fd,size-8-len );
	return(len);
}


int main(int argc, char **argv){
		int opts=0;
		char buf[4096];
		int ret = PARSEOPTS_short(opts, argv, (h+r+a+e), SETOPT_short(opts,h));

		if ( GETOPT_short(opts,h) ){
				writes("Usage: ap [-h] [-r] [-a] [-e] file\n\
-a append / -r replace / -e extract stdin to file / to stdout\n");
				return 0;
		} 


		if ( GETOPT_short(opts,a)){
				int fd = open( argv[ret], O_RDWR | O_APPEND );
				if ( fd<=0 )
					return ( 1 );

				int size = lseek( fd, 0, SEEK_END );
				writefile(fd);

				return(0);
		} 

		if ( GETOPT_short(opts,r)){
				int fd = open( argv[ret], O_RDWR );
				if ( fd<=0 )
					return ( 1 );

				int len = seekfile(fd,1);
				writefile(fd);
				return(0);
		}



		if ( GETOPT_short(opts,e)){
				int fd = open( argv[ret], O_RDONLY );
				if ( fd<=0 )
					return ( 1 );

				int len = seekfile(fd,0);
				if ( len<0 ){
						ewrites("Error. Nothing appended.\n");
						exit(-1);
				}

				int l;
				do {
					l=len;

					if ( len > 4096 )
						l=4096;

					l=read(fd,buf,l);

					len-=l;
					write(1,buf,l);
				} while ( len>0 && l );

				if ( len ){
					ewrites("Error\n");
					return(3);
				}

				close(fd);
				return(0);
		} 


		return 0;
}
