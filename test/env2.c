#if 0
#mini_buf 256
#globals_on_stack
#mini_errno
mini_start
#mini_printf
mini_prints
#mini_itodec
#mini_atoi
#mini_getenv
#mini_environ
mini_INCLUDESRC
STRIPFLAG
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[], char *envp[] ){
		prints("getenv.\n");

		printsl( argv[0] );
		if ( argc>1 ){
				printsl( argv[1] );
		}
		printsl(envp[0]);

		printsl("Ok");

		return(0);
}
