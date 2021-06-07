#if 0
mini_buf 256
#globals_on_stack
mini_errno
mini_start
mini_printf
mini_prints
mini_itodec
mini_atoi
mini_getenv
mini_environ
mini_INCLUDESRC
STRIPFLAG
LDSCRIPT text_and_bss
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[], char *envp[] ){
		prints("getenv.\n");

				printsl( argv[0] );
		if ( argc>1 ){
				printsl( argv[1] );
		}
		//printsl(envp[0]);

		printsl(getenv("HOME"));

		//printsl(environ[0]);
		//printsl(envp[0]);
		//printsl(environ[1]);
		printsl("Ok");

		int a=0;
		for (;a<3;a++)
				printf("a: %d\n",a);

		printf("a out: %d\n",a);

		return(0);
}
