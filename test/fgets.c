#if 0
mini_buf 256
mini_start
mini_printf
mini_fgets
mini_ungetc
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[] ){
		printf("Fgets.\n");

		char buf[64];
		char *c = fgets( buf, 1, stdin );
		printf("Got: %s\n", buf);
		printf("Got c: %s\n", c);

		ungetc('t',stdin);
		c = fgets( buf, 16, stdin );
		printf("Got: %s\n", buf);
		printf("Got c: %s\n", c);

		c = fgets( buf, 16, stdin );
		printf("Got: %s\n", buf);
		printf("Got c: %s\n", c);


		return(0);
}
