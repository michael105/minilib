/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_string_h
#define included_string_h

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

// file: minilib/src/memcpy.c
void *memcpy( void *d, const void *s, int n );

// file: minilib/src/memcpy.c
char *strcpy(char *dest, const char *src);

// file: minilib/src/memcpy.c
char *strncpy(char *dest, const char *src, int n);

// file: minilib/src/memmove.c
void* memmove(void *dest, const void *src, int n);

// file: minilib/src/memset.c
void *memset( void *s, int c, int n);

// file: minilib/src/strcat.c
char *strcat(char *dest, const char *src );

// file: minilib/src/strchr.c
char *strchrnul(const char *s, int c);

// file: minilib/src/strchr.c
char *strchr(const char *s, int c);

// file: minilib/src/strchr.c
char *strrchr(const char *s, int c);

// file: minilib/src/strcmp.c
#include "minilib/src/strcmp.c"
// file: minilib/src/strcmp.c
#include "minilib/src/strcmp.c"
// file: minilib/src/strcmp.c
#include "minilib/src/strcmp.c"
// file: minilib/src/strcmp.c
#include "minilib/src/strcmp.c"
// file: minilib/src/strcmp.c
#include "minilib/src/strcmp.c"
// file: minilib/src/strcmp.c
#include "minilib/src/strcmp.c"
// file: minilib/src/strdup.c
char *strdup(const char *source);

// file: minilib/src/strerror.c
const char* strerror( int errnum );

// file: minilib/src/strerror.c
const char *errno_str(int err);

// file: minilib/src/strlen.c
int strlen(const char*str);

// file: minilib/src/strstr.c
char* strstr(const char *big, const char *little);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/strdup.c"
#include "minilib/src/memmove.c"
#include "minilib/src/strerror.c"
#include "minilib/src/memset.c"
#include "minilib/src/strcat.c"
#include "minilib/src/strlen.c"
#include "minilib/src/strstr.c"
#include "minilib/src/strchr.c"
#include "minilib/src/memcpy.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
