/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_stdio_h
#define included_stdio_h

// file: minilib/src/src/mfprintf.c
int fprintf(int fd, const char* fmt, ... );

// file: minilib/src/src/msprintf.c
int sprintf(char *buf, const char* fmt, ... );

// file: minilib/src/include/fputc.h
static inline int volatile fputc(int c, int fd);

// file: minilib/src/include/fputs.h
static inline int volatile fputs(const char *c, int fd);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/src/msprintf.c"
#include "minilib/src/include/fputc.h"
#include "minilib/src/src/mfprintf.c"
#include "minilib/src/include/fputs.h"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
