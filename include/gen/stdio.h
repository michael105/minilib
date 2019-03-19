// Header generated by tools/genheaders.pl
// Put changes into stdio.h.in

#ifndef ansi_stdio_h
#define ansi_stdio_h

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

// file: src/mfprintf.c
int mfprintf(int fd, const char* fmt, ... );

// file: src/msprintf.c
int sprintf(char *buf, const char* fmt, ... );

// file: include/fputc.h
#include "include/fputc.h"
// file: include/fputc.h
inline int volatile fputc(int c, int fd);

// file: include/fputs.h
#include "include/fputs.h"
// file: include/fputs.h
inline int volatile fputs(const char *c, int fd);



#ifdef mini_INCLUDESRC
#include "include/fputs.h"
#include "src/msprintf.c"
#include "src/itobin.c"
#include "src/mfprintf.c"
#include "src/itodec.c"
#include "include/fputc.h"
#include "src/itohex.c"
#include "src/dtodec.c"
// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"
#endif

#endif
