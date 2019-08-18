#ifndef fputc_c
#define fputc_c

//#include "write.h"

//+header stdio.h
//+depends fileno write
//+needs mini_fstream.h
//+inc
//+def
static inline int volatile fputc(int c, FILE* F){
		write(fileno(F), &c, 1);
		return(c);
}

//+depends fputc
//+macro  putchar(c) fputc(c,stdout)

#endif
