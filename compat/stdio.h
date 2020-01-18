/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
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


#include "minilib/include/timeval.h"
#include "minilib/include/filemodes.h"


#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"

#include "include/exit.h"

#include "minilib/include/globaldefs.h"
#include "include/minilib_global.h"

#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"


//needed for puts
#include "src/strlen.c"


// file: minilib/src/fopen.c
FILE *fopen(const char* filename, const char* mode);

// file: minilib/src/itohex.c
int _itohex(int i,char* buf,int padding, int capitals);

// file: minilib/src/itohex.c
int itohex(int i,char* buf,int padding);

// file: minilib/src/itohex.c
int itoHEX(int i,char* buf,int padding);

// file: minilib/src/sprintf.c
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

// file: minilib/src/sprintf.c
#define fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))

// file: minilib/src/strerror.c
void perror(char *msg);

// file: minilib/include/fgetc.h
static inline int fgetc(FILE *F);

// file: minilib/include/fgetc.h
#define getc(F) fgetc(F)

// file: minilib/include/fputc.h
static inline int volatile fputc(int c, FILE* F);

// file: minilib/include/fputc.h
#define putchar(c) fputc(c,stdout)

// file: minilib/include/fputc.h
#define putc(c,stream) fputc(c,stream)

// file: minilib/include/fputs.h
static inline int volatile fputs(const char *c, FILE *F);

// file: minilib/include/mini_fstream.h
#include "minilib/include/mini_fstream.h"
// file: minilib/include/prints.h
#define puts(msg) ( print(msg) + printl() )



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/include/fputs.h"
#include "minilib/src/fopen.c"
#include "minilib/include/fgetc.h"
#include "minilib/src/itohex.c"
#include "minilib/include/fputc.h"
#include "minilib/include/prints.h"
#include "minilib/src/sprintf.c"
#include "minilib/src/strerror.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
