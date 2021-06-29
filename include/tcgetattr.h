#ifndef tcgetattr_h
#define tcgetattr_h



int ioctl( int fd, unsigned long int request, ... );


//+header unistd.h
//+include
///+needs sys/ttycom.h
//+depends ioctl termio
//+def
static inline int __attribute__((always_inline)) tcgetattr(int fd, struct termios *io){
	//return(ioctl(fd, 0x5401, io));
	return(ioctl(fd, TCGETS, io));

}



#endif
