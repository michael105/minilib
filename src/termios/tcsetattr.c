#ifndef tcsetattr_h
#define tcsetattr_h

#ifdef OSX
//#include <sys/ttycom.h>
#else
//#include <sys/ioctl.h>
#endif

//#ifndef TCSETS
//#warning TCSETS not defined. Applying ugly hack.
//#define TCSETS TIOCSETA
//#endif


//+depends termio ioctl
//+def
int tcsetattr(int fd, int opt, const struct termios *io){
	return(ioctl(fd, TCSETA +opt, io));
	//return(ioctl(fd, 0x5402+opt, io));
}



#endif
