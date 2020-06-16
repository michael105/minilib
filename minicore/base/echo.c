#if 0
 mini_start
 mini_putchar
 INCLUDESRC
 shrinkelf
return
#endif
#include "minilib.h"
/* Usage: echo [-n] [TEXT...] */
int main(int argc, char *argv[]){
		int n = 1;

		if ( argc>1 && argv[1][0] == '-' && argv[1][1] == 'n' ) 
				n=2;

		for ( int a = n; a<argc;  a++  ){
				if ( a>n )
						putchar(' ');
				for ( char *c = argv[a]; *c!=0; c++ )
						putchar(*c);
		}

		if ( n==1 )
				putchar( '\n' );

		return 0;
}
