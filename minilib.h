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


#ifdef mini_dtodec
//dep
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif

#ifdef mini_fopen
//dep
#ifndef mini_open
#define mini_open
#endif
#endif

#ifdef mini_itohex
//dep
#ifndef mini__itohex
#define mini__itohex
#endif
#endif

#ifdef mini_memcmp
//dep
#ifndef mini_0
#define mini_0
#endif
#endif

#ifdef mini_sprintf
//dep
#ifndef mini_snprintf
#define mini_snprintf
#endif
#endif

#ifdef mini_prints
//dep
#ifndef mini__mprints
#define mini__mprints
#endif
#endif

#ifdef mini_itobin
//dep
#ifndef mini__itobin
#define mini__itobin
#endif
#endif

#ifdef mini_fgetpos
//dep
#ifndef mini_ftell
#define mini_ftell
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

#ifdef mini_fwrite
//dep
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_fsetpos
//dep
#ifndef mini_lseek
#define mini_lseek
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

#ifdef mini_fread
//dep
#ifndef mini_read
#define mini_read
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

#ifdef mini_fprint
//dep
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
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

#ifdef mini__strcmp
//dep
#ifndef mini_0
#define mini_0
#endif
#endif

#ifdef mini_strncmp
//dep
#ifndef mini__strcmp
#define mini__strcmp
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

#ifdef mini_basename
//dep
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

#ifdef mini_tcsetattr
//dep
#ifndef mini_ioctl
#define mini_ioctl
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

#ifdef mini_dprintf
//dep
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#endif

#ifdef mini_ftell
//dep
#ifndef mini_lseek
#define mini_lseek
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

#ifdef mini_putchar
//dep
#ifndef mini_fputc
#define mini_fputc
#endif
#endif

#ifdef mini_fseek
//dep
#ifndef mini_lseek
#define mini_lseek
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

#ifdef mini_rewind
//dep
#ifndef mini_fseek
#define mini_fseek
#endif
#endif

#ifdef mini_strcat
//dep
#ifndef mini_strlen
#define mini_strlen
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

#ifdef mini_putc
//dep
#ifndef mini_fputc
#define mini_fputc
#endif
#endif

#ifdef mini_printl
//dep
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_strcmp
//dep
#ifndef mini__strcmp
#define mini__strcmp
#endif
#endif

#ifdef mini__mprints
//dep
#ifndef mini_dprints
#define mini_dprints
#endif
#endif

#ifdef mini_strncpy
//dep
#ifndef mini_memcpy
#define mini_memcpy
#endif
#endif

#ifdef mini_vfprintf
//dep
#ifndef mini_fprintf
#define mini_fprintf
#endif
#endif

#ifdef mini_writes
//dep
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_itoHEX
//dep
#ifndef mini__itohex
#define mini__itohex
#endif
#endif

#ifdef mini_fclose
//dep
#ifndef mini_close
#define mini_close
#endif
#endif

#ifdef mini_fwrites
//dep
#ifndef mini_write
#define mini_write
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

#ifdef mini_vsnprintf
//dep
#ifndef mini_write
#define mini_write
#endif
#endif

#ifdef mini_printsl
//dep
#ifndef mini__mprints
#define mini__mprints
#endif
#endif

#ifdef mini_closedir
//dep
#ifndef mini_free
#define mini_free
#endif
#endif

#ifdef mini_tcgetattr
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

#ifdef mini_printf
//dep
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#endif
// Start incfirst

// minilib/src/itodec.c
#ifdef mini_uitodec
int uitodec(unsigned int i, char *buf, int prec, char limiter );
#endif

// minilib/src/sprintf.c
#ifdef mini_vsnprintf
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_close
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/mstrcmp.c
#ifdef mini__strcmp
int _strcmp(const char*c1,const char*c2,int len);
#endif

// minilib/include/prints.h
#ifdef mini_print
#define print(str) write(STDOUT_FILENO,str,strlen(str))
#endif

