#if 0
mini_buf 256
mini_start
mini_printf
mini_nanosleep
mini_sleep
mini_itodec
mini_atoi
mini_fork
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[] ){
		printf("Fork.\n");

		int pid = fork();
		//printf("Pid: %d\n",pid);
		printf("Sleep 1\n");
		unsigned int i = sleep(1);
		printf("Got: %d\n",i);


		return(0);
}
