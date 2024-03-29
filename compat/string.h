/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_string_h
#define included_string_h

#warning compat headers are instable.
#warning Better include minilib.h or use minimake, when possible


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


#include "minilib/headers/common/allheaders.h"
#include "minilib/headers/linux_x64/allheaders.h"

#include "minilib/include/minilib_global.h"
#include "minilib/include/dirent.h"


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

// file: minilib/src/memory/memchr.c
void* memchr(const void *s, int c, unsigned int n);

// file: minilib/src/memory/memcmp.c
int memcmp(const void* c1,const void* c2,int len);

// file: minilib/src/memory/memcpy.c
void* memcpy( void*d, const void *s, int n );

// file: minilib/src/memory/memmove.c
void* memmove(void *dest, const void *src, int n);

// file: minilib/src/memory/memset.c
void *memset( void *s, int c, int n);

// file: minilib/src/string/strcat.c
char *strcat(char *dest, const char *src );

// file: minilib/src/string/strchr.c
char *strchr(const char *s, int c);

// file: minilib/src/string/strcmp.c
#include "minilib/src/string/strcmp.c"
// file: minilib/src/string/strcmp.c
#include "minilib/src/string/strcmp.c"
// file: minilib/src/string/strcmp.c
#include "minilib/src/string/strcmp.c"
// file: minilib/src/string/strcpy.c
char *strcpy(char *dest, const char *src);

// file: minilib/src/string/strcspn.c
int strcspn(const char *s1, const char *s2);

// file: minilib/src/string/strdup.c
char *strdup(const char *source);

// file: minilib/src/string/strerror.c
static char* strerror( int errnum );

// file: minilib/src/string/strlen.c
int strlen(const char*str);

// file: minilib/src/string/strncat.c
char* strncat( char* dst, const char* src, unsigned int n);

// file: minilib/src/string/strncpy.c
char *strncpy(char *dest, const char *src, int n);

// file: minilib/src/string/strndup.c
char *strndup(const char *source, int maxlen);

// file: minilib/src/string/strnlen.c
int strnlen(const char*str, int max);

// file: minilib/src/string/strpbrk.c
char* strpbrk(const char* s, const char* charset);

// file: minilib/src/string/strrchr.c
char *strrchr(const char *s, int c);

// file: minilib/src/string/strspn.c
int strspn(const char *s1, const char *s2);

// file: minilib/src/string/strstr.c
char* strstr(const char *big, const char *little);

// file: minilib/src/string/strtok.c
char* strtok(char *s, const char *delim);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/string/strnlen.c"
#include "minilib/src/string/strtok.c"
#include "minilib/src/string/strchr.c"
#include "minilib/src/memory/memset.c"
#include "minilib/src/string/strncpy.c"
#include "minilib/src/string/strcspn.c"
#include "minilib/src/string/strcpy.c"
#include "minilib/src/string/strerror.c"
#include "minilib/src/string/strncat.c"
#include "minilib/src/string/strndup.c"
#include "minilib/src/string/strdup.c"
#include "minilib/src/memory/memcpy.c"
#include "minilib/src/memory/memchr.c"
#include "minilib/src/string/strstr.c"
#include "minilib/src/string/strcat.c"
#include "minilib/src/string/strspn.c"
#include "minilib/src/memory/memcmp.c"
#include "minilib/src/string/strpbrk.c"
#include "minilib/src/memory/memmove.c"
#include "minilib/src/string/strlen.c"
#include "minilib/src/string/strrchr.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
