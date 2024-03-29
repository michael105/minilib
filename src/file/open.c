#ifndef open_c
#define open_c
//+header fcntl.h
//+include


#include "include/filemodes.h"

#include "macros/stdarg.h"

//+doc open or create a file.
// warning: when using the flag O_CREAT,
// file permission flags have to be given
// as third argument. Otherwise file permission
// flags will be random. (I still do not know, what 
// the flag showing up as "-T" means..)
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

//FILE* volatile fopen( const char *s, const char *mode ){
//		int m = 0;




#endif
