/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_mini_addons_h
#define included_mini_addons_h

#warning compat headers are instable.
#warning Better include minilib.h or use mini-gcc, when possible


#ifndef mini_INCLUDESRC
#ifdef INCLUDESRC
#define mini_INCLUDESRC
#endif
#endif


#define mini_start
#define mini_exit

#ifndef mini_buf
#define mini_buf 1024
#endif



#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER int
#endif

#ifndef uint32_t
#define uint32_t uint
#endif

#ifndef uint8_t
#define uint8_t uchar
#endif

#ifndef size_t
#define size_t long
#endif


#ifndef NULL
#define NULL 0
#endif


//#include "minilib/include/timeval.h"
#include "minilib/include/filemodes.h"

#include "minilib/headers/common/bits/alltypes.h"
#include "minilib/include/globaldefs.h"
#include "minilib/include/minilib_global.h"
#include "minilib/headers/common/dirent.h"
#include "minilib/headers/common/bits/signal.h"
#include "minilib/headers/common/bits/stat.h"
#include "minilib/headers/common/signal.h"
#include "minilib/headers/common/ctype.h"
#include "minilib/include/ctype.h"
#include "minilib/include/syscall.h"
#include "minilib/headers/linux_x64/sys/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"



#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"

#include "include/exit.h"

#include "minilib/include/globaldefs.h"
#include "include/minilib_global.h"

#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"

#include "minilib/include/headerguards.h"

// file: minilib/src/basename.c
char *basename(char *path);

// file: minilib/src/brk.c
static long sys_brk(unsigned long addr);

// file: minilib/src/brk.c
static int brk( const void* addr );

// file: minilib/src/brk.c
static long getbrk();

// file: minilib/src/brk.c
static void* sbrk(long incr);

// file: minilib/src/dirname.c
char *dirname(char *s);

// file: minilib/src/dprintf.c
int dprintf( int fd, const char *fmt, ... );

// file: minilib/src/dtodec.c
int dtodec(double d, char* buf, int precision);

// file: minilib/src/errno_str.c
static char *errno_str(int err);

// file: minilib/src/exit_errno.c
void exit_errno( int errnum );

// file: minilib/src/ext_match.c
int ext_match(const char *text, const char *re);

// file: minilib/src/fprintfs.c
int fprintfs( FILE* F, char *fmt, ...);

// file: minilib/src/hashes.c
unsigned long djb2_hash(const unsigned char *str);

// file: minilib/src/hashes.c
unsigned long sdbm_hash(const unsigned char *str);

// file: minilib/src/itobin.c
int _itobin(int i, char*buf, int prec, int groups );

// file: minilib/src/itobin.c
#define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

// file: minilib/src/itodec.c
int __attribute__((optimize("Os")))uitodec(unsigned int i, char *buf, int prec, char limiter );

// file: minilib/src/itodec.c
int itodec(int i, char *buf, int prec, char limiter );

// file: minilib/src/itooct.c
int itooct(int i, char *buf);

// file: minilib/src/match.c
int match(const char *text, const char *re);

// file: minilib/src/memfrob.c
void* memfrob(void* s, unsigned int len);

// file: minilib/src/mmap.c
static void* __attribute__((optimize("O0"))) mmap(void* addr,  size_t len,  int prot,  int flags,  int fd,  off_t off);

// file: minilib/src/prints.c
int dprints(int fd, const char *msg,...);

// file: minilib/src/prints.c
#define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)

// file: minilib/src/pty.c
int posix_openpt(int flags);

// file: minilib/src/pty.c
int grantpt(int fd);

// file: minilib/src/pty.c
int unlockpt(int fd);

// file: minilib/src/pty.c
int ptsname_r(int fd, char *buf, size_t len);

// file: minilib/src/pty.c
char *ptsname(int fd);

// file: minilib/src/putenv.c
int putenv( char *string );

// file: minilib/src/qsort.c
static inline void swap(void* a, void* b,int size);

// file: minilib/src/snprintf.c
int snprintf( char *buf, size_t size, const char *fmt, ... );

// file: minilib/src/vexec.c
int vexec( const char* path, char* const* argv, char* const* envp );

