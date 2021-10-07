#if 0
mini_buf 512
mini_start
mini_printf
mini_prints
mini_printsl
mini_writes
mini_itodec
mini_atoi
mini_malloc
mini_realloc
mini_free
mini_memcpy
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[] ){
		char *c1 = malloc(8);
		memcpy(c1,"Alloc.\n",8);
		char *c = malloc(8);
		memcpy(c,"Hello.\n",8);
		prints(c1);
		prints(c);

		c=realloc(c,12);
		memcpy(c,"Hello. xx \n",12);

		prints(c1);
		prints(c);

		c1=realloc(c1,12);
		memcpy(c1,"Alloc. == \n",12);

		prints(c1);
		prints(c);

		printsl("XXX");

		free(c);
		prints(c1);
		printsl("Y1");
		c1=realloc(c1,16);
		printsl("Y2");
		prints(c1);
		write(1,c1,10);
		writes("| \n");

		c = malloc(8);
		memcpy(c,"=====.\n",8);
		prints(c1);
		prints(c);


		return(0);
}
