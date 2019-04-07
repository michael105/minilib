#if 0

mini_start
mini_fopen
mini_feof
mini_fclose
mini_fprintf
mini_printf
mini_sprintf
mini_print
mini_itodec
mini_itohex
mini_itoHEX
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
		fprintf( f, "Hallo 23\n" );

		fclose(f);

		f = fopen( "tl.test", "a+" );
		fprintf( f, "  xxx Hallo 42\n" );

		fclose(f);

		f = fopen( "tl.test", "r" );
	
		FILE* f2 = fopen( "t2.test", "w" );

		char buf[128];

		int i = read( fileno(f), buf, 40 );
		write( fileno(f2), buf, i );
		write( fileno(f2), "\nSososo\n\nXXX", 12 );
		printf("i: %d\n", i );
		buf[i-1]=0;
		puts("Got:");
		print(buf);
		puts("+   Ok.");
	
		fclose(f);
		fclose(f2);

		f = fopen( "fopen.c", "r" );
		char bbuf[4096];
		int r = read( fileno(f), bbuf, 2014 );
		puts( bbuf );

		printf("got: %d\n", r);

		//f2 = fopen( "t3.test", "w" );
		r = fwrite( &bbuf[32], 2, 5, stdout );
		printf("got: %d\n", r);

		//fclose(f);
		
		f2 = fopen("t3.test", "w" );
		for ( i=0x10; i<=0xFF; i++ ){
				sprintf(&bbuf[(i-0x10)*3], "%X\n", i );
		}
		puts("XXXXXXXXXXXXXXX");
		fwrite( bbuf, 6,10, f2 );
		fclose(f2);

		f2 = fopen("t3.test", "r" );
		char bufc[256];
		bufc[64] = 0;
		for ( i=0; i<=8; i++ ){
				fread( &bufc[i*6], 3, 2, f2 );
		}
		puts ( bufc );

		// check feof..
		if ( feof( f2 ) )
				puts("feof f2");
		else
				puts("not feof f2");

		i = 1;
		bufc[13] = 0;
		while ( !feof(f2) ){
			fread(bufc, 3,4,f2 );
			printf("i:  %d, buf: %s",i, bufc);
			i++;
		}
	
		return(0);
}


