#if 0
mini_buf 256
mini_start
mini_printf
mini_fprintf
mini_nanosleep
mini_sleep
mini_itodec
mini_atoi
mini_fork
mini_getenv
mini_environ
mini_INCLUDESRC
LDSCRIPT default
return
#endif

#include "minilib.h"

static char *st = "Test\n";

int main( int argc, char *argv[] ){
		printf("Static.\n");
		static int pid = 234;

		printf("Pid: %d\n",pid);
		printf("Got: %s\n",st);

		//printf("HOME: %s\n", getenv("HOME"));


		return(0);
}
