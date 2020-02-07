/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_minilib_h
#define included_minilib_h

/* templates/header.in */


#ifndef mini_INCLUDESRC
#ifdef INCLUDESRC
#define mini_INCLUDESRC
#endif
#endif


#ifdef HEADERGUARDS
#ifndef mini_HEADERGUARDS
#define mini_HEADERGUARDS
#endif
#endif


#ifdef HEADERGUARDS
#include "minilib/include/headerguards.h"
#endif

//#define mini_start
//#define mini_exit

#include "minilib/include/globaldefs.h"
#include "minilib/include/minilib_global.h"
#include "minilib/include/timeval.h"
#include "minilib/headers/common/dirent.h"
#include "minilib/include/syscall.h"
#include "minilib/headers/linux_x64/sys/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"

#ifdef mini_GETOPTS
#include "minilib/macros/getoptm.h"
#endif

/* end templates/header.in */
/* templates/minilib.h.in */

#include "minilib/include//utils.h"

#include "minilib/macros/vararg.h"

//#include "minilib/include/syscall.h"
#include "minilib/include/stdarg.h"

//#include "minilib/headers/common/sys/types.h"
//#include "minilib/include/syscall_stubs.h"
#include "minilib/include/exit.h"
#include "minilib/include/minilib_global.h"
#include "minilib/include/filemodes.h"

//#include "minilib/headers/common/dirent.h"


struct udiv_t { unsigned int quot, rem; };

#ifdef mini_perror
//#define perror(str) fprintf(stderr,str)
//#ifndef mini_fprintf
//#define mini_fprintf
//#endif
#endif


//#ifdef mini_puts
//#define puts(a1) printl(a1)
//#define mini_print
//#endif
//#ifdef mini_print
////#include "print.h"
//extern int print(const char *msg);
//extern int printl(const char *msg);
//#endif

//#ifdef mini_errno / No reason to not define errno Macros by default
#include "errno.h"
//#endif
//


/* end templates/minilib.h.in */


#ifdef mini_basename
//dep
#ifndef mini_strlen
#define mini_strlen
#endif
#endif

#ifdef mini_printsl
//dep
#ifndef mini__mprints
#define mini__mprints
#endif
#endif

#ifdef mini_fread
//dep
#ifndef mini_read
#define mini_read
#endif
#endif

#ifdef mini_getc
//dep
#ifndef mini_fgetc
#define mini_fgetc
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_read
#define mini_read
#endif
#endif

#ifdef mini_prints
//dep
#ifndef mini__mprints
#define mini__mprints
#endif
#endif

#ifdef mini_putc
//dep
#ifndef mini_fputc
#define mini_fputc
#endif
#endif

#ifdef mini_vfprintf
//dep
#ifndef mini_fprintf
#define mini_fprintf
#endif
#endif

#ifdef mini_printl
//dep
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_fwrite
//dep
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_fprint
//dep
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#endif

#ifdef mini_fsetpos
//dep
#ifndef mini_lseek
#define mini_lseek
#endif
#endif

#ifdef mini_fprintf
//dep
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_prints
#define mini_prints
#endif
#ifndef mini_dprintf
#define mini_dprintf
#endif
#ifndef mini_sprintf
#define mini_sprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#endif

#ifdef mini_putchar
//dep
#ifndef mini_fputc
#define mini_fputc
#endif
#endif

#ifdef mini_fputc
//dep
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_strncpy
//dep
#ifndef mini_memcpy
#define mini_memcpy
#endif
#endif

#ifdef mini_dprintf
//dep
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#endif

#ifdef mini_memcmp
//dep
#ifndef mini_0
#define mini_0
#endif
#endif

#ifdef mini_strcat
//dep
#ifndef mini_strlen
#define mini_strlen
#endif
#endif

#ifdef mini_printf
//dep
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#endif

