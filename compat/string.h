/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_string_h
#define included_string_h

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


// file: minilib/src/memcpy.c
void *memcpy( void *d, const void *s, int n );

// file: minilib/src/memcpy.c
char *strcpy(char *dest, const char *src);

// file: minilib/src/memcpy.c
char *strncpy(char *dest, const char *src, int n);

// file: minilib/src/memset.c
void *memset( void *s, int c, int n);

// file: minilib/src/mstrcmp.c
int strcmp(const char*c1,const char*c2);

// file: minilib/src/mstrcmp.c
int strncmp(const char*c1,const char*c2,int len);

// file: minilib/src/mstrcmp.c
int memcmp(const void* c1,const void* c2,int len);

// file: minilib/src/strcat.c
char *strcat(char *dest, const char *src );

// file: minilib/src/strerror.c
char* strerror( int errnum );

// file: minilib/src/strlen.c
int strlen(const char*str);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/mstrcmp.c"
#include "minilib/src/strlen.c"
#include "minilib/src/strcat.c"
#include "minilib/src/memset.c"
#include "minilib/src/strerror.c"
#include "minilib/src/memcpy.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
