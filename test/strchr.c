#if 0
mini_buf 256
mini_start
mini_prints
mini_strchr
mini_strrchr
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[] ){

		char *c = "strchr\ntest\n";
		prints(c);

		char *c2 = strchr(c,'e');
		prints(c2);

		char *c3 = strchr(c,'r');
		c3 = strchr(c3+1,'r');
		prints(c3);


		char *c4 = strrchr(c,'r');
		prints(c4);

		c4 = strrchr(c,'c');
		prints(c4);

		c4 = strrchr(c,'c');
		prints(c4);


		c4 = strchr(c,'X');
		if ( c4 )
			prints(c4);
		else
				prints("ok\n");

		c4 = strrchr(c,'X');
		if ( c4 )
			prints(c4);
		else
				prints("ok\n");




		return(0);
}
