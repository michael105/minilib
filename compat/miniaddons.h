/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_miniaddons_h
#define included_miniaddons_h

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


// file: minilib/src/dtodec.c
int dtodec(double d, char* buf, int precision);

// file: minilib/src/itobin.c
int _itobin(int i, char*buf, int prec, int groups );

// file: minilib/src/itodec.c
int uitodec(unsigned int i, char *buf, int prec, char limiter );

// file: minilib/src/itodec.c
int itodec(int i, char *buf, int prec, char limiter );

// file: minilib/src/memfrob.c
void* memfrob(void* s, unsigned int len);

// file: minilib/src/print.c
int print(const char *msg);

// file: minilib/src/print.c
int printl(const char *msg);

// file: minilib/src/sprintf.c
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );

// file: minilib/src/sprintf.c
int dprintf( int fd, const char *fmt, ... );

// file: minilib/src/sprintf.c
int snprintf( char *buf, size_t size, const char *fmt, ... );

// file: minilib/include/globaldefs.h
typedef int FILE;



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/itobin.c"
#include "minilib/src/memfrob.c"
#include "minilib/src/dtodec.c"
#include "minilib/src/print.c"
#include "minilib/src/itodec.c"
#include "minilib/include/globaldefs.h"
#include "minilib/src/sprintf.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
