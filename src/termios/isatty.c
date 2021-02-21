//+header unistd.h
//+include
//+depends tcgetattr ioctl
//+def
int isatty(int fd){
	struct termios term;
	return( tcgetattr(fd, &term) == 0 );
}

