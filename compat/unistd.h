/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_unistd_h
#define included_unistd_h

/* header.in */

#include "sys/termios.h"
#include "ioctl.h"
// file: minilib/src/open.c
int volatile open( const char *s, int flags, ... );

// file: minilib/include/close.h
#include "minilib/include/close.h"
// file: minilib/include/close.h
static inline int volatile __attribute__((always_inline)) close( int fd );

// file: minilib/include/exit.h
#include "minilib/include/exit.h"
// file: minilib/include/lseek.h
#include "minilib/include/lseek.h"
// file: minilib/include/read.h
#include "minilib/include/read.h"
// file: minilib/include/read.h
static inline int volatile __attribute__((always_inline)) read( int fd, void* buf, int len );

// file: minilib/include/select.h
#include "minilib/include/select.h"
// file: minilib/include/select.h
static inline int volatile __attribute__((always_inline)) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait);

// file: minilib/include/tcgetattr.h
static inline int __attribute__((always_inline)) tcgetattr(int fd, struct termios *io);

// file: minilib/include/tcsetattr.h
static inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io);

// file: minilib/include/write.h
#include "minilib/include/write.h"
// file: minilib/include/write.h
//DEF_syscall(write,3,int a1,const void *a2, int a3 )



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/include/select.h"
#include "minilib/include/close.h"
#include "minilib/include/tcsetattr.h"
#include "minilib/include/write.h"
#include "minilib/src/open.c"
#include "minilib/include/tcgetattr.h"
#include "minilib/include/read.h"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
