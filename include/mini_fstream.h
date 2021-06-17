#ifndef inc_mini_fstream_h
#define inc_mini_fstream_h

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
//+doc In order to sync data to disc, please use fsync
//+inline
static inline int __attribute__((always_inline)) fflush( FILE *F ){
		return(0);
}



#ifndef mini_fstream

//+doc Return the fd nummber of stdin,-out,-err. 
// this is a boilerplate, in case, no minibuf and no streams are compiled.
//+def
static int fileno( FILE *F ){
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

//+doc Return the fd nummber of stdin,-out,-err. 
//+def
static int fileno( FILE *f ){
		return( (f==0) ? 0 : (*f & FD_MASK) );
}

////+macro
//#define fileno(stream) ({union ful { FILE *F; int i, fd;};ful.F=stream;ful.fd;})

#ifdef mini_fclose

//+depends close
//+inline
static inline int __attribute__((always_inline)) fclose( FILE* f ){
		int fd = fileno(f);
		*f = -1;
		// empty garbage; go back to first closed stream
		if ( f[1] == mlgl->stream[mlgl->pstream] )
				for ( mlgl->pstream--; mlgl->stream[mlgl->pstream-1] == -1; mlgl->pstream-- ); 

		return( close(fd) );
}

#endif

//+depends fprintf fileno snprintf vsnprintf write strlen
//+macro
#define printf(...) fprintf(stdout,__VA_ARGS__)

//+depends fprintf fileno snprintf vsnprintf write strlen
//+macro
#define fprint(...) fprintf(__VA_ARGS__)


//+depends fprintf fileno snprintf vsnprintf write strlen
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

#ifdef mini_lseek
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
#endif

#ifdef mini_fread

//+depends read
//+inline
static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f){
		void *p = ptr;
		int a;
		for ( a = 0; a<nmemb; a++ ){
				if ( read( fileno(f), p, size ) != size ){
						*f = *f | FEOF_FLAG ; // set feof. Could have also been another error.
						return(a);
				}
				p = p + size;
		}
		return(a);
}

#endif

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
static inline void clearerr(FILE *f){
		*f = *f & FD_MASK;
}

//+inline
static inline void clearerror(FILE *f){
		*f = *f & FD_MASK;
}


//+doc dummy function.
// There is no buffering implemented for the streams yet.
//+def
static void setbuf(FILE *stream, char *buf){
}

//+doc dummy function
//+def
static int setvbuf(FILE *stream, char *buf, int mode, size_t size){
		return(0);
}




// ifdef mini_fstream
#endif 


#endif
