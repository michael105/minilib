#if 0

mini_start
mini_printf
mini_itodec
mini_div
mini_ldiv
mini_buf 1024
mini_INCLUDESRC

return
#endif


#include "minilib/minilib.h"


int main( int argc, char *argv[] ){

		div_t r = div(9,4);
		printf("quot: %d, rem: %d\n",r.quot,r.rem);
		r = div(-9,4);
		printf("quot: %d, rem: %d\n",r.quot,r.rem);
		r = div(9,-4);
		printf("quot: %d, rem: %d\n",r.quot,r.rem);

		return(0);
}


