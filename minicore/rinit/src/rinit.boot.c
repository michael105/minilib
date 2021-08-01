#if 0
# minilib configuration
COMPILE start,printsl,fclose,strcpy,putenv,fopen,fgets,vexec,scandir,\
			  strlen,ansicolors,free_brk,match,sleep,printfs,errno_str,errno,alphasort\
			  strncpy
mini_dirbuf_malloc malloc_brk
mini_buf 512

OPTFLAG -Os
SHRINKELF
INCLUDESRC

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
