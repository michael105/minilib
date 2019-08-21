#if 0
ifdef UNDEF

Copyright (c) 2012-2019, Michael (Misc) Myer 
(misc.myer@zoho.com, www.github.com/michael105)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer in 
   the documentation and/or other materials provided with the distribution.
 * Neither the name of the minilib nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL Michael Myer BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

endif
#endif
#ifndef minilibcompiled_h
#define minilibcompiled_h

/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_minilib_c
#define included_minilib_c

/* header.in */


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
#ifndef headerguards_h
#define headerguards_h

// prevent standard headers from being compiled

#define included_ctype_h
#define included_declarations_h
#define included_fcntl_h
#define included_ioctl_h
#define included_miniaddons_h
#define included_stdio_h
#define included_stdlib_h
#define included_string_h
#define included_time_h
#define included_unistd_h


#define _AIO_H
#define _ALIASES_H
#define _ARGP_H
#define _ARGZ_H
#define _ARPA_FTP_H
#define _ARPA_INET_H
#define _ARPA_NAMESER_H
#define _ARPA_TELNET_H
#define _ARPA_TFTP_H
#define _AR_H
#define _BITS_BYTESWAP_H
#define _BITS_CPU_SET_H
#define _BITS_ERRNO_H
#define _BITS_FLOATN_COMMON_H
#define _BITS_FLOATN_H
#define _BITS_IPCTYPES_H
#define _BITS_LIBM_SIMD_DECL_STUBS_H
#define _BITS_LOCALE_H
#define _BITS_PTHREADTYPES_ARCH_H
#define _BITS_PTHREADTYPES_COMMON_H
#define _BITS_SCHED_H
#define _BITS_SETJMP_H
#define _BITS_SIGACTION_H
#define _BITS_SIGCONTEXT_H
#define _BITS_SIGEVENT_CONSTS_H
#define _BITS_SIGINFO_ARCH_H
#define _BITS_SIGINFO_CONSTS_ARCH_H
#define _BITS_SIGINFO_CONSTS_H
#define _BITS_SIGNUM_H
#define _BITS_SIGSTACK_H
#define _BITS_SIGTHREAD_H
#define _BITS_SOCKADDR_H
#define _BITS_SS_FLAGS_H
#define _BITS_STAT_H
#define _BITS_STDINT_INTN_H
#define _BITS_STDINT_UINTN_H
#define _BITS_STDIO2_H
#define _BITS_STDIO_H
#define _BITS_STDIO_LIM_H
#define _BITS_STRING_FORTIFIED_H
#define _BITS_STROPTS_H
#define _BITS_SYSLOG_PATH_H
#define _BITS_SYSMACROS_H
#define _BITS_TIME_H
#define _BITS_TYPES_H
#define _BITS_TYPES_LOCALE_T_H
#define _BITS_TYPES_STRUCT_SCH
#define _BITS_TYPES___LOCALE_T_H
#define _BITS_UINTN_IDENTITY_H
#define _BITS_UIO_EXT_H
#define _BITS_UIO_LIM_H
#define _BITS_WCHAR_H
#define _BITS_WCTYPE_WCHAR_H
#define _BITS_XTITYPES_H
#define _BYTESWAP_H
#define _COMPLEX_H
#define _CPIO_H
#define _CRYPT_H
//#define _DIRENT_H
#define _DLFCN_H
//#define _ELF_H
//#define _ENDIAN_H
#define _ENVZ_H
#define _ERROR_H
#define _EXECINFO_H
#define _FCNTL_H
#define _FEATURES_H
#define _FENV_H
#define _FPU_CONTROL_H
#define _FSTAB_H
#define _FTW_H
#define _GCONV_H
#define _GETOPT_CORE_H
#define _GETOPT_EXT_H
#define _GETOPT_H
#define _GETOPT_POSIX_H
#define _GNU_LIBC_VERSION_H
#define _GNU_VERSIONS_H
#define _GSHADOW_H
#define _ICONV_H
#define _IEEE754_H
#define _IFADDRS_H
#define _INTTYPES_H
#define _IP_VH
#define _LANGINFO_H
#define _LIBC_LIMITS_H
#define _LIBGEN_H
#define _LIBINTL_H
#define _LINK_H
#define _LINUX_KERNEL_H
#define _LINUX_LIST_H
#define _LINUX_TYPES_H
#define _MALLOC_H
#define _MATH_H
#define _MCHECK_H
#define _MONETARY_H
#define _MQUEUE_H
#define _NETASH_ASH_H
#define _NETATALK_AT_H
#define _NETAX25_AX25_H
#define _NETDB_H
#define _NETECONET_EC_H
#define _NETINET_ETHER_H
#define _NETINET_ICMP6_H
#define _NETINET_IF_FDDI_H
#define _NETINET_IF_TR_H
#define _NETINET_IGMP_H
#define _NETINET_IN_H
#define _NETINET_IN_SYSTM_H
#define _NETINET_IP6_H
#define _NETINET_TCP_H
#define _NETROM_NETROM_H
#define _NETROSE_ROSE_H
#define _NET_IF_ARP_H
#define _NET_IF_H
#define _NET_IF_SHAPER_H
#define _NET_IF_SLIP_H
#define _NET_PPP_DEFS_H
#define _NET_ROUTE_H
#define _NL_TYPES_H
#define _NSS_H
#define _OBSTACK_H
#define _PATH
#define _PATHS_H
#define _PRINTF_H
#define _PROC_SERVICE_H
#define _PROFIL_H
#define _PROTOCOLS_ROUTED_H
#define _PROTOCOLS_RWHOD_H
#define _PROTOCOLS_TALKD_H
#define _PTHREAD_H
#define _PTY_H
#define _REGEXP_H
#define _REGEX_H
#define _RESOLV_H
#define _RE_COMP_H
#define _RPC_NETDB_H
#define _SCHED_H
#define _SCSI_IOCTL_H
#define _SCSI_SCSI_H
#define _SCSI_SG_H
#define _SEARCH_H
#define _SEMAPHORE_H
#define _SETJMP_H
#define _SHADOW_H
#define _SIGNAL_H
//#define _STDINT_H
#define _STDIO_EXT_H
#define _STDIO_H
#define _STDLIB_H
#define _STRING_H
#define _STROPTS_H
#define _SYSCALL_H
#define _SYS_ACCT_H
#define _SYS_AUXV_H
#define _SYS_DEBUGREG_H
#define _SYS_ELF_H
#define _SYS_FSUID_H
#define _SYS_GMON_OUT_H
#define _SYS_IOCTL_H
#define _SYS_IPC_H
#define _SYS_KD_H
#define _SYS_MMAN_H
#define _SYS_MOUNT_H
#define _SYS_MSG_H
#define _SYS_MTIO_H
#define _SYS_PARAM_H
#define _SYS_PCI_H
#define _SYS_PERM_H
#define _SYS_PERSONALITY_H
#define _SYS_POLL_H
#define _SYS_PRCTL_H
#define _SYS_PROCFS_H
#define _SYS_PTRACE_H
#define _SYS_QUOTA_H
#define _SYS_RANDOM_H
#define _SYS_RAW_H
#define _SYS_REBOOT_H
#define _SYS_REG_H
#define _SYS_RESOURCE_H
#define _SYS_SELECT_H
#define _SYS_SEM_H
#define _SYS_SENDFILE_H
#define _SYS_SHM_H
#define _SYS_SOCKET_H
#define _SYS_STATFS_H
#define _SYS_STATVFS_H
//#define _SYS_STAT_H
#define _SYS_SWAP_H
#define _SYS_SYSINFO_H
#define _SYS_SYSLOG_H
#define _SYS_SYSMACROS_H
#define _SYS_TERMIOS_H
#define _SYS_TIMEB_H
#define _SYS_TIME_H
#define _SYS_TTYCHARS_H
#define _SYS_TTYDEFAULTS_H
#define _SYS_UCONTEXT_H
#define _SYS_UIO_H
#define _SYS_USER_H
//#define _SYS_UTSNAME_H
#define _SYS_VLIMIT_H
#define _SYS_VM86_H
#define _SYS_VTIMES_H
#define _SYS_XATTR_H
#define _TERMIOS_H
#define _TGMATH_H
#define _THREADS_H
#define _THREAD_DB_H
#define _THREAD_SHARED_TYPES_H
#define _UCHAR_H
#define _UCONTEXT_H
#define _ULIMIT_H
#define _UNISTD_H
#define _UTMPX_H
#define _UTMP_H
#define _UTSNAME_MACHINE_LENGTH
#define _UTSNAME_NODENAME_LENGTH
#define _UTSNAME_RELEASE_LENGTH
#define _UTSNAME_SYSNAME_LENGTH
#define _UTSNAME_VERSION_LENGTH
#define _WCHAR_H
#define _WCTYPE_H
#define _XOPEN_LIM_H
#define __A_OUT_GNU_H
#define __BITS_SOCKET_H
#define __FMTMSG_H
#define __GLIBC_INTERNAL_STARTING_H
#define __GNU_LIB_NAMES_H
#define __IF_PACKET_H
#define __LINUX_COMPILER_H
#define __NETINET_IF_ETHER_H
#define __NETINET_IP_H
#define __NETINET_IP_ICMP_H
#define __NETINET_UDP_H
#define __NETIPX_IPX_H
#define __NETIUCV_IUCV_H
#define __NETPACKET_PACKET_H
#define __NET_ETHERNET_H
#define __NET_IF_PPP_H
#define __NO_MATH
#define __O_PATH
#define __PTHREAD_RWLOCK_INT_FLAGS_SH
#define __SI_ERRNO_TH
#define __SI_H




#endif
#endif

//#define mini_start
//#define mini_exit

#ifndef globaldefs_h
#define globaldefs_h

// definitions

#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER unsigned int
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

#define PATH_MAX 4096

#define FOPEN_MAX 16

#ifndef SEEK_SET
#define SEEK_SET        0       /* seek relative to beginning of file */
#define SEEK_CUR        1       /* seek relative to current file position */
#define SEEK_END        2       /* seek relative to end of file */
#define SEEK_MAX        SEEK_END
#endif


#define mini_FOPEN_MAX 16

#ifndef NULL
#define NULL 0
#endif
#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif

#define BUFSIZ 1024


//+def
typedef int FILE;

#define FEOF_FLAG 0x80000000
#define ERR_FLAG 0x40000000
#define FLAG_MASK 0xc0000000
#define FD_MASK 0x3fffffff

#ifdef X64
typedef union { FILE *F; int i, fd;} mfl_union;
#else
//typedef union { FILE *F; int fd;} mfl_union;
#error checkme
#endif
//(untested for x32) better commenting this out for now.
//Might be better to find later
//also: endiannes.

#define EOF (-1)

#ifdef mini_buf
#ifndef stdin
#define stdin &ml.stream[0]
#endif
#ifndef stdout
#define stdout &ml.stream[1]
#endif
#ifndef stderr
#define stderr &ml.stream[2]
#endif
#else 
// no minibuf -> no stream descriptors.
#ifndef stdin
#define stdin (int*)0
#endif
#ifndef stdout
#define stdout (int*)1
#endif
#ifndef stderr
#define stderr (int*)2
#endif
#endif

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#endif

/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _LINUX_UTSNAME_H
#define _LINUX_UTSNAME_H

#define __OLD_UTS_LEN 8

struct oldold_utsname {
        char sysname[9];
        char nodename[9];
        char release[9];
        char version[9];
        char machine[9];
};

#define __NEW_UTS_LEN 64

struct old_utsname {
        char sysname[65];
        char nodename[65];
        char release[65];
        char version[65];
        char machine[65];
};

struct new_utsname {
        char sysname[__NEW_UTS_LEN + 1];
        char nodename[__NEW_UTS_LEN + 1];
        char release[__NEW_UTS_LEN + 1];
        char version[__NEW_UTS_LEN + 1];
        char machine[__NEW_UTS_LEN + 1];
        char domainname[__NEW_UTS_LEN + 1];
};


#endif /* _LINUX_UTSNAME_H */



#endif
#ifndef mini_timeval_h
#define mini_timeval_h
#ifndef type_t_h
#define type_t_h
typedef long time_t;
#endif

#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif


struct timezone {
		int     tz_minuteswest; /*	minutes	west of	Greenwich */
		int     tz_dsttime;     /*	type of	dst correction */
};
#endif
#ifndef	_DIRENT_H
#define	_DIRENT_H

#ifdef __cplusplus
extern "C" {
#endif

// just a placeholder

#define __NEED_ino_t
#define __NEED_off_t
#if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
#define __NEED_size_t
#endif

// source: musl
#ifndef alltypes_h
#define alltypes_h


#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif



#define _Addr long
#define _Int64 long
#define _Reg long

#ifndef size_t
#define size_t long
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

//typedef __builtin_va_list va_list;

//typedef __builtin_va_list __isoc_va_list;

typedef int wchar_t;

typedef long double double_t;

typedef float float_t;

typedef struct { long long __ll; long double __ld; } max_align_t;

//typedef long time_t;

//typedef long suseconds_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;

typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;

//typedef unsigned _Addr size_t;
//#define __DEFINED_size_t

typedef unsigned _Addr uintptr_t;

typedef _Addr ptrdiff_t;

typedef _Addr ssize_t;

typedef _Addr intptr_t;

typedef _Addr regoff_t;

typedef _Reg register_t;

typedef signed char     int8_t;

typedef signed short    int16_t;

typedef signed int      int32_t;

typedef signed _Int64   int64_t;

typedef signed _Int64   intmax_t;

typedef unsigned char   uint8_t;

typedef unsigned short  uint16_t;

typedef unsigned int    uint32_t;

typedef unsigned _Int64 uint64_t;

typedef unsigned _Int64 u_int64_t;

typedef unsigned _Int64 uintmax_t;

typedef unsigned mode_t;

typedef unsigned _Reg nlink_t;

typedef _Int64 off_t;

typedef unsigned _Int64 ino_t;

typedef unsigned _Int64 dev_t;

typedef long blksize_t;

typedef _Int64 blkcnt_t;

typedef unsigned _Int64 fsblkcnt_t;

typedef unsigned _Int64 fsfilcnt_t;

typedef unsigned wint_t;

typedef unsigned long wctype_t;

typedef void * timer_t;

typedef int clockid_t;

typedef long clock_t;

//struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timespec { time_t tv_sec; long tv_nsec; };

typedef int pid_t;

typedef unsigned id_t;

typedef unsigned uid_t;

typedef unsigned gid_t;

typedef int key_t;

//typedef unsigned useconds_t;

//typedef struct _IO_FILE FILE;

typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;

typedef struct __locale_struct * locale_t;

typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;

struct iovec { void *iov_base; size_t iov_len; };

typedef unsigned socklen_t;

typedef unsigned short sa_family_t;

#undef _Addr
#undef _Int64
#undef _Reg

#endif


struct __dirstream
{
	off_t tell;
	int fd;
	int buf_pos;
	int buf_end;
	volatile int lock[1];
	/* Any changes to this struct must preserve the property:
	 * offsetof(struct __dirent, buf) % sizeof(off_t) == 0 */
	char buf[2048];
};
typedef struct __dirstream DIR;

#define _DIRENT_HAVE_D_RECLEN
#define _DIRENT_HAVE_D_OFF
#define _DIRENT_HAVE_D_TYPE

struct dirent {
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	//unsigned char d_type;
	char d_name[256];
};

#define d_fileno d_ino
#if 0
int            closedir(DIR *);
DIR           *fdopendir(int);
DIR           *opendir(const char *);
struct dirent *readdir(DIR *);
int            readdir_r(DIR *__restrict, struct dirent *__restrict, struct dirent **__restrict);
void           rewinddir(DIR *);
int            dirfd(DIR *);

int alphasort(const struct dirent **, const struct dirent **);
int scandir(const char *, struct dirent ***, int (*)(const struct dirent *), int (*)(const struct dirent **, const struct dirent **));

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
void           seekdir(DIR *, long);
long           telldir(DIR *);
#endif
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define DT_UNKNOWN 0
#define DT_FIFO 1
#define DT_CHR 2
#define DT_DIR 4
#define DT_BLK 6
#define DT_REG 8
#define DT_LNK 10
#define DT_SOCK 12
#define DT_WHT 14
#define IFTODT(x) ((x)>>12 & 017)
#define DTTOIF(x) ((x)<<12)
int getdents(int, struct dirent *, size_t);
#endif

#ifdef _GNU_SOURCE
int versionsort(const struct dirent **, const struct dirent **);
#endif

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define dirent64 dirent
#define readdir64 readdir
#define readdir64_r readdir_r
#define scandir64 scandir
#define alphasort64 alphasort
#define versionsort64 versionsort
#define off64_t off_t
#define ino64_t ino_t
#define getdents64 getdents
#endif

#ifdef __cplusplus
}
#endif

#endif
#ifndef minilib_syscall_h
#define minilib_syscall_h

#ifdef mini_vsyscalls
extern int __mini_vsys;
#endif


//extern int sysret;
#ifdef mini_errno
extern int errno;
#endif

#ifdef OSX

#define NCONST 0x2000000
#define SCALL(call) SYS_##call
#ifndef _ASM_X86_UNISTD_64_H
#define _ASM_X86_UNISTD_64_H 1

