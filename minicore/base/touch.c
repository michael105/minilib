#if 0
mini_start
mini_open
mini_close
mini_write
mini_writes
mini_read
mini_GETOPTS
LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif


int main(int argc, char **argv){
		int opts=0;
		int ret = PARSEOPTS_short(opts, argv, (m+h), SETOPT_short(opts,h));

		if ( GETOPT_short(opts,h) ){
				writes("Usage: touch [-h] [-m]\n");
				return 1;
		} 

		for ( int a=ret; argv[a] !=0; a++ ){
				int fd = open( argv[a], O_CREAT | O_RDWR | O_APPEND, 0644 );
				char *v=0;
				if ( !GETOPT_short(opts,m) )
						read( fd, (void*)v,1 ); // Read nothing, or eof. Update access time

				write(fd,0,1); 
				// write eof. Update modify/and change time 
				// This doesn't change the file's contents. 
				// (not sure whether both confirms to posix
				// plase tell me, if not. It's just the smallest working solution I've been able to find)
				// Changing the access time only is somehow sort of unstable.
				// sometimes works, sometimes not. ??
				// Also when syncing the file.
				// so I removed the option.
				// It might be neccessary, to use utime here.
				// Anyways, the binary already is at 464 Bytes.
				// I'd really love having all core utils within 64kB.
				// So, cannot afford too many rarely used options.
				// (misc)
				close(fd);
		}

		return 0;
}
