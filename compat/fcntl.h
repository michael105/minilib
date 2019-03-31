/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_fcntl_h
#define included_fcntl_h



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


#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"

#include "include/exit.h"

#include "include/minilib_global.h"

#include "minilib/include/globaldefs.h"
#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"



#ifndef mini_buf
#define mini_buf 1024
#endif


#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"


// file: minilib/src/open.c
inline int volatile __attribute__((always_inline)) creat( const char *s, int mode );



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/open.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
