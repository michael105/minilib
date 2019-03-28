/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_stdlib_h
#define included_stdlib_h

/* header.in */
// file: minilib/src/atoi.c
int atoi(char *c);

// file: minilib/src/malloc.c
void* malloc(int size);

// file: minilib/src/malloc.c
void free(void *p);

// file: minilib/src/malloc.c
void* volatile malloc(int size);

// file: minilib/src/malloc.c
void volatile free(void* p);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/malloc.c"
#include "minilib/src/atoi.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
