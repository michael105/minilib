#ifndef minilib_exit_h
#define minilib_exit_h

//#include "syscall.h"
//#undef write
//#undef exit
static inline void __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
}


#endif
