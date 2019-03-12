#ifndef fputc_c
#define fputc_c

#include "write.h"


int fputc(int c, int fd){
		write(fd, &c, 1);
		return(c);
}



#endif
