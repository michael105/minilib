/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_minilib_h
#define included_minilib_h

/* header.in */


#ifndef mini_INCLUDESRC
#ifdef INCLUDESRC
#define mini_INCLUDESRC
#endif
#endif


//#define mini_start
//#define mini_exit

#include "minilib/include/globaldefs.h"
#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/include/timeval.h"
#include "minilib/headers/common/sys/types.h"




#include "minilib/include//utils.h"

#include "minilib/macros/vararg.h"

//#include "minilib/include/syscall.h"
#include "minilib/include/stdarg.h"

//#include "minilib/headers/common/sys/types.h"
//#include "minilib/include/syscall_stubs.h"
#include "minilib/include/exit.h"
#include "minilib/include/minilib_global.h"


struct udiv_t { unsigned int quot, rem; };

#ifdef mini_perror
#define perror(...) fprintf(stderr,__VA_ARGS__)
#ifndef mini_fprintf
#define mini_fprintf
#endif
#endif


//#ifdef mini_puts
//#define puts(a1) printl(a1)
//#define mini_print
//#endif
//#ifdef mini_print
////#include "mprint.h"
//extern int print(const char *msg);
//extern int printl(const char *msg);
//#endif

//#ifdef mini_errno / No reason to not define errno Macros by default
#include "errno.h"
//#endif



#ifdef mini_print
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_snprintf
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#endif

#ifdef mini_printl
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_fopen
#ifndef mini_open
#define mini_open
#endif
#endif

#ifdef mini_fprintf
#ifndef mini_dprintf
#define mini_dprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#endif

#ifdef mini_putchar
#ifndef mini_fputc
#define mini_fputc
#endif
#endif

#ifdef mini_tcgetattr
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif

#ifdef mini_dprintf
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#endif

#ifdef mini_vsnprintf
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_fclose
#ifndef mini_close
#define mini_close
#endif
#endif

#ifdef mini_dtodec
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif

#ifdef mini_printf
#ifndef mini_dprintf
#define mini_dprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#endif

#ifdef mini_fputs
#ifndef mini_strlen
#define mini_strlen
#endif
#endif

#ifdef mini_puts
#ifndef mini_printl
#define mini_printl
#endif
#endif

#ifdef mini_strncpy
#ifndef mini_memcpy
#define mini_memcpy
#endif
#endif

#ifdef mini_tcsetattr
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif

#ifdef mini_itodec
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif

// 
#ifdef mini_close
static inline int volatile __attribute__((always_inline)) close( int fd ){
		int ret;
		syscall1(ret,SCALL(close),(int)fd);
		return(ret);
}
#endif

// minilib/src/mprint.c
#ifdef mini_printl
int printl(const char *msg);
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_write
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/src/ioctl.c
#ifdef mini_ioctl
int ioctl( int fd, unsigned long int request, ... );
#endif

// minilib/src/msprintf.c
#ifdef mini_dprintf
int dprintf( int fd, const char *fmt, ... );
#endif

// minilib/src/mstrlen.c
#ifdef mini_strlen
int strlen(const char*str);
#endif

// minilib/include/fputc.h
#ifdef mini_fputc
#include "minilib/include/fputc.h"
#endif

// minilib/src/msprintf.c
#ifdef mini_vsnprintf
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );
#endif

// minilib/src/open.c
#ifdef mini_open
int volatile open( const char *s, int flags, ... );
#endif

// minilib/include/mini_stdio.h
#ifdef mini_fileno
#include "minilib/include/mini_stdio.h"
#endif

// minilib/src/memcpy.c
#ifdef mini_memcpy
void *memcpy( void *d, const void *s, int n );
#endif

// minilib/src/itodec.c
#ifdef mini_uitodec
int uitodec(unsigned int i, char *buf, int prec, char limiter );
#endif

// minilib/include/read.h
#ifdef mini_read
#include "syscall.h"
#include "minilib/include/read.h"
#endif

// minilib/include/write.h
#ifdef mini_def
#include "minilib/include/write.h"
#endif

