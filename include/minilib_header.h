#ifndef minilib_header_h
#define minilib_header_h



#ifdef X64
#define POINTER long int
#else
#define POINTER int
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef stdin
#define stdin 0
#endif
#ifndef stdout
#define stdout 1
#endif
#ifndef stderr
#define stderr 2
#endif




#include "../macros/vararg.h"

//#include "../src/syscall_stubs.c"

#ifdef mini_syscall
#include "syscall.h"
#endif


#ifdef mini_read
#include "read.h"
#endif


#ifdef mini_mprintf
//extern int mprintf(const char *fmt, ...);
//#include "mprintf.h"
#define mprintf(...) mfprintf(stdout,__VA_ARGS__)
#ifndef mini_buf
#define mini_buf 1024
#endif
#ifndef mini_mfprintf
#define mini_mfprintf
#endif
#endif

#ifdef mini_perror
#define perror(...) mfprintf(stderr,__VA_ARGS__)
#endif

#ifdef mini_mfprintf
//#include "mfprintf.h"
extern int mfprintf(int fd, const char*fmt, ...);
#ifndef mini_buf
#define mini_buf 1024
#endif
#endif


#ifdef mini_msprintf
extern int msprintf(char *buf, const char *fmt, ...);
#ifndef mini_buf
#define mini_buf 1024
#endif
#endif


#ifdef mini_mprints
#include "mprints.h"
#endif

#ifdef mini_print
//#include "mprint.h"
extern int print(const char *msg);
extern int printl(const char *msg);
#endif



#ifdef mini_buf
//extern char mbuf[mini_buf];
#endif

#ifdef mini_exit
#include "exit.h"
#endif

#ifdef mini_write
#include "write.h"
#endif

#ifdef mini_isprint
#include "isprint.h"
#endif

#ifdef mini_isspace
extern int isspace(int c);
#endif





#ifdef mini_open
#include "open.h"
#ifndef mini_filemodes
#define mini_filemodes
#endif
#ifndef mini_errno
#define mini_errno
#endif
#endif

#ifdef mini_lseek
#include "lseek.h"
#endif

#ifdef mini_close
#include "close.h"
#endif



#ifdef mini_filemodes
#include "filemodes.h"
#endif

#ifdef mini_errno
#include "errno.h"
#endif



#ifdef mini_ioctl
//#include "ioctl.h"
int ioctl( int fd, unsigned long int request, ... );
#endif

#ifdef mini_tcgetattr
//#include "tcgetattr.h"
#include <sys/termios.h>
extern int tcgetattr(int fd, struct termios *io);
#endif

#ifdef mini_tcsetattr
//#include "tcsetattr.h"
#include <sys/termios.h>
extern int tcsetattr(int fd, int opt, const struct termios *io);
#endif

#ifdef mini_select
#include "select.h"
#endif

#ifdef mini_epoll
#include "epoll.h"
#endif

#ifdef mini_mstrcmp
extern int mstrcmp(char*,char*);
extern int mstrncmp(char*,char*,int);
#endif

#ifdef mini_mstrlen
extern int mstrlen(const char*);
#endif

#ifdef mini_memset
extern void *memset( void *s, int c, int n);
#endif

#ifdef mini_memcpy
extern void *memcpy( void *d, const void *s, int n);
#endif



#ifdef mini_itohex
extern int itohex(int i,char* buf,int padding);
#endif

#ifdef mini_dtodec
extern int dtodec(double d,char* buf, int prec);
#ifndef mini_itodec
#define mini_itodec
#endif
#endif


#ifdef mini_itodec
extern int itodec(int i,char* buf,int padding, char dec);
#endif


#ifdef mini_atoi
extern int atoi(char *c);
#endif

#ifdef mini_itobin
// int number, char *buf, int padding = 0, int groups = 32 (no grouping)
extern int _itobin(int i,char* buf, int padding, int groups);
#define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )
#endif

#ifdef mini_malloc
extern void* malloc(unsigned int size);
#endif

#ifdef mini_powers
//extern float fpowerui(float,unsigned int);
extern int ipoweriui(int,unsigned int);
extern int ipoweri(int,int); 
//extern int ipoweriui2(int,unsigned int);
#endif

#ifdef mini_memfrob
extern void* memfrob(void*,unsigned int);
#endif


#ifdef mini_overwrite
#define printf(...) mprintf(__VA_ARGS__)
#define fprintf(...) mfprintf(__VA_ARGS__)
#define sprintf(...) msprintf(__VA_ARGS__)
#define fileno(F) F
#define strcmp(A,B) mstrcmp(A,B)
#define strncmp(A,B,LEN) mstrncmp(A,B,LEN)
#define strlen(A) mstrlen(A)
#endif


#endif