// minilib/src/sprintf.c
#ifdef mini_dprintf
int dprintf( int fd, const char *fmt, ... );
#endif

// 
#ifdef mini_0
#endif

// minilib/src/itodec.c
#ifdef mini_itodec
int itodec(int i, char *buf, int prec, char limiter );
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fileno
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/fputs.h
#ifdef mini_fputs
#include "mini_fstream.h"
#include "minilib/include/fputs.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_ioctl
#include "minilib/include/syscalls_x64.h"
#endif

// 
#ifdef mini_dprints
#endif

// minilib/src/itohex.c
#ifdef mini__itohex
int _itohex(int i,char* buf,int padding, int capitals);
#endif

// minilib/src/sprintf.c
#ifdef mini_fprintf
#define fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))
#endif

// minilib/src/prints.c
#ifdef mini__mprints
#define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)
#endif

// minilib/include/fgetc.h
#ifdef mini_fgetc
#include "mini_fstream.h"
#include "minilib/include/fgetc.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_open
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/fputc.h
#ifdef mini_fputc
#include "mini_fstream.h"
#include "minilib/include/fputc.h"
#endif

// minilib/src/itobin.c
#ifdef mini__itobin
int _itobin(int i, char*buf, int prec, int groups );
#endif

// minilib/src/sprintf.c
#ifdef mini_sprintf
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)
#endif

// minilib/src/malloc.c
#ifdef mini_free
void volatile free(void* p);
#endif

// minilib/src/malloc.c
#ifdef mini_malloc
void* volatile malloc(int size);
#endif

// minilib/include/prints.h
#ifdef mini_printl
#define printl() write(STDOUT_FILENO,"\n",1)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_read
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/prints.h
#ifdef mini_prints
#define prints(...) _mprints(__VA_ARGS__,0)
#endif

// minilib/src/strerror.c
#ifdef mini_strerror
char* strerror( int errnum );
#endif

// minilib/src/strlen.c
#ifdef mini_strlen
int strlen(const char*str);
#endif

// minilib/include/mini_fstream.h
#ifdef mini_ftell
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_lseek
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/sprintf.c
#ifdef mini_snprintf
int snprintf( char *buf, size_t size, const char *fmt, ... );
#endif

// minilib/src/memcpy.c
#ifdef mini_memcpy
void *memcpy( void *d, const void *s, int n );
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_write
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fseek
#include "minilib/include/mini_fstream.h"
#endif
// End incfirst