#define __NR_read 0
#define __NR_write 1
#define __NR_open 2
#define __NR_close 3
#define __NR_stat 4
#define __NR_fstat 5
#define __NR_lstat 6
#define __NR_poll 7
#define __NR_lseek 8
#define __NR_mmap 9
#define __NR_mprotect 10
#define __NR_munmap 11
#define __NR_brk 12
#define __NR_rt_sigaction 13
#define __NR_rt_sigprocmask 14
#define __NR_rt_sigreturn 15
#define __NR_ioctl 16
#define __NR_pread64 17
#define __NR_pwrite64 18
#define __NR_readv 19
#define __NR_writev 20
#define __NR_access 21
#define __NR_pipe 22
#define __NR_select 23
#define __NR_sched_yield 24
#define __NR_mremap 25
#define __NR_msync 26
#define __NR_mincore 27
#define __NR_madvise 28
#define __NR_shmget 29
#define __NR_shmat 30
#define __NR_shmctl 31
#define __NR_dup 32
#define __NR_dup2 33
#define __NR_pause 34
#define __NR_nanosleep 35
#define __NR_getitimer 36
#define __NR_alarm 37
#define __NR_setitimer 38
#define __NR_getpid 39
#define __NR_sendfile 40
#define __NR_socket 41
#define __NR_connect 42
#define __NR_accept 43
#define __NR_sendto 44
#define __NR_recvfrom 45
#define __NR_sendmsg 46
#define __NR_recvmsg 47
#define __NR_shutdown 48
#define __NR_bind 49
#define __NR_listen 50
#define __NR_getsockname 51
#define __NR_getpeername 52
#define __NR_socketpair 53
#define __NR_setsockopt 54
#define __NR_getsockopt 55
#define __NR_clone 56
#define __NR_fork 57
#define __NR_vfork 58
#define __NR_execve 59
#define __NR_exit 60
#define __NR_wait4 61
#define __NR_kill 62
#define __NR_uname 63
#define __NR_semget 64
#define __NR_semop 65
#define __NR_semctl 66
#define __NR_shmdt 67
#define __NR_msgget 68
#define __NR_msgsnd 69
#define __NR_msgrcv 70
#define __NR_msgctl 71
#define __NR_fcntl 72
#define __NR_flock 73
#define __NR_fsync 74
#define __NR_fdatasync 75
#define __NR_truncate 76
#define __NR_ftruncate 77
#define __NR_getdents 78
#define __NR_getcwd 79
#define __NR_chdir 80
#define __NR_fchdir 81
#define __NR_rename 82
#define __NR_mkdir 83
#define __NR_rmdir 84
#define __NR_creat 85
#define __NR_link 86
#define __NR_unlink 87
#define __NR_symlink 88
#define __NR_readlink 89
#define __NR_chmod 90
#define __NR_fchmod 91
#define __NR_chown 92
#define __NR_fchown 93
#define __NR_lchown 94
#define __NR_umask 95
#define __NR_gettimeofday 96
#define __NR_getrlimit 97
#define __NR_getrusage 98
#define __NR_sysinfo 99
#define __NR_times 100
#define __NR_ptrace 101
#define __NR_getuid 102
#define __NR_syslog 103
#define __NR_getgid 104
#define __NR_setuid 105
#define __NR_setgid 106
#define __NR_geteuid 107
#define __NR_getegid 108
#define __NR_setpgid 109
#define __NR_getppid 110
#define __NR_getpgrp 111
#define __NR_setsid 112
#define __NR_setreuid 113
#define __NR_setregid 114
#define __NR_getgroups 115
#define __NR_setgroups 116
#define __NR_setresuid 117
#define __NR_getresuid 118
#define __NR_setresgid 119
#define __NR_getresgid 120
#define __NR_getpgid 121
#define __NR_setfsuid 122
#define __NR_setfsgid 123
#define __NR_getsid 124
#define __NR_capget 125
#define __NR_capset 126
#define __NR_rt_sigpending 127
#define __NR_rt_sigtimedwait 128
#define __NR_rt_sigqueueinfo 129
#define __NR_rt_sigsuspend 130
#define __NR_sigaltstack 131
#define __NR_utime 132
#define __NR_mknod 133
#define __NR_uselib 134
#define __NR_personality 135
#define __NR_ustat 136
#define __NR_statfs 137
#define __NR_fstatfs 138
#define __NR_sysfs 139
#define __NR_getpriority 140
#define __NR_setpriority 141
#define __NR_sched_setparam 142
#define __NR_sched_getparam 143
#define __NR_sched_setscheduler 144
#define __NR_sched_getscheduler 145
#define __NR_sched_get_priority_max 146
#define __NR_sched_get_priority_min 147
#define __NR_sched_rr_get_interval 148
#define __NR_mlock 149
#define __NR_munlock 150
#define __NR_mlockall 151
#define __NR_munlockall 152
#define __NR_vhangup 153
#define __NR_modify_ldt 154
#define __NR_pivot_root 155
#define __NR__sysctl 156
#define __NR_prctl 157
#define __NR_arch_prctl 158
#define __NR_adjtimex 159
#define __NR_setrlimit 160
#define __NR_chroot 161
#define __NR_sync 162
#define __NR_acct 163
#define __NR_settimeofday 164
#define __NR_mount 165
#define __NR_umount2 166
#define __NR_swapon 167
#define __NR_swapoff 168
#define __NR_reboot 169
#define __NR_sethostname 170
#define __NR_setdomainname 171
#define __NR_iopl 172
#define __NR_ioperm 173
#define __NR_create_module 174
#define __NR_init_module 175
#define __NR_delete_module 176
#define __NR_get_kernel_syms 177
#define __NR_query_module 178
#define __NR_quotactl 179
#define __NR_nfsservctl 180
#define __NR_getpmsg 181
#define __NR_putpmsg 182
#define __NR_afs_syscall 183
#define __NR_tuxcall 184
#define __NR_security 185
#define __NR_gettid 186
#define __NR_readahead 187
#define __NR_setxattr 188
#define __NR_lsetxattr 189
#define __NR_fsetxattr 190
#define __NR_getxattr 191
#define __NR_lgetxattr 192
#define __NR_fgetxattr 193
#define __NR_listxattr 194
#define __NR_llistxattr 195
#define __NR_flistxattr 196
#define __NR_removexattr 197
#define __NR_lremovexattr 198
#define __NR_fremovexattr 199
#define __NR_tkill 200
#define __NR_time 201
#define __NR_futex 202
#define __NR_sched_setaffinity 203
#define __NR_sched_getaffinity 204
#define __NR_set_thread_area 205
#define __NR_io_setup 206
#define __NR_io_destroy 207
#define __NR_io_getevents 208
#define __NR_io_submit 209
#define __NR_io_cancel 210
#define __NR_get_thread_area 211
#define __NR_lookup_dcookie 212
#define __NR_epoll_create 213
#define __NR_epoll_ctl_old 214
#define __NR_epoll_wait_old 215
#define __NR_remap_file_pages 216
#define __NR_getdents64 217
#define __NR_set_tid_address 218
#define __NR_restart_syscall 219
#define __NR_semtimedop 220
#define __NR_fadvise64 221
#define __NR_timer_create 222
#define __NR_timer_settime 223
#define __NR_timer_gettime 224
#define __NR_timer_getoverrun 225
#define __NR_timer_delete 226
#define __NR_clock_settime 227
#define __NR_clock_gettime 228
#define __NR_clock_getres 229
#define __NR_clock_nanosleep 230
#define __NR_exit_group 231
#define __NR_epoll_wait 232
#define __NR_epoll_ctl 233
#define __NR_tgkill 234
#define __NR_utimes 235
#define __NR_vserver 236
#define __NR_mbind 237
#define __NR_set_mempolicy 238
#define __NR_get_mempolicy 239
#define __NR_mq_open 240
#define __NR_mq_unlink 241
#define __NR_mq_timedsend 242
#define __NR_mq_timedreceive 243
#define __NR_mq_notify 244
#define __NR_mq_getsetattr 245
#define __NR_kexec_load 246
#define __NR_waitid 247
#define __NR_add_key 248
#define __NR_request_key 249
#define __NR_keyctl 250
#define __NR_ioprio_set 251
#define __NR_ioprio_get 252
#define __NR_inotify_init 253
#define __NR_inotify_add_watch 254
#define __NR_inotify_rm_watch 255
#define __NR_migrate_pages 256
#define __NR_openat 257
#define __NR_mkdirat 258
#define __NR_mknodat 259
#define __NR_fchownat 260
#define __NR_futimesat 261
#define __NR_newfstatat 262
#define __NR_unlinkat 263
#define __NR_renameat 264
#define __NR_linkat 265
#define __NR_symlinkat 266
#define __NR_readlinkat 267
#define __NR_fchmodat 268
#define __NR_faccessat 269
#define __NR_pselect6 270
#define __NR_ppoll 271
#define __NR_unshare 272
#define __NR_set_robust_list 273
#define __NR_get_robust_list 274
#define __NR_splice 275
#define __NR_tee 276
#define __NR_sync_file_range 277
#define __NR_vmsplice 278
#define __NR_move_pages 279
#define __NR_utimensat 280
#define __NR_epoll_pwait 281
#define __NR_signalfd 282
#define __NR_timerfd_create 283
#define __NR_eventfd 284
#define __NR_fallocate 285
#define __NR_timerfd_settime 286
#define __NR_timerfd_gettime 287
#define __NR_accept4 288
#define __NR_signalfd4 289
#define __NR_eventfd2 290
#define __NR_epoll_create1 291
#define __NR_dup3 292
#define __NR_pipe2 293
#define __NR_inotify_init1 294
#define __NR_preadv 295
#define __NR_pwritev 296
#define __NR_rt_tgsigqueueinfo 297
#define __NR_perf_event_open 298
#define __NR_recvmmsg 299
#define __NR_fanotify_init 300
#define __NR_fanotify_mark 301
#define __NR_prlimit64 302
#define __NR_name_to_handle_at 303
#define __NR_open_by_handle_at 304
#define __NR_clock_adjtime 305
#define __NR_syncfs 306
#define __NR_sendmmsg 307
#define __NR_setns 308
#define __NR_getcpu 309
#define __NR_process_vm_readv 310
#define __NR_process_vm_writev 311
#define __NR_kcmp 312
#define __NR_finit_module 313
#define __NR_sched_setattr 314
#define __NR_sched_getattr 315
#define __NR_renameat2 316
#define __NR_seccomp 317
#define __NR_getrandom 318
#define __NR_memfd_create 319
#define __NR_kexec_file_load 320
#define __NR_bpf 321
#define __NR_execveat 322
#define __NR_userfaultfd 323
#define __NR_membarrier 324
#define __NR_mlock2 325
#define __NR_copy_file_range 326
#define __NR_preadv2 327
#define __NR_pwritev2 328
#define __NR_pkey_mprotect 329
#define __NR_pkey_alloc 330
#define __NR_pkey_free 331
#define __NR_statx 332

#endif /* _ASM_X86_UNISTD_64_H */

#else

#define NCONST 0
#define SCALL(call) __NR_##call

#ifdef X64
#ifndef _ASM_X86_UNISTD_64_H
#define _ASM_X86_UNISTD_64_H 1

#define __NR_read 0
#define __NR_write 1
#define __NR_open 2
#define __NR_close 3
#define __NR_stat 4
#define __NR_fstat 5
#define __NR_lstat 6
#define __NR_poll 7
#define __NR_lseek 8
#define __NR_mmap 9
#define __NR_mprotect 10
#define __NR_munmap 11
#define __NR_brk 12
#define __NR_rt_sigaction 13
#define __NR_rt_sigprocmask 14
#define __NR_rt_sigreturn 15
#define __NR_ioctl 16
#define __NR_pread64 17
#define __NR_pwrite64 18
#define __NR_readv 19
#define __NR_writev 20
#define __NR_access 21
#define __NR_pipe 22
#define __NR_select 23
#define __NR_sched_yield 24
#define __NR_mremap 25
#define __NR_msync 26
#define __NR_mincore 27
#define __NR_madvise 28
#define __NR_shmget 29
#define __NR_shmat 30
#define __NR_shmctl 31
#define __NR_dup 32
#define __NR_dup2 33
#define __NR_pause 34
#define __NR_nanosleep 35
#define __NR_getitimer 36
#define __NR_alarm 37
#define __NR_setitimer 38
#define __NR_getpid 39
#define __NR_sendfile 40
#define __NR_socket 41
#define __NR_connect 42
#define __NR_accept 43
#define __NR_sendto 44
#define __NR_recvfrom 45
#define __NR_sendmsg 46
#define __NR_recvmsg 47
#define __NR_shutdown 48
#define __NR_bind 49
#define __NR_listen 50
#define __NR_getsockname 51
#define __NR_getpeername 52
#define __NR_socketpair 53
#define __NR_setsockopt 54
#define __NR_getsockopt 55
#define __NR_clone 56
#define __NR_fork 57
#define __NR_vfork 58
#define __NR_execve 59
#define __NR_exit 60
#define __NR_wait4 61
#define __NR_kill 62
#define __NR_uname 63
#define __NR_semget 64
#define __NR_semop 65
#define __NR_semctl 66
#define __NR_shmdt 67
#define __NR_msgget 68
#define __NR_msgsnd 69
#define __NR_msgrcv 70
#define __NR_msgctl 71
#define __NR_fcntl 72
#define __NR_flock 73
#define __NR_fsync 74
#define __NR_fdatasync 75
#define __NR_truncate 76
#define __NR_ftruncate 77
#define __NR_getdents 78
#define __NR_getcwd 79
#define __NR_chdir 80
#define __NR_fchdir 81
#define __NR_rename 82
#define __NR_mkdir 83
#define __NR_rmdir 84
#define __NR_creat 85
#define __NR_link 86
#define __NR_unlink 87
#define __NR_symlink 88
#define __NR_readlink 89
#define __NR_chmod 90
#define __NR_fchmod 91
#define __NR_chown 92
#define __NR_fchown 93
#define __NR_lchown 94
#define __NR_umask 95
#define __NR_gettimeofday 96
#define __NR_getrlimit 97
#define __NR_getrusage 98
#define __NR_sysinfo 99
#define __NR_times 100
#define __NR_ptrace 101
#define __NR_getuid 102
#define __NR_syslog 103
#define __NR_getgid 104
#define __NR_setuid 105
#define __NR_setgid 106
#define __NR_geteuid 107
#define __NR_getegid 108
#define __NR_setpgid 109
#define __NR_getppid 110
#define __NR_getpgrp 111
#define __NR_setsid 112
#define __NR_setreuid 113
#define __NR_setregid 114
#define __NR_getgroups 115
#define __NR_setgroups 116
#define __NR_setresuid 117
#define __NR_getresuid 118
#define __NR_setresgid 119
#define __NR_getresgid 120
#define __NR_getpgid 121
#define __NR_setfsuid 122
#define __NR_setfsgid 123
#define __NR_getsid 124
#define __NR_capget 125
#define __NR_capset 126
#define __NR_rt_sigpending 127
#define __NR_rt_sigtimedwait 128
#define __NR_rt_sigqueueinfo 129
#define __NR_rt_sigsuspend 130
#define __NR_sigaltstack 131
#define __NR_utime 132
#define __NR_mknod 133
#define __NR_uselib 134
#define __NR_personality 135
#define __NR_ustat 136
#define __NR_statfs 137
#define __NR_fstatfs 138
#define __NR_sysfs 139
#define __NR_getpriority 140
#define __NR_setpriority 141
#define __NR_sched_setparam 142
#define __NR_sched_getparam 143
#define __NR_sched_setscheduler 144
#define __NR_sched_getscheduler 145
#define __NR_sched_get_priority_max 146
#define __NR_sched_get_priority_min 147
#define __NR_sched_rr_get_interval 148
#define __NR_mlock 149
#define __NR_munlock 150
#define __NR_mlockall 151
#define __NR_munlockall 152
#define __NR_vhangup 153
#define __NR_modify_ldt 154
#define __NR_pivot_root 155
#define __NR__sysctl 156
#define __NR_prctl 157
#define __NR_arch_prctl 158
#define __NR_adjtimex 159
#define __NR_setrlimit 160
#define __NR_chroot 161
#define __NR_sync 162
#define __NR_acct 163
#define __NR_settimeofday 164
#define __NR_mount 165
#define __NR_umount2 166
#define __NR_swapon 167
#define __NR_swapoff 168
#define __NR_reboot 169
#define __NR_sethostname 170
#define __NR_setdomainname 171
#define __NR_iopl 172
#define __NR_ioperm 173
#define __NR_create_module 174
#define __NR_init_module 175
#define __NR_delete_module 176
#define __NR_get_kernel_syms 177
#define __NR_query_module 178
#define __NR_quotactl 179
#define __NR_nfsservctl 180
#define __NR_getpmsg 181
#define __NR_putpmsg 182
#define __NR_afs_syscall 183
#define __NR_tuxcall 184
#define __NR_security 185
#define __NR_gettid 186
#define __NR_readahead 187
#define __NR_setxattr 188
#define __NR_lsetxattr 189
#define __NR_fsetxattr 190
#define __NR_getxattr 191
#define __NR_lgetxattr 192
#define __NR_fgetxattr 193
#define __NR_listxattr 194
#define __NR_llistxattr 195
#define __NR_flistxattr 196
#define __NR_removexattr 197
#define __NR_lremovexattr 198
#define __NR_fremovexattr 199
#define __NR_tkill 200
#define __NR_time 201
#define __NR_futex 202
#define __NR_sched_setaffinity 203
#define __NR_sched_getaffinity 204
#define __NR_set_thread_area 205
#define __NR_io_setup 206
#define __NR_io_destroy 207
#define __NR_io_getevents 208
#define __NR_io_submit 209
#define __NR_io_cancel 210
#define __NR_get_thread_area 211
#define __NR_lookup_dcookie 212
#define __NR_epoll_create 213
#define __NR_epoll_ctl_old 214
#define __NR_epoll_wait_old 215
#define __NR_remap_file_pages 216
#define __NR_getdents64 217
#define __NR_set_tid_address 218
#define __NR_restart_syscall 219
#define __NR_semtimedop 220
#define __NR_fadvise64 221
#define __NR_timer_create 222
#define __NR_timer_settime 223
#define __NR_timer_gettime 224
#define __NR_timer_getoverrun 225
#define __NR_timer_delete 226
#define __NR_clock_settime 227
#define __NR_clock_gettime 228
#define __NR_clock_getres 229
#define __NR_clock_nanosleep 230
#define __NR_exit_group 231
#define __NR_epoll_wait 232
#define __NR_epoll_ctl 233
#define __NR_tgkill 234
#define __NR_utimes 235
#define __NR_vserver 236
#define __NR_mbind 237
#define __NR_set_mempolicy 238
#define __NR_get_mempolicy 239
#define __NR_mq_open 240
#define __NR_mq_unlink 241
#define __NR_mq_timedsend 242
#define __NR_mq_timedreceive 243
#define __NR_mq_notify 244
#define __NR_mq_getsetattr 245
#define __NR_kexec_load 246
#define __NR_waitid 247
#define __NR_add_key 248
#define __NR_request_key 249
#define __NR_keyctl 250
#define __NR_ioprio_set 251
#define __NR_ioprio_get 252
#define __NR_inotify_init 253
#define __NR_inotify_add_watch 254
#define __NR_inotify_rm_watch 255
#define __NR_migrate_pages 256
#define __NR_openat 257
#define __NR_mkdirat 258
#define __NR_mknodat 259
#define __NR_fchownat 260
#define __NR_futimesat 261
#define __NR_newfstatat 262
#define __NR_unlinkat 263
#define __NR_renameat 264
#define __NR_linkat 265
#define __NR_symlinkat 266
#define __NR_readlinkat 267
#define __NR_fchmodat 268
#define __NR_faccessat 269
#define __NR_pselect6 270
#define __NR_ppoll 271
#define __NR_unshare 272
#define __NR_set_robust_list 273
#define __NR_get_robust_list 274
#define __NR_splice 275
#define __NR_tee 276
#define __NR_sync_file_range 277
#define __NR_vmsplice 278
#define __NR_move_pages 279
#define __NR_utimensat 280
#define __NR_epoll_pwait 281
#define __NR_signalfd 282
#define __NR_timerfd_create 283
#define __NR_eventfd 284
#define __NR_fallocate 285
#define __NR_timerfd_settime 286
#define __NR_timerfd_gettime 287
#define __NR_accept4 288
#define __NR_signalfd4 289
#define __NR_eventfd2 290
#define __NR_epoll_create1 291
#define __NR_dup3 292
#define __NR_pipe2 293
#define __NR_inotify_init1 294
#define __NR_preadv 295
#define __NR_pwritev 296
#define __NR_rt_tgsigqueueinfo 297
#define __NR_perf_event_open 298
#define __NR_recvmmsg 299
#define __NR_fanotify_init 300
#define __NR_fanotify_mark 301
#define __NR_prlimit64 302
#define __NR_name_to_handle_at 303
#define __NR_open_by_handle_at 304
#define __NR_clock_adjtime 305
#define __NR_syncfs 306
#define __NR_sendmmsg 307
#define __NR_setns 308
#define __NR_getcpu 309
#define __NR_process_vm_readv 310
#define __NR_process_vm_writev 311
#define __NR_kcmp 312
#define __NR_finit_module 313
#define __NR_sched_setattr 314
#define __NR_sched_getattr 315
#define __NR_renameat2 316
#define __NR_seccomp 317
#define __NR_getrandom 318
#define __NR_memfd_create 319
#define __NR_kexec_file_load 320
#define __NR_bpf 321
#define __NR_execveat 322
#define __NR_userfaultfd 323
#define __NR_membarrier 324
#define __NR_mlock2 325
#define __NR_copy_file_range 326
#define __NR_preadv2 327
#define __NR_pwritev2 328
#define __NR_pkey_mprotect 329
#define __NR_pkey_alloc 330
#define __NR_pkey_free 331
#define __NR_statx 332

#endif /* _ASM_X86_UNISTD_64_H */
#else
#ifndef _ASM_X86_UNISTD_32_H
#define _ASM_X86_UNISTD_32_H

/*
 * This file contains the system call numbers.
 */

