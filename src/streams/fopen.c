
//+header stdio.h
//+include
//+depends open _fopen fileno close
//+needs lseek.h
//+doc modes implemented: r, r+, w, w+, a, a+
//+def
FILE *fopen(const char* filename, const char* mode){
		return(_fopen(0,filename, mode,0));
}

