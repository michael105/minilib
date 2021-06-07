#ifndef tcsetattr_h
#define tcsetattr_h

//#include <termios.h>
//#include "ioctl.h"
int ioctl( int fd, unsigned long int request, ... );

//#include <sys/ttycom.h>

#ifndef TCSETS
#warning TCSETS not defined. Applying ugly hack.
#define TCSETS TIOCSETA
#endif

//+needs termios.h bits/ioctl.h
//+header unistd.h
//+include
//+depends ioctl
//+def
static inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io){
	return(ioctl(fd, TCSETS +opt, io));
	//return(ioctl(fd, 0x5402+opt, io));
}



#endif
