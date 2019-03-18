#ifndef minilib_read_h
#define minilib_read_h

//+ansi unistd.h
//+inc

//#include "syscall.h"
#include "../macros/overrun.h"


//+def
inline int volatile __attribute__((always_inline)) read( int fd, void* buf, int len ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
		//MINI_TEST_OVERRUN(len);
		int ret;
		syscall3(ret,SCALL(read),fd,(POINTER)buf,len);
		return(ret);
}


#endif
