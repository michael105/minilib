#ifndef minilib_write_h
#define minilib_write_h

//+ansi unistd.h
//+inc

//#include "syscall.h"
//#undef write
/*static inline int __attribute__((always_inline)) write( int fd, const char *s, int len ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
		int ret;
		syscall3(ret,__NR_write,fd,(int)s,len);
//  asm volatile ("call *__mini_vsys"
//					: "=a" (ret): "a" (4) , "b" (fd), "c" ((int)s), "d" (len) : "memory" ); //WORKS! FINALLY

		return(ret);
}*/
// +64 bytes.
DEF_syscall(write,3,int a1,const void *a2, int a3 )


/*volatile static inline int __attribute__((always_inline)) write( register int fd, const char *s, int len ){
		register int a asm("a") = 4;
		register int b asm("b") = fd;
		register int c asm("c") = (int)s;
		register int d asm("d") = len;
		__asm__ volatile( "call *__mini_vsys");

		return(0);
}*/


#endif
