#ifndef mini_stdio_h
#define mini_stdio_h

#include "stdarg.h"


//+header stdio.h
//+depends close
//+inc

static int close(int);

//+def
static inline int __attribute__((always_inline)) fileno( FILE *f ){
		mfl_union fl;
		fl.F=f;
		return( fl.fd );
}

////+macro
//#define fileno(stream) ({union ful { FILE *F; int i, fd;};ful.F=stream;ful.fd;})


//+depends close
//+def
static inline int __attribute__((always_inline)) fclose( FILE* f ){
		return( close(fileno(f)) );
}



//+depends dprintf fileno
//+macro
#define fprintf(stream,...)  dprintf(fileno(stream),__VA_ARGS__)


//+depends dprintf fileno
//+macro
#define printf(...) fprintf(stdout,__VA_ARGS__)

#endif
