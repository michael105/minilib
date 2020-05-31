#ifndef isatty_c
#define isatty_c
//+header unistd.h
//+include
//+depends tcgetattr
//+def
int isatty(int fd){
	struct termios term;
	return( tcgetattr(fd, &term) == 0 );
}


#endif

