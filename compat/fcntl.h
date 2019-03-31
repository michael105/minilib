/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_fcntl_h
#define included_fcntl_h

/* header.in */

#include "minilib/include/globaldefs.h"
#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/include/timeval.h"
#include "minilib/headers/common/sys/types.h"


#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"


// file: minilib/src/open.c
inline int volatile __attribute__((always_inline)) creat( const char *s, int mode );



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/open.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
