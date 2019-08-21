#ifndef mini_fstream_h
#define mini_fstream_h

#include "stdarg.h"

#ifndef SEEK_SET
#define SEEK_SET        0       /* seek relative to beginning of file */
#define SEEK_CUR        1       /* seek relative to current file position */
#define SEEK_END        2       /* seek relative to end of file */
#define SEEK_MAX        SEEK_END
#endif


#ifdef mini_buf
#ifndef mini_fstream
#define mini_fstream
#endif
#endif


//+header stdio.h
//+include
//+after read close

//+doc This does nothing, since minilib doesn't provide buffered streams yet.
//+doc in order to sync the stream, please use fsync
//+inline
static inline int __attribute__((always_inline)) fflush( FILE *F ){
		return(0);
}



#ifndef mini_fstream


//+inline
static inline int __attribute__((always_inline)) fileno( FILE *F ){
		if ( F==stdin )
				return ( 0 );
		if ( F==stdout )
				return(1);
		if ( F==stderr )
	  		return(2);
		exit(-1);
		return(-1);
}

#else

int snprintf( char *buf, size_t size, const char *fmt, ... );

//+inline
static inline int __attribute__((always_inline)) fileno( FILE *f ){
		return( *f & FD_MASK );
}

////+macro
//#define fileno(stream) ({union ful { FILE *F; int i, fd;};ful.F=stream;ful.fd;})


//+depends close
//+inline
static inline int __attribute__((always_inline)) fclose( FILE* f ){
		int fd = *f;
		*f = -1;
		// empty garbage; go back to first closed stream
		if ( f[1] == ml.stream[ml.pstream] )
				for ( ml.pstream--; ml.stream[ml.pstream-1] == -1; ml.pstream-- ); 

		return( close(fd) );
}

#if 0
#ifndef fprintf
#ifndef mini_sprintf
#define mini_sprintf

///+depends dprintf fileno sprintf
///+def
//#define fprintf(stream,...)  dprintf(fileno(stream),__VA_ARGS__)

#endif
#endif 

#endif

//+depends fprintf fileno
//+macro
#define printf(...) fprintf(stdout,__VA_ARGS__)


//+depends fprintf
//+macro
#define vfprintf(...) fprintf(__VA_ARGS__)



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
	

//+inline
static inline int feof(FILE *f){
		if ( *f & FLAG_MASK )
				return(1);
		return(0);
}

//+inline
static inline int ferror(FILE *f){
		if ( *f & FLAG_MASK )
				return(1);
		return(0);
}

//+inline
static inline void clearerror(FILE *f){
		*f = *f & FD_MASK;
}


//+doc dummy functions.
// There is no buffering implemented for the streams yet.
//+def
void setbuf(FILE *stream, char *buf){
}
//+doc dummy
//+def
int setvbuf(FILE *stream, char *buf, int mode, size_t size){
		return(0);
}



// ifdef mini_fstream
#endif 


#endif