#define __NR_restart_syscall      0
#define __NR_exit		  1
#define __NR_fork		  2
#define __NR_read		  3
#define __NR_write		  4
#define __NR_open		  5
#define __NR_close		  6
#define __NR_waitpid		  7
#define __NR_creat		  8
#define __NR_link		  9
#define __NR_unlink		 10
#define __NR_execve		 11
#define __NR_chdir		 12
#define __NR_time		 13
#define __NR_mknod		 14
#define __NR_chmod		 15
#define __NR_lchown		 16
#define __NR_break		 17
#define __NR_oldstat		 18
#define __NR_lseek		 19
#define __NR_getpid		 20
#define __NR_mount		 21
#define __NR_umount		 22
#define __NR_setuid		 23
#define __NR_getuid		 24
#define __NR_stime		 25
#define __NR_ptrace		 26
#define __NR_alarm		 27
#define __NR_oldfstat		 28
#define __NR_pause		 29
#define __NR_utime		 30
#define __NR_stty		 31
#define __NR_gtty		 32
#define __NR_access		 33
#define __NR_nice		 34
#define __NR_ftime		 35
#define __NR_sync		 36
#define __NR_kill		 37
#define __NR_rename		 38
#define __NR_mkdir		 39
#define __NR_rmdir		 40
#define __NR_dup		 41
#define __NR_pipe		 42
#define __NR_times		 43
#define __NR_prof		 44
#define __NR_brk		 45
#define __NR_setgid		 46
#define __NR_getgid		 47
#define __NR_signal		 48
#define __NR_geteuid		 49
#define __NR_getegid		 50
#define __NR_acct		 51
#define __NR_umount2		 52
#define __NR_lock		 53
#define __NR_ioctl		 54
#define __NR_fcntl		 55
#define __NR_mpx		 56
#define __NR_setpgid		 57
#define __NR_ulimit		 58
#define __NR_oldolduname	 59
#define __NR_umask		 60
#define __NR_chroot		 61
#define __NR_ustat		 62
#define __NR_dup2		 63
#define __NR_getppid		 64
#define __NR_getpgrp		 65
#define __NR_setsid		 66
#define __NR_sigaction		 67
#define __NR_sgetmask		 68
#define __NR_ssetmask		 69
#define __NR_setreuid		 70
#define __NR_setregid		 71
#define __NR_sigsuspend		 72
#define __NR_sigpending		 73
#define __NR_sethostname	 74
#define __NR_setrlimit		 75
#define __NR_getrlimit		 76   /* Back compatible 2Gig limited rlimit */
#define __NR_getrusage		 77
#define __NR_gettimeofday	 78
#define __NR_settimeofday	 79
#define __NR_getgroups		 80
#define __NR_setgroups		 81
#define __NR_select		 82
#define __NR_symlink		 83
#define __NR_oldlstat		 84
#define __NR_readlink		 85
#define __NR_uselib		 86
#define __NR_swapon		 87
#define __NR_reboot		 88
#define __NR_readdir		 89
#define __NR_mmap		 90
#define __NR_munmap		 91
#define __NR_truncate		 92
#define __NR_ftruncate		 93
#define __NR_fchmod		 94
#define __NR_fchown		 95
#define __NR_getpriority	 96
#define __NR_setpriority	 97
#define __NR_profil		 98
#define __NR_statfs		 99
#define __NR_fstatfs		100
#define __NR_ioperm		101
#define __NR_socketcall		102
#define __NR_syslog		103
#define __NR_setitimer		104
#define __NR_getitimer		105
#define __NR_stat		106
#define __NR_lstat		107
#define __NR_fstat		108
#define __NR_olduname		109
#define __NR_iopl		110
#define __NR_vhangup		111
#define __NR_idle		112
#define __NR_vm86old		113
#define __NR_wait4		114
#define __NR_swapoff		115
#define __NR_sysinfo		116
#define __NR_ipc		117
#define __NR_fsync		118
#define __NR_sigreturn		119
#define __NR_clone		120
#define __NR_setdomainname	121
#define __NR_uname		122
#define __NR_modify_ldt		123
#define __NR_adjtimex		124
#define __NR_mprotect		125
#define __NR_sigprocmask	126
#define __NR_create_module	127
#define __NR_init_module	128
#define __NR_delete_module	129
#define __NR_get_kernel_syms	130
#define __NR_quotactl		131
#define __NR_getpgid		132
#define __NR_fchdir		133
#define __NR_bdflush		134
#define __NR_sysfs		135
#define __NR_personality	136
#define __NR_afs_syscall	137 /* Syscall for Andrew File System */
#define __NR_setfsuid		138
#define __NR_setfsgid		139
#define __NR__llseek		140
#define __NR_getdents		141
#define __NR__newselect		142
#define __NR_flock		143
#define __NR_msync		144
#define __NR_readv		145
#define __NR_writev		146
#define __NR_getsid		147
#define __NR_fdatasync		148
#define __NR__sysctl		149
#define __NR_mlock		150
#define __NR_munlock		151
#define __NR_mlockall		152
#define __NR_munlockall		153
#define __NR_sched_setparam		154
#define __NR_sched_getparam		155
#define __NR_sched_setscheduler		156
#define __NR_sched_getscheduler		157
#define __NR_sched_yield		158
#define __NR_sched_get_priority_max	159
#define __NR_sched_get_priority_min	160
#define __NR_sched_rr_get_interval	161
#define __NR_nanosleep		162
#define __NR_mremap		163
#define __NR_setresuid		164
#define __NR_getresuid		165
#define __NR_vm86		166
#define __NR_query_module	167
#define __NR_poll		168
#define __NR_nfsservctl		169
#define __NR_setresgid		170
#define __NR_getresgid		171
#define __NR_prctl              172
#define __NR_rt_sigreturn	173
#define __NR_rt_sigaction	174
#define __NR_rt_sigprocmask	175
#define __NR_rt_sigpending	176
#define __NR_rt_sigtimedwait	177
#define __NR_rt_sigqueueinfo	178
#define __NR_rt_sigsuspend	179
#define __NR_pread64		180
#define __NR_pwrite64		181
#define __NR_chown		182
#define __NR_getcwd		183
#define __NR_capget		184
#define __NR_capset		185
#define __NR_sigaltstack	186
#define __NR_sendfile		187
#define __NR_getpmsg		188	/* some people actually want streams */
#define __NR_putpmsg		189	/* some people actually want streams */
#define __NR_vfork		190
#define __NR_ugetrlimit		191	/* SuS compliant getrlimit */
#define __NR_mmap2		192
#define __NR_truncate64		193
#define __NR_ftruncate64	194
#define __NR_stat64		195
#define __NR_lstat64		196
#define __NR_fstat64		197
#define __NR_lchown32		198
#define __NR_getuid32		199
#define __NR_getgid32		200
#define __NR_geteuid32		201
#define __NR_getegid32		202
#define __NR_setreuid32		203
#define __NR_setregid32		204
#define __NR_getgroups32	205
#define __NR_setgroups32	206
#define __NR_fchown32		207
#define __NR_setresuid32	208
#define __NR_getresuid32	209
#define __NR_setresgid32	210
#define __NR_getresgid32	211
#define __NR_chown32		212
#define __NR_setuid32		213
#define __NR_setgid32		214
#define __NR_setfsuid32		215
#define __NR_setfsgid32		216
#define __NR_pivot_root		217
#define __NR_mincore		218
#define __NR_madvise		219
#define __NR_madvise1		219	/* delete when C lib stub is removed */
#define __NR_getdents64		220
#define __NR_fcntl64		221
/* 223 is unused */
#define __NR_gettid		224
#define __NR_readahead		225
#define __NR_setxattr		226
#define __NR_lsetxattr		227
#define __NR_fsetxattr		228
#define __NR_getxattr		229
#define __NR_lgetxattr		230
#define __NR_fgetxattr		231
#define __NR_listxattr		232
#define __NR_llistxattr		233
#define __NR_flistxattr		234
#define __NR_removexattr	235
#define __NR_lremovexattr	236
#define __NR_fremovexattr	237
#define __NR_tkill		238
#define __NR_sendfile64		239
#define __NR_futex		240
#define __NR_sched_setaffinity	241
#define __NR_sched_getaffinity	242
#define __NR_set_thread_area	243
#define __NR_get_thread_area	244
#define __NR_io_setup		245
#define __NR_io_destroy		246
#define __NR_io_getevents	247
#define __NR_io_submit		248
#define __NR_io_cancel		249
#define __NR_fadvise64		250
/* 251 is available for reuse (was briefly sys_set_zone_reclaim) */
#define __NR_exit_group		252
#define __NR_lookup_dcookie	253
#define __NR_epoll_create	254
#define __NR_epoll_ctl		255
#define __NR_epoll_wait		256
#define __NR_remap_file_pages	257
#define __NR_set_tid_address	258
#define __NR_timer_create	259
#define __NR_timer_settime	(__NR_timer_create+1)
#define __NR_timer_gettime	(__NR_timer_create+2)
#define __NR_timer_getoverrun	(__NR_timer_create+3)
#define __NR_timer_delete	(__NR_timer_create+4)
#define __NR_clock_settime	(__NR_timer_create+5)
#define __NR_clock_gettime	(__NR_timer_create+6)
#define __NR_clock_getres	(__NR_timer_create+7)
#define __NR_clock_nanosleep	(__NR_timer_create+8)
#define __NR_statfs64		268
#define __NR_fstatfs64		269
#define __NR_tgkill		270
#define __NR_utimes		271
#define __NR_fadvise64_64	272
#define __NR_vserver		273
#define __NR_mbind		274
#define __NR_get_mempolicy	275
#define __NR_set_mempolicy	276
#define __NR_mq_open 		277
#define __NR_mq_unlink		(__NR_mq_open+1)
#define __NR_mq_timedsend	(__NR_mq_open+2)
#define __NR_mq_timedreceive	(__NR_mq_open+3)
#define __NR_mq_notify		(__NR_mq_open+4)
#define __NR_mq_getsetattr	(__NR_mq_open+5)
#define __NR_kexec_load		283
#define __NR_waitid		284
/* #define __NR_sys_setaltroot	285 */
#define __NR_add_key		286
#define __NR_request_key	287
#define __NR_keyctl		288
#define __NR_ioprio_set		289
#define __NR_ioprio_get		290
#define __NR_inotify_init	291
#define __NR_inotify_add_watch	292
#define __NR_inotify_rm_watch	293
#define __NR_migrate_pages	294
#define __NR_openat		295
#define __NR_mkdirat		296
#define __NR_mknodat		297
#define __NR_fchownat		298
#define __NR_futimesat		299
#define __NR_fstatat64		300
#define __NR_unlinkat		301
#define __NR_renameat		302
#define __NR_linkat		303
#define __NR_symlinkat		304
#define __NR_readlinkat		305
#define __NR_fchmodat		306
#define __NR_faccessat		307
#define __NR_pselect6		308
#define __NR_ppoll		309
#define __NR_unshare		310
#define __NR_set_robust_list	311
#define __NR_get_robust_list	312
#define __NR_splice		313
#define __NR_sync_file_range	314
#define __NR_tee		315
#define __NR_vmsplice		316
#define __NR_move_pages		317
#define __NR_getcpu		318
#define __NR_epoll_pwait	319
#define __NR_utimensat		320
#define __NR_signalfd		321
#define __NR_timerfd_create	322
#define __NR_eventfd		323
#define __NR_fallocate		324
#define __NR_timerfd_settime	325
#define __NR_timerfd_gettime	326
#define __NR_signalfd4		327
#define __NR_eventfd2		328
#define __NR_epoll_create1	329
#define __NR_dup3		330
#define __NR_pipe2		331
#define __NR_inotify_init1	332
#define __NR_preadv		333
#define __NR_pwritev		334
#define __NR_rt_tgsigqueueinfo	335
#define __NR_perf_event_open	336
#define __NR_recvmmsg		337
#define __NR_fanotify_init	338
#define __NR_fanotify_mark	339
#define __NR_prlimit64		340

#endif /* _ASM_X86_UNISTD_32_H */
#endif

#endif


// syscall table at: /usr/src/linux/include/linux/syscalls.h. 
// table, ordered: /usr/src/linux/arch/x86/syscalls/syscall_32.tbl

// defining sycalls as static inline has these advantages:
// -not compiled, if not used
// -optimization can take place, gcc (4.4.5, at least) doesn't use the stack at all.
// since the syscall parameters have to be placed into registers,
// using functions would mean push and pop every parameter.
// even with -O (lowest Optimization) gcc handles putting the parameters into the right registers fine.
// so static inline even results often in smaller codesize than not inlining.
//

//#define __callend : "rcx" )

// Seems linux x86_64 has same convention as osx darwin
#ifdef X64

// memory clobber is needed, gcc optimizes syscalls very likely away without
#define __callend : "memory","rcx", "r11" )
//(also osx)
#define __SYSCALL_ASM(ret,call) asm volatile ("syscall" : "=a" (ret)  : "a" ( (call | NCONST ) )
#else
#ifdef mini_vsyscalls
#define __SYSCALL_ASM(ret,call) asm volatile ("call *__mini_vsys" : "=a" (ret)  : "a" (call)
#else
//linux32bit
// memory clobber is needed, gcc optimizes syscalls very likely away without
#define __callend : "memory" )
#define __SYSCALL_ASM(ret,call) asm volatile ("int $0x80" : "=a" (ret)  : "a" (call)
#endif
#endif

#ifdef X64 
	// also osx
#define syscall1(ret,call,a1) __SYSCALL_ASM(ret,call) , "D" (a1) __callend
#define syscall2(ret,call,a1,a2) __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2) __callend
#define syscall3(ret,call,a1,a2,a3) __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3) __callend
//#warning seems register ecx has been replaced with r10, but cannot say for sure. Tests needed.
//#warning Yes. Todo: change macros accordingly. Also better copy flags. or not? ALso a question of an unneccessary instruction. 

#define syscall4(ret,call,a1,a2,a3,a4) register long int r10 asm ("r10") = a4 ; __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "r" (r10) __callend
//#define syscall4(ret,call,a1,a2,a3,a4) __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "c" (a4) __callend
#define syscall5(ret,call,a1,a2,a3,a4,a5) register long int r10 asm ("r10") = a4 ; register long int r8 asm ("r8") = a5 ; __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "r" (r10), "r" (r8) __callend
#define syscall6(ret,call,a1,a2,a3,a4,a5,a6) register long int r10 asm ("r10") = a4 ; register long int r8 asm ("r8") = a5 ; register long int r9 asm ("r9") = a6; __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "r" (r10), "r" (r8), "r" (r9) __callend


// save value in (temporary) var sysret.
// return -1 if an error occured, set errno.
#define syscall0_ret(call) __SYSCALL_ASM(sysret,call) 
#define syscall1_ret(call) syscall0_ret(call) , "D" (a1) 
#define syscall2_ret(call) syscall1_ret(call) , "S" (a2) 
#define syscall3_ret(call) syscall2_ret(call) , "d" (a3) 
#define syscall4_ret(call) register long int r10 asm("r10")= a4; syscall3_ret(call) , "r" (r10)
#define syscall5_ret(call) register long int r10 asm("r10")= a4; register long int r8 asm("r8")= a5 ; syscall4_ret(call) , "r" (r8) 

#else

//linux

#ifndef X64
//linux 32bit

#define syscall1(ret,call,a1) __SYSCALL_ASM(ret,call) , "b" (a1) __callend
#define syscall2(ret,call,a1,a2) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2) __callend
#define syscall3(ret,call,a1,a2,a3) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3) __callend
#define syscall4(ret,call,a1,a2,a3,a4) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4) __callend
#define syscall5(ret,call,a1,a2,a3,a4,a5) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4), "D" (a5) __callend


// save value in (temporary) var sysret.
// return -1 if an error occured, set errno.
#define syscall0_ret(call) __SYSCALL_ASM(sysret,call) 
#define syscall1_ret(call) syscall0_ret(call) , "b" (a1) 
#define syscall2_ret(call) syscall1_ret(call) , "c" (a2) 
#define syscall3_ret(call) syscall2_ret(call) , "d" (a3) 
#define syscall4_ret(call) syscall3_ret(call) , "S" (a4)
#define syscall5_ret(call) syscall4_ret(call) , "D" (a5) 

#else
// linux 86_X64
#define syscall1(ret,call,a1) __SYSCALL_ASM(ret,call) , "b" (a1) __callend
#define syscall2(ret,call,a1,a2) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2) __callend
#define syscall3(ret,call,a1,a2,a3) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3) __callend
#define syscall4(ret,call,a1,a2,a3,a4) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4) __callend
#define syscall5(ret,call,a1,a2,a3,a4,a5) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4), "D" (a5) __callend


// save value in (temporary) var sysret.
// return -1 if an error occured, set errno.
#define syscall0_ret(call) __SYSCALL_ASM(sysret,call) 
#define syscall1_ret(call) syscall0_ret(call) , "b" (a1) 
#define syscall2_ret(call) syscall1_ret(call) , "c" (a2) 
#define syscall3_ret(call) syscall2_ret(call) , "d" (a3) 
#define syscall4_ret(call) syscall3_ret(call) , "S" (a4)
#define syscall5_ret(call) syscall4_ret(call) , "D" (a5) 

#endif

#endif


// args: count of parameters, syscall number, [parameters...]
#define __DO_syscall(n,...) syscall##n##_ret( __VA_ARGS__ ) __callend

// args: name (e.g. getpid), count of args, arguments (e.g. int* a1, char *a2).
// arguments must be named a1,a2,...

#ifdef mini_errno
#define REAL_define_syscall( name, argcount, ... ) inline \
		int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, (SCALL(name) | NCONST ) );\
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}
#else
#define REAL_define_syscall( name, argcount, ... ) inline \
		int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, ( SCALL(name) | NCONST ) );\
				return( (sysret<0) ? -1 : sysret );\
		}
#endif

//return( (sysret<0) ? -1 : sysret ); (no errno) : ok. not added anything to the final size

/*
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}
		*/

// global sysret: +34 bytes (??)

// errno = (sysret<0) ? 0 : sysret;\ + 42 bytes..

/* (+64bytes) /+38 bytes with local sysret
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}\
		*/

// args: name (e.g. getpid), argument to return, count of args, arguments (e.g. int* a1, char *a2).
// arguments must be named a1,a2,...
#define REAL_define_syscallret( name, ret, argcount, ... ) inline \
		int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
				__DO_syscall( argcount, SCALL(name));\
				if ( sysret<0 ){\
						errno = -sysret;\
						return(-1);}\
				return(ret);\
		}\


#define DEF_syscall(...) 
#define DEF_syscallret(...) 



//#define __DEF_SYSCALL(count) extern int __attribute__((always_inline,optimize("0"))) 

#if 0 

#define __SYSCALL_ASMret(call) asm volatile ("mov %1,%%eax\n\tint $0x80" : "=a" (sysret)  : "g" (call)

#define syscall0_ret(call,unused) __SYSCALL_ASMret(call) )
#define syscall1_ret(call,a1) __SYSCALL_ASMret(call) , "b" (a1) )
#define syscall2_ret(call,a1,a2) __SYSCALL_ASMret(call) , "b" (a1), "c" (a2) )
#define syscall3_ret(call,a1,a2,a3) __SYSCALL_ASMret(call) , "b" (a1), "c" (a2), "d" (a3) )
#define syscall4_ret(call,a1,a2,a3,a4) __SYSCALL_ASMret(call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4))
#define syscall5_ret(call,a1,a2,a3,a4,a5) __SYSCALL_ASMret(call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4), "D" (a5) )

// args: count of parameters, syscall number, [parameters...]
#define __DO_syscall(n,...) syscall##n##_ret( __VA_ARGS__ )

