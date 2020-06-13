#if 0
 mini_start
 mini_putchar
 mini_writes
 mini_errno
 INCLUDESRC
 LDSCRIPT textandbss
 shrinkelf
return
#endif
#include "minilib.h"

int main(int argc, char *argv[]){
		if ( argc < 3 ){
				writes("usage: ln [-s] path link\n");
				return(1);
		}

		int s = 1;
		if ( argv[1][0] == '-' && argv[1][1] == 's' ) 
				s=2;

		int ret;

		if ( s==2 ){
				ret=symlink(argv[s],argv[s+1]);
		} else {
				ret=link(argv[s],argv[s+1]);
		}
		if ( ret ){
				writes("ln: error: ");
				putchar( 48+(errno/10) );
				putchar( 48+(errno%10) );
				putchar( '\n' );
				return(errno);
		}

		return( 0 );
}
