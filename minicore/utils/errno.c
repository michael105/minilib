#if 0
mini_start
mini_writes
mini_puts
mini_fprintf
mini_itodec
mini_atoi
mini_buf 256
mini_verbose_errstr2
INCLUDESRC
LDSCRIPT text_and_bss
globals_on_stack
HEADERGUARDS
shrinkelf
return
#endif
#include "minilib.h"


int main(int argc, char *argv[]){
		int e =0;

		if ( argc == 1 ){
				writes("Usage: errno [-l] [errno number]\n");
				exit(0);
		}

		if ( argv[1][0]=='-' && argv[1][1] == 'l' ){ // list all errno values
				for ( int a=1; a <= ERRNO_MAX; a++ ){
						printf("%d: %s\n", a, verbose_errstr2(a));
				}
		} else {
				e = atoi( argv[1] );
				if ( e ){
						puts(verbose_errstr2(e));
				}
		}
		exit(e);
}

