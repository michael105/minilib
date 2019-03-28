/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_string_h
#define included_string_h

/* header.in */
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

// file: minilib/src/mstrlen.c
int strlen(const char*str);

// file: minilib/src/strcat.c
char *strcat(char *dest, const char *src );



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/memcpy.c"
#include "minilib/src/memset.c"
#include "minilib/src/strcat.c"
#include "minilib/src/mstrcmp.c"
#include "minilib/src/mstrlen.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