// args: name (e.g. getpid), count of args, arguments (e.g. int* a1, char *a2).
#define DEF_syscall( name, argcount, ... ) static inline \
		int __attribute__((always_inline)) name( __VA_ARGS__ ){\
				__DO_syscall( argcount, __NR_##name , __VA_ARGS__ );\
				if ( sysret<0 )\
						errno = -sysret;\
				return(sysret);\
		}\





wantbugs_by_optimizing
#define __SYSCALL_asm(ret) asm volatile ("int $0x80" : "=a" (ret)  : "0" (call),

#define __SYSCALL_CONSTRAINTS_1 "b" (a1)
#define __SYSCALL_CONSTRAINTS_2 __SYSCALL_CONSTRAINTS_1, "c" (a2)
#define __SYSCALL_CONSTRAINTS_3 __SYSCALL_CONSTRAINTS_2, "d" (a3)
#define __SYSCALL_CONSTRAINTS_4 __SYSCALL_CONSTRAINTS_3, "S" (a4)
#define __SYSCALL_CONSTRAINTS_5 __SYSCALL_CONSTRAINTS_4, "D" (a5)

#define __SYSCALL_ARGS1 int a1
#define __SYSCALL_ARGS2 __SYSCALL_ARGS1, int a2
#define __SYSCALL_ARGS3 __SYSCALL_ARGS2, int a3
#define __SYSCALL_ARGS4 __SYSCALL_ARGS3, int a4
#define __SYSCALL_ARGS5 __SYSCALL_ARGS4, int a5
#define __SYSCALL_ARGS6 __SYSCALL_ARGS5, int a6


				
#define __DEF_SYSCALL(count) extern int \
		__syscall ## count \
				( int call, __SYSCALL_ARGS ## count );


#define __IMPL_SYSCALL(count) int \
		__syscall ## count \
				( int call, __SYSCALL_ARGS ## count ){\
		__SYSCALL_asm(call)  __SYSCALL_CONSTRAINTS_ ##count );\
		return(call);\
}

__DEF_SYSCALL(1)
__DEF_SYSCALL(2)
__DEF_SYSCALL(3)
__DEF_SYSCALL(4)
__DEF_SYSCALL(5)


#define syscall1(call,a) __syscall1((int)call,(int)a)
#define syscall2(call,a,b) __syscall2(call,(int)a,(int)b)
#define syscall3(call,a,b,c) __syscall3(call,(int)a,(int)b,(int)c)
#define syscall4(call,a,b,c,d) __syscall4(call,(int)a,(int)b,(int)c,(int)d)
//#define syscall5(call,a,b,c,d,e) __syscall5(call,(int)a,(int)b,(int)c,(int)d,(int)e)
#define syscall6(call,a,b,c,d,e,f) __syscall6(call,(int)a,(int)b,(int)c,(int)d,(int)e,(int)f)

	/*
static inline int __attribute__((always_inline)) __syscall6(int call, __SYSCALL_ARGS6 ){
		int ret;
		asm volatile ("push %%ebp\n\tmov %1,%%ebp\n\t int $0x80\n\tpop %%ebp" \
												 : "=a" (ret) : "g" (a6), "a" (call) __SYSCALL_CONSTRAINTS_5 );
		return(ret);
}
*/

#endif

#endif
#ifndef syscall_stubs_h
#define syscall_stubs_h
/*
 These are just wrapped syscalls.
 errno is set, anyway.

 The arguments need to be named a1,a2,..

*/

//+header declarations.h
//
///+needs mini_fstream.h

//#include "syscall.h"
//#include "sys/types.h"
//#include "sys/syscall.h"

extern int sysret;
extern int errno;

struct stat;
struct timeval;
struct timezone;


DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )

DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

DEF_syscall(close, 1, int fd )
DEF_syscall(read, 3, int fd, POINTER *buf, int len )

DEF_syscall(uname,1,struct old_utsname *name )

DEF_syscall(getdents, 3, unsigned int fd, struct dirent *direntry, unsigned int count )

DEF_syscall(write,3,int fd,const void *buf, int len )
//rename a1=oldpath a2=newpath

DEF_syscall(rename,2, const char* a1, const char* a2 )		
DEF_syscall(unlink,1, const char* a1)		

DEF_syscall(fstat,2,int a1,struct stat* a2)		
DEF_syscall(stat,2,const char* filename,struct stat* a2)		
DEF_syscall(dup,1,int a1)		
DEF_syscall(dup2,2,int a1, int a2)		
DEF_syscall(dup3,3,int a1, int a2, int a3)		

DEF_syscall(getcwd,2,char *buf,long size)		


#ifndef OSX
DEF_syscall(time,1,unsigned int *a1 )
//DEF_syscallret(time,*a1,1,unsigned int *a1 )
#else

#endif

	// problem: ifdef / ifndef now doesnt work anymore for the definitions. 
	// Hopefully, thats not going to be a problem.
	// Will see it when trying to compile at osx again
	//
/* --- generated-macros-start: syscalldefs --- */
/* minilib/include/syscall_stubs.h, line: 41 */
REAL_define_syscall(write,3,int a1, const void *a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 39 */
REAL_define_syscall(getdents, 3, unsigned int a1,  struct dirent *a2,  unsigned int a3) 

/* minilib/include/syscall_stubs.h, line: 45 */
REAL_define_syscall(unlink,1, const char* a1) 		

/* minilib/include/lseek.h, line: 20 */
REAL_define_syscall(ftruncate,2,unsigned int a1,  unsigned int a2) 

/* minilib/include/syscall_stubs.h, line: 50 */
REAL_define_syscall(dup2,2,int a1,  int a2) 		

/* minilib/include/syscall_stubs.h, line: 34 */
REAL_define_syscall(close, 1, int a1) 

/* minilib/include/syscall_stubs.h, line: 32 */
REAL_define_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3)

/* minilib/include/syscall_stubs.h, line: 48 */
REAL_define_syscall(stat,2,const char* a1, struct stat* a2) 		

/* minilib/include/syscall_stubs.h, line: 49 */
REAL_define_syscall(dup,1,int a1) 		

/* minilib/include/syscall_stubs.h, line: 47 */
REAL_define_syscall(fstat,2,int a1, struct stat* a2) 		

/* minilib/include/syscall_stubs.h, line: 28 */
REAL_define_syscall(gettimeofday,2, struct timeval *a1,  struct timezone *a2) 

/* minilib/include/syscall_stubs.h, line: 44 */
REAL_define_syscall(rename,2, const char* a1,  const char* a2) 		

/* minilib/include/syscall_stubs.h, line: 51 */
REAL_define_syscall(dup3,3,int a1,  int a2,  int a3) 		

/* minilib/include/syscall_stubs.h, line: 30 */
REAL_define_syscall(getpid,0 )

/* minilib/include/syscall_stubs.h, line: 37 */
REAL_define_syscall(uname,1,struct old_utsname *a1) 

/* minilib/include/lseek.h, line: 18 */
REAL_define_syscall(lseek,3,unsigned int a1,  int a2,  int a3) 

/* minilib/include/lseek.h, line: 21 */
REAL_define_syscall(fsync,1,int a1) 

/* minilib/include/syscall_stubs.h, line: 57 */
REAL_define_syscall(time,1,unsigned int *a1) 

/* minilib/include/syscall_stubs.h, line: 35 */
REAL_define_syscall(read, 3, int a1,  POINTER *a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 53 */
REAL_define_syscall(getcwd,2,char *a1, long a2) 		

/* --- generated-macros-end: syscalldefs --- */


#endif
#ifndef	SYS_TYPES_H
#define	SYS_TYPES_H

#ifndef POINTER
#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER int
#endif
#endif


// source: musl
#ifndef alltypes_h
#define alltypes_h


#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif



#define _Addr long
#define _Int64 long
#define _Reg long

#ifndef size_t
#define size_t long
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

//typedef __builtin_va_list va_list;

//typedef __builtin_va_list __isoc_va_list;

typedef int wchar_t;

typedef long double double_t;

typedef float float_t;

typedef struct { long long __ll; long double __ld; } max_align_t;

//typedef long time_t;

//typedef long suseconds_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;

typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;

//typedef unsigned _Addr size_t;
//#define __DEFINED_size_t

typedef unsigned _Addr uintptr_t;

typedef _Addr ptrdiff_t;

typedef _Addr ssize_t;

typedef _Addr intptr_t;

typedef _Addr regoff_t;

typedef _Reg register_t;

typedef signed char     int8_t;

typedef signed short    int16_t;

typedef signed int      int32_t;

typedef signed _Int64   int64_t;

typedef signed _Int64   intmax_t;

typedef unsigned char   uint8_t;

typedef unsigned short  uint16_t;

typedef unsigned int    uint32_t;

typedef unsigned _Int64 uint64_t;

typedef unsigned _Int64 u_int64_t;

typedef unsigned _Int64 uintmax_t;

typedef unsigned mode_t;

typedef unsigned _Reg nlink_t;

typedef _Int64 off_t;

typedef unsigned _Int64 ino_t;

typedef unsigned _Int64 dev_t;

typedef long blksize_t;

typedef _Int64 blkcnt_t;

typedef unsigned _Int64 fsblkcnt_t;

typedef unsigned _Int64 fsfilcnt_t;

typedef unsigned wint_t;

typedef unsigned long wctype_t;

typedef void * timer_t;

typedef int clockid_t;

typedef long clock_t;

//struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timespec { time_t tv_sec; long tv_nsec; };

typedef int pid_t;

typedef unsigned id_t;

typedef unsigned uid_t;

typedef unsigned gid_t;

typedef int key_t;

//typedef unsigned useconds_t;

//typedef struct _IO_FILE FILE;

typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;

typedef struct __locale_struct * locale_t;

typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;

struct iovec { void *iov_base; size_t iov_len; };

typedef unsigned socklen_t;

typedef unsigned short sa_family_t;

#undef _Addr
#undef _Int64
#undef _Reg

#endif


typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned u_int32_t;
typedef char *caddr_t;
typedef unsigned char u_char;
typedef unsigned short u_short, ushort;
typedef unsigned u_int, uint;
typedef unsigned long u_long, ulong;
typedef long long quad_t;
typedef unsigned long long u_quad_t;
#ifndef _ENDIAN_H
#define _ENDIAN_H


#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN 4321
#define __PDP_ENDIAN 3412
#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

#define BIG_ENDIAN __BIG_ENDIAN
#define LITTLE_ENDIAN __LITTLE_ENDIAN
#define PDP_ENDIAN __PDP_ENDIAN
#define BYTE_ORDER __BYTE_ORDER

#ifndef _STDINT_H
#define _STDINT_H

#define __NEED_int8_t
#define __NEED_int16_t
#define __NEED_int32_t
#define __NEED_int64_t

#define __NEED_uint8_t
#define __NEED_uint16_t
#define __NEED_uint32_t
#define __NEED_uint64_t

#define __NEED_intptr_t
#define __NEED_uintptr_t

#define __NEED_intmax_t
#define __NEED_uintmax_t

// source: musl
#ifndef alltypes_h
#define alltypes_h


#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif



#define _Addr long
#define _Int64 long
#define _Reg long

#ifndef size_t
#define size_t long
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

//typedef __builtin_va_list va_list;

//typedef __builtin_va_list __isoc_va_list;

typedef int wchar_t;

typedef long double double_t;

typedef float float_t;

typedef struct { long long __ll; long double __ld; } max_align_t;

//typedef long time_t;

//typedef long suseconds_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;

typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;

//typedef unsigned _Addr size_t;
//#define __DEFINED_size_t

typedef unsigned _Addr uintptr_t;

typedef _Addr ptrdiff_t;

typedef _Addr ssize_t;

typedef _Addr intptr_t;

typedef _Addr regoff_t;

typedef _Reg register_t;

typedef signed char     int8_t;

typedef signed short    int16_t;

typedef signed int      int32_t;

typedef signed _Int64   int64_t;

typedef signed _Int64   intmax_t;

typedef unsigned char   uint8_t;

typedef unsigned short  uint16_t;

typedef unsigned int    uint32_t;

typedef unsigned _Int64 uint64_t;

typedef unsigned _Int64 u_int64_t;

typedef unsigned _Int64 uintmax_t;

typedef unsigned mode_t;

typedef unsigned _Reg nlink_t;

typedef _Int64 off_t;

typedef unsigned _Int64 ino_t;

typedef unsigned _Int64 dev_t;

typedef long blksize_t;

typedef _Int64 blkcnt_t;

typedef unsigned _Int64 fsblkcnt_t;

typedef unsigned _Int64 fsfilcnt_t;

typedef unsigned wint_t;

typedef unsigned long wctype_t;

typedef void * timer_t;

typedef int clockid_t;

typedef long clock_t;

//struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timespec { time_t tv_sec; long tv_nsec; };

typedef int pid_t;

typedef unsigned id_t;

typedef unsigned uid_t;

typedef unsigned gid_t;

typedef int key_t;

//typedef unsigned useconds_t;

//typedef struct _IO_FILE FILE;

typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;

typedef struct __locale_struct * locale_t;

typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;

struct iovec { void *iov_base; size_t iov_len; };

typedef unsigned socklen_t;

typedef unsigned short sa_family_t;

#undef _Addr
#undef _Int64
#undef _Reg

#endif


typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;

typedef int8_t  int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;

typedef uint8_t  uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

#define INT8_MIN   (-1-0x7f)
#define INT16_MIN  (-1-0x7fff)
#define INT32_MIN  (-1-0x7fffffff)
#define INT64_MIN  (-1-0x7fffffffffffffff)

#define INT8_MAX   (0x7f)
#define INT16_MAX  (0x7fff)
#define INT32_MAX  (0x7fffffff)
#define INT64_MAX  (0x7fffffffffffffff)

#define UINT8_MAX  (0xff)
#define UINT16_MAX (0xffff)
#define UINT32_MAX (0xffffffffu)
#define UINT64_MAX (0xffffffffffffffffu)

#define INT_FAST8_MIN   INT8_MIN
#define INT_FAST64_MIN  INT64_MIN

#define INT_LEAST8_MIN   INT8_MIN
#define INT_LEAST16_MIN  INT16_MIN
#define INT_LEAST32_MIN  INT32_MIN
#define INT_LEAST64_MIN  INT64_MIN

#define INT_FAST8_MAX   INT8_MAX
#define INT_FAST64_MAX  INT64_MAX

#define INT_LEAST8_MAX   INT8_MAX
#define INT_LEAST16_MAX  INT16_MAX
#define INT_LEAST32_MAX  INT32_MAX
#define INT_LEAST64_MAX  INT64_MAX

#define UINT_FAST8_MAX  UINT8_MAX
#define UINT_FAST64_MAX UINT64_MAX

#define UINT_LEAST8_MAX  UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX

#define INTMAX_MIN  INT64_MIN
#define INTMAX_MAX  INT64_MAX
#define UINTMAX_MAX UINT64_MAX

#define WINT_MIN 0U
#define WINT_MAX UINT32_MAX

#if L'\0'-1 > 0
#define WCHAR_MAX (0xffffffffu+L'\0')
#define WCHAR_MIN (0+L'\0')
#else
#define WCHAR_MAX (0x7fffffff+L'\0')
#define WCHAR_MIN (-1-0x7fffffff+L'\0')
#endif

#define SIG_ATOMIC_MIN  INT32_MIN
#define SIG_ATOMIC_MAX  INT32_MAX

//#include <bits/stdint.h>

#define INT8_C(c)  c
#define INT16_C(c) c
#define INT32_C(c) c

#define UINT8_C(c)  c
#define UINT16_C(c) c
#define UINT32_C(c) c ## U

#if UINTPTR_MAX == UINT64_MAX
#define INT64_C(c) c ## L
#define UINT64_C(c) c ## UL
#define INTMAX_C(c)  c ## L
#define UINTMAX_C(c) c ## UL
#else
#define INT64_C(c) c ## LL
#define UINT64_C(c) c ## ULL
#define INTMAX_C(c)  c ## LL
#define UINTMAX_C(c) c ## ULL
#endif

#endif

static __inline uint16_t __bswap16(uint16_t __x)
{
	return __x<<8 | __x>>8;
}

static __inline uint32_t __bswap32(uint32_t __x)
{
	return __x>>24 | __x>>8&0xff00 | __x<<8&0xff0000 | __x<<24;
}

static __inline uint64_t __bswap64(uint64_t __x)
{
	return __bswap32(__x)+0ULL<<32 | __bswap32(__x>>32);
}

#if __BYTE_ORDER == __LITTLE_ENDIAN
#define htobe16(x) __bswap16(x)
#define be16toh(x) __bswap16(x)
#define betoh16(x) __bswap16(x)
#define htobe32(x) __bswap32(x)
#define be32toh(x) __bswap32(x)
#define betoh32(x) __bswap32(x)
#define htobe64(x) __bswap64(x)
#define be64toh(x) __bswap64(x)
#define betoh64(x) __bswap64(x)
#define htole16(x) (uint16_t)(x)
#define le16toh(x) (uint16_t)(x)
#define letoh16(x) (uint16_t)(x)
#define htole32(x) (uint32_t)(x)
#define le32toh(x) (uint32_t)(x)
#define letoh32(x) (uint32_t)(x)
#define htole64(x) (uint64_t)(x)
#define le64toh(x) (uint64_t)(x)
#define letoh64(x) (uint64_t)(x)
#else
#define htobe16(x) (uint16_t)(x)
#define be16toh(x) (uint16_t)(x)
#define betoh16(x) (uint16_t)(x)
#define htobe32(x) (uint32_t)(x)
#define be32toh(x) (uint32_t)(x)
#define betoh32(x) (uint32_t)(x)
#define htobe64(x) (uint64_t)(x)
#define be64toh(x) (uint64_t)(x)
#define betoh64(x) (uint64_t)(x)
#define htole16(x) __bswap16(x)
#define le16toh(x) __bswap16(x)
#define letoh16(x) __bswap16(x)
#define htole32(x) __bswap32(x)
#define le32toh(x) __bswap32(x)
#define letoh32(x) __bswap32(x)
#define htole64(x) __bswap64(x)
#define le64toh(x) __bswap64(x)
#define letoh64(x) __bswap64(x)
#endif

#endif

#endif

#define blkcnt64_t blkcnt_t
#define fsblkcnt64_t fsblkcnt_t
#define fsfilcnt64_t fsfilcnt_t
#define ino64_t ino_t
#define off64_t off_t

#endif



//#include "minilib.conf"
#ifndef start_c
#define start_c

#ifndef OSX

#ifdef mini_vsyscalls
int __mini_vsys = 0;
#ifndef startc_c
#define startc_c

typedef struct _elf_aux_v {
		unsigned int type;
		unsigned int value;
} elf_aux_v;



void __start_c(char **envp){

		//for ( ; *envp == 0; envp++  );
		while ( *envp++ != 0 );
		elf_aux_v *p = (elf_aux_v*)envp;

		while ( p ){
				if ( p->type == 32 ){
						__mini_vsys = p->value;
						return;
				}
				p++;
		}
}


#endif

#endif

#ifdef mini_start
#ifdef X64
#ifdef mini_start
void _start(){
// This is "callen" just before main.
// 
// dbg("Startup -xx"); // no arguments allowed here. 
// otherwise argv[] gets confused
// Or we would have to add some further bloating bytes
#ifdef mini_buf
ml.mbufsize = mini_buf;
ml.stream[0]=0;
ml.stream[1]=1;
ml.stream[2]=2;
ml.pstream = 3;
#endif
__asm__("\
#.global _start\n\
#_start:\n\
	popq %rdi\n\
	movq %rsp,%rsi\n\
	leaq  8(%rsi,%rdi,8),%rdx\n"
#ifdef mini_getenv
	"movq %rdx, mini_env\n"
#endif

	"call main\n\
	movq %rax, %rdi\n\
.global _exit\n\
_exit:\n\
	movq $60, %rax\n\
	syscall\n"
	);
};
#endif

#else
#ifdef mini_start
//#include "src/start_c.c"
void _start(){
// This is "callen" just before main.
// 
// dbg("Startup -xx"); // no arguments allowed here. 
// otherwise argv[] gets confused
// Or we would have to add some further bloating bytes
#ifdef mini_buf
ml.mbufsize = mini_buf;
ml.stream[0]=0;
ml.stream[1]=1;
ml.stream[2]=2;
ml.pstream = 3;
#endif
__asm__("\
#.global _start\n\
#_start:\n\
	pop %eax\n\
	leal  12(%esp,%eax,4),%ebx\n"
//	push %ebx\n
//	call __start_c\n
//	pop %ebx\n
  "pop %eax\n\
  mov %esp,%ecx\n\
	push %ebx\n\
	push %ecx\n\
	push %eax\n\
	call main\n\
	mov %eax, %ebx\n\
.global _exit\n\
_exit:\n\
	mov $1, %eax\n\
	int $0x80\n"
	);
};
#endif

#endif
#endif


#else

#ifdef mini_start
#ifdef mini_start
// Not tested yet
//
void start(){
// This is "callen" just before main.
// 
// dbg("Startup -xx"); // no arguments allowed here. 
// otherwise argv[] gets confused
// Or we would have to add some further bloating bytes
#ifdef mini_buf
ml.mbufsize = mini_buf;
ml.stream[0]=0;
ml.stream[1]=1;
ml.stream[2]=2;
ml.pstream = 3;
#endif
__asm__ volatile (
//		".globl start\n\t"
//		"start:	
		"pushq	$0\n\t"
		"movq	%rsp,%rbp\n\t"
		"andq    $-16,%rsp\n\t"
		"movq	8(%rbp),%rdi\n\t"
		"leaq	16(%rbp),%rsi\n\t"
		"movl	%edi,%edx\n\t"
		"addl	$1,%edx\n\t"
		"sall	$3,%edx\n\t"
		"addq	%rsi,%rdx\n\t"
		"movq	%rdx,%rcx\n\t"
		"jmp	Lapple2\n\t"
		"Lapple:	add	$8,%rcx\n\t"
		"Lapple2:cmpq	$0,(%rcx)\n\t"
		"jne	Lapple		    \n\t"
		"add	$8,%rcx\n\t"
		"call _main\n\t"
		"movq %rax, %rdi\n\t"
		".globl _exit\n\t"
		"_exit:\n\t"
		"movl $0x2000001, %eax\n\t"
		"syscall\n\t"
	);
} 
#endif

#endif


#endif




#endif
#ifndef minilib_globals_c
#define minilib_globals_c

// 
//#ifndef mini_buf
//#warning defining minibuf
//#define mini_buf 1024
//#endif
//
#ifdef mini_buf
minilib_globals ml;
//
//void minilib_global_init(){ // this is callen by startup.c
//	ml.mbufsize = mini_buf;
  //ibuf = (int*)mbuf;
//}
//
#else
//
//void minilib_global_init(){} // this is callen by startup.c
//
#endif

#endif

#ifdef mini_prints
#ifndef prints_c
#define prints_c
//#include "../include/write.h"
#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...);
extern int dprints(int fd, char *msg,...);
//+header mini_addons.h

//+doc print the string(s) supplied as arg(s) to stdout
//+depends _mprints 
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)

//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints 
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)


//+depends printl print strlen
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

#endif
#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif


#ifndef mini_prints
#define mini_prints
#endif

//TODO: Handle errors of write (ret == -1)

#if 0
int _prints(char *msg,...){
		int a;
		int ret = 0;

		do {
				a = 0;
				while (msg[a] != 0 ){
						a++;
				}
				ret += write(1,msg,a);
				//msg = 0;//va_arg(args,char*);
				//msg+=4;
				printf("\nmsg: %u\n",msg);
				printf("msg: %u\n",&msg);
				unsigned int i;
				i = &msg;
				printf("i: %u\n",i);
				i+=4;
				printf("i: %u\n",i);
				*msg = i;
				printf("\nmsg: %u\n",msg);
				printf("msg: %u\n",&msg);

				msg=0;
		} while ( msg != 0 );
		return(ret);
}

#else

//+needs write.h prints.h stdarg.h
//+depends write
int dprints(int fd, char *msg,...){
		va_list args;
		va_start(args,msg);
		int a;
		int ret = 0;

		do {
				a = 0;
				while (msg[a] != 0 ){
						a++;
				}
				ret += write(fd,msg,a);
				msg = va_arg(args,char*);
		} while ( msg != 0 );
		va_end(args);
		return(ret);
}

//+needs write.h prints.h stdarg.h
//+depends dprints
//+macro _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)


#endif

#endif
#endif

#ifdef mini_errno
int errno;
int sysret;
#endif



// minilib/src/strerror.c
#ifdef mini_perror
#ifndef strerror_r
#define strerror_r


char *errstr = "error: 00";

//+header string.h
//+def
char* strerror( int errnum ){
		errstr[7] = '0';
		while ( errnum>9 ){
				errnum-=10;
				errstr[7]++;
		}
		errstr[8] = 48+errnum; // 0+errnum..
		return( errstr );
}

//+header stdio.h
//+depends fputs
//+inline
static inline void perror(char *msg){
		if ( msg !=0 && msg[0] != '\0' )
				fputs( msg, stderr );

		fputs( strerror( errno ), stderr );
}


#endif

#endif

// minilib/src/memset.c
#ifdef mini_memset
//+ansi string.h
//+def
void *memset( void *s, int c, int n){
		int a;
		char *sp = s;
		for ( a=0; a<n; a++)
				sp[a] = (char)c;
		return(s);
}
#endif

// minilib/src/memfrob.c
#ifdef mini_memfrob
//+ansi string.h
//+def
void* memfrob(void* s, unsigned int len){
		unsigned int a;
		char *c = s;
		for ( a=0; a<len;a++)
				c[a] = 	c[a] ^ 42;
		return ( s );
}
		
#endif

// minilib/src/strerror.c
#ifdef mini_strerror
#ifndef strerror_r
#define strerror_r


char *errstr = "error: 00";

//+header string.h
//+def
char* strerror( int errnum ){
		errstr[7] = '0';
		while ( errnum>9 ){
				errnum-=10;
				errstr[7]++;
		}
		errstr[8] = 48+errnum; // 0+errnum..
		return( errstr );
}

//+header stdio.h
//+depends fputs
//+inline
static inline void perror(char *msg){
		if ( msg !=0 && msg[0] != '\0' )
				fputs( msg, stderr );

		fputs( strerror( errno ), stderr );
}


#endif

#endif

