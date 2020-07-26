#if 0

mini_start
mini_writes
mini_prints
mini_printfs
mini_printsl


mini_scandir
mini_match
mini_alphasort
#mini_malloc
mini_vexec
mini_strcpy

mini_errno
mini_buf 256
mini_errno_str
STRIPFLAG

mini_ansicolors

INCLUDESRC
SHRINKELF
#LDSCRIPT textandbss

return
#endif

//#define RC_BOOT "/etc/rinit/boot"
#define RC_BOOT "./test/"

#include "common.c"


int main( int argc, char **argv, char **envp ){
		log("Start stage 1");

		int r = rundir(RC_BOOT, "S*", argv, envp);

		return(0);
}
