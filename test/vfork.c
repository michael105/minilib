#if 0
mini_buf 256
mini_start
mini_printf
mini_nanosleep
mini_sleep
mini_itodec
mini_atoi
mini_vfork
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[], char *envp[] ){
		printf("Fork.\n");

		int pid = vfork();
		if ( pid ){
			printf("Pid: > 0\n" );
		} else {
			printf("Pid 0\n" );
			execve("./vforked", (char* const*)argv, (char* const*)envp );
			printf("exec ERROR\n");
		}

		printf("Sleep 20ms\n");

		struct timespec ts = { .tv_sec = 0, .tv_nsec = 20000000 };
    nanosleep(&ts, 0);

		printf("Ok.\n");


		return(0);
}
