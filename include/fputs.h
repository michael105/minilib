#ifndef fputs_h
#define fputs_h

//#include "write.h"


//+header stdio.h
//+inc

int strlen(const char*str);

//+depends strlen fileno write
//+def
static inline int volatile fputs(const char *c, FILE *F){
		return(write(fileno(F), c, strlen(c)));
}



#endif
