/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_mini_addons_h
#define included_mini_addons_h

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


// file: minilib/src/basename.c
char *basename(char *path);

// file: minilib/src/dtodec.c
int dtodec(double d, char* buf, int precision);

// file: minilib/src/fprintfs.c
int fprintfs( FILE* F, char *fmt, ...);

// file: minilib/src/itobin.c
int _itobin(int i, char*buf, int prec, int groups );

// file: minilib/src/itobin.c
#define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

// file: minilib/src/itodec.c
int uitodec(unsigned int i, char *buf, int prec, char limiter );

// file: minilib/src/itodec.c
int itodec(int i, char *buf, int prec, char limiter );

// file: minilib/src/memfrob.c
void* memfrob(void* s, unsigned int len);

// file: minilib/src/mstrcmp.c
int _strcmp(const char*c1,const char*c2,int len);

// file: minilib/src/prints.c
#define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)

// file: minilib/src/sprintf.c
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );

// file: minilib/src/sprintf.c
int dprintf( int fd, const char *fmt, ... );

// file: minilib/src/sprintf.c
int snprintf( char *buf, size_t size, const char *fmt, ... );

// file: minilib/include/globaldefs.h
typedef int FILE;

// file: minilib/include/prints.h
#define prints(...) _mprints(__VA_ARGS__,0)

// file: minilib/include/prints.h
#define fprints(F,str) write(fileno(F),str,strlen(str))

// file: minilib/include/prints.h
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

// file: minilib/include/prints.h
#define print(str) write(STDOUT_FILENO,str,strlen(str))

// file: minilib/include/prints.h
#define writes(str) write(STDOUT_FILENO,str,sizeof(str))

// file: minilib/include/prints.h
#define fwrites(fd,str) write(fd,str,sizeof(str))

// file: minilib/include/prints.h
#define printl() write(STDOUT_FILENO,"\n",1)



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/mstrcmp.c"
#include "minilib/include/prints.h"
#include "minilib/include/globaldefs.h"
#include "minilib/src/sprintf.c"
#include "minilib/src/basename.c"
#include "minilib/src/itodec.c"
#include "minilib/src/memfrob.c"
#include "minilib/src/itobin.c"
#include "minilib/src/prints.c"
#include "minilib/src/fprintfs.c"
#include "minilib/src/dtodec.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
