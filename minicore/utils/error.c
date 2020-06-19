#if 0
mini_start
mini_writes
mini_puts
mini_fprintf
mini_itodec
mini_atoi
mini_buf 256
mini_verbose_errstr
INCLUDESRC
LDSCRIPT text_and_bss
HEADERGUARDS
shrinkelf
return
#endif
#include "minilib.h"


int main(int argc, char *argv[]){
		if ( argc == 1 ){
				writes("Usage: error [-l] [errno number]\n");
				return(0);
		}
		if ( argv[1][0]=='-' && argv[1][1] == 'l' ){
				for ( int a=1; a <= ERRNO_MAX; a++ ){
						printf("%d: %s\n", a, verbose_errstr(a));
				}
		} else {
				int e = atoi( argv[1] );
				puts(verbose_errstr(e));
		}
		return( 0 );
}
