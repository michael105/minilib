#if 0
source minilib.conf
return
#endif

// run all executables within /etc/rinit/boot

#include "config.h"

#include "common.c"


int main( int argc, char **argv, char **envp ){
		log("Start stage 1");

		putenv("PATH=" PATH );

		int r = rundir(RC_BOOT_PATH, 'B', argv, envp);

		log("stage 1 up");

		return(r);
}
