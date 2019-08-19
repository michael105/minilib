#if 0
mini_start
mini_write
mini_puts
mini_strlen
LDSCRIPT onlytext
INCLUDESRC
shrinkelf
return
#endif

#include "minilib.h"

int main(int argc, char *argv[]){

		if ( argc == 1 ){
				for (;;){ 
						puts("y");
				}
		} else {
				for ( int a=1; a<argc-1; a++ ){
						argv[a][strlen(argv[a])] = ' ';
				}
				for ( ;; ){
				puts( argv[1] );
				}
		}

		return(0);
}