#ifdef mini_writes
//dep
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_puts
//dep
#ifndef mini_printl
#define mini_printl
#endif
#ifndef mini_print
#define mini_print
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif

#ifdef mini_itohex
//dep
#ifndef mini__itohex
#define mini__itohex
#endif
#endif

#ifdef mini_fputs
//dep
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_fclose
//dep
#ifndef mini_close
#define mini_close
#endif
#endif

#ifdef mini_print
//dep
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif

#ifdef mini_itobin
//dep
#ifndef mini__itobin
#define mini__itobin
#endif
#endif

#ifdef mini_sprintf
//dep
#ifndef mini_snprintf
#define mini_snprintf
#endif
#endif

#ifdef mini_opendir
//dep
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_close
#define mini_close
#endif
#ifndef mini_malloc
#define mini_malloc
#endif
#endif

#ifdef mini_rewind
//dep
#ifndef mini_fseek
#define mini_fseek
#endif
#endif

#ifdef mini_fprintfs
//dep
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#endif

#ifdef mini_ftell
//dep
#ifndef mini_lseek
#define mini_lseek
#endif
#endif

#ifdef mini_fgetc
//dep
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_read
#define mini_read
#endif
#endif

#ifdef mini_itoHEX
//dep
#ifndef mini__itohex
#define mini__itohex
#endif
#endif

#ifdef mini_closedir
//dep
#ifndef mini_free
#define mini_free
#endif
#endif

#ifdef mini_fopen
//dep
#ifndef mini_open
#define mini_open
#endif
#endif

#ifdef mini_tcsetattr
//dep
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif

#ifdef mini_fprints
//dep
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif

#ifdef mini_itodec
//dep
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif

#ifdef mini_fwrites
//dep
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_perror
//dep
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_strerror
#define mini_strerror
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif

#ifdef mini_strcmp
//dep
#ifndef mini__strcmp
#define mini__strcmp
#endif
#endif

#ifdef mini_snprintf
//dep
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#endif

#ifdef mini_dtodec
//dep
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif

#ifdef mini_strncmp
//dep
#ifndef mini__strcmp
#define mini__strcmp
#endif
#endif

#ifdef mini_fseek
//dep
#ifndef mini_lseek
#define mini_lseek
#endif
#endif

#ifdef mini__strcmp
//dep
#ifndef mini_0
#define mini_0
#endif
#endif

#ifdef mini_vsnprintf
//dep
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini__mprints
//dep
#ifndef mini_dprints
#define mini_dprints
#endif
#endif

#ifdef mini_fgetpos
//dep
#ifndef mini_ftell
#define mini_ftell
#endif
#endif

#ifdef mini_tcgetattr
//dep
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif
// Start incfirst

// minilib/include/fputs.h
#ifdef mini_fputs
#include "mini_fstream.h"
#include "minilib/include/fputs.h"
#endif

// minilib/src/strlen.c
#ifdef mini_strlen
int strlen(const char*str);
#endif

// minilib/src/itobin.c
#ifdef mini__itobin
int _itobin(int i, char*buf, int prec, int groups );
#endif

// minilib/include/lseek.h
#ifdef mini_lseek
#include "minilib/include/lseek.h"
#endif

// minilib/src/open.c
#ifdef mini_open
int volatile open( const char *s, int flags, ... );
#endif

// minilib/src/memcpy.c
#ifdef mini_memcpy
void *memcpy( void *d, const void *s, int n );
#endif

// minilib/src/sprintf.c
#ifdef mini_sprintf
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)
#endif

// minilib/src/malloc.c
#ifdef mini_free
void volatile free(void* p);
#endif

// minilib/include/prints.h
#ifdef mini_print
#define print(str) write(STDOUT_FILENO,str,strlen(str))
#endif

// minilib/src/malloc.c
#ifdef mini_malloc
void* volatile malloc(int size);
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fseek
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_read
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/src/sprintf.c
#ifdef mini_snprintf
int snprintf( char *buf, size_t size, const char *fmt, ... );
#endif

