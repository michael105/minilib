#if 0
mini_buf 256
mini_start
mini_prints
mini_printf
mini_itodec
mini_djb2_hash
mini_INCLUDESRC
return
#endif

#include "minilib.h"


int main( int argc, char *argv[] ){
		const char *c = "testhash";
		union {
				int i[2];
				long l;
		} u;
		if ( argc > 1 )
				u.l = djb2_hash((unsigned char*)argv[1]);
		else
				u.l = djb2_hash((uchar*)c);
		printf("%d%d\n",u.i[0],u.i[1]);
		return(0);
}
