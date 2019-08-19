#if 0
mini_start
mini_write
mini_writes
mini_puts
mini_strlen
LDSCRIPT onlytext
INCLUDESRC
shrinkelf
return
#endif

#include "minilib.h"

int main(int argc, char *argv[]){
		int p = 1;
		if ( argc > 1 ){
				if ( argv[1][0] == '-' && argv[1][1] == 'h' ){
						writes("echo [-h] [-n] [args]\n");
						return(0);
				}
				if ( argv[1][0] == '-' && argv[1][1] == 'n' ){
						p = 2;
				}
				int a = p;
				if ( argc > p ){
						while ( print(argv[a]) && a++ && a<argc ){
								print(" ");
						}
				}
		}
		if ( p==1 ){
				printl();
		}

		return(0);
}
