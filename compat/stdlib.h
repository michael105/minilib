/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_stdlib_h
#define included_stdlib_h

#warning compat headers are instable.
#warning Better include minilib.h or use mini-gcc, when possible


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

#define mini_getenv
// file: minilib/src/abort.c
void abort();

// file: minilib/src/atexit.c
static int atexit( functionp* func );

// file: minilib/src/atoi.c
int atoi(const char *c);

// file: minilib/src/atoi.c
long atol(const char *c);

// file: minilib/src/getenv.c
char* getenv(const char* name);

// file: minilib/src/malloc.c
#include "minilib/src/malloc.c"
// file: minilib/src/qsort.c
void qsort(void  *base,	size_t nel,	size_t width,	int (*comp)(const void *, const void *));

// file: minilib/src/rand.c
void srand( unsigned int i );

// file: minilib/src/rand.c
unsigned int rand();

// file: minilib/src/strtol.c
long int strtol(const char *c, const char **endp, int base);

// file: minilib/src/system.c
int system( const char* command );

// file: minilib/include/math.h
static div_t div(int numerator, int denominator);

// file: minilib/include/math.h
static ldiv_t ldiv(long int numerator, long int denominator);

// file: minilib/include/math.h
static int abs(int i);

// file: minilib/include/math.h
static long int labs(long int i);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/getenv.c"
#include "minilib/src/qsort.c"
#include "minilib/src/abort.c"
#include "minilib/src/rand.c"
#include "minilib/src/system.c"
#include "minilib/src/strtol.c"
#include "minilib/src/atexit.c"
#include "minilib/src/atoi.c"
#include "minilib/include/math.h"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
