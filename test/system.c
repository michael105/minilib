#if 0
mini_start
mini_buf 512
mini_prints
mini_printf
mini_itodec
mini_system
mini_INCLUDESRC
LDSCRIPT text_and_bss
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[] ){
		
		int r = system("ls system.c Makefile");
		printf("ret: %d\n",r);
		r = system("ls should_not_be_there");
		printf("ret: %d\n",r);
		r = system("sleep 1");
		printf("ret: %d\n",r);
		r = system("this_should_raise_an_error");
		printf("ret: %d\n",r);
		r = system("echo \"\e[32m system tests ok\"");
		printf("ret: %d\n",r);

		return(0);
}
