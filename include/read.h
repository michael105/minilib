#ifndef minilib_read_h
#define minilib_read_h

#include "syscall.h"
#include "../macros/overrun.h"

static inline int __attribute__((always_inline)) read( int fd, char *buf, int len ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
		//MINI_TEST_OVERRUN(len);
		int ret;
		syscall3(ret,SCALL(read),fd,(long int)buf,len);
		return(ret);
}


#endif