// minilib/src/itohex.c
#ifdef mini_itohex
#ifndef itohex_c
#define itohex_c
//+header stdio.h
//+def
int _itohex(int i,char* buf,int padding, int capitals){

		if ( capitals>0 )
				capitals = 55;
		else
				capitals = 87;

		padding = padding - 8;
		if ( padding < -7 )
				padding = -7;

		union { int n; char c[4]; } conv[2];
		conv[0].n = (( i & 0xf0f0f0f0 ) >> 4);
		conv[1].n = ( i & 0x0f0f0f0f );
		int p = 0;
		int a,b;

		for ( a=3; a>=0; a-- ){
				for ( b=0; b <=1; b++ ){
						if ( padding != 0 ){
								if ( conv[b].c[a] != 0 ){
										padding = 0;
								}
						}
						if ( padding == 0 ){
								char c = conv[b].c[a];
								if ( c < 0xa )
										c = c + 48;
								else
										c = c + capitals; // 55 for big abc ..
								buf[p] = c;
								p++;
						} else
								padding++;
				}
		}
		buf[p] = 0 ;
		return(p);
}

//+header stdio.h
//+depends _itohex
//+def
int itohex(int i,char* buf,int padding){
		return(_itohex(i,buf,padding,0));
}

//+header stdio.h
//+depends _itohex
//+def
int itoHEX(int i,char* buf,int padding){
		return(_itohex(i,buf,padding,1));
}




#endif

#endif

// minilib/src/basename.c
#ifdef mini_basename
/*-
 * Copyright (c) 2015-2016 Nuxi, https://nuxi.nl/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
// source freebsd 

//+depends strlen
//+def
char *basename(char *path){
	char *ptr;

	/*
	 * If path is a null pointer or points to an empty string,
	 * basename() shall return a pointer to the string ".".
	 */
	if (path == NULL || *path == '\0')
		return ( ".");

	/* Find end of last pathname component and null terminate it. */
	ptr = path + strlen(path);
	while (ptr > path + 1 && *(ptr - 1) == '/')
		--ptr;
	*ptr-- = '\0';

	/* Find beginning of last pathname component. */
	while (ptr > path && *(ptr - 1) != '/')
		--ptr;
	return (ptr);
}
#endif

// minilib/src/malloc.c
#ifdef mini_free
#ifndef mini_malloc_c
#define mini_malloc_c
//+header stdlib.h
//#include "../include/syscall.h"

#ifdef __NR_brk
#define BRK
#else
#ifdef SYS_brk
#define BRK
#endif
#endif

#ifndef minilib_global_h
#define minilib_global_h

// Don't like this pattern.
// Will most likely "bloat" minilib.
// But other options do not seem sensible.

//#ifndef mini_buf
//#warning defining mini_buf
//#define mini_buf 1024
//#endif

#ifdef mini_buf


typedef struct {
		int align;
		int srand;	
		int pstream;
		int mbufsize;
		int stream[mini_FOPEN_MAX];
		union {
				int ibuf[mini_buf>>2];
				char mbuf[mini_buf];
		};
} minilib_globals;

extern minilib_globals ml;
#else

//#warning no mini_buf

#endif

#ifdef mini_getenv
//+doc pointer to env, when mini_getenv is defined.
char **mini_env;
#endif


#endif

/// Debugging macros
#ifdef DEBUG
#define mini_fputc
#define mini_fprintf
static inline int fputc(int c, int fd);


#define dbgwarnf(...) {fprintf(stderr,__VA_ARGS__);fputc('\n',stderr);}
#define dbgwarn(s) {write(stderr,s,sizeof(s));fputc('\n',stderr);}
#define dbgwarnfif(a,...) {if ( a ){dbgwarnf(__VA_ARGS__)};}
#define dbgwarnif(a,s) {if ( a ){dbgwarn(s)};}
#define dbgerr(s) {dbgwarn(s);exit(1);}
#define dbgerrf(...) {dbgwarnf(__VA_ARGS__);exit(1);}
#define dbgerrif(a,s) {if(a){dbgwarn(s);exit(1);};}
#define dbgerrfif(a,...) {if(a){dbgwarnf(__VA_ARGS__);exit(1);};}

#define dbg(s) dbgwarn(s)
#define dbgf(...) dbgwarnf(__VA_ARGS__)

#else

#define dbg(s) {}
#define dbgf(...) {}


#define dbgwarnf(...) {}
#define dbgwarn(s) {} 
#define dbgwarnfif(a,...) {} 
#define dbgwarnif(a,s) {} 
#define dbgerr(s) {}
#define dbgerrf(...) {}
#define dbgerrif(a,s) {}
#define dbgerrfif(a,...) {}

#endif


// ansicolors
#define AC_BLACK "\033[0;30m"
#define AC_RED "\033[0;31m"
#define AC_GREEN "\033[32;0m"
#define AC_BROWN "\033[0;33m"
#define AC_BLUE "\033[0;34m"
#define AC_MAGENTA "\033[0;35m"
#define AC_MARINE "\033[0;36m"
#define AC_LGREY "\033[0;37m"
#define AC_WHITE "\033[0;38m"

#define AC_GREY "\033[1;30m" 
#define AC_LRED "\033[1;31m" 
#define AC_LGREEN "\033[1;32m" 
#define AC_YELLOW "\033[1;33m"
#define AC_LBLUE "\033[1;34m"
#define AC_LMAGENTA "\033[1;35m"
#define AC_LMARINE "\033[1;36m"
#define AC_LWHITE "\033[1;37m"







//#include "mbuf.c"

#define MBUF_FREE 0x80000000
#define MBUF_FREEMASK 0x8FFFFFFF
#define MBUF_OCC 0x40000000
// simple checksum whether a area is free or occupied.
// If neither nor, most possibly there's a problem.
#define MBUF_CHK 0xC0000000   

#define MBUF_PREVISFREE 0x20000000
#define MBUF_V 0x1FFFFFFF


// Here we go.. with the .. well. 
// Fastes and smallest malloc/free combi ever. 
// Not the smartest.
// Since it isn't exactly a memory allocation,
// instead it (mis)uses the minilib buf.
// muahaha. 1024 Bytes should be enough for everyone.
//  Ok. If you really do need more memory - 
//  rethink your design, increase mini_mbuf,
//  or use a proper malloc implementation.
//
// Here we misuse mbuf from top to bottom as stack.
// 64 Bytes are left at the bottom as reserve.
// Possibly we'd like to complain
// about the lack of memory, before we exit..
//
// ATM, the 'free' is really lazy. 
// It free's memory, but a real 'free' is only commited,
// when all memory below a freed area is also freed.
// Since the target of minilib atm are tiny tools, 
// this might be ok.
// ;) but, as I told before - 
// probably you should look out for a proper malloc implementation.
//
// I'm not sure yet, 
// whether a better implementation of free would be useful at all.
// Overall, I'd really prefer keeping minilib tiny.
//
// Reusing also sparse freed memory areas leads 
// to a whole bunch of complications.
// cache misses, searching complexity,
// storage overhead,
// just to name a few.
//
// I'm not sure whether it's worth it.
//
// And the existing malloc implementations 
// out there are countless.
//
// ;) It's sometimes smarter to stay special,
// although in this case this means the opposite.
//   ? I'm not sure what this sentence means XD
//misc
//
//+def
void* malloc(int size){
		size = ((size-1) >> 2 ) + 2; // alignment and reserving space for the "pointer"
		if( ml.mbufsize-(size<<2)<64 ){
				write( STDERR_FILENO, "Out of memory.\n",15 );
				return((void*)0);
		}

		ml.ibuf[(ml.mbufsize>>2)] = ml.ibuf[(ml.mbufsize>>2)] & MBUF_V; // clear flag prev_isfree
		ml.mbufsize -= (size<<2);
		ml.ibuf[(ml.mbufsize>>2)] = size;
		return( &ml.mbuf[ml.mbufsize+4] );
}

#if 0
///+def
void free(void *p){
}

#else

//+def
void free(void *p){
		char *c = p;
		int *i = p;
		i--;
		c-=4;
		
		if ( &ml.mbuf[ml.mbufsize] == (char*)c ){ // at the bottom of the stack
				ml.mbufsize += (i[0] & MBUF_V) <<2;
				if ( ml.mbufsize == mini_buf )
						return;
				if ( ml.ibuf[ml.mbufsize>>2] & MBUF_FREE )
						ml.mbufsize += ( ( ml.ibuf[ml.mbufsize>>2] & MBUF_V ) << 2 );
				return;
				/*do {
						ml.mbufsize += mbuf[ml.mbufsize] +4;
						} while ( (ml.mbufsize < mini_buf ) && ( mbuf[ml.mbufsize] & MBUF_FREE ) );*/ // next area also free'd
		} else { // Not at the bottom
				if ( ( i[0] & MBUF_PREVISFREE )){ // prev area is free
						i[ - i[-1] -1 ] = ( ( i[ - i[-1] -1 ] + i[0] ) & MBUF_V ) | MBUF_FREE; // add this to prev.
						i = i - ( i[-1] + 1 );
				}
				// prev not free
				if ( (i[( i[0] & MBUF_V)] & MBUF_FREE) ){ // next area free
						i[0] = ((i[0] + i[( i[0] & MBUF_V)]) & MBUF_V) | MBUF_FREE; // add next to current. 
						// MBUF_FREE is already set. But for safety set it again. via mask 
						// adding MBUF_FREE twice wouldn't be that great
						i[( i[0] & MBUF_V) - 1 ] = ( i[0] & MBUF_V) - 1;
						return;
				} // prev area not free, next area not free
				i[( i[0] & MBUF_V) - 1 ] = ( i[0] & MBUF_V) - 1;
				i[( i[0] & MBUF_V)] = ( i[( i[0] & MBUF_V)] | MBUF_PREVISFREE ); 
				i[0] = i[0] | MBUF_FREE;
				return;

		} 

							 /*	(int)c[ -(int)c[-4] ] = (int)c[ -(int)c[-4] ] + ( (int)c[0] & MBUF_V ) + ( (int)c[ ((int)c[0] & MBUF_V) ] & MBUF_V ); // add this and next area to prev area.
								(int)c[(int)c[ ((int)c[0] & MBUF_V)]-4] = (int)c[ -(int)c[-4] ] -4; // write combined free areas
								else { // next not free
										(int)c[ -(int)c[-4] ] += ( (int)c[0] & MBUF_V ); // add this area to prev area.
										(int)c[(int)c[0] & MBUF_V ] = (int)c[(int)c[0]&MBUF_V] | MBUF_PREVISFREE // mark next area 
												(int)c[(int)c[0]-4] = (int)c[ -(int)c[-4] ]-4; //write len of combined free areas there 
								}
						} else { //prev not free
								if ( (int)c[ (int)c[0] & MBUF_V ] & MBUF_FREE ){ // next free
										//mbuf[ (int)c[0]
								}
						}

				}*/
		
}

#endif


#if 0

POINTER* ml_brk=0;
extern POINTER _bssend;

//+def
void* volatile malloc(int size){
#ifdef undef
#warning BRK def
		int ret=1;
		mfprintf(stderr,"MALLOC: _bssend: %d\n",_bssend);
		if ( ml_brk == 0 ){
				ml_brk = _bssend;
				syscall1(ret,SCALL(brk),&ml_brk+size);
				if ( ret!=0 ){
						mfprintf(stderr,"MALLOC: 0\n");
						return(0);
				}
				ml_brk+=size;
				return((void*)_bssend);
		} else {
				syscall1(ret,SCALL(brk),size+ml_brk);
				if ( ret!=0 ){
						mfprintf(stderr,"MALLOC: 0\n");
						return(0);
				}
				int old_brk= ml_brk;
				ml_brk += size;
				return((void*)old_brk);
		}
#else 
#warning malloc SYSCALL
/*		void* ret;
		syscall6(ret, SCALL(mmap), 0, size, (0x01|0x02), 0x1002, -1, 0);
		//syscall6(ret, SCALL(mmap), 0, size, PROT_READ|PROT_WRITE, 0x1002, -1, 0);
		return((void*)ret);*/
#endif

		void* ret;
		size=4096;
	  register volatile long int r8 asm ("r8") = -1 ; 
		register volatile long int r9 asm ("r9") = 0; 
		register volatile long int r10 asm ("r10") = 0x1002; 
			asm volatile (
							//"xor %%r9, %%r9;"
							//"mov $-1, %%r8;"
							//"mov $0x1002, %%r10;"
							"syscall" 
							   : "=a" (ret) 
								 : "a" (SCALL(mmap) ) , "D" (0), "S" (size), "d" (0x01|0x02), "r" (r10), "r" (r8), "r" (r9) 
							   : "rcx", "memory" );
			return( (void*)ret );

}

//+def
void volatile free(void* p){

}




//malloc old
		//size = 4096;
/*	  register long int r8 asm ("r8") = -1 ; 
		register long int r9 asm ("r9") = 0; 
		register volatile long int r10 asm ("r10") = 0x1002; 
			asm volatile (
							//"xor %%r9, %%r9;"
							//"mov $-1, %%r8;"
							//"mov $0x1002, %%r10;"
							"syscall" 
							   : "=a" (ret) 
								 : "a" ( ( 197  | 0x2000000 ) ) , "D" (0), "S" (size), "d" (0x01|0x02), "r" (r10), "r" (r8), "r" (r9) 
							   : "ecx", "memory" );
	*/					
 /*
		asm volatile(
						"mov %p6, %%r9\n\t"
						"mov %p5, %%r8\n\t"
						"mov %p4, %%r10\n\t"
						"mov %p3, %%rdx\n\t"
						"mov %p2, %%rsi\n\t"
						"mov %p1, %%rdi\n\t"
						"mov $0x20000000, %%rax\n\t"
						"syscall\n\t"
						:"=a"(ret)
						:[p1]"m"(0),[p2]"m"(1024),[p3]"m"(0x01),[p4]"m"(0x0002),[p5]"m"(-1),[p6]"m"(0));*/
#endif



#endif
#endif

// minilib/src/itohex.c
#ifdef mini_itoHEX
#ifndef itohex_c
#define itohex_c
//+header stdio.h
//+def
int _itohex(int i,char* buf,int padding, int capitals){

		if ( capitals>0 )
				capitals = 55;
		else
				capitals = 87;

		padding = padding - 8;
		if ( padding < -7 )
				padding = -7;

		union { int n; char c[4]; } conv[2];
		conv[0].n = (( i & 0xf0f0f0f0 ) >> 4);
		conv[1].n = ( i & 0x0f0f0f0f );
		int p = 0;
		int a,b;

		for ( a=3; a>=0; a-- ){
				for ( b=0; b <=1; b++ ){
						if ( padding != 0 ){
								if ( conv[b].c[a] != 0 ){
										padding = 0;
								}
						}
						if ( padding == 0 ){
								char c = conv[b].c[a];
								if ( c < 0xa )
										c = c + 48;
								else
										c = c + capitals; // 55 for big abc ..
								buf[p] = c;
								p++;
						} else
								padding++;
				}
		}
		buf[p] = 0 ;
		return(p);
}

//+header stdio.h
//+depends _itohex
//+def
int itohex(int i,char* buf,int padding){
		return(_itohex(i,buf,padding,0));
}

//+header stdio.h
//+depends _itohex
//+def
int itoHEX(int i,char* buf,int padding){
		return(_itohex(i,buf,padding,1));
}




#endif

#endif

// minilib/src/open.c
#ifdef mini_creat
#ifndef open_c
#define open_c
//+header fcntl.h


//#include "syscall.h"
#ifndef mini_filemodes_h
#define mini_filemodes_h

#ifdef OSX

/* open-only flags */
#define	O_RDONLY	0x0000		/* open for reading only */
#define	O_WRONLY	0x0001		/* open for writing only */
#define	O_RDWR		0x0002		/* open for reading and writing */
#define	O_ACCMODE	0x0003		/* mask for above modes */

#define	FREAD		0x0001
#define	FWRITE		0x0002
#define	O_NONBLOCK	0x0004		/* no delay */
#define	O_APPEND	0x0008		/* set append mode */

#define	O_SHLOCK	0x0010		/* open with shared file lock */
#define	O_EXLOCK	0x0020		/* open with exclusive file lock */
#define	O_ASYNC		0x0040		/* signal pgrp when data ready */
#define	O_FSYNC		O_SYNC		/* source compatibility: do not use */
#define O_NOFOLLOW  0x0100      /* don't follow symlinks */
#define	O_CREAT		0x0200		/* create if nonexistant */
#define	O_TRUNC		0x0400		/* truncate to zero length */
#define	O_EXCL		0x0800		/* error if already exists */

#define	O_EVTONLY	0x8000		/* descriptor requested for event notifications only */

#define	O_NOCTTY	0x20000		/* don't assign controlling terminal */
#define O_DIRECTORY	0x100000
#define O_SYMLINK	0x200000	/* allow open of a symlink */
#define	O_CLOEXEC	0x1000000	/* implicitly set FD_CLOEXEC */
#define O_DP_GETRAWENCRYPTED	0x0001
#define O_DP_GETRAWUNENCRYPTED	0x0002



#else


#define O_ACCMODE	00000003
#define O_RDONLY	00000000
#define O_WRONLY	00000001
#define O_RDWR		00000002
#define O_CREAT		00000100	/* not fcntl */
#define O_EXCL		00000200	/* not fcntl */
#define O_NOCTTY	00000400	/* not fcntl */
#define O_TRUNC		00001000	/* not fcntl */
#define O_APPEND	00002000
#define O_NONBLOCK	00004000
#define O_DSYNC		00010000	/* used to be O_SYNC, see below */
#define FASYNC		00020000	/* fcntl, for BSD compatibility */
#define O_DIRECT	00040000	/* direct disk access hint */
#define O_LARGEFILE	00100000
#define O_DIRECTORY	00200000	/* must be a directory */
#define O_NOFOLLOW	00400000	/* don't follow links */
#define O_NOATIME	01000000
#define O_CLOEXEC	02000000	/* set close_on_exec */

#endif



#endif


#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif


//+def
int volatile open( const char *s, int flags, ... ){
		int ret;
		va_list args;
		va_start(args,flags);
		int mode = va_arg(args,int);
		va_end(args);

		syscall3(ret,SCALL(open),(POINTER)s,flags,mode);
		return(ret);
}

/// creat
//d open
//+def
inline int volatile __attribute__((always_inline)) creat( const char *s, int mode ){
		return(open( s, O_CREAT|O_WRONLY|O_TRUNC, mode) );
}



//FILE* volatile fopen( const char *s, const char *mode ){
//		int m = 0;




#endif
#endif

// minilib/src/itodec.c
#ifdef mini_itodec
#ifndef mini_itodec_c
#define mini_itodec_c
//+ansi stdio.h
//
// convert int to string.
// prec: precision, e.g. 4=> 0087 
//+def
int uitodec(unsigned int i, char *buf, int prec, char limiter ){
		int p = 0;
		int a;
		int t1,t2,t3,dec;
		//unsigned int ut1,ut2,ut3;
		char n;
		prec = prec - 10; // Maximale Stellenanzahl 


		if ( i==0 ){
				buf[0] = '0';
				//p++;
				//return(
		}

		int trailing = 1;

	const int div[13] = {0, 100000000, 10000000, 1000000, 0, 100000, 10000, 1000, 0, 100, 10, 1};
	
	if ( i >= 1000000000){
			//prints("hier.\n");
			p=1;
			prec=0;
			if ( i>=2000000000 ){
					i-=2000000000;
				if ( i>=1000000000 ){
						if ( i>=2000000000 ){
								buf[0] = '4';
								i-=2000000000;
						} else {
								buf[0] = '3';
								i-=1000000000;
						}
					} else {
						buf[0] = '2';
						//i-=2000000000;
					}
			}	else {
					buf[0] = '1'; 
					i-=1000000000;
			}
	trailing = 0;
	} else {
			if ( prec == 0 ){
					buf[0] = ' ';
					p++;
			} else
					prec++;
	}

	

					
			

	for (a=0;a<12;a++){
			if ( div[a] == 0 ){
					if ( (limiter != 0 ) && (prec==0) ){
							buf[p] = limiter;
							p++;
					}
			} else {
			n = '0';

			if ( (t1=(i - div[a])) >= 0 ){
					prec = 0;
					trailing = 0;
					n = '1';
					if ( (t2=(t1-(dec=(div[a]<<2)))) >= 0){
							if ( (t3=t2-dec) >= 0 ){
									n = '9';
									i = t3;
									goto write;
							} else {
									n = '5';
									t1 = t2;
							}
					} 
					if ( (t2=(t1-(div[a]<<1) ) ) >=0 ){
							t1=t2;
							n += 2;
					}
					if ( (t2=(t1-(div[a]) ) ) >=0 ){
							t1=t2;
							n += 1;
					}
					i = t1;
			}

			if ( prec == 0 ){
			write:
					if ( trailing )
							buf[p] = ' ';
					else
							buf[p] = n;
					p++;
			} else
					prec++;
					//buf[p] = 'x';
					//p++;

			}
	}
	if ( p==0 )
			p=1;
	buf[p] = 0;

	return(p);
}

	
//+depends uitodec
//+def
int itodec(int i, char *buf, int prec, char limiter ){
	if ( i < 0 ){
			buf[0]='-';
			i = -i;
			return(uitodec((unsigned int)i,&buf[1],prec,limiter) + 1 );
	}
	return(uitodec((unsigned int)i,buf,prec,limiter) );
}


#endif
#endif

// minilib/src/sprintf.c
#ifdef mini_sprintf
#ifndef msprintf_c
#define msprintf_c

#ifndef mini_write
#define mini_write
#endif


#ifndef mini_prints
#define mini_prints
#endif

// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
#ifndef mini_prints
#define mini_prints
#endif
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...);
extern int dprints(int fd, char *msg,...);
//+header mini_addons.h

//+doc print the string(s) supplied as arg(s) to stdout
//+depends _mprints 
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)

