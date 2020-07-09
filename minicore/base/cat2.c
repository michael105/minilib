#if 0
mini_start
mini_open
mini_errno
mini_strerror
mini_perror
mini_writes
mini_ewrites
mini_eputs


#LDSCRIPT default
LDSCRIPT text_and_bss
INCLUDESRC
SHRINKELF
return
#endif

void usage(){
		writes("cat2 infile [outfile]\n");
		exit(1);
}

void err(const char* f, int e){
			 ewrites("Couldn't open ");
			 eputs(f);
			 //perror("Got: ");
			 eputs(strerror(e));
			 exit(e);
}


int main(int argc, char**argv){
		if ( argc==1 || argc>3 || (argv[1][0]=='-' && argv[1][0]=='h') )
				usage();

	 int fd = open( argv[1], O_RDONLY );
	 if(fd<0){
			 err(argv[1],errno);
	 }

	 int outfd = STDOUT_FILENO;
	 if ( argc>2 ){
			 if ( (outfd=open(argv[2],O_WRONLY | O_CREAT ))< 0 )
					 err(argv[2],errno);
	 }

	 
		while ( sendfile(outfd,fd,0,4096) );

		if ( errno ){
				eputs(strerror(errno));
				//perror(errno);
				exit(errno);
		}


		return(0);
}
