#ifndef fputs_h
#define fputs_h

//#include "write.h"


//+header stdio.h
//+include

int strlen(const char*str);

//+depends strlen fileno write
//+needs mini_fstream.h
//+inline
static inline int volatile fputs(const char *c, FILE *F){
		return(write(fileno(F), c, strlen(c)));
}



#endif
