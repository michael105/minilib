#ifndef open_c
#define open_c
//+header fcntl.h
//+include


//#include "syscall.h"
#include "include/filemodes.h"

#include "include/stdarg.h"

//+def
int volatile open( const char *s, int flags, ... ){
		int ret;
		va_list args;
		va_start(args,flags);
		int mode = va_arg(args,int);
		va_end(args);
		syscall3(ret,SCALL(open),(POINTER)s,flags,mode);
#ifdef mini_errno
		if ( ret<0 )
				errno = -ret;
#endif
		return(ret);
}

/// creat
//+depends open
//+def
int volatile creat( const char *s, int mode ){
		return(open( s, O_CREAT|O_WRONLY|O_TRUNC, mode) );
}



//FILE* volatile fopen( const char *s, const char *mode ){
//		int m = 0;




#endif
