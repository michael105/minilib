
//+header stdio.h
//+depends open _fopen fileno close
//+needs lseek.h
//+doc modes implemented: r, r+, w, w+, a, a+
//+def
FILE *freopen(const char* filename, const char* mode, FILE *F){
		return(_fopen(0,filename, mode,F));
}