// minilib/include/fputc.h
#ifdef mini_fputc
#include "mini_fstream.h"
#include "minilib/include/fputc.h"
#endif

// minilib/src/sprintf.c
#ifdef mini_fprintf
#define fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))
#endif

// minilib/src/prints.c
#ifdef mini__mprints
#define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)
#endif

// minilib/src/sprintf.c
#ifdef mini_vsnprintf
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );
#endif

// minilib/src/mstrcmp.c
#ifdef mini__strcmp
int _strcmp(const char*c1,const char*c2,int len);
#endif

// minilib/src/sprintf.c
#ifdef mini_dprintf
int dprintf( int fd, const char *fmt, ... );
#endif

// minilib/include/prints.h
#ifdef mini_printl
#define printl() write(STDOUT_FILENO,"\n",1)
#endif

// minilib/include/prints.h
#ifdef mini_prints
#define prints(...) _mprints(__VA_ARGS__,0)
#endif

// minilib/src/itodec.c
#ifdef mini_uitodec
int uitodec(unsigned int i, char *buf, int prec, char limiter );
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_close
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/src/itodec.c
#ifdef mini_itodec
int itodec(int i, char *buf, int prec, char limiter );
#endif

// 
#ifdef mini_0
#endif

// 
#ifdef mini_dprints
#endif

// minilib/src/ioctl.c
#ifdef mini_ioctl
int ioctl( int fd, unsigned long int request, ... );
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fileno
#include "minilib/include/mini_fstream.h"
#endif

// minilib/src/itohex.c
#ifdef mini__itohex
int _itohex(int i,char* buf,int padding, int capitals);
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_write
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/src/strerror.c
#ifdef mini_strerror
char* strerror( int errnum );
#endif

// minilib/include/fgetc.h
#ifdef mini_fgetc
#include "mini_fstream.h"
#include "minilib/include/fgetc.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_ftell
#include "minilib/include/mini_fstream.h"
#endif
// End incfirst

