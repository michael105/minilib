#ifndef select_h
#define select_h
#include "timeval.h"
//#include "syscall.h"

//+header unistd.h
//+inc

// from musl
#define FD_SETSIZE 1024

		typedef unsigned long fd_mask;

		typedef struct
		{
				  unsigned long fds_bits[FD_SETSIZE / 8 / sizeof(long)];
		} fd_set;


#define FD_ZERO(s) do { int __i; unsigned long *__b=(s)->fds_bits; for(__i=sizeof (fd_set)/sizeof (long); __i; __i--) *__b++=0; } while(0)
#define FD_SET(d, s)   ((s)->fds_bits[(d)/(8*sizeof(long))] |= (1UL<<((d)%(8*sizeof(long)))))
#define FD_CLR(d, s)   ((s)->fds_bits[(d)/(8*sizeof(long))] &= ~(1UL<<((d)%(8*sizeof(long)))))
#define FD_ISSET(d, s) !!((s)->fds_bits[(d)/(8*sizeof(long))] & (1UL<<((d)%(8*sizeof(long)))))

// end of musl 

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

