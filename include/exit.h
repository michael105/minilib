#ifndef minilib_exit_h
#define minilib_exit_h
//+ansi unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit



#ifdef X64
#define exit(ret) asm volatile ( "jmp _exit" : : "D"(ret) )
#else
#define exit(ret) asm volatile ( "jmp _exit" : : "b"(ret) )
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
