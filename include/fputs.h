#ifndef fputs_h
#define fputs_h



//+header stdio.h
//+needs mini_fstream.h
//+include

int strlen(const char*str);
// after doesnt ork here. inline. so here's the predef.
// need to rethink the dependency build process
//static int fileno(FILE*);

//+needs mini_fstream.h
//+after fileno
//+depends strlen fileno write
//+def
static inline int volatile fputs(const char *c, FILE *F){
		return(write(fileno(F), c, strlen(c)));
}



#endif
