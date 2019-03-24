/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_minilib_h
#define included_minilib_h


#ifdef mini_tcsetattr
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif

#ifdef mini_sprintf
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_fprintf
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_itodec
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif

#ifdef mini_fputs
#ifndef mini_strlen
#define mini_strlen
#endif
#endif

#ifdef mini_strncpy
#ifndef mini_memcpy
#define mini_memcpy
#endif
#endif

#ifdef mini_dtodec
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif

#ifdef mini_tcgetattr
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif

// src/mstrlen.c
#ifdef mini_strlen
int strlen(const char*str);
#endif

// src/itodec.c
#ifdef mini_uitodec
int uitodec(unsigned int i, char *buf, int prec, char limiter );
#endif

// include/write.h
#ifdef mini_write
#include "include/write.h"
#endif

// src/ioctl.c
#ifdef mini_ioctl
int ioctl( int fd, unsigned long int request, ... );
#endif

// src/memcpy.c
#ifdef mini_memcpy
void *memcpy( void *d, const void *s, int n );
#endif

// src/strcat.c
#ifdef mini_strcat
char *strcat(char *dest, const char *src );
#endif

// include/tcgetattr.h
#ifdef mini_tcgetattr
#include "sys/ttycom.h"
#include "include/tcgetattr.h"
#endif

// src/mprint.c
#ifdef mini_print
int print(const char *msg);
#endif

// src/memcpy.c
#ifdef mini_strncpy
char *strncpy(char *dest, const char *src, int n);
#endif

// include/close.h
#ifdef mini_close
#include "include/close.h"
#endif

// src/open.c
#ifdef mini_creat
inline int volatile __attribute__((always_inline)) creat( const char *s, int mode );
#endif

// src/ioctl.c
#ifdef mini_ioctl
int ioctl( int fd, unsigned long int request, ... );
#endif

// src/mstrcmp.c
#ifdef mini_strncmp
int strncmp(const char*c1,const char*c2,int len);
#endif

// src/memcpy.c
#ifdef mini_memcpy
void *memcpy( void *d, const void *s, int n );
#endif

// src/malloc.c
#ifdef mini_free
void volatile free(void* p);
#endif

// src/memcpy.c
#ifdef mini_strcpy
char *strcpy(char *dest, const char *src);
#endif

// src/isspace.c
#ifdef mini_isspace
int isspace(int c);
#endif

// include/write.h
#ifdef mini_write
#include "include/write.h"
#endif

// src/itohex.c
#ifdef mini_itohex
int itohex(int i,char* buf,int padding);
#endif

// include/read.h
#ifdef mini_read
#include "syscall.h"
#include "include/read.h"
#endif

// include/tcsetattr.h
#ifdef mini_tcsetattr
#include "sys/ttycom.h"
#include "termios.h"
#include "include/tcsetattr.h"
#endif

// include/isprint.h
#ifdef mini_isprint
#include "include/isprint.h"
#endif

// src/atoi.c
#ifdef mini_atoi
int atoi(char *c);
#endif

// include/fputs.h
#ifdef mini_fputs
#include "include/fputs.h"
#endif

// src/itobin.c
#ifdef mini__itobin
int _itobin(int i, char*buf, int prec, int groups );
#endif

// src/msprintf.c
#ifdef mini_sprintf
int sprintf(char *buf, const char* fmt, ... );
#endif

// src/memset.c
#ifdef mini_memset
void *memset( void *s, int c, int n);
#endif

// src/itodec.c
#ifdef mini_uitodec
int uitodec(unsigned int i, char *buf, int prec, char limiter );
#endif

// src/dtodec.c
#ifdef mini_dtodec
int dtodec(double d, char* buf, int precision);
#endif

// src/mstrcmp.c
#ifdef mini_strcmp
int strcmp(const char*c1,const char*c2);
#endif

// src/itodec.c
#ifdef mini_itodec
int itodec(int i, char *buf, int prec, char limiter );
#endif

// src/mstrcmp.c
#ifdef mini_memcmp
int memcmp(const void* c1,const void* c2,int len);
#endif

// src/open.c
#ifdef mini_open
int volatile open( const char *s, int flags, ... );
#endif

// include/select.h
#ifdef mini_select
#include "include/select.h"
#endif

// src/mstrlen.c
#ifdef mini_strlen
int strlen(const char*str);
#endif

// src/mfprintf.c
#ifdef mini_fprintf
int fprintf(int fd, const char* fmt, ... );
#endif

// src/mprint.c
#ifdef mini_printl
int printl(const char *msg);
#endif

// src/memfrob.c
#ifdef mini_memfrob
void* memfrob(void* s, unsigned int len);
#endif

// src/malloc.c
#ifdef mini_malloc
void* volatile malloc(int size);
#endif

// include/fputc.h
#ifdef mini_fputc
#include "include/fputc.h"
#endif


#ifdef INCLUDESRC
#include "minilib.c"
#endif

#endif
