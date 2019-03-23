#ifndef tcsetattr_h
#define tcsetattr_h

//#include <termios.h>
//#include "ioctl.h"
#ifdef OSX
//#include <sys/ttycom.h>
#else
#include <sys/ioctl.h>
#endif



#ifndef TCSETS
//#warning TCSETS not defined. Applying ugly hack.
#define TCSETS TIOCSETA
#endif

int tcsetattr(int fd, int opt, const struct termios *io)
{
	return(ioctl(fd, TCSETS +opt, io));
	//return(ioctl(fd, 0x5402+opt, io));
}



#endif
