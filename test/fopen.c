#if 0

mini_start
mini_fopen
mini_fclose
mini_fprintf
mini_printf
mini_print
mini_itodec
mini_fileno
mini_puts
mini_read
mini_buf 1024
mini_INCLUDESRC

return
#endif


#include "minilib/minilib.h"


int main( int argc, char *argv[] ){

		FILE *f = fopen( "tl.test", "w" );
		fprintf( fileno(f), "Hallo 23\n" );

		fclose(f);

		f = fopen( "tl.test", "a+" );
		fprintf( fileno(f), "  xxx Hallo 42\n" );

		fclose(f);

		f = fopen( "tl.test", "r" );
		char buf[128];

		int i = read( fileno(f), buf, 40 );
		printf("i: %d\n", i );
		buf[i-1]=0;
		puts("Got:");
		print(buf);
		puts("+   Ok.");


		return(0);
}


