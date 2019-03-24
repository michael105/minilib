#ifndef tcgetattr_h
#define tcgetattr_h

//#include <sys/termios.h>
//#include "ioctl.h"
#include <sys/ttycom.h>


#ifndef TCGETS
#warning TCGETS not defined. Applying ugly hack.
#define TCGETS TIOCGETA
#endif

//+header unistd.h
//+needs sys/ttycom.h
//+depends ioctl
//+def
static inline int __attribute__((always_inline)) tcgetattr(int fd, struct termios *io){
	//return(ioctl(fd, 0x5401, io));
	return(ioctl(fd, TCGETS, io));

}



#endif
