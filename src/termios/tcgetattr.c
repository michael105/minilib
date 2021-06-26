#ifndef tcgetattr_h
#define tcgetattr_h

#include <sys/termios.h>
#ifdef OSX
#else
#endif


//+depends termio ioctl
//+def
int tcgetattr(int fd, struct termios *io){
	//return(ioctl(fd, 0x5401, io));
	return(ioctl(fd, TCGETA, io));

}



#endif
