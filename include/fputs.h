#ifndef fputs_c
#define fputs_c

include "write.h"

//+ansi stdio.h
//+inc

int strlen(const char*str);

//+def
inline int volatile fputs(const char *c, int fd){
		return(write(fd, c, strlen(c)));
}



#endif
