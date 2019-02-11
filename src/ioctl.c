#ifndef mini_ioctl_h
#define mini_ioctl_h

//#include "../include/syscall.h"
#ifdef LINUX
#include <linux/ioctl.h> //changed from linux/ioctl.h
#else
#include <sys/ioctl.h> //changed from linux/ioctl.h
#endif
#include "../include/stdarg.h"
//#include "/usr/diet/include/stdarg.h"


int ioctl( int fd, unsigned long int request, ... ){
		va_list args;
		va_start(args,request);

		int ret;
		syscall3(ret, SCALL(ioctl),fd,request,(long int)va_arg(args,void*));
		va_end(args);
		return(ret);
}


#endif
