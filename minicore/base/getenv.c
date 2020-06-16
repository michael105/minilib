#if 0
mini_start
mini_strcmp
mini_strlen
mini_fprintfs
mini_getenv
INCLUDESRC
shrinkelf
LDSCRIPT text_and_bss
return
#endif
#include "minilib.h"




int main(int argc, char **argv, char **env ){

		char *delimiter = "\n";
		int a = 1;


		if ( argc > 1 ){
		if ( argv[1][0] == '-' && argv[1][1] == '0' ){
				delimiter = "\0";
				a++;
		}
		}
		if ( argc > a ){
				fprintfs( stdout, "%s:  %s%s", argv[a], getenv(argv[a]), delimiter );
				return(0);
		}

	


		for ( int a =0; env[a]; a++ ){
						fprintfs(stdout, "%s%s", env[a], delimiter );
				}
		return(0);
}