//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints 
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)


//+depends printl print strlen
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

#endif
#define MINI_TEST_OVERRUN(pos) if (pos > ml.mbufsize){\
		printsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif

//#include "../include/write.h"
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif



#undef MINI_TEST_OVERRUN
#define MINI_TEST_OVERRUN(pos) if ( pos>= size ){ overflow=1; goto msprintfout;}



//+depends snprintf
//+macro
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

// I'm really uncertain about the size arg here, amongst others


//+ansi stdio.h
//+depends write
//+needs exit.h stdarg.h overrun.h
//+after itohex itoHEX
//+def
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args ){

		//va_list args;
		//va_start(args,fmt);
		int a = 0;
		int b = 0;
		int overflow = 0;
		int end, padding, c,groups=0;
		char sep;
		char tmp[16];
		char *s;

#if 1
		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}
								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
#if 1
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
#endif
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;
										case 'l':
#ifdef mini_ltodec
												MINI_TEST_OVERRUN(b+27);
												b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itoHEX(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;

										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
msprintfout:
		buf[b] = 0;
		va_end(args);

		//write( 2, buf, 20 );
		//return(write(fd,buf,b));
		if ( overflow )
				return(-b);
		else
				return(b);
#endif
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int dprintf( int fd, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(ml.mbuf, ml.mbufsize, fmt, args);
		if ( r<0 ){
				write(2,"Buffer Overrun.\n",16);
				exit(1);
		}
		write( fd, ml.mbuf, r );
		va_end(args);
		return(r);
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int snprintf( char *buf, size_t size, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(buf, size, fmt, args);
		va_end(args);
		return(r);
}



/// fprintf
/// conversions implemented:
/// %d  
/// %u
/// %f (max precision 8 digits, highest possible number: 2^31
/// %s
/// %c
/// %b : binary output
/// %x/X : hex output
/// %(
/// 
//+header stdio.h
//+depends write prints dprintf sprintf fileno
//+needs mini_fstream.h 
//+after itobin atoi itodec dtodec ltodec itohex
//+macro fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))



#if 0		
		va_list args;
		va_start(args,fmt);
		int a = 0;
		int b = 0;
		int end, padding, c,groups;
		char sep;
		char tmp[16];
		char *s;

		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}

								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&ml.mbuf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
		buf[b] = 0;
		va_end(args);
		//return(write(1,buf,b));
		return(b);
}
#endif
#endif
#endif

// minilib/src/strlen.c
#ifdef mini_strlen
#ifndef strlen_c
#define strlen_c

//+header string.h

//+def
int strlen(const char*str){
		int a = 0;
		while ( str[a] != 0 ){
				a++;
		}
		return (a);
}


#endif
#endif

// minilib/src/memcpy.c
#ifdef mini_strncpy
#ifndef memcpy_c
#define memcpy_c

//+ansi string.h
//+def
void *memcpy( void *d, const void *s, int n ){
		char *dp=d;
		const char *sp = s;
		int a;
		for ( a=0; a<n; a++ )
				dp[a] = sp[a];
		return(d);
}


//+def
char *strcpy(char *dest, const char *src){
		int a;
		for ( a=0; src[a] != 0; a++)
				dest[a] = src[a];
		dest[a] = 0;
		return(dest);
}

//+depends memcpy
//+def
char *strncpy(char *dest, const char *src, int n){
		return( memcpy( dest, src, n ) );
}

#endif

#endif

// minilib/src/sprintf.c
#ifdef mini_dprintf
#ifndef msprintf_c
#define msprintf_c

#ifndef mini_write
#define mini_write
#endif


#ifndef mini_prints
#define mini_prints
#endif

// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
#ifndef mini_prints
#define mini_prints
#endif
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...);
extern int dprints(int fd, char *msg,...);
//+header mini_addons.h

//+doc print the string(s) supplied as arg(s) to stdout
//+depends _mprints 
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)

//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints 
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)


//+depends printl print strlen
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

#endif
#define MINI_TEST_OVERRUN(pos) if (pos > ml.mbufsize){\
		printsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif

//#include "../include/write.h"
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif



#undef MINI_TEST_OVERRUN
#define MINI_TEST_OVERRUN(pos) if ( pos>= size ){ overflow=1; goto msprintfout;}



//+depends snprintf
//+macro
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

// I'm really uncertain about the size arg here, amongst others


//+ansi stdio.h
//+depends write
//+needs exit.h stdarg.h overrun.h
//+after itohex itoHEX
//+def
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args ){

		//va_list args;
		//va_start(args,fmt);
		int a = 0;
		int b = 0;
		int overflow = 0;
		int end, padding, c,groups=0;
		char sep;
		char tmp[16];
		char *s;

#if 1
		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}
								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
#if 1
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
#endif
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;
										case 'l':
#ifdef mini_ltodec
												MINI_TEST_OVERRUN(b+27);
												b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itoHEX(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;

										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
msprintfout:
		buf[b] = 0;
		va_end(args);

		//write( 2, buf, 20 );
		//return(write(fd,buf,b));
		if ( overflow )
				return(-b);
		else
				return(b);
#endif
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int dprintf( int fd, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(ml.mbuf, ml.mbufsize, fmt, args);
		if ( r<0 ){
				write(2,"Buffer Overrun.\n",16);
				exit(1);
		}
		write( fd, ml.mbuf, r );
		va_end(args);
		return(r);
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int snprintf( char *buf, size_t size, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(buf, size, fmt, args);
		va_end(args);
		return(r);
}



/// fprintf
/// conversions implemented:
/// %d  
/// %u
/// %f (max precision 8 digits, highest possible number: 2^31
/// %s
/// %c
/// %b : binary output
/// %x/X : hex output
/// %(
/// 
//+header stdio.h
//+depends write prints dprintf sprintf fileno
//+needs mini_fstream.h 
//+after itobin atoi itodec dtodec ltodec itohex
//+macro fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))



#if 0		
		va_list args;
		va_start(args,fmt);
		int a = 0;
		int b = 0;
		int end, padding, c,groups;
		char sep;
		char tmp[16];
		char *s;

		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}

								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&ml.mbuf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
		buf[b] = 0;
		va_end(args);
		//return(write(1,buf,b));
		return(b);
}
#endif
#endif
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strcmp
#ifndef strcmp_c
#define strcmp_c

//+ansi string.h

//TODO: not implemented correct. need to return also -1.

int _strcmp(const char*c1,const char*c2,int len){
		int a = 0;
		while ( (c1[a] != 0) && (c2[a]!=0 ) && a != len ){
				//write(1,&c1[a],1);
				if ( c1[a] != c2[a] )
						return(1);
				a++;
		}
		if ( (c1[a] == 0 ) && ( c2[a] == 0 ) )
				return(0);
		return (1);
}



//+def
int strcmp(const char*c1,const char*c2){
		return( _strcmp(c1,c2,-1) );
}

//+def
int strncmp(const char*c1,const char*c2,int len){
		if ( len <=0 )
				return(-1);
		return(_strcmp(c1,c2,len) );
}

//+def
int memcmp(const void* c1,const void* c2,int len){
		const char* cc1 = c1;
		const char* cc2 = c2;
		if ( len <=0 )
				return(-1);
		int a = 0;
		while ( a != len ){
				//write(1,&c1[a],1);
				if ( cc1[a] != cc2[a] )
						return(1);
				a++;
		}
	 return(0);
}


#endif
#endif

// minilib/src/memcpy.c
#ifdef mini_memcpy
#ifndef memcpy_c
#define memcpy_c

//+ansi string.h
//+def
void *memcpy( void *d, const void *s, int n ){
		char *dp=d;
		const char *sp = s;
		int a;
		for ( a=0; a<n; a++ )
				dp[a] = sp[a];
		return(d);
}


//+def
char *strcpy(char *dest, const char *src){
		int a;
		for ( a=0; src[a] != 0; a++)
				dest[a] = src[a];
		dest[a] = 0;
		return(dest);
}

//+depends memcpy
//+def
char *strncpy(char *dest, const char *src, int n){
		return( memcpy( dest, src, n ) );
}

#endif

#endif

// minilib/src/isspace.c
#ifdef mini_isspace
#ifndef isspace_c
#define isspace_c

//+ansi ctype.h
//+def
int isspace(int c){
		switch (c){
				case ' ':
				case '\f':
				case '\n':
				case '\r':
				case '\t':
				case '\v':
						return(1);
		}
		return(0);
}




#endif

#endif

// minilib/src/itodec.c
#ifdef mini_uitodec
#ifndef mini_itodec_c
#define mini_itodec_c
//+ansi stdio.h
//
// convert int to string.
// prec: precision, e.g. 4=> 0087 
//+def
int uitodec(unsigned int i, char *buf, int prec, char limiter ){
		int p = 0;
		int a;
		int t1,t2,t3,dec;
		//unsigned int ut1,ut2,ut3;
		char n;
		prec = prec - 10; // Maximale Stellenanzahl 


		if ( i==0 ){
				buf[0] = '0';
				//p++;
				//return(
		}

		int trailing = 1;

	const int div[13] = {0, 100000000, 10000000, 1000000, 0, 100000, 10000, 1000, 0, 100, 10, 1};
	
	if ( i >= 1000000000){
			//prints("hier.\n");
			p=1;
			prec=0;
			if ( i>=2000000000 ){
					i-=2000000000;
				if ( i>=1000000000 ){
						if ( i>=2000000000 ){
								buf[0] = '4';
								i-=2000000000;
						} else {
								buf[0] = '3';
								i-=1000000000;
						}
					} else {
						buf[0] = '2';
						//i-=2000000000;
					}
			}	else {
					buf[0] = '1'; 
					i-=1000000000;
			}
	trailing = 0;
	} else {
			if ( prec == 0 ){
					buf[0] = ' ';
					p++;
			} else
					prec++;
	}

	

					
			

	for (a=0;a<12;a++){
			if ( div[a] == 0 ){
					if ( (limiter != 0 ) && (prec==0) ){
							buf[p] = limiter;
							p++;
					}
			} else {
			n = '0';

			if ( (t1=(i - div[a])) >= 0 ){
					prec = 0;
					trailing = 0;
					n = '1';
					if ( (t2=(t1-(dec=(div[a]<<2)))) >= 0){
							if ( (t3=t2-dec) >= 0 ){
									n = '9';
									i = t3;
									goto write;
							} else {
									n = '5';
									t1 = t2;
							}
					} 
					if ( (t2=(t1-(div[a]<<1) ) ) >=0 ){
							t1=t2;
							n += 2;
					}
					if ( (t2=(t1-(div[a]) ) ) >=0 ){
							t1=t2;
							n += 1;
					}
					i = t1;
			}

			if ( prec == 0 ){
			write:
					if ( trailing )
							buf[p] = ' ';
					else
							buf[p] = n;
					p++;
			} else
					prec++;
					//buf[p] = 'x';
					//p++;

			}
	}
	if ( p==0 )
			p=1;
	buf[p] = 0;

	return(p);
}

	
//+depends uitodec
//+def
int itodec(int i, char *buf, int prec, char limiter ){
	if ( i < 0 ){
			buf[0]='-';
			i = -i;
			return(uitodec((unsigned int)i,&buf[1],prec,limiter) + 1 );
	}
	return(uitodec((unsigned int)i,buf,prec,limiter) );
}


#endif
#endif

// minilib/src/getenv.c
#ifdef mini_getenv
#ifndef getenv_c
#define getenv_c

#ifndef dumbsyntaxchecker
char **mini_env;
#endif


//+header stdlib.h
//+def
char *getenv(const char* name){
		int b;
		for ( int a=0; mini_env[a]; a++ ){
				for ( b = 0; mini_env[a][b] == name[b]; b++ ){}
				if ( mini_env[a][b] == '=' ){
						return( &mini_env[a][b+1] );
				}
		}
		return(0);
}



#endif
#endif

// minilib/src/sprintf.c
#ifdef mini_vsnprintf
#ifndef msprintf_c
#define msprintf_c

#ifndef mini_write
#define mini_write
#endif


#ifndef mini_prints
#define mini_prints
#endif

// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
#ifndef mini_prints
#define mini_prints
#endif
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...);
extern int dprints(int fd, char *msg,...);
//+header mini_addons.h

//+doc print the string(s) supplied as arg(s) to stdout
//+depends _mprints 
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)

//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints 
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)


//+depends printl print strlen
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

#endif
#define MINI_TEST_OVERRUN(pos) if (pos > ml.mbufsize){\
		printsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif

//#include "../include/write.h"
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif



#undef MINI_TEST_OVERRUN
#define MINI_TEST_OVERRUN(pos) if ( pos>= size ){ overflow=1; goto msprintfout;}



//+depends snprintf
//+macro
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

// I'm really uncertain about the size arg here, amongst others


//+ansi stdio.h
//+depends write
//+needs exit.h stdarg.h overrun.h
//+after itohex itoHEX
//+def
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args ){

		//va_list args;
		//va_start(args,fmt);
		int a = 0;
		int b = 0;
		int overflow = 0;
		int end, padding, c,groups=0;
		char sep;
		char tmp[16];
		char *s;

#if 1
		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}
								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
#if 1
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
#endif
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;
										case 'l':
#ifdef mini_ltodec
												MINI_TEST_OVERRUN(b+27);
												b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itoHEX(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;

										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
msprintfout:
		buf[b] = 0;
		va_end(args);

		//write( 2, buf, 20 );
		//return(write(fd,buf,b));
		if ( overflow )
				return(-b);
		else
				return(b);
#endif
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int dprintf( int fd, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(ml.mbuf, ml.mbufsize, fmt, args);
		if ( r<0 ){
				write(2,"Buffer Overrun.\n",16);
				exit(1);
		}
		write( fd, ml.mbuf, r );
		va_end(args);
		return(r);
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int snprintf( char *buf, size_t size, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(buf, size, fmt, args);
		va_end(args);
		return(r);
}



/// fprintf
/// conversions implemented:
/// %d  
/// %u
/// %f (max precision 8 digits, highest possible number: 2^31
/// %s
/// %c
/// %b : binary output
/// %x/X : hex output
/// %(
/// 
//+header stdio.h
//+depends write prints dprintf sprintf fileno
//+needs mini_fstream.h 
//+after itobin atoi itodec dtodec ltodec itohex
//+macro fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))



#if 0		
		va_list args;
		va_start(args,fmt);
		int a = 0;
		int b = 0;
		int end, padding, c,groups;
		char sep;
		char tmp[16];
		char *s;

		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}

								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&ml.mbuf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
		buf[b] = 0;
		va_end(args);
		//return(write(1,buf,b));
		return(b);
}
#endif
#endif
#endif

// minilib/src/prints.c
#ifdef mini__mprints
#ifndef prints_c
#define prints_c
//#include "../include/write.h"
#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...);
extern int dprints(int fd, char *msg,...);
//+header mini_addons.h

//+doc print the string(s) supplied as arg(s) to stdout
//+depends _mprints 
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)

//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints 
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)


//+depends printl print strlen
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

#endif
#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif


#ifndef mini_prints
#define mini_prints
#endif

//TODO: Handle errors of write (ret == -1)

#if 0
int _prints(char *msg,...){
		int a;
		int ret = 0;

		do {
				a = 0;
				while (msg[a] != 0 ){
						a++;
				}
				ret += write(1,msg,a);
				//msg = 0;//va_arg(args,char*);
				//msg+=4;
				printf("\nmsg: %u\n",msg);
				printf("msg: %u\n",&msg);
				unsigned int i;
				i = &msg;
				printf("i: %u\n",i);
				i+=4;
				printf("i: %u\n",i);
				*msg = i;
				printf("\nmsg: %u\n",msg);
				printf("msg: %u\n",&msg);

				msg=0;
		} while ( msg != 0 );
		return(ret);
}

#else

//+needs write.h prints.h stdarg.h
//+depends write
int dprints(int fd, char *msg,...){
		va_list args;
		va_start(args,msg);
		int a;
		int ret = 0;

		do {
				a = 0;
				while (msg[a] != 0 ){
						a++;
				}
				ret += write(fd,msg,a);
				msg = va_arg(args,char*);
		} while ( msg != 0 );
		va_end(args);
		return(ret);
}

//+needs write.h prints.h stdarg.h
//+depends dprints
//+macro _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)


#endif

#endif
#endif

// minilib/src/mstrcmp.c
#ifdef mini_memcmp
#ifndef strcmp_c
#define strcmp_c

//+ansi string.h

//TODO: not implemented correct. need to return also -1.

int _strcmp(const char*c1,const char*c2,int len){
		int a = 0;
		while ( (c1[a] != 0) && (c2[a]!=0 ) && a != len ){
				//write(1,&c1[a],1);
				if ( c1[a] != c2[a] )
						return(1);
				a++;
		}
		if ( (c1[a] == 0 ) && ( c2[a] == 0 ) )
				return(0);
		return (1);
}



//+def
int strcmp(const char*c1,const char*c2){
		return( _strcmp(c1,c2,-1) );
}

//+def
int strncmp(const char*c1,const char*c2,int len){
		if ( len <=0 )
				return(-1);
		return(_strcmp(c1,c2,len) );
}

//+def
int memcmp(const void* c1,const void* c2,int len){
		const char* cc1 = c1;
		const char* cc2 = c2;
		if ( len <=0 )
				return(-1);
		int a = 0;
		while ( a != len ){
				//write(1,&c1[a],1);
				if ( cc1[a] != cc2[a] )
						return(1);
				a++;
		}
	 return(0);
}


#endif
#endif

// minilib/src/malloc.c
#ifdef mini_malloc
#ifndef mini_malloc_c
#define mini_malloc_c
//+header stdlib.h
//#include "../include/syscall.h"

#ifdef __NR_brk
#define BRK
#else
#ifdef SYS_brk
#define BRK
#endif
#endif

#ifndef minilib_global_h
#define minilib_global_h

// Don't like this pattern.
// Will most likely "bloat" minilib.
// But other options do not seem sensible.

//#ifndef mini_buf
//#warning defining mini_buf
//#define mini_buf 1024
//#endif

#ifdef mini_buf


typedef struct {
		int align;
		int srand;	
		int pstream;
		int mbufsize;
		int stream[mini_FOPEN_MAX];
		union {
				int ibuf[mini_buf>>2];
				char mbuf[mini_buf];
		};
} minilib_globals;

extern minilib_globals ml;
#else

//#warning no mini_buf

#endif

#ifdef mini_getenv
//+doc pointer to env, when mini_getenv is defined.
char **mini_env;
#endif


#endif

/// Debugging macros
#ifdef DEBUG
#define mini_fputc
#define mini_fprintf
static inline int fputc(int c, int fd);


#define dbgwarnf(...) {fprintf(stderr,__VA_ARGS__);fputc('\n',stderr);}
#define dbgwarn(s) {write(stderr,s,sizeof(s));fputc('\n',stderr);}
#define dbgwarnfif(a,...) {if ( a ){dbgwarnf(__VA_ARGS__)};}
#define dbgwarnif(a,s) {if ( a ){dbgwarn(s)};}
#define dbgerr(s) {dbgwarn(s);exit(1);}
#define dbgerrf(...) {dbgwarnf(__VA_ARGS__);exit(1);}
#define dbgerrif(a,s) {if(a){dbgwarn(s);exit(1);};}
#define dbgerrfif(a,...) {if(a){dbgwarnf(__VA_ARGS__);exit(1);};}

#define dbg(s) dbgwarn(s)
#define dbgf(...) dbgwarnf(__VA_ARGS__)

#else

#define dbg(s) {}
#define dbgf(...) {}


#define dbgwarnf(...) {}
#define dbgwarn(s) {} 
#define dbgwarnfif(a,...) {} 
#define dbgwarnif(a,s) {} 
#define dbgerr(s) {}
#define dbgerrf(...) {}
#define dbgerrif(a,s) {}
#define dbgerrfif(a,...) {}

#endif


// ansicolors
#define AC_BLACK "\033[0;30m"
#define AC_RED "\033[0;31m"
#define AC_GREEN "\033[32;0m"
#define AC_BROWN "\033[0;33m"
#define AC_BLUE "\033[0;34m"
#define AC_MAGENTA "\033[0;35m"
#define AC_MARINE "\033[0;36m"
#define AC_LGREY "\033[0;37m"
#define AC_WHITE "\033[0;38m"

#define AC_GREY "\033[1;30m" 
#define AC_LRED "\033[1;31m" 
#define AC_LGREEN "\033[1;32m" 
#define AC_YELLOW "\033[1;33m"
#define AC_LBLUE "\033[1;34m"
#define AC_LMAGENTA "\033[1;35m"
#define AC_LMARINE "\033[1;36m"
#define AC_LWHITE "\033[1;37m"







//#include "mbuf.c"

#define MBUF_FREE 0x80000000
#define MBUF_FREEMASK 0x8FFFFFFF
#define MBUF_OCC 0x40000000
// simple checksum whether a area is free or occupied.
// If neither nor, most possibly there's a problem.
#define MBUF_CHK 0xC0000000   

#define MBUF_PREVISFREE 0x20000000
#define MBUF_V 0x1FFFFFFF


