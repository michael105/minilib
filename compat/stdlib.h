/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_stdlib_h
#define included_stdlib_h

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


#define mini_getenv
// file: minilib/src/atoi.c
int atoi(char *c);

// file: minilib/src/getenv.c
char *getenv(const char* name);

// file: minilib/src/malloc.c
void* malloc(int size);

// file: minilib/src/malloc.c
void free(void *p);

// file: minilib/src/malloc.c
void* volatile malloc(int size);

// file: minilib/src/malloc.c
void volatile free(void* p);

// file: minilib/src/rand.c
void srand( unsigned int i );

// file: minilib/src/rand.c
unsigned int rand();



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/rand.c"
#include "minilib/src/getenv.c"
#include "minilib/src/malloc.c"
#include "minilib/src/atoi.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