// minilib/include/syscalls_x64.h
#ifdef mini_fadvise64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_init_module
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_inotify_rm_watch
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_socketpair
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_quotactl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_reboot
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_delete_module
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/rand.c
#ifdef mini_rand
unsigned int rand();
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_shmget
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/macros/getoptm.h
#ifdef mini_def
#include "minilib/macros/getoptm.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mlockall
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_pipe
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_clock_gettime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getresuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rt_sigreturn
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_readahead
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_io_submit
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strncmp
int strncmp(const char*c1,const char*c2,int len);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_gettid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_poll
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_readlinkat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mount
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_io_destroy
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setreuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_semctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_timer_gettime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setresuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_truncate
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_capset
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_creat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_printf
#define printf(...) fprintf(stdout,__VA_ARGS__)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_process_vm_readv
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sync_file_range
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_newfstatat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_renameat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/dirent/closedir.c
#ifdef mini_closedir
int closedir(DIR *dir);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_semget
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/getenv.c
#ifdef mini_getenv
char *getenv(const char* name);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fork
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/itohex.c
#ifdef mini_itohex
int itohex(int i,char* buf,int padding);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getcwd
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_acct
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rmdir
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/itobin.c
#ifdef mini_itobin
#define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fgetpos
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_bind
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fgetxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_exit
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_personality
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mq_unlink
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getpriority
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_dup
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fsetxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fcntl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fsetpos
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_process_vm_writev
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/strerror.c
#ifdef mini_perror
void perror(char *msg);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getsid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fanotify_init
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_chroot
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_capget
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setpriority
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/strcat.c
#ifdef mini_strcat
char *strcat(char *dest, const char *src );
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getsockname
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mlock
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_signalfd
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_lchown
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_arch_prctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_yield
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_getscheduler
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_utime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_syncfs
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_recvmmsg
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/memcpy.c
#ifdef mini_strncpy
char *strncpy(char *dest, const char *src, int n);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_io_setup
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/isprint.h
#ifdef mini_isprint
#include "minilib/include/isprint.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mprotect
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_swapon
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_shmctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getdents
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_get_priority_min
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setsid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_pause
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_setbuf
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_alarm
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_set_mempolicy
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_openat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/dtodec.c
#ifdef mini_dtodec
int dtodec(double d, char* buf, int precision);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setrlimit
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_getattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_utimensat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_flistxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_epoll_ctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sigaltstack
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_shmat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_uname
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_symlinkat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_pselect6
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_msync
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fwrite
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_inotify_init
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fremovexattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setfsuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_msgrcv
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setgroups
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_ppoll
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getdents64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_lstat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_wait4
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_umount2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/fgetc.h
#ifdef mini_getc
#define getc(F) fgetc(F)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_prlimit64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getrlimit
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_nanosleep
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_get_mempolicy
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_eventfd
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_finit_module
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_timer_getoverrun
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/rand.c
#ifdef mini_srand
void srand( unsigned int i );
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_restart_syscall
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sethostname
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_eventfd2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getgroups
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_clone
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/prints.h
#ifdef mini_fwrites
#define fwrites(fd,str) write(fd,str,sizeof(str))
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_clock_getres
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fchownat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/dirent/opendir.c
#ifdef mini_opendir
DIR *opendir(const char *name);
#endif

// minilib/src/memset.c
#ifdef mini_memset
void *memset( void *s, int c, int n);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_futex
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_kill
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sendmmsg
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_exit_group
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_timerfd_settime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_setvbuf
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_getaffinity
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sync
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_kcmp
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rt_tgsigqueueinfo
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/fprintfs.c
#ifdef mini_fprintfs
int fprintfs( FILE* F, char *fmt, ...);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_pwrite64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_unlink
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_time
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_msgsnd
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rt_sigpending
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getrandom
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_move_pages
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_adjtimex
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fchmod
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setitimer
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fchdir
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_epoll_create1
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_open_by_handle_at
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_pipe2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_execve
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/memfrob.c
#ifdef mini_memfrob
void* memfrob(void* s, unsigned int len);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mq_notify
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_migrate_pages
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_io_getevents
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strcmp
int strcmp(const char*c1,const char*c2);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_getparam
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mkdirat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_semop
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_set_tid_address
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_vfork
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mknod
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_clearerror
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getitimer
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_vhangup
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_symlink
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_timerfd_create
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_connect
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mq_open
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_dup2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getegid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_accept
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/fopen.c
#ifdef mini_fopen
FILE *fopen(const char* filename, const char* mode);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fchown
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_pwritev
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rt_sigprocmask
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_times
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_keyctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_pread64
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_chown
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sysfs
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sysinfo
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_get_priority_max
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_memcmp
int memcmp(const void* c1,const void* c2,int len);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getcpu
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getsockopt
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_preadv
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_unshare
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_request_key
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fprint
#define fprint(...) fprintf(__VA_ARGS__)
#endif

// minilib/src/basename.c
#ifdef mini_basename
char *basename(char *path);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_set_robust_list
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_feof
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mmap
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_msgget
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_setparam
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/prints.h
#ifdef mini_puts
#define puts(msg) ( print(msg) + printl() )
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setsockopt
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mremap
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_accept4
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_swapoff
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_brk
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_ioprio_set
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getppid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_timer_delete
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rt_sigtimedwait
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_lgetxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fflush
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_lsetxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_vfprintf
#define vfprintf(...) fprintf(__VA_ARGS__)
#endif

