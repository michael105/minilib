#ifndef SYSCALL_STUBS
#define SYSCALL_STUBS
/*
 These are just wrapped syscalls.
 errno is set, anyway.

 The arguments need to be named a1,a2,..

*/

#include "timeval.h"
#include "syscall.h"
#include "sys/types.h"
#include "sys/syscall.h"

static int sysret;
extern int errno;



DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )

DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )


//rename a1=oldpath a2=newpath
DEF_syscall(rename,2, const char* a1, const char* a2 )		
DEF_syscall(unlink,1, const char* a1)		


#ifndef OSX
DEF_syscallret(time,*a1,1,unsigned int *a1 )
#else

#endif




#endif
