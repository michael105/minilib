/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_miniextras_h
#define included_miniextras_h

/* header.in */
// file: minilib/src/dtodec.c
int dtodec(double d, char* buf, int precision);

// file: minilib/src/itobin.c
int _itobin(int i, char*buf, int prec, int groups );

// file: minilib/src/itodec.c
int uitodec(unsigned int i, char *buf, int prec, char limiter );

// file: minilib/src/itodec.c
int itodec(int i, char *buf, int prec, char limiter );

// file: minilib/src/itohex.c
int itohex(int i,char* buf,int padding);

// file: minilib/src/memfrob.c
void* memfrob(void* s, unsigned int len);

// file: minilib/src/mprint.c
int print(const char *msg);

// file: minilib/src/mprint.c
int printl(const char *msg);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/itohex.c"
#include "minilib/src/itobin.c"
#include "minilib/src/mprint.c"
#include "minilib/src/itodec.c"
#include "minilib/src/memfrob.c"
#include "minilib/src/dtodec.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
