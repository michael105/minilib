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
		puts("ok.");

		FILE *f = fopen( "tl.test", "w" );

		puts("ok open");
		fprintf( f, "Hallo 23\n" );
		printf( "ml.pstream: %d\n", ml.pstream );

		puts("ok written");
		fclose(f);

		printf( "ml.pstream: %d\n", ml.pstream );
		f = fopen( "tl.test", "a+" );
		fprintf( f, "  xxx Hallo 42\n" );

		printf( "ml.pstream: %d\n", ml.pstream );
		fclose(f);

		printf( "ml.pstream: %d\n", ml.pstream );
		f = fopen( "tl.test", "r" );
	
		printf( "ml.pstream: %d\n", ml.pstream );
		FILE* f2 = fopen( "t2.test", "w" );

		printf( "ml.pstream: %d\n", ml.pstream );
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

		printf( "ml.pstream: %d\n", ml.pstream );
		fclose(f2);

		printf( "ml.pstream: %d\n", ml.pstream );
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
		for ( i=0; i<=4; i++ ){
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
		for ( i=0; (!feof(f2)) && ( i<4); i++ ){
			int r = fread(bufc, 3,4,f2 );
			printf("i:  %d, r: %d, buf: %s",i, r, bufc);
		}
	
		i = fsetpos( f2, 7 );
		printf("\nsetpos: %d\n",i);

		for ( i=0; (!feof(f2)) && ( i<4); i++ ){
			int r = fread(bufc, 3,4,f2 );
			printf("i:  %d, r: %d, buf: %s",i, r, bufc);
		}
		printf("\nftell: %d\n",ftell(f2));
	
			i = fsetpos( f2, 13 );
		printf("\nsetpos: %d\n",i);
		printf("\nftell: %d\n",ftell(f2));

		for ( i=0; (!feof(f2)) && ( i<4); i++ ){
			int r = fread(bufc, 3,4,f2 );
			printf("i:  %d, r: %d, buf: %s",i, r, bufc);
		}
		
		printf("\nftell: %d\n",ftell(f2));
			i = fsetpos( f2, 88 );
		printf("\nsetpos: %d\n",i);
		printf("\nftell: %d\n",ftell(f2));

		for ( i=0; (!feof(f2)) && ( i<4); i++ ){
			int r = fread(bufc, 3,4,f2 );
			printf("i:  %d, r: %d, buf: %s",i, r, bufc);
		}
		printf("\nftell: %d\n",ftell(f2));
		
		fclose(f2);
		fclose(f);

		f = fopen( "t3.test", "a" );
		fprintf( f, "Appending\n" );
		fclose(f);
		f = fopen( "t3.test", "a+" );
		fsetpos( f, 0 );
		while( !feof( f )){
				fread( bufc, 4,1, f );
				write(fileno(stdout), bufc, 4 );
				write(fileno(stdout), "  (t3)\n", 7 );
		}
		fsetpos( f, 1 );
		fprintf( f, "ZZZZZ\n" );

		for ( fsetpos(f,0); !feof(f); (fread( bufc, 1, 1, f )==1) && write( fileno(stdout), bufc, 1 ) );
		fclose(f);

		f = fopen( "t3.test", "r+" );
		fsetpos( f, 12 );
		fprintf( f, "YYYY" );
		for ( fsetpos(f,0); !feof(f); (fread( bufc, 1, 1, f )==1) && write( fileno(stdout), bufc, 1 ) );
		fclose(f);

		f = fopen( "t3.test", "w+" );
		//fsetpos( f, 0 );
		fprintf(f,"Truncated\nOk..\n");
		//fsetpos( f, 12 );
		//fprintf( f, "VV" );
		for ( fsetpos(f,0); !feof(f); (fread( bufc, 1, 1, f )==1) && write( fileno(stdout), bufc, 1 ) );
		fclose(f);


		f = fopen( "t3.test", "r+" );
		printf("fileno: %d\n", fileno(f) );
		fprintf( f, "Test\n" );

		return(0);
}


