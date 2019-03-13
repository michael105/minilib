#ifndef fputs_c
#define fputs_c

#include "write.h"
int strlen(const char*str);

static int fputs(const char *c, int fd){
		return(write(fd, c, strlen(c)));
}



#endif
