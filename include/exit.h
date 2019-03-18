#ifndef minilib_exit_h
#define minilib_exit_h
//+ansi unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit

//+def
inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
}


#endif
