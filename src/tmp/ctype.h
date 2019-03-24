/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_ctype_h
#define included_ctype_h

// file: minilib/src/include/isprint.h
static inline int __attribute__((always_inline)) isprint(const char c);

// file: minilib/src/src/isspace.c
int isspace(int c);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/src/isspace.c"
#include "minilib/src/include/isprint.h"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
