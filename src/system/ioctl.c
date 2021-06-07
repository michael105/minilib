#ifndef mini_ioctl_h
#define mini_ioctl_h

#include "sys/ioctl.h" //changed from linux/ioctl.h
#include "../include/stdarg.h"

//+header ioctl.h
//+def
int volatile  __attribute__((optimize("O0"))) ioctl( int fd, unsigned long int request, ... ){
		va_list args;
		va_start(args,request);

		int ret;
		syscall3(ret, SCALL(ioctl),fd,request,(long int)va_arg(args,void*));
		OPTFENCE(&ret,&fd,&request,(void*)args);
		va_end(args);
		return(ret);
}


#endif
