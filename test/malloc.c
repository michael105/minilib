#define mini_malloc
#define mini_mbuf 1024
#define mini_start start
#define mini_write
#define mini_printf
#define mini_fprintf
#define mini_puts
#define mini_fputc
#define mini_overwrite

#include "include/minilib_header.h"

int main(){
		write(stdout,"write\n",6);

		puts("Ok.");
		char *c = malloc(64);
		puts("malloc1");
		
		int a;
		for ( a=0; a<=32; a++ )
				c[a] = a+50;

		puts("malloc2");
		printf ( c );
		printf ( "\n" );

		char *d = c;
		if ( c == d ) {
				printf("Ok\n");
		}

		puts("malloc3");
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

		printf("ml.mbufsize: %d\n", ml.mbufsize );

		int *a1 = malloc(4);
		int *a2 = malloc(8);

		printf("ml.mbufsize: %d\n", ml.mbufsize );

		a1[0] = 42;
		a2[0] = 13;
		a2[1] = 23;
		
		printf( "a1: %d\n", a1[0] );
		for ( int i=0; i<=3; i++ )
				printf( "a2[%d]: %d\n", i, a2[i] );
		int *i = a1;
		i--;
		printf( "i[-1]: %d\n", i[-1] );
		printf( "i[0]: %d\n", i[0] );
		printf( "i[1]: %d\n", i[1] );
		printf( "i[2]: %d\n", i[2] );

		printf("ml.mbufsize: %d\n", ml.mbufsize );
		printf("mbuf: %d\n", ml.mbuf[ml.mbufsize] ); // size of last region in bytes
		printf("mbuf: %d\n", (int)ml.mbuf[ml.mbufsize+4] );


		if ( (char*)&a2[-1] == &ml.mbuf[ml.mbufsize] )
				printf("Bottom a2\n"); // Ok. works

		if ( (char*)&a1[-1] == &ml.mbuf[ml.mbufsize] )
				printf("Bottom a1\n");

		//mbuf[ml.mbufsize+4] = 1976; //no: overflow with conversion.
//		mbuf[ml.mbufsize+4](int&) = 1976; //no: overflow with conversion.
		printf("mbuf: %d\n", (int)ml.mbuf[ml.mbufsize+4] );

		i-=3;
		printf( "i[-1]: %d\n", i[-1] );
		printf( "i[0]: %d\n", i[0] ); // ok. now points to len of last element.
		printf( "i[1]: %d\n", i[1] );
		printf( "i[2]: %d\n", i[2] );





		return(0);
}
