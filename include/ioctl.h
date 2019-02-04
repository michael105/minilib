#ifndef mini_ioctl_h
#define mini_ioctl_h

#include "syscall.h"
#include <asm-generic/ioctl.h> //changed from linux/ioctl.h
#include "../include/stdarg.h"
//#include "/usr/diet/include/stdarg.h"


static int ioctl( int fd, unsigned long int request, ... ){
		va_list args;
		va_start(args,request);

		int ret;
		syscall3(ret,SCALL(ioctl),fd,request,(int)va_arg(args,void*));
		va_end(args);
		return(ret);
}


#endif
