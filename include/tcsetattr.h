#ifndef tcsetattr_h
#define tcsetattr_h

int ioctl( int fd, unsigned long int request, ... );


#ifndef TCSETS
#warning TCSETS not defined. Applying ugly hack.
#define TCSETS TIOCSETA
#endif

//+needs termios.h bits/ioctl.h
//+header unistd.h
//+include
//+depends ioctl termio
//+def
static inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io){
	return(ioctl(fd, TCSETS +opt, io));
	//return(ioctl(fd, 0x5402+opt, io));
}



#endif
