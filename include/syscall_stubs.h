#ifndef SYSCALL_STUBS
#define SYSCALL_STUBS
/*
 These are just wrapped syscalls.
 errno is set, anyway.

 The arguments need to be named a1,a2,..

*/

//+header declarations.h

#include "timeval.h"
//#include "syscall.h"
//#include "sys/types.h"
//#include "sys/syscall.h"

extern int sysret;
extern int errno;

struct stat;


DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )

DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )


DEF_syscall(write,3,int a1,const void *a2, int a3 )
//rename a1=oldpath a2=newpath
DEF_syscall(rename,2, const char* a1, const char* a2 )		
DEF_syscall(unlink,1, const char* a1)		

DEF_syscall(fstat,2,int a1,struct stat* a2)		
DEF_syscall(dup,1,int a1)		
DEF_syscall(dup2,2,int a1, int a2)		
DEF_syscall(dup3,3,int a1, int a2, int a3)		

#ifndef OSX
DEF_syscallret(time,*a1,1,unsigned int *a1 )
#else

#endif




#endif
