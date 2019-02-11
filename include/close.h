#ifndef minilib_close_h
#define minilib_close_h

//#include "syscall.h"
static inline int __attribute__((always_inline)) close( int fd ){
		int ret;
		syscall1(ret,SCALL(close),(int)fd);
		return(ret);
}


#endif
