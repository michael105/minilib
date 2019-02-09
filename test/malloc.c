#define mini_malloc
#define mini_start start
#define mini_write
#define mini_mprintf
#define mini_overwrite

#include "include/minilib_header.h"
#include "../minilib.c"

int main(){

		char *c = malloc(64);
		
		int a;
		for ( a=0; a<=32; a++ )
				c[a] = a+50;

		printf ( c );
		printf ( "\n" );

		char *d = c;
		if ( c == d ) {
				printf("Ok\n");
		}

		d = malloc(128);
		if ( c == d ) {
				printf("Not Ok\n");
		}

		for ( a=0; a<64; a++ ){
				d[a] = a+38;
		}
		printf ( d );
		printf ("\n");
		printf ( c );
		printf ("\n");

		for ( a=0; a<64; a++ )
				c[a] = a+39;

		printf ( d );
		printf ("\n");
		printf ( c );
		printf ("\n");




		return(0);
}

