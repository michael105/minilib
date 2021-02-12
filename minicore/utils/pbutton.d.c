#if 0
mini_start
mini_exit_errno
mini_open
mini_system
mini_writes


mini_group_printf
mini_fileno
mini_buf 256

INCLUDESRC
SHRINKELF
LDSCRIPT default

return
#endif

int main( int argc, char **argv){

		int fd = open("/dev/input/event2",O_RDONLY );

		if ( fd<0 ){
				exit_errno(fd);
		}

		char buf[128];
		int r;
		while( r = read( fd, buf, 128 ) ){
				//if ( buf[2] == 38 && buf[3] == 95 ){
				if ( buf[1] == 100 && buf[2] == 111  ){
						writes("Shutdown\n");
						system("halt");
				}
				while( r-->0 )
						printf(" %d - ", buf[r] );
						printf("r: %d, %d - ",r, buf[r] );
		}

		return(0);
}
