//+header stdio.h
//+depends open _fopen fileno close
//+needs lseek.h
//+doc modes implemented: r, r+, w, w+, a, a+
//+def
FILE *fdopen(int fd, const char* mode){
		return(_fopen(fd,0, mode,0));
}