// minilib/include/syscalls_x64.h
#ifdef mini__seccomp
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mq_timedsend
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fchownat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sysfs
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__inotify_init
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__shutdown
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mbind
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/lseek.h
#ifdef mini_fsync
#include "minilib/include/lseek.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__modify_ldt
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__prctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__io_getevents
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getrusage
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__eventfd2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/itohex.c
#ifdef mini_itoHEX
int itoHEX(int i,char* buf,int padding);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__removexattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__process_vm_writev
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__creat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__utimensat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__timer_create
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__accept4
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mknod
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_chdir
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fclose
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mount
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__set_mempolicy
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_dup
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/src/isspace.c
#ifdef mini_isspace
int isspace(int c);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__dup
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__newfstatat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__pipe2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__accept
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fwrite
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setitimer
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__munlockall
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setpgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fanotify_mark
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/getenv.c
#ifdef mini_getenv
char *getenv(const char* name);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__unlink
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fread
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__prlimit64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__clone
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_getparam
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getrlimit
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__ustat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__clock_settime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_get_priority_max
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fstat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_stat
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getdents
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__process_vm_readv
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_uname
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fsync
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setresuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__clock_getres
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__lseek
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__epoll_pwait
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__io_setup
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__alarm
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__uname
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sync
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__get_robust_list
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mremap
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setfsgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rt_tgsigqueueinfo
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__epoll_wait
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__ioprio_get
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__write
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__futimesat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fstatfs
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__kcmp
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rt_sigtimedwait
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__ptrace
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__read
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__statfs
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__semctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__inotify_add_watch
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__inotify_init1
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_get_priority_min
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__close
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getrandom
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__times
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setresgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fork
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mkdirat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setgroups
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setreuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getsockopt
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__readlinkat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__lgetxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__munmap
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setpriority
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_getscheduler
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/memcpy.c
#ifdef mini_strcpy
char *strcpy(char *dest, const char *src);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__brk
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__quotactl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sync_file_range
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__gettimeofday
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__kexec_file_load
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mq_timedreceive
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__clock_adjtime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/open.c
#ifdef mini_creat
inline int volatile __attribute__((always_inline)) creat( const char *s, int mode );
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__personality
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/fprintfs.c
#ifdef mini_fprintfs
int fprintfs( FILE* F, char *fmt, ...);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__semtimedop
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_setattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__stat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/tcsetattr.h
#ifdef mini_tcsetattr
#include "termios.h"
#include "ioctl.h"
#include "minilib/include/tcsetattr.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__timerfd_create
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getsid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__chown
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_mprotect
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__renameat2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__set_tid_address
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__ppoll
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/fputc.h
#ifdef mini_putchar
#define putchar(c) fputc(c,stdout)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__time
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/prints.h
#ifdef mini_writes
#define writes(str) write(STDOUT_FILENO,str,sizeof(str))
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__request_key
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_clearerror
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__ioprio_set
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__connect
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fprint
#define fprint(...) fprintf(__VA_ARGS__)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__ioctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__syncfs
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getcpu
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__flistxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__recvfrom
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fremovexattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__timer_gettime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__epoll_create
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_setaffinity
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/tcgetattr.h
#ifdef mini_tcgetattr
#include "minilib/include/tcgetattr.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__capset
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__exit
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__swapon
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mprotect
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__epoll_create1
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_getdents
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__semget
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_fstat
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__timer_getoverrun
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__eventfd
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mmap
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__socketpair
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getegid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__writev
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__pwrite64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fchmod
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/select.h
#ifdef mini_select
#include "minilib/include/select.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__readlink
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__timerfd_gettime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__lsetxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rt_sigqueueinfo
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__nanosleep
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/memfrob.c
#ifdef mini_memfrob
void* memfrob(void* s, unsigned int len);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__tee
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__pread64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/itobin.c
#ifdef mini_itobin
#define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_time
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__utime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__lchown
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__pivot_root
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__pause
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rmdir
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fdatasync
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__shmdt
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_vfprintf
#define vfprintf(...) fprintf(__VA_ARGS__)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rename
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__arch_prctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__flock
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fsetpos
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__kexec_load
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/prints.h
#ifdef mini_printsl
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__io_cancel
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mkdir
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rt_sigaction
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/isprint.h
#ifdef mini_isprint
#include "minilib/include/isprint.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__pwritev
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__linkat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getresgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getgroups
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__swapoff
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__shmget
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strncmp
int strncmp(const char*c1,const char*c2,int len);
#endif

// minilib/src/dtodec.c
#ifdef mini_dtodec
int dtodec(double d, char* buf, int precision);
#endif

// minilib/macros/getoptm.h
#ifdef mini_def
#include "minilib/macros/getoptm.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mq_notify
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strcmp
int strcmp(const char*c1,const char*c2);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__add_key
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sendmmsg
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__open
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__finit_module
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__vmsplice
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fchmodat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__keyctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__semop
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getpid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__tgkill
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__clock_gettime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__lookup_dcookie
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_setparam
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/dirent/opendir.c
#ifdef mini_opendir
DIR *opendir(const char *name);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__delete_module
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_dup2
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__waitid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__bind
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__set_robust_list
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mlockall
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__syslog
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/prints.h
#ifdef mini_puts
#define puts(msg) ( print(msg) + printl() )
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getpeername
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__renameat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/memset.c
#ifdef mini_memset
void *memset( void *s, int c, int n);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__select
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__symlink
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__io_destroy
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getsockname
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__timer_delete
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__ftruncate
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__chdir
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getresuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__msgctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__init_module
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__ioperm
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__tkill
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__vfork
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setrlimit
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/basename.c
#ifdef mini_basename
char *basename(char *path);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__acct
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__preadv
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sysinfo
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_feof
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__umask
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__futex
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_rr_get_interval
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__clock_nanosleep
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sendto
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sigaltstack
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sendfile
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setfsuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sendmsg
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getpgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getitimer
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__get_mempolicy
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/prints.h
#ifdef mini_fwrites
#define fwrites(fd,str) write(fd,str,sizeof(str))
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__signalfd4
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__access
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rt_sigsuspend
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__listen
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_rewind
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sethostname
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__move_pages
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fadvise64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__gettid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__migrate_pages
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setdomainname
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__open_by_handle_at
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/atoi.c
#ifdef mini_atoi
int atoi(char *c);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mknodat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fallocate
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/fopen.c
#ifdef mini_fopen
FILE *fopen(const char* filename, const char* mode);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__munlock
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rt_sigpending
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/itohex.c
#ifdef mini_itohex
int itohex(int i,char* buf,int padding);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__readv
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__msgsnd
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getcwd
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__umount2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__exit_group
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__execve
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__remap_file_pages
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_printf
#define printf(...) fprintf(stdout,__VA_ARGS__)
#endif

