#if 0
mini_buf 256
mini_start
mini_prints
mini_strstr
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[] ){

		char *c = "strstr\ntest\n";
		prints(c);

		char *c2 = strstr(c,"te");
		prints(c2);

		c2 = strstr(c,"str");
		prints(c2);

		c2 = strstr(c,"rstr");
		prints(c2);




		c2 = strstr(c,"x");
		if ( c2 )
			prints(c2);
		else
				prints("ok\n");

		c2 = strstr(c,"");
		if ( c2 )
			prints(c2);
		else
				prints("Not ok\n");


		return(0);
}
