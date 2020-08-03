#if 0

mini_start
mini_group_write
mini_group_print


mini_sendfile
mini_mmap
mini_exit_errno
mini_errno
mini_open
mini_sleep

mini_group_printf
mini_buf 256

INCLUDESRC
SHRINKELF

return
#endif

void usage(){
		writes("usage: lockfile file\n"
						"Load and lock a file in memory. (mmap)\n");
		exit(1);
}


int main(int argc, char **argv){

		if ( argc<2 )
				usage();

		int fd = open( argv[1], O_RDONLY );
		if ( fd<0 ){
				printsl("Couldn't open ",argv[1]);
				exit_errno(fd);
		}
		errno=0;
		struct stat ststat;
		fstat(fd, &ststat );
		printf("Size: %d\n", ststat.st_size);
		
		void* p = mmap( 0, ststat.st_size, PROT_READ, MAP_PRIVATE| MAP_LOCKED | MAP_POPULATE , fd, 0 );

		if ( errno )
				exit_errno(errno);


		while(1){
				writes("Sleeping\n");
				sleep(-1);
		}

		return(0);
}
