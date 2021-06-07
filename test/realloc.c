#if 0
mini_buf 256
mini_start
mini_printf
mini_prints
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

		free(c);
		prints(c1);
		c1=realloc(c1,16);
		write(1,c1,8);
		writes("| \n");

		c = malloc(8);
		memcpy(c,"=====.\n",8);
		prints(c1);
		prints(c);


		return(0);
}
