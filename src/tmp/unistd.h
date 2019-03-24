/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_unistd_h
#define included_unistd_h

// file: include/close.h
#include "include/close.h"
// file: include/close.h
static inline int volatile __attribute__((always_inline)) close( int fd );

// file: include/exit.h
#include "include/exit.h"
// file: include/lseek.h
#include "include/lseek.h"
// file: include/read.h
#include "include/read.h"
// file: include/read.h
static inline int volatile __attribute__((always_inline)) read( int fd, void* buf, int len );

// file: include/select.h
#include "include/select.h"
// file: include/select.h
static inline int volatile __attribute__((always_inline)) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait);

// file: include/tcgetattr.h
static inline int __attribute__((always_inline)) tcgetattr(int fd, struct termios *io);

// file: include/tcsetattr.h
static inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io);

// file: include/write.h
#include "include/write.h"
// file: include/write.h
DEF_syscall(write,3,int a1,const void *a2, int a3 )

// file: src/open.c
int volatile open( const char *s, int flags, ... );



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "include/tcsetattr.h"
#include "include/read.h"
#include "include/write.h"
#include "include/close.h"
#include "include/select.h"
#include "src/open.c"
#include "include/tcgetattr.h"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
