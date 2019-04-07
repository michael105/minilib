#ifndef mini_stdio_h
#define mini_stdio_h

#include "stdarg.h"


//+header stdio.h
//+depends close
//+inc

static int close(int);
static int read(int fd, void *buf, int len);

//+def
static inline int __attribute__((always_inline)) fileno( FILE *f ){
		mfl_union fl;
		fl.F=f;
		return( fl.fd & FLAG_MASK );
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


//+depends snprintf
//+macro 
#define sprintf(str,fmt,...) snprintf( str, 4096, fmt, __VA_ARGS__)

// I'm really uncertain about the size arg here,


//+depends write
//+inline
static inline size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f){
		const void *p = ptr;
		mfl_union fl;
		fl.F = f;
		int a;
		for ( a = 0; a<nmemb; a++ ){
				if ( write( fl.fd, p, size ) != size ){
						fl.fd = fl.fd | ERR_FLAG;
						return(a);
				}
				p = p + size;
		}
		return(a);
}


//+depends read
//+inline
static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f){
		void *p = ptr;
		mfl_union fl;
		fl.F = f;
		int a;
		for ( a = 0; a<nmemb; a++ ){
				if ( read( fl.fd, p, size ) != size ){
						f = (int)f | FEOF_FLAG;
						write(stderr,"EOF\n", 4);
						return(a);
				}
				p = p + size;
		}
		return(a);
}


//+def
static inline int feof(FILE *f){
		mfl_union fl;
		fl.F = f;
		if ( fl.fd & (!FLAG_MASK) )
				return(1);
		return(0);
}



#endif
