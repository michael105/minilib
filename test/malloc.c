#define mini_malloc
#define mini_buf 1024
//#define mini_start start
#define mini_write
#define mini_printf
#define mini_fprintf
#define mini_puts
#define mini_fputc

//#define INCLUDESRC

#include "minilib/minilib.h"

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
		printf( "i[0]: (len of a1) %d\n", i[0] );  
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
		//ml.mbuf[ml.mbufsize+4](int&) = 1976; //no: somehow casting doesn't work out. changed mbuf to ml.mbuf..
	 	ml.ibuf[(ml.mbufsize>>2)+1] = 1976; 
	 	//printf("mbuf: %d\n", (int)ml.mbuf[ml.mbufsize+5] ); // strange. The union{ ml.mbuf; ml.ibuf} is really better

		i-=3;
		printf( "i[-1]: %d\n", i[-1] );
		printf( "i[0]: %d\n", i[0] ); // ok len of a2
		printf( "i[1]: %d\n", i[1] ); // 1976
		printf( "i[2]: %d\n", i[2] );

		printf("ml.mbufsize: %d\n", ml.mbufsize );
		free(a2);
		printf("ml.mbufsize: %d\n", ml.mbufsize );
		free(a1);
		printf("ml.mbufsize: %d\n", ml.mbufsize );	
		char *c9 = malloc(9);
		printf("ml.mbufsize: %d\n", ml.mbufsize );	
		free(c9);
		printf("ml.mbufsize: %d\n", ml.mbufsize );	
		free(c9);
		printf("ml.mbufsize: %d\n", ml.mbufsize );	

		int *a4 = malloc(8);
		int *a3 = malloc(4);

		printf("ml.mbufsize: %d\n", ml.mbufsize );

		a3[0] = 47;
		a4[0] = 1333;
		a4[1] = 23100;

		int *i2 = a3;
		i2--;
		//printf( "i[-1]: %d\n", i[-1] );
		printf( "i2[0]: (len of a3) %d\n", i2[0] );  
		printf( "i2[1]: %d\n", i2[1] );
		printf( "i2[2]: (len of a4) %d\n", i2[2] );
		printf( "i2[3]: %d\n", i2[3] );
		printf( "i2[4]: %d\n", i2[4] );
		printf( "i2[5]: (len of next area) 0x%x\n", i2[5] );

		printf("ml.mbufsize: %d\n", ml.mbufsize );
		free(a4);
		printf("a4 free'd\n");
		printf("ml.mbufsize: %d\n", ml.mbufsize );
		printf( "i2[0]: (len of a3) %d\n", i2[0] );  
		printf( "i2[1]: %d\n", i2[1] );
		printf( "i2[2]: (len of a4) 0x%x\n", i2[2] );
		printf( "i2[3]: %d\n", i2[3] );
		printf( "i2[4]: %d\n", i2[4] );
		printf( "i2[5]: (len of next area) 0x%x\n", i2[5] );

		free(a3);
		printf("a3 free'd\n");
		printf("ml.mbufsize: %d\n", ml.mbufsize );
		printf( "i2[0]: (len of a3) %d\n", i2[0] );  
		printf( "i2[1]: %d\n", i2[1] );
		printf( "i2[2]: (len of a4) 0x%x\n", i2[2] );
		printf( "i2[3]: %d\n", i2[3] );
		printf( "i2[4]: %d\n", i2[4] );
		printf( "i2[5]: (len of next area) 0x%x\n", i2[5] );

		printf("=============\n");
		a4 = malloc(4);
		a3 = malloc(8);
		i2 = a3;
		i2--;
		a4[0] = 77;
		a3[0] = 3314;
		a3[1] = 1234;

		printf("ml.mbufsize: %d\n", ml.mbufsize );
		printf( "i2[0]: (len of a3) %d\n", i2[0] );  
		printf( "i2[1]: %d\n", i2[1] );
		printf( "i2[2]: %d\n", i2[2] );
		printf( "i2[3]: (len of a4) 0x%x\n", i2[3] );
		printf( "i2[4]: %d\n", i2[4] );
		printf( "i2[5]: (len of next area) 0x%x\n", i2[5] );

		a2 = malloc(4);
		a1 = malloc(8);
		a1[0] = 0;
		a1[1] = 10;
		a2[0] = 22;

		i2 = a1;
		i2--;
		a4[0] = 78;
		a3[0] = 3315;
		a3[1] = 1235;

		printf(AC_LMARINE "===== allocated a1 - a4\n" AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		void dump( int *p ){
				for ( int b = 0; b<=10; b++ ){
						if ( &ml.mbuf[ml.mbufsize] == (char*)&p[b] ){
								printf( AC_YELLOW "-> bufsize ( %d ) " AC_WHITE , ml.mbufsize ); // ?????
								//printf( "p[%d]: 0x%x = %d\n", b, p[b], p[b] ); 
						} else
								printf( "                   " );
						if ( p[b] & 0xF0000000 )
								printf( AC_LGREEN "p[%d]: 0x%x" AC_WHITE " = %d \n", b, p[b], p[b] ); 
						else
								printf( "p[%d]: 0x%x = %d \n", b, p[b], p[b] ); 
				}
		}

		dump(i2);



		free(a3);
		free(a2);
		printf(AC_LMARINE "===== free'd a3, a2\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );


		dump(i2);



		free(a1);
		printf(AC_LMARINE "===== free'd a1\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );


		dump(i2);
		
		printf(AC_YELLOW "==================\n" AC_WHITE);
		a3 = malloc(8);
		i2 = a3;
		i2--;
		a4[0] = 77;
		a3[0] = 3314;
		a3[1] = 1234;

		printf("ml.mbufsize: %d\n", ml.mbufsize );
		printf( "i2[0]: (len of a3) %d\n", i2[0] );  
		printf( "i2[1]: %d\n", i2[1] );
		printf( "i2[2]: %d\n", i2[2] );
		printf( "i2[3]: (len of a4) 0x%x\n", i2[3] );
		printf( "i2[4]: %d\n", i2[4] );
		printf( "i2[5]: (len of next area) 0x%x\n", i2[5] );

		a2 = malloc(4);
		a1 = malloc(8);
		a1[0] = 0;
		a1[1] = 10;
		a2[0] = 22;

		i2 = a1;
		i2--;
		a4[0] = 78;
		a3[0] = 3315;
		a3[1] = 1235;

		printf(AC_LMARINE "===== allocated a1 - a4\n" AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);

		free(a2);
		printf(AC_LMARINE "===== free'd a2\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);

		free(a1);
		printf(AC_LMARINE "===== free'd a1\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );


		dump(i2);
		
		free(a3);
		printf(AC_LMARINE "===== free'd a3\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);
		
		free(a4);
		printf(AC_LMARINE "===== free'd a4\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);

// =========================
		
		printf(AC_LMAGENTA "==================\n" AC_WHITE);
		a4 = malloc(3);
		a3 = malloc(8);
		i2 = a3;
		i2--;
		a4[0] = 44;
		a3[0] = 11;
		a3[1] = 22;

		a2 = malloc(4);
		a1 = malloc(8);
		a1[0] = 37;
		a1[1] = 1001;
		a2[0] = 2222;

		i2 = a1;
		i2--;
		a4[0] = 45;
		a3[0] = 12;
		a3[1] = 373737;

		printf(AC_LMARINE "===== allocated a1 - a4\n" AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);

		free(a4);
		printf(AC_LMARINE "===== free'd a4\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);

		free(a2);
		printf(AC_LMARINE "===== free'd a2\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );


		dump(i2);
		
		free(a1);
		printf(AC_LMARINE "===== free'd a1\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);
		
		free(a3);
		printf(AC_LMARINE "===== free'd a3\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);


		printf(AC_LMAGENTA "==================\n" AC_WHITE);
		a4 = malloc(3);
		a3 = malloc(8);
		i2 = a3;
		i2--;
		a4[0] = 44;
		a3[0] = 11;
		a3[1] = 22;

		a2 = malloc(4);
		a1 = malloc(8);
		a1[0] = 37;
		a1[1] = 1001;
		a2[0] = 2222;

		i2 = a1;
		i2--;
		a4[0] = 45;
		a3[0] = 12;
		a3[1] = 373737;

		printf(AC_LMARINE "===== allocated a1 - a4\n" AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);

		free(a4);
		printf(AC_LMARINE "===== free'd a4\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);

		free(a2);
		printf(AC_LMARINE "===== free'd a2\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );


		dump(i2);
		
		free(a3);
		printf(AC_LMARINE "===== free'd a3\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);
		
		free(a1);
		printf(AC_LMARINE "===== free'd a1\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);



		printf(AC_LMAGENTA "==================\n" AC_WHITE);
		a4 = malloc(3);
		a3 = malloc(8);
		i2 = a3;
		i2--;
		a4[0] = 44;
		a3[0] = 11;
		a3[1] = 22;

		a2 = malloc(4);
		a1 = malloc(8);
		a1[0] = 37;
		a1[1] = 1001;
		a2[0] = 2222;

		i2 = a1;
		i2--;
		a4[0] = 45;
		a3[0] = 12;
		a3[1] = 373737;

		printf(AC_LMARINE "===== allocated a1 - a4\n" AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);

		free(a2);
		printf(AC_LMARINE "===== free'd a2\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);

		free(a4);
		printf(AC_LMARINE "===== free'd a4\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );


		dump(i2);
		
		free(a3);
		printf(AC_LMARINE "===== free'd a3\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);
		
		free(a1);
		printf(AC_LMARINE "===== free'd a1\n"AC_WHITE);
		printf("ml.mbufsize: " AC_LRED "%d\n" AC_WHITE, ml.mbufsize );

		dump(i2);



		return(0);
}
