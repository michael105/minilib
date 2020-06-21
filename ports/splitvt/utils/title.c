/* Set the titlebar on an xterm */

#include <stdio.h>

main(int argc, char *argv[])
{
	if ( argc != 2 ) {
		fprintf(stderr, "%s title-text\n", argv[0]);
		exit(1);
	}
	printf("\033]0;%s\07", argv[1]); fflush(stdout);
	exit(0);
}
