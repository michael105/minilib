/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_ioctl_h
#define included_ioctl_h

/* header.in */
// file: minilib/src/ioctl.c
int ioctl( int fd, unsigned long int request, ... );



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/ioctl.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
