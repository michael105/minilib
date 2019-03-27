/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_ctype_h
#define included_ctype_h

/* header.in */
// file: minilib/src/isspace.c
int isspace(int c);

// file: minilib/include/isprint.h
static inline int __attribute__((always_inline)) isprint(const char c);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/include/isprint.h"
#include "minilib/src/isspace.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
