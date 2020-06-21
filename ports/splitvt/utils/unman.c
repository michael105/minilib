
/* A program to remove the doubled letters in nroff -man output */

/* This program was written before I learned the trick:

	nroff -man file.man | col -b
*/

#include	<stdio.h>

main()
{
	char buffer[BUFSIZ], newbuf[BUFSIZ];
	int i, j;

	while ( gets(buffer) != NULL ) {
		for ( i=0, j=0; buffer[i]; ++i ) {
			if ( buffer[i] == ('H'-'@') )
				--j;
			else
				newbuf[j++]=buffer[i];
		}
		newbuf[j]='\0';
		puts(newbuf);
	}
	exit(0);
}
