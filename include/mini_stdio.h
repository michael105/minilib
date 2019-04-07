#ifndef mini_stdio_h
#define mini_stdio_h

#include "stdarg.h"

#ifndef SEEK_SET
#define SEEK_SET        0       /* seek relative to beginning of file */
#define SEEK_CUR        1       /* seek relative to current file position */
#define SEEK_END        2       /* seek relative to end of file */
#define SEEK_MAX        SEEK_END
#endif



//+header stdio.h
//+depends close
//+inc

static int close(int);
static int read(int fd, void *buf, int len);

//+def
static inline int __attribute__((always_inline)) fileno( FILE *f ){
		return( *f & FD_MASK );
}

////+macro
//#define fileno(stream) ({union ful { FILE *F; int i, fd;};ful.F=stream;ful.fd;})


//+depends close
//+def
static inline int __attribute__((always_inline)) fclose( FILE* f ){
		int fd = *f;
		*f = -1;
		// empty garbage; go back to first closed stream
		if ( f[1] == ml.stream[ml.pstream] )
				for ( ml.pstream--; ml.stream[ml.pstream-1] == -1; ml.pstream-- ); 

		return( close(fd) );
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

// I'm really uncertain about the size arg here, amongst others



//+depends write
//+inline
static inline size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f){
		const void *p = ptr;
		int a;
		for ( a = 0; a<nmemb; a++ ){
				if ( write( fileno(f), p, size ) != size ){
						*f = *f | ERR_FLAG;
						return(a);
				}
				p = p + size;
		}
		return(a);
}

//+depends lseek
//+inline
static inline long ftell(FILE *f){
	 	return(lseek( fileno(f), 0, SEEK_CUR ));
}

//+depends ftell
//+inline
static inline void fgetpos(FILE *f, long *pos ){
	 	*pos = ftell(f);
}

//+depends lseek
//+inline
static inline int fsetpos(FILE *f, int pos ){
	 	int r = lseek( fileno(f), pos, SEEK_SET );
		if ( r==pos ){ //
				*f = *f & FD_MASK; // unset feof
				return(r);
		}
		return(r); // todo set errno 
}



//+depends lseek
//+inline
static inline int fseek(FILE *f, long offset, int whence ){
	 	int r = lseek( fileno(f), offset, whence );
		if ( r>0 )
				*f = *f & FD_MASK; // clear feof
		return(r);
}


//+depends fseek
//+inline
static inline void rewind( FILE *f ){
		fseek(f, 0, SEEK_SET);
}

//+depends read
//+inline
static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f){
		void *p = ptr;
		int a;
		for ( a = 0; a<nmemb; a++ ){
				if ( read( fileno(f), p, size ) != size ){
						*f = *f | FEOF_FLAG ; // set feof. Could also have been another error.
						return(a);
				}
				p = p + size;
		}
		return(a);
}

//todo: case eagain


///+depends _fread
///+macro
//#define fread(ptr,size,nmemb,f) ((_fread(ptr,size,nmemb,f)==nmemb) ? nmemb : ((int)(f=((int)f|FEOF_FLAG))&0x3fffffff))
	

//+def
static inline int feof(FILE *f){
		if ( *f & 0xc0000000 )
				return(1);
		return(0);
}



#endif