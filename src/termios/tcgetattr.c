#ifndef tcgetattr_h
#define tcgetattr_h

#include <sys/termios.h>
//#include "ioctl.h"
#ifdef OSX
//#include <sys/ttycom.h>
#else
//#include <sys/ioctl.h>
#endif

//#ifndef TCGETS
//#warning TCGETS not defined. Applying ugly hack.
//#define TCGETS TIOCGETA
//#endif

//+depends termio ioctl
//+def
int tcgetattr(int fd, struct termios *io){
	//return(ioctl(fd, 0x5401, io));
	return(ioctl(fd, TCGETA, io));

}



#endif
