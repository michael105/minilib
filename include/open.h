#ifndef minilib_open_h
#define minilib_open_h

#include "syscall.h"
#include "filemodes.h"

//#undef open
static inline int __attribute__((always_inline)) open( const char *s, int flags, int mode ){
		int ret;
		syscall3(ret,SCALL(open),(POINTER)s,flags,mode);
		return(ret);
}


static inline int __attribute__((always_inline)) creat( const char *s, int mode ){
		return(open( s, O_CREAT|O_WRONLY|O_TRUNC, mode) );
}


#endif
