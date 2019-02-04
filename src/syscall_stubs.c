// These are just wrapped syscalls.
// errno is set, anyway.


#include "../include/syscall.h"

static int sysret;
extern int errno;

DEF_syscall(getpid,0 )
#ifndef OSX
DEF_syscallret(time,*a1,1,unsigned int *a1 )
#endif




