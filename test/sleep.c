#if 0
mini_buf 256
mini_start
mini_printf
mini_nanosleep
mini_sleep
mini_strlen
mini_itodec

if [ -n "$CLANG" ]; then
# clang needs memcpy defined here, used within uitodec. (??)
	mini_memcpy
# clang makes trouble with optimizations > O1 and fork
	OPTFLAG -O1
fi

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
		if ( !pid){
			printf("pid\n");
			unsigned int i = sleep(1);
			printf("pid . sl\n");
			printf("Got: %d\n",i);
		} else {
			printf("nopid\n");
		}


		return(0);
}