// minilib/include/prints.h
#ifdef mini_writes
#define writes(str) write(STDOUT_FILENO,str,sizeof(str))
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sendto
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_get_robust_list
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/tcgetattr.h
#ifdef mini_tcgetattr
#include "minilib/include/tcgetattr.h"
#endif

// minilib/include/prints.h
#ifdef mini_fprints
#define fprints(F,str) write(fileno(F),str,strlen(str))
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_readv
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_setaffinity
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_recvfrom
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rt_sigqueueinfo
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_memfd_create
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/dirent/readdir.c
#ifdef mini_readdir
struct dirent *readdir(DIR *dir);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mbind
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_remap_file_pages
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_kexec_file_load
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mq_timedreceive
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_shmdt
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fdatasync
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_ioperm
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rt_sigaction
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fread
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fsync
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setregid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_tee
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/tcsetattr.h
#ifdef mini_tcsetattr
#include "termios.h"
#include "ioctl.h"
#include "minilib/include/tcsetattr.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_access
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_select
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_chmod
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setpgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fchmodat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_rewind
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_ptrace
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_ftruncate
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_prctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/atoi.c
#ifdef mini_atoi
int atoi(char *c);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_msgctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_stat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_unlinkat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_shutdown
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rt_sigsuspend
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sendfile
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_seccomp
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_iopl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_vmsplice
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_clock_nanosleep
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_recvmsg
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getpgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_kexec_load
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setdomainname
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setns
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_setattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_signalfd4
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_pivot_root
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_utimes
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mincore
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_munlockall
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setresgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_bpf
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_rename
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_epoll_create
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mkdir
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_clock_adjtime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/isspace.c
#ifdef mini_isspace
int isspace(int c);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getpeername
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_listen
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_umask
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mknodat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_inotify_add_watch
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_syslog
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_setscheduler
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_writev
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_tgkill
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_flock
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mq_getsetattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/memcpy.c
#ifdef mini_strcpy
char *strcpy(char *dest, const char *src);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_link
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_faccessat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fallocate
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getresgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_readlink
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_add_key
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_perf_event_open
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_semtimedop
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_mq_timedsend
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_futimesat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/src/itohex.c
#ifdef mini_itoHEX
int itoHEX(int i,char* buf,int padding);
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fanotify_mark
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_timer_create
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getpid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_ferror
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_madvise
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_splice
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_socket
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_listxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_io_cancel
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_munmap
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_statfs
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_timer_settime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sendmsg
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_waitid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_modify_ldt
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_gettimeofday
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_inotify_init1
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_removexattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_linkat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_sched_rr_get_interval
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_chdir
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini__sysctl
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_settimeofday
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_llistxattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/fputc.h
#ifdef mini_putchar
#define putchar(c) fputc(c,stdout)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_clock_settime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_dup3
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_renameat2
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_ioprio_get
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/fputc.h
#ifdef mini_putc
#define putc(c,stream) fputc(c,stream)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getrusage
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_lookup_dcookie
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_epoll_wait
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_geteuid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_epoll_pwait
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_lremovexattr
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fstatfs
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_name_to_handle_at
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/mini_fstream.h
#ifdef mini_fclose
#include "minilib/include/mini_fstream.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_ustat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/prints.h
#ifdef mini_printsl
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_setfsgid
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_fstat
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_timerfd_gettime
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_munlock
#include "minilib/include/syscalls_x64.h"
#endif

// minilib/include/syscalls_x64.h
#ifdef mini_getpgrp
#include "minilib/include/syscalls_x64.h"
#endif


#ifdef INCLUDESRC
#ifndef included_minilib_c
#include "minilib.c"
#endif
#endif

#endif
