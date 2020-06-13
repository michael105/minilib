/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_stdio_h
#define included_stdio_h

// #warning compat headers are more or less instable. 
// Better include minilib.h, when possible


#ifndef mini_INCLUDESRC
#ifdef INCLUDESRC
#define mini_INCLUDESRC
#endif
#endif


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

#include "minilib/headers/common/bits/alltypes.h"
#include "minilib/include/globaldefs.h"
#include "minilib/include/minilib_global.h"
#include "minilib/include/timeval.h"
#include "minilib/headers/common/dirent.h"
#include "minilib/headers/common/bits/signal.h"
#include "minilib/headers/common/bits/stat.h"
#include "minilib/headers/common/signal.h"
#include "minilib/headers/common/ctype.h"
#include "minilib/include/ctype.h"
#include "minilib/include/syscall.h"
#include "minilib/headers/linux_x64/sys/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"



#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"

#include "include/exit.h"

#include "minilib/include/globaldefs.h"
#include "include/minilib_global.h"

#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"

#include "minilib/include/headerguards.h"

//needed for puts
#include "src/strlen.c"


// file: minilib/src/fgets.c
char* fgets(char *buf, int size, FILE* F);

// file: minilib/src/fgets.c
#define gets(F) fgets(F,0xfffffff,stdin)

// file: minilib/src/fopen.c
FILE *_fopen(int fd, const char* filename, const char* mode, FILE *f);

// file: minilib/src/fopen.c
FILE *fopen(const char* filename, const char* mode);

// file: minilib/src/fopen.c
FILE *fdopen(int fd, const char* mode);

// file: minilib/src/fopen.c
FILE *freopen(const char* filename, const char* mode, FILE *F);

// file: minilib/src/itohex.c
#include "minilib/src/itohex.c"
// file: minilib/src/strerror.c
void perror(const char *msg);

// file: minilib/include/fgetc.h
static inline int fgetc(FILE *F);

// file: minilib/include/fgetc.h
#define getc(F) fgetc(F)

// file: minilib/include/fgetc.h
#define getchar() fgetc(0)

// file: minilib/include/fgetc.h
static int ungetc(int c, FILE *F);

// file: minilib/include/fputc.h
static inline int volatile fputc(int c, FILE* F);

// file: minilib/include/fputc.h
#define putchar(c) fputc(c,stdout)

// file: minilib/include/fputc.h
#define putc(c,stream) fputc(c,stream)

// file: minilib/include/fputs.h
#include "minilib/include/fputs.h"
// file: minilib/include/mini_fstream.h
#include "minilib/include/mini_fstream.h"
// file: minilib/include/prints.h
#define puts(msg) ( print(msg) + printl() )



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/fopen.c"
#include "minilib/src/strerror.c"
#include "minilib/include/fputc.h"
#include "minilib/include/prints.h"
#include "minilib/include/fgetc.h"
#include "minilib/src/fgets.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
