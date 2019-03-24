#ifndef minilib_open_h
#define minilib_open_h
/// +header fcntl.h
/// +inc 


#if 0
//#include "syscall.h"
#include "filemodes.h"

#include "stdarg.h"

/// open compiles only defined static. (???)
/// +def
int volatile open( const char *s, int flags, ... ){
		int ret;
		va_list args;
		va_start(args,flags);
		int mode = va_arg(args,int);
		va_end(args);

		syscall3(ret,SCALL(open),(POINTER)s,flags,mode);
		return(ret);
}

/// creat
//d open
/// +def
inline int volatile __attribute__((always_inline)) creat( const char *s, int mode ){
		return(open( s, O_CREAT|O_WRONLY|O_TRUNC, mode) );
}
#endif

#endif
