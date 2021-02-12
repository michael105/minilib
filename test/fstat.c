#if 0
mini_start
mini_fopen
mini_fclose
mini_fprintf
mini_printf
mini_print
mini_itodec
mini_itohex
mini_fileno
mini_puts
mini_read
mini_strlen
mini_fstat

mini_buf 1024
mini_INCLUDESRC

return
#endif


#include "minilib/minilib.h"


int main( int argc, char *argv[] ){

	fprintf( stdout, "stdio.\n" );

	int fd = open( "fstat", O_RDONLY );
	if ( fd <= 0 ){
		printf("Err, errno: %d\n",fd*-1);
		exit(fd);
	}
	printf("fd: %d\n",fd);

	struct stat st;

	int r = fstat(fd,&st);
	if ( r < 0 ){
		printf("Err fstat, errno: %d\n",r*-1);
		exit(r);
	}

	printf("size: %d\n",st.st_size);

	return(0);
}
