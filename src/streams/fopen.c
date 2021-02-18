#ifndef mini_fopen_c
#define mini_fopen_c


//+header stdio.h
//+depends open _fopen fileno close
//+needs lseek.h
//+doc modes implemented: r, r+, w, w+, a, a+
//+def
FILE *fopen(const char* filename, const char* mode){
		return(_fopen(0,filename, mode,0));
}


//+header stdio.h
//+depends open _fopen fileno close
//+needs lseek.h
//+doc modes implemented: r, r+, w, w+, a, a+
//+def
FILE *fdopen(int fd, const char* mode){
		return(_fopen(fd,0, mode,0));
}


//+header stdio.h
//+depends open _fopen fileno close
//+needs lseek.h
//+doc modes implemented: r, r+, w, w+, a, a+
//+def
FILE *freopen(const char* filename, const char* mode, FILE *F){
		return(_fopen(0,filename, mode,F));
}


#endif