// minilib/src/strcat.c
#ifdef mini_strcat
char *strcat(char *dest, const char *src );
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fcntl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mlock
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__pselect6
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__chroot
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getppid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_gettimeofday
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__chmod
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rt_sigreturn
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__listxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__lstat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__restart_syscall
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mq_unlink
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/fgetc.h
#ifdef mini_getc
#define getc(F) fgetc(F)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mq_getsetattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__lremovexattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__truncate
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__llistxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_setbuf
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__readahead
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__poll
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fgetpos
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__msgget
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fflush
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__utimes
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__link
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__wait4
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/dirent/readdir.c
#ifdef mini_readdir
struct dirent *readdir(DIR *dir);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__unshare
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/strerror.c
#ifdef mini_perror
void perror(char *msg);
#endif

// minilib/src/rand.c
#ifdef mini_srand
void srand( unsigned int i );
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mq_open
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__kill
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getpgrp
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/dirent/closedir.c
#ifdef mini_closedir
int closedir(DIR *dir);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__openat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_dup3
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini___sysctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__io_submit
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setns
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/memcpy.c
#ifdef mini_strncpy
char *strncpy(char *dest, const char *src, int n);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__splice
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__geteuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_ferror
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__adjtimex
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setregid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__msgrcv
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__memfd_create
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_memcmp
int memcmp(const void* c1,const void* c2,int len);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/fputc.h
#ifdef mini_putc
#define putc(c,stream) fputc(c,stream)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__socket
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__bpf
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_rename
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__signalfd
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__faccessat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__epoll_ctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fgetxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__recvmmsg
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__shmctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_setvbuf
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__madvise
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fchdir
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__timerfd_settime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_getattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__mincore
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__pipe
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__capget
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__msync
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__inotify_rm_watch
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fchown
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__dup2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/lseek.h
#ifdef mini_ftruncate
#include "minilib/include/lseek.h"
#endif

// minilib/include/prints.h
#ifdef mini_fprints
#define fprints(F,str) write(fileno(F),str,strlen(str))
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fanotify_init
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setsid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__symlinkat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__reboot
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_setscheduler
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__dup3
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_yield
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__name_to_handle_at
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/rand.c
#ifdef mini_rand
unsigned int rand();
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__timer_settime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_getcwd
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sched_getaffinity
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__fsetxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__unlinkat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__shmat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__vhangup
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__settimeofday
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__rt_sigprocmask
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__iopl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__perf_event_open
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__setsockopt
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getdents64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_unlink
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__recvmsg
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscall_stubs.h
#ifdef mini_getpid
#include "minilib/include/syscall_stubs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__getpriority
#include "minilib/include/syscalls_x64.h"
#endif


#ifdef INCLUDESRC
#ifndef included_minilib_c
#include "minilib.c"
#endif
#endif

#endif
