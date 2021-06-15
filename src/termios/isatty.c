//+header unistd.h
//+include
//+depends termio tcgetattr ioctl
//+def
int isatty(int fd){
	struct termios term;
	return( tcgetattr(fd, &term) == 0 );
}