// file: minilib/src/vexec.c
int vexec_q( const char* path, char* const* argv, char* const* envp );

// file: minilib/include/dirent.h


// file: minilib/include/dirent.h
#ifndef mini_dirbufsize

// file: minilib/include/fexecve.h
static inline int fexecve(int fd, char *const argv[], char *const envp[]);

// file: minilib/include/fexecveat.h
static inline int fexecveat(int fd, char *const argv[], char *const envp[]);

// file: minilib/include/globaldefs.h
typedef int FILE;

// file: minilib/include/minilib_global.h
static void __attribute__((noipa,cold)) optimization_fence(void*p){}

// file: minilib/include/prints.h
#define prints(...) _mprints(__VA_ARGS__,0)

// file: minilib/include/prints.h
#define eprints(...) dprints(STDERR_FILENO,__VA_ARGS__,0)

// file: minilib/include/prints.h
#define fprints(F,str) write(fileno(F),str,strlen(str))

// file: minilib/include/prints.h
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

// file: minilib/include/prints.h
#define print(str) write(STDOUT_FILENO,str,strlen(str))

// file: minilib/include/prints.h
#define eprint(str) write(STDERR_FILENO,str,strlen(str))

// file: minilib/include/prints.h
#define writes(str) write(STDOUT_FILENO,str,sizeof(str))

// file: minilib/include/prints.h
#define ewrites(str) write(STDERR_FILENO,str,sizeof(str))

// file: minilib/include/prints.h
#define fwrites(fd,str) write(fd,str,sizeof(str))

// file: minilib/include/prints.h
#define printl() write(STDOUT_FILENO,"\n",1)

// file: minilib/include/prints.h
#define eprintl() write(STDERR_FILENO,"\n",1)

// file: minilib/include/prints.h
#define eputs(msg) ( eprint(msg) + eprintl() )

// file: minilib/include/prints.h
#define printfs(fmt,...) fprintfs(stdout, fmt, __VA_ARGS__)

// file: minilib/include/prints.h
#define eprintfs(fmt,...) fprintfs(stderr, fmt, __VA_ARGS__)

// file: minilib/include/ret_errno.h
#ifdef mini_errno

// file: minilib/include/seterrno.h
#ifdef mini_errno

// file: minilib/src/dirent/alphasort.c
int alphasort( const struct dirent** de1, const struct dirent** de2 );

// file: minilib/src/dirent/dirfd.c
int dirfd(DIR *d);

// file: minilib/src/dirent/opendir.c
static DIR *opendirp(const char *name, DIR *dir);

// file: minilib/src/dirent/scandir.c
//#define mini_scandir_bufsize 4096



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/dprintf.c"
#include "minilib/src/itodec.c"
#include "minilib/src/dirent/scandir.c"
#include "minilib/src/itobin.c"
#include "minilib/src/pty.c"
#include "minilib/include/minilib_global.h"
#include "minilib/include/globaldefs.h"
#include "minilib/src/dtodec.c"
#include "minilib/include/ret_errno.h"
#include "minilib/src/dirent/alphasort.c"
#include "minilib/include/seterrno.h"
#include "minilib/src/exit_errno.c"
#include "minilib/src/match.c"
#include "minilib/src/fprintfs.c"
#include "minilib/src/prints.c"
#include "minilib/src/putenv.c"
#include "minilib/include/fexecveat.h"
#include "minilib/src/dirname.c"
#include "minilib/src/basename.c"
#include "minilib/include/dirent.h"
#include "minilib/src/ext_match.c"
#include "minilib/src/itooct.c"
#include "minilib/src/mmap.c"
#include "minilib/src/vexec.c"
#include "minilib/src/hashes.c"
#include "minilib/src/dirent/opendir.c"
#include "minilib/src/dirent/dirfd.c"
#include "minilib/src/errno_str.c"
#include "minilib/src/qsort.c"
#include "minilib/src/brk.c"
#include "minilib/src/memfrob.c"
#include "minilib/src/snprintf.c"
#include "minilib/include/prints.h"
#include "minilib/include/fexecve.h"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
