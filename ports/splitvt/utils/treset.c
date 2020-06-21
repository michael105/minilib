/* A simple program to reset the scrolling regions of a vt100 terminal */

#include	<stdio.h>

main()
{
	printf("\033[m\033;r\033[;H\033[2J");
	fflush(stdout);
	exit(0);
}
