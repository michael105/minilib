/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_declarations_h
#define included_declarations_h

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


// file: minilib/include/syscall_stubs.h
DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

// file: minilib/include/syscall_stubs.h
DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

// file: minilib/include/syscall_stubs.h
DEF_syscall(dup3,3,int a1, int a2, int a3)		

// file: minilib/include/syscall_stubs.h
DEF_syscall(getcwd,2,char *buf,long size)		



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/include/syscall_stubs.h"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
