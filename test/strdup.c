#if 0

mini_start
mini_fprintf
mini_printf
mini_sprintf
mini_strdup
mini_print
mini_writes
mini_itodec
mini_buf 1024
mini_INCLUDESRC

return
#endif


#include "minilib/minilib.h"


int main(int argc, char**argv, char** envp){

		char *c = "strdup.\n";

		char *d=0;
		d=strdup(c);

		c[0]='O';
		c[1]='R';
		c[2]='I';
		c[3]=' ';
		writes(c);
		writes(d);

		return(0);
}
