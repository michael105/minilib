#ifndef select_h
#define select_h
#include "timeval.h"
//#include "syscall.h"

//+header unistd.h
//+inc
//
//+def
static inline int volatile __attribute__((always_inline)) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait){
		int ret;
		syscall5(ret, SCALL(select),&fd,readfd,(POINTER)writefd,(POINTER)exceptfd,(POINTER) wait);
		return(ret);
}
/*
		//return(syscall5(__NR_select,(long)fd,(long)readfd,(long)writefd,(long)exceptfd, (long)wait));
		int ret;
		syscall5(ret,__NR_select,&fd,readfd,writefd,exceptfd, wait);
		return(ret);
		//return(syscall5(__NR_select,fd,readfd,,0,0));
}
*/



		//int pselect (int, fd_set *, fd_set *, fd_set *, const struct timespec *, const sigset_t *);


#endif