// Here we go.. with the .. well. 
// Fastes and smallest malloc/free combi ever. 
// Not the smartest.
// Since it isn't exactly a memory allocation,
// instead it (mis)uses the minilib buf.
// muahaha. 1024 Bytes should be enough for everyone.
//  Ok. If you really do need more memory - 
//  rethink your design, increase mini_mbuf,
//  or use a proper malloc implementation.
//
// Here we misuse mbuf from top to bottom as stack.
// 64 Bytes are left at the bottom as reserve.
// Possibly we'd like to complain
// about the lack of memory, before we exit..
//
// ATM, the 'free' is really lazy. 
// It free's memory, but a real 'free' is only commited,
// when all memory below a freed area is also freed.
// Since the target of minilib atm are tiny tools, 
// this might be ok.
// ;) but, as I told before - 
// probably you should look out for a proper malloc implementation.
//
// I'm not sure yet, 
// whether a better implementation of free would be useful at all.
// Overall, I'd really prefer keeping minilib tiny.
//
// Reusing also sparse freed memory areas leads 
// to a whole bunch of complications.
// cache misses, searching complexity,
// storage overhead,
// just to name a few.
//
// I'm not sure whether it's worth it.
//
// And the existing malloc implementations 
// out there are countless.
//
// ;) It's sometimes smarter to stay special,
// although in this case this means the opposite.
//   ? I'm not sure what this sentence means XD
//misc
//
//+def
void* malloc(int size){
		size = ((size-1) >> 2 ) + 2; // alignment and reserving space for the "pointer"
		if( ml.mbufsize-(size<<2)<64 ){
				write( STDERR_FILENO, "Out of memory.\n",15 );
				return((void*)0);
		}

		ml.ibuf[(ml.mbufsize>>2)] = ml.ibuf[(ml.mbufsize>>2)] & MBUF_V; // clear flag prev_isfree
		ml.mbufsize -= (size<<2);
		ml.ibuf[(ml.mbufsize>>2)] = size;
		return( &ml.mbuf[ml.mbufsize+4] );
}

#if 0
///+def
void free(void *p){
}

#else

//+def
void free(void *p){
		char *c = p;
		int *i = p;
		i--;
		c-=4;
		
		if ( &ml.mbuf[ml.mbufsize] == (char*)c ){ // at the bottom of the stack
				ml.mbufsize += (i[0] & MBUF_V) <<2;
				if ( ml.mbufsize == mini_buf )
						return;
				if ( ml.ibuf[ml.mbufsize>>2] & MBUF_FREE )
						ml.mbufsize += ( ( ml.ibuf[ml.mbufsize>>2] & MBUF_V ) << 2 );
				return;
				/*do {
						ml.mbufsize += mbuf[ml.mbufsize] +4;
						} while ( (ml.mbufsize < mini_buf ) && ( mbuf[ml.mbufsize] & MBUF_FREE ) );*/ // next area also free'd
		} else { // Not at the bottom
				if ( ( i[0] & MBUF_PREVISFREE )){ // prev area is free
						i[ - i[-1] -1 ] = ( ( i[ - i[-1] -1 ] + i[0] ) & MBUF_V ) | MBUF_FREE; // add this to prev.
						i = i - ( i[-1] + 1 );
				}
				// prev not free
				if ( (i[( i[0] & MBUF_V)] & MBUF_FREE) ){ // next area free
						i[0] = ((i[0] + i[( i[0] & MBUF_V)]) & MBUF_V) | MBUF_FREE; // add next to current. 
						// MBUF_FREE is already set. But for safety set it again. via mask 
						// adding MBUF_FREE twice wouldn't be that great
						i[( i[0] & MBUF_V) - 1 ] = ( i[0] & MBUF_V) - 1;
						return;
				} // prev area not free, next area not free
				i[( i[0] & MBUF_V) - 1 ] = ( i[0] & MBUF_V) - 1;
				i[( i[0] & MBUF_V)] = ( i[( i[0] & MBUF_V)] | MBUF_PREVISFREE ); 
				i[0] = i[0] | MBUF_FREE;
				return;

		} 

							 /*	(int)c[ -(int)c[-4] ] = (int)c[ -(int)c[-4] ] + ( (int)c[0] & MBUF_V ) + ( (int)c[ ((int)c[0] & MBUF_V) ] & MBUF_V ); // add this and next area to prev area.
								(int)c[(int)c[ ((int)c[0] & MBUF_V)]-4] = (int)c[ -(int)c[-4] ] -4; // write combined free areas
								else { // next not free
										(int)c[ -(int)c[-4] ] += ( (int)c[0] & MBUF_V ); // add this area to prev area.
										(int)c[(int)c[0] & MBUF_V ] = (int)c[(int)c[0]&MBUF_V] | MBUF_PREVISFREE // mark next area 
												(int)c[(int)c[0]-4] = (int)c[ -(int)c[-4] ]-4; //write len of combined free areas there 
								}
						} else { //prev not free
								if ( (int)c[ (int)c[0] & MBUF_V ] & MBUF_FREE ){ // next free
										//mbuf[ (int)c[0]
								}
						}

				}*/
		
}

#endif


#if 0

POINTER* ml_brk=0;
extern POINTER _bssend;

//+def
void* volatile malloc(int size){
#ifdef undef
#warning BRK def
		int ret=1;
		mfprintf(stderr,"MALLOC: _bssend: %d\n",_bssend);
		if ( ml_brk == 0 ){
				ml_brk = _bssend;
				syscall1(ret,SCALL(brk),&ml_brk+size);
				if ( ret!=0 ){
						mfprintf(stderr,"MALLOC: 0\n");
						return(0);
				}
				ml_brk+=size;
				return((void*)_bssend);
		} else {
				syscall1(ret,SCALL(brk),size+ml_brk);
				if ( ret!=0 ){
						mfprintf(stderr,"MALLOC: 0\n");
						return(0);
				}
				int old_brk= ml_brk;
				ml_brk += size;
				return((void*)old_brk);
		}
#else 
#warning malloc SYSCALL
/*		void* ret;
		syscall6(ret, SCALL(mmap), 0, size, (0x01|0x02), 0x1002, -1, 0);
		//syscall6(ret, SCALL(mmap), 0, size, PROT_READ|PROT_WRITE, 0x1002, -1, 0);
		return((void*)ret);*/
#endif

		void* ret;
		size=4096;
	  register volatile long int r8 asm ("r8") = -1 ; 
		register volatile long int r9 asm ("r9") = 0; 
		register volatile long int r10 asm ("r10") = 0x1002; 
			asm volatile (
							//"xor %%r9, %%r9;"
							//"mov $-1, %%r8;"
							//"mov $0x1002, %%r10;"
							"syscall" 
							   : "=a" (ret) 
								 : "a" (SCALL(mmap) ) , "D" (0), "S" (size), "d" (0x01|0x02), "r" (r10), "r" (r8), "r" (r9) 
							   : "rcx", "memory" );
			return( (void*)ret );

}

//+def
void volatile free(void* p){

}




//malloc old
		//size = 4096;
/*	  register long int r8 asm ("r8") = -1 ; 
		register long int r9 asm ("r9") = 0; 
		register volatile long int r10 asm ("r10") = 0x1002; 
			asm volatile (
							//"xor %%r9, %%r9;"
							//"mov $-1, %%r8;"
							//"mov $0x1002, %%r10;"
							"syscall" 
							   : "=a" (ret) 
								 : "a" ( ( 197  | 0x2000000 ) ) , "D" (0), "S" (size), "d" (0x01|0x02), "r" (r10), "r" (r8), "r" (r9) 
							   : "ecx", "memory" );
	*/					
 /*
		asm volatile(
						"mov %p6, %%r9\n\t"
						"mov %p5, %%r8\n\t"
						"mov %p4, %%r10\n\t"
						"mov %p3, %%rdx\n\t"
						"mov %p2, %%rsi\n\t"
						"mov %p1, %%rdi\n\t"
						"mov $0x20000000, %%rax\n\t"
						"syscall\n\t"
						:"=a"(ret)
						:[p1]"m"(0),[p2]"m"(1024),[p3]"m"(0x01),[p4]"m"(0x0002),[p5]"m"(-1),[p6]"m"(0));*/
#endif



#endif
#endif

// minilib/src/open.c
#ifdef mini_open
#ifndef open_c
#define open_c
//+header fcntl.h


//#include "syscall.h"
#ifndef mini_filemodes_h
#define mini_filemodes_h

#ifdef OSX

/* open-only flags */
#define	O_RDONLY	0x0000		/* open for reading only */
#define	O_WRONLY	0x0001		/* open for writing only */
#define	O_RDWR		0x0002		/* open for reading and writing */
#define	O_ACCMODE	0x0003		/* mask for above modes */

#define	FREAD		0x0001
#define	FWRITE		0x0002
#define	O_NONBLOCK	0x0004		/* no delay */
#define	O_APPEND	0x0008		/* set append mode */

#define	O_SHLOCK	0x0010		/* open with shared file lock */
#define	O_EXLOCK	0x0020		/* open with exclusive file lock */
#define	O_ASYNC		0x0040		/* signal pgrp when data ready */
#define	O_FSYNC		O_SYNC		/* source compatibility: do not use */
#define O_NOFOLLOW  0x0100      /* don't follow symlinks */
#define	O_CREAT		0x0200		/* create if nonexistant */
#define	O_TRUNC		0x0400		/* truncate to zero length */
#define	O_EXCL		0x0800		/* error if already exists */

#define	O_EVTONLY	0x8000		/* descriptor requested for event notifications only */

#define	O_NOCTTY	0x20000		/* don't assign controlling terminal */
#define O_DIRECTORY	0x100000
#define O_SYMLINK	0x200000	/* allow open of a symlink */
#define	O_CLOEXEC	0x1000000	/* implicitly set FD_CLOEXEC */
#define O_DP_GETRAWENCRYPTED	0x0001
#define O_DP_GETRAWUNENCRYPTED	0x0002



#else


#define O_ACCMODE	00000003
#define O_RDONLY	00000000
#define O_WRONLY	00000001
#define O_RDWR		00000002
#define O_CREAT		00000100	/* not fcntl */
#define O_EXCL		00000200	/* not fcntl */
#define O_NOCTTY	00000400	/* not fcntl */
#define O_TRUNC		00001000	/* not fcntl */
#define O_APPEND	00002000
#define O_NONBLOCK	00004000
#define O_DSYNC		00010000	/* used to be O_SYNC, see below */
#define FASYNC		00020000	/* fcntl, for BSD compatibility */
#define O_DIRECT	00040000	/* direct disk access hint */
#define O_LARGEFILE	00100000
#define O_DIRECTORY	00200000	/* must be a directory */
#define O_NOFOLLOW	00400000	/* don't follow links */
#define O_NOATIME	01000000
#define O_CLOEXEC	02000000	/* set close_on_exec */

#endif



#endif


#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif


//+def
int volatile open( const char *s, int flags, ... ){
		int ret;
		va_list args;
		va_start(args,flags);
		int mode = va_arg(args,int);
		va_end(args);

		syscall3(ret,SCALL(open),(POINTER)s,flags,mode);
		return(ret);
}

/// creat
//d open
//+def
inline int volatile __attribute__((always_inline)) creat( const char *s, int mode ){
		return(open( s, O_CREAT|O_WRONLY|O_TRUNC, mode) );
}



//FILE* volatile fopen( const char *s, const char *mode ){
//		int m = 0;




#endif
#endif

// minilib/src/sprintf.c
#ifdef mini_snprintf
#ifndef msprintf_c
#define msprintf_c

#ifndef mini_write
#define mini_write
#endif


#ifndef mini_prints
#define mini_prints
#endif

// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
#ifndef mini_prints
#define mini_prints
#endif
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...);
extern int dprints(int fd, char *msg,...);
//+header mini_addons.h

//+doc print the string(s) supplied as arg(s) to stdout
//+depends _mprints 
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)

//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints 
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)


//+depends printl print strlen
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

#endif
#define MINI_TEST_OVERRUN(pos) if (pos > ml.mbufsize){\
		printsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif

//#include "../include/write.h"
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif



#undef MINI_TEST_OVERRUN
#define MINI_TEST_OVERRUN(pos) if ( pos>= size ){ overflow=1; goto msprintfout;}



//+depends snprintf
//+macro
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

// I'm really uncertain about the size arg here, amongst others


//+ansi stdio.h
//+depends write
//+needs exit.h stdarg.h overrun.h
//+after itohex itoHEX
//+def
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args ){

		//va_list args;
		//va_start(args,fmt);
		int a = 0;
		int b = 0;
		int overflow = 0;
		int end, padding, c,groups=0;
		char sep;
		char tmp[16];
		char *s;

#if 1
		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}
								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
#if 1
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
#endif
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;
										case 'l':
#ifdef mini_ltodec
												MINI_TEST_OVERRUN(b+27);
												b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itoHEX(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;

										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
msprintfout:
		buf[b] = 0;
		va_end(args);

		//write( 2, buf, 20 );
		//return(write(fd,buf,b));
		if ( overflow )
				return(-b);
		else
				return(b);
#endif
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int dprintf( int fd, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(ml.mbuf, ml.mbufsize, fmt, args);
		if ( r<0 ){
				write(2,"Buffer Overrun.\n",16);
				exit(1);
		}
		write( fd, ml.mbuf, r );
		va_end(args);
		return(r);
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int snprintf( char *buf, size_t size, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(buf, size, fmt, args);
		va_end(args);
		return(r);
}



/// fprintf
/// conversions implemented:
/// %d  
/// %u
/// %f (max precision 8 digits, highest possible number: 2^31
/// %s
/// %c
/// %b : binary output
/// %x/X : hex output
/// %(
/// 
//+header stdio.h
//+depends write prints dprintf sprintf fileno
//+needs mini_fstream.h 
//+after itobin atoi itodec dtodec ltodec itohex
//+macro fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))



#if 0		
		va_list args;
		va_start(args,fmt);
		int a = 0;
		int b = 0;
		int end, padding, c,groups;
		char sep;
		char tmp[16];
		char *s;

		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}

								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&ml.mbuf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
		buf[b] = 0;
		va_end(args);
		//return(write(1,buf,b));
		return(b);
}
#endif
#endif
#endif

// minilib/src/dirent/readdir.c
#ifdef mini_readdir
#ifndef readdir_c
#define readdir_c

#ifndef	_DIRENT_H
#define	_DIRENT_H

#ifdef __cplusplus
extern "C" {
#endif

// just a placeholder

#define __NEED_ino_t
#define __NEED_off_t
#if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
#define __NEED_size_t
#endif

// source: musl
#ifndef alltypes_h
#define alltypes_h


#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif



#define _Addr long
#define _Int64 long
#define _Reg long

#ifndef size_t
#define size_t long
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

//typedef __builtin_va_list va_list;

//typedef __builtin_va_list __isoc_va_list;

typedef int wchar_t;

typedef long double double_t;

typedef float float_t;

typedef struct { long long __ll; long double __ld; } max_align_t;

//typedef long time_t;

//typedef long suseconds_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;

typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;

//typedef unsigned _Addr size_t;
//#define __DEFINED_size_t

typedef unsigned _Addr uintptr_t;

typedef _Addr ptrdiff_t;

typedef _Addr ssize_t;

typedef _Addr intptr_t;

typedef _Addr regoff_t;

typedef _Reg register_t;

typedef signed char     int8_t;

typedef signed short    int16_t;

typedef signed int      int32_t;

typedef signed _Int64   int64_t;

typedef signed _Int64   intmax_t;

typedef unsigned char   uint8_t;

typedef unsigned short  uint16_t;

typedef unsigned int    uint32_t;

typedef unsigned _Int64 uint64_t;

typedef unsigned _Int64 u_int64_t;

typedef unsigned _Int64 uintmax_t;

typedef unsigned mode_t;

typedef unsigned _Reg nlink_t;

typedef _Int64 off_t;

typedef unsigned _Int64 ino_t;

typedef unsigned _Int64 dev_t;

typedef long blksize_t;

typedef _Int64 blkcnt_t;

typedef unsigned _Int64 fsblkcnt_t;

typedef unsigned _Int64 fsfilcnt_t;

typedef unsigned wint_t;

typedef unsigned long wctype_t;

typedef void * timer_t;

typedef int clockid_t;

typedef long clock_t;

//struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timespec { time_t tv_sec; long tv_nsec; };

typedef int pid_t;

typedef unsigned id_t;

typedef unsigned uid_t;

typedef unsigned gid_t;

typedef int key_t;

//typedef unsigned useconds_t;

//typedef struct _IO_FILE FILE;

typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;

typedef struct __locale_struct * locale_t;

typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;

struct iovec { void *iov_base; size_t iov_len; };

typedef unsigned socklen_t;

typedef unsigned short sa_family_t;

#undef _Addr
#undef _Int64
#undef _Reg

#endif


struct __dirstream
{
	off_t tell;
	int fd;
	int buf_pos;
	int buf_end;
	volatile int lock[1];
	/* Any changes to this struct must preserve the property:
	 * offsetof(struct __dirent, buf) % sizeof(off_t) == 0 */
	char buf[2048];
};
typedef struct __dirstream DIR;

#define _DIRENT_HAVE_D_RECLEN
#define _DIRENT_HAVE_D_OFF
#define _DIRENT_HAVE_D_TYPE

struct dirent {
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	//unsigned char d_type;
	char d_name[256];
};

#define d_fileno d_ino
#if 0
int            closedir(DIR *);
DIR           *fdopendir(int);
DIR           *opendir(const char *);
struct dirent *readdir(DIR *);
int            readdir_r(DIR *__restrict, struct dirent *__restrict, struct dirent **__restrict);
void           rewinddir(DIR *);
int            dirfd(DIR *);

int alphasort(const struct dirent **, const struct dirent **);
int scandir(const char *, struct dirent ***, int (*)(const struct dirent *), int (*)(const struct dirent **, const struct dirent **));

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
void           seekdir(DIR *, long);
long           telldir(DIR *);
#endif
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define DT_UNKNOWN 0
#define DT_FIFO 1
#define DT_CHR 2
#define DT_DIR 4
#define DT_BLK 6
#define DT_REG 8
#define DT_LNK 10
#define DT_SOCK 12
#define DT_WHT 14
#define IFTODT(x) ((x)>>12 & 017)
#define DTTOIF(x) ((x)<<12)
int getdents(int, struct dirent *, size_t);
#endif

#ifdef _GNU_SOURCE
int versionsort(const struct dirent **, const struct dirent **);
#endif

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define dirent64 dirent
#define readdir64 readdir
#define readdir64_r readdir_r
#define scandir64 scandir
#define alphasort64 alphasort
#define versionsort64 versionsort
#define off64_t off_t
#define ino64_t ino_t
#define getdents64 getdents
#endif

#ifdef __cplusplus
}
#endif

#endif
//typedef char dirstream_buf_alignment_check[1-2*(int)(
//	offsetof(struct __dirstream, buf) % sizeof(off_t))];

//+def
struct dirent *readdir(DIR *dir){
	struct dirent *de;
	
	if (dir->buf_pos >= dir->buf_end) {
		int len = getdents( dir->fd, dir->buf, sizeof dir->buf);
		if (len <= 0) {
			if (len < 0 && len != -ENOENT) errno = -len;
			return 0;
		}
		dir->buf_end = len;
		dir->buf_pos = 0;
	}
	de = (void *)(dir->buf + dir->buf_pos);
	dir->buf_pos += de->d_reclen;
	dir->tell = de->d_off;
	return de;
}


#endif
#endif

// minilib/src/itobin.c
#ifdef mini_itobin
#ifndef mini_itobin_h
#define mini_itobin_h



//+ansi stdio.h
//+def
int _itobin(int i, char*buf, int prec, int groups ){
		prec -= 32;
		int a,p=0;
		int g = 0;
		for ( a=0; a<32; a++ ){
				if (i&0x80000000 ){
						prec = 0;
						buf[p] = '1';
						p++;
				} else {
						if ( prec == 0 ){
								buf[p] = '0';
								p++;
						} else
								prec++;
				}
				i <<= 1;
				g++;
				if ( (prec==0) && (g>=groups) ){
						g=0;
						buf[p] = ' ';
						p++;
				}
		}
		if ( p == 0 ){
				buf[0] = '0';
				p++;
		}
		buf[p] = 0;
		return(p);
}

//+depends _itobin
//+macro itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )


#endif
#endif

// minilib/src/ioctl.c
#ifdef mini_ioctl
#ifndef mini_ioctl_h
#define mini_ioctl_h

//#include "../include/syscall.h"
#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif

//#include "/usr/diet/include/stdarg.h"

//+header ioctl.h
//+def
int ioctl( int fd, unsigned long int request, ... ){
		va_list args;
		va_start(args,request);

		int ret;
		syscall3(ret, SCALL(ioctl),fd,request,(long int)va_arg(args,void*));
		va_end(args);
		return(ret);
}


#endif
#endif

// minilib/src/dtodec.c
#ifdef mini_dtodec
//convert double to string
//return number of bytes written to buf.
//doesn't convert numbers > 2^31 (!!!)
//doesn't round(!)
//max. prec after the dot: 8 digits. (!!)

//+ansi stdio.h
//+depends uitodec
//+def
int dtodec(double d, char* buf, int precision){
		int i = (int) d;
		unsigned int i2;
		if ( d >= 0 )
			 i2 = (unsigned int)((d-i)*1000000000+0.1);
		else 
			 i2 = (unsigned int)((double)(-d+i)*1000000000+0.1);


		int p;
		if ( (d<=-1) || (d>0) )
				p = itodec(i,buf,0,0);
		else {
				buf[0] = '-';
				buf[1] = '0';
				p = 1;
		}

	
		buf[p+1]='.';
		int p2 = uitodec(i2,&buf[p+2],9,0);
		return(p+p2+2-9+precision);
}
#endif

// minilib/src/fprintfs.c
#ifdef mini_fprintfs



