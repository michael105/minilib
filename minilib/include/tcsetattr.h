#ifndef tcsetattr_h
#define tcsetattr_h

//#include <termios.h>
//#include "ioctl.h"

#include <sys/ttycom.h>

#ifndef TCSETS
#warning TCSETS not defined. Applying ugly hack.
#define TCSETS TIOCSETA
#endif

//+needs sys/ttycom.h termios.h
//+ansi unistd.h
//+depends ioctl
//+def
inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io){
	return(ioctl(fd, TCSETS +opt, io));
	//return(ioctl(fd, 0x5402+opt, io));
}



#endif
