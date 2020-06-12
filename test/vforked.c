#if 0
mini_buf 256
mini_start
mini_printf
mini_nanosleep
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[] ){

		struct timespec ts = { .tv_sec = 0, .tv_nsec = 40000000 };
    nanosleep(&ts, 0);

		printf("executed by child, bye.\n");


		return(0);
}
