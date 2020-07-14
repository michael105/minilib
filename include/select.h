#ifndef select_h
#define select_h
//#include "syscall.h"

//+header unistd.h
//+inc
//
//+def
static int volatile __attribute__((optimize("O0"))) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait){
#if 0
		int ret;
		int tmp = fd;
		syscall5(ret, SCALL(select),tmp,(POINTER)readfd,(POINTER)writefd,(POINTER)exceptfd,(POINTER) wait);
		return(ret);
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"


		// somehow, when using fd directly, this leads to trouble. 
		// might be gcc related.
		int sysret = fd;
		//__DO_syscall( 5, (SCALL(name) | NCONST ) );
		register long int r10 asm ("r10") = exceptfd; 
		register long int r8 asm ("r8") = wait;
		__SYSCALL_ASM(sysret,__NR_select) , "D" (sysret), "S" (readfd), "d" (writefd), "r" (r10), "r" (r8) __callend;

#ifdef mini_errno
		if ( sysret<0){
				errno = -sysret;
				return(-1);}
#endif
		return(sysret);

#pragma GCC diagnostic pop
#endif
}

#endif

