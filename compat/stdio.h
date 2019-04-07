/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_stdio_h
#define included_stdio_h

#define mini_start
#define mini_exit

#ifndef mini_buf
#define mini_buf 1024
#endif



#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER int
#endif

#ifndef uint32_t
#define uint32_t uint
#endif

#ifndef uint8_t
#define uint8_t uchar
#endif

#ifndef size_t
#define size_t long
#endif


#ifndef NULL
#define NULL 0
#endif

#ifndef stdin
#define stdin 0
#endif
#ifndef stdout
#define stdout 1
#endif
#ifndef stderr
#define stderr 2
#endif

#define STDOUT_FILENO stdout
#define STDIN_FILENO stdin

#define mini_getenv

#include "minilib/include/timeval.h"
#include "minilib/include/filemodes.h"


#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"

#include "include/exit.h"

#include "include/minilib_global.h"

#include "minilib/include/globaldefs.h"
#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"


//needed for puts
#include "src/mstrlen.c"


// file: minilib/src/fopen.c
FILE *fopen(const char* filename, const char* mode);

// file: minilib/src/itohex.c
int _itohex(int i,char* buf,int padding, int capitals);

// file: minilib/src/itohex.c
int itohex(int i,char* buf,int padding);

// file: minilib/src/itohex.c
int itoHEX(int i,char* buf,int padding);

// file: minilib/src/mfprintf.c
#define printf(...) fprintf(stdout,__VA_ARGS__)

// file: minilib/src/mprint.c
#define puts(c) printl(c)

// file: minilib/src/msprintf.c
#define fprintf(stream,...)	write(fileno(stdout),ml.mbuf,sprintf(ml.mbuf

// file: minilib/include/fputc.h
#include "minilib/include/fputc.h"
// file: minilib/include/fputc.h
static inline int volatile fputc(int c, int fd);

// file: minilib/include/fputc.h
#define putchar(c) fputc(c,stdout)

// file: minilib/include/fputs.h
#include "minilib/include/fputs.h"
// file: minilib/include/fputs.h
static inline int volatile fputs(const char *c, int fd);

// file: minilib/include/mini_stdio.h
#include "minilib/include/mini_stdio.h"
// file: minilib/include/mini_stdio.h
static inline int __attribute__((always_inline)) fileno( FILE *f );

// file: minilib/include/mini_stdio.h
static inline int __attribute__((always_inline)) fclose( FILE* f );

// file: minilib/include/mini_stdio.h
#define fprintf(stream,...)  dprintf(fileno(stream),__VA_ARGS__)

// file: minilib/include/mini_stdio.h
#define printf(...) fprintf(stdout,__VA_ARGS__)

// file: minilib/include/mini_stdio.h
#define sprintf(str,fmt,...) snprintf( str, 4096, fmt, __VA_ARGS__)

// file: 
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

// file: 
static inline long ftell(FILE *f){
	 	return(lseek( fileno(f), 0, SEEK_CUR ));
}

// file: 
static inline void fgetpos(FILE *f, long *pos ){
	 	*pos = ftell(f);
}

// file: 
static inline int fsetpos(FILE *f, int pos ){
	 	int r = lseek( fileno(f), pos, SEEK_SET );
		if ( r==pos ){ //
				*f = *f & FD_MASK; // unset feof
				return(r);
		}
		return(r); // todo set errno 
}

// file: 
static inline int fseek(FILE *f, long offset, int whence ){
	 	int r = lseek( fileno(f), offset, whence );
		if ( r>0 )
				*f = *f & FD_MASK; // clear feof
		return(r);
}

// file: 
static inline void rewind( FILE *f ){
		fseek(f, 0, SEEK_SET);
}

// file: 
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

// file: minilib/include/mini_stdio.h
static inline int feof(FILE *f);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/msprintf.c"
#include "minilib/src/mfprintf.c"
#include "minilib/src/mprint.c"
#include "minilib/src/fopen.c"
#include "minilib/include/fputc.h"
#include "minilib/src/itohex.c"
#include "minilib/include/mini_stdio.h"
#include "minilib/include/fputs.h"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