// minilib/src/strcat.c
#ifdef mini_strcat
char *strcat(char *dest, const char *src );
#endif

// minilib/include/mini_stdio.h
#ifdef mini_fclose
#include "minilib/include/mini_stdio.h"
#endif

// minilib/src/getenv.c
#ifdef mini_getenv
char *getenv(const char* name);
#endif

// minilib/include/fputs.h
#ifdef mini_fputs
#include "minilib/include/fputs.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_rename
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_mprotect
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/src/atoi.c
#ifdef mini_atoi
int atoi(char *c);
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_getcwd
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_dup2
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/mini_stdio.h
#ifdef mini_fprintf
#include "minilib/include/mini_stdio.h"
#endif

// minilib/src/memcpy.c
#ifdef mini_strcpy
char *strcpy(char *dest, const char *src);
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_gettimeofday
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/tcgetattr.h
#ifdef mini_tcgetattr
#include "minilib/include/tcgetattr.h"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_memcmp
int memcmp(const void* c1,const void* c2,int len);
#endif

// minilib/src/memcpy.c
#ifdef mini_strncpy
char *strncpy(char *dest, const char *src, int n);
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_time
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/tcsetattr.h
#ifdef mini_tcsetattr
#include "termios.h"
#include "ioctl.h"
#include "minilib/include/tcsetattr.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_unlink
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_dup3
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/mini_stdio.h
#ifdef mini_printf
#include "minilib/include/mini_stdio.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_getpid
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/fputc.h
#ifdef mini_putchar
#include "minilib/include/fputc.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_dup
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/src/malloc.c
#ifdef mini_malloc
void* volatile malloc(int size);
#endif

// minilib/include/select.h
#ifdef mini_select
#include "minilib/include/select.h"
#endif

// minilib/src/memset.c
#ifdef mini_memset
void *memset( void *s, int c, int n);
#endif

// minilib/src/msprintf.c
#ifdef mini_snprintf
int snprintf( char *buf, size_t size, const char *fmt, ... );
#endif

// minilib/include/lseek.h
#ifdef mini_fsync
#include "minilib/include/lseek.h"
#endif

// minilib/src/isspace.c
#ifdef mini_isspace
int isspace(int c);
#endif

// minilib/src/malloc.c
#ifdef mini_free
void volatile free(void* p);
#endif

// minilib/src/memfrob.c
#ifdef mini_memfrob
void* memfrob(void* s, unsigned int len);
#endif

// minilib/src/fopen.c
#ifdef mini_fopen
FILE *fopen(const char* filename, const char* mode);
#endif

// minilib/src/itobin.c
#ifdef mini__itobin
int _itobin(int i, char*buf, int prec, int groups );
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strncmp
int strncmp(const char*c1,const char*c2,int len);
#endif

// minilib/include/lseek.h
#ifdef mini_ftruncate
#include "minilib/include/lseek.h"
#endif

// minilib/src/mprint.c
#ifdef mini_print
int print(const char *msg);
#endif

// minilib/src/mprint.c
#ifdef mini_puts
#define puts(c) printl(c)
#endif

// minilib/src/itodec.c
#ifdef mini_itodec
int itodec(int i, char *buf, int prec, char limiter );
#endif

// minilib/include/lseek.h
#ifdef mini_lseek
#include "minilib/include/lseek.h"
#endif

// minilib/src/itohex.c
#ifdef mini_itohex
int itohex(int i,char* buf,int padding);
#endif

// minilib/src/dtodec.c
#ifdef mini_dtodec
int dtodec(double d, char* buf, int precision);
#endif

// minilib/include/isprint.h
#ifdef mini_isprint
#include "minilib/include/isprint.h"
#endif

// minilib/src/open.c
#ifdef mini_creat
inline int volatile __attribute__((always_inline)) creat( const char *s, int mode );
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strcmp
int strcmp(const char*c1,const char*c2);
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_fstat
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/src/strerror.c
#ifdef mini_strerror
char* strerror( int errnum );
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_stat
#include "minilib/include/syscall_stubs.h"
#endif


#ifdef INCLUDESRC
#include "minilib.c"
#endif

#endif
