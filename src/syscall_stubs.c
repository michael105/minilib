// These are just wrapped syscalls.
// errno is set, anyway.
#ifndef SYSCALL_STUBS
#define SYSCALL_STUBS

//#include "../include/syscall.h"

static int sysret;
extern int errno;



DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )

DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

#ifndef OSX
DEF_syscallret(time,*a1,1,unsigned int *a1 )
#else

#endif




#endif
