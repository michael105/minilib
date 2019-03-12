#ifndef fputs_c
#define fputs_c

#include "write.h"
#include "src/mstrlen.c"

int fputs(const char *c, int fd){
		return(write(fd, c, strlen(c)));
}



#endif
