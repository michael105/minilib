#ifndef tcsetattr_h
#define tcsetattr_h

#ifdef OSX
#else
#endif



//+depends termio ioctl
//+def
int tcsetattr(int fd, int opt, const struct termios *io){
	return(ioctl(fd, TCSETA +opt, io));
	//return(ioctl(fd, 0x5402+opt, io));
}



#endif
