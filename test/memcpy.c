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
mini_memcpy
mini_buf 1024

OPTIMIZE
STRIPFLAG
INCLUDESRC

return
#endif


#include "minilib/minilib.h"


int main( int argc, char *argv[] ){

	fprintf( stdout, "sizeof long: %d\n", sizeof(long) );
	char d[16];
	char *s1="1234567\nabcdefg\n";

	memcpy(d,s1,8);
	printf("d: %s\n",d);

	memcpy(d,s1,10);
	printf("d: %s\n",d);

	memcpy(d,s1,11);
	printf("d: %s\n",d);

	memcpy(d,s1,14);
	printf("d: %s\n",d);


	return(0);
}
