// run all executables within /etc/rinit/boot

//#define RC_BOOT "/etc/rinit/boot"
#define RC_BOOT "./test/"

#include "common.c"


int main( int argc, char **argv, char **envp ){
		log("Start stage 1");

		int r = rundir(RC_BOOT, "S*", argv, envp);

		log("stage 1 up");

		return(r);
}
