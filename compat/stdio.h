/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_stdio_h
#define included_stdio_h

#warning compat headers are instable.
#warning Better include minilib.h or use mlcc, when possible


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

//#include "minilib/include/timeval.h"
#include "minilib/include/filemodes.h"

#include "minilib/headers/common/bits/alltypes.h"
#include "minilib/include/globaldefs.h"
#include "minilib/include/minilib_global.h"
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


#include "minilib/headers/common/allheaders.h"
#include "minilib/headers/linux_x64/allheaders.h"

#include "minilib/include/minilib_global.h"
#include "minilib/include/dirent.h"


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


// file: minilib/include/fgetc.h
#define getc(F) fgetc(F)

// file: minilib/include/fgetc.h
#define getchar() fgetc(0)

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

// file: minilib/src/conversions/itohex.c
#include "minilib/src/conversions/itohex.c"
// file: minilib/src/output/fprintf.c
#define fprintf(stream,...)	write(fileno(stream),mlgl->mbuf,snprintf(mlgl->mbuf,mlgl->mbufsize,__VA_ARGS__))

// file: minilib/src/output/perror.c
void perror(const char *msg);

// file: minilib/src/output/vsprintf.c
int vsprintf( char *buf, const char *fmt, ... );

// file: minilib/src/streams/_fopen.c
FILE *_fopen(int fd, const char* filename, const char* mode, FILE *f);

// file: minilib/src/streams/fdopen.c
FILE *fdopen(int fd, const char* mode);

// file: minilib/src/streams/fgetc.c
static inline int fgetc(FILE *F);

// file: minilib/src/streams/fgets.c
char* fgets(char *buf, int size, FILE* F);

// file: minilib/src/streams/fopen.c
#include "minilib/src/streams/fopen.c"
// file: minilib/src/streams/freopen.c
FILE *freopen(const char* filename, const char* mode, FILE *F);

// file: minilib/src/streams/gets.c
#define gets(F) fgets(F,0xfffffff,stdin)

// file: minilib/src/streams/ungetc.c
static int ungetc(int c, FILE *F);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/streams/fgetc.c"
#include "minilib/src/streams/_fopen.c"
#include "minilib/include/fgetc.h"
#include "minilib/src/streams/fgets.c"
#include "minilib/src/streams/gets.c"
#include "minilib/src/streams/ungetc.c"
#include "minilib/src/streams/fdopen.c"
#include "minilib/src/output/fprintf.c"
#include "minilib/include/prints.h"
#include "minilib/src/streams/freopen.c"
#include "minilib/src/output/perror.c"
#include "minilib/include/fputc.h"
#include "minilib/src/output/vsprintf.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
