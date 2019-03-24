/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_miniextras_h
#define included_miniextras_h

// file: src/dtodec.c
int dtodec(double d, char* buf, int precision);

// file: src/itobin.c
int _itobin(int i, char*buf, int prec, int groups );

// file: src/itodec.c
int uitodec(unsigned int i, char *buf, int prec, char limiter );

// file: src/itodec.c
int itodec(int i, char *buf, int prec, char limiter );

// file: src/itohex.c
int itohex(int i,char* buf,int padding);

// file: src/memfrob.c
void* memfrob(void* s, unsigned int len);

// file: src/mprint.c
int print(const char *msg);

// file: src/mprint.c
int printl(const char *msg);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "src/dtodec.c"
#include "src/itohex.c"
#include "src/memfrob.c"
#include "src/mprint.c"
#include "src/itobin.c"
#include "src/itodec.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