//+depends fputs write fileno
//+after fputs
//+doc prints formatted to the stream F.
//+doc only %s is recognized.
//+doc no mini_buf needed, so using fprintfs instead of fprintf can save some sections / bytes.
//+def
int fprintfs( FILE* F, char *fmt, ...){
		va_list args;
		va_start(args,fmt);
		char *msg;
		int fd = fileno(F);
		int a;
		int p=0;
		int ret = 0;

		a = 0;
		while (fmt[a] != 0 ){
				if ( fmt[a] == '%' ){
						a++;
						if (fmt[a] == 's'){
								ret += write(fd,&fmt[p],a-1-p);
								p=a+1;
								msg = va_arg(args,char*);
								ret += fputs( msg, F );
						}
				}
				a++;
		}
		ret += write(fd,&fmt[p],a-p);

		va_end(args);
		return(ret);

}


#endif

// minilib/src/mstrcmp.c
#ifdef mini_strncmp
#ifndef strcmp_c
#define strcmp_c

//+ansi string.h

//TODO: not implemented correct. need to return also -1.

int _strcmp(const char*c1,const char*c2,int len){
		int a = 0;
		while ( (c1[a] != 0) && (c2[a]!=0 ) && a != len ){
				//write(1,&c1[a],1);
				if ( c1[a] != c2[a] )
						return(1);
				a++;
		}
		if ( (c1[a] == 0 ) && ( c2[a] == 0 ) )
				return(0);
		return (1);
}



//+def
int strcmp(const char*c1,const char*c2){
		return( _strcmp(c1,c2,-1) );
}

//+def
int strncmp(const char*c1,const char*c2,int len){
		if ( len <=0 )
				return(-1);
		return(_strcmp(c1,c2,len) );
}

//+def
int memcmp(const void* c1,const void* c2,int len){
		const char* cc1 = c1;
		const char* cc2 = c2;
		if ( len <=0 )
				return(-1);
		int a = 0;
		while ( a != len ){
				//write(1,&c1[a],1);
				if ( cc1[a] != cc2[a] )
						return(1);
				a++;
		}
	 return(0);
}


#endif
#endif

// minilib/src/memcpy.c
#ifdef mini_strcpy
#ifndef memcpy_c
#define memcpy_c

//+ansi string.h
//+def
void *memcpy( void *d, const void *s, int n ){
		char *dp=d;
		const char *sp = s;
		int a;
		for ( a=0; a<n; a++ )
				dp[a] = sp[a];
		return(d);
}


//+def
char *strcpy(char *dest, const char *src){
		int a;
		for ( a=0; src[a] != 0; a++)
				dest[a] = src[a];
		dest[a] = 0;
		return(dest);
}

//+depends memcpy
//+def
char *strncpy(char *dest, const char *src, int n){
		return( memcpy( dest, src, n ) );
}

#endif

#endif

// minilib/src/dirent/opendir.c
#ifdef mini_opendir
#ifndef opendir_c
#define opendir_c
#ifndef	_DIRENT_H
#define	_DIRENT_H

#ifdef __cplusplus
extern "C" {
#endif

// just a placeholder

#define __NEED_ino_t
#define __NEED_off_t
#if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
#define __NEED_size_t
#endif

// source: musl
#ifndef alltypes_h
#define alltypes_h


#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif



#define _Addr long
#define _Int64 long
#define _Reg long

#ifndef size_t
#define size_t long
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

//typedef __builtin_va_list va_list;

//typedef __builtin_va_list __isoc_va_list;

typedef int wchar_t;

typedef long double double_t;

typedef float float_t;

typedef struct { long long __ll; long double __ld; } max_align_t;

//typedef long time_t;

//typedef long suseconds_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;

typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;

//typedef unsigned _Addr size_t;
//#define __DEFINED_size_t

typedef unsigned _Addr uintptr_t;

typedef _Addr ptrdiff_t;

typedef _Addr ssize_t;

typedef _Addr intptr_t;

typedef _Addr regoff_t;

typedef _Reg register_t;

typedef signed char     int8_t;

typedef signed short    int16_t;

typedef signed int      int32_t;

typedef signed _Int64   int64_t;

typedef signed _Int64   intmax_t;

typedef unsigned char   uint8_t;

typedef unsigned short  uint16_t;

typedef unsigned int    uint32_t;

typedef unsigned _Int64 uint64_t;

typedef unsigned _Int64 u_int64_t;

typedef unsigned _Int64 uintmax_t;

typedef unsigned mode_t;

typedef unsigned _Reg nlink_t;

typedef _Int64 off_t;

typedef unsigned _Int64 ino_t;

typedef unsigned _Int64 dev_t;

typedef long blksize_t;

typedef _Int64 blkcnt_t;

typedef unsigned _Int64 fsblkcnt_t;

typedef unsigned _Int64 fsfilcnt_t;

typedef unsigned wint_t;

typedef unsigned long wctype_t;

typedef void * timer_t;

typedef int clockid_t;

typedef long clock_t;

//struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timespec { time_t tv_sec; long tv_nsec; };

typedef int pid_t;

typedef unsigned id_t;

typedef unsigned uid_t;

typedef unsigned gid_t;

typedef int key_t;

//typedef unsigned useconds_t;

//typedef struct _IO_FILE FILE;

typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;

typedef struct __locale_struct * locale_t;

typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;

struct iovec { void *iov_base; size_t iov_len; };

typedef unsigned socklen_t;

typedef unsigned short sa_family_t;

#undef _Addr
#undef _Int64
#undef _Reg

#endif


struct __dirstream
{
	off_t tell;
	int fd;
	int buf_pos;
	int buf_end;
	volatile int lock[1];
	/* Any changes to this struct must preserve the property:
	 * offsetof(struct __dirent, buf) % sizeof(off_t) == 0 */
	char buf[2048];
};
typedef struct __dirstream DIR;

#define _DIRENT_HAVE_D_RECLEN
#define _DIRENT_HAVE_D_OFF
#define _DIRENT_HAVE_D_TYPE

struct dirent {
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	//unsigned char d_type;
	char d_name[256];
};

#define d_fileno d_ino
#if 0
int            closedir(DIR *);
DIR           *fdopendir(int);
DIR           *opendir(const char *);
struct dirent *readdir(DIR *);
int            readdir_r(DIR *__restrict, struct dirent *__restrict, struct dirent **__restrict);
void           rewinddir(DIR *);
int            dirfd(DIR *);

int alphasort(const struct dirent **, const struct dirent **);
int scandir(const char *, struct dirent ***, int (*)(const struct dirent *), int (*)(const struct dirent **, const struct dirent **));

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
void           seekdir(DIR *, long);
long           telldir(DIR *);
#endif
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define DT_UNKNOWN 0
#define DT_FIFO 1
#define DT_CHR 2
#define DT_DIR 4
#define DT_BLK 6
#define DT_REG 8
#define DT_LNK 10
#define DT_SOCK 12
#define DT_WHT 14
#define IFTODT(x) ((x)>>12 & 017)
#define DTTOIF(x) ((x)<<12)
int getdents(int, struct dirent *, size_t);
#endif

#ifdef _GNU_SOURCE
int versionsort(const struct dirent **, const struct dirent **);
#endif

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define dirent64 dirent
#define readdir64 readdir
#define readdir64_r readdir_r
#define scandir64 scandir
#define alphasort64 alphasort
#define versionsort64 versionsort
#define off64_t off_t
#define ino64_t ino_t
#define getdents64 getdents
#endif

#ifdef __cplusplus
}
#endif

#endif



//+depends open close malloc
//+needs dirent.h
//+def
DIR *opendir(const char *name){
	int fd;
	DIR *dir;

	if ((fd = open(name, O_RDONLY|O_DIRECTORY|O_CLOEXEC)) < 0)
		return 0;
	dir = malloc(sizeof(*dir));
	if ( dir == 0 ){
		//	fprintf("Got: %d\n", dir);
		close( fd );
		return 0;
	}

	dir->fd = fd;
	return dir;
}



#endif

#endif

// minilib/src/rand.c
#ifdef mini_srand
#ifndef rand_c
#define rand_c


//+header stdlib.h
//+def
void srand( unsigned int i ){
		ml.srand = i;
}
	


//+header stdlib.h
//+def
unsigned int rand(){
		// xorshift, algorithm af marsaglia.
		// second round added, it doesn't give more randomness,
		// but isn't so expensive on the other hand.
		if ( ml.srand==0 ){
				ml.srand=1;
		}
		ml.srand ^= ml.srand << 13;
 		ml.srand ^= ml.srand >> 17;
 		ml.srand ^= ml.srand << 5;
		unsigned int t = ml.srand;
		ml.srand ^= ml.srand << 13;
 		ml.srand ^= ml.srand >> 17;
 		ml.srand ^= ml.srand << 5;
		return(t-1);
}









#endif

#endif

// minilib/src/itohex.c
#ifdef mini__itohex
#ifndef itohex_c
#define itohex_c
//+header stdio.h
//+def
int _itohex(int i,char* buf,int padding, int capitals){

		if ( capitals>0 )
				capitals = 55;
		else
				capitals = 87;

		padding = padding - 8;
		if ( padding < -7 )
				padding = -7;

		union { int n; char c[4]; } conv[2];
		conv[0].n = (( i & 0xf0f0f0f0 ) >> 4);
		conv[1].n = ( i & 0x0f0f0f0f );
		int p = 0;
		int a,b;

		for ( a=3; a>=0; a-- ){
				for ( b=0; b <=1; b++ ){
						if ( padding != 0 ){
								if ( conv[b].c[a] != 0 ){
										padding = 0;
								}
						}
						if ( padding == 0 ){
								char c = conv[b].c[a];
								if ( c < 0xa )
										c = c + 48;
								else
										c = c + capitals; // 55 for big abc ..
								buf[p] = c;
								p++;
						} else
								padding++;
				}
		}
		buf[p] = 0 ;
		return(p);
}

//+header stdio.h
//+depends _itohex
//+def
int itohex(int i,char* buf,int padding){
		return(_itohex(i,buf,padding,0));
}

//+header stdio.h
//+depends _itohex
//+def
int itoHEX(int i,char* buf,int padding){
		return(_itohex(i,buf,padding,1));
}




#endif

#endif

// minilib/src/sprintf.c
#ifdef mini_fprintf
#ifndef msprintf_c
#define msprintf_c

#ifndef mini_write
#define mini_write
#endif


#ifndef mini_prints
#define mini_prints
#endif

// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
#ifndef mini_prints
#define mini_prints
#endif
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...);
extern int dprints(int fd, char *msg,...);
//+header mini_addons.h

//+doc print the string(s) supplied as arg(s) to stdout
//+depends _mprints 
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)

//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints 
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)


//+depends printl print strlen
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

#endif
#define MINI_TEST_OVERRUN(pos) if (pos > ml.mbufsize){\
		printsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif

//#include "../include/write.h"
#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

//#include "syscall.h"
//#undef write
//#undef exit


#ifdef X64
#define exit(ret) asm("jmp _exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _exit"::"b"(ret))
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
#ifndef stdarg_h
#define stdarg_h
// copied from musl
// copy more - the builtin list..

#if 1
#if __GNUC__ >= 3
//#warning here 1
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
//#warning here 2

#ifdef __GNUC__
//#warning here 3
//TODO: this gets scrambled if in the same compiler unit as the caller.
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))

#define va_arg(ap, type) \
	( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))), \
	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )


#else

//#warning here 4
// copied from tcc
#ifdef __x86_64__
//#warning here 5
#ifndef _WIN64
//#warning here 6

typedef void *va_list;

va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);

#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type)                                                \
		    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)

#else /* _WIN64 */
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

#else /* __i386__ */
typedef char *va_list;
/* only correct for i386 */
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif

/* fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif
#endif

#endif

#endif



#undef MINI_TEST_OVERRUN
#define MINI_TEST_OVERRUN(pos) if ( pos>= size ){ overflow=1; goto msprintfout;}



//+depends snprintf
//+macro
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

// I'm really uncertain about the size arg here, amongst others


//+ansi stdio.h
//+depends write
//+needs exit.h stdarg.h overrun.h
//+after itohex itoHEX
//+def
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args ){

		//va_list args;
		//va_start(args,fmt);
		int a = 0;
		int b = 0;
		int overflow = 0;
		int end, padding, c,groups=0;
		char sep;
		char tmp[16];
		char *s;

#if 1
		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}
								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
#if 1
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
#endif
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;
										case 'l':
#ifdef mini_ltodec
												MINI_TEST_OVERRUN(b+27);
												b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itoHEX(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;

										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
msprintfout:
		buf[b] = 0;
		va_end(args);

		//write( 2, buf, 20 );
		//return(write(fd,buf,b));
		if ( overflow )
				return(-b);
		else
				return(b);
#endif
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int dprintf( int fd, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(ml.mbuf, ml.mbufsize, fmt, args);
		if ( r<0 ){
				write(2,"Buffer Overrun.\n",16);
				exit(1);
		}
		write( fd, ml.mbuf, r );
		va_end(args);
		return(r);
}


//+depends write vsnprintf
//+needs stdarg.h
//+def
int snprintf( char *buf, size_t size, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(buf, size, fmt, args);
		va_end(args);
		return(r);
}



/// fprintf
/// conversions implemented:
/// %d  
/// %u
/// %f (max precision 8 digits, highest possible number: 2^31
/// %s
/// %c
/// %b : binary output
/// %x/X : hex output
/// %(
/// 
//+header stdio.h
//+depends write prints dprintf sprintf fileno
//+needs mini_fstream.h 
//+after itobin atoi itodec dtodec ltodec itohex
//+macro fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))



#if 0		
		va_list args;
		va_start(args,fmt);
		int a = 0;
		int b = 0;
		int end, padding, c,groups;
		char sep;
		char tmp[16];
		char *s;

		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}

								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&ml.mbuf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
		buf[b] = 0;
		va_end(args);
		//return(write(1,buf,b));
		return(b);
}
#endif
#endif
#endif

// minilib/src/dirent/closedir.c
#ifdef mini_closedir
#ifndef closedir_c
#define closedir_c


//+def
int closedir(DIR *dir){
	int ret = close(dir->fd);
	free(dir);
	return ret;
}



#endif
#endif

// minilib/src/atoi.c
#ifdef mini_atoi
#ifndef atoi_c
#define atoi_c

//+ansi stdlib.h
//+def
int atoi(char *c){
		int t,a=0;
	 	int ret=0;
		int dez = 1;

		while( c[a] != 0 ){ 
				a++; 
		}
		while ( a>0 ){
				a--;
				if ( (c[a] > 48 ) && ( c[a] < 58 ) ){
						t = c[a] - 48;
						if ( t & 1 )
								ret += dez;
						dez <<= 1;
						if ( t & 2 )
								ret += dez;
						dez <<= 1;
						if ( t & 4 )
								ret += dez;
						dez <<= 1;
						if ( t & 8 )
								ret += dez;
				} else {
						dez <<= 3;
				}
				dez += (dez >> 2);
		}
		if ( c[0] == '-' )
				ret = -ret;
		return(ret);
}


#endif
		
#endif

// minilib/src/strcat.c
#ifdef mini_strcat
#ifndef strcat_c
#define strcat_c

//+ansi string.h
//+def
char *strcat(char *dest, const char *src ){
		size_t dest_len = strlen(dest);
		size_t i;

		for (i = 0 ; src[i] != '\0' ; i++)
				dest[dest_len + i] = src[i];
		dest[dest_len + i] = '\0';

		return dest;
}


#endif

#endif

// minilib/src/fopen.c
#ifdef mini_fopen
#ifndef mini_fopen_c
#define mini_fopen_c

#ifndef mini_filemodes_h
#define mini_filemodes_h

#ifdef OSX

/* open-only flags */
#define	O_RDONLY	0x0000		/* open for reading only */
#define	O_WRONLY	0x0001		/* open for writing only */
#define	O_RDWR		0x0002		/* open for reading and writing */
#define	O_ACCMODE	0x0003		/* mask for above modes */

#define	FREAD		0x0001
#define	FWRITE		0x0002
#define	O_NONBLOCK	0x0004		/* no delay */
#define	O_APPEND	0x0008		/* set append mode */

#define	O_SHLOCK	0x0010		/* open with shared file lock */
#define	O_EXLOCK	0x0020		/* open with exclusive file lock */
#define	O_ASYNC		0x0040		/* signal pgrp when data ready */
#define	O_FSYNC		O_SYNC		/* source compatibility: do not use */
#define O_NOFOLLOW  0x0100      /* don't follow symlinks */
#define	O_CREAT		0x0200		/* create if nonexistant */
#define	O_TRUNC		0x0400		/* truncate to zero length */
#define	O_EXCL		0x0800		/* error if already exists */

#define	O_EVTONLY	0x8000		/* descriptor requested for event notifications only */

#define	O_NOCTTY	0x20000		/* don't assign controlling terminal */
#define O_DIRECTORY	0x100000
#define O_SYMLINK	0x200000	/* allow open of a symlink */
#define	O_CLOEXEC	0x1000000	/* implicitly set FD_CLOEXEC */
#define O_DP_GETRAWENCRYPTED	0x0001
#define O_DP_GETRAWUNENCRYPTED	0x0002



#else


#define O_ACCMODE	00000003
#define O_RDONLY	00000000
#define O_WRONLY	00000001
#define O_RDWR		00000002
#define O_CREAT		00000100	/* not fcntl */
#define O_EXCL		00000200	/* not fcntl */
#define O_NOCTTY	00000400	/* not fcntl */
#define O_TRUNC		00001000	/* not fcntl */
#define O_APPEND	00002000
#define O_NONBLOCK	00004000
#define O_DSYNC		00010000	/* used to be O_SYNC, see below */
#define FASYNC		00020000	/* fcntl, for BSD compatibility */
#define O_DIRECT	00040000	/* direct disk access hint */
#define O_LARGEFILE	00100000
#define O_DIRECTORY	00200000	/* must be a directory */
#define O_NOFOLLOW	00400000	/* don't follow links */
#define O_NOATIME	01000000
#define O_CLOEXEC	02000000	/* set close_on_exec */

#endif



#endif



//+header stdio.h
//+depends open
//+needs lseek.h
//+def
FILE *fopen(const char* filename, const char* mode){
		int imode;

		switch (mode[0]){
				case 'r': imode = O_RDONLY;
									break;
				case 'w': imode = O_WRONLY | O_TRUNC | O_CREAT;
									break;
				case 'a': imode = O_APPEND; // somehow only "a+" works. Not sure, why.
									break;
				default: return((FILE*)0); // hopefully a fd cannot be 0.? By reading the manual, 
								 // I conclude only stdin has the fildes 0. So It MIGHT be ok.
								  // Anyways, if someone's trying to open stdin via fopen and is wondering, what's going on..
								 // Here's the answer. But, regarding the bsd manuals, one shouldn't open stdin with fopen at all. so..
		}

		for ( int a=1; (mode[a] != 0) && ( a<6 ); a++ ){
 				if ( mode[a] == '+' ){ 
						imode = imode | O_RDWR;
				} else {
						switch (mode[0]){
								case 'r': 
										break;
								case 'w': if ( mode[a] == 'x' )
															imode = imode & ( ~(O_CREAT | O_TRUNC) );
													break;
								case 'a': 
													break;
						}
				}
		}
		//puts("XXX");
		int a;
		if ( ml.stream[ml.pstream]>=FOPEN_MAX){
			for ( a=3; ml.stream[a]>=0; a++ )
					if ( a >= FOPEN_MAX )
							return(0);
		} else {
				a = ml.pstream;
				ml.pstream++;
		}

		//printf("a: %d\n",a);
		FILE *f = &ml.stream[a];
		ml.stream[a] =  open( filename, imode, 0666 );
		return ( f ); // 
}

#endif
#endif

// minilib/src/rand.c
#ifdef mini_rand
#ifndef rand_c
#define rand_c


//+header stdlib.h
//+def
void srand( unsigned int i ){
		ml.srand = i;
}
	


//+header stdlib.h
//+def
unsigned int rand(){
		// xorshift, algorithm af marsaglia.
		// second round added, it doesn't give more randomness,
		// but isn't so expensive on the other hand.
		if ( ml.srand==0 ){
				ml.srand=1;
		}
		ml.srand ^= ml.srand << 13;
 		ml.srand ^= ml.srand >> 17;
 		ml.srand ^= ml.srand << 5;
		unsigned int t = ml.srand;
		ml.srand ^= ml.srand << 13;
 		ml.srand ^= ml.srand >> 17;
 		ml.srand ^= ml.srand << 5;
		return(t-1);
}









#endif

#endif

// minilib/src/itobin.c
#ifdef mini__itobin
#ifndef mini_itobin_h
#define mini_itobin_h



//+ansi stdio.h
//+def
int _itobin(int i, char*buf, int prec, int groups ){
		prec -= 32;
		int a,p=0;
		int g = 0;
		for ( a=0; a<32; a++ ){
				if (i&0x80000000 ){
						prec = 0;
						buf[p] = '1';
						p++;
				} else {
						if ( prec == 0 ){
								buf[p] = '0';
								p++;
						} else
								prec++;
				}
				i <<= 1;
				g++;
				if ( (prec==0) && (g>=groups) ){
						g=0;
						buf[p] = ' ';
						p++;
				}
		}
		if ( p == 0 ){
				buf[0] = '0';
				p++;
		}
		buf[p] = 0;
		return(p);
}

//+depends _itobin
//+macro itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )


#endif
#endif

#endif
#endif
