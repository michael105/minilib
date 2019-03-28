/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_stdio_h
#define included_stdio_h

/* header.in */
#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"

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


// file: minilib/src/mfprintf.c
int fprintf(int fd, const char* fmt, ... );

// file: minilib/src/msprintf.c
int sprintf(char *buf, const char* fmt, ... );

// file: minilib/include/fputc.h
static inline int volatile fputc(int c, int fd);

// file: minilib/include/fputs.h
static inline int volatile fputs(const char *c, int fd);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/include/fputs.h"
#include "minilib/include/fputc.h"
#include "minilib/src/mfprintf.c"
#include "minilib/src/msprintf.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
