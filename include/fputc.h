#ifndef fputc_c
#define fputc_c

#include "write.h"

//+header stdio.h
//+inc
//+def
static inline int volatile fputc(int c, int fd){
		write(fd, &c, 1);
		return(c);
}

//+depends fputc
//+macro  putchar(c) fputc(c,stdout)

#endif
