#ifndef fputc_c
#define fputc_c

#include "write.h"

//+ansi stdio.h
//+inc
//+def
static inline int volatile fputc(int c, int fd){
		write(fd, &c, 1);
		return(c);
}



#endif
