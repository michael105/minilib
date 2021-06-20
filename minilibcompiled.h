#ifdef UNDEF
ifdef UNDEF

This file is part of minilib,
a C system library with a focus on small sizes
and being configurable.
(www.github.com/michael105/minilib)

Copyright (c) 2012-2021, Michael (Misc) Myer 
(misc.myer@zoho.com, www.github.com/michael105)
All rights reserved.

Please have a look into the file NOTICE and/or LICENSE 
for the exact license terms.

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
#ifndef LDSCRIPT
#ifndef included_minilib_h
#define included_minilib_h
#ifdef HEADERGUARDS
#define mini_HEADERGUARDS
#endif
#ifdef mini_getenv
#ifndef mini_environ
#define mini_environ
#endif
#endif
#ifdef mini_system
#ifndef mini_environ
#define mini_environ
#endif
#endif
#ifdef HEADERGUARDS
#ifndef headerguards_h
#define headerguards_h
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
#define __LINUX_IF_PACKET_H
#define _ERR_H
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
#define _DLFCN_H
#define _ENVZ_H
#define _ERRNO_H
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
#define _LINUX_LOOP_H
#define _LINUX_TYPES_H
#define _LINUX_SECCOMP_H
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
#define _STDDEF_H
#define _STDIO_EXT_H
#define _STDIO_H
#define _STDLIB_H
#define _STRING_H
#define _STRINGS_H
#define _STROPTS_H
#define _SYSCALL_H
#define _SYS_ACCT_H
#define _SYS_AUXV_H
#define _SYS_DEBUGREG_H
#define _SYS_ELF_H
#define _SYS_FSUID_H
#define _SYS_GMON_OUT_H
#define _SYS_IOCTL_H
#define _SYS_INOTIFY_H
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
#define _SYS_SWAP_H
#define _SYS_SYSINFO_H
#define _SYS_SYSLOG_H
#define _SYS_SYSMACROS_H
#define _SYS_TIMEB_H
#define _SYS_TIME_H
#define _SYS_TIMERFD_H
#define _SYS_TTYCHARS_H
#define _SYS_TTYDEFAULTS_H
#define _SYS_TYPES_H
#define _SYS_UCONTEXT_H
#define _SYS_UIO_H
#define _SYS_USER_H
#define _SYS_VLIMIT_H
#define _SYS_VM86_H
#define _SYS_VTIMES_H
#define _SYS_XATTR_H
#define _SYS_WAIT_H
#define _TGMATH_H
#define _THREADS_H
#define _THREAD_DB_H
#define _THREAD_SHARED_TYPES_H
#define _TIME_H
#define _UCHAR_H
#define _UCONTEXT_H
#define _ULIMIT_H
#define _UNISTD_H
#define _UTIME_H
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
#ifndef globaldefs_h
#define globaldefs_h
#ifdef X64
#define POINTER unsigned long int
#define __BYTEORDER __LITTLE_ENDIAN
#else
#define POINTER unsigned int
#endif
#ifndef uint32_t
typedef unsigned int uint32_t;
#endif
#ifndef uint8_t
typedef unsigned char uint8_t;
#endif
#ifndef size_t
typedef long size_t;
#endif
#define LOCK_SH 1 // Shared
#define LOCK_EX 2 // Exclusive
#define LOCK_NB 4 // Don't block when locking
#define LOCK_UN 8 // Unlock
#ifndef SEEK_SET
#define SEEK_SET        0       
#define SEEK_CUR        1       
#define SEEK_END        2       
#define SEEK_MAX        SEEK_END
#endif
#ifndef ENOENT
#define ENOENT           2
#endif
#define SIG_BLOCK     0
#define SIG_UNBLOCK   1
#define SIG_SETMASK   2
#define RE_NOMATCH 0
#define RE_ERROR 0
#define RE_MATCH 1
#define RE_MATCHEND -1
typedef struct _text_match { char *pos; int len; } text_match;
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
struct utimbuf{
time_t actime;    
time_t modtime;   
};
#define AT_STATX_SYNC_AS_STAT 0x0000
#define AT_NO_AUTOMOUNT 0x800
#define AT_EMPTY_PATH 0x1000
#define AT_STATX_SYNC_TYPE 0x6000
#define AT_STATX_FORCE_SYNC 0x2000
#define AT_STATX_DONT_SYNC 0x4000
#define AT_RECURSIVE 0x8000
#define BUFSIZ 1024
#ifndef mini_max_groupmembers
#define mini_max_groupmembers 64
#endif
#define MAX_GROUPMEMBERS mini_max_groupmembers
typedef int FILE;
#define FEOF_FLAG 0x800000
#define ERR_FLAG 0x400000
#define FLAG_MASK 0xc00000
#define FD_MASK 0x3fffff
#define UNGETC_MASK 0xff000000
#ifdef X64
typedef union { FILE *F; int i, fd;} mfl_union;
#else
#warning checkme
#warning typedef union { FILE *F; int fd;} mfl_union;
#endif
#define EOF (-1)
#ifdef mini_buf
#ifndef stdin
#define stdin &mlgl->stream[0]
#endif
#ifndef stdout
#define stdout &mlgl->stream[1]
#endif
#ifndef stderr
#define stderr &mlgl->stream[2]
#endif
#else
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
typedef struct { int quot; int rem; } div_t;
typedef struct { long int quot; long int rem; } ldiv_t;
typedef void (*sighandler_t)(int);
typedef void (functionp)(void);
#ifdef mini_atexit
#if (mini_atexit>0)
#define ATEXIT_MAX mini_atexit
#else
#define ATEXIT_MAX 8
#endif
#endif
#ifdef mini_ioctl
#endif
#define SIZE_MAX 0xfffffff
#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
struct timezone {
int     tz_minuteswest; 
int     tz_dsttime;     
};
#endif
#define FD_SETSIZE 1024
typedef unsigned long fd_mask;
typedef struct
{
unsigned long fds_bits[FD_SETSIZE / 8 / sizeof(long)];
} fd_set;
#define FD_ZERO(s) do { int __i; unsigned long *__b=(s)->fds_bits; for(__i=sizeof (fd_set)/sizeof (long); __i; __i--) *__b++=0; } while(0)
#define FD_SET(d, s)   ((s)->fds_bits[(d)/(8*sizeof(long))] |= (1UL<<((d)%(8*sizeof(long)))))
#define FD_CLR(d, s)   ((s)->fds_bits[(d)/(8*sizeof(long))] &= ~(1UL<<((d)%(8*sizeof(long)))))
#define FD_ISSET(d, s) !!((s)->fds_bits[(d)/(8*sizeof(long))] & (1UL<<((d)%(8*sizeof(long)))))
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define F_OK 0
#define X_OK 1
#define W_OK 2
#define R_OK 4
#define WNOHANG    1
#define WUNTRACED  2
#define WSTOPPED   2
#define WEXITED    4
#define WCONTINUED 8
#define WNOWAIT    0x1000000
#define WEXITSTATUS(s) (((s) & 0xff00) >> 8)
#define WTERMSIG(s) ((s) & 0x7f)
#define WSTOPSIG(s) WEXITSTATUS(s)
#define WCOREDUMP(s) ((s) & 0x80)
#define WIFEXITED(s) (!WTERMSIG(s))
#define WIFSTOPPED(s) ((short)((((s)&0xffff)*0x10001)>>8) > 0x7f00)
#define WIFSIGNALED(s) (((s)&0xffff)-1U < 0xffu)
#define WIFCONTINUED(s) ((s) == 0xffff)
#define MAP_FAILED ((void *) -1)
#define MAP_FILE       0
#define MAP_SHARED     0x01
#define MAP_PRIVATE    0x02
#define MAP_SHARED_VALIDATE 0x03
#define MAP_TYPE       0x0f
#define MAP_FIXED      0x10
#define MAP_ANON       0x20
#define MAP_ANONYMOUS  MAP_ANON
#define MAP_NORESERVE  0x4000
#define MAP_GROWSDOWN  0x0100
#define MAP_DENYWRITE  0x0800
#define MAP_EXECUTABLE 0x1000
#define MAP_LOCKED     0x2000
#define MAP_POPULATE   0x8000
#define MAP_NONBLOCK   0x10000
#define MAP_STACK      0x20000
#define MAP_HUGETLB    0x40000
#define MAP_SYNC       0x80000
#define MAP_FIXED_NOREPLACE 0x100000
#define PROT_NONE      0
#define PROT_READ      1
#define PROT_WRITE     2
#define PROT_EXEC      4
#define PROT_GROWSDOWN 0x01000000
#define PROT_GROWSUP   0x02000000
#define MREMAP_MAYMOVE 1
#define MREMAP_FIXED 2
#define MS_ASYNC  1   
#define MS_INVALIDATE 2   
#define MS_SYNC   4   
#define CLONE_VM  0x00000100
#define CLONE_FS  0x00000200
#define CLONE_FILES 0x00000400
#define CLONE_SIGHAND 0x00000800
#define CLONE_PTRACE  0x00002000
#define CLONE_VFORK 0x00004000
#define CLONE_PARENT  0x00008000
#define CLONE_THREAD  0x00010000
#define CLONE_NEWNS 0x00020000
#define CLONE_SYSVSEM 0x00040000
#define CLONE_SETTLS  0x00080000
#define CLONE_PARENT_SETTID 0x00100000
#define CLONE_CHILD_CLEARTID  0x00200000
#define CLONE_DETACHED  0x00400000
#define CLONE_UNTRACED  0x00800000
#define CLONE_CHILD_SETTID  0x01000000
#define CLONE_NEWCGROUP 0x02000000
#define CLONE_NEWUTS  0x04000000
#define CLONE_NEWIPC  0x08000000
#define CLONE_NEWUSER 0x10000000
#define CLONE_NEWPID  0x20000000
#define CLONE_NEWNET  0x40000000
#define CLONE_IO  0x80000000
#endif
#ifndef vararg_h
#define vararg_h
#define VARARG(A,B) ((A+0) ?: B )
#define SHIFT(A,...) A
#define ARG(A,...) __VA_ARGS__
#endif
#ifndef stdarg_h
#define stdarg_h
#if 1
#if __GNUC__ >= 3
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
#ifdef __GNUC__
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))
#define va_arg(ap, type) ( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))),	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )
#else
#ifdef __x86_64__
#ifndef _WIN64
typedef void *va_list;
va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);
#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type) (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)
#else 
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif
#else 
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED
#endif
#endif
#endif
#endif
#define PATH_MAX 4096
#define FOPEN_MAX 16
#ifndef PASSWDFILE
#define PASSWDFILE "/etc/passwd"
#endif
#ifndef GROUPFILE
#define GROUPFILE "/etc/group"
#endif
#define LOGIN_NAME_MAX 256
#define HOST_NAME_MAX 64
#define MAXGROUPS 128
#define mini_FOPEN_MAX 16
#ifndef ctype_h
#define ctype_h
#define isalpha(a) (0 ? 1 : (((unsigned)(a)|32)-'a') < 26)
#define isdigit(a) (0 ? 1 : ((unsigned)(a)-'0') < 10)
#define islower(a) (0 ? 1 : ((unsigned)(a)-'a') < 26)
#define isupper(a) (0 ? 1 : ((unsigned)(a)-'A') < 26)
#define isprint(a) (0 ? 1 : ((unsigned)(a)-(0x20)) < 0x5f)
#define isgraph(a) (0 ? 1 : ((unsigned)(a)-0x21) < 0x5e)
#define isspace(a) ((a==' ')||(a=='\t')||(a=='\n')||(a=='\f')||(a=='\r')||(a=='\v'))
#define isalnum(a) (isalpha(a) || isdigit(a))
#define _tolower(a) ((a)|0x20)
#define tolower(a) ((a)|0x20)
#define _toupper(a) ((a)&0x5f)
#define toupper(a) ((a)&0x5f)
#define isascii(a) (0 ? isascii(a) : (unsigned)(a) < 128)
#endif
#ifndef minilib_syscall_h
#define minilib_syscall_h
#ifdef mini_vsyscalls
extern int __mini_vsys;
#endif
#ifdef mini_errno
#ifndef mini_globals_on_stack
extern int errno;
#endif
#endif
#ifdef OSX
#define NCONST 0x2000000
#define SCALL(call) SYS_##call
#define __SYSCALL(call) SYS##call
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
#endif 
#else
#define NCONST 0
#define SCALL(call) __NR_##call
#define __SYSCALL(call) __NR##call
#ifdef X64
#else
#ifndef _ASM_X86_UNISTD_32_H
#define _ASM_X86_UNISTD_32_H
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
#define __NR_getrlimit		 76   
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
#define __NR_afs_syscall	137 
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
#define __NR_getpmsg		188	
#define __NR_putpmsg		189	
#define __NR_vfork		190
#define __NR_ugetrlimit		191	
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
#define __NR_madvise1		219	
#define __NR_getdents64		220
#define __NR_fcntl64		221
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
#endif 
#endif
#endif
#ifndef OPTFENCE
static void __attribute__((noipa,cold,naked)) opt_fence(void*p,...){}
#define _optjmp(a,b) asm( a "OPTFENCE_"#b )
#define _optlabel(a) asm( "OPTFENCE_" #a ":" )
#define __optfence(a,...) _optjmp("jmp ", a ); opt_fence(__VA_ARGS__); _optlabel(a)
#define OPTFENCE(...) __optfence(__COUNTER__,__VA_ARGS__)
#endif
#ifdef X64
#define __callend : "memory","rcx", "r11" )
#define __callend0 __callend
#define __callend1 __callend
#define __callend2 __callend
#define __callend3 __callend
#define __callend4 __callend; OPTFENCE((void*)r10)
#define __callend5 __callend; OPTFENCE((void*)r10,(void*)r8)
#define __callend6 __callend; OPTFENCE((void*)r10,(void*)r8,(void*)r9)
#define __SYSCALL_ASM(ret,call) asm volatile ("syscall" : "=a" (ret)  : "a" ( (call | NCONST ) )
#else
#ifdef mini_vsyscalls
#define __SYSCALL_ASM(ret,call) asm volatile ("call *__mini_vsys" : "=a" (ret)  : "a" (call)
#else
#define __callend : "memory" )
#define __SYSCALL_ASM(ret,call) asm volatile ("int $0x80" : "=a" (ret)  : "a" (call)
#endif
#endif
#ifdef X64
#define syscall1(ret,call,a1) __SYSCALL_ASM(ret,call) , "D" (a1) __callend
#define syscall2(ret,call,a1,a2) __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2) __callend
#define syscall3(ret,call,a1,a2,a3) __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3) __callend
#define syscall4(ret,call,a1,a2,a3,a4) register long int r10 asm ("r10") = a4 ; __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "r" (r10) __callend
#define syscall5(ret,call,a1,a2,a3,a4,a5) register long int r10 asm ("r10") = a4 ; register long int r8 asm ("r8") = a5 ; __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "r" (r10), "r" (r8) __callend
#define syscall6(ret,call,a1,a2,a3,a4,a5,a6) register long int r10 asm ("r10") = a4 ; register long int r8 asm ("r8") = a5 ; register long int r9 asm ("r9") = a6; __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "r" (r10), "r" (r8), "r" (r9) __callend
#define syscall0_ret(call) __SYSCALL_ASM(sysret,call)
#define syscall1_ret(call) syscall0_ret(call) , "D" (a1)
#define syscall2_ret(call) syscall1_ret(call) , "S" (a2)
#define syscall3_ret(call) syscall2_ret(call) , "d" (a3)
#define syscall4_ret(call) register long int r10 asm("r10")= a4; syscall3_ret(call) , "r" (r10)
#define syscall5_ret(call) register long int r10 asm("r10")= a4; register long int r8 asm("r8")= a5 ; syscall3_ret(call) , "r" (r8)
#define syscall6_ret(call) register long int r10 asm("r10")= a4; register long int r8 asm("r8")= a5 ; register long int r9 asm("r9")=a6; syscall3_ret(call) , "r" (r8)
#else
#ifndef X64
#define syscall1(ret,call,a1) __SYSCALL_ASM(ret,call) , "b" (a1) __callend
#define syscall2(ret,call,a1,a2) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2) __callend
#define syscall3(ret,call,a1,a2,a3) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3) __callend
#define syscall4(ret,call,a1,a2,a3,a4) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4) __callend
#define syscall5(ret,call,a1,a2,a3,a4,a5) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4), "D" (a5) __callend
#define syscall0_ret(call) __SYSCALL_ASM(sysret,call)
#define syscall1_ret(call) syscall0_ret(call) , "b" (a1)
#define syscall2_ret(call) syscall1_ret(call) , "c" (a2)
#define syscall3_ret(call) syscall2_ret(call) , "d" (a3)
#define syscall4_ret(call) syscall3_ret(call) , "S" (a4)
#define syscall5_ret(call) syscall4_ret(call) , "D" (a5)
#else
#define syscall1(ret,call,a1) __SYSCALL_ASM(ret,call) , "b" (a1) __callend
#define syscall2(ret,call,a1,a2) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2) __callend
#define syscall3(ret,call,a1,a2,a3) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3) __callend
#define syscall4(ret,call,a1,a2,a3,a4) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4) __callend
#define syscall5(ret,call,a1,a2,a3,a4,a5) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4), "D" (a5) __callend
#define syscall0_ret(call) __SYSCALL_ASM(sysret,call)
#define syscall1_ret(call) syscall0_ret(call) , "b" (a1)
#define syscall2_ret(call) syscall1_ret(call) , "c" (a2)
#define syscall3_ret(call) syscall2_ret(call) , "d" (a3)
#define syscall4_ret(call) syscall3_ret(call) , "S" (a4)
#define syscall5_ret(call) syscall4_ret(call) , "D" (a5)
#define syscall6_ret(call) syscall5_ret(call) , "r10" (a6)
#endif
#endif
#define __DO_syscall(n,...) syscall##n##_ret( __VA_ARGS__ ) __callend##n
#ifndef GENSYNTAXCHECK
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
#define REAL_define_syscall_noopt( name, argcount, ... ) \
int volatile  name( __VA_ARGS__ ){\
int sysret;\
__DO_syscall( argcount, (SCALL(name) | NCONST ) );\
if ( sysret<0){\
errno = -sysret;\
return(-1);}\
return(sysret);\
}
#else //errno
#define REAL_define_syscall( name, argcount, ... ) inline \
int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
int sysret;\
__DO_syscall( argcount, ( SCALL(name) | NCONST ) );\
return( sysret );\
}
#define REAL_define_syscall_noopt( name, argcount, ... ) \
int volatile name( __VA_ARGS__ ){\
int sysret;\
__DO_syscall( argcount, ( SCALL(name) | NCONST ) );\
return( sysret );\
}
#endif
#ifdef mini_errno
#define SYSREAL_define_syscall( name, argcount, ... ) inline \
int volatile __attribute__((always_inline)) sys##name( __VA_ARGS__ ){\
int sysret;\
__DO_syscall( argcount, (__SYSCALL(name) | NCONST ) );\
if ( sysret<0){\
errno = -sysret;\
return(-1);}\
return(sysret);\
}
#define SYSREAL_define_syscall_noopt( name, argcount, ... ) \
int volatile sys##name( __VA_ARGS__ ){\
int sysret;\
__DO_syscall( argcount, (__SYSCALL(name) | NCONST ) );\
if ( sysret<0){\
errno = -sysret;\
return(-1);}\
return(sysret);\
}
#else
#define SYSREAL_define_syscall( name, argcount, ... ) inline \
int volatile __attribute__((always_inline)) sys##name( __VA_ARGS__ ){\
int sysret;\
__DO_syscall( argcount, ( __SYSCALL(name) | NCONST ) );\
return( sysret );\
}
#define SYSREAL_define_syscall_noopt( name, argcount, ... ) \
int volatile sys##name( __VA_ARGS__ ){\
int sysret;\
__DO_syscall( argcount, ( __SYSCALL(name) | NCONST ) );\
return( sysret );\
}
#endif
#ifdef mini_errno
#define REAL_define_syscallret( name, ret, argcount, ... ) inline \
int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
int sysret;\
__DO_syscall( argcount, SCALL(name));\
if ( sysret<0 ){\
errno = -sysret;\
return(-1);}\
return(ret);\
}
#else
#define REAL_define_syscallret( name, ret, argcount, ... ) inline \
int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
int sysret;\
__DO_syscall( argcount, SCALL(name));\
if ( sysret<0 ){\
return(sysret);}\
return(ret);\
}
#endif
#define DEF_syscall(...)
#define DEF_syscallret(...)
#else //ifndef gensyntaxcheck
#define DEF_syscall( name, argcount, ... ) int volatile name( __VA_ARGS__ );
#define DEF_syscallret( name, ret, argcount, ... ) int volatile name( __VA_ARGS__ );
#define SYSDEF_syscall( name, argcount, ... ) int volatile sys##name( __VA_ARGS__ );
#define REAL_define_syscall(...)
#define REAL_define_syscall_noopt(...)
#define REAL_define_syscallret(...)
#define SYSREAL_define_syscall(...)
#define SYSREAL_define_syscall_noopt(...)
#endif
#endif
#ifdef mini_GETOPTS
#ifndef mini_getoptm_h
#define mini_getoptm_h
#define DEF_OPTIONS_ENUM_short enum MINI_OPTIONS_short { a=0x1,b=0x2,c=0x4,d=0x8,e=0x10,f=0x20,g=0x40,h=0x80,i=0x100,j=0x200,\
k=0x400,l=0x800,m=0x1000,n=0x2000,o=0x4000,p=0x8000,q=0x10000,r=0x20000,s=0x40000,\
t=0x80000,u=0x100000,v=0x200000,w=0x400000,x=0x800000,y=0x1000000,z=0x2000000 };
#define PARSEOPTS_short( opts, argv, options, unrecognized ) ({\
DEF_OPTIONS_ENUM_short;\
int argp=1;\
for ( int ap=1; argv[ap]; ap++ ){\
if ( argv[ap][0] == '-' ){\
argp = ap+1;\
for ( int b=1; argv[ap][b]; b++ ){\
int ti; char option;\
opts |= (ti=1<< ((option=argv[ap][b])-97) );\
if ( ! ( (options) & ti ) ){\
unrecognized;\
}\
}\
}\
}\
argp;\
} )
#define GETOPT_short( opts, option ) ({\
DEF_OPTIONS_ENUM_short;\
opts & option;\
} )
#define SETOPT_short( opts, option ) ({\
DEF_OPTIONS_ENUM_short;\
opts = (opts | option);\
} )
#endif
#endif
struct udiv_t { unsigned int quot, rem; };
#ifdef mini_getopt
#define mini_prints
#define mini_strcmp
#define mini_strchr
#endif
#ifndef itodec
#ifdef printf
#warning printf defined, but no int conversion (%d). Consider defining mini_itodec
#endif
#ifdef fprintf
#warning fprintf defined, but no int conversion (%d). Consider defining mini_itodec
#endif
#endif
#ifdef mini_perror
#endif
#ifndef mini_errno_h
#define mini_errno_h
#define EPERM            1
#ifndef ENOENT
#define ENOENT           2
#endif
#define ESRCH            3
#define EINTR            4
#define EIO              5
#define ENXIO            6
#define E2BIG            7
#define ENOEXEC          8
#define EBADF            9
#define ECHILD          10
#define EAGAIN          11
#define ENOMEM          12
#define EACCES          13
#define EFAULT          14
#define ENOTBLK         15
#define EBUSY           16
#define EEXIST          17
#define EXDEV           18
#define ENODEV          19
#define ENOTDIR         20
#define EISDIR          21
#define EINVAL          22
#define ENFILE          23
#define EMFILE          24
#define ENOTTY          25
#define ETXTBSY         26
#define EFBIG           27
#define ENOSPC          28
#define ESPIPE          29
#define EROFS           30
#define EMLINK          31
#define EPIPE           32
#define EDOM            33
#define ERANGE          34
#define EDEADLK         35
#define ENAMETOOLONG    36
#define ENOLCK          37
#define ENOSYS          38
#define ENOTEMPTY       39
#define ELOOP           40
#define EWOULDBLOCK     EAGAIN
#define ENOMSG          42
#define EIDRM           43
#define ECHRNG          44
#define EL2NSYNC        45
#define EL3HLT          46
#define EL3RST          47
#define ELNRNG          48
#define EUNATCH         49
#define ENOCSI          50
#define EL2HLT          51
#define EBADE           52
#define EBADR           53
#define EXFULL          54
#define ENOANO          55
#define EBADRQC         56
#define EBADSLT         57
#define EDEADLOCK       EDEADLK
#define EBFONT          59
#define ENOSTR          60
#define ENODATA         61
#define ETIME           62
#define ENOSR           63
#define ENONET          64
#define ENOPKG          65
#define EREMOTE         66
#define ENOLINK         67
#define EADV            68
#define ESRMNT          69
#define ECOMM           70
#define EPROTO          71
#define EMULTIHOP       72
#define EDOTDOT         73
#define EBADMSG         74
#define EOVERFLOW       75
#define ENOTUNIQ        76
#define EBADFD          77
#define EREMCHG         78
#define ELIBACC         79
#define ELIBBAD         80
#define ELIBSCN         81
#define ELIBMAX         82
#define ELIBEXEC        83
#define EILSEQ          84
#define ERESTART        85
#define ESTRPIPE        86
#define EUSERS          87
#define ENOTSOCK        88
#define EDESTADDRREQ    89
#define EMSGSIZE        90
#define EPROTOTYPE      91
#define ENOPROTOOPT     92
#define EPROTONOSUPPORT 93
#define ESOCKTNOSUPPORT 94
#define EOPNOTSUPP      95
#define ENOTSUP         EOPNOTSUPP
#define EPFNOSUPPORT    96
#define EAFNOSUPPORT    97
#define EADDRINUSE      98
#define EADDRNOTAVAIL   99
#define ENETDOWN        100
#define ENETUNREACH     101
#define ENETRESET       102
#define ECONNABORTED    103
#define ECONNRESET      104
#define ENOBUFS         105
#define EISCONN         106
#define ENOTCONN        107
#define ESHUTDOWN       108
#define ETOOMANYREFS    109
#define ETIMEDOUT       110
#define ECONNREFUSED    111
#define EHOSTDOWN       112
#define EHOSTUNREACH    113
#define EALREADY        114
#define EINPROGRESS     115
#define ESTALE          116
#define EUCLEAN         117
#define ENOTNAM         118
#define ENAVAIL         119
#define EISNAM          120
#define EREMOTEIO       121
#define EDQUOT          122
#define ENOMEDIUM       123
#define EMEDIUMTYPE     124
#define ECANCELED       125
#define ENOKEY          126
#define EKEYEXPIRED     127
#define EKEYREVOKED     128
#define EKEYREJECTED    129
#define EOWNERDEAD      130
#define ENOTRECOVERABLE 131
#define ERFKILL         132
#ifndef mini_globals_on_stack
extern int errno;
#endif
#endif
#ifdef mini_dtodec
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif
#ifdef mini_unmap_protected
#ifndef mini_munmap
#define mini_munmap
#endif
#ifndef mini_mprotect
#define mini_mprotect
#endif
#endif
#ifdef mini_fwrite
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_setenv
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_strncmp
#define mini_strncmp
#endif
#ifndef mini_ret_errno
#define mini_ret_errno
#endif
#ifndef mini_malloc
#define mini_malloc
#endif
#ifndef mini_strcpy
#define mini_strcpy
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_dief_if
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_ewritesl
#define mini_ewritesl
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini_die
#define mini_die
#endif
#endif
#ifdef mini_putchar
#ifndef mini_fputc
#define mini_fputc
#endif
#endif
#ifdef mini_ftell
#ifndef mini_lseek
#define mini_lseek
#endif
#endif
#ifdef mini_fopen
#ifndef mini_open
#define mini_open
#endif
#ifndef mini__fopen
#define mini__fopen
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_die_if
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_ewritesl
#define mini_ewritesl
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini_die
#define mini_die
#endif
#endif
#ifdef mini_error
#ifndef mini_strerror
#define mini_strerror
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fprints
#define mini_fprints
#endif
#endif
#ifdef mini_writesl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_putc
#ifndef mini_fputc
#define mini_fputc
#endif
#endif
#ifdef mini_gets
#ifndef mini_fgets
#define mini_fgets
#endif
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
#ifdef mini_fgetpos
#ifndef mini_ftell
#define mini_ftell
#endif
#endif
#ifdef mini_dies_if
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini_dies
#define mini_dies
#endif
#endif
#ifdef mini_userdb_open
#ifndef mini_globals
#define mini_globals
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_fstat
#define mini_fstat
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_vsprintf
#ifndef mini_0
#define mini_0
#endif
#endif
#ifdef mini_alphasort
#ifndef mini_strcmp
#define mini_strcmp
#endif
#endif
#ifdef mini_execl
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_execve
#define mini_execve
#endif
#endif
#ifdef mini_abort
#ifndef mini_raise
#define mini_raise
#endif
#ifndef mini_signal
#define mini_signal
#endif
#endif
#ifdef mini_realloc
#ifndef mini_free
#define mini_free
#endif
#ifndef mini_malloc
#define mini_malloc
#endif
#endif
#ifdef mini_strcat
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_endgrent
#ifndef mini_munmap
#define mini_munmap
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini_grantpt
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_fstat
#define mini_fstat
#endif
#ifndef mini_ptsname
#define mini_ptsname
#endif
#endif
#ifdef mini_usleep
#ifndef mini_nanosleep
#define mini_nanosleep
#endif
#endif
#ifdef mini_group_printf
#ifndef mini_printf
#define mini_printf
#endif
#ifndef mini_eprintf
#define mini_eprintf
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_ltodec
#define mini_ltodec
#endif
#ifndef mini_uitodec
#define mini_uitodec
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_atoi
#define mini_atoi
#endif
#ifndef mini_itohex
#define mini_itohex
#endif
#ifndef mini_uitohex
#define mini_uitohex
#endif
#ifndef mini_itoHEX
#define mini_itoHEX
#endif
#ifndef mini_uitoHEX
#define mini_uitoHEX
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini_globals
#define mini_globals
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_sprintf
#define mini_sprintf
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#ifndef mini_itooct
#define mini_itooct
#endif
#endif
#ifdef mini_fprints
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
#ifdef mini_getgrent
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_userdb
#define mini_userdb
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini_sleep
#ifndef mini_nanosleep
#define mini_nanosleep
#endif
#endif
#ifdef mini_closedir
#ifndef mini_free
#define mini_free
#endif
#endif
#ifdef mini_isatty
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_tcgetattr
#define mini_tcgetattr
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif
#ifdef mini_itohex
#ifndef mini__itohex
#define mini__itohex
#endif
#endif
#ifdef mini_group_write
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_ewrite
#define mini_ewrite
#endif
#ifndef mini_writes
#define mini_writes
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_fwrites
#define mini_fwrites
#endif
#ifndef mini_ewritesl
#define mini_ewritesl
#endif
#ifndef mini_writesl
#define mini_writesl
#endif
#endif
#ifdef mini_warn
#ifndef mini_fprintf
#define mini_fprintf
#endif
#endif
#ifdef mini_putenv
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_strncmp
#define mini_strncmp
#endif
#ifndef mini_ret_errno
#define mini_ret_errno
#endif
#endif
#ifdef mini_tcsetattr
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif
#ifdef mini_itobin
#ifndef mini__itobin
#define mini__itobin
#endif
#endif
#ifdef mini_errx
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#endif
#ifdef mini_strncmp
#ifndef mini__strcmp
#define mini__strcmp
#endif
#endif
#ifdef mini_htons
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_print
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_memcmp
#ifndef mini_0
#define mini_0
#endif
#endif
#ifdef mini_execvp
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_execvpe
#define mini_execvpe
#endif
#ifndef mini_access
#define mini_access
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_access
#define mini_access
#endif
#endif
#ifdef mini_match
#ifndef mini__match
#define mini__match
#endif
#endif
#ifdef mini_fgetsn
#ifndef mini_fgetc
#define mini_fgetc
#endif
#endif
#ifdef mini__fopen
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_setbrk
#ifndef mini_brk
#define mini_brk
#endif
#endif
#ifdef mini_printl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_opendir
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_close
#define mini_close
#endif
#ifndef mini_malloc
#define mini_malloc
#endif
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#ifndef mini_opendirp
#define mini_opendirp
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_free
#define mini_free
#endif
#endif
#ifdef mini_printsl
#ifndef mini__mprints
#define mini__mprints
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini__strcasecmp
#ifndef mini_tolower
#define mini_tolower
#endif
#endif
#ifdef mini_getgrnam
#ifndef mini_grent
#define mini_grent
#endif
#ifndef mini_setgrent
#define mini_setgrent
#endif
#ifndef mini_getgrent
#define mini_getgrent
#endif
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_userdb_open
#define mini_userdb_open
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_token_s
#define mini_token_s
#endif
#ifndef mini_token_i
#define mini_token_i
#endif
#endif
#ifdef mini_dprints
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_strcasecmp
#ifndef mini__strcasecmp
#define mini__strcasecmp
#endif
#endif
#ifdef mini_strcmp
#ifndef mini__strcmp
#define mini__strcmp
#endif
#endif
#ifdef mini_freopen
#ifndef mini_open
#define mini_open
#endif
#ifndef mini__fopen
#define mini__fopen
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_eprintl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_signal
#ifndef mini_sigaction
#define mini_sigaction
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_rt_sigaction
#define mini_rt_sigaction
#endif
#endif
#ifdef mini_eprintsl
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_execvpe
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_access
#define mini_access
#endif
#endif
#ifdef mini_free
#ifndef mini_brk
#define mini_brk
#endif
#ifndef mini_getbrk
#define mini_getbrk
#endif
#endif
#ifdef mini_group_print
#ifndef mini_print
#define mini_print
#endif
#ifndef mini_prints
#define mini_prints
#endif
#ifndef mini_printsl
#define mini_printsl
#endif
#ifndef mini_printl
#define mini_printl
#endif
#ifndef mini_eprint
#define mini_eprint
#endif
#ifndef mini_eprintl
#define mini_eprintl
#endif
#ifndef mini_eprintsl
#define mini_eprintsl
#endif
#ifndef mini_eprints
#define mini_eprints
#endif
#ifndef mini_printfs
#define mini_printfs
#endif
#ifndef mini_eprintfs
#define mini_eprintfs
#endif
#ifndef mini_puts
#define mini_puts
#endif
#ifndef mini_eputs
#define mini_eputs
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini__mprints
#define mini__mprints
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_strdup
#ifndef mini_malloc
#define mini_malloc
#endif
#ifndef mini_strcpy
#define mini_strcpy
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_tcgetattr
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif
#ifdef mini_atexit
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_ptsname_r
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_sprintf
#define mini_sprintf
#endif
#endif
#ifdef mini_fgetsp
#ifndef mini_fgetc
#define mini_fgetc
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
#ifdef mini_inet_aton
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_raise
#ifndef mini_getpid
#define mini_getpid
#endif
#ifndef mini_kill
#define mini_kill
#endif
#endif
#ifdef mini_getgroups
#ifndef mini_getpwuid
#define mini_getpwuid
#endif
#ifndef mini_setgrent
#define mini_setgrent
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_grent
#define mini_grent
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#ifndef mini_getusergroups
#define mini_getusergroups
#endif
#ifndef mini_getuid
#define mini_getuid
#endif
#endif
#ifdef mini_opendirp
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_close
#define mini_close
#endif
#ifndef mini_malloc
#define mini_malloc
#endif
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#ifndef mini_free
#define mini_free
#endif
#endif
#ifdef mini_eprints
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_getpwuid
#ifndef mini_pwent
#define mini_pwent
#endif
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_passwdfile_open
#define mini_passwdfile_open
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_token_s
#define mini_token_s
#endif
#ifndef mini_token_i
#define mini_token_i
#endif
#ifndef mini_setpwent
#define mini_setpwent
#endif
#endif
#ifdef mini_vsnprintf
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_printfs
#ifndef mini_fprintfs
#define mini_fprintfs
#endif
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_fseek
#ifndef mini_lseek
#define mini_lseek
#endif
#endif
#ifdef mini_itodec
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif
#ifdef mini_getgrouplist
#ifndef mini_getusergroups
#define mini_getusergroups
#endif
#endif
#ifdef mini_waitpid
#ifndef mini_wait4
#define mini_wait4
#endif
#endif
#ifdef mini_fprint
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_writes
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_map_protected
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_mprotect
#define mini_mprotect
#endif
#endif
#ifdef mini_wait
#ifndef mini_wait4
#define mini_wait4
#endif
#endif
#ifdef mini_sigaction
#ifndef mini_memcpy
#define mini_memcpy
#endif
#ifndef mini_rt_sigaction
#define mini_rt_sigaction
#endif
#endif
#ifdef mini_err
#ifndef mini_strerror
#define mini_strerror
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_errno
#define mini_errno
#endif
#ifndef mini_fprints
#define mini_fprints
#endif
#endif
#ifdef mini_sigsuspend
#ifndef mini_rt_sigsuspend
#define mini_rt_sigsuspend
#endif
#endif
#ifdef mini_malloc
#ifndef mini_0
#define mini_0
#endif
#endif
#ifdef mini_fwritesl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_vexec
#ifndef mini_seterrno
#define mini_seterrno
#endif
#ifndef mini_waitpid
#define mini_waitpid
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_vfork
#define mini_vfork
#endif
#endif
#ifdef mini_strchr
#ifndef mini_strchrnul
#define mini_strchrnul
#endif
#endif
#ifdef mini_scandir
#ifndef mini_errno
#define mini_errno
#endif
#ifndef mini_malloc_brk
#define mini_malloc_brk
#endif
#ifndef mini_realloc
#define mini_realloc
#endif
#ifndef mini_free
#define mini_free
#endif
#ifndef mini_memcpy
#define mini_memcpy
#endif
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#ifndef mini_seterrno
#define mini_seterrno
#endif
#ifndef mini_getbrk
#define mini_getbrk
#endif
#ifndef mini_sbrk
#define mini_sbrk
#endif
#ifndef mini_prints
#define mini_prints
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_sprintf
#define mini_sprintf
#endif
#ifndef mini_qsort
#define mini_qsort
#endif
#endif
#ifdef mini_dies
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini__die
#define mini__die
#endif
#ifndef mini_eprintsl
#define mini_eprintsl
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_getpwent
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_userdb
#define mini_userdb
#endif
#endif
#ifdef mini_strncasecmp
#ifndef mini__strcasecmp
#define mini__strcasecmp
#endif
#endif
#ifdef mini_getenv
#ifndef mini_environ
#define mini_environ
#endif
#endif
#ifdef mini_match_ext2
#ifndef mini__match_ext2
#define mini__match_ext2
#endif
#endif
#ifdef mini_getusergroups
#ifndef mini_getpwuid
#define mini_getpwuid
#endif
#ifndef mini_setgrent
#define mini_setgrent
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_grent
#define mini_grent
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini_vfprintf
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_dief
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini__die
#define mini__die
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#endif
#ifdef mini_fclose
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_fputc
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_fprintfs
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_getgrgid
#ifndef mini_grent
#define mini_grent
#endif
#ifndef mini_setgrent
#define mini_setgrent
#endif
#ifndef mini_getgrent
#define mini_getgrent
#endif
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_userdb_open
#define mini_userdb_open
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_token_s
#define mini_token_s
#endif
#ifndef mini_token_i
#define mini_token_i
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini_rewind
#ifndef mini_fseek
#define mini_fseek
#endif
#endif
#ifdef mini_fprintf
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
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_fputs
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
#ifdef mini_fread
#ifndef mini_read
#define mini_read
#endif
#endif
#ifdef mini_fwrites
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_endpwent
#ifndef mini_munmap
#define mini_munmap
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini__mprints
#ifndef mini_dprints
#define mini_dprints
#endif
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_die
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_ewritesl
#define mini_ewritesl
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini__die
#define mini__die
#endif
#endif
#ifdef mini_eprint
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_creat
#ifndef mini_open
#define mini_open
#endif
#endif
#ifdef mini_sprintf
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_printf
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_fsetpos
#ifndef mini_lseek
#define mini_lseek
#endif
#endif
#ifdef mini_prints
#ifndef mini__mprints
#define mini__mprints
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_dirname
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_strrchr
#ifndef mini_strchrnul
#define mini_strchrnul
#endif
#endif
#ifdef mini_getpwnam
#ifndef mini_pwent
#define mini_pwent
#endif
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_userdb_open
#define mini_userdb_open
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_token_s
#define mini_token_s
#endif
#ifndef mini_token_i
#define mini_token_i
#endif
#endif
#ifdef mini_posix_openpt
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_open
#define mini_open
#endif
#endif
#ifdef mini_ptsname
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_ptsname_r
#define mini_ptsname_r
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#ifndef mini_sprintf
#define mini_sprintf
#endif
#endif
#ifdef mini_ewritesl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_htonl
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_dprintf
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#endif
#ifdef mini_fgetc
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_read
#define mini_read
#endif
#endif
#ifdef mini_cfmakeraw
#ifndef mini_termio
#define mini_termio
#endif
#endif
#ifdef mini_fgets
#ifndef mini_fgetc
#define mini_fgetc
#endif
#endif
#ifdef mini_malloc_brk
#ifndef mini_sbrk
#define mini_sbrk
#endif
#ifndef mini_getbrk
#define mini_getbrk
#endif
#endif
#ifdef mini_sigprocmask
#ifndef mini_rt_sigprocmask
#define mini_rt_sigprocmask
#endif
#endif
#ifdef mini_exit_errno
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#endif
#ifdef mini_perror
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_strerror
#define mini_strerror
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini_errno
#define mini_errno
#endif
#endif
#ifdef mini_getchar
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
#ifdef mini_term_width
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_environ
#define mini_environ
#endif
#endif
#ifdef mini_fgetul
#ifndef mini_fgetc
#define mini_fgetc
#endif
#endif
#ifdef mini_inet_ntoa
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_vexec_q
#ifndef mini_seterrno
#define mini_seterrno
#endif
#ifndef mini_waitpid
#define mini_waitpid
#endif
#ifndef mini_vfork
#define mini_vfork
#endif
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_exit
#define mini_exit
#endif
#endif
#ifdef mini_snprintfs
#ifndef mini_0
#define mini_0
#endif
#endif
#ifdef mini_fdopen
#ifndef mini_open
#define mini_open
#endif
#ifndef mini__fopen
#define mini__fopen
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_fgetud
#ifndef mini_fgetc
#define mini_fgetc
#endif
#endif
#ifdef mini_gethostname
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_eprintf
#ifndef mini_fprintfs
#define mini_fprintfs
#endif
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_itoHEX
#ifndef mini__itohex
#define mini__itohex
#endif
#endif
#ifdef mini_unlockpt
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif
#ifdef mini_eputs
#ifndef mini_eprintl
#define mini_eprintl
#endif
#ifndef mini_eprint
#define mini_eprint
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_ewrites
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_system
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_vfork
#define mini_vfork
#endif
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_waitpid
#define mini_waitpid
#endif
#endif
#ifdef mini_readdir
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#ifndef mini_getdents
#define mini_getdents
#endif
#endif
#ifdef mini_execv
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_execve
#define mini_execve
#endif
#endif
#ifdef mini_getc
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
#ifdef mini_eprintfs
#ifndef mini_fprintfs
#define mini_fprintfs
#endif
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_puts
#ifndef mini_printl
#define mini_printl
#endif
#ifndef mini_print
#define mini_print
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_printf
#define mini_printf
#endif
#endif
#ifdef mini_dtodec
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif
#ifdef mini_unmap_protected
#ifndef mini_munmap
#define mini_munmap
#endif
#ifndef mini_mprotect
#define mini_mprotect
#endif
#endif
#ifdef mini_fwrite
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_setenv
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_strncmp
#define mini_strncmp
#endif
#ifndef mini_ret_errno
#define mini_ret_errno
#endif
#ifndef mini_malloc
#define mini_malloc
#endif
#ifndef mini_strcpy
#define mini_strcpy
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_dief_if
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_ewritesl
#define mini_ewritesl
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini_die
#define mini_die
#endif
#endif
#ifdef mini_putchar
#ifndef mini_fputc
#define mini_fputc
#endif
#endif
#ifdef mini_ftell
#ifndef mini_lseek
#define mini_lseek
#endif
#endif
#ifdef mini_fopen
#ifndef mini_open
#define mini_open
#endif
#ifndef mini__fopen
#define mini__fopen
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_die_if
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_ewritesl
#define mini_ewritesl
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini_die
#define mini_die
#endif
#endif
#ifdef mini_error
#ifndef mini_strerror
#define mini_strerror
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fprints
#define mini_fprints
#endif
#endif
#ifdef mini_writesl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_putc
#ifndef mini_fputc
#define mini_fputc
#endif
#endif
#ifdef mini_gets
#ifndef mini_fgets
#define mini_fgets
#endif
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
#ifdef mini_fgetpos
#ifndef mini_ftell
#define mini_ftell
#endif
#endif
#ifdef mini_dies_if
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini_dies
#define mini_dies
#endif
#endif
#ifdef mini_userdb_open
#ifndef mini_globals
#define mini_globals
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_fstat
#define mini_fstat
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_vsprintf
#ifndef mini_0
#define mini_0
#endif
#endif
#ifdef mini_alphasort
#ifndef mini_strcmp
#define mini_strcmp
#endif
#endif
#ifdef mini_execl
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_execve
#define mini_execve
#endif
#endif
#ifdef mini_abort
#ifndef mini_raise
#define mini_raise
#endif
#ifndef mini_signal
#define mini_signal
#endif
#endif
#ifdef mini_realloc
#ifndef mini_free
#define mini_free
#endif
#ifndef mini_malloc
#define mini_malloc
#endif
#endif
#ifdef mini_strcat
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_endgrent
#ifndef mini_munmap
#define mini_munmap
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini_grantpt
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_fstat
#define mini_fstat
#endif
#ifndef mini_ptsname
#define mini_ptsname
#endif
#endif
#ifdef mini_usleep
#ifndef mini_nanosleep
#define mini_nanosleep
#endif
#endif
#ifdef mini_group_printf
#ifndef mini_printf
#define mini_printf
#endif
#ifndef mini_eprintf
#define mini_eprintf
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_ltodec
#define mini_ltodec
#endif
#ifndef mini_uitodec
#define mini_uitodec
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_atoi
#define mini_atoi
#endif
#ifndef mini_itohex
#define mini_itohex
#endif
#ifndef mini_uitohex
#define mini_uitohex
#endif
#ifndef mini_itoHEX
#define mini_itoHEX
#endif
#ifndef mini_uitoHEX
#define mini_uitoHEX
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini_globals
#define mini_globals
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_sprintf
#define mini_sprintf
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#ifndef mini_itooct
#define mini_itooct
#endif
#endif
#ifdef mini_fprints
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
#ifdef mini_getgrent
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_userdb
#define mini_userdb
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini_sleep
#ifndef mini_nanosleep
#define mini_nanosleep
#endif
#endif
#ifdef mini_closedir
#ifndef mini_free
#define mini_free
#endif
#endif
#ifdef mini_isatty
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_tcgetattr
#define mini_tcgetattr
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif
#ifdef mini_itohex
#ifndef mini__itohex
#define mini__itohex
#endif
#endif
#ifdef mini_group_write
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_ewrite
#define mini_ewrite
#endif
#ifndef mini_writes
#define mini_writes
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_fwrites
#define mini_fwrites
#endif
#ifndef mini_ewritesl
#define mini_ewritesl
#endif
#ifndef mini_writesl
#define mini_writesl
#endif
#endif
#ifdef mini_warn
#ifndef mini_fprintf
#define mini_fprintf
#endif
#endif
#ifdef mini_putenv
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_strncmp
#define mini_strncmp
#endif
#ifndef mini_ret_errno
#define mini_ret_errno
#endif
#endif
#ifdef mini_tcsetattr
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif
#ifdef mini_itobin
#ifndef mini__itobin
#define mini__itobin
#endif
#endif
#ifdef mini_errx
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#endif
#ifdef mini_strncmp
#ifndef mini__strcmp
#define mini__strcmp
#endif
#endif
#ifdef mini_htons
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_print
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_memcmp
#ifndef mini_0
#define mini_0
#endif
#endif
#ifdef mini_execvp
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_execvpe
#define mini_execvpe
#endif
#ifndef mini_access
#define mini_access
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_access
#define mini_access
#endif
#endif
#ifdef mini_match
#ifndef mini__match
#define mini__match
#endif
#endif
#ifdef mini_fgetsn
#ifndef mini_fgetc
#define mini_fgetc
#endif
#endif
#ifdef mini__fopen
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_setbrk
#ifndef mini_brk
#define mini_brk
#endif
#endif
#ifdef mini_printl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_opendir
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_close
#define mini_close
#endif
#ifndef mini_malloc
#define mini_malloc
#endif
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#ifndef mini_opendirp
#define mini_opendirp
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_free
#define mini_free
#endif
#endif
#ifdef mini_printsl
#ifndef mini__mprints
#define mini__mprints
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini__strcasecmp
#ifndef mini_tolower
#define mini_tolower
#endif
#endif
#ifdef mini_getgrnam
#ifndef mini_grent
#define mini_grent
#endif
#ifndef mini_setgrent
#define mini_setgrent
#endif
#ifndef mini_getgrent
#define mini_getgrent
#endif
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_userdb_open
#define mini_userdb_open
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_token_s
#define mini_token_s
#endif
#ifndef mini_token_i
#define mini_token_i
#endif
#endif
#ifdef mini_dprints
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_strcasecmp
#ifndef mini__strcasecmp
#define mini__strcasecmp
#endif
#endif
#ifdef mini_strcmp
#ifndef mini__strcmp
#define mini__strcmp
#endif
#endif
#ifdef mini_freopen
#ifndef mini_open
#define mini_open
#endif
#ifndef mini__fopen
#define mini__fopen
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_eprintl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_signal
#ifndef mini_sigaction
#define mini_sigaction
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_rt_sigaction
#define mini_rt_sigaction
#endif
#endif
#ifdef mini_eprintsl
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_execvpe
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_access
#define mini_access
#endif
#endif
#ifdef mini_free
#ifndef mini_brk
#define mini_brk
#endif
#ifndef mini_getbrk
#define mini_getbrk
#endif
#endif
#ifdef mini_group_print
#ifndef mini_print
#define mini_print
#endif
#ifndef mini_prints
#define mini_prints
#endif
#ifndef mini_printsl
#define mini_printsl
#endif
#ifndef mini_printl
#define mini_printl
#endif
#ifndef mini_eprint
#define mini_eprint
#endif
#ifndef mini_eprintl
#define mini_eprintl
#endif
#ifndef mini_eprintsl
#define mini_eprintsl
#endif
#ifndef mini_eprints
#define mini_eprints
#endif
#ifndef mini_printfs
#define mini_printfs
#endif
#ifndef mini_eprintfs
#define mini_eprintfs
#endif
#ifndef mini_puts
#define mini_puts
#endif
#ifndef mini_eputs
#define mini_eputs
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini__mprints
#define mini__mprints
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_strdup
#ifndef mini_malloc
#define mini_malloc
#endif
#ifndef mini_strcpy
#define mini_strcpy
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_tcgetattr
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif
#ifdef mini_atexit
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_ptsname_r
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_sprintf
#define mini_sprintf
#endif
#endif
#ifdef mini_fgetsp
#ifndef mini_fgetc
#define mini_fgetc
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
#ifdef mini_inet_aton
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_raise
#ifndef mini_getpid
#define mini_getpid
#endif
#ifndef mini_kill
#define mini_kill
#endif
#endif
#ifdef mini_getgroups
#ifndef mini_getpwuid
#define mini_getpwuid
#endif
#ifndef mini_setgrent
#define mini_setgrent
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_grent
#define mini_grent
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#ifndef mini_getusergroups
#define mini_getusergroups
#endif
#ifndef mini_getuid
#define mini_getuid
#endif
#endif
#ifdef mini_opendirp
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_close
#define mini_close
#endif
#ifndef mini_malloc
#define mini_malloc
#endif
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#ifndef mini_free
#define mini_free
#endif
#endif
#ifdef mini_eprints
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_getpwuid
#ifndef mini_pwent
#define mini_pwent
#endif
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_passwdfile_open
#define mini_passwdfile_open
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_token_s
#define mini_token_s
#endif
#ifndef mini_token_i
#define mini_token_i
#endif
#ifndef mini_setpwent
#define mini_setpwent
#endif
#endif
#ifdef mini_vsnprintf
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_printfs
#ifndef mini_fprintfs
#define mini_fprintfs
#endif
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_fseek
#ifndef mini_lseek
#define mini_lseek
#endif
#endif
#ifdef mini_itodec
#ifndef mini_uitodec
#define mini_uitodec
#endif
#endif
#ifdef mini_getgrouplist
#ifndef mini_getusergroups
#define mini_getusergroups
#endif
#endif
#ifdef mini_waitpid
#ifndef mini_wait4
#define mini_wait4
#endif
#endif
#ifdef mini_fprint
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_writes
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_map_protected
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_mprotect
#define mini_mprotect
#endif
#endif
#ifdef mini_wait
#ifndef mini_wait4
#define mini_wait4
#endif
#endif
#ifdef mini_sigaction
#ifndef mini_memcpy
#define mini_memcpy
#endif
#ifndef mini_rt_sigaction
#define mini_rt_sigaction
#endif
#endif
#ifdef mini_err
#ifndef mini_strerror
#define mini_strerror
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_errno
#define mini_errno
#endif
#ifndef mini_fprints
#define mini_fprints
#endif
#endif
#ifdef mini_sigsuspend
#ifndef mini_rt_sigsuspend
#define mini_rt_sigsuspend
#endif
#endif
#ifdef mini_malloc
#ifndef mini_0
#define mini_0
#endif
#endif
#ifdef mini_fwritesl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_vexec
#ifndef mini_seterrno
#define mini_seterrno
#endif
#ifndef mini_waitpid
#define mini_waitpid
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_vfork
#define mini_vfork
#endif
#endif
#ifdef mini_strchr
#ifndef mini_strchrnul
#define mini_strchrnul
#endif
#endif
#ifdef mini_scandir
#ifndef mini_errno
#define mini_errno
#endif
#ifndef mini_malloc_brk
#define mini_malloc_brk
#endif
#ifndef mini_realloc
#define mini_realloc
#endif
#ifndef mini_free
#define mini_free
#endif
#ifndef mini_memcpy
#define mini_memcpy
#endif
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#ifndef mini_seterrno
#define mini_seterrno
#endif
#ifndef mini_getbrk
#define mini_getbrk
#endif
#ifndef mini_sbrk
#define mini_sbrk
#endif
#ifndef mini_prints
#define mini_prints
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_sprintf
#define mini_sprintf
#endif
#ifndef mini_qsort
#define mini_qsort
#endif
#endif
#ifdef mini_dies
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini__die
#define mini__die
#endif
#ifndef mini_eprintsl
#define mini_eprintsl
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_getpwent
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_userdb
#define mini_userdb
#endif
#endif
#ifdef mini_strncasecmp
#ifndef mini__strcasecmp
#define mini__strcasecmp
#endif
#endif
#ifdef mini_getenv
#ifndef mini_environ
#define mini_environ
#endif
#endif
#ifdef mini_match_ext2
#ifndef mini__match_ext2
#define mini__match_ext2
#endif
#endif
#ifdef mini_getusergroups
#ifndef mini_getpwuid
#define mini_getpwuid
#endif
#ifndef mini_setgrent
#define mini_setgrent
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_grent
#define mini_grent
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini_vfprintf
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_dief
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini__die
#define mini__die
#endif
#ifndef mini_fprintf
#define mini_fprintf
#endif
#endif
#ifdef mini_fclose
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_fputc
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_fprintfs
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_getgrgid
#ifndef mini_grent
#define mini_grent
#endif
#ifndef mini_setgrent
#define mini_setgrent
#endif
#ifndef mini_getgrent
#define mini_getgrent
#endif
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_userdb_open
#define mini_userdb_open
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_token_s
#define mini_token_s
#endif
#ifndef mini_token_i
#define mini_token_i
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini_rewind
#ifndef mini_fseek
#define mini_fseek
#endif
#endif
#ifdef mini_fprintf
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
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_fputs
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
#ifdef mini_fread
#ifndef mini_read
#define mini_read
#endif
#endif
#ifdef mini_fwrites
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_endpwent
#ifndef mini_munmap
#define mini_munmap
#endif
#ifndef mini_pwent
#define mini_pwent
#endif
#endif
#ifdef mini__mprints
#ifndef mini_dprints
#define mini_dprints
#endif
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_die
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_ewritesl
#define mini_ewritesl
#endif
#ifndef mini_exit_errno
#define mini_exit_errno
#endif
#ifndef mini__die
#define mini__die
#endif
#endif
#ifdef mini_eprint
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_creat
#ifndef mini_open
#define mini_open
#endif
#endif
#ifdef mini_sprintf
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_printf
#ifndef mini_fprintf
#define mini_fprintf
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_fsetpos
#ifndef mini_lseek
#define mini_lseek
#endif
#endif
#ifdef mini_prints
#ifndef mini__mprints
#define mini__mprints
#endif
#ifndef mini_dprints
#define mini_dprints
#endif
#endif
#ifdef mini_dirname
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_strrchr
#ifndef mini_strchrnul
#define mini_strchrnul
#endif
#endif
#ifdef mini_getpwnam
#ifndef mini_pwent
#define mini_pwent
#endif
#ifndef mini_mmap
#define mini_mmap
#endif
#ifndef mini_userdb_open
#define mini_userdb_open
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_open
#define mini_open
#endif
#ifndef mini_strcmp
#define mini_strcmp
#endif
#ifndef mini_token_s
#define mini_token_s
#endif
#ifndef mini_token_i
#define mini_token_i
#endif
#endif
#ifdef mini_posix_openpt
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_open
#define mini_open
#endif
#endif
#ifdef mini_ptsname
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_ptsname_r
#define mini_ptsname_r
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#ifndef mini_itodec
#define mini_itodec
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#ifndef mini_sprintf
#define mini_sprintf
#endif
#endif
#ifdef mini_ewritesl
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_htonl
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_dprintf
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_vsnprintf
#define mini_vsnprintf
#endif
#ifndef mini_snprintf
#define mini_snprintf
#endif
#endif
#ifdef mini_fgetc
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_read
#define mini_read
#endif
#endif
#ifdef mini_cfmakeraw
#ifndef mini_termio
#define mini_termio
#endif
#endif
#ifdef mini_fgets
#ifndef mini_fgetc
#define mini_fgetc
#endif
#endif
#ifdef mini_malloc_brk
#ifndef mini_sbrk
#define mini_sbrk
#endif
#ifndef mini_getbrk
#define mini_getbrk
#endif
#endif
#ifdef mini_sigprocmask
#ifndef mini_rt_sigprocmask
#define mini_rt_sigprocmask
#endif
#endif
#ifdef mini_exit_errno
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_errno_str
#define mini_errno_str
#endif
#ifndef mini_exit
#define mini_exit
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#endif
#ifdef mini_perror
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_strerror
#define mini_strerror
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini_errno
#define mini_errno
#endif
#endif
#ifdef mini_getchar
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
#ifdef mini_term_width
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_getenv
#define mini_getenv
#endif
#ifndef mini_environ
#define mini_environ
#endif
#endif
#ifdef mini_fgetul
#ifndef mini_fgetc
#define mini_fgetc
#endif
#endif
#ifdef mini_inet_ntoa
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_vexec_q
#ifndef mini_seterrno
#define mini_seterrno
#endif
#ifndef mini_waitpid
#define mini_waitpid
#endif
#ifndef mini_vfork
#define mini_vfork
#endif
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_exit
#define mini_exit
#endif
#endif
#ifdef mini_snprintfs
#ifndef mini_0
#define mini_0
#endif
#endif
#ifdef mini_fdopen
#ifndef mini_open
#define mini_open
#endif
#ifndef mini__fopen
#define mini__fopen
#endif
#ifndef mini_fileno
#define mini_fileno
#endif
#ifndef mini_close
#define mini_close
#endif
#endif
#ifdef mini_fgetud
#ifndef mini_fgetc
#define mini_fgetc
#endif
#endif
#ifdef mini_gethostname
#ifndef mini_network
#define mini_network
#endif
#endif
#ifdef mini_eprintf
#ifndef mini_fprintfs
#define mini_fprintfs
#endif
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_itoHEX
#ifndef mini__itohex
#define mini__itohex
#endif
#endif
#ifdef mini_unlockpt
#ifndef mini_termio
#define mini_termio
#endif
#ifndef mini_ioctl
#define mini_ioctl
#endif
#endif
#ifdef mini_eputs
#ifndef mini_eprintl
#define mini_eprintl
#endif
#ifndef mini_eprint
#define mini_eprint
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_ewrites
#ifndef mini_write
#define mini_write
#endif
#endif
#ifdef mini_system
#ifndef mini_execve
#define mini_execve
#endif
#ifndef mini_vfork
#define mini_vfork
#endif
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_ewrites
#define mini_ewrites
#endif
#ifndef mini_waitpid
#define mini_waitpid
#endif
#endif
#ifdef mini_readdir
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#ifndef mini_getdents
#define mini_getdents
#endif
#endif
#ifdef mini_execv
#ifndef mini_environ
#define mini_environ
#endif
#ifndef mini_execve
#define mini_execve
#endif
#endif
#ifdef mini_getc
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
#ifdef mini_eprintfs
#ifndef mini_fprintfs
#define mini_fprintfs
#endif
#ifndef mini_fputs
#define mini_fputs
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#endif
#ifdef mini_puts
#ifndef mini_printl
#define mini_printl
#endif
#ifndef mini_print
#define mini_print
#endif
#ifndef mini_strlen
#define mini_strlen
#endif
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_printf
#define mini_printf
#endif
#endif
#ifndef common_allheaders_h
#define common_allheaders_h
#ifndef termios_xxxxx
#define termios_xxxxx
#ifdef mini_termio
#define VINTR     0
#define VQUIT     1
#define VERASE    2
#define VKILL     3
#define VEOF      4
#define VTIME     5
#define VMIN      6
#define VSWTC     7
#define VSTART    8
#define VSTOP     9
#define VSUSP    10
#define VEOL     11
#define VREPRINT 12
#define VDISCARD 13
#define VWERASE  14
#define VLNEXT   15
#define VEOL2    16
#define IGNBRK  0000001
#define BRKINT  0000002
#define IGNPAR  0000004
#define PARMRK  0000010
#define INPCK   0000020
#define ISTRIP  0000040
#define INLCR   0000100
#define IGNCR   0000200
#define ICRNL   0000400
#define IUCLC   0001000
#define IXON    0002000
#define IXANY   0004000
#define IXOFF   0010000
#define IMAXBEL 0020000
#define IUTF8   0040000
#define OPOST  0000001
#define OLCUC  0000002
#define ONLCR  0000004
#define OCRNL  0000010
#define ONOCR  0000020
#define ONLRET 0000040
#define OFILL  0000100
#define OFDEL  0000200
#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_XOPEN_SOURCE)
#define NLDLY  0000400
#define NL0    0000000
#define NL1    0000400
#define CRDLY  0003000
#define CR0    0000000
#define CR1    0001000
#define CR2    0002000
#define CR3    0003000
#define TABDLY 0014000
#define TAB0   0000000
#define TAB1   0004000
#define TAB2   0010000
#define TAB3   0014000
#define BSDLY  0020000
#define BS0    0000000
#define BS1    0020000
#define FFDLY  0100000
#define FF0    0000000
#define FF1    0100000
#endif
#define VTDLY  0040000
#define VT0    0000000
#define VT1    0040000
#define B0       0000000
#define B50      0000001
#define B75      0000002
#define B110     0000003
#define B134     0000004
#define B150     0000005
#define B200     0000006
#define B300     0000007
#define B600     0000010
#define B1200    0000011
#define B1800    0000012
#define B2400    0000013
#define B4800    0000014
#define B9600    0000015
#define B19200   0000016
#define B38400   0000017
#define B57600   0010001
#define B115200  0010002
#define B230400  0010003
#define B460800  0010004
#define B500000  0010005
#define B576000  0010006
#define B921600  0010007
#define B1000000 0010010
#define B1152000 0010011
#define B1500000 0010012
#define B2000000 0010013
#define B2500000 0010014
#define B3000000 0010015
#define B3500000 0010016
#define B4000000 0010017
#define CSIZE  0000060
#define CS5    0000000
#define CS6    0000020
#define CS7    0000040
#define CS8    0000060
#define CSTOPB 0000100
#define CREAD  0000200
#define PARENB 0000400
#define PARODD 0001000
#define HUPCL  0002000
#define CLOCAL 0004000
#define ISIG   0000001
#define ICANON 0000002
#define ECHO   0000010
#define ECHOE  0000020
#define ECHOK  0000040
#define ECHONL 0000100
#define NOFLSH 0000200
#define TOSTOP 0000400
#define IEXTEN 0100000
#define TCOOFF 0
#define TCOON  1
#define TCIOFF 2
#define TCION  3
#define TCIFLUSH  0
#define TCOFLUSH  1
#define TCIOFLUSH 2
#define TCSANOW   0
#define TCSADRAIN 1
#define TCSAFLUSH 2
#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define EXTA    0000016
#define EXTB    0000017
#define CBAUD   0010017
#define CBAUDEX 0010000
#define CIBAUD  002003600000
#define CMSPAR  010000000000
#define CRTSCTS 020000000000
#define XCASE   0000004
#define ECHOCTL 0001000
#define ECHOPRT 0002000
#define ECHOKE  0004000
#define FLUSHO  0010000
#define PENDIN  0040000
#define EXTPROC 0200000
#define XTABS  0014000
#endif
#endif
#endif
#ifndef mini_alltypes_h
#define mini_alltypes_h
#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif
#define ITIMER_REAL    0
#define ITIMER_VIRTUAL 1
#define ITIMER_PROF    2
struct itimerval {
struct timeval it_interval;
struct timeval it_value;
};
#define _Addr long
#define _Int64 long
#define _Reg long
#ifndef size_t
#define size_t long
#endif
#ifndef uchar
typedef unsigned char uchar;
#endif
typedef int wchar_t;
typedef long double double_t;
typedef float float_t;
typedef struct { long long __ll; long double __ld; } max_align_t;
typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;
typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;
typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;
typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;
typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;
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
struct timespec { time_t tv_sec; long tv_nsec; };
typedef int pid_t;
typedef unsigned id_t;
typedef unsigned uid_t;
typedef unsigned gid_t;
typedef int key_t;
typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;
typedef struct __locale_struct * locale_t;
struct iovec { void *iov_base; size_t iov_len; };
typedef unsigned socklen_t;
typedef unsigned short sa_family_t;
#undef _Addr
#undef _Int64
#undef _Reg
#endif
#ifndef ioctl_h
#define ioctl_h
#define _IOC(a,b,c,d) ( ((a)<<30) | ((b)<<8) | (c) | ((d)<<16) )
#define _IOC_NONE  0U
#define _IOC_WRITE 1U
#define _IOC_READ  2U
#define _IO(a,b) _IOC(_IOC_NONE,(a),(b),0)
#define _IOW(a,b,c) _IOC(_IOC_WRITE,(a),(b),sizeof(c))
#define _IOR(a,b,c) _IOC(_IOC_READ,(a),(b),sizeof(c))
#define _IOWR(a,b,c) _IOC(_IOC_READ|_IOC_WRITE,(a),(b),sizeof(c))
#define TCGETS		0x5401
#define TCSETS		0x5402
#define TCSETSW		0x5403
#define TCSETSF		0x5404
#define TCGETA		0x5405
#define TCSETA		0x5406
#define TCSETAW		0x5407
#define TCSETAF		0x5408
#define TCSBRK		0x5409
#define TCXONC		0x540A
#define TCFLSH		0x540B
#define TIOCEXCL	0x540C
#define TIOCNXCL	0x540D
#define TIOCSCTTY	0x540E
#define TIOCGPGRP	0x540F
#define TIOCSPGRP	0x5410
#define TIOCOUTQ	0x5411
#define TIOCSTI		0x5412
#define TIOCGWINSZ	0x5413
#define TIOCSWINSZ	0x5414
#define TIOCMGET	0x5415
#define TIOCMBIS	0x5416
#define TIOCMBIC	0x5417
#define TIOCMSET	0x5418
#define TIOCGSOFTCAR	0x5419
#define TIOCSSOFTCAR	0x541A
#define FIONREAD	0x541B
#define TIOCINQ		FIONREAD
#define TIOCLINUX	0x541C
#define TIOCCONS	0x541D
#define TIOCGSERIAL	0x541E
#define TIOCSSERIAL	0x541F
#define TIOCPKT		0x5420
#define FIONBIO		0x5421
#define TIOCNOTTY	0x5422
#define TIOCSETD	0x5423
#define TIOCGETD	0x5424
#define TCSBRKP		0x5425
#define TIOCSBRK	0x5427
#define TIOCCBRK	0x5428
#define TIOCGSID	0x5429
#define TIOCGRS485	0x542E
#define TIOCSRS485	0x542F
#define TIOCGPTN	0x80045430
#define TIOCSPTLCK	0x40045431
#define TIOCGDEV	0x80045432
#define TCGETX		0x5432
#define TCSETX		0x5433
#define TCSETXF		0x5434
#define TCSETXW		0x5435
#define TIOCSIG		0x40045436
#define TIOCVHANGUP	0x5437
#define TIOCGPKT	0x80045438
#define TIOCGPTLCK	0x80045439
#define TIOCGEXCL	0x80045440
#define TIOCGPTPEER	0x5441
#define FIONCLEX	0x5450
#define FIOCLEX		0x5451
#define FIOASYNC	0x5452
#define TIOCSERCONFIG	0x5453
#define TIOCSERGWILD	0x5454
#define TIOCSERSWILD	0x5455
#define TIOCGLCKTRMIOS	0x5456
#define TIOCSLCKTRMIOS	0x5457
#define TIOCSERGSTRUCT	0x5458
#define TIOCSERGETLSR   0x5459
#define TIOCSERGETMULTI 0x545A
#define TIOCSERSETMULTI 0x545B
#define TIOCMIWAIT	0x545C
#define TIOCGICOUNT	0x545D
#define FIOQSIZE	0x5460
#define TIOCPKT_DATA		 0
#define TIOCPKT_FLUSHREAD	 1
#define TIOCPKT_FLUSHWRITE	 2
#define TIOCPKT_STOP		 4
#define TIOCPKT_START		 8
#define TIOCPKT_NOSTOP		16
#define TIOCPKT_DOSTOP		32
#define TIOCPKT_IOCTL		64
#define TIOCSER_TEMT    0x01
struct winsize {
unsigned short ws_row;
unsigned short ws_col;
unsigned short ws_xpixel;
unsigned short ws_ypixel;
};
#define TIOCM_LE        0x001
#define TIOCM_DTR       0x002
#define TIOCM_RTS       0x004
#define TIOCM_ST        0x008
#define TIOCM_SR        0x010
#define TIOCM_CTS       0x020
#define TIOCM_CAR       0x040
#define TIOCM_RNG       0x080
#define TIOCM_DSR       0x100
#define TIOCM_CD        TIOCM_CAR
#define TIOCM_RI        TIOCM_RNG
#define TIOCM_OUT1      0x2000
#define TIOCM_OUT2      0x4000
#define TIOCM_LOOP      0x8000
#define N_TTY           0
#define N_SLIP          1
#define N_MOUSE         2
#define N_PPP           3
#define N_STRIP         4
#define N_AX25          5
#define N_X25           6
#define N_6PACK         7
#define N_MASC          8
#define N_R3964         9
#define N_PROFIBUS_FDL  10
#define N_IRDA          11
#define N_SMSBLOCK      12
#define N_HDLC          13
#define N_SYNC_PPP      14
#define N_HCI           15
#define FIOSETOWN       0x8901
#define SIOCSPGRP       0x8902
#define FIOGETOWN       0x8903
#define SIOCGPGRP       0x8904
#define SIOCATMARK      0x8905
#define SIOCGSTAMP      0x8906
#define SIOCGSTAMPNS    0x8907
#define SIOCADDRT       0x890B
#define SIOCDELRT       0x890C
#define SIOCRTMSG       0x890D
#define SIOCGIFNAME     0x8910
#define SIOCSIFLINK     0x8911
#define SIOCGIFCONF     0x8912
#define SIOCGIFFLAGS    0x8913
#define SIOCSIFFLAGS    0x8914
#define SIOCGIFADDR     0x8915
#define SIOCSIFADDR     0x8916
#define SIOCGIFDSTADDR  0x8917
#define SIOCSIFDSTADDR  0x8918
#define SIOCGIFBRDADDR  0x8919
#define SIOCSIFBRDADDR  0x891a
#define SIOCGIFNETMASK  0x891b
#define SIOCSIFNETMASK  0x891c
#define SIOCGIFMETRIC   0x891d
#define SIOCSIFMETRIC   0x891e
#define SIOCGIFMEM      0x891f
#define SIOCSIFMEM      0x8920
#define SIOCGIFMTU      0x8921
#define SIOCSIFMTU      0x8922
#define SIOCSIFNAME     0x8923
#define SIOCSIFHWADDR   0x8924
#define SIOCGIFENCAP    0x8925
#define SIOCSIFENCAP    0x8926
#define SIOCGIFHWADDR   0x8927
#define SIOCGIFSLAVE    0x8929
#define SIOCSIFSLAVE    0x8930
#define SIOCADDMULTI    0x8931
#define SIOCDELMULTI    0x8932
#define SIOCGIFINDEX    0x8933
#define SIOGIFINDEX     SIOCGIFINDEX
#define SIOCSIFPFLAGS   0x8934
#define SIOCGIFPFLAGS   0x8935
#define SIOCDIFADDR     0x8936
#define SIOCSIFHWBROADCAST 0x8937
#define SIOCGIFCOUNT    0x8938
#define SIOCGIFBR       0x8940
#define SIOCSIFBR       0x8941
#define SIOCGIFTXQLEN   0x8942
#define SIOCSIFTXQLEN   0x8943
#define SIOCDARP        0x8953
#define SIOCGARP        0x8954
#define SIOCSARP        0x8955
#define SIOCDRARP       0x8960
#define SIOCGRARP       0x8961
#define SIOCSRARP       0x8962
#define SIOCGIFMAP      0x8970
#define SIOCSIFMAP      0x8971
#define SIOCADDDLCI     0x8980
#define SIOCDELDLCI     0x8981
#define SIOCDEVPRIVATE		0x89F0
#define SIOCPROTOPRIVATE	0x89E0
#endif
#ifndef __bits_stat_h
#define __bits_stat_h
#define S_IFMT  0170000
#define	S_IFDIR	0040000	
#define	S_IFCHR	0020000	
#define	S_IFBLK	0060000	
#define	S_IFREG	0100000	
#define	S_IFIFO	0010000	
#define	S_IFLNK	0120000	
#define	S_IFSOCK 0140000	
#define	S_ISUID	04000	
#define	S_ISGID	02000	
#define	S_ISVTX	01000	
#define	S_IREAD	0400	
#define	S_IWRITE 0200	
#define	S_IEXEC	0100	
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#define S_ISCHR(mode)  (((mode) & S_IFMT) == S_IFCHR)
#define S_ISBLK(mode)  (((mode) & S_IFMT) == S_IFBLK)
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#define S_ISFIFO(mode) (((mode) & S_IFMT) == S_IFIFO)
#define S_ISLNK(mode)  (((mode) & S_IFMT) == S_IFLNK)
#define S_ISSOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)
#define S_ISUID 04000
#define S_ISGID 02000
#define S_ISVTX 01000
#define S_IRUSR 0400
#define S_IWUSR 0200
#define S_IXUSR 0100
#define S_IRWXU 0700
#define S_IRGRP 0040
#define S_IWGRP 0020
#define S_IXGRP 0010
#define S_IRWXG 0070
#define S_IROTH 0004
#define S_IWOTH 0002
#define S_IXOTH 0001
#define S_IRWXO 0007
#ifdef X64
#ifndef stat_defined
#define stat_defined
struct stat {
dev_t st_dev;
ino_t st_ino;
nlink_t st_nlink;
mode_t st_mode;
uid_t st_uid;
gid_t st_gid;
unsigned int    __pad0;
dev_t st_rdev;
off_t st_size;
blksize_t st_blksize;
blkcnt_t st_blocks;
struct timespec st_atime;
struct timespec st_mtime;
struct timespec st_ctime;
long __unused[3];
};
#endif
#else
#endif
#endif
#ifndef bits_signal_h
#define bits_signal_h
#define SA_NOCLDSTOP  1
#define SA_NOCLDWAIT  2
#define SA_SIGINFO    4
#define SA_ONSTACK    0x08000000
#define SA_RESTART    0x10000000
#define SA_NODEFER    0x40000000
#define SA_RESETHAND  0x80000000
#define SA_RESTORER   0x04000000
#define _NSIG 65
#define SIGHUP    1
#define SIGINT    2
#define SIGQUIT   3
#define SIGILL    4
#define SIGTRAP   5
#define SIGABRT   6
#define SIGIOT    SIGABRT
#define SIGBUS    7
#define SIGFPE    8
#define SIGKILL   9
#define SIGUSR1   10
#define SIGSEGV   11
#define SIGUSR2   12
#define SIGPIPE   13
#define SIGALRM   14
#define SIGTERM   15
#define SIGSTKFLT 16
#define SIGCHLD   17
#define SIGCONT   18
#define SIGSTOP   19
#define SIGTSTP   20
#define SIGTTIN   21
#define SIGTTOU   22
#define SIGURG    23
#define SIGXCPU   24
#define SIGXFSZ   25
#define SIGVTALRM 26
#define SIGPROF   27
#define SIGWINCH  28
#define SIGIO     29
#define SIGPOLL   29
#define SIGPWR    30
#define SIGSYS    31
#define SIGUNUSED SIGSYS
#endif
#ifndef common_bits_fcntl_h
#define common_bits_fcntl_h
#define F_DUPFD  0
#define F_GETFD  1
#define F_SETFD  2
#define F_GETFL  3
#define F_SETFL  4
#define F_SETOWN 8
#define F_GETOWN 9
#define F_SETSIG 10
#define F_GETSIG 11
#define F_GETLK 5
#define F_SETLK 6
#define F_SETLKW 7
#define F_SETOWN_EX 15
#define F_GETOWN_EX 16
#define F_GETOWNER_UIDS 17
#endif
#ifndef ctype_h
#define ctype_h
#define isalpha(a) (0 ? 1 : (((unsigned)(a)|32)-'a') < 26)
#define isdigit(a) (0 ? 1 : ((unsigned)(a)-'0') < 10)
#define islower(a) (0 ? 1 : ((unsigned)(a)-'a') < 26)
#define isupper(a) (0 ? 1 : ((unsigned)(a)-'A') < 26)
#define isprint(a) (0 ? 1 : ((unsigned)(a)-(0x20)) < 0x5f)
#define isgraph(a) (0 ? 1 : ((unsigned)(a)-0x21) < 0x5e)
#define isspace(a) ((a==' ')||(a=='\t')||(a=='\n')||(a=='\f')||(a=='\r')||(a=='\v'))
#define isalnum(a) (isalpha(a) || isdigit(a))
#define _tolower(a) ((a)|0x20)
#define tolower(a) ((a)|0x20)
#define _toupper(a) ((a)&0x5f)
#define toupper(a) ((a)&0x5f)
#define isascii(a) (0 ? isascii(a) : (unsigned)(a) < 128)
#endif
#ifndef mini_ELF_H
#define mini_ELF_H
#ifdef mini_elf
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
#ifndef mini_alltypes_h
#define mini_alltypes_h
#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif
#define ITIMER_REAL    0
#define ITIMER_VIRTUAL 1
#define ITIMER_PROF    2
struct itimerval {
struct timeval it_interval;
struct timeval it_value;
};
#define _Addr long
#define _Int64 long
#define _Reg long
#ifndef size_t
#define size_t long
#endif
#ifndef uchar
typedef unsigned char uchar;
#endif
typedef int wchar_t;
typedef long double double_t;
typedef float float_t;
typedef struct { long long __ll; long double __ld; } max_align_t;
typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;
typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;
typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;
typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;
typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;
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
struct timespec { time_t tv_sec; long tv_nsec; };
typedef int pid_t;
typedef unsigned id_t;
typedef unsigned uid_t;
typedef unsigned gid_t;
typedef int key_t;
typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;
typedef struct __locale_struct * locale_t;
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
typedef uint16_t Elf32_Half;
typedef uint16_t Elf64_Half;
typedef uint32_t Elf32_Word;
typedef	int32_t  Elf32_Sword;
typedef uint32_t Elf64_Word;
typedef	int32_t  Elf64_Sword;
typedef uint64_t Elf32_Xword;
typedef	int64_t  Elf32_Sxword;
typedef uint64_t Elf64_Xword;
typedef	int64_t  Elf64_Sxword;
typedef uint32_t Elf32_Addr;
typedef uint64_t Elf64_Addr;
typedef uint32_t Elf32_Off;
typedef uint64_t Elf64_Off;
typedef uint16_t Elf32_Section;
typedef uint16_t Elf64_Section;
typedef Elf32_Half Elf32_Versym;
typedef Elf64_Half Elf64_Versym;
#define EI_NIDENT (16)
typedef struct {
unsigned char	e_ident[EI_NIDENT];
Elf32_Half	e_type;
Elf32_Half	e_machine;
Elf32_Word	e_version;
Elf32_Addr	e_entry;
Elf32_Off	e_phoff;
Elf32_Off	e_shoff;
Elf32_Word	e_flags;
Elf32_Half	e_ehsize;
Elf32_Half	e_phentsize;
Elf32_Half	e_phnum;
Elf32_Half	e_shentsize;
Elf32_Half	e_shnum;
Elf32_Half	e_shstrndx;
} Elf32_Ehdr;
typedef struct {
unsigned char	e_ident[EI_NIDENT];
Elf64_Half	e_type;
Elf64_Half	e_machine;
Elf64_Word	e_version;
Elf64_Addr	e_entry;
Elf64_Off	e_phoff;
Elf64_Off	e_shoff;
Elf64_Word	e_flags;
Elf64_Half	e_ehsize;
Elf64_Half	e_phentsize;
Elf64_Half	e_phnum;
Elf64_Half	e_shentsize;
Elf64_Half	e_shnum;
Elf64_Half	e_shstrndx;
} Elf64_Ehdr;
#define EI_MAG0		0
#define ELFMAG0		0x7f
#define EI_MAG1		1
#define ELFMAG1		'E'
#define EI_MAG2		2
#define ELFMAG2		'L'
#define EI_MAG3		3
#define ELFMAG3		'F'
#define	ELFMAG		"\177ELF"
#define	SELFMAG		4
#define EI_CLASS	4
#define ELFCLASSNONE	0
#define ELFCLASS32	1
#define ELFCLASS64	2
#define ELFCLASSNUM	3
#define EI_DATA		5
#define ELFDATANONE	0
#define ELFDATA2LSB	1
#define ELFDATA2MSB	2
#define ELFDATANUM	3
#define EI_VERSION	6
#define EI_OSABI	7
#define ELFOSABI_NONE		0
#define ELFOSABI_SYSV		0
#define ELFOSABI_HPUX		1
#define ELFOSABI_NETBSD		2
#define ELFOSABI_LINUX		3
#define ELFOSABI_GNU		3
#define ELFOSABI_SOLARIS	6
#define ELFOSABI_AIX		7
#define ELFOSABI_IRIX		8
#define ELFOSABI_FREEBSD	9
#define ELFOSABI_TRU64		10
#define ELFOSABI_MODESTO	11
#define ELFOSABI_OPENBSD	12
#define ELFOSABI_ARM		97
#define ELFOSABI_STANDALONE	255
#define EI_ABIVERSION	8
#define EI_PAD		9
#define ET_NONE		0
#define ET_REL		1
#define ET_EXEC		2
#define ET_DYN		3
#define ET_CORE		4
#define	ET_NUM		5
#define ET_LOOS		0xfe00
#define ET_HIOS		0xfeff
#define ET_LOPROC	0xff00
#define ET_HIPROC	0xffff
#define EM_NONE		 0
#define EM_M32		 1
#define EM_SPARC	 2
#define EM_386		 3
#define EM_68K		 4
#define EM_88K		 5
#define EM_860		 7
#define EM_MIPS		 8
#define EM_S370		 9
#define EM_MIPS_RS3_LE	10
#define EM_PARISC	15
#define EM_VPP500	17
#define EM_SPARC32PLUS	18
#define EM_960		19
#define EM_PPC		20
#define EM_PPC64	21
#define EM_S390		22
#define EM_V800		36
#define EM_FR20		37
#define EM_RH32		38
#define EM_RCE		39
#define EM_ARM		40
#define EM_FAKE_ALPHA	41
#define EM_SH		42
#define EM_SPARCV9	43
#define EM_TRICORE	44
#define EM_ARC		45
#define EM_H8_300	46
#define EM_H8_300H	47
#define EM_H8S		48
#define EM_H8_500	49
#define EM_IA_64	50
#define EM_MIPS_X	51
#define EM_COLDFIRE	52
#define EM_68HC12	53
#define EM_MMA		54
#define EM_PCP		55
#define EM_NCPU		56
#define EM_NDR1		57
#define EM_STARCORE	58
#define EM_ME16		59
#define EM_ST100	60
#define EM_TINYJ	61
#define EM_X86_64	62
#define EM_PDSP		63
#define EM_FX66		66
#define EM_ST9PLUS	67
#define EM_ST7		68
#define EM_68HC16	69
#define EM_68HC11	70
#define EM_68HC08	71
#define EM_68HC05	72
#define EM_SVX		73
#define EM_ST19		74
#define EM_VAX		75
#define EM_CRIS		76
#define EM_JAVELIN	77
#define EM_FIREPATH	78
#define EM_ZSP		79
#define EM_MMIX		80
#define EM_HUANY	81
#define EM_PRISM	82
#define EM_AVR		83
#define EM_FR30		84
#define EM_D10V		85
#define EM_D30V		86
#define EM_V850		87
#define EM_M32R		88
#define EM_MN10300	89
#define EM_MN10200	90
#define EM_PJ		91
#define EM_OR1K		92
#define EM_OPENRISC	92
#define EM_ARC_A5	93
#define EM_ARC_COMPACT	93
#define EM_XTENSA	94
#define EM_VIDEOCORE	95
#define EM_TMM_GPP	96
#define EM_NS32K	97
#define EM_TPC		98
#define EM_SNP1K	99
#define EM_ST200	100
#define EM_IP2K		101
#define EM_MAX		102
#define EM_CR		103
#define EM_F2MC16	104
#define EM_MSP430	105
#define EM_BLACKFIN	106
#define EM_SE_C33	107
#define EM_SEP		108
#define EM_ARCA		109
#define EM_UNICORE	110
#define EM_EXCESS	111
#define EM_DXP		112
#define EM_ALTERA_NIOS2 113
#define EM_CRX		114
#define EM_XGATE	115
#define EM_C166		116
#define EM_M16C		117
#define EM_DSPIC30F	118
#define EM_CE		119
#define EM_M32C		120
#define EM_TSK3000	131
#define EM_RS08		132
#define EM_SHARC	133
#define EM_ECOG2	134
#define EM_SCORE7	135
#define EM_DSP24	136
#define EM_VIDEOCORE3	137
#define EM_LATTICEMICO32 138
#define EM_SE_C17	139
#define EM_TI_C6000	140
#define EM_TI_C2000	141
#define EM_TI_C5500	142
#define EM_TI_ARP32	143
#define EM_TI_PRU	144
#define EM_MMDSP_PLUS	160
#define EM_CYPRESS_M8C	161
#define EM_R32C		162
#define EM_TRIMEDIA	163
#define EM_QDSP6	164
#define EM_8051		165
#define EM_STXP7X	166
#define EM_NDS32	167
#define EM_ECOG1X	168
#define EM_MAXQ30	169
#define EM_XIMO16	170
#define EM_MANIK	171
#define EM_CRAYNV2	172
#define EM_RX		173
#define EM_METAG	174
#define EM_MCST_ELBRUS	175
#define EM_ECOG16	176
#define EM_CR16		177
#define EM_ETPU		178
#define EM_SLE9X	179
#define EM_L10M		180
#define EM_K10M		181
#define EM_AARCH64	183
#define EM_AVR32	185
#define EM_STM8		186
#define EM_TILE64	187
#define EM_TILEPRO	188
#define EM_MICROBLAZE	189
#define EM_CUDA		190
#define EM_TILEGX	191
#define EM_CLOUDSHIELD	192
#define EM_COREA_1ST	193
#define EM_COREA_2ND	194
#define EM_ARC_COMPACT2	195
#define EM_OPEN8	196
#define EM_RL78		197
#define EM_VIDEOCORE5	198
#define EM_78KOR	199
#define EM_56800EX	200
#define EM_BA1		201
#define EM_BA2		202
#define EM_XCORE	203
#define EM_MCHP_PIC	204
#define EM_KM32		210
#define EM_KMX32	211
#define EM_EMX16	212
#define EM_EMX8		213
#define EM_KVARC	214
#define EM_CDP		215
#define EM_COGE		216
#define EM_COOL		217
#define EM_NORC		218
#define EM_CSR_KALIMBA	219
#define EM_Z80		220
#define EM_VISIUM	221
#define EM_FT32		222
#define EM_MOXIE	223
#define EM_AMDGPU	224
#define EM_RISCV	243
#define EM_BPF		247
#define EM_NUM		248
#define EM_ALPHA	0x9026
#define EV_NONE		0
#define EV_CURRENT	1
#define EV_NUM		2
typedef struct {
Elf32_Word	sh_name;
Elf32_Word	sh_type;
Elf32_Word	sh_flags;
Elf32_Addr	sh_addr;
Elf32_Off	sh_offset;
Elf32_Word	sh_size;
Elf32_Word	sh_link;
Elf32_Word	sh_info;
Elf32_Word	sh_addralign;
Elf32_Word	sh_entsize;
} Elf32_Shdr;
typedef struct {
Elf64_Word	sh_name;
Elf64_Word	sh_type;
Elf64_Xword	sh_flags;
Elf64_Addr	sh_addr;
Elf64_Off	sh_offset;
Elf64_Xword	sh_size;
Elf64_Word	sh_link;
Elf64_Word	sh_info;
Elf64_Xword	sh_addralign;
Elf64_Xword	sh_entsize;
} Elf64_Shdr;
#define SHN_UNDEF	0
#define SHN_LORESERVE	0xff00
#define SHN_LOPROC	0xff00
#define SHN_BEFORE	0xff00
#define SHN_AFTER	0xff01
#define SHN_HIPROC	0xff1f
#define SHN_LOOS	0xff20
#define SHN_HIOS	0xff3f
#define SHN_ABS		0xfff1
#define SHN_COMMON	0xfff2
#define SHN_XINDEX	0xffff
#define SHN_HIRESERVE	0xffff
#define SHT_NULL	  0
#define SHT_PROGBITS	  1
#define SHT_SYMTAB	  2
#define SHT_STRTAB	  3
#define SHT_RELA	  4
#define SHT_HASH	  5
#define SHT_DYNAMIC	  6
#define SHT_NOTE	  7
#define SHT_NOBITS	  8
#define SHT_REL		  9
#define SHT_SHLIB	  10
#define SHT_DYNSYM	  11
#define SHT_INIT_ARRAY	  14
#define SHT_FINI_ARRAY	  15
#define SHT_PREINIT_ARRAY 16
#define SHT_GROUP	  17
#define SHT_SYMTAB_SHNDX  18
#define	SHT_NUM		  19
#define SHT_LOOS	  0x60000000
#define SHT_GNU_ATTRIBUTES 0x6ffffff5
#define SHT_GNU_HASH	  0x6ffffff6
#define SHT_GNU_LIBLIST	  0x6ffffff7
#define SHT_CHECKSUM	  0x6ffffff8
#define SHT_LOSUNW	  0x6ffffffa
#define SHT_SUNW_move	  0x6ffffffa
#define SHT_SUNW_COMDAT   0x6ffffffb
#define SHT_SUNW_syminfo  0x6ffffffc
#define SHT_GNU_verdef	  0x6ffffffd
#define SHT_GNU_verneed	  0x6ffffffe
#define SHT_GNU_versym	  0x6fffffff
#define SHT_HISUNW	  0x6fffffff
#define SHT_HIOS	  0x6fffffff
#define SHT_LOPROC	  0x70000000
#define SHT_HIPROC	  0x7fffffff
#define SHT_LOUSER	  0x80000000
#define SHT_HIUSER	  0x8fffffff
#define SHF_WRITE	     (1 << 0)
#define SHF_ALLOC	     (1 << 1)
#define SHF_EXECINSTR	     (1 << 2)
#define SHF_MERGE	     (1 << 4)
#define SHF_STRINGS	     (1 << 5)
#define SHF_INFO_LINK	     (1 << 6)
#define SHF_LINK_ORDER	     (1 << 7)
#define SHF_OS_NONCONFORMING (1 << 8)
#define SHF_GROUP	     (1 << 9)
#define SHF_TLS		     (1 << 10)
#define SHF_COMPRESSED	     (1 << 11)
#define SHF_MASKOS	     0x0ff00000
#define SHF_MASKPROC	     0xf0000000
#define SHF_ORDERED	     (1 << 30)
#define SHF_EXCLUDE	     (1U << 31)
typedef struct {
Elf32_Word	ch_type;
Elf32_Word	ch_size;
Elf32_Word	ch_addralign;
} Elf32_Chdr;
typedef struct {
Elf64_Word	ch_type;
Elf64_Word	ch_reserved;
Elf64_Xword	ch_size;
Elf64_Xword	ch_addralign;
} Elf64_Chdr;
#define ELFCOMPRESS_ZLIB	1
#define ELFCOMPRESS_LOOS	0x60000000
#define ELFCOMPRESS_HIOS	0x6fffffff
#define ELFCOMPRESS_LOPROC	0x70000000
#define ELFCOMPRESS_HIPROC	0x7fffffff
#define GRP_COMDAT	0x1
typedef struct {
Elf32_Word	st_name;
Elf32_Addr	st_value;
Elf32_Word	st_size;
unsigned char	st_info;
unsigned char	st_other;
Elf32_Section	st_shndx;
} Elf32_Sym;
typedef struct {
Elf64_Word	st_name;
unsigned char	st_info;
unsigned char st_other;
Elf64_Section	st_shndx;
Elf64_Addr	st_value;
Elf64_Xword	st_size;
} Elf64_Sym;
typedef struct {
Elf32_Half si_boundto;
Elf32_Half si_flags;
} Elf32_Syminfo;
typedef struct {
Elf64_Half si_boundto;
Elf64_Half si_flags;
} Elf64_Syminfo;
#define SYMINFO_BT_SELF		0xffff
#define SYMINFO_BT_PARENT	0xfffe
#define SYMINFO_BT_LOWRESERVE	0xff00
#define SYMINFO_FLG_DIRECT	0x0001
#define SYMINFO_FLG_PASSTHRU	0x0002
#define SYMINFO_FLG_COPY	0x0004
#define SYMINFO_FLG_LAZYLOAD	0x0008
#define SYMINFO_NONE		0
#define SYMINFO_CURRENT		1
#define SYMINFO_NUM		2
#define ELF32_ST_BIND(val)		(((unsigned char) (val)) >> 4)
#define ELF32_ST_TYPE(val)		((val) & 0xf)
#define ELF32_ST_INFO(bind, type)	(((bind) << 4) + ((type) & 0xf))
#define ELF64_ST_BIND(val)		ELF32_ST_BIND (val)
#define ELF64_ST_TYPE(val)		ELF32_ST_TYPE (val)
#define ELF64_ST_INFO(bind, type)	ELF32_ST_INFO ((bind), (type))
#define STB_LOCAL	0
#define STB_GLOBAL	1
#define STB_WEAK	2
#define	STB_NUM		3
#define STB_LOOS	10
#define STB_GNU_UNIQUE	10
#define STB_HIOS	12
#define STB_LOPROC	13
#define STB_HIPROC	15
#define STT_NOTYPE	0
#define STT_OBJECT	1
#define STT_FUNC	2
#define STT_SECTION	3
#define STT_FILE	4
#define STT_COMMON	5
#define STT_TLS		6
#define	STT_NUM		7
#define STT_LOOS	10
#define STT_GNU_IFUNC	10
#define STT_HIOS	12
#define STT_LOPROC	13
#define STT_HIPROC	15
#define STN_UNDEF	0
#define ELF32_ST_VISIBILITY(o)	((o) & 0x03)
#define ELF64_ST_VISIBILITY(o)	ELF32_ST_VISIBILITY (o)
#define STV_DEFAULT	0
#define STV_INTERNAL	1
#define STV_HIDDEN	2
#define STV_PROTECTED	3
typedef struct {
Elf32_Addr	r_offset;
Elf32_Word	r_info;
} Elf32_Rel;
typedef struct {
Elf64_Addr	r_offset;
Elf64_Xword	r_info;
} Elf64_Rel;
typedef struct {
Elf32_Addr	r_offset;
Elf32_Word	r_info;
Elf32_Sword	r_addend;
} Elf32_Rela;
typedef struct {
Elf64_Addr	r_offset;
Elf64_Xword	r_info;
Elf64_Sxword	r_addend;
} Elf64_Rela;
#define ELF32_R_SYM(val)		((val) >> 8)
#define ELF32_R_TYPE(val)		((val) & 0xff)
#define ELF32_R_INFO(sym, type)		(((sym) << 8) + ((type) & 0xff))
#define ELF64_R_SYM(i)			((i) >> 32)
#define ELF64_R_TYPE(i)			((i) & 0xffffffff)
#define ELF64_R_INFO(sym,type)		((((Elf64_Xword) (sym)) << 32) + (type))
typedef struct {
Elf32_Word	p_type;
Elf32_Off	p_offset;
Elf32_Addr	p_vaddr;
Elf32_Addr	p_paddr;
Elf32_Word	p_filesz;
Elf32_Word	p_memsz;
Elf32_Word	p_flags;
Elf32_Word	p_align;
} Elf32_Phdr;
typedef struct {
Elf64_Word	p_type;
Elf64_Word	p_flags;
Elf64_Off	p_offset;
Elf64_Addr	p_vaddr;
Elf64_Addr	p_paddr;
Elf64_Xword	p_filesz;
Elf64_Xword	p_memsz;
Elf64_Xword	p_align;
} Elf64_Phdr;
#define	PT_NULL		0
#define PT_LOAD		1
#define PT_DYNAMIC	2
#define PT_INTERP	3
#define PT_NOTE		4
#define PT_SHLIB	5
#define PT_PHDR		6
#define PT_TLS		7
#define	PT_NUM		8
#define PT_LOOS		0x60000000
#define PT_GNU_EH_FRAME	0x6474e550
#define PT_GNU_STACK	0x6474e551
#define PT_GNU_RELRO	0x6474e552
#define PT_LOSUNW	0x6ffffffa
#define PT_SUNWBSS	0x6ffffffa
#define PT_SUNWSTACK	0x6ffffffb
#define PT_HISUNW	0x6fffffff
#define PT_HIOS		0x6fffffff
#define PT_LOPROC	0x70000000
#define PT_HIPROC	0x7fffffff
#define PN_XNUM 0xffff
#define PF_X		(1 << 0)
#define PF_W		(1 << 1)
#define PF_R		(1 << 2)
#define PF_MASKOS	0x0ff00000
#define PF_MASKPROC	0xf0000000
#define NT_PRSTATUS	1
#define NT_PRFPREG	2
#define NT_FPREGSET	2
#define NT_PRPSINFO	3
#define NT_PRXREG	4
#define NT_TASKSTRUCT	4
#define NT_PLATFORM	5
#define NT_AUXV		6
#define NT_GWINDOWS	7
#define NT_ASRS		8
#define NT_PSTATUS	10
#define NT_PSINFO	13
#define NT_PRCRED	14
#define NT_UTSNAME	15
#define NT_LWPSTATUS	16
#define NT_LWPSINFO	17
#define NT_PRFPXREG	20
#define NT_SIGINFO	0x53494749
#define NT_FILE		0x46494c45
#define NT_PRXFPREG	0x46e62b7f
#define NT_PPC_VMX	0x100
#define NT_PPC_SPE	0x101
#define NT_PPC_VSX	0x102
#define NT_PPC_TAR	0x103
#define NT_PPC_PPR	0x104
#define NT_PPC_DSCR	0x105
#define NT_PPC_EBB	0x106
#define NT_PPC_PMU	0x107
#define NT_PPC_TM_CGPR	0x108
#define NT_PPC_TM_CFPR	0x109
#define NT_PPC_TM_CVMX	0x10a
#define NT_PPC_TM_CVSX	0x10b
#define NT_PPC_TM_SPR	0x10c
#define NT_PPC_TM_CTAR	0x10d
#define NT_PPC_TM_CPPR	0x10e
#define NT_PPC_TM_CDSCR	0x10f
#define NT_386_TLS	0x200
#define NT_386_IOPERM	0x201
#define NT_X86_XSTATE	0x202
#define NT_S390_HIGH_GPRS	0x300
#define NT_S390_TIMER	0x301
#define NT_S390_TODCMP	0x302
#define NT_S390_TODPREG	0x303
#define NT_S390_CTRS	0x304
#define NT_S390_PREFIX	0x305
#define NT_S390_LAST_BREAK	0x306
#define NT_S390_SYSTEM_CALL	0x307
#define NT_S390_TDB	0x308
#define NT_S390_VXRS_LOW	0x309
#define NT_S390_VXRS_HIGH	0x30a
#define NT_S390_GS_CB	0x30b
#define NT_S390_GS_BC	0x30c
#define NT_S390_RI_CB	0x30d
#define NT_ARM_VFP	0x400
#define NT_ARM_TLS	0x401
#define NT_ARM_HW_BREAK	0x402
#define NT_ARM_HW_WATCH	0x403
#define NT_ARM_SYSTEM_CALL	0x404
#define NT_ARM_SVE	0x405
#define NT_METAG_CBUF	0x500
#define NT_METAG_RPIPE	0x501
#define NT_METAG_TLS	0x502
#define NT_ARC_V2	0x600
#define NT_VMCOREDD	0x700
#define NT_VERSION	1
typedef struct {
Elf32_Sword d_tag;
union {
Elf32_Word d_val;
Elf32_Addr d_ptr;
} d_un;
} Elf32_Dyn;
typedef struct {
Elf64_Sxword d_tag;
union {
Elf64_Xword d_val;
Elf64_Addr d_ptr;
} d_un;
} Elf64_Dyn;
#define DT_NULL		0
#define DT_NEEDED	1
#define DT_PLTRELSZ	2
#define DT_PLTGOT	3
#define DT_HASH		4
#define DT_STRTAB	5
#define DT_SYMTAB	6
#define DT_RELA		7
#define DT_RELASZ	8
#define DT_RELAENT	9
#define DT_STRSZ	10
#define DT_SYMENT	11
#define DT_INIT		12
#define DT_FINI		13
#define DT_SONAME	14
#define DT_RPATH	15
#define DT_SYMBOLIC	16
#define DT_REL		17
#define DT_RELSZ	18
#define DT_RELENT	19
#define DT_PLTREL	20
#define DT_DEBUG	21
#define DT_TEXTREL	22
#define DT_JMPREL	23
#define	DT_BIND_NOW	24
#define	DT_INIT_ARRAY	25
#define	DT_FINI_ARRAY	26
#define	DT_INIT_ARRAYSZ	27
#define	DT_FINI_ARRAYSZ	28
#define DT_RUNPATH	29
#define DT_FLAGS	30
#define DT_ENCODING	32
#define DT_PREINIT_ARRAY 32
#define DT_PREINIT_ARRAYSZ 33
#define DT_SYMTAB_SHNDX	34
#define	DT_NUM		35
#define DT_LOOS		0x6000000d
#define DT_HIOS		0x6ffff000
#define DT_LOPROC	0x70000000
#define DT_HIPROC	0x7fffffff
#define	DT_PROCNUM	DT_MIPS_NUM
#define DT_VALRNGLO	0x6ffffd00
#define DT_GNU_PRELINKED 0x6ffffdf5
#define DT_GNU_CONFLICTSZ 0x6ffffdf6
#define DT_GNU_LIBLISTSZ 0x6ffffdf7
#define DT_CHECKSUM	0x6ffffdf8
#define DT_PLTPADSZ	0x6ffffdf9
#define DT_MOVEENT	0x6ffffdfa
#define DT_MOVESZ	0x6ffffdfb
#define DT_FEATURE_1	0x6ffffdfc
#define DT_POSFLAG_1	0x6ffffdfd
#define DT_SYMINSZ	0x6ffffdfe
#define DT_SYMINENT	0x6ffffdff
#define DT_VALRNGHI	0x6ffffdff
#define DT_VALTAGIDX(tag)	(DT_VALRNGHI - (tag))
#define DT_VALNUM 12
#define DT_ADDRRNGLO	0x6ffffe00
#define DT_GNU_HASH	0x6ffffef5
#define DT_TLSDESC_PLT	0x6ffffef6
#define DT_TLSDESC_GOT	0x6ffffef7
#define DT_GNU_CONFLICT	0x6ffffef8
#define DT_GNU_LIBLIST	0x6ffffef9
#define DT_CONFIG	0x6ffffefa
#define DT_DEPAUDIT	0x6ffffefb
#define DT_AUDIT	0x6ffffefc
#define	DT_PLTPAD	0x6ffffefd
#define	DT_MOVETAB	0x6ffffefe
#define DT_SYMINFO	0x6ffffeff
#define DT_ADDRRNGHI	0x6ffffeff
#define DT_ADDRTAGIDX(tag)	(DT_ADDRRNGHI - (tag))
#define DT_ADDRNUM 11
#define DT_VERSYM	0x6ffffff0
#define DT_RELACOUNT	0x6ffffff9
#define DT_RELCOUNT	0x6ffffffa
#define DT_FLAGS_1	0x6ffffffb
#define	DT_VERDEF	0x6ffffffc
#define	DT_VERDEFNUM	0x6ffffffd
#define	DT_VERNEED	0x6ffffffe
#define	DT_VERNEEDNUM	0x6fffffff
#define DT_VERSIONTAGIDX(tag)	(DT_VERNEEDNUM - (tag))
#define DT_VERSIONTAGNUM 16
#define DT_AUXILIARY    0x7ffffffd
#define DT_FILTER       0x7fffffff
#define DT_EXTRATAGIDX(tag)	((Elf32_Word)-((Elf32_Sword) (tag) <<1>>1)-1)
#define DT_EXTRANUM	3
#define DF_ORIGIN	0x00000001
#define DF_SYMBOLIC	0x00000002
#define DF_TEXTREL	0x00000004
#define DF_BIND_NOW	0x00000008
#define DF_STATIC_TLS	0x00000010
#define DF_1_NOW	0x00000001
#define DF_1_GLOBAL	0x00000002
#define DF_1_GROUP	0x00000004
#define DF_1_NODELETE	0x00000008
#define DF_1_LOADFLTR	0x00000010
#define DF_1_INITFIRST	0x00000020
#define DF_1_NOOPEN	0x00000040
#define DF_1_ORIGIN	0x00000080
#define DF_1_DIRECT	0x00000100
#define DF_1_TRANS	0x00000200
#define DF_1_INTERPOSE	0x00000400
#define DF_1_NODEFLIB	0x00000800
#define DF_1_NODUMP	0x00001000
#define DF_1_CONFALT	0x00002000
#define DF_1_ENDFILTEE	0x00004000
#define	DF_1_DISPRELDNE	0x00008000
#define	DF_1_DISPRELPND	0x00010000
#define	DF_1_NODIRECT	0x00020000
#define	DF_1_IGNMULDEF	0x00040000
#define	DF_1_NOKSYMS	0x00080000
#define	DF_1_NOHDR	0x00100000
#define	DF_1_EDITED	0x00200000
#define	DF_1_NORELOC	0x00400000
#define	DF_1_SYMINTPOSE	0x00800000
#define	DF_1_GLOBAUDIT	0x01000000
#define	DF_1_SINGLETON	0x02000000
#define	DF_1_STUB	0x04000000
#define	DF_1_PIE	0x08000000
#define DTF_1_PARINIT	0x00000001
#define DTF_1_CONFEXP	0x00000002
#define DF_P1_LAZYLOAD	0x00000001
#define DF_P1_GROUPPERM	0x00000002
typedef struct {
Elf32_Half	vd_version;
Elf32_Half	vd_flags;
Elf32_Half	vd_ndx;
Elf32_Half	vd_cnt;
Elf32_Word	vd_hash;
Elf32_Word	vd_aux;
Elf32_Word	vd_next;
} Elf32_Verdef;
typedef struct {
Elf64_Half	vd_version;
Elf64_Half	vd_flags;
Elf64_Half	vd_ndx;
Elf64_Half	vd_cnt;
Elf64_Word	vd_hash;
Elf64_Word	vd_aux;
Elf64_Word	vd_next;
} Elf64_Verdef;
#define VER_DEF_NONE	0
#define VER_DEF_CURRENT	1
#define VER_DEF_NUM	2
#define VER_FLG_BASE	0x1
#define VER_FLG_WEAK	0x2
#define	VER_NDX_LOCAL		0
#define	VER_NDX_GLOBAL		1
#define	VER_NDX_LORESERVE	0xff00
#define	VER_NDX_ELIMINATE	0xff01
typedef struct {
Elf32_Word	vda_name;
Elf32_Word	vda_next;
} Elf32_Verdaux;
typedef struct {
Elf64_Word	vda_name;
Elf64_Word	vda_next;
} Elf64_Verdaux;
typedef struct {
Elf32_Half	vn_version;
Elf32_Half	vn_cnt;
Elf32_Word	vn_file;
Elf32_Word	vn_aux;
Elf32_Word	vn_next;
} Elf32_Verneed;
typedef struct {
Elf64_Half	vn_version;
Elf64_Half	vn_cnt;
Elf64_Word	vn_file;
Elf64_Word	vn_aux;
Elf64_Word	vn_next;
} Elf64_Verneed;
#define VER_NEED_NONE	 0
#define VER_NEED_CURRENT 1
#define VER_NEED_NUM	 2
typedef struct {
Elf32_Word	vna_hash;
Elf32_Half	vna_flags;
Elf32_Half	vna_other;
Elf32_Word	vna_name;
Elf32_Word	vna_next;
} Elf32_Vernaux;
typedef struct {
Elf64_Word	vna_hash;
Elf64_Half	vna_flags;
Elf64_Half	vna_other;
Elf64_Word	vna_name;
Elf64_Word	vna_next;
} Elf64_Vernaux;
#define VER_FLG_WEAK	0x2
typedef struct {
uint32_t a_type;
union {
uint32_t a_val;
} a_un;
} Elf32_auxv_t;
typedef struct {
uint64_t a_type;
union {
uint64_t a_val;
} a_un;
} Elf64_auxv_t;
#define AT_NULL		0
#define AT_IGNORE	1
#define AT_EXECFD	2
#define AT_PHDR		3
#define AT_PHENT	4
#define AT_PHNUM	5
#define AT_PAGESZ	6
#define AT_BASE		7
#define AT_FLAGS	8
#define AT_ENTRY	9
#define AT_NOTELF	10
#define AT_UID		11
#define AT_EUID		12
#define AT_GID		13
#define AT_EGID		14
#define AT_CLKTCK	17
#define AT_PLATFORM	15
#define AT_HWCAP	16
#define AT_FPUCW	18
#define AT_DCACHEBSIZE	19
#define AT_ICACHEBSIZE	20
#define AT_UCACHEBSIZE	21
#define AT_IGNOREPPC	22
#define	AT_SECURE	23
#define AT_BASE_PLATFORM 24
#define AT_RANDOM	25
#define AT_HWCAP2	26
#define AT_EXECFN	31
#define AT_SYSINFO	32
#define AT_SYSINFO_EHDR	33
#define AT_L1I_CACHESHAPE	34
#define AT_L1D_CACHESHAPE	35
#define AT_L2_CACHESHAPE	36
#define AT_L3_CACHESHAPE	37
#define AT_L1I_CACHESIZE	40
#define AT_L1I_CACHEGEOMETRY	41
#define AT_L1D_CACHESIZE	42
#define AT_L1D_CACHEGEOMETRY	43
#define AT_L2_CACHESIZE		44
#define AT_L2_CACHEGEOMETRY	45
#define AT_L3_CACHESIZE		46
#define AT_L3_CACHEGEOMETRY	47
#define AT_MINSIGSTKSZ		51
typedef struct {
Elf32_Word n_namesz;
Elf32_Word n_descsz;
Elf32_Word n_type;
} Elf32_Nhdr;
typedef struct {
Elf64_Word n_namesz;
Elf64_Word n_descsz;
Elf64_Word n_type;
} Elf64_Nhdr;
#define ELF_NOTE_SOLARIS	"SUNW Solaris"
#define ELF_NOTE_GNU		"GNU"
#define ELF_NOTE_PAGESIZE_HINT	1
#define NT_GNU_ABI_TAG	1
#define ELF_NOTE_ABI	NT_GNU_ABI_TAG
#define ELF_NOTE_OS_LINUX	0
#define ELF_NOTE_OS_GNU		1
#define ELF_NOTE_OS_SOLARIS2	2
#define ELF_NOTE_OS_FREEBSD	3
#define NT_GNU_BUILD_ID	3
#define NT_GNU_GOLD_VERSION	4
typedef struct {
Elf32_Xword m_value;
Elf32_Word m_info;
Elf32_Word m_poffset;
Elf32_Half m_repeat;
Elf32_Half m_stride;
} Elf32_Move;
typedef struct {
Elf64_Xword m_value;
Elf64_Xword m_info;
Elf64_Xword m_poffset;
Elf64_Half m_repeat;
Elf64_Half m_stride;
} Elf64_Move;
#define ELF32_M_SYM(info)	((info) >> 8)
#define ELF32_M_SIZE(info)	((unsigned char) (info))
#define ELF32_M_INFO(sym, size)	(((sym) << 8) + (unsigned char) (size))
#define ELF64_M_SYM(info)	ELF32_M_SYM (info)
#define ELF64_M_SIZE(info)	ELF32_M_SIZE (info)
#define ELF64_M_INFO(sym, size)	ELF32_M_INFO (sym, size)
#define EF_CPU32	0x00810000
#define R_386_NONE	   0
#define R_386_32	   1
#define R_386_PC32	   2
#define R_386_GOT32	   3
#define R_386_PLT32	   4
#define R_386_COPY	   5
#define R_386_GLOB_DAT	   6
#define R_386_JMP_SLOT	   7
#define R_386_RELATIVE	   8
#define R_386_GOTOFF	   9
#define R_386_GOTPC	   10
#define R_386_32PLT	   11
#define R_386_TLS_TPOFF	   14
#define R_386_TLS_IE	   15
#define R_386_TLS_GOTIE	   16
#define R_386_TLS_LE	   17
#define R_386_TLS_GD	   18
#define R_386_TLS_LDM	   19
#define R_386_16	   20
#define R_386_PC16	   21
#define R_386_8		   22
#define R_386_PC8	   23
#define R_386_TLS_GD_32	   24
#define R_386_TLS_GD_PUSH  25
#define R_386_TLS_GD_CALL  26
#define R_386_TLS_GD_POP   27
#define R_386_TLS_LDM_32   28
#define R_386_TLS_LDM_PUSH 29
#define R_386_TLS_LDM_CALL 30
#define R_386_TLS_LDM_POP  31
#define R_386_TLS_LDO_32   32
#define R_386_TLS_IE_32	   33
#define R_386_TLS_LE_32	   34
#define R_386_TLS_DTPMOD32 35
#define R_386_TLS_DTPOFF32 36
#define R_386_TLS_TPOFF32  37
#define R_386_SIZE32       38
#define R_386_TLS_GOTDESC  39
#define R_386_TLS_DESC_CALL 40
#define R_386_TLS_DESC     41
#define R_386_IRELATIVE	   42
#define R_386_GOT32X	   43
#define R_386_NUM	   44
typedef union {
struct {
Elf32_Word gt_current_g_value;
Elf32_Word gt_unused;
} gt_header;
struct {
Elf32_Word gt_g_value;
Elf32_Word gt_bytes;
} gt_entry;
} Elf32_gptab;
typedef struct {
Elf32_Word	ri_gprmask;
Elf32_Word	ri_cprmask[4];
Elf32_Sword	ri_gp_value;
} Elf32_RegInfo;
typedef struct {
unsigned char kind;
unsigned char size;
Elf32_Section section;
Elf32_Word info;
} Elf_Options;
#define ODK_NULL	0
#define ODK_REGINFO	1
#define ODK_EXCEPTIONS	2
#define ODK_PAD		3
#define ODK_HWPATCH	4
#define ODK_FILL	5
#define ODK_TAGS	6
#define ODK_HWAND	7
#define ODK_HWOR	8
#define OEX_FPU_MIN	0x1f
#define OEX_FPU_MAX	0x1f00
#define OEX_PAGE0	0x10000
#define OEX_SMM		0x20000
#define OEX_FPDBUG	0x40000
#define OEX_PRECISEFP	OEX_FPDBUG
#define OEX_DISMISS	0x80000
#define OEX_FPU_INVAL	0x10
#define OEX_FPU_DIV0	0x08
#define OEX_FPU_OFLO	0x04
#define OEX_FPU_UFLO	0x02
#define OEX_FPU_INEX	0x01
#define OHW_R4KEOP	0x1
#define OHW_R8KPFETCH	0x2
#define OHW_R5KEOP	0x4
#define OHW_R5KCVTL	0x8
#define OPAD_PREFIX	0x1
#define OPAD_POSTFIX	0x2
#define OPAD_SYMBOL	0x4
typedef struct {
Elf32_Word hwp_flags1;
Elf32_Word hwp_flags2;
} Elf_Options_Hw;
typedef struct {
Elf32_Word l_name;
Elf32_Word l_time_stamp;
Elf32_Word l_checksum;
Elf32_Word l_version;
Elf32_Word l_flags;
} Elf32_Lib;
typedef struct {
Elf64_Word l_name;
Elf64_Word l_time_stamp;
Elf64_Word l_checksum;
Elf64_Word l_version;
Elf64_Word l_flags;
} Elf64_Lib;
#define LL_NONE		  0
#define LL_EXACT_MATCH	  (1 << 0)
#define LL_IGNORE_INT_VER (1 << 1)
#define LL_REQUIRE_MINOR  (1 << 2)
#define LL_EXPORTS	  (1 << 3)
#define LL_DELAY_LOAD	  (1 << 4)
#define LL_DELTA	  (1 << 5)
typedef Elf32_Addr Elf32_Conflict;
#define EF_ARM_RELEXEC		0x01
#define EF_ARM_HASENTRY		0x02
#define EF_ARM_INTERWORK	0x04
#define EF_ARM_APCS_26		0x08
#define EF_ARM_APCS_FLOAT	0x10
#define EF_ARM_PIC		0x20
#define EF_ARM_ALIGN8		0x40
#define EF_ARM_NEW_ABI		0x80
#define EF_ARM_OLD_ABI		0x100
#define EF_ARM_SOFT_FLOAT	0x200
#define EF_ARM_VFP_FLOAT	0x400
#define EF_ARM_MAVERICK_FLOAT	0x800
#define EF_ARM_ABI_FLOAT_SOFT	0x200
#define EF_ARM_ABI_FLOAT_HARD	0x400
#define EF_ARM_SYMSARESORTED	0x04
#define EF_ARM_DYNSYMSUSESEGIDX	0x08
#define EF_ARM_MAPSYMSFIRST	0x10
#define EF_ARM_EABIMASK		0XFF000000
#define EF_ARM_BE8	    0x00800000
#define EF_ARM_LE8	    0x00400000
#define EF_ARM_EABI_VERSION(flags)	((flags) & EF_ARM_EABIMASK)
#define EF_ARM_EABI_UNKNOWN	0x00000000
#define EF_ARM_EABI_VER1	0x01000000
#define EF_ARM_EABI_VER2	0x02000000
#define EF_ARM_EABI_VER3	0x03000000
#define EF_ARM_EABI_VER4	0x04000000
#define EF_ARM_EABI_VER5	0x05000000
#define STT_ARM_TFUNC		STT_LOPROC
#define STT_ARM_16BIT		STT_HIPROC
#define SHF_ARM_ENTRYSECT	0x10000000
#define SHF_ARM_COMDEF		0x80000000
#define PF_ARM_SB		0x10000000
#define PF_ARM_PI		0x20000000
#define PF_ARM_ABS		0x40000000
#define PT_ARM_EXIDX		(PT_LOPROC + 1)
#define SHT_ARM_EXIDX		(SHT_LOPROC + 1)
#define SHT_ARM_PREEMPTMAP	(SHT_LOPROC + 2)
#define SHT_ARM_ATTRIBUTES	(SHT_LOPROC + 3)
#define R_AARCH64_NONE            0
#define R_AARCH64_P32_ABS32	1
#define R_AARCH64_P32_COPY	180
#define R_AARCH64_P32_GLOB_DAT	181
#define R_AARCH64_P32_JUMP_SLOT	182
#define R_AARCH64_P32_RELATIVE	183
#define R_AARCH64_P32_TLS_DTPMOD 184
#define R_AARCH64_P32_TLS_DTPREL 185
#define R_AARCH64_P32_TLS_TPREL	186
#define R_AARCH64_P32_TLSDESC	187
#define R_AARCH64_P32_IRELATIVE	188
#define R_AARCH64_ABS64         257
#define R_AARCH64_ABS32         258
#define R_AARCH64_ABS16		259
#define R_AARCH64_PREL64	260
#define R_AARCH64_PREL32	261
#define R_AARCH64_PREL16	262
#define R_AARCH64_MOVW_UABS_G0	263
#define R_AARCH64_MOVW_UABS_G0_NC 264
#define R_AARCH64_MOVW_UABS_G1	265
#define R_AARCH64_MOVW_UABS_G1_NC 266
#define R_AARCH64_MOVW_UABS_G2	267
#define R_AARCH64_MOVW_UABS_G2_NC 268
#define R_AARCH64_MOVW_UABS_G3	269
#define R_AARCH64_MOVW_SABS_G0	270
#define R_AARCH64_MOVW_SABS_G1	271
#define R_AARCH64_MOVW_SABS_G2	272
#define R_AARCH64_LD_PREL_LO19	273
#define R_AARCH64_ADR_PREL_LO21	274
#define R_AARCH64_ADR_PREL_PG_HI21 275
#define R_AARCH64_ADR_PREL_PG_HI21_NC 276
#define R_AARCH64_ADD_ABS_LO12_NC 277
#define R_AARCH64_LDST8_ABS_LO12_NC 278
#define R_AARCH64_TSTBR14	279
#define R_AARCH64_CONDBR19	280
#define R_AARCH64_JUMP26	282
#define R_AARCH64_CALL26	283
#define R_AARCH64_LDST16_ABS_LO12_NC 284
#define R_AARCH64_LDST32_ABS_LO12_NC 285
#define R_AARCH64_LDST64_ABS_LO12_NC 286
#define R_AARCH64_MOVW_PREL_G0	287
#define R_AARCH64_MOVW_PREL_G0_NC 288
#define R_AARCH64_MOVW_PREL_G1	289
#define R_AARCH64_MOVW_PREL_G1_NC 290
#define R_AARCH64_MOVW_PREL_G2	291
#define R_AARCH64_MOVW_PREL_G2_NC 292
#define R_AARCH64_MOVW_PREL_G3	293
#define R_AARCH64_LDST128_ABS_LO12_NC 299
#define R_AARCH64_MOVW_GOTOFF_G0 300
#define R_AARCH64_MOVW_GOTOFF_G0_NC 301
#define R_AARCH64_MOVW_GOTOFF_G1 302
#define R_AARCH64_MOVW_GOTOFF_G1_NC 303
#define R_AARCH64_MOVW_GOTOFF_G2 304
#define R_AARCH64_MOVW_GOTOFF_G2_NC 305
#define R_AARCH64_MOVW_GOTOFF_G3 306
#define R_AARCH64_GOTREL64	307
#define R_AARCH64_GOTREL32	308
#define R_AARCH64_GOT_LD_PREL19	309
#define R_AARCH64_LD64_GOTOFF_LO15 310
#define R_AARCH64_ADR_GOT_PAGE	311
#define R_AARCH64_LD64_GOT_LO12_NC 312
#define R_AARCH64_LD64_GOTPAGE_LO15 313
#define R_AARCH64_TLSGD_ADR_PREL21 512
#define R_AARCH64_TLSGD_ADR_PAGE21 513
#define R_AARCH64_TLSGD_ADD_LO12_NC 514
#define R_AARCH64_TLSGD_MOVW_G1	515
#define R_AARCH64_TLSGD_MOVW_G0_NC 516
#define R_AARCH64_TLSLD_ADR_PREL21 517
#define R_AARCH64_TLSLD_ADR_PAGE21 518
#define R_AARCH64_TLSLD_ADD_LO12_NC 519
#define R_AARCH64_TLSLD_MOVW_G1	520
#define R_AARCH64_TLSLD_MOVW_G0_NC 521
#define R_AARCH64_TLSLD_LD_PREL19 522
#define R_AARCH64_TLSLD_MOVW_DTPREL_G2 523
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1 524
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC 525
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0 526
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC 527
#define R_AARCH64_TLSLD_ADD_DTPREL_HI12 528
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12 529
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12_NC 530
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12 531
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC 532
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12 533
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC 534
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12 535
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC 536
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12 537
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC 538
#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G1 539
#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC 540
#define R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21 541
#define R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC 542
#define R_AARCH64_TLSIE_LD_GOTTPREL_PREL19 543
#define R_AARCH64_TLSLE_MOVW_TPREL_G2 544
#define R_AARCH64_TLSLE_MOVW_TPREL_G1 545
#define R_AARCH64_TLSLE_MOVW_TPREL_G1_NC 546
#define R_AARCH64_TLSLE_MOVW_TPREL_G0 547
#define R_AARCH64_TLSLE_MOVW_TPREL_G0_NC 548
#define R_AARCH64_TLSLE_ADD_TPREL_HI12 549
#define R_AARCH64_TLSLE_ADD_TPREL_LO12 550
#define R_AARCH64_TLSLE_ADD_TPREL_LO12_NC 551
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12 552
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC 553
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12 554
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC 555
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12 556
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC 557
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12 558
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC 559
#define R_AARCH64_TLSDESC_LD_PREL19 560
#define R_AARCH64_TLSDESC_ADR_PREL21 561
#define R_AARCH64_TLSDESC_ADR_PAGE21 562
#define R_AARCH64_TLSDESC_LD64_LO12 563
#define R_AARCH64_TLSDESC_ADD_LO12 564
#define R_AARCH64_TLSDESC_OFF_G1 565
#define R_AARCH64_TLSDESC_OFF_G0_NC 566
#define R_AARCH64_TLSDESC_LDR	567
#define R_AARCH64_TLSDESC_ADD	568
#define R_AARCH64_TLSDESC_CALL	569
#define R_AARCH64_TLSLE_LDST128_TPREL_LO12 570
#define R_AARCH64_TLSLE_LDST128_TPREL_LO12_NC 571
#define R_AARCH64_TLSLD_LDST128_DTPREL_LO12 572
#define R_AARCH64_TLSLD_LDST128_DTPREL_LO12_NC 573
#define R_AARCH64_COPY         1024
#define R_AARCH64_GLOB_DAT     1025
#define R_AARCH64_JUMP_SLOT    1026
#define R_AARCH64_RELATIVE     1027
#define R_AARCH64_TLS_DTPMOD   1028
#define R_AARCH64_TLS_DTPMOD64 1028
#define R_AARCH64_TLS_DTPREL   1029
#define R_AARCH64_TLS_DTPREL64 1029
#define R_AARCH64_TLS_TPREL    1030
#define R_AARCH64_TLS_TPREL64  1030
#define R_AARCH64_TLSDESC      1031
#define R_ARM_NONE		0
#define R_ARM_PC24		1
#define R_ARM_ABS32		2
#define R_ARM_REL32		3
#define R_ARM_PC13		4
#define R_ARM_ABS16		5
#define R_ARM_ABS12		6
#define R_ARM_THM_ABS5		7
#define R_ARM_ABS8		8
#define R_ARM_SBREL32		9
#define R_ARM_THM_PC22		10
#define R_ARM_THM_PC8		11
#define R_ARM_AMP_VCALL9	12
#define R_ARM_TLS_DESC		13
#define R_ARM_THM_SWI8		14
#define R_ARM_XPC25		15
#define R_ARM_THM_XPC22		16
#define R_ARM_TLS_DTPMOD32	17
#define R_ARM_TLS_DTPOFF32	18
#define R_ARM_TLS_TPOFF32	19
#define R_ARM_COPY		20
#define R_ARM_GLOB_DAT		21
#define R_ARM_JUMP_SLOT		22
#define R_ARM_RELATIVE		23
#define R_ARM_GOTOFF		24
#define R_ARM_GOTPC		25
#define R_ARM_GOT32		26
#define R_ARM_PLT32		27
#define R_ARM_CALL		28
#define R_ARM_JUMP24		29
#define R_ARM_THM_JUMP24	30
#define R_ARM_BASE_ABS		31
#define R_ARM_ALU_PCREL_7_0	32
#define R_ARM_ALU_PCREL_15_8	33
#define R_ARM_ALU_PCREL_23_15	34
#define R_ARM_LDR_SBREL_11_0	35
#define R_ARM_ALU_SBREL_19_12	36
#define R_ARM_ALU_SBREL_27_20	37
#define R_ARM_TARGET1		38
#define R_ARM_SBREL31		39
#define R_ARM_V4BX		40
#define R_ARM_TARGET2		41
#define R_ARM_PREL31		42
#define R_ARM_MOVW_ABS_NC	43
#define R_ARM_MOVT_ABS		44
#define R_ARM_MOVW_PREL_NC	45
#define R_ARM_MOVT_PREL		46
#define R_ARM_THM_MOVW_ABS_NC	47
#define R_ARM_THM_MOVT_ABS	48
#define R_ARM_THM_MOVW_PREL_NC	49
#define R_ARM_THM_MOVT_PREL	50
#define R_ARM_THM_JUMP19	51
#define R_ARM_THM_JUMP6		52
#define R_ARM_THM_ALU_PREL_11_0	53
#define R_ARM_THM_PC12		54
#define R_ARM_ABS32_NOI		55
#define R_ARM_REL32_NOI		56
#define R_ARM_ALU_PC_G0_NC	57
#define R_ARM_ALU_PC_G0		58
#define R_ARM_ALU_PC_G1_NC	59
#define R_ARM_ALU_PC_G1		60
#define R_ARM_ALU_PC_G2		61
#define R_ARM_LDR_PC_G1		62
#define R_ARM_LDR_PC_G2		63
#define R_ARM_LDRS_PC_G0	64
#define R_ARM_LDRS_PC_G1	65
#define R_ARM_LDRS_PC_G2	66
#define R_ARM_LDC_PC_G0		67
#define R_ARM_LDC_PC_G1		68
#define R_ARM_LDC_PC_G2		69
#define R_ARM_ALU_SB_G0_NC	70
#define R_ARM_ALU_SB_G0		71
#define R_ARM_ALU_SB_G1_NC	72
#define R_ARM_ALU_SB_G1		73
#define R_ARM_ALU_SB_G2		74
#define R_ARM_LDR_SB_G0		75
#define R_ARM_LDR_SB_G1		76
#define R_ARM_LDR_SB_G2		77
#define R_ARM_LDRS_SB_G0	78
#define R_ARM_LDRS_SB_G1	79
#define R_ARM_LDRS_SB_G2	80
#define R_ARM_LDC_SB_G0		81
#define R_ARM_LDC_SB_G1		82
#define R_ARM_LDC_SB_G2		83
#define R_ARM_MOVW_BREL_NC	84
#define R_ARM_MOVT_BREL		85
#define R_ARM_MOVW_BREL		86
#define R_ARM_THM_MOVW_BREL_NC	87
#define R_ARM_THM_MOVT_BREL	88
#define R_ARM_THM_MOVW_BREL	89
#define R_ARM_TLS_GOTDESC	90
#define R_ARM_TLS_CALL		91
#define R_ARM_TLS_DESCSEQ	92
#define R_ARM_THM_TLS_CALL	93
#define R_ARM_PLT32_ABS		94
#define R_ARM_GOT_ABS		95
#define R_ARM_GOT_PREL		96
#define R_ARM_GOT_BREL12	97
#define R_ARM_GOTOFF12		98
#define R_ARM_GOTRELAX		99
#define R_ARM_GNU_VTENTRY	100
#define R_ARM_GNU_VTINHERIT	101
#define R_ARM_THM_PC11		102
#define R_ARM_THM_PC9		103
#define R_ARM_TLS_GD32		104
#define R_ARM_TLS_LDM32		105
#define R_ARM_TLS_LDO32		106
#define R_ARM_TLS_IE32		107
#define R_ARM_TLS_LE32		108
#define R_ARM_TLS_LDO12		109
#define R_ARM_TLS_LE12		110
#define R_ARM_TLS_IE12GP	111
#define R_ARM_ME_TOO		128
#define R_ARM_THM_TLS_DESCSEQ	129
#define R_ARM_THM_TLS_DESCSEQ16	129
#define R_ARM_THM_TLS_DESCSEQ32	130
#define R_ARM_THM_GOT_BREL12	131
#define R_ARM_IRELATIVE		160
#define R_ARM_RXPC25		249
#define R_ARM_RSBREL32		250
#define R_ARM_THM_RPC22		251
#define R_ARM_RREL32		252
#define R_ARM_RABS22		253
#define R_ARM_RPC24		254
#define R_ARM_RBASE		255
#define R_ARM_NUM		256
#define EF_IA_64_MASKOS		0x0000000f
#define EF_IA_64_ABI64		0x00000010
#define EF_IA_64_ARCH		0xff000000
#define PT_IA_64_ARCHEXT	(PT_LOPROC + 0)
#define PT_IA_64_UNWIND		(PT_LOPROC + 1)
#define PT_IA_64_HP_OPT_ANOT	(PT_LOOS + 0x12)
#define PT_IA_64_HP_HSL_ANOT	(PT_LOOS + 0x13)
#define PT_IA_64_HP_STACK	(PT_LOOS + 0x14)
#define PF_IA_64_NORECOV	0x80000000
#define SHT_IA_64_EXT		(SHT_LOPROC + 0)
#define SHT_IA_64_UNWIND	(SHT_LOPROC + 1)
#define SHF_IA_64_SHORT		0x10000000
#define SHF_IA_64_NORECOV	0x20000000
#define DT_IA_64_PLT_RESERVE	(DT_LOPROC + 0)
#define DT_IA_64_NUM		1
#define R_IA64_NONE		0x00
#define R_IA64_IMM14		0x21
#define R_IA64_IMM22		0x22
#define R_IA64_IMM64		0x23
#define R_IA64_DIR32MSB		0x24
#define R_IA64_DIR32LSB		0x25
#define R_IA64_DIR64MSB		0x26
#define R_IA64_DIR64LSB		0x27
#define R_IA64_GPREL22		0x2a
#define R_IA64_GPREL64I		0x2b
#define R_IA64_GPREL32MSB	0x2c
#define R_IA64_GPREL32LSB	0x2d
#define R_IA64_GPREL64MSB	0x2e
#define R_IA64_GPREL64LSB	0x2f
#define R_IA64_LTOFF22		0x32
#define R_IA64_LTOFF64I		0x33
#define R_IA64_PLTOFF22		0x3a
#define R_IA64_PLTOFF64I	0x3b
#define R_IA64_PLTOFF64MSB	0x3e
#define R_IA64_PLTOFF64LSB	0x3f
#define R_IA64_FPTR64I		0x43
#define R_IA64_FPTR32MSB	0x44
#define R_IA64_FPTR32LSB	0x45
#define R_IA64_FPTR64MSB	0x46
#define R_IA64_FPTR64LSB	0x47
#define R_IA64_PCREL60B		0x48
#define R_IA64_PCREL21B		0x49
#define R_IA64_PCREL21M		0x4a
#define R_IA64_PCREL21F		0x4b
#define R_IA64_PCREL32MSB	0x4c
#define R_IA64_PCREL32LSB	0x4d
#define R_IA64_PCREL64MSB	0x4e
#define R_IA64_PCREL64LSB	0x4f
#define R_IA64_LTOFF_FPTR22	0x52
#define R_IA64_LTOFF_FPTR64I	0x53
#define R_IA64_LTOFF_FPTR32MSB	0x54
#define R_IA64_LTOFF_FPTR32LSB	0x55
#define R_IA64_LTOFF_FPTR64MSB	0x56
#define R_IA64_LTOFF_FPTR64LSB	0x57
#define R_IA64_SEGREL32MSB	0x5c
#define R_IA64_SEGREL32LSB	0x5d
#define R_IA64_SEGREL64MSB	0x5e
#define R_IA64_SEGREL64LSB	0x5f
#define R_IA64_SECREL32MSB	0x64
#define R_IA64_SECREL32LSB	0x65
#define R_IA64_SECREL64MSB	0x66
#define R_IA64_SECREL64LSB	0x67
#define R_IA64_REL32MSB		0x6c
#define R_IA64_REL32LSB		0x6d
#define R_IA64_REL64MSB		0x6e
#define R_IA64_REL64LSB		0x6f
#define R_IA64_LTV32MSB		0x74
#define R_IA64_LTV32LSB		0x75
#define R_IA64_LTV64MSB		0x76
#define R_IA64_LTV64LSB		0x77
#define R_IA64_PCREL21BI	0x79
#define R_IA64_PCREL22		0x7a
#define R_IA64_PCREL64I		0x7b
#define R_IA64_IPLTMSB		0x80
#define R_IA64_IPLTLSB		0x81
#define R_IA64_COPY		0x84
#define R_IA64_SUB		0x85
#define R_IA64_LTOFF22X		0x86
#define R_IA64_LDXMOV		0x87
#define R_IA64_TPREL14		0x91
#define R_IA64_TPREL22		0x92
#define R_IA64_TPREL64I		0x93
#define R_IA64_TPREL64MSB	0x96
#define R_IA64_TPREL64LSB	0x97
#define R_IA64_LTOFF_TPREL22	0x9a
#define R_IA64_DTPMOD64MSB	0xa6
#define R_IA64_DTPMOD64LSB	0xa7
#define R_IA64_LTOFF_DTPMOD22	0xaa
#define R_IA64_DTPREL14		0xb1
#define R_IA64_DTPREL22		0xb2
#define R_IA64_DTPREL64I	0xb3
#define R_IA64_DTPREL32MSB	0xb4
#define R_IA64_DTPREL32LSB	0xb5
#define R_IA64_DTPREL64MSB	0xb6
#define R_IA64_DTPREL64LSB	0xb7
#define R_IA64_LTOFF_DTPREL22	0xba
#define R_X86_64_NONE		0
#define R_X86_64_64		1
#define R_X86_64_PC32		2
#define R_X86_64_GOT32		3
#define R_X86_64_PLT32		4
#define R_X86_64_COPY		5
#define R_X86_64_GLOB_DAT	6
#define R_X86_64_JUMP_SLOT	7
#define R_X86_64_RELATIVE	8
#define R_X86_64_GOTPCREL	9
#define R_X86_64_32		10
#define R_X86_64_32S		11
#define R_X86_64_16		12
#define R_X86_64_PC16		13
#define R_X86_64_8		14
#define R_X86_64_PC8		15
#define R_X86_64_DTPMOD64	16
#define R_X86_64_DTPOFF64	17
#define R_X86_64_TPOFF64	18
#define R_X86_64_TLSGD		19
#define R_X86_64_TLSLD		20
#define R_X86_64_DTPOFF32	21
#define R_X86_64_GOTTPOFF	22
#define R_X86_64_TPOFF32	23
#define R_X86_64_PC64		24
#define R_X86_64_GOTOFF64	25
#define R_X86_64_GOTPC32	26
#define R_X86_64_GOT64		27
#define R_X86_64_GOTPCREL64	28
#define R_X86_64_GOTPC64	29
#define R_X86_64_GOTPLT64	30
#define R_X86_64_PLTOFF64	31
#define R_X86_64_SIZE32		32
#define R_X86_64_SIZE64		33
#define R_X86_64_GOTPC32_TLSDESC 34
#define R_X86_64_TLSDESC_CALL   35
#define R_X86_64_TLSDESC        36
#define R_X86_64_IRELATIVE	37
#define R_X86_64_RELATIVE64	38
#define R_X86_64_GOTPCRELX	41
#define R_X86_64_REX_GOTPCRELX	42
#define R_X86_64_NUM		43
#ifdef __cplusplus
}
#endif
#endif
#endif
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
static __inline uint16_t __bswap16(uint16_t __x)
{
return __x<<8 | __x>>8;
}
static __inline uint32_t __bswap32(uint32_t __x)
{
return( (__x>>24) | (__x>>8&0xff00) | (__x<<8&0xff0000) | (__x<<24));
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
#ifndef	_TERMIOS_H
#define	_TERMIOS_H
#endif
#ifndef	_sys_stat_h
#define	_sys_stat_h
#ifdef __cplusplus
extern "C" {
#endif
#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif
#ifndef stat_defined
#define stat_defined
struct stat {
dev_t st_dev;
ino_t st_ino;
nlink_t st_nlink;
mode_t st_mode;
uid_t st_uid;
gid_t st_gid;
unsigned int    __pad0;
dev_t st_rdev;
off_t st_size;
blksize_t st_blksize;
blkcnt_t st_blocks;
struct timespec st_atim;
struct timespec st_mtim;
struct timespec st_ctim;
long __unused[3];
};
#endif
#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
#define S_TYPEISMQ(buf)  0
#define S_TYPEISSEM(buf) 0
#define S_TYPEISSHM(buf) 0
#define S_TYPEISTMO(buf) 0
#define UTIME_NOW  0x3fffffff
#define UTIME_OMIT 0x3ffffffe
#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#endif
#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define stat64 stat
#define fstat64 fstat
#define lstat64 lstat
#define fstatat64 fstatat
#define blkcnt64_t blkcnt_t
#define fsblkcnt64_t fsblkcnt_t
#define fsfilcnt64_t fsfilcnt_t
#define ino64_t ino_t
#define off64_t off_t
#endif
#ifdef __cplusplus
}
#endif
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
static __inline uint16_t __bswap16(uint16_t __x)
{
return __x<<8 | __x>>8;
}
static __inline uint32_t __bswap32(uint32_t __x)
{
return( (__x>>24) | (__x>>8&0xff00) | (__x<<8&0xff0000) | (__x<<24));
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
#ifndef sys_kdb_h
#define sys_kbd_h
#define PIO_FONTRESET   0x4B6D	
#define GIO_CMAP	0x4B70	
#define PIO_CMAP	0x4B71	
#define KIOCSOUND	0x4B2F	
#define KDMKTONE	0x4B30	
#define KDGETLED	0x4B31	
#define KDSETLED	0x4B32	
#define LED_SCR		0x01	
#define LED_CAP		0x04	
#define LED_NUM		0x02	
#define KDGKBTYPE	0x4B33	
#define KB_84		0x01
#define KB_101		0x02 	
#define KB_OTHER	0x03
#define KDADDIO		0x4B34	
#define KDDELIO		0x4B35	
#define KDENABIO	0x4B36	
#define KDDISABIO	0x4B37	
#define KDSETMODE	0x4B3A	
#define KD_TEXT		0x00
#define KD_GRAPHICS	0x01
#define KD_TEXT0	0x02	
#define KD_TEXT1	0x03	
#define KDGETMODE	0x4B3B	
#define KDMAPDISP	0x4B3C	
#define KDUNMAPDISP	0x4B3D	
#define UNI_DIRECT_BASE 0xF000	
#define UNI_DIRECT_MASK 0x01FF	
#define K_RAW		0x00
#define K_XLATE		0x01
#define K_MEDIUMRAW	0x02
#define K_UNICODE	0x03
#define KDGKBMODE	0x4B44	
#define KDSKBMODE	0x4B45	
#define K_METABIT	0x03
#define K_ESCPREFIX	0x04
#define KDGKBMETA	0x4B62	
#define KDSKBMETA	0x4B63	
#define K_SCROLLLOCK	0x01
#define K_CAPSLOCK	0x02
#define K_NUMLOCK	0x04
#define KDGKBLED	0x4B64	
#define KDSKBLED	0x4B65	
#endif
#ifndef	ML_SOCKET_H
#define	ML_SOCKET_H
struct sockaddr {
sa_family_t sa_family;
char sa_data[14];
};
#endif
#ifndef mini_dirent_h
#define mini_dirent_h
#ifdef mini_opendir
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#endif
#ifdef mini_dirbuf
#ifndef mini_dirbufsize
#define mini_dirbufsize 2048
#endif
#ifndef mini_dirbuf_malloc
#define DIRBUF_MALLOC malloc
#ifndef mini_buf
#error mini_buf not set. Try using malloc_brk for mini_dirbuf_malloc
#endif
#if mini_buf < mini_dirbufsize
#error mini_buf < dirbufsize
#endif
#else
#define DIRBUF_MALLOC mini_dirbuf_malloc
#endif
#else // ifdef dirbuf
#define mini_dirbufsize 0
#endif
struct __dirstream{
off_t tell;
int fd;
int buf_pos;
int buf_end;
int align;
char buf[mini_dirbufsize];
};
typedef struct __dirstream DIR;
struct dirent {
ino_t d_ino;
off_t d_off;
unsigned short d_reclen;
char d_name[];
};
#endif
#ifndef signal_h
#define signal_h
#ifndef linux_x64_signal_h
#define linux_x64_signal_h
typedef long __band_t;
typedef union sigval {
int sival_int;
void *sival_ptr;
} sigval_t;
typedef struct siginfo {
int32_t si_signo;
int32_t si_errno;
int32_t si_code;
union {
char __pad[128 - 2*sizeof(int) - sizeof(long)];
struct {
pid_t _pid;   
uid_t _uid;   
} _kill;
struct {
uint32_t _timer1;
uint32_t _timer2;
} _timer;
struct {
pid_t _pid;   
uid_t _uid;   
sigval_t _sigval;
} _rt;
struct {
pid_t _pid;   
uid_t _uid;   
int32_t _status;    
clock_t _utime;
clock_t _stime;
} _sigchld;
struct {
void *_addr; 
} _sigfault;
struct {
__band_t _band; 
int32_t _fd;
} _sigpoll;
} _sifields;
} siginfo_t;
typedef struct __sigset_t { unsigned long sig; } sigset_t;
struct sigaction {
void (*sa_handler)(int);
unsigned long sa_flags;
void (*restorer)(void);
sigset_t sa_mask;
};
#endif
#define SIG_ERR  ((void (*)(int))-1)
#define SIG_DFL  ((void (*)(int)) 0)
#define SIG_IGN  ((void (*)(int)) 1)
#endif
#ifndef mini_time_h
#define mini_time_h
#define TFD_NONBLOCK O_NONBLOCK
#define TFD_CLOEXEC O_CLOEXEC
#define TFD_TIMER_ABSTIME 1
#define TFD_TIMER_CANCEL_ON_SET (1 << 1)
#define CLOCK_REALTIME           0
#define CLOCK_MONOTONIC          1
#define CLOCK_PROCESS_CPUTIME_ID 2
#define CLOCK_THREAD_CPUTIME_ID  3
#define CLOCK_MONOTONIC_RAW      4
#define CLOCK_REALTIME_COARSE    5
#define CLOCK_MONOTONIC_COARSE   6
#define CLOCK_BOOTTIME           7
#define CLOCK_REALTIME_ALARM     8
#define CLOCK_BOOTTIME_ALARM     9
#define CLOCK_SGI_CYCLE         10
#define CLOCK_TAI               11
#define TIMER_ABSTIME 1
struct itimerspec {
struct timespec it_interval;
struct timespec it_value;
};
#endif
#ifndef mini_limits_h
#define mini_limits_h
#define _POSIX_AIO_LISTIO_MAX   2
#define _POSIX_AIO_MAX          1
#define _POSIX_ARG_MAX          4096
#define _POSIX_CHILD_MAX        25
#define _POSIX_CLOCKRES_MIN     20000000
#define _POSIX_DELAYTIMER_MAX   32
#define _POSIX_HOST_NAME_MAX    255
#define _POSIX_LINK_MAX         8
#define _POSIX_LOGIN_NAME_MAX   9
#define _POSIX_MAX_CANON        255
#define _POSIX_MAX_INPUT        255
#define _POSIX_MQ_OPEN_MAX      8
#define _POSIX_MQ_PRIO_MAX      32
#define _POSIX_NAME_MAX         14
#define _POSIX_NGROUPS_MAX      8
#define _POSIX_OPEN_MAX         20
#define _POSIX_PATH_MAX         256
#define _POSIX_PIPE_BUF         512
#define _POSIX_RE_DUP_MAX       255
#define _POSIX_RTSIG_MAX        8
#define _POSIX_SEM_NSEMS_MAX    256
#define _POSIX_SEM_VALUE_MAX    32767
#define _POSIX_SIGQUEUE_MAX     32
#define _POSIX_SSIZE_MAX        32767
#define _POSIX_STREAM_MAX       8
#define _POSIX_SS_REPL_MAX      4
#define _POSIX_SYMLINK_MAX      255
#define _POSIX_SYMLOOP_MAX      8
#define _POSIX_THREAD_DESTRUCTOR_ITERATIONS 4
#define _POSIX_THREAD_KEYS_MAX  128
#define _POSIX_THREAD_THREADS_MAX 64
#define _POSIX_TIMER_MAX        32
#define _POSIX_TRACE_EVENT_NAME_MAX 30
#define _POSIX_TRACE_NAME_MAX   8
#define _POSIX_TRACE_SYS_MAX    8
#define _POSIX_TRACE_USER_EVENT_MAX 32
#define _POSIX_TTY_NAME_MAX     9
#define _POSIX_TZNAME_MAX       6
#define _POSIX2_BC_BASE_MAX     99
#define _POSIX2_BC_DIM_MAX      2048
#define _POSIX2_BC_SCALE_MAX    99
#define _POSIX2_BC_STRING_MAX   1000
#define _POSIX2_CHARCLASS_NAME_MAX 14
#define _POSIX2_COLL_WEIGHTS_MAX 2
#define _POSIX2_EXPR_NEST_MAX   32
#define _POSIX2_LINE_MAX        2048
#define _POSIX2_RE_DUP_MAX      255
#define _XOPEN_IOV_MAX          16
#define _XOPEN_NAME_MAX         255
#define _XOPEN_PATH_MAX         1024
#endif
#endif
#ifndef linux_x64_allheaders_h
#define linux_x64_allheaders_h
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
#endif 
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
#endif 
#ifndef linux_x64_signal_h
#define linux_x64_signal_h
typedef long __band_t;
typedef union sigval {
int sival_int;
void *sival_ptr;
} sigval_t;
typedef struct siginfo {
int32_t si_signo;
int32_t si_errno;
int32_t si_code;
union {
char __pad[128 - 2*sizeof(int) - sizeof(long)];
struct {
pid_t _pid;   
uid_t _uid;   
} _kill;
struct {
uint32_t _timer1;
uint32_t _timer2;
} _timer;
struct {
pid_t _pid;   
uid_t _uid;   
sigval_t _sigval;
} _rt;
struct {
pid_t _pid;   
uid_t _uid;   
int32_t _status;    
clock_t _utime;
clock_t _stime;
} _sigchld;
struct {
void *_addr; 
} _sigfault;
struct {
__band_t _band; 
int32_t _fd;
} _sigpoll;
} _sifields;
} siginfo_t;
typedef struct __sigset_t { unsigned long sig; } sigset_t;
struct sigaction {
void (*sa_handler)(int);
unsigned long sa_flags;
void (*restorer)(void);
sigset_t sa_mask;
};
#endif
#ifndef mini_sys_prctl_h
#define mini_sys_prctl_h
#define PR_SET_PDEATHSIG  1
#define PR_GET_PDEATHSIG  2
#define PR_GET_DUMPABLE   3
#define PR_SET_DUMPABLE   4
#define PR_GET_UNALIGN   5
#define PR_SET_UNALIGN   6
#define PR_UNALIGN_NOPRINT 1
#define PR_UNALIGN_SIGBUS 2
#define PR_GET_KEEPCAPS   7
#define PR_SET_KEEPCAPS   8
#define PR_GET_FPEMU  9
#define PR_SET_FPEMU 10
#define PR_FPEMU_NOPRINT 1
#define PR_FPEMU_SIGFPE 2
#define PR_GET_FPEXC 11
#define PR_SET_FPEXC 12
#define PR_FP_EXC_SW_ENABLE 0x80
#define PR_FP_EXC_DIV  0x010000
#define PR_FP_EXC_OVF  0x020000
#define PR_FP_EXC_UND  0x040000
#define PR_FP_EXC_RES  0x080000
#define PR_FP_EXC_INV  0x100000
#define PR_FP_EXC_DISABLED 0
#define PR_FP_EXC_NONRECOV 1
#define PR_FP_EXC_ASYNC 2
#define PR_FP_EXC_PRECISE 3
#define PR_GET_TIMING   13
#define PR_SET_TIMING   14
#define PR_TIMING_STATISTICAL  0
#define PR_TIMING_TIMESTAMP    1
#define PR_SET_NAME    15
#define PR_GET_NAME    16
#define PR_GET_ENDIAN 19
#define PR_SET_ENDIAN 20
#define PR_ENDIAN_BIG 0
#define PR_ENDIAN_LITTLE 1
#define PR_ENDIAN_PPC_LITTLE 2
#define PR_GET_SECCOMP 21
#define PR_SET_SECCOMP 22
#define PR_CAPBSET_READ 23
#define PR_CAPBSET_DROP 24
#define PR_GET_TSC 25
#define PR_SET_TSC 26
#define PR_TSC_ENABLE 1
#define PR_TSC_SIGSEGV 2
#define PR_GET_SECUREBITS 27
#define PR_SET_SECUREBITS 28
#define PR_SET_TIMERSLACK 29
#define PR_GET_TIMERSLACK 30
#define PR_TASK_PERF_EVENTS_DISABLE             31
#define PR_TASK_PERF_EVENTS_ENABLE              32
#define PR_MCE_KILL     33
#define PR_MCE_KILL_CLEAR   0
#define PR_MCE_KILL_SET     1
#define PR_MCE_KILL_LATE    0
#define PR_MCE_KILL_EARLY   1
#define PR_MCE_KILL_DEFAULT 2
#define PR_MCE_KILL_GET 34
#define PR_SET_MM               35
#define PR_SET_MM_START_CODE           1
#define PR_SET_MM_END_CODE             2
#define PR_SET_MM_START_DATA           3
#define PR_SET_MM_END_DATA             4
#define PR_SET_MM_START_STACK          5
#define PR_SET_MM_START_BRK            6
#define PR_SET_MM_BRK                  7
#define PR_SET_MM_ARG_START            8
#define PR_SET_MM_ARG_END              9
#define PR_SET_MM_ENV_START            10
#define PR_SET_MM_ENV_END              11
#define PR_SET_MM_AUXV                 12
#define PR_SET_MM_EXE_FILE             13
#define PR_SET_MM_MAP                  14
#define PR_SET_MM_MAP_SIZE             15
struct prctl_mm_map {
uint64_t start_code;
uint64_t end_code;
uint64_t start_data;
uint64_t end_data;
uint64_t start_brk;
uint64_t brk;
uint64_t start_stack;
uint64_t arg_start;
uint64_t arg_end;
uint64_t env_start;
uint64_t env_end;
uint64_t *auxv;
uint32_t auxv_size;
uint32_t exe_fd;
};
#define PR_SET_PTRACER 0x59616d61
#define PR_SET_PTRACER_ANY (-1UL)
#define PR_SET_CHILD_SUBREAPER  36
#define PR_GET_CHILD_SUBREAPER  37
#define PR_SET_NO_NEW_PRIVS     38
#define PR_GET_NO_NEW_PRIVS     39
#define PR_GET_TID_ADDRESS      40
#define PR_SET_THP_DISABLE      41
#define PR_GET_THP_DISABLE      42
#define PR_MPX_ENABLE_MANAGEMENT  43
#define PR_MPX_DISABLE_MANAGEMENT 44
#define PR_SET_FP_MODE          45
#define PR_GET_FP_MODE          46
#define PR_FP_MODE_FR (1 << 0)
#define PR_FP_MODE_FRE (1 << 1)
#define PR_CAP_AMBIENT          47
#define PR_CAP_AMBIENT_IS_SET   1
#define PR_CAP_AMBIENT_RAISE    2
#define PR_CAP_AMBIENT_LOWER    3
#define PR_CAP_AMBIENT_CLEAR_ALL 4
#define PR_SVE_SET_VL           50
#define PR_SVE_SET_VL_ONEXEC (1 << 18)
#define PR_SVE_GET_VL           51
#define PR_SVE_VL_LEN_MASK 0xffff
#define PR_SVE_VL_INHERIT (1 << 17)
#define PR_GET_SPECULATION_CTRL 52
#define PR_SET_SPECULATION_CTRL 53
#define PR_SPEC_STORE_BYPASS 0
#define PR_SPEC_INDIRECT_BRANCH 1
#define PR_SPEC_NOT_AFFECTED 0
#define PR_SPEC_PRCTL (1UL << 0)
#define PR_SPEC_ENABLE (1UL << 1)
#define PR_SPEC_DISABLE (1UL << 2)
#define PR_SPEC_FORCE_DISABLE (1UL << 3)
#define PR_SPEC_DISABLE_NOEXEC (1UL << 4)
#define PR_PAC_RESET_KEYS       54
#define PR_PAC_APIAKEY (1UL << 0)
#define PR_PAC_APIBKEY (1UL << 1)
#define PR_PAC_APDAKEY (1UL << 2)
#define PR_PAC_APDBKEY (1UL << 3)
#define PR_PAC_APGAKEY (1UL << 4)
#endif
#ifndef _LINUX_REBOOT_H
#define _LINUX_REBOOT_H
#define	LINUX_REBOOT_MAGIC1	0xfee1dead
#define	LINUX_REBOOT_MAGIC2	672274793
#define	LINUX_REBOOT_MAGIC2A	85072278
#define	LINUX_REBOOT_MAGIC2B	369367448
#define	LINUX_REBOOT_MAGIC2C	537993216
#define	LINUX_REBOOT_CMD_RESTART	0x01234567
#define	LINUX_REBOOT_CMD_HALT		0xCDEF0123
#define	LINUX_REBOOT_CMD_CAD_ON		0x89ABCDEF
#define	LINUX_REBOOT_CMD_CAD_OFF	0x00000000
#define	LINUX_REBOOT_CMD_POWER_OFF	0x4321FEDC
#define	LINUX_REBOOT_CMD_RESTART2	0xA1B2C3D4
#define	LINUX_REBOOT_CMD_SW_SUSPEND	0xD000FCE2
#define	LINUX_REBOOT_CMD_KEXEC		0x45584543
#endif 
#define PAGESIZE 4096
#define LONG_BIT 64
#define LONG_MAX  0x7fffffffffffffffL
#define LLONG_MAX  0x7fffffffffffffffLL
#define CHAR_BIT 8
struct inotify_event {
int wd;
uint32_t mask, cookie, len;
char name[];
};
#define IN_CLOEXEC O_CLOEXEC
#define IN_NONBLOCK O_NONBLOCK
#define IN_ACCESS        0x00000001
#define IN_MODIFY        0x00000002
#define IN_ATTRIB        0x00000004
#define IN_CLOSE_WRITE   0x00000008
#define IN_CLOSE_NOWRITE 0x00000010
#define IN_CLOSE         (IN_CLOSE_WRITE | IN_CLOSE_NOWRITE)
#define IN_OPEN          0x00000020
#define IN_MOVED_FROM    0x00000040
#define IN_MOVED_TO      0x00000080
#define IN_MOVE          (IN_MOVED_FROM | IN_MOVED_TO)
#define IN_CREATE        0x00000100
#define IN_DELETE        0x00000200
#define IN_DELETE_SELF   0x00000400
#define IN_MOVE_SELF     0x00000800
#define IN_ALL_EVENTS    0x00000fff
#define IN_UNMOUNT       0x00002000
#define IN_Q_OVERFLOW    0x00004000
#define IN_IGNORED       0x00008000
#define IN_ONLYDIR       0x01000000
#define IN_DONT_FOLLOW   0x02000000
#define IN_EXCL_UNLINK   0x04000000
#define IN_MASK_CREATE   0x10000000
#define IN_MASK_ADD      0x20000000
#define IN_ISDIR         0x40000000
#define IN_ONESHOT       0x80000000
#ifndef linux_types_h
#define linux_types_h
typedef unsigned long __u64;
typedef unsigned int __u32;
typedef signed long __s64;
typedef signed int __s32;
typedef unsigned short __u16;
typedef signed short __s16;
#endif
#ifndef _LINUX_MOUNT_H
#define _LINUX_MOUNT_H
#define MS_RDONLY	 1	
#define MS_NOSUID	 2	
#define MS_NODEV	 4	
#define MS_NOEXEC	 8	
#define MS_SYNCHRONOUS	16	
#define MS_REMOUNT	32	
#define MS_MANDLOCK	64	
#define MS_DIRSYNC	128	
#define MS_NOATIME	1024	
#define MS_NODIRATIME	2048	
#define MS_BIND		4096
#define MS_MOVE		8192
#define MS_REC		16384
#define MS_VERBOSE	32768	
#define MS_SILENT	32768
#define MS_POSIXACL	(1<<16)	
#define MS_UNBINDABLE	(1<<17)	
#define MS_PRIVATE	(1<<18)	
#define MS_SLAVE	(1<<19)	
#define MS_SHARED	(1<<20)	
#define MS_RELATIME	(1<<21)	
#define MS_KERNMOUNT	(1<<22) 
#define MS_I_VERSION	(1<<23) 
#define MS_STRICTATIME	(1<<24) 
#define MS_LAZYTIME	(1<<25) 
#define MS_SUBMOUNT     (1<<26)
#define MS_NOREMOTELOCK	(1<<27)
#define MS_NOSEC	(1<<28)
#define MS_BORN		(1<<29)
#define MS_ACTIVE	(1<<30)
#define MS_NOUSER	(1<<31)
#define MS_RMT_MASK	(MS_RDONLY|MS_SYNCHRONOUS|MS_MANDLOCK|MS_I_VERSION|\
MS_LAZYTIME)
#define MS_MGC_VAL 0xC0ED0000
#define MS_MGC_MSK 0xffff0000
#define OPEN_TREE_CLONE		1		
#define OPEN_TREE_CLOEXEC	O_CLOEXEC	
#define MOVE_MOUNT_F_SYMLINKS		0x00000001 
#define MOVE_MOUNT_F_AUTOMOUNTS		0x00000002 
#define MOVE_MOUNT_F_EMPTY_PATH		0x00000004 
#define MOVE_MOUNT_T_SYMLINKS		0x00000010 
#define MOVE_MOUNT_T_AUTOMOUNTS		0x00000020 
#define MOVE_MOUNT_T_EMPTY_PATH		0x00000040 
#define MOVE_MOUNT__MASK		0x00000077
#define FSOPEN_CLOEXEC		0x00000001
#define FSPICK_CLOEXEC		0x00000001
#define FSPICK_SYMLINK_NOFOLLOW	0x00000002
#define FSPICK_NO_AUTOMOUNT	0x00000004
#define FSPICK_EMPTY_PATH	0x00000008
enum fsconfig_command {
FSCONFIG_SET_FLAG	= 0,	
FSCONFIG_SET_STRING	= 1,	
FSCONFIG_SET_BINARY	= 2,	
FSCONFIG_SET_PATH	= 3,	
FSCONFIG_SET_PATH_EMPTY	= 4,	
FSCONFIG_SET_FD		= 5,	
FSCONFIG_CMD_CREATE	= 6,	
FSCONFIG_CMD_RECONFIGURE = 7,	
};
#define FSMOUNT_CLOEXEC		0x00000001
#define MOUNT_ATTR_RDONLY	0x00000001 
#define MOUNT_ATTR_NOSUID	0x00000002 
#define MOUNT_ATTR_NODEV	0x00000004 
#define MOUNT_ATTR_NOEXEC	0x00000008 
#define MOUNT_ATTR__ATIME	0x00000070 
#define MOUNT_ATTR_RELATIME	0x00000000 
#define MOUNT_ATTR_NOATIME	0x00000010 
#define MOUNT_ATTR_STRICTATIME	0x00000020 
#define MOUNT_ATTR_NODIRATIME	0x00000080 
#define MNT_FORCE       1
#define MNT_DETACH      2
#define MNT_EXPIRE      4
#define UMOUNT_NOFOLLOW 8
#endif 
#ifndef linux_fcntl_h
#define linux_fcntl_h
#define DN_ACCESS 0x00000001  
#define DN_MODIFY 0x00000002  
#define DN_CREATE 0x00000004  
#define DN_DELETE 0x00000008  
#define DN_RENAME 0x00000010  
#define DN_ATTRIB 0x00000020  
#define DN_MULTISHOT  0x80000000  
#define AT_FDCWD    -100    
#define AT_SYMLINK_NOFOLLOW 0x100   
#define AT_REMOVEDIR    0x200   
#define AT_SYMLINK_FOLLOW 0x400   
#define AT_NO_AUTOMOUNT   0x800 
#define AT_EMPTY_PATH   0x1000  
#define AT_STATX_SYNC_TYPE  0x6000  
#define AT_STATX_SYNC_AS_STAT 0x0000  
#define AT_STATX_FORCE_SYNC 0x2000  
#define AT_STATX_DONT_SYNC  0x4000  
#define AT_RECURSIVE    0x8000  
#endif
#ifndef linux_seccomp_h
#define linux_seccomp_h
#define SECCOMP_MODE_DISABLED	0 
#define SECCOMP_MODE_STRICT	1 
#define SECCOMP_MODE_FILTER	2 
#define SECCOMP_SET_MODE_STRICT		0
#define SECCOMP_SET_MODE_FILTER		1
#define SECCOMP_GET_ACTION_AVAIL	2
#define SECCOMP_GET_NOTIF_SIZES		3
#define SECCOMP_FILTER_FLAG_TSYNC		(1UL << 0)
#define SECCOMP_FILTER_FLAG_LOG			(1UL << 1)
#define SECCOMP_FILTER_FLAG_SPEC_ALLOW		(1UL << 2)
#define SECCOMP_FILTER_FLAG_NEW_LISTENER	(1UL << 3)
#define SECCOMP_RET_KILL_PROCESS 0x80000000U 
#define SECCOMP_RET_KILL_THREAD	 0x00000000U 
#define SECCOMP_RET_KILL	 SECCOMP_RET_KILL_THREAD
#define SECCOMP_RET_TRAP	 0x00030000U 
#define SECCOMP_RET_ERRNO	 0x00050000U 
#define SECCOMP_RET_USER_NOTIF	 0x7fc00000U 
#define SECCOMP_RET_TRACE	 0x7ff00000U 
#define SECCOMP_RET_LOG		 0x7ffc0000U 
#define SECCOMP_RET_ALLOW	 0x7fff0000U 
#define SECCOMP_RET_ACTION_FULL	0xffff0000U
#define SECCOMP_RET_ACTION	0x7fff0000U
#define SECCOMP_RET_DATA	0x0000ffffU
struct seccomp_data {
int nr;
__u32 arch;
__u64 instruction_pointer;
__u64 args[6];
};
struct seccomp_notif_sizes {
__u16 seccomp_notif;
__u16 seccomp_notif_resp;
__u16 seccomp_data;
};
struct seccomp_notif {
__u64 id;
__u32 pid;
__u32 flags;
struct seccomp_data data;
};
struct seccomp_notif_resp {
__u64 id;
__s64 val;
__s32 error;
__u32 flags;
};
#define SECCOMP_IOC_MAGIC		'!'
#define SECCOMP_IO(nr)			_IO(SECCOMP_IOC_MAGIC, nr)
#define SECCOMP_IOR(nr, type)		_IOR(SECCOMP_IOC_MAGIC, nr, type)
#define SECCOMP_IOW(nr, type)		_IOW(SECCOMP_IOC_MAGIC, nr, type)
#define SECCOMP_IOWR(nr, type)		_IOWR(SECCOMP_IOC_MAGIC, nr, type)
#define SECCOMP_IOCTL_NOTIF_RECV	SECCOMP_IOWR(0, struct seccomp_notif)
#define SECCOMP_IOCTL_NOTIF_SEND	SECCOMP_IOWR(1,	\
struct seccomp_notif_resp)
#define SECCOMP_IOCTL_NOTIF_ID_VALID	SECCOMP_IOR(2, __u64)
#endif
#endif
#ifdef mini_pwent
#ifndef mini_pwent_h
#define mini_pwent_h
typedef struct passwd {
char   *pw_name;       
char   *pw_passwd;     
uid_t   pw_uid;        
gid_t   pw_gid;        
char   *pw_gecos;      
char   *pw_dir;        
char   *pw_shell;      
} _passwd;
typedef struct group {
char   *gr_name;        
char   *gr_passwd;      
gid_t   gr_gid;         
char  *gr_mem[MAX_GROUPMEMBERS];         
}_group;
typedef struct {
char* file;
char* p;
char** p2;
int size;
} userdb;
#endif
#endif
#ifdef mini_termio
typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;
#define NCCS 32
struct termios {
tcflag_t c_iflag;
tcflag_t c_oflag;
tcflag_t c_cflag;
tcflag_t c_lflag;
cc_t c_line;
cc_t c_cc[NCCS];
speed_t __c_ispeed;
speed_t __c_ospeed;
};
#define NCC 8
struct termio
{
unsigned short int c_iflag;   
unsigned short int c_oflag;   
unsigned short int c_cflag;   
unsigned short int c_lflag;   
unsigned char c_line;   
unsigned char c_cc[NCC];    
};
#endif
#ifndef minilib_exit_h
#define minilib_exit_h
#ifdef mini_atexit
#ifdef X64
#define exit(ret) asm("jmp _atexit"::"D"(ret))
static inline void __attribute__((noreturn))_exit(int ret){
asm("jmp __exit"::"D"(ret));
__builtin_unreachable();
}
#else
#define exit(ret) asm("jmp _atexit"::"b"(ret))
#define _exit(ret) asm("jmp __exit"::"b"(ret))
#endif
#else
#ifdef X64
static inline void __attribute__((noreturn))exit(int ret){
asm("jmp __exit"::"D"(ret));
__builtin_unreachable();
}
static inline void __attribute__((noreturn))_exit(int ret){
asm("jmp __exit"::"D"(ret));
__builtin_unreachable();
}
#else
#define exit(ret) asm("jmp __exit"::"b"(ret))
#define _exit(ret) asm("jmp __exit"::"b"(ret))
#endif
#endif
#endif
#ifndef minilib_global_h
#define minilib_global_h
#ifdef mini_globals_on_stack
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_errno
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_environ
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifndef mini_pwent
#ifdef mini_getpwent
#define mini_pwent
#endif
#ifdef mini_getpwuid
#define mini_pwent
#endif
#ifdef mini_getpwnam
#define mini_pwent
#endif
#ifdef mini_setpwent
#define mini_pwent
#endif
#endif
#ifndef mini_grent
#ifdef mini_getgrent
#define mini_grent
#endif
#ifdef mini_getgrnam
#define mini_grent
#endif
#ifdef mini_getgroups
#define mini_grent
#endif
#ifdef mini_getgrgid
#define mini_grent
#endif
#endif
#ifdef mini_buf
#if mini_buf > 0
#else
#warning mini_buf defaults to 2048 Bytes
#define mini_buf 2048
#endif
#endif
#ifdef mini_buf
#define mini_bufsize mini_buf
#ifndef mini_globals
#define mini_globals
#endif
#else
#define mini_bufsize 0
#endif
typedef struct {
int errno;
int sysret;
int srand;
int pstream;
int mbufsize;
int align[1];
char **environ;
unsigned long brk;
unsigned long malloc_start;
#ifdef mini_atexit
functionp* atexitp[ATEXIT_MAX];
#endif
void *appdata; // can be used freely.
int stream[mini_FOPEN_MAX];
#ifdef mini_pwent
userdb passwdfile;
struct passwd pwent; // quite some overhead. But needed for threadsafety.
#endif
#ifdef mini_grent
userdb groupfile;
struct group groupent;
#endif
#ifdef mini_inet_ntoa
char inet_ntoa_addr[16];
#endif
union {
int ibuf[(mini_bufsize>>2)];
char mbuf[mini_bufsize];
};
} minilib_globals;
static void __attribute__((noipa,cold)) optimization_fence(void*p){}
#ifdef mini_globals_on_stack
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_globals
#ifndef mini_globals_on_stack
extern minilib_globals*__restrict__ mlgl;
extern minilib_globals __mlgl;
#ifdef mini_errno
extern int errno;
#endif
#ifdef mini_environ
extern char **environ;
#endif
#else //mini_globals_on_stack
register minilib_globals __attribute__((used))*__restrict__ mlgl asm("r15");
#define errno mlgl->errno
#ifdef mini_environ
#define environ mlgl->environ
#endif
#endif //mini_globals_on_stack
#else
#endif
#endif
#ifndef mini_dirent_h
#define mini_dirent_h
#ifdef mini_opendir
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#endif
#ifdef mini_dirbuf
#ifndef mini_dirbufsize
#define mini_dirbufsize 2048
#endif
#ifndef mini_dirbuf_malloc
#define DIRBUF_MALLOC malloc
#ifndef mini_buf
#error mini_buf not set. Try using malloc_brk for mini_dirbuf_malloc
#endif
#if mini_buf < mini_dirbufsize
#error mini_buf < dirbufsize
#endif
#else
#define DIRBUF_MALLOC mini_dirbuf_malloc
#endif
#else // ifdef dirbuf
#define mini_dirbufsize 0
#endif
struct __dirstream{
off_t tell;
int fd;
int buf_pos;
int buf_end;
int align;
char buf[mini_dirbufsize];
};
typedef struct __dirstream DIR;
struct dirent {
ino_t d_ino;
off_t d_off;
unsigned short d_reclen;
char d_name[];
};
#endif
#ifndef mini_filemodes_h
#define mini_filemodes_h
#ifdef OSX
#define	O_RDONLY	0x0000		
#define	O_WRONLY	0x0001		
#define	O_RDWR		0x0002		
#define	O_ACCMODE	0x0003		
#define	FREAD		0x0001
#define	FWRITE		0x0002
#define	O_NONBLOCK	0x0004		
#define	O_APPEND	0x0008		
#define	O_SHLOCK	0x0010		
#define	O_EXLOCK	0x0020		
#define	O_ASYNC		0x0040		
#define	O_FSYNC		O_SYNC		
#define O_NOFOLLOW  0x0100      
#define	O_CREAT		0x0200		
#define	O_CREATE		0x0200		
#define	O_TRUNC		0x0400		
#define	O_EXCL		0x0800		
#define	O_EVTONLY	0x8000		
#define	O_NOCTTY	0x20000		
#define O_DIRECTORY	0x100000
#define O_SYMLINK	0x200000	
#define	O_CLOEXEC	0x1000000	
#define O_DP_GETRAWENCRYPTED	0x0001
#define O_DP_GETRAWUNENCRYPTED	0x0002
#else
#define O_ACCMODE	00000003
#define O_RDONLY	00000000
#define O_WRONLY	00000001
#define O_RDWR		00000002
#define O_CREAT		00000100	
#define O_EXCL		00000200	
#define O_NOCTTY	00000400	
#define O_TRUNC		00001000	
#define O_APPEND	00002000
#define O_NONBLOCK	00004000
#define O_DSYNC		00010000	
#define FASYNC		00020000	
#define O_ASYNC      020000
#define O_DIRECT	00040000	
#define O_LARGEFILE	00100000
#define O_DIRECTORY	00200000	
#define O_NOFOLLOW	00400000	
#define O_NOATIME	01000000
#define O_CLOEXEC	02000000	
#define O_PATH    010000000
#define O_SYNC     04010000
#define O_RSYNC    04010000
#endif
#endif
#ifdef VERBOSE_COMPILATION
#pragma message "=== End of definitions, and beginning of src ==="
#endif
#ifndef syscall_stubs_h
#define syscall_stubs_h
#ifndef mini_globals_on_stack
extern int errno;
#endif
struct stat;
struct timeval;
struct timezone;
typedef unsigned long u64;
typedef unsigned int u32;
typedef long aio_context_t;
typedef long key_serial_t;
typedef long loff_t;
typedef long qid_t;
typedef long mqd_t;
typedef long stack_t;
typedef long umode_t;
typedef long cap_user_data_t;
typedef long cap_user_header_t;
typedef long semun_u;
struct sockaddr;
struct iovcc;
struct rusage;
struct file_handle;
struct utimbuf;
struct sched_attr;
struct sched_param;
struct itimerspec;
struct kexec_segment;
struct task_struct;
struct msghdr;
struct iocb;
struct io_event;
struct linux_dirent64;
struct pt_regs;
struct perf_event_attr;
struct __sysctl_args;
struct timex;
struct msgbuf;
struct pollfd;
struct getcpu_cache;
struct bpf_attr;
struct shmid_ds;
struct epoll_event;
struct mq_attr;
struct poll_fd;
struct mq_attr;
struct sembuf;
struct statfs;
struct sysinfo;
struct rlimit;
struct ustat;
struct itimerval;
struct linux_dirent;
struct robust_list_head;
struct sigevent;
struct siginfo;
struct bpf_attr;
struct msqid_ds;
struct rlimit64;
struct sigaction;
struct mmsghdr;
struct msqid_ds;
#ifndef OSX
#else
#warning Todo: time osx
#endif
#if 1
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
#ifdef mini_rmdir
REAL_define_syscall(rmdir,1, const char *a1)
#endif
#ifdef mini_splice
REAL_define_syscall_noopt(splice,6, int a1,   loff_t *a2,   int a3,   loff_t *a4,  size_t a5,   unsigned int a6)
#endif
#ifdef mini_gettimeofday
REAL_define_syscall(gettimeofday,2, struct timeval *a1,  struct timezone *a2)
#endif
#ifdef mini_nanosleep
REAL_define_syscall(nanosleep,2, struct timespec *a1,  struct timespec *a2)
#endif
#ifdef mini_mprotect
REAL_define_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3)
#endif
#ifdef mini_inotify_init
REAL_define_syscall(inotify_init,0)
#endif
#ifdef mini_recvfrom
REAL_define_syscall_noopt(recvfrom,6, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5,   unsigned int *a6)
#endif
#ifdef mini_getpgrp
REAL_define_syscall(getpgrp,0)
#endif
#ifdef mini_rename
REAL_define_syscall(rename,2, const char* a1,  const char* a2)
#endif
#ifdef mini_setsid
REAL_define_syscall(setsid,0 )
#endif
#ifdef mini_fchmod
REAL_define_syscall(fchmod,2, unsigned int a1,  mode_t a2)
#endif
#ifdef mini_getresuid
REAL_define_syscall(getresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3)
#endif
#ifdef mini_fsync
REAL_define_syscall(fsync,1,int a1)
#endif
#ifdef mini_execveat
REAL_define_syscall_noopt(execveat,5, int a1,  const char *a2,   char* const* a3,  char* const* a4,  int a5)
#endif
#ifdef mini_setreuid
REAL_define_syscall(setreuid,2, uid_t a1,   uid_t a2)
#endif
#ifdef mini_setitimer
REAL_define_syscall(setitimer,3, int a1,   struct itimerval *a2,   struct itimerval *a3)
#endif
#ifdef mini_kill
REAL_define_syscall(kill,2, pid_t a1,   int a2)
#endif
#ifdef mini_setgid
REAL_define_syscall(setgid,1, gid_t a1)
#endif
#ifdef mini_lseek
REAL_define_syscall(lseek,3,unsigned int a1,  int a2,  int a3)
#endif
#ifdef mini_chmod
REAL_define_syscall(chmod,2, const char *a1,  mode_t a2)
#endif
#ifdef mini_vhangup
REAL_define_syscall(vhangup,0 )
#endif
#ifdef mini_rt_sigreturn
REAL_define_syscall(rt_sigreturn,1, unsigned long a1)
#endif
#ifdef mini_munmap
REAL_define_syscall(munmap,2, void* a1,   size_t a2)
#endif
#ifdef mini_msync
REAL_define_syscall(msync,3, void* a1,   size_t a2,  int a3)
#endif
#ifdef mini_setsockopt
REAL_define_syscall_noopt(setsockopt,5, int a1,   int a2,   int a3,   const void *a4,   int a5)
#endif
#ifdef mini_timerfd_create
REAL_define_syscall(timerfd_create,2, int a1,   int a2)
#endif
#ifdef mini_flock
REAL_define_syscall(flock,2, unsigned int a1,   unsigned int a2)
#endif
#ifdef mini_readahead
REAL_define_syscall(readahead,3, int a1,   loff_t a2,   size_t a3)
#endif
#ifdef mini_umount2
REAL_define_syscall(umount2,2, const char *a1,  int a2)
#endif
#ifdef mini_getuid
REAL_define_syscall(getuid,0)
#endif
#ifdef mini_ftruncate
REAL_define_syscall(ftruncate,2,unsigned int a1,  unsigned int a2)
#endif
#ifdef mini_dup2
REAL_define_syscall(dup2,2,int a1,  int a2)
#endif
#ifdef mini_pipe
REAL_define_syscall(pipe,1, int *a1)
#endif
#ifdef mini_chroot
REAL_define_syscall(chroot,1, const char *a1)
#endif
#ifdef mini_dup
REAL_define_syscall(dup,1,int a1)
#endif
#ifdef mini_fstat
REAL_define_syscall(fstat,2,int a1, struct stat* a2)
#endif
#ifdef mini_rt_sigprocmask
REAL_define_syscall_noopt(rt_sigprocmask,4, int a1,   sigset_t *a2,   sigset_t *a3,   size_t a4)
#endif
#ifdef mini_link
REAL_define_syscall(link,2, const char *a1,  const char *a2)
#endif
#ifdef mini_sync
REAL_define_syscall(sync,0)
#endif
#ifdef mini_socket
REAL_define_syscall(socket,3, int a1,   int a2,   int a3)
#endif
#ifdef mini_mount
REAL_define_syscall_noopt(mount,5, char *a1,   char *a2,   char *a3,   unsigned long a4,   void *a5)
#endif
#ifdef mini_clone
REAL_define_syscall_noopt(clone,4, int a1,   unsigned long a2,   void *a3,   void *a4)
#endif
#ifdef mini_fcntl
REAL_define_syscall(fcntl,3, unsigned int a1,  unsigned int a2,  unsigned long a3)
#endif
#ifdef mini_write
REAL_define_syscall(write,3,int a1, const void *a2,  int a3)
#endif
#ifdef mini_getppid
REAL_define_syscall(getppid,0)
#endif
#ifdef mini_read
REAL_define_syscall(read, 3, int a1,  void *a2,  int a3)
#endif
#ifdef mini_stat
REAL_define_syscall(stat,2,const char* a1, struct stat* a2)
#endif
#ifdef mini_getcwd
REAL_define_syscall(getcwd,2, char *a1,   unsigned long a2)
#endif
#ifdef mini_inotify_rm_watch
REAL_define_syscall(inotify_rm_watch,2, int a1,   __s32 a2)
#endif
#ifdef mini_lstat
REAL_define_syscall(lstat,2,const char* a1, struct stat* a2)
#endif
#ifdef mini_close
REAL_define_syscall(close, 1, int a1)
#endif
#ifdef mini_reboot
REAL_define_syscall_noopt(reboot,4, int a1,   int a2,   unsigned int a3,   void *a4)
#endif
#ifdef mini_timerfd_gettime
REAL_define_syscall(timerfd_gettime,2, int a1,   struct itimerspec *a2)
#endif
#ifdef mini_getgid
REAL_define_syscall(getgid,0)
#endif
#ifdef mini_rt_sigaction
REAL_define_syscall_noopt(rt_sigaction,4, int a1,   const struct sigaction *a2,   struct sigaction *a3,   size_t a4)
#endif
#ifdef mini_time
REAL_define_syscall(time,1,unsigned int *a1)
#endif
#ifdef mini_pivot_root
REAL_define_syscall(pivot_root,2, const char *a1,   const char *a2)
#endif
#ifdef mini_symlink
REAL_define_syscall(symlink,2, const char *a1,   const char *a2)
#endif
#ifdef mini_execve
REAL_define_syscall(execve,3, const char *a1,   char* const* a2,  char* const* a3)
#endif
#ifdef mini_getsockopt
REAL_define_syscall_noopt(getsockopt,5, int a1,   int a2,   int a3,   char *a4,   int *a5)
#endif
#ifdef mini_dup3
REAL_define_syscall(dup3,3,int a1,  int a2,  int a3)
#endif
#ifdef mini_bind
REAL_define_syscall(bind,3, int a1,   struct sockaddr *a2,   int a3)
#endif
#ifdef mini_fork
REAL_define_syscall(fork,0)
#endif
#ifdef mini_mkdir
REAL_define_syscall(mkdir,2, const char *a1,  int a2)
#endif
#ifdef mini_unlink
REAL_define_syscall(unlink,1, const char* a1)
#endif
#ifdef mini_setgroups
REAL_define_syscall(setgroups,2, int a1,   gid_t *a2)
#endif
#ifdef mini_sendto
REAL_define_syscall_noopt(sendto,6, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5,   int a6)
#endif
#ifdef mini_getitimer
REAL_define_syscall(getitimer,2, int a1,   struct itimerval *a2)
#endif
#ifdef mini_memfd_create
REAL_define_syscall(memfd_create,2, const char  *a1,   unsigned int a2)
#endif
#ifdef mini_chdir
REAL_define_syscall(chdir,1,const char* a1)
#endif
#ifdef mini_setresuid
REAL_define_syscall(setresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3)
#endif
#ifdef mini_getpid
REAL_define_syscall(getpid,0 )
#endif
#ifdef mini_mknod
REAL_define_syscall(mknod,3, const char *a1,   umode_t a2,   unsigned a3)
#endif
#ifdef mini_wait4
REAL_define_syscall_noopt(wait4,4, pid_t a1,   int *a2,   int a3,   struct rusage *a4)
#endif
#ifdef mini_timerfd_settime
REAL_define_syscall_noopt(timerfd_settime,4, int a1,   int a2,   const struct itimerspec *a3,   struct itimerspec *a4)
#endif
#ifdef mini_umask
REAL_define_syscall(umask,1, int a1)
#endif
#ifdef mini_utime
REAL_define_syscall(utime,2, const char *a1,  struct utimbuf *a2)
#endif
#ifdef mini_rt_sigsuspend
REAL_define_syscall(rt_sigsuspend, 2, const sigset_t *a1,  size_t a2) ;
#endif
#ifdef mini_uname
REAL_define_syscall(uname,1,struct new_utsname *a1)
#endif
#ifdef mini_chown
REAL_define_syscall(chown,3, const char *a1,  uid_t a2,  gid_t a3)
#endif
#ifdef mini_setuid
REAL_define_syscall(setuid,1, uid_t a1)
#endif
#ifdef mini_setpgid
REAL_define_syscall(setpgid,2, pid_t a1,  pid_t a2)
#endif
#ifdef mini_getdents
REAL_define_syscall(getdents, 3, unsigned int a1,  struct dirent *a2,  unsigned int a3)
#endif
#ifdef mini_inotify_init1
REAL_define_syscall(inotify_init1,1, int a1)
#endif
#ifdef mini_sendfile
REAL_define_syscall_noopt(sendfile,4, int a1,   int a2,   off_t *a3,   size_t a4)
#endif
#ifdef mini_prctl
REAL_define_syscall_noopt(prctl,5, int a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5)
#endif
#ifdef mini_vfork
REAL_define_syscall(vfork,0)
#endif
#ifdef mini_access
REAL_define_syscall(access,2, const char *a1,  int a2)
#endif
#ifdef mini_inotify_add_watch
REAL_define_syscall(inotify_add_watch,3, int a1,   const char *a2,   u32 a3)
#endif
#ifdef mini_fchown
REAL_define_syscall(fchown,3, unsigned int a1,  uid_t a2,  gid_t a3)
#endif
#ifdef mini_syscalls
SYSREAL_define_syscall(_getsockname,3, int a1,   struct sockaddr *a2,   int *a3)
SYSREAL_define_syscall(_getresgid,3, gid_t *a1,   gid_t *a2,   gid_t *a3)
SYSREAL_define_syscall(_statfs,2, const char *a1,   struct statfs *a2)
SYSREAL_define_syscall_noopt(_recvmmsg,5, int a1,   struct msghdr *a2,   unsigned int a3,   unsigned int a4,   struct timespec *a5)
SYSREAL_define_syscall(_sendmsg,3, int a1,   struct msghdr *a2,   unsigned a3)
SYSREAL_define_syscall(_shmdt,1, char *a1)
SYSREAL_define_syscall_noopt(_reboot,4, int a1,   int a2,   unsigned int a3,   void *a4)
SYSREAL_define_syscall(_sched_getscheduler,1, pid_t a1)
SYSREAL_define_syscall(_write,3, unsigned int a1,   const char *a2,   size_t a3)
SYSREAL_define_syscall(_vhangup,0)
SYSREAL_define_syscall_noopt(_mq_open,4, const char *a1,   int a2,   mode_t a3,   struct mq_attr *a4)
SYSREAL_define_syscall_noopt(_sendto,6, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5,   int a6)
SYSREAL_define_syscall(_fcntl,3, unsigned int a1,   unsigned int a2,   unsigned long a3)
SYSREAL_define_syscall(_fdatasync,1, unsigned int a1)
SYSREAL_define_syscall(_sched_setaffinity,3, pid_t a1,   unsigned int a2,   unsigned long *a3)
SYSREAL_define_syscall_noopt(_clock_nanosleep,4, const clockid_t a1,   int a2,   const struct timespec *a3,   struct timespec *a4)
SYSREAL_define_syscall(_io_destroy,1, aio_context_t a1)
SYSREAL_define_syscall_noopt(_fsetxattr,5, int a1,   const char *a2,   const void *a3,   size_t a4,  int a5)
SYSREAL_define_syscall_noopt(_pwritev,5, unsigned long a1,   const struct iovec *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5)
SYSREAL_define_syscall(_getcwd,2, char *a1,   unsigned long a2)
SYSREAL_define_syscall(_ftruncate,2, unsigned int a1,   unsigned long a2)
SYSREAL_define_syscall(_truncate,2, const char *a1,   long a2)
SYSREAL_define_syscall_noopt(_prlimit64,4, pid_t a1,   unsigned int a2,   const struct rlimit64 *a3,   struct rlimit64 *a4)
SYSREAL_define_syscall_noopt(_migrate_pages,4, pid_t a1,   unsigned long a2,   const unsigned long *a3,   const unsigned long *a4)
SYSREAL_define_syscall(_swapoff,1, const char *a1)
SYSREAL_define_syscall(_uname,1, struct old_utsname *a1)
SYSREAL_define_syscall_noopt(_kexec_file_load,5, int a1,   int a2,   unsigned long a3,   const char  *a4,   unsigned long a5)
SYSREAL_define_syscall_noopt(_fgetxattr,4, int a1,   const char *a2,   void *a3,   size_t a4)
SYSREAL_define_syscall_noopt(_keyctl,5, int a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5)
SYSREAL_define_syscall(_pivot_root,2, const char *a1,   const char *a2)
SYSREAL_define_syscall(_dup,1, unsigned int a1)
SYSREAL_define_syscall_noopt(_msgrcv,5, int a1,   struct msgbuf *a2,   size_t a3,   long a4,   int a5)
SYSREAL_define_syscall(_stat,2, const char *a1,   struct stat *a2)
SYSREAL_define_syscall(_setfsuid,1, uid_t a1)
SYSREAL_define_syscall(_getitimer,2, int a1,   struct itimerval *a2)
SYSREAL_define_syscall(_restart_syscall,0)
SYSREAL_define_syscall_noopt(_prctl,5, int a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5)
SYSREAL_define_syscall(_rt_sigreturn,1, unsigned long a1)
SYSREAL_define_syscall(_arch_prctl,3, struct task_struct *a1,   int a2,   unsigned long *a3)
SYSREAL_define_syscall(_mkdirat,3, int a1,   const char *a2,   int a3)
SYSREAL_define_syscall(_readahead,3, int a1,   loff_t a2,   size_t a3)
SYSREAL_define_syscall(_timerfd_create,2, int a1,   int a2)
SYSREAL_define_syscall(_mlockall,1, int a1)
SYSREAL_define_syscall(_rt_sigpending,2, sigset_t *a1,   size_t a2)
SYSREAL_define_syscall(_fstat,2, unsigned int a1,   struct stat *a2)
SYSREAL_define_syscall_noopt(_ptrace,4, long a1,   long a2,   unsigned long a3,   unsigned long a4)
SYSREAL_define_syscall(_iopl,2, unsigned int a1,   struct pt_regs *a2)
SYSREAL_define_syscall(_io_setup,2, unsigned a1,   aio_context_t *a2)
SYSREAL_define_syscall(_epoll_create,1, int a1)
SYSREAL_define_syscall(_listxattr,3, const char *a1,   char *a2,   size_t a3)
SYSREAL_define_syscall_noopt(_open_by_handle_at,5, int a1,   const char *a2,   struct file_handle *a3,   int *a4,   int a5)
SYSREAL_define_syscall_noopt(_pselect6,6, int a1,   fd_set *a2,   fd_set *a3,   fd_set *a4,   struct timespec *a5,   void *a6)
SYSREAL_define_syscall(_shmat,3, int a1,   char *a2,   int a3)
SYSREAL_define_syscall(_timer_delete,1, timer_t a1)
SYSREAL_define_syscall(_ioctl,3, unsigned int a1,   unsigned int a2,   unsigned long a3)
SYSREAL_define_syscall(_capget,2, cap_user_header_t a1,   cap_user_data_t a2)
SYSREAL_define_syscall(_eventfd,1, unsigned int a1)
SYSREAL_define_syscall(_getrusage,2, int a1,   struct rusage *a2)
SYSREAL_define_syscall(_chroot,1, const char *a1)
SYSREAL_define_syscall(_rt_sigqueueinfo,3, pid_t a1,   int a2,   siginfo_t *a3)
SYSREAL_define_syscall_noopt(_wait4,4, pid_t a1,   int *a2,   int a3,   struct rusage *a4)
SYSREAL_define_syscall(_umask,1, int a1)
SYSREAL_define_syscall(_timer_create,3, const clockid_t a1,   struct sigevent *a2,   timer_t *a3)
SYSREAL_define_syscall(_getpgrp,0)
SYSREAL_define_syscall(_msync,3, unsigned long a1,   size_t a2,   int a3)
SYSREAL_define_syscall_noopt(_move_pages,6, pid_t a1,   unsigned long a2,   const void *a3,  const int *a4,   int *a5,   int a6)
SYSREAL_define_syscall(_shutdown,2, int a1,   int a2)
SYSREAL_define_syscall(_getpgid,1, pid_t a1)
SYSREAL_define_syscall(_getegid,0)
SYSREAL_define_syscall_noopt(_epoll_pwait,6, int a1,   struct epoll_event *a2,   int a3,   int a4,   const sigset_t *a5,   size_t a6)
SYSREAL_define_syscall_noopt(_mremap,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5)
SYSREAL_define_syscall(_symlinkat,3, const char *a1,   int a2,   const char *a3)
SYSREAL_define_syscall(_swapon,2, const char *a1,   int a2)
SYSREAL_define_syscall(_clock_adjtime,2, clockid_t a1,   struct timex *a2)
SYSREAL_define_syscall_noopt(_remap_file_pages,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5)
SYSREAL_define_syscall_noopt(_getsockopt,5, int a1,   int a2,   int a3,   char *a4,   int *a5)
SYSREAL_define_syscall_noopt(_accept4,4, int a1,   struct sockaddr *a2,   int *a3,   int a4)
SYSREAL_define_syscall_noopt(_waitid,5, int a1,   pid_t a2,   struct siginfo *a3,   int a4,   struct rusage *a5)
SYSREAL_define_syscall(_sched_get_priority_min,1, int a1)
SYSREAL_define_syscall(_ioprio_get,2, int a1,   int a2)
SYSREAL_define_syscall_noopt(_fadvise64,4, int a1,   loff_t a2,   size_t a3,   int a4)
SYSREAL_define_syscall_noopt(_sync_file_range,4, long a1,   loff_t a2,   loff_t a3,   long a4)
SYSREAL_define_syscall(_getpid,0)
SYSREAL_define_syscall_noopt(_request_key,4, const char *a1,   const char *a2,   const char *a3,   key_serial_t a4)
SYSREAL_define_syscall(_epoll_create1,1, int a1)
SYSREAL_define_syscall(_personality,1, unsigned int a1)
SYSREAL_define_syscall(_io_submit,3, aio_context_t a1,   long a2,   struct iocb **a3)
SYSREAL_define_syscall(_lchown,3, const char *a1,   uid_t a2,   gid_t a3)
SYSREAL_define_syscall(_tgkill,3, pid_t a1,   pid_t a2,   int a3)
SYSREAL_define_syscall_noopt(_setsockopt,5, int a1,   int a2,   int a3,   char *a4,   int a5)
SYSREAL_define_syscall(_close,1, unsigned int a1)
SYSREAL_define_syscall_noopt(_mbind,6, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long *a4,   unsigned long a5,   unsigned a6)
SYSREAL_define_syscall(_sched_get_priority_max,1, int a1)
SYSREAL_define_syscall_noopt(_perf_event_open,5, struct perf_event_attr *a1,   pid_t a2,   int a3,   int a4,   unsigned long a5)
SYSREAL_define_syscall(_timer_gettime,2, timer_t a1,   struct itimerspec *a2)
SYSREAL_define_syscall(_pipe2,2, int *a1,   int a2)
SYSREAL_define_syscall(_setns,2, int a1,   int a2)
SYSREAL_define_syscall_noopt(_sched_getattr,4, pid_t a1,   struct sched_attr  *a2,   unsigned int a3,   unsigned int a4)
SYSREAL_define_syscall(_kill,2, pid_t a1,   int a2)
SYSREAL_define_syscall_noopt(_openat,4, int a1,   const char *a2,   int a3,   int a4)
SYSREAL_define_syscall_noopt(_rt_sigaction,4, int a1,   const struct sigaction *a2,   struct sigaction *a3,   size_t a4)
SYSREAL_define_syscall(_setpgid,2, pid_t a1,   pid_t a2)
SYSREAL_define_syscall(_signalfd,3, int a1,   sigset_t *a2,   size_t a3)
SYSREAL_define_syscall(_pipe,1, int *a1)
SYSREAL_define_syscall(_sched_getparam,2, pid_t a1,   struct sched_param *a2)
SYSREAL_define_syscall(_setreuid,2, uid_t a1,   uid_t a2)
SYSREAL_define_syscall(_ioprio_set,3, int a1,   int a2,   int a3)
SYSREAL_define_syscall(_sigaltstack,2, const stack_t *a1,   stack_t *a2)
SYSREAL_define_syscall_noopt(_select,5, int a1,   fd_set *a2,   fd_set *a3,   fd_set *a4,   struct timeval *a5)
SYSREAL_define_syscall(_flistxattr,3, int a1,   char *a2,   size_t a3)
SYSREAL_define_syscall(_clock_settime,2, const clockid_t a1,   const struct timespec *a2)
SYSREAL_define_syscall_noopt(_mmap,6, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5,   unsigned long a6)
SYSREAL_define_syscall(_sethostname,2, char *a1,   int a2)
SYSREAL_define_syscall(_chdir,1, const char *a1)
SYSREAL_define_syscall(_sysinfo,1, struct sysinfo *a1)
SYSREAL_define_syscall_noopt(_mknodat,4, int a1,   const char *a2,   int a3,   unsigned a4)
SYSREAL_define_syscall(_ioperm,3, unsigned long a1,   unsigned long a2,   int a3)
SYSREAL_define_syscall(_faccessat,3, int a1,   const char *a2,   int a3)
SYSREAL_define_syscall(_munlock,2, unsigned long a1,   size_t a2)
SYSREAL_define_syscall(_setresgid,3, gid_t a1,   gid_t a2,   gid_t a3)
SYSREAL_define_syscall(_acct,1, const char *a1)
SYSREAL_define_syscall_noopt(_readlinkat,4, int a1,   const char *a2,   char *a3,   int a4)
SYSREAL_define_syscall(_adjtimex,1, struct timex *a1)
SYSREAL_define_syscall(_capset,2, cap_user_header_t a1,   const cap_user_data_t a2)
SYSREAL_define_syscall_noopt(_rt_sigprocmask,4, int a1,   sigset_t *a2,   sigset_t *a3,   size_t a4)
SYSREAL_define_syscall(_futimesat,3, int a1,   const char *a2,   struct timeval *a3)
SYSREAL_define_syscall(_setitimer,3, int a1,   struct itimerval *a2,   struct itimerval *a3)
SYSREAL_define_syscall(_syslog,3, int a1,   char *a2,   int a3)
SYSREAL_define_syscall(_seccomp,3, unsigned int a1,   unsigned int a2,   const char  *a3)
SYSREAL_define_syscall(_creat,2, const char *a1,   int a2)
SYSREAL_define_syscall_noopt(_epoll_wait,4, int a1,   struct epoll_event *a2,   int a3,   int a4)
SYSREAL_define_syscall(_flock,2, unsigned int a1,   unsigned int a2)
SYSREAL_define_syscall_noopt(_process_vm_writev,6, pid_t a1,   const struct iovec *a2,   unsigned long a3,   const struct iovcc *a4,   unsigned long a5,   unsigned long a6)
SYSREAL_define_syscall(_fanotify_init,2, unsigned int a1,   unsigned int a2)
SYSREAL_define_syscall_noopt(_quotactl,4, unsigned int a1,   const char *a2,   qid_t a3,   void *a4)
SYSREAL_define_syscall(_inotify_rm_watch,2, int a1,   __s32 a2)
SYSREAL_define_syscall(_getpeername,3, int a1,   struct sockaddr *a2,   int *a3)
SYSREAL_define_syscall(_mq_notify,2, mqd_t a1,   const struct sigevent *a2)
SYSREAL_define_syscall(_link,2, const char *a1,   const char *a2)
SYSREAL_define_syscall(_mincore,3, unsigned long a1,   size_t a2,   unsigned char *a3)
SYSREAL_define_syscall_noopt(_mq_timedreceive,5, mqd_t a1,   char *a2,   size_t a3,   unsigned int *a4,   const struct timespec *a5)
SYSREAL_define_syscall(_lremovexattr,2, const char *a1,   const char *a2)
SYSREAL_define_syscall_noopt(_signalfd4,4, int a1,   sigset_t *a2,   size_t a3,   int a4)
SYSREAL_define_syscall(_setpriority,3, int a1,   int a2,   int a3)
SYSREAL_define_syscall(_memfd_create,2, const char  *a1,   unsigned int a2)
SYSREAL_define_syscall(_setrlimit,2, unsigned int a1,   struct rlimit *a2)
SYSREAL_define_syscall(_set_robust_list,2, struct robust_list_head *a1,   size_t a2)
SYSREAL_define_syscall(_shmget,3, key_t a1,   size_t a2,   int a3)
SYSREAL_define_syscall(_munlockall,0)
SYSREAL_define_syscall(_getsid,1, pid_t a1)
SYSREAL_define_syscall(_access,2, const char *a1,   int a2)
SYSREAL_define_syscall(_tkill,2, pid_t a1,   int a2)
SYSREAL_define_syscall(_setregid,2, gid_t a1,   gid_t a2)
SYSREAL_define_syscall(_getresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3)
SYSREAL_define_syscall_noopt(_sendfile,4, int a1,   int a2,   off_t *a3,   size_t a4)
SYSREAL_define_syscall(_mprotect,3, unsigned long a1,   size_t a2,   unsigned long a3)
SYSREAL_define_syscall(_fchmod,2, unsigned int a1,   mode_t a2)
SYSREAL_define_syscall(_mq_getsetattr,3, mqd_t a1,   const struct mq_attr *a2,   struct mq_attr *a3)
SYSREAL_define_syscall(_getgroups,2, int a1,   gid_t *a2)
SYSREAL_define_syscall(_init_module,3, void *a1,   unsigned long a2,   const char *a3)
SYSREAL_define_syscall(_msgctl,3, int a1,   int a2,   struct msqid_ds *a3)
SYSREAL_define_syscall(_pause,0)
SYSREAL_define_syscall(_open,3, const char *a1,   int a2,   int a3)
SYSREAL_define_syscall(_finit_module,3, int a1,   const char  *a2,   int a3)
SYSREAL_define_syscall(_lstat,2, const char *a1,   struct stat *a2)
SYSREAL_define_syscall(_geteuid,0)
SYSREAL_define_syscall_noopt(_add_key,4, const char *a1,   const char *a2,   const void *a3,   size_t a4)
SYSREAL_define_syscall_noopt(_newfstatat,4, int a1,   const char *a2,   struct stat *a3,   int a4)
SYSREAL_define_syscall(_sched_yield,0)
SYSREAL_define_syscall(_getuid,0)
SYSREAL_define_syscall(_fsync,1, unsigned int a1)
SYSREAL_define_syscall(_fchmodat,3, int a1,   const char *a2,   mode_t a3)
SYSREAL_define_syscall_noopt(_sendmmsg,4, int a1,   struct mmsghdr *a2,   unsigned int a3,   unsigned int a4)
SYSREAL_define_syscall(_recvmsg,3, int a1,   struct msghdr *a2,   unsigned int a3)
SYSREAL_define_syscall(_setdomainname,2, char *a1,   int a2)
SYSREAL_define_syscall(_rmdir,1, const char *a1)
SYSREAL_define_syscall(_sched_getaffinity,3, pid_t a1,   unsigned int a2,   unsigned long *a3)
SYSREAL_define_syscall(_settimeofday,2, struct timeval *a1,   struct timezone *a2)
SYSREAL_define_syscall(_sched_setscheduler,3, pid_t a1,   int a2,   struct sched_param *a3)
SYSREAL_define_syscall(_eventfd2,2, unsigned int a1,   int a2)
SYSREAL_define_syscall(_modify_ldt,3, int a1,   void *a2,   unsigned long a3)
SYSREAL_define_syscall_noopt(_name_to_handle_at,5, int a1,   const char *a2,   struct file_handle *a3,   int *a4,   int a5)
SYSREAL_define_syscall_noopt(_pwrite64,4, unsigned int a1,   const char *a2,   size_t a3,   loff_t a4)
SYSREAL_define_syscall(_syncfs,1, int a1)
SYSREAL_define_syscall_noopt(_linkat,5, int a1,   const char *a2,   int a3,   const char *a4,   int a5)
SYSREAL_define_syscall_noopt(_semtimedop,4, int a1,   struct sembuf *a2,   unsigned a3,   const struct timespec *a4)
SYSREAL_define_syscall(_vfork,0)
SYSREAL_define_syscall_noopt(_mount,5, char *a1,   char *a2,   char *a3,   unsigned long a4,   void *a5)
SYSREAL_define_syscall_noopt(_epoll_ctl,4, int a1,   int a2,   int a3,   struct epoll_event *a4)
SYSREAL_define_syscall(_unshare,1, unsigned long a1)
SYSREAL_define_syscall(_rt_sigsuspend,2, sigset_t *a1,   size_t a2)
SYSREAL_define_syscall_noopt(_lgetxattr,4, const char *a1,   const char *a2,   void *a3,   size_t a4)
SYSREAL_define_syscall(_mknod,3, const char *a1,   umode_t a2,   unsigned a3)
SYSREAL_define_syscall_noopt(_rt_tgsigqueueinfo,4, pid_t a1,   pid_t a2,   int a3,   siginfo_t *a4)
SYSREAL_define_syscall(_dup3,3, unsigned int a1,   unsigned int a2,   int a3)
SYSREAL_define_syscall(_setgid,1, gid_t a1)
SYSREAL_define_syscall_noopt(_setxattr,5, const char *a1,   const char *a2,   const void *a3,  size_t a4,   int a5)
SYSREAL_define_syscall_noopt(_recvfrom,6, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5,   int *a6)
SYSREAL_define_syscall(_io_cancel,3, aio_context_t a1,   struct iocb *a2,   struct io_event *a3)
SYSREAL_define_syscall_noopt(_semctl,4, int a1,   int a2,   int a3,   semun_u a4)
SYSREAL_define_syscall(_sync,0)
SYSREAL_define_syscall(_chmod,2, const char *a1,   mode_t a2)
SYSREAL_define_syscall(_fchdir,1, unsigned int a1)
SYSREAL_define_syscall(_times,1, struct sysinfo *a1)
SYSREAL_define_syscall_noopt(_lsetxattr,5, const char *a1,   const char *a2,   const void *a3,  size_t a4,   int a5)
SYSREAL_define_syscall(_fstatfs,2, unsigned int a1,   struct statfs *a2)
SYSREAL_define_syscall(_semop,3, int a1,   struct sembuf *a2,   unsigned a3)
SYSREAL_define_syscall(_utimes,2, char *a1,   struct timeval *a2)
SYSREAL_define_syscall_noopt(_get_mempolicy,5, int *a1,   unsigned long *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5)
SYSREAL_define_syscall(_gettid,0)
SYSREAL_define_syscall_noopt(_utimensat,4, int a1,   const char *a2,   struct timespec *a3,  int a4)
SYSREAL_define_syscall(_getrandom,3, char  *a1,   size_t a2,   unsigned int a3)
SYSREAL_define_syscall(_inotify_init1,1, int a1)
SYSREAL_define_syscall_noopt(_mq_timedsend,5, mqd_t a1,   const char *a2,   size_t a3,   unsigned int a4,   const struct timespec *a5)
SYSREAL_define_syscall_noopt(_splice,6, int a1,   loff_t *a2,   int a3,   loff_t *a4,  size_t a5,   unsigned int a6)
SYSREAL_define_syscall_noopt(_fanotify_mark,5, long a1,   long a2,   __u64 a3,   long a4,  long a5)
SYSREAL_define_syscall_noopt(_timer_settime,4, timer_t a1,   int a2,   const struct itimerspec *a3,   struct itimerspec *a4)
SYSREAL_define_syscall(_exit_group,1, int a1)
SYSREAL_define_syscall(_sched_setattr,3, pid_t a1,   struct sched_attr  *a2,   unsigned int a3)
SYSREAL_define_syscall(_nanosleep,2, struct timespec *a1,   struct timespec *a2)
SYSREAL_define_syscall(_getppid,0)
SYSREAL_define_syscall(_writev,3, unsigned long a1,   const struct iovec *a2,   unsigned long a3)
SYSREAL_define_syscall(_mq_unlink,1, const char *a1)
SYSREAL_define_syscall(_setfsgid,1, gid_t a1)
SYSREAL_define_syscall(_unlinkat,3, int a1,   const char *a2,   int a3)
SYSREAL_define_syscall(_sched_rr_get_interval,2, pid_t a1,   struct timespec *a2)
SYSREAL_define_syscall(_timer_getoverrun,1, timer_t a1)
SYSREAL_define_syscall(_getdents64,3, unsigned int a1,   struct linux_dirent64 *a2,   unsigned int a3)
SYSREAL_define_syscall(_munmap,2, unsigned long a1,   size_t a2)
SYSREAL_define_syscall(_madvise,3, unsigned long a1,   size_t a2,   int a3)
SYSREAL_define_syscall(_sched_setparam,2, pid_t a1,   struct sched_param *a2)
SYSREAL_define_syscall(_fremovexattr,2, int a1,   const char *a2)
SYSREAL_define_syscall_noopt(_preadv,5, unsigned long a1,   const struct iovec *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5)
SYSREAL_define_syscall(_alarm,1, unsigned int a1)
SYSREAL_define_syscall_noopt(_rt_sigtimedwait,4, const sigset_t *a1,   siginfo_t *a2,   const struct timespec *a3,   size_t a4)
SYSREAL_define_syscall_noopt(_clone,4, unsigned long a1,   unsigned long a2,   void *a3,   void *a4)
SYSREAL_define_syscall(_chown,3, const char *a1,   uid_t a2,   gid_t a3)
SYSREAL_define_syscall_noopt(_timerfd_settime,4, int a1,   int a2,   const struct itimerspec *a3,   struct itimerspec *a4)
SYSREAL_define_syscall(_dup2,2, unsigned int a1,   unsigned int a2)
SYSREAL_define_syscall(_llistxattr,3, const char *a1,   char *a2,   size_t a3)
SYSREAL_define_syscall(_set_mempolicy,3, int a1,   unsigned long *a2,   unsigned long a3)
SYSREAL_define_syscall(_delete_module,2, const char *a1,   unsigned int a2)
SYSREAL_define_syscall(_read,3, unsigned int a1,   char *a2,   size_t a3)
SYSREAL_define_syscall(_mlock,2, unsigned long a1,   size_t a2)
SYSREAL_define_syscall(_semget,3, key_t a1,   int a2,   int a3)
SYSREAL_define_syscall(_unlink,1, const char *a1)
SYSREAL_define_syscall_noopt(_process_vm_readv,6, pid_t a1,   const struct iovec *a2,   unsigned long a3,   const struct iovec *a4,   unsigned long a5,   unsigned long a6)
SYSREAL_define_syscall_noopt(_getxattr,4, const char *a1,   const char *a2,   void *a3,   size_t a4)
SYSREAL_define_syscall(_getdents,3, unsigned int a1,   struct linux_dirent *a2,   unsigned int a3)
SYSREAL_define_syscall_noopt(_tee,4, int a1,   int a2,   size_t a3,   unsigned int a4)
SYSREAL_define_syscall_noopt(_vmsplice,4, int a1,   const struct iovec *a2,   unsigned long a3,  unsigned int a4)
SYSREAL_define_syscall(_bind,3, int a1,   struct sockaddr *a2,   int a3)
SYSREAL_define_syscall_noopt(_renameat2,5, int a1,   const char  *a2,   int a3,   const char  *a4,   unsigned int a5)
SYSREAL_define_syscall(_readlink,3, const char *a1,   char *a2,   int a3)
SYSREAL_define_syscall_noopt(_pread64,4, unsigned long a1,   char *a2,   size_t a3,   loff_t a4)
SYSREAL_define_syscall(_getgid,0)
SYSREAL_define_syscall(_inotify_init,0)
SYSREAL_define_syscall(_fork,0)
SYSREAL_define_syscall(_utime,2, char *a1,   struct utimbuf *a2)
SYSREAL_define_syscall_noopt(_kcmp,5, pid_t a1,   pid_t a2,   int a3,   unsigned long a4,   unsigned long a5)
SYSREAL_define_syscall(_rename,2, const char *a1,   const char *a2)
SYSREAL_define_syscall(_removexattr,2, const char *a1,   const char *a2)
SYSREAL_define_syscall_noopt(_socketpair,4, int a1,   int a2,   int a3,   int *a4)
SYSREAL_define_syscall(_shmctl,3, int a1,   int a2,   struct shmid_ds *a3)
SYSREAL_define_syscall_noopt(_fchownat,5, int a1,   const char *a2,   uid_t a3,   gid_t a4,   int a5)
SYSREAL_define_syscall(_symlink,2, const char *a1,   const char *a2)
SYSREAL_define_syscall(_setgroups,2, int a1,   gid_t *a2)
SYSREAL_define_syscall(_poll,3, struct poll_fd *a1,   unsigned int a2,   long a3)
SYSREAL_define_syscall(_getcpu,3, unsigned *a1,   unsigned *a2,   struct getcpu_cache *a3)
SYSREAL_define_syscall(_mkdir,2, const char *a1,   int a2)
SYSREAL_define_syscall(_ustat,2, unsigned a1,   struct ustat *a2)
SYSREAL_define_syscall(_lseek,3, unsigned int a1,   off_t a2,   unsigned int a3)
SYSREAL_define_syscall(_setresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3)
SYSREAL_define_syscall(_setsid,0)
SYSREAL_define_syscall(_getrlimit,2, unsigned int a1,   struct rlimit *a2)
SYSREAL_define_syscall(_get_robust_list,3, int a1,   struct robust_list_head **a2,   size_t *a3)
SYSREAL_define_syscall_noopt(_kexec_load,4, unsigned long a1,   unsigned long a2,   struct kexec_segment *a3,   unsigned long a4)
SYSREAL_define_syscall(_msgget,2, key_t a1,   int a2)
SYSREAL_define_syscall(_umount2,2, const char *a1,   int a2)
SYSREAL_define_syscall(_readv,3, unsigned long a1,   const struct iovec *a2,   unsigned long a3)
SYSREAL_define_syscall(_getpriority,2, int a1,   int a2)
SYSREAL_define_syscall(_clock_gettime,2, const clockid_t a1,   struct timespec *a2)
SYSREAL_define_syscall(_execve,3, const char *a1,   const char *const a2,   const char *const a3)
SYSREAL_define_syscall(_accept,3, int a1,   struct sockaddr *a2,   int *a3)
SYSREAL_define_syscall(_clock_getres,2, const clockid_t a1,   struct timespec *a2)
SYSREAL_define_syscall(_gettimeofday,2, struct timeval *a1,   struct timezone *a2)
SYSREAL_define_syscall_noopt(_ppoll,5, struct pollfd *a1,   unsigned int a2,   struct timespec *a3,   const sigset_t *a4,   size_t a5)
SYSREAL_define_syscall(_connect,3, int a1,   struct sockaddr *a2,   int a3)
SYSREAL_define_syscall_noopt(_fallocate,4, long a1,   long a2,   loff_t a3,   loff_t a4)
SYSREAL_define_syscall(_lookup_dcookie,3, u64 a1,   long a2,   long a3)
SYSREAL_define_syscall(__sysctl,1, struct __sysctl_args *a1)
SYSREAL_define_syscall(_set_tid_address,1, int *a1)
SYSREAL_define_syscall_noopt(_futex,6, u32 *a1,   int a2,   u32 a3,   struct timespec *a4,   u32 *a5,   u32 a6)
SYSREAL_define_syscall_noopt(_msgsnd,4, int a1,   struct msgbuf *a2,   size_t a3,   int a4)
SYSREAL_define_syscall(_time,1, time_t *a1)
SYSREAL_define_syscall(_sysfs,3, int a1,   unsigned long a2,   unsigned long a3)
SYSREAL_define_syscall(_timerfd_gettime,2, int a1,   struct itimerspec *a2)
SYSREAL_define_syscall(_setuid,1, uid_t a1)
SYSREAL_define_syscall(_inotify_add_watch,3, int a1,   const char *a2,   u32 a3)
SYSREAL_define_syscall_noopt(_renameat,4, int a1,   const char *a2,   int a3,   const char *a4)
SYSREAL_define_syscall(_socket,3, int a1,   int a2,   int a3)
SYSREAL_define_syscall(_fchown,3, unsigned int a1,   uid_t a2,   gid_t a3)
SYSREAL_define_syscall(_listen,2, int a1,   int a2)
SYSREAL_define_syscall_noopt(_io_getevents,4, aio_context_t a1,   long a2,   long a3,   struct io_event *a4)
#endif
#pragma GCC diagnostic pop
#endif
#endif
#ifdef mini_qsort
void qsort(void  *base,	size_t nel,	size_t width,	int (*comp)(const void *, const void *));
#endif
#ifdef mini__match_ext2
char* _match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char), text_match *st_match);
#endif
#ifdef mini_userdb
#endif
#ifdef mini_eprintfs
#define eprintfs(fmt,...) fprintfs(stderr, fmt, __VA_ARGS__)
#endif
#ifdef mini_puts
#define puts(msg) ( print(msg) + printl() )
#endif
#ifdef mini_getbrk
static long getbrk();
#endif
#ifdef mini_environ
#endif
#ifdef mini_ewrites
#define ewrites(str) write(STDERR_FILENO,str,sizeof(str))
#endif
#ifdef mini_errno
#endif
#ifdef mini_globals
#endif
#ifdef mini_eprintf
#define eprintf(fmt,...) fprintf(stderr, fmt, __VA_ARGS__)
#endif
#ifdef mini_itoHEX
int itoHEX(int i,char* buf,int padding);
#define include_minilib_src_conversions_itohex_c
#endif
#ifdef mini_eputs
#define eputs(msg) ( eprint(msg) + eprintl() )
#endif
#ifdef mini_prints
#define prints(...) _mprints(__VA_ARGS__,0)
#endif
#ifdef mini_errno_str
static char *errno_str(int err);
#endif
#ifdef mini_sprintf
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)
#define include_minilib_src_output_sprintf_c
#endif
#ifdef mini_grent
#endif
#ifdef mini_printf
#define printf(...) fprintf(stdout,__VA_ARGS__)
#endif
#ifdef mini_die
#define die(errnum,msg) {ewritesl(msg);exit_errno(errnum);}
#endif
#ifdef mini_eprint
#define eprint(str) write(STDERR_FILENO,str,strlen(str))
#endif
#ifdef mini_brk
static int brk( const void* addr );
#endif
#ifdef mini_malloc_brk
void* malloc_brk(int size);
#endif
#ifdef mini_fgets
char* fgets(char *buf, int size, FILE* F);
#endif
#ifdef mini_exit_errno
void exit_errno( int errnum );
#endif
#ifdef mini_ptsname
char *ptsname(int fd);
#endif
#ifdef mini_ewritesl
#define ewritesl(str) write(STDERR_FILENO,str"\n",sizeof(str)+1)
#endif
#ifdef mini_dprintf
int dprintf( int fd, const char *fmt, ... );
#endif
#ifdef mini_fgetc
static inline int fgetc(FILE *F);
#endif
#ifdef mini_getusergroups
int getusergroups(const char* user, int maxgroups, int *list);
#endif
#ifdef mini_open
int volatile open( const char *s, int flags, ... );
#define include_minilib_src_file_open_c
#endif
#ifdef mini__die
void _die();
#endif
#ifdef mini_getenv
char* getenv(const char* name);
#endif
#ifdef mini_strcpy
char *strcpy(char *dest, const char *src);
#endif
#ifdef mini_pwent
#define minilib_include_pwent_h
#endif
#ifdef mini_dies
#define dies(errnum,...) {eprintsl(__VA_ARGS__);exit_errno(errnum);}
#endif
#ifdef mini__mprints
#define prints_h
#define stdarg_h
#define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)
#endif
#ifdef mini_fwrites
#define fwrites(fd,str) write(fd,str,sizeof(str))
#endif
#ifdef mini_0
#endif
#ifdef mini_fprintf
#define fprintf(stream,...)	write(fileno(stream),mlgl->mbuf,sprintf(mlgl->mbuf,__VA_ARGS__))
#define include_minilib_src_output_sprintf_c
#endif
#ifdef mini_fputs
#define mini_fstream_h
#define minilib_include_fputs_h
#endif
#ifdef mini_fileno
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_memcpy
void* memcpy( void*d, const void *s, int n );
#endif
#ifdef mini_fprintfs
int fprintfs( FILE* F, char *fmt, ...);
#endif
#ifdef mini__strcmp
int _strcmp(const char*c1,const char*c2,int len);
#define include_minilib_src_string_strcmp_c
#endif
#ifdef mini_ltodec
int ltodec(long i, char *buf, int prec, char limiter );
#define include_minilib_src_conversions_ltodec_c
#endif
#ifdef mini_fputc
#define mini_fstream_h
#define minilib_include_fputc_h
#endif
#ifdef mini_strlen
int strlen(const char*str);
#endif
#ifdef mini_writes
#define writes(str) write(STDOUT_FILENO,str,sizeof(str))
#endif
#ifdef mini_waitpid
pid_t waitpid(pid_t pid, int *wstatus, int options);
#define include_minilib_src_process_wait_c
#endif
#ifdef mini_fseek
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_itodec
int itodec(int i, char *buf, int prec, char limiter, char pad );
#endif
#ifdef mini_tolower
#endif
#ifdef mini_setgrent
void setgrent();
#endif
#ifdef mini_dirbuf
#define minilib_include_dirent_h
#endif
#ifdef mini_malloc
void* malloc(int size);
#define include_minilib_src_memory_malloc_c
#endif
#ifdef mini_sigaction
static int volatile sigaction(int sig, const struct sigaction *act, struct sigaction *oact);
#define include_minilib_src_process_sigaction_c
#endif
#ifdef mini_snprintf
int snprintf( char *buf, size_t size, const char *fmt, ... );
#endif
#ifdef mini_passwdfile_open
#endif
#ifdef mini_tcgetattr
int tcgetattr(int fd, struct termios *io);
#endif
#ifdef mini_ptsname_r
int ptsname_r(int fd, char *buf, size_t len);
#endif
#ifdef mini_free
void free(void *p);
#define include_minilib_src_memory_malloc_c
#endif
#ifdef mini__itohex
int _itohex(int i,char* buf,int padding, int capitals);
#define include_minilib_src_conversions_itohex_c
#endif
#ifdef mini_execvpe
static int execvpe(const char *file, char *const argv[], char *const envp[]);
#endif
#ifdef mini_token_s
char *token_s( userdb *udb, char **p );
#define include_minilib_src_userdb_userdb_c
#endif
#ifdef mini_vsnprintf
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );
#define include_minilib_src_output_sprintf_c
#endif
#ifdef mini_uitoHEX
#endif
#ifdef mini_printfs
#define printfs(fmt,...) fprintfs(stdout, fmt, __VA_ARGS__)
#endif
#ifdef mini_eprints
#define eprints(...) dprints(STDERR_FILENO,__VA_ARGS__,0)
#endif
#ifdef mini_opendirp
static DIR *opendirp(const char *name, DIR *dir);
#endif
#ifdef mini_getpwuid
struct passwd *getpwuid(uid_t uid);
#endif
#ifdef mini_ret_errno
#define minilib_include_ret_errno_h
#endif
#ifdef mini_raise
static inline int raise(int signr);
#define include_minilib_src_process_sigaction_c
#endif
#ifdef mini_token_i
int token_i( userdb* udb, char **p );
#define include_minilib_src_userdb_userdb_c
#endif
#ifdef mini__match
int _match(char *text, const char *re, text_match *st_match);
#endif
#ifdef mini_strncmp
int strncmp(const char*c1,const char*c2,int len);
#define include_minilib_src_string_strcmp_c
#endif
#ifdef mini_ewrite
#endif
#ifdef mini_print
#define print(str) write(STDOUT_FILENO,str,strlen(str))
#endif
#ifdef mini__itobin
int _itobin(int i, char*buf, int prec, int groups );
#endif
#ifdef mini_strchrnul
char *strchrnul(const char *s, int c);
#endif
#ifdef mini_eprintl
#define eprintl() write(STDERR_FILENO,"\n",1)
#endif
#ifdef mini_strcmp
int strcmp(const char*c1,const char*c2);
#define include_minilib_src_string_strcmp_c
#endif
#ifdef mini_signal
sighandler_t signal(int sig, sighandler_t func );
#endif
#ifdef mini_exit
#endif
#ifdef mini_eprintsl
#define eprintsl(...) dprints(STDERR_FILENO,__VA_ARGS__,"\n",0)
#endif
#ifdef mini_dprints
int dprints(int fd, const char *msg,...);
#endif
#ifdef mini_lseek
#define minilib_include_lseek_h
#endif
#ifdef mini__strcasecmp
int _strcasecmp(const char*c1,const char*c2,int len);
#define include_minilib_src_string_strcmp_c
#endif
#ifdef mini__fopen
FILE *_fopen(int fd, const char* filename, const char* mode, FILE *f);
#endif
#ifdef mini_printl
#define printl() write(STDOUT_FILENO,"\n",1)
#endif
#ifdef mini_printsl
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)
#endif
#ifdef mini_atoi
int atoi(const char *c);
#endif
#ifdef mini_itooct
int itooct(int i, char *buf);
#endif
#ifdef mini_sbrk
static void* sbrk(long incr);
#endif
#ifdef mini_realloc
void* realloc(void *p, int size);
#define include_minilib_src_memory_malloc_c
#endif
#ifdef mini_uitodec
int __attribute__((optimize("Os")))uitodec(unsigned int i, char *buf, int prec, char limiter, char pad );
#endif
#ifdef mini_ioctl
int volatile  __attribute__((optimize("O0"))) ioctl( int fd, unsigned long int request, ... );
#endif
#ifdef mini_network
#define minilib_include_network_h
#endif
#ifdef mini_itohex
int itohex(int i,char* buf,int padding);
#define include_minilib_src_conversions_itohex_c
#endif
#ifdef mini_seterrno
#define minilib_include_seterrno_h
#endif
#ifdef mini_getgrent
struct group* getgrent();
#endif
#ifdef mini_termio
#define minilib_include_termio_h
#endif
#ifdef mini_uitohex
#endif
#ifdef mini_fprints
#define fprints(F,...) dprints(fileno(F),__VA_ARGS__,0)
#endif
#ifdef mini_strerror
static char* strerror( int errnum );
#endif
#ifdef mini_setpwent
void setpwent();
#endif
#ifdef mini_ftell
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_mmap
static void* __attribute__((optimize("O0"))) mmap(void* addr,  size_t len,  int prot,  int flags,  int fd,  off_t off);
#endif
#ifdef mini_userdb_open
int userdb_open(userdb *udb, const char* file);
#endif
#ifdef mini_writesl
#define writesl(str) write(STDOUT_FILENO,str "\n",sizeof(str)+1)
#endif
#ifdef mini__sendmsg
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__recvmmsg
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__shmdt
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__reboot
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getsockname
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_dtodec
int dtodec(double d, char* buf, int precision);
#endif
#ifdef mini_unmap_protected
int unmap_protected(void *p, int len);
#endif
#ifdef mini_select
#define minilib_include_select_h
#endif
#ifdef mini_fgetpos
#define minilib_include_mini_fstream_h
#endif
#ifdef mini__fdatasync
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_djb_cksum
unsigned int djb_cksum( const char* p, unsigned int len );
#endif
#ifdef mini_dirbufsize
#define minilib_include_dirent_h
#endif
#ifdef mini_ungetc
static int ungetc(int c, FILE *F);
#endif
#ifdef mini_vsprintf
int vsprintf( char *buf, const char *fmt, ... );
#endif
#ifdef mini__write
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sched_getscheduler
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mq_open
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_labs
#define minilib_include_math_h
#endif
#ifdef mini__fcntl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__ftruncate
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__truncate
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__migrate_pages
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_abs
#define minilib_include_math_h
#endif
#ifdef mini_ntohs
#define ntohs(i) htons(i)
#endif
#ifdef mini__stat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_sleep
unsigned int volatile sleep(unsigned int seconds);
#define include_minilib_src_process_sleep_c
#endif
#ifdef mini__setfsuid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_sigemptyset
static int sigemptyset(sigset_t *set);
#define include_minilib_src_process_sigaction_c
#endif
#ifdef mini__restart_syscall
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_verbose_errstr
#define minilib_include_errstr_h
#endif
#ifdef mini__uname
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__dup
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__keyctl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_errx
#define errx( status, fmt ... ) { fprintf(stderr,fmt); exit(status); }
#endif
#ifdef mini__rt_sigpending
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__iopl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__ptrace
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_htons
static uint16_t htons(uint16_t i);
#endif
#ifdef mini__epoll_create
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_execvp
static inline int execvp(const char *file, char *const argv[]);
#endif
#ifdef mini_memset
void *memset( void *s, int c, int n);
#endif
#ifdef mini__timerfd_create
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getrusage
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_ferror
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_strcasecmp
int strcasecmp(const char*c1,const char*c2);
#define include_minilib_src_string_strcmp_c
#endif
#ifdef mini_ansicolors
#define minilib_include_ansicolors_h
#endif
#ifdef mini_match
int match(char *text, const char *re, text_match *st_match);
#endif
#ifdef mini_scandir_bufsize
#endif
#ifdef mini_strtol
long int strtol(const char *c, const char **endp, int base);
#endif
#ifdef mini__eventfd
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__timer_delete
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__shmat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getpgrp
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_div
#define minilib_include_math_h
#endif
#ifdef mini__getpgid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_rand
unsigned int rand();
#endif
#ifdef mini__umask
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__clock_adjtime
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__remap_file_pages
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getsockopt
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__accept4
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__epoll_pwait
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getegid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mremap
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_getgroups
int getgroups(int maxgroups, int *list);
#endif
#ifdef mini__fadvise64
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__request_key
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_map_protected
void* map_protected(int len);
#endif
#ifdef mini__getpid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__epoll_create1
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sched_get_priority_min
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_swap
static inline void swap(void* a, void* b,int size);
#endif
#ifdef mini_free_brk
int free_brk();
#endif
#ifdef mini_getgrouplist
int getgrouplist(const char* user, gid_t group, gid_t *groups, int *ngroups);
#endif
#ifdef mini__tgkill
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_vexec
int vexec( const char* path, char* const* argv, char* const* envp );
#endif
#ifdef mini_strchr
char *strchr(const char *s, int c);
#endif
#ifdef mini__personality
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_clearerr
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_wait
pid_t wait(int *wstatus);
#define include_minilib_src_process_wait_c
#endif
#ifdef mini__lchown
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setns
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__openat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_memfrob
void* memfrob(void* s, unsigned int len);
#endif
#ifdef mini__kill
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_match_ext2
int match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char),text_match *st_match);
#endif
#ifdef mini_setvbuf
#define minilib_include_mini_fstream_h
#endif
#ifdef mini__close
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mbind
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_basename
char *basename(char *path);
#endif
#ifdef mini__sched_getparam
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setreuid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__pipe
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__signalfd
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_strtoll
long long int strtoll(const char *c, const char **endp, int base);
#endif
#ifdef mini__clock_settime
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__flistxattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_strrchr
char *strrchr(const char *s, int c);
#endif
#ifdef mini_posix_openpt
int posix_openpt(int flags);
#endif
#ifdef mini__sigaltstack
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_strstr
char* strstr(const char *big, const char *little);
#endif
#ifdef mini__select
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_dirfd
int dirfd(DIR *d);
#endif
#ifdef mini__munlock
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__ioperm
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setresgid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__acct
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__adjtimex
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__readlinkat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sethostname
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sysinfo
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_verbose_errstr2
#define minilib_include_errstr2_h
#endif
#ifdef mini_cfmakeraw
void cfmakeraw(struct termios *tp);
#endif
#ifdef mini__flock
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_snprintfs
int snprintfs( char* buf, int size, char *fmt, ...);
#endif
#ifdef mini__futimesat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__capset
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__syslog
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setitimer
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__epoll_wait
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mincore
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mq_timedreceive
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__lremovexattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_setbuf
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_fexecve
#define minilib_include_fexecve_h
#endif
#ifdef mini__link
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_dief_if
#define dief_if( when, errnum, fmt,... ) if( when ) dief( errnum, fmt, __VA_ARGS__ )
#endif
#ifdef mini_putchar
#define putchar(c) fputc(c,stdout)
#endif
#ifdef mini__tkill
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__access
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setregid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sendfile
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setrlimit
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__msgctl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_dies_if
#define dies_if( when, errnum, ... ) if( when ) dies( errnum, __VA_ARGS__ )
#endif
#ifdef mini__open
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mprotect
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fchmod
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mq_getsetattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getuid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setdomainname
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_execl
static int execl(const char *pathname, const char* arg0,... );
#endif
#ifdef mini__add_key
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_strcat
char *strcat(char *dest, const char *src );
#endif
#ifdef mini__geteuid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sched_setscheduler
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__modify_ldt
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_isatty
int isatty(int fd);
#define include_minilib_src_termios_isatty_c
#endif
#ifdef mini__eventfd2
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__semtimedop
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__linkat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_stplcpy
char *stplcpy(char *dest, const char *src, int size);
#endif
#ifdef mini_setbrk
static int setbrk(long addr);
#endif
#ifdef mini__rt_sigsuspend
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_def
#define minilib_macros_getoptm_h
#endif
#ifdef mini__recvfrom
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__semctl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_OPTIMIZATIONS
#define minilib_include_config_h
#endif
#ifdef mini__utimes
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__semop
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__get_mempolicy
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getrandom
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sync
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__times
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_memmove
void* memmove(void *dest, const void *src, int n);
#endif
#ifdef mini__fstatfs
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setfsgid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__timer_getoverrun
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__munmap
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__madvise
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fanotify_mark
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__nanosleep
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mq_unlink
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__chown
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sched_setparam
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__alarm
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__preadv
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fremovexattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__read
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mlock
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__semget
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_vfprintf
#define vfprintf(...) fprintf(__VA_ARGS__)
#endif
#ifdef mini__llistxattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_getpwent
struct passwd* getpwent();
#endif
#ifdef mini_sigismember
int sigismember(sigset_t *set, int sig);
#define include_minilib_src_process_sigaction_c
#endif
#ifdef mini__delete_module
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_rewind
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_getgrgid
struct group *getgrgid(gid_t gid);
#endif
#ifdef mini__bind
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__renameat2
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getgid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fork
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__pread64
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_dief
#define dief(errnum,fmt,...) {fprintf(stderr,fmt,__VA_ARGS__);exit_errno(errnum);}
#endif
#ifdef mini__unlink
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__process_vm_readv
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_sdbm_hash
unsigned long sdbm_hash(const unsigned char *str);
#endif
#ifdef mini__getxattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setgroups
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__symlink
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getcpu
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_mremap
#define minilib_include_mremap_h
#endif
#ifdef mini__utime
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__kcmp
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__rename
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__removexattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__kexec_load
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__get_robust_list
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__msgget
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__umount2
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getpriority
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__lseek
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setresuid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setsid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__gettimeofday
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_strncpy
char *strncpy(char *dest, const char *src, int n);
#endif
#ifdef mini__ppoll
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini___sysctl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_perror
void perror(const char *msg);
#endif
#ifdef mini_term_width
int term_width();
#endif
#ifdef mini_inet_ntoa
char* inet_ntoa( struct in_addr in);
#endif
#ifdef mini__clock_gettime
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__accept
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_djb2_hash
unsigned long djb2_hash(const unsigned char *str);
#endif
#ifdef mini__inotify_add_watch
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__socket
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_getc
#define getc(F) fgetc(F)
#endif
#ifdef mini__io_getevents
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fchown
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__set_tid_address
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_gethostname
static int gethostname(char *name,int len);
#endif
#ifdef mini_unlockpt
int unlockpt(int fd);
#endif
#ifdef mini__timerfd_gettime
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__statfs
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fopen
FILE *fopen(const char* filename, const char* mode);
#define include_minilib_src_streams_fopen_c
#endif
#ifdef mini_die_if
#define die_if( when, errnum, msg ) if( when ) die( errnum, msg )
#endif
#ifdef mini__getresgid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__clock_nanosleep
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__io_destroy
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sched_setaffinity
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__pwritev
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fsetxattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_ldiv
#define minilib_include_math_h
#endif
#ifdef mini__vhangup
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_dirbuf_malloc
#define minilib_include_dirent_h
#endif
#ifdef mini__sendto
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_putc
#define putc(c,stream) fputc(c,stream)
#endif
#ifdef mini__prlimit64
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getcwd
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_alphasort
int alphasort( const struct dirent** de1, const struct dirent** de2 );
#endif
#ifdef mini_sigdelset
int sigdelset(sigset_t *set, int sig);
#define include_minilib_src_process_sigaction_c
#endif
#ifdef mini_closedir
int closedir(DIR *dir);
#endif
#ifdef mini_clearerror
#define minilib_include_mini_fstream_h
#endif
#ifdef mini__getitimer
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__rt_sigreturn
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__prctl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__swapoff
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_usleep
unsigned int volatile usleep(unsigned int useconds);
#define include_minilib_src_process_sleep_c
#endif
#ifdef mini__fgetxattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_group_printf
#define minilib_macros_defgroups_h
#endif
#ifdef mini__kexec_file_load
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__pivot_root
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__msgrcv
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fstat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__io_setup
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__listxattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_memcmp
int memcmp(const void* c1,const void* c2,int len);
#endif
#ifdef mini_warn
#define warn( fmt ... ) { fprintf(stderr,fmt ); }
#endif
#ifdef mini__arch_prctl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mkdirat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__readahead
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_tcsetattr
int tcsetattr(int fd, int opt, const struct termios *io);
#endif
#ifdef mini__mlockall
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_getgrnam
struct group *getgrnam(const char* name);
#endif
#ifdef mini__chroot
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__open_by_handle_at
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__pselect6
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_ALIGN
#define minilib_macros_alignment_h
#endif
#ifdef mini__ioctl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_opendir
static DIR *opendir(const char *name );
#endif
#ifdef mini__capget
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__timer_create
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_strdup
char *strdup(const char *source);
#endif
#ifdef mini__move_pages
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_atexit
static int atexit( functionp* func );
#endif
#ifdef mini__msync
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fgetsp
char* fgetsp(char *buf, int size, FILE* F);
#endif
#ifdef mini__shutdown
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__rt_sigqueueinfo
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fsync
#define minilib_include_lseek_h
#endif
#ifdef mini_group_print
#define minilib_macros_defgroups_h
#endif
#ifdef mini__wait4
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_stpncpy
char *stpncpy(char *dest, const char *src, int size);
#endif
#ifdef mini_bsd_cksum
unsigned int bsd_cksum( const char* p, unsigned int len );
#endif
#ifdef mini_srand
void srand( unsigned int i );
#endif
#ifdef mini_inet_aton
int inet_aton(const char* s, struct in_addr *addr);
#endif
#ifdef mini__symlinkat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__swapon
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sync_file_range
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_sys_brk
static long sys_brk(unsigned long addr);
#endif
#ifdef mini__waitid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__ioprio_get
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__io_submit
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_sigsuspend
static int sigsuspend( const sigset_t *mask );
#define include_minilib_src_process_sigaction_c
#endif
#ifdef mini__timer_gettime
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sched_getattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__pipe2
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_scandir
int scandir(const char *path, struct dirent **listing[], int (*fp_select)(const struct dirent *),	int (*cmp)(const struct dirent **, const struct dirent **));
#endif
#ifdef mini__setsockopt
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_strncasecmp
int strncasecmp(const char*c1,const char*c2,int len);
#define include_minilib_src_string_strcmp_c
#endif
#ifdef mini__sched_get_priority_max
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__perf_event_open
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fread
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_endpwent
void endpwent();
#endif
#ifdef mini_ntohl
#define ntohl(i) htonl(i)
#endif
#ifdef mini__setpgid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__rt_sigaction
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_where
int where(const char *file,char *buf);
#endif
#ifdef mini_bsd_cksumblock
unsigned int bsd_cksumblock( unsigned int hash, const char* p, unsigned int len );
#endif
#ifdef mini_fexecveat
#define minilib_include_fexecveat_h
#endif
#ifdef mini__mmap
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__ioprio_set
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fsetpos
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_max_groupmembers
#define minilib_include_globaldefs_h
#endif
#ifdef mini_ultodec
int ultodec(unsigned long ui, char *buf, int prec, char limiter );
#define include_minilib_src_conversions_ltodec_c
#endif
#ifdef mini__faccessat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__chdir
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_htonl
static uint32_t htonl(uint32_t i);
#endif
#ifdef mini_strlcpy
char *strlcpy(char *dest, const char *src, int n);
#endif
#ifdef mini_sigfillset
static int sigfillset(sigset_t *set);
#define include_minilib_src_process_sigaction_c
#endif
#ifdef mini__mknodat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__process_vm_writev
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_match_ext
int match_ext(char *text, const char *re, void(*p_match)(int number, char *pos,int len, void *userdata), int(*p_match_char)(int number, char *match_char, void *userdata), tmatch_ext *st_match, void *userdata);
#endif
#ifdef mini__fanotify_init
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__quotactl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fdopen
FILE *fdopen(int fd, const char* mode);
#define include_minilib_src_streams_fopen_c
#endif
#ifdef mini__rt_sigprocmask
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_getchar
#define getchar() fgetc(0)
#endif
#ifdef mini_fgetul
unsigned long int fgetul(FILE* F);
#endif
#ifdef mini_clone_t
int clone_t(int flags);
#endif
#ifdef mini_OPTFENCE
#define minilib_include_syscall_h
#endif
#ifdef mini__seccomp
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__creat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_vexec_q
int vexec_q( const char* path, char* const* argv, char* const* envp );
#endif
#ifdef mini_execv
static inline int execv(const char *pathname, char *const argv[]);
#endif
#ifdef mini__signalfd4
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_shortcolornames
#define minilib_include_ansicolors_h
#endif
#ifdef mini__mq_notify
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_system
int system( const char* command );
#endif
#ifdef mini__getpeername
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__inotify_rm_watch
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_readdir
struct dirent *readdir(DIR *dir);
#endif
#ifdef mini__getsid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_poll
#define minilib_include_poll_h
#endif
#ifdef mini__getresuid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setpriority
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__memfd_create
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fwrite
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_setenv
int setenv( const char *name, const char *value, int overwrite );
#endif
#ifdef mini__munlockall
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__shmget
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__set_robust_list
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_feof
#define minilib_include_mini_fstream_h
#endif
#ifdef mini__init_module
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_atol
long atol(const char *c);
#endif
#ifdef mini__pause
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fflush
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_error
#define error( status, errnum, fmt ... ) { fprintf(stderr,fmt ); if (errnum) fprints(stderr,":",strerror(errnum)); if ( status ) exit(status); }
#endif
#ifdef mini__getgroups
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_gets
#define gets(F) fgets(F,0xfffffff,stdin)
#endif
#ifdef mini_endgrent
void endgrent();
#endif
#ifdef mini_grantpt
int grantpt(int fd);
#endif
#ifdef mini__newfstatat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sched_yield
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fsync
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fchmodat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_stpcpy
char *stpcpy(char *dest, const char *src);
#endif
#ifdef mini__recvmsg
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sendmmsg
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__finit_module
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__lstat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_abort
void abort();
#endif
#ifdef mini__name_to_handle_at
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_ftruncate
#define minilib_include_lseek_h
#endif
#ifdef mini__pwrite64
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_group_write
#define minilib_macros_defgroups_h
#endif
#ifdef mini__rmdir
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_sigaddset
int sigaddset(sigset_t *set, int sig);
#define include_minilib_src_process_sigaction_c
#endif
#ifdef mini__sched_getaffinity
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__settimeofday
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_rewinddir
void rewinddir(DIR *dir);
#endif
#ifdef mini_putenv
int putenv( char *string );
#endif
#ifdef mini__syncfs
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_seekdir
void seekdir(DIR *dir, long off);
#endif
#ifdef mini_itobin
#define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )
#endif
#ifdef mini__lgetxattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mknod
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_freopen
FILE *freopen(const char* filename, const char* mode, FILE *F);
#define include_minilib_src_streams_fopen_c
#endif
#ifdef mini__rt_tgsigqueueinfo
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mount
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__vfork
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fgetsn
int fgetsn(char *buf, int size, FILE* F);
#endif
#ifdef mini__epoll_ctl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__unshare
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setxattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__io_cancel
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setgid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__dup3
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__utimensat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__gettid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__inotify_init1
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mq_timedsend
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__splice
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__chmod
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fchdir
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_config
#define minilib_include_config_h
#endif
#ifdef mini__lsetxattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__unlinkat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sched_rr_get_interval
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fprint
#define fprint(...) fprintf(__VA_ARGS__)
#endif
#ifdef mini__getdents64
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__timer_settime
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__exit_group
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sched_setattr
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__writev
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getppid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fwritesl
#define fwritesl(fd,str) write(fd,str"\n",sizeof(str)+1)
#endif
#ifdef mini_mkfifo
#define minilib_include_mkfifo_h
#endif
#ifdef mini__clone
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__dup2
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__timerfd_settime
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_err
#define err( status, fmt ... ) { fprintf(stderr,fmt ); fprints(stderr,":",strerror(errno)); exit(status); }
#endif
#ifdef mini__rt_sigtimedwait
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__set_mempolicy
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__vmsplice
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__tee
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getdents
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__inotify_init
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__readlink
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fclose
#define minilib_include_mini_fstream_h
#endif
#ifdef mini_dirname
char *dirname(char *s);
#endif
#ifdef mini__poll
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_getpwnam
struct passwd *getpwnam(const char* name);
#endif
#ifdef mini__ustat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__mkdir
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_telldir
long telldir(DIR *dir);
#endif
#ifdef mini_creat
int volatile creat( const char *s, int mode );
#define include_minilib_src_file_open_c
#endif
#ifdef mini__fchownat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__shmctl
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__socketpair
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__getrlimit
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_sigprocmask
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
#define include_minilib_src_process_sigaction_c
#endif
#ifdef mini__readv
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_calloc
void* calloc(int nmemb, int size);
#endif
#ifdef mini_optimization_fence
#define minilib_include_minilib_global_h
#endif
#ifdef mini__clock_getres
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__connect
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__fallocate
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__lookup_dcookie
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_initgroups
int initgroups(const char* user, gid_t group);
#endif
#ifdef mini_fgetud
unsigned int fgetud(FILE* F);
#endif
#ifdef mini__execve
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__renameat
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_short_errstr
#define minilib_include_errstrshort_h
#endif
#ifdef mini__listen
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__msgsnd
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__futex
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__sysfs
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__time
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini__setuid
#define minilib_include_syscalls_x64_h
#endif
#ifdef mini_fstream_h
#ifndef inc_mini_fstream_h
#define inc_mini_fstream_h
#ifndef stdarg_h
#define stdarg_h
#if 1
#if __GNUC__ >= 3
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
#ifdef __GNUC__
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))
#define va_arg(ap, type) ( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))),	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )
#else
#ifdef __x86_64__
#ifndef _WIN64
typedef void *va_list;
va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);
#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type) (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)
#else 
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif
#else 
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED
#endif
#endif
#endif
#endif
#ifndef SEEK_SET
#define SEEK_SET        0       
#define SEEK_CUR        1       
#define SEEK_END        2       
#define SEEK_MAX        SEEK_END
#endif
#ifdef mini_buf
#ifndef mini_fstream
#define mini_fstream
#endif
#endif
static inline int __attribute__((always_inline)) fflush( FILE *F ){
return(0);
}
#ifndef mini_fstream
static int fileno( FILE *F ){
if ( F==stdin )
return ( 0 );
if ( F==stdout )
return(1);
if ( F==stderr )
return(2);
exit(-1);
return(-1);
}
#else
int snprintf( char *buf, size_t size, const char *fmt, ... );
static int fileno( FILE *f ){
return( (f==0) ? 0 : (*f & FD_MASK) );
}
#ifdef mini_fclose
static inline int __attribute__((always_inline)) fclose( FILE* f ){
int fd = fileno(f);
*f = -1;
if ( f[1] == mlgl->stream[mlgl->pstream] )
for ( mlgl->pstream--; mlgl->stream[mlgl->pstream-1] == -1; mlgl->pstream-- );
return( close(fd) );
}
#endif
#define printf(...) fprintf(stdout,__VA_ARGS__)
#define fprint(...) fprintf(__VA_ARGS__)
#define vfprintf(...) fprintf(__VA_ARGS__)
static inline size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f){
const void *p = ptr;
int a;
for ( a = 0; a<nmemb; a++ ){
if ( write( fileno(f), p, size ) != size ){
*f = *f | ERR_FLAG;
return(a);
}
p = p + size;
}
return(a);
}
#ifdef mini_lseek
static inline long ftell(FILE *f){
return(lseek( fileno(f), 0, SEEK_CUR ));
}
static inline void fgetpos(FILE *f, long *pos ){
*pos = ftell(f);
}
static inline int fsetpos(FILE *f, int pos ){
int r = lseek( fileno(f), pos, SEEK_SET );
if ( r==pos ){ //
*f = *f & FD_MASK; // unset feof
return(r);
}
return(r); // todo set errno
}
static inline int fseek(FILE *f, long offset, int whence ){
int r = lseek( fileno(f), offset, whence );
if ( r>0 )
*f = *f & FD_MASK; // clear feof
return(r);
}
static inline void rewind( FILE *f ){
fseek(f, 0, SEEK_SET);
}
#endif
#ifdef mini_fread
static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f){
void *p = ptr;
int a;
for ( a = 0; a<nmemb; a++ ){
if ( read( fileno(f), p, size ) != size ){
*f = *f | FEOF_FLAG ; // set feof. Could have also been another error.
return(a);
}
p = p + size;
}
return(a);
}
#endif
static inline int feof(FILE *f){
if ( *f & FLAG_MASK )
return(1);
return(0);
}
static inline int ferror(FILE *f){
if ( *f & FLAG_MASK )
return(1);
return(0);
}
static inline void clearerr(FILE *f){
*f = *f & FD_MASK;
}
static inline void clearerror(FILE *f){
*f = *f & FD_MASK;
}
static void setbuf(FILE *stream, char *buf){
}
static int setvbuf(FILE *stream, char *buf, int mode, size_t size){
return(0);
}
#endif
#endif
#endif
#ifdef stdarg_h
#endif
#ifdef prints_h
#ifndef prints_h
#define prints_h
extern int dprints(int fd, const char *msg,...);
#define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)
#define prints(...) _mprints(__VA_ARGS__,0)
#define eprints(...) dprints(STDERR_FILENO,__VA_ARGS__,0)
#define fprints(F,...) dprints(fileno(F),__VA_ARGS__,0)
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)
#define eprintsl(...) dprints(STDERR_FILENO,__VA_ARGS__,"\n",0)
#endif
#endif
#ifdef minilib_include_mkfifo_h
static int mkfifo( const char* path, mode_t mode ){
return( mknod(path, mode | S_IFIFO, 0 ) );
}
#endif
#ifdef minilib_macros_getoptm_h
#endif
#ifdef minilib_include_mremap_h
static void* volatile __attribute__((optimize("O0"))) mremap(void* addr, size_t old_len, size_t new_len, int flags, void* new_addr){
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
long sysret;
register long int r10 asm ("r10") = flags;
register long int r8 asm ("r8") = new_addr;
__SYSCALL_ASM(sysret,__NR_select) , "D" (addr), "S" (old_len), "d" (new_len), "r" (r10), "r" (r8) __callend;
#ifdef mini_errno
if ( sysret<0){
errno = -sysret;
return(-1);}
#endif
return((void*)sysret);
#pragma GCC diagnostic pop
}
#endif
#ifdef minilib_include_seterrno_h
#ifdef mini_errno
#define seterrno(e) { if ( e>0 ) errno = e; else errno=-e; }
#else
#define seterrno(e) {}
#endif
#endif
#ifdef minilib_include_syscall_h
#endif
#ifdef minilib_include_dirent_h
#endif
#ifdef minilib_include_math_h
#ifndef mini_math_h
#define mini_math_h
static div_t div(int numerator, int denominator){
div_t ret;
ret.quot = numerator/denominator;
ret.rem = numerator-(ret.quot*denominator);
return(ret);
}
static ldiv_t ldiv(long int numerator, long int denominator){
ldiv_t ret;
ret.quot = numerator/denominator;
ret.rem = numerator-(ret.quot*denominator);
return(ret);
}
static int abs(int i){
return( (i >= 0) ? i : -i);
}
static long int labs(long int i){
return( (i >= 0) ? i : -i);
}
#endif
#endif
#ifdef minilib_include_errstr2_h
#define ERRNO_MAX 133
static const char* verbose_errstr2(int num){
if ( num > ERRNO_MAX || num < 0 ){
return("Errno unknown");
}
char *errstr =
"Internal error (errno=0)\0"
"Operation not permitted\0"
"No such file or directory\0"
"No such process\0"
"Interrupted system call\0"
"I/O error\0"
"No such device or address\0"
"Argument list too long\0"
"Exec format error\0"
"Bad file number\0"
"No child processes\0"
"Try again\0"
"Out of memory\0"
"Permission denied\0"
"Bad address\0"
"Block device required\0"
"Device or resource busy\0"
"File exists\0"
"Cross-device link\0"
"No such device\0"
"Not a directory\0"
"Is a directory\0"
"Invalid argument\0"
"File table overflow\0"
"Too many open files\0"
"Not a typewriter\0"
"Text file busy\0"
"File too large\0"
"No space left on device\0"
"Illegal seek\0"
"Read-only file system\0"
"Too many links\0"
"Broken pipe\0"
"Math argument out of domain of func\0"
"Math result not representable\0"
"Resource deadlock would occur\0"
"File name too long\0"
"No record locks available\0"
"Invalid system call number\0"
"Directory not empty\0"
"Too many symbolic links encountered\0"
"Operation would block\0"
"No message of desired type\0"
"Identifier removed\0"
"Channel number out of range\0"
"Level 2 not synchronized\0"
"Level 3 halted\0"
"Level 3 reset\0"
"Link number out of range\0"
"Protocol driver not attached\0"
"No CSI structure available\0"
"Level 2 halted\0"
"Invalid exchange\0"
"Invalid request descriptor\0"
"Exchange full\0"
"No anode\0"
"Invalid request code\0"
"Invalid slot\0"
"Resource deadlock would occur\0"
"Bad font file format\0"
"Device not a stream\0"
"No data available\0"
"Timer expired\0"
"Out of streams resources\0"
"Machine is not on the network\0"
"Package not installed\0"
"Object is remote\0"
"Link has been severed\0"
"Advertise error\0"
"Srmount error\0"
"Communication error on send\0"
"Protocol error\0"
"Multihop attempted\0"
"RFS specific error\0"
"Not a data message\0"
"Value too large for defined data type\0"
"Name not unique on network\0"
"File descriptor in bad state\0"
"Remote address changed\0"
"Can not access a needed shared library\0"
"Accessing a corrupted shared library\0"
".lib section in a.out corrupted\0"
"Attempting to link in too many shared libraries\0"
"Cannot exec a shared library directly\0"
"Illegal byte sequence\0"
"Interrupted system call should be restarted\0"
"Streams pipe error\0"
"Too many users\0"
"Socket operation on non-socket\0"
"Destination address required\0"
"Message too long\0"
"Protocol wrong type for socket\0"
"Protocol not available\0"
"Protocol not supported\0"
"Socket type not supported\0"
"Operation not supported on transport endpoint\0"
"Protocol family not supported\0"
"Address family not supported by protocol\0"
"Address already in use\0"
"Cannot assign requested address\0"
"Network is down\0"
"Network is unreachable\0"
"Network dropped connection because of reset\0"
"Software caused connection abort\0"
"Connection reset by peer\0"
"No buffer space available\0"
"Transport endpoint is already connected\0"
"Transport endpoint is not connected\0"
"Cannot send after transport endpoint shutdown\0"
"Too many references: cannot splice\0"
"Connection timed out\0"
"Connection refused\0"
"Host is down\0"
"No route to host\0"
"Operation already in progress\0"
"Operation now in progress\0"
"Stale file handle\0"
"Structure needs cleaning\0"
"Not a XENIX named type file\0"
"No XENIX semaphores available\0"
"Is a named type file\0"
"Remote I/O error\0"
"Quota exceeded\0"
"No medium found\0"
"Wrong medium type\0"
"Operation Canceled\0"
"Required key not available\0"
"Key has expired\0"
"Key has been revoked\0"
"Key was rejected by service\0"
"Owner died\0"
"State not recoverable\0"
"Operation not possible due to RF-kill\0"
"Memory page has hardware error";
char *c = errstr;
for ( ; num > 0; num-- ){
do {
c++;
} while ( *c != 0 );
}
c++;
return(c);
}
#endif
#ifdef minilib_include_errstr_h
#ifndef ERRNO_MAX
#define ERRNO_MAX 133
#endif
const char* verbose_errstr(int num){
const char* unknown = "Errno unknown";
if ( num > ERRNO_MAX || num < 0 ){
return("Errno unknown");
}
const char *errstr[] = { "Internal error (errno=0)",
"Operation not permitted",
"No such file or directory",
"No such process",
"Interrupted system call",
"I/O error",
"No such device or address",
"Argument list too long",
"Exec format error",
"Bad file number",
"No child processes",
"Try again",
"Out of memory",
"Permission denied",
"Bad address",
"Block device required",
"Device or resource busy",
"File exists",
"Cross-device link",
"No such device",
"Not a directory",
"Is a directory",
"Invalid argument",
"File table overflow",
"Too many open files",
"Not a typewriter",
"Text file busy",
"File too large",
"No space left on device",
"Illegal seek",
"Read-only file system",
"Too many links",
"Broken pipe",
"Math argument out of domain of func",
"Math result not representable",
"Resource deadlock would occur",
"File name too long",
"No record locks available",
"Invalid system call number",
"Directory not empty",
"Too many symbolic links encountered",
"Operation would block",
"No message of desired type",
"Identifier removed",
"Channel number out of range",
"Level 2 not synchronized",
"Level 3 halted",
"Level 3 reset",
"Link number out of range",
"Protocol driver not attached",
"No CSI structure available",
"Level 2 halted",
"Invalid exchange",
"Invalid request descriptor",
"Exchange full",
"No anode",
"Invalid request code",
"Invalid slot",
"Resource deadlock would occur",
"Bad font file format",
"Device not a stream",
"No data available",
"Timer expired",
"Out of streams resources",
"Machine is not on the network",
"Package not installed",
"Object is remote",
"Link has been severed",
"Advertise error",
"Srmount error",
"Communication error on send",
"Protocol error",
"Multihop attempted",
"RFS specific error",
"Not a data message",
"Value too large for defined data type",
"Name not unique on network",
"File descriptor in bad state",
"Remote address changed",
"Can not access a needed shared library",
"Accessing a corrupted shared library",
".lib section in a.out corrupted",
"Attempting to link in too many shared libraries",
"Cannot exec a shared library directly",
"Illegal byte sequence",
"Interrupted system call should be restarted",
"Streams pipe error",
"Too many users",
"Socket operation on non-socket",
"Destination address required",
"Message too long",
"Protocol wrong type for socket",
"Protocol not available",
"Protocol not supported",
"Socket type not supported",
"Operation not supported on transport endpoint",
"Protocol family not supported",
"Address family not supported by protocol",
"Address already in use",
"Cannot assign requested address",
"Network is down",
"Network is unreachable",
"Network dropped connection because of reset",
"Software caused connection abort",
"Connection reset by peer",
"No buffer space available",
"Transport endpoint is already connected",
"Transport endpoint is not connected",
"Cannot send after transport endpoint shutdown",
"Too many references: cannot splice",
"Connection timed out",
"Connection refused",
"Host is down",
"No route to host",
"Operation already in progress",
"Operation now in progress",
"Stale file handle",
"Structure needs cleaning",
"Not a XENIX named type file",
"No XENIX semaphores available",
"Is a named type file",
"Remote I/O error",
"Quota exceeded",
"No medium found",
"Wrong medium type",
"Operation Canceled",
"Required key not available",
"Key has expired",
"Key has been revoked",
"Key was rejected by service",
"Owner died",
"State not recoverable",
"Operation not possible due to RF-kill",
"Memory page has hardware error" };
return(errstr[num]);
}
#endif
#ifdef minilib_include_lseek_h
#ifndef mini_lseek_h
#define mini_lseek_h
#ifndef SEEK_SET
#define SEEK_SET        0       
#define SEEK_CUR        1       
#define SEEK_END        2       
#define SEEK_MAX        SEEK_END
#endif
extern int sysret;
#ifndef mini_globals_on_stack
extern int errno;
#endif
#endif
#endif
#ifdef minilib_include_termio_h
#endif
#ifdef minilib_include_globaldefs_h
#endif
#ifdef minilib_include_fexecve_h
static inline int fexecve(int fd, char *const argv[], char *const envp[]){
return( execveat(fd,"",argv,envp,AT_EMPTY_PATH) );
}
#endif
#ifdef minilib_include_poll_h
#define POLLIN     0x001
#define POLLPRI    0x002
#define POLLOUT    0x004
#define POLLERR    0x008
#define POLLHUP    0x010
#define POLLNVAL   0x020
#define POLLRDNORM 0x040
#define POLLRDBAND 0x080
#define POLLWRNORM 0x100
#define POLLWRBAND 0x200
#define POLLMSG    0x400
typedef unsigned int nfds_t;
struct pollfd{
int fd;
short events;
short revents;
};
static inline int poll(struct pollfd *fds, nfds_t cnt, int timeout){
int ret;
__SYSCALL_ASM(ret,__NR_poll) ,"D"(fds), "S"(cnt), "d"(timeout) __callend;
#ifdef mini_errno
if ( ret<0){
errno = -ret;
return(-1);
}
#endif
return(ret);
}
#endif
#ifdef minilib_include_config_h
#endif
#ifdef minilib_macros_defgroups_h
#endif
#ifdef minilib_include_network_h
#ifdef mini_network
#define IFHWADDRLEN  6
#define IF_NAMESIZE  16
#define IFNAMSIZ  IF_NAMESIZE
#define ifr_name  ifr_ifrn.ifrn_name
#define ifr_hwaddr   ifr_ifru.ifru_hwaddr
#define ifr_addr  ifr_ifru.ifru_addr
#define ifr_dstaddr  ifr_ifru.ifru_dstaddr
#define ifr_broadaddr   ifr_ifru.ifru_broadaddr
#define ifr_netmask  ifr_ifru.ifru_netmask
#define ifr_flags ifr_ifru.ifru_flags
#define ifr_metric   ifr_ifru.ifru_ivalue
#define ifr_mtu      ifr_ifru.ifru_mtu
#define ifr_map      ifr_ifru.ifru_map
#define ifr_slave ifr_ifru.ifru_slave
#define ifr_data  ifr_ifru.ifru_data
#define ifr_ifindex  ifr_ifru.ifru_ivalue
#define ifr_bandwidth   ifr_ifru.ifru_ivalue
#define ifr_qlen  ifr_ifru.ifru_ivalue
#define ifr_newname  ifr_ifru.ifru_newname
struct udphdr {
uint16_t uh_sport;
uint16_t uh_dport;
uint16_t uh_ulen;
uint16_t uh_sum;
};
#define UDP_CORK  1
#define UDP_ENCAP 100
#define UDP_NO_CHECK6_TX 101
#define UDP_NO_CHECK6_RX 102
#define UDP_SEGMENT  103
#define UDP_ENCAP_ESPINUDP_NON_IKE 1
#define UDP_ENCAP_ESPINUDP 2
#define UDP_ENCAP_L2TPINUDP   3
#define UDP_ENCAP_GTP0     4
#define UDP_ENCAP_GTP1U    5
#define SOL_UDP            17
#define IPPORT_RESERVED 1024
#define IPPROTO_IP       0
#define IPPROTO_HOPOPTS  0
#define IPPROTO_ICMP     1
#define IPPROTO_IGMP     2
#define IPPROTO_IPIP     4
#define IPPROTO_TCP      6
#define IPPROTO_EGP      8
#define IPPROTO_PUP      12
#define IPPROTO_UDP      17
#define IPPROTO_IDP      22
#define IPPROTO_TP       29
#define IPPROTO_DCCP     33
#define IPPROTO_IPV6     41
#define IPPROTO_ROUTING  43
#define IPPROTO_FRAGMENT 44
#define IPPROTO_RSVP     46
#define IPPROTO_GRE      47
#define IPPROTO_ESP      50
#define IPPROTO_AH       51
#define IPPROTO_ICMPV6   58
#define IPPROTO_NONE     59
#define IPPROTO_DSTOPTS  60
#define IPPROTO_MTP      92
#define IPPROTO_BEETPH   94
#define IPPROTO_ENCAP    98
#define IPPROTO_PIM      103
#define IPPROTO_COMP     108
#define IPPROTO_SCTP     132
#define IPPROTO_MH       135
#define IPPROTO_UDPLITE  136
#define IPPROTO_MPLS     137
#define IPPROTO_RAW      255
#define IPPROTO_MAX      256
#define	IPVERSION	4
#define	IP_MAXPACKET	65535
#define	IPTOS_ECN_MASK		0x03
#define	IPTOS_ECN(x)		((x) & IPTOS_ECN_MASK)
#define	IPTOS_ECN_NOT_ECT	0x00
#define	IPTOS_ECN_ECT1		0x01
#define	IPTOS_ECN_ECT0		0x02
#define	IPTOS_ECN_CE		0x03
#define	IPTOS_DSCP_MASK		0xfc
#define	IPTOS_DSCP(x)		((x) & IPTOS_DSCP_MASK)
#define	IPTOS_DSCP_AF11		0x28
#define	IPTOS_DSCP_AF12		0x30
#define	IPTOS_DSCP_AF13		0x38
#define	IPTOS_DSCP_AF21		0x48
#define	IPTOS_DSCP_AF22		0x50
#define	IPTOS_DSCP_AF23		0x58
#define	IPTOS_DSCP_AF31		0x68
#define	IPTOS_DSCP_AF32		0x70
#define	IPTOS_DSCP_AF33		0x78
#define	IPTOS_DSCP_AF41		0x88
#define	IPTOS_DSCP_AF42		0x90
#define	IPTOS_DSCP_AF43		0x98
#define	IPTOS_DSCP_EF		0xb8
#define	IPTOS_CLASS_MASK	0xe0
#define	IPTOS_CLASS(x)		((x) & IPTOS_CLASS_MASK)
#define	IPTOS_CLASS_CS0		0x00
#define	IPTOS_CLASS_CS1		0x20
#define	IPTOS_CLASS_CS2		0x40
#define	IPTOS_CLASS_CS3		0x60
#define	IPTOS_CLASS_CS4		0x80
#define	IPTOS_CLASS_CS5		0xa0
#define	IPTOS_CLASS_CS6		0xc0
#define	IPTOS_CLASS_CS7		0xe0
#define	IPTOS_CLASS_DEFAULT	IPTOS_CLASS_CS0
#define	IPTOS_TOS_MASK		0x1E
#define	IPTOS_TOS(tos)		((tos) & IPTOS_TOS_MASK)
#define	IPTOS_LOWDELAY		0x10
#define	IPTOS_THROUGHPUT	0x08
#define	IPTOS_RELIABILITY	0x04
#define	IPTOS_LOWCOST		0x02
#define	IPTOS_MINCOST		IPTOS_LOWCOST
#define	IPTOS_PREC_MASK			0xe0
#define	IPTOS_PREC(tos)                ((tos) & IPTOS_PREC_MASK)
#define	IPTOS_PREC_NETCONTROL		0xe0
#define	IPTOS_PREC_INTERNETCONTROL	0xc0
#define	IPTOS_PREC_CRITIC_ECP		0xa0
#define	IPTOS_PREC_FLASHOVERRIDE	0x80
#define	IPTOS_PREC_FLASH		0x60
#define	IPTOS_PREC_IMMEDIATE		0x40
#define	IPTOS_PREC_PRIORITY		0x20
#define	IPTOS_PREC_ROUTINE		0x00
#define	IPOPT_COPY		0x80
#define	IPOPT_CLASS_MASK	0x60
#define	IPOPT_NUMBER_MASK	0x1f
#define	IPOPT_COPIED(o)		((o) & IPOPT_COPY)
#define	IPOPT_CLASS(o)		((o) & IPOPT_CLASS_MASK)
#define	IPOPT_NUMBER(o)		((o) & IPOPT_NUMBER_MASK)
#define	IPOPT_CONTROL		0x00
#define	IPOPT_RESERVED1		0x20
#define	IPOPT_DEBMEAS		0x40
#define	IPOPT_MEASUREMENT       IPOPT_DEBMEAS
#define	IPOPT_RESERVED2		0x60
#define	IPOPT_EOL		0
#define	IPOPT_END		IPOPT_EOL
#define	IPOPT_NOP		1
#define	IPOPT_NOOP		IPOPT_NOP
#define	IPOPT_RR		7
#define	IPOPT_TS		68
#define	IPOPT_TIMESTAMP		IPOPT_TS
#define	IPOPT_SECURITY		130
#define	IPOPT_SEC		IPOPT_SECURITY
#define	IPOPT_LSRR		131
#define	IPOPT_SATID		136
#define	IPOPT_SID		IPOPT_SATID
#define	IPOPT_SSRR		137
#define	IPOPT_RA		148
#define	IPOPT_OPTVAL		0
#define	IPOPT_OLEN		1
#define	IPOPT_OFFSET		2
#define	IPOPT_MINOFF		4
#define	MAX_IPOPTLEN		40
#define	IPOPT_TS_TSONLY		0
#define	IPOPT_TS_TSANDADDR	1
#define	IPOPT_TS_PRESPEC	3
#define	IPOPT_SECUR_UNCLASS	0x0000
#define	IPOPT_SECUR_CONFID	0xf135
#define	IPOPT_SECUR_EFTO	0x789a
#define	IPOPT_SECUR_MMMM	0xbc4d
#define	IPOPT_SECUR_RESTR	0xaf13
#define	IPOPT_SECUR_SECRET	0xd788
#define	IPOPT_SECUR_TOPSECRET	0x6bc5
#define	MAXTTL		255
#define	IPDEFTTL	64
#define	IPFRAGTTL	60
#define	IPTTLDEC	1
#define	IP_MSS		576
#define ETHER_ADDR_LEN 6
#define IFF_UP 0x1
#define IFF_BROADCAST 0x2
#define IFF_DEBUG 0x4
#define IFF_LOOPBACK 0x8
#define IFF_POINTOPOINT 0x10
#define IFF_NOTRAILERS 0x20
#define IFF_RUNNING 0x40
#define IFF_NOARP 0x80
#define IFF_PROMISC 0x100
#define IFF_ALLMULTI 0x200
#define IFF_MASTER 0x400
#define IFF_SLAVE 0x800
#define IFF_MULTICAST 0x1000
#define IFF_PORTSEL 0x2000
#define IFF_AUTOMEDIA 0x4000
#define IFF_DYNAMIC 0x8000
#define IFF_LOWER_UP 0x10000
#define IFF_DORMANT 0x20000
#define IFF_ECHO 0x40000
#define IFF_VOLATILE (IFF_LOOPBACK|IFF_POINTOPOINT|IFF_BROADCAST| \
IFF_ECHO|IFF_MASTER|IFF_SLAVE|IFF_RUNNING|IFF_LOWER_UP|IFF_DORMANT)
#define ETH_P_802_3  0x0001
#define ETH_P_AX25   0x0002
#define ETH_P_ALL 0x0003
#define ETH_P_802_2  0x0004
#define ETH_P_SNAP   0x0005
#define ETH_P_DDCMP     0x0006
#define ETH_P_WAN_PPP   0x0007
#define ETH_P_PPP_MP    0x0008
#define ETH_P_LOCALTALK 0x0009
#define ETH_P_CAN 0x000C
#define ETH_P_CANFD  0x000D
#define ETH_P_PPPTALK   0x0010
#define ETH_P_TR_802_2  0x0011
#define ETH_P_MOBITEX   0x0015
#define ETH_P_CONTROL   0x0016
#define ETH_P_IRDA   0x0017
#define ETH_P_ECONET 0x0018
#define ETH_P_HDLC   0x0019
#define ETH_P_ARCNET 0x001A
#define ETH_P_DSA 0x001B
#define ETH_P_TRAILER   0x001C
#define ETH_P_PHONET 0x00F5
#define ETH_P_IEEE802154 0x00F6
#define ETH_P_CAIF   0x00F7
#define ETH_P_XDSA   0x00F8
#define ETH_P_MAP 0x00F9
#define ETH_ALEN  6
#define ETH_TLEN  2
#define ETH_HLEN  14
#define ETH_ZLEN  60
#define ETH_DATA_LEN 1500
#define ETH_FRAME_LEN   1514
#define ETH_FCS_LEN  4
#define ETH_MIN_MTU  68
#define ETH_MAX_MTU  0xFFFFU
#define ETH_P_LOOP   0x0060
#define ETH_P_PUP 0x0200
#define ETH_P_PUPAT  0x0201
#define ETH_P_TSN 0x22F0
#define ETH_P_ERSPAN2   0x22EB
#define ETH_P_IP  0x0800
#define ETH_P_X25 0x0805
#define ETH_P_ARP 0x0806
#define  ETH_P_BPQ   0x08FF
#define ETH_P_IEEEPUP   0x0a00
#define ETH_P_IEEEPUPAT 0x0a01
#define ETH_P_BATMAN 0x4305
#define ETH_P_DEC       0x6000
#define ETH_P_DNA_DL    0x6001
#define ETH_P_DNA_RC    0x6002
#define ETH_P_DNA_RT    0x6003
#define ETH_P_LAT       0x6004
#define ETH_P_DIAG      0x6005
#define ETH_P_CUST      0x6006
#define ETH_P_SCA       0x6007
#define ETH_P_TEB 0x6558
#define ETH_P_RARP      0x8035
#define ETH_P_ATALK  0x809B
#define ETH_P_AARP   0x80F3
#define ETH_P_8021Q  0x8100
#define ETH_P_IPX 0x8137
#define ETH_P_IPV6   0x86DD
#define ETH_P_PAUSE  0x8808
#define ETH_P_SLOW   0x8809
#define ETH_P_WCCP   0x883E
#define ETH_P_MPLS_UC   0x8847
#define ETH_P_MPLS_MC   0x8848
#define ETH_P_ATMMPOA   0x884c
#define ETH_P_PPP_DISC  0x8863
#define ETH_P_PPP_SES   0x8864
#define ETH_P_LINK_CTL  0x886c
#define ETH_P_ATMFATE   0x8884
#define ETH_P_PAE 0x888E
#define ETH_P_AOE 0x88A2
#define ETH_P_8021AD 0x88A8
#define ETH_P_802_EX1   0x88B5
#define ETH_P_ERSPAN 0x88BE
#define ETH_P_PREAUTH   0x88C7
#define ETH_P_TIPC   0x88CA
#define ETH_P_MACSEC 0x88E5
#define ETH_P_8021AH 0x88E7
#define ETH_P_MVRP   0x88F5
#define ETH_P_1588   0x88F7
#define ETH_P_NCSI   0x88F8
#define ETH_P_PRP 0x88FB
#define ETH_P_FCOE   0x8906
#define ETH_P_TDLS   0x890D
#define ETH_P_FIP 0x8914
#define ETH_P_IBOE   0x8915
#define ETH_P_80221  0x8917
#define ETH_P_HSR 0x892F
#define ETH_P_NSH 0x894F
#define ETH_P_LOOPBACK  0x9000
#define ETH_P_QINQ1  0x9100
#define ETH_P_QINQ2  0x9200
#define ETH_P_QINQ3  0x9300
#define ETH_P_EDSA   0xDADA
#define ETH_P_IFE 0xED3E
#define ETH_P_AF_IUCV   0xFBFB
#define ETH_P_802_3_MIN 0x0600
#define INADDR_ANY        ((in_addr_t) 0x00000000)
#define INADDR_BROADCAST  ((in_addr_t) 0xffffffff)
#define INADDR_NONE       ((in_addr_t) 0xffffffff)
#define INADDR_LOOPBACK   ((in_addr_t) 0x7f000001)
#define INADDR_UNSPEC_GROUP     ((in_addr_t) 0xe0000000)
#define INADDR_ALLHOSTS_GROUP   ((in_addr_t) 0xe0000001)
#define INADDR_ALLRTRS_GROUP    ((in_addr_t) 0xe0000002)
#define INADDR_MAX_LOCAL_GROUP  ((in_addr_t) 0xe00000ff)
#define IN6ADDR_ANY_INIT      { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } } }
#define IN6ADDR_LOOPBACK_INIT { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 } } }
#undef INET_ADDRSTRLEN
#undef INET6_ADDRSTRLEN
#define INET_ADDRSTRLEN  16
#define INET6_ADDRSTRLEN 46
typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;
struct in_addr { in_addr_t s_addr; };
struct in6_addr {
union {
uint8_t __s6_addr[16];
uint16_t __s6_addr16[8];
uint32_t __s6_addr32[4];
} __in6_union;
};
struct timestamp {
uint8_t len;
uint8_t ptr;
#if __BYTEORDER == __LITTLE_ENDIAN
unsigned int flags:4;
unsigned int overflow:4;
#else
unsigned int overflow:4;
unsigned int flags:4;
#endif
uint32_t data[9];
};
struct iphdr {
#if __BYTEORDER == __LITTLE_ENDIAN
unsigned int ihl:4;
unsigned int version:4;
#else
unsigned int version:4;
unsigned int ihl:4;
#endif
uint8_t tos;
uint16_t tot_len;
uint16_t id;
uint16_t frag_off;
uint8_t ttl;
uint8_t protocol;
uint16_t check;
uint32_t saddr;
uint32_t daddr;
};
struct ethhdr {
uint8_t h_dest[ETH_ALEN];
uint8_t h_source[ETH_ALEN];
uint16_t h_proto;
};
struct ip {
#if __BYTEORDER == __LITTLE_ENDIAN
unsigned int ip_hl:4;
unsigned int ip_v:4;
#else
unsigned int ip_v:4;
unsigned int ip_hl:4;
#endif
uint8_t ip_tos;
uint16_t ip_len;
uint16_t ip_id;
uint16_t ip_off;
uint8_t ip_ttl;
uint8_t ip_p;
uint16_t ip_sum;
struct in_addr ip_src, ip_dst;
};
#define  IP_RF 0x8000
#define  IP_DF 0x4000
#define  IP_MF 0x2000
#define  IP_OFFMASK 0x1fff
struct ip_timestamp {
uint8_t ipt_code;
uint8_t ipt_len;
uint8_t ipt_ptr;
#if __BYTEORDER == __LITTLE_ENDIAN
unsigned int ipt_flg:4;
unsigned int ipt_oflw:4;
#else
unsigned int ipt_oflw:4;
unsigned int ipt_flg:4;
#endif
uint32_t data[9];
};
#define  IPVERSION   4
#define  IP_MAXPACKET   65535
struct sockaddr_in {
unsigned short sin_family;
uint16_t sin_port;
struct in_addr sin_addr;
uint8_t sin_zero[8];
};
struct addrinfo {
int ai_flags;
int ai_family;
int ai_socktype;
int ai_protocol;
socklen_t ai_addrlen;
struct sockaddr *ai_addr;
char *ai_canonname;
struct addrinfo *ai_next;
};
struct ifmap {
unsigned long mem_start;
unsigned long mem_end;
uint16_t base_addr;
unsigned char irq;
unsigned char dma;
unsigned char port;
};
struct sockaddr_storage {
sa_family_t  ss_family;
uint32_t  __ss_align;
char __ss_padding[(128  - (2 * sizeof (uint32_t ))) ];
};
#define  ETHERTYPE_PUP     0x0200
#define ETHERTYPE_SPRITE   0x0500
#define  ETHERTYPE_IP      0x0800
#define  ETHERTYPE_ARP     0x0806
#define  ETHERTYPE_REVARP  0x8035
#define ETHERTYPE_AT    0x809B
#define ETHERTYPE_AARP     0x80F3
#define  ETHERTYPE_VLAN    0x8100
#define ETHERTYPE_IPX      0x8137
#define  ETHERTYPE_IPV6    0x86dd
#define ETHERTYPE_LOOPBACK 0x9000
#define  ETHER_TYPE_LEN 2
#define  ETHER_CRC_LEN  4
#define  ETHER_HDR_LEN  ETH_HLEN
#define  ETHER_MIN_LEN  (ETH_ZLEN + ETHER_CRC_LEN)
#define  ETHER_MAX_LEN  (ETH_FRAME_LEN + ETHER_CRC_LEN)
#define  ETHER_IS_VALID_LEN(foo) \
((foo) >= ETHER_MIN_LEN && (foo) <= ETHER_MAX_LEN)
#define  ETHERTYPE_TRAIL      0x1000
#define  ETHERTYPE_NTRAILER   16
#define  ETHERMTU ETH_DATA_LEN
#define  ETHERMIN (ETHER_MIN_LEN - ETHER_HDR_LEN - ETHER_CRC_LEN)
struct ether_addr {
uint8_t ether_addr_octet[ETH_ALEN];
};
struct ether_header {
uint8_t  ether_dhost[ETH_ALEN];
uint8_t  ether_shost[ETH_ALEN];
uint16_t ether_type;
};
struct ifreq {
union
{
char ifrn_name[IF_NAMESIZE];    
} ifr_ifrn;
union {
struct sockaddr ifru_addr;
struct sockaddr ifru_dstaddr;
struct sockaddr ifru_broadaddr;
struct sockaddr ifru_netmask;
struct  sockaddr ifru_hwaddr;
int16_t ifru_flags;
int32_t ifru_ivalue;
int32_t ifru_mtu;
struct ifmap ifru_map;
char ifru_slave[IF_NAMESIZE];
char ifru_newname[IF_NAMESIZE];
char* ifru_data;
} ifr_ifru;
};
struct sockaddr_ll {
unsigned short sll_family, sll_protocol;
int sll_ifindex;
unsigned short sll_hatype;
unsigned char sll_pkttype, sll_halen;
unsigned char sll_addr[8];
};
struct packet_mreq {
int mr_ifindex;
unsigned short int mr_type,  mr_alen;
unsigned char mr_address[8];
};
#define PACKET_HOST     	0
#define PACKET_BROADCAST   1
#define PACKET_MULTICAST   2
#define PACKET_OTHERHOST   3
#define PACKET_OUTGOING    4
#define PACKET_LOOPBACK    5
#define PACKET_FASTROUTE   6
#define PACKET_ADD_MEMBERSHIP    1
#define PACKET_DROP_MEMBERSHIP   2
#define  PACKET_RECV_OUTPUT      3
#define  PACKET_RX_RING       5
#define  PACKET_STATISTICS    6
#define PACKET_COPY_THRESH    7
#define PACKET_AUXDATA        8
#define PACKET_ORIGDEV        9
#define PACKET_VERSION        10
#define PACKET_HDRLEN         11
#define PACKET_RESERVE        12
#define PACKET_TX_RING        13
#define PACKET_LOSS           14
#define PACKET_VNET_HDR       15
#define PACKET_TX_TIMESTAMP   16
#define PACKET_TIMESTAMP      17
#define PACKET_FANOUT         18
#define PACKET_TX_HAS_OFF     19
#define PACKET_QDISC_BYPASS   20
#define PACKET_ROLLOVER_STATS 21
#define PACKET_FANOUT_DATA    22
#define PACKET_MR_MULTICAST   0
#define PACKET_MR_PROMISC     1
#define PACKET_MR_ALLMULTI    2
#define PACKET_MR_UNICAST     3
struct rtentry {
unsigned long int rt_pad1;
struct sockaddr rt_dst;
struct sockaddr rt_gateway;
struct sockaddr rt_genmask;
unsigned short int rt_flags;
short int rt_pad2;
unsigned long int rt_pad3;
unsigned char rt_tos;
unsigned char rt_class;
short int rt_pad4[sizeof(long)/2-1];
short int rt_metric;
char *rt_dev;
unsigned long int rt_mtu;
unsigned long int rt_window;
unsigned short int rt_irtt;
};
#define rt_mss rt_mtu
struct in6_rtmsg {
struct in6_addr rtmsg_dst;
struct in6_addr rtmsg_src;
struct in6_addr rtmsg_gateway;
uint32_t rtmsg_type;
uint16_t rtmsg_dst_len;
uint16_t rtmsg_src_len;
uint32_t rtmsg_metric;
unsigned long int rtmsg_info;
uint32_t rtmsg_flags;
int rtmsg_ifindex;
};
#define	RTF_UP		0x0001
#define	RTF_GATEWAY	0x0002
#define	RTF_HOST	0x0004
#define RTF_REINSTATE	0x0008
#define	RTF_DYNAMIC	0x0010
#define	RTF_MODIFIED	0x0020
#define RTF_MTU		0x0040
#define RTF_MSS		RTF_MTU
#define RTF_WINDOW	0x0080
#define RTF_IRTT	0x0100
#define RTF_REJECT	0x0200
#define	RTF_STATIC	0x0400
#define	RTF_XRESOLVE	0x0800
#define RTF_NOFORWARD   0x1000
#define RTF_THROW	0x2000
#define RTF_NOPMTUDISC  0x4000
#define RTF_DEFAULT	0x00010000
#define RTF_ALLONLINK	0x00020000
#define RTF_ADDRCONF	0x00040000
#define RTF_LINKRT	0x00100000
#define RTF_NONEXTHOP	0x00200000
#define RTF_CACHE	0x01000000
#define RTF_FLOW	0x02000000
#define RTF_POLICY	0x04000000
#define RTCF_VALVE	0x00200000
#define RTCF_MASQ	0x00400000
#define RTCF_NAT	0x00800000
#define RTCF_DOREDIRECT 0x01000000
#define RTCF_LOG	0x02000000
#define RTCF_DIRECTSRC	0x04000000
#define RTF_LOCAL	0x80000000
#define RTF_INTERFACE	0x40000000
#define RTF_MULTICAST	0x20000000
#define RTF_BROADCAST	0x10000000
#define RTF_NAT		0x08000000
#define RTF_ADDRCLASSMASK	0xF8000000
#define RT_ADDRCLASS(flags)	((uint32_t) flags >> 23)
#define RT_TOS(tos)		((tos) & IPTOS_TOS_MASK)
#define RT_LOCALADDR(flags)	((flags & RTF_ADDRCLASSMASK) \
== (RTF_LOCAL|RTF_INTERFACE))
#define RT_CLASS_UNSPEC		0
#define RT_CLASS_DEFAULT	253
#define RT_CLASS_MAIN		254
#define RT_CLASS_LOCAL		255
#define RT_CLASS_MAX		255
#define RTMSG_ACK		NLMSG_ACK
#define RTMSG_OVERRUN		NLMSG_OVERRUN
#define RTMSG_NEWDEVICE		0x11
#define RTMSG_DELDEVICE		0x12
#define RTMSG_NEWROUTE		0x21
#define RTMSG_DELROUTE		0x22
#define RTMSG_NEWRULE		0x31
#define RTMSG_DELRULE		0x32
#define RTMSG_CONTROL		0x40
#define RTMSG_AR_FAILED		0x51
#endif
#endif
#ifdef minilib_include_ret_errno_h
#ifdef mini_errno
#define ret_errno(e) { if ( e>0 ) errno = e; return(-1); }
#else
#define ret_errno(e) { return(-e); }
#endif
#endif
#ifdef minilib_include_select_h
#ifndef select_h
#define select_h
static int volatile __attribute__((optimize("O0"))) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait){
}
#endif
#endif
#ifdef minilib_include_minilib_global_h
#endif
#ifdef minilib_include_pwent_h
#endif
#ifdef minilib_macros_alignment_h
#define __ALIGNSHIFT2 1
#define __ALIGNSHIFT4 2
#define __ALIGNSHIFT8 3
#define __ALIGNSHIFT16 4
#define __ALIGNSHIFT32 5
#define __ALIGNSHIFT64 6
#define __ALIGNSHIFT128 7
#define __ALIGNSHIFT256 8
#define __ALIGN(shift,base,p) p = (typeof(p))(((( (POINTER)p - (POINTER)1 ) >> shift ) << shift ) +base)
#define _ALIGN( base, p ) __ALIGN( base,base,p)
#define _ALIGNBASE( base, p ) __ALIGN( __ALIGNSHIFT##base,base,p)
#define ALIGN_2(p) _ALIGNBASE(2,p)
#define ALIGN_4(p) _ALIGNBASE(4,p)
#define ALIGN_8(p) _ALIGNBASE(8,p)
#define ALIGN_16(p) _ALIGNBASE(16,p)
#define ALIGN_32(p) _ALIGNBASE(32,p)
#define ALIGN_64(p) _ALIGNBASE(64,p)
#define ALIGN_128(p) _ALIGNBASE(128,p)
#define ALIGN_256(p) _ALIGNBASE(256,p)
#define ALIGN_P(p)	_ALIGN( __SIZEOF_POINTER__ ,p)
#endif
#ifdef minilib_include_fexecveat_h
static inline int fexecveat(int fd, char *const argv[], char *const envp[]){
return( execveat(fd,"",argv,envp,AT_EMPTY_PATH) );
}
#endif
#ifdef minilib_include_syscalls_x64_h
#ifndef syscalls_x64_h
#define syscalls_x64_h
#endif
#endif
#ifdef minilib_include_mini_fstream_h
#ifndef inc_mini_fstream_h
#define inc_mini_fstream_h
#ifndef SEEK_SET
#define SEEK_SET        0       
#define SEEK_CUR        1       
#define SEEK_END        2       
#define SEEK_MAX        SEEK_END
#endif
#ifdef mini_buf
#ifndef mini_fstream
#define mini_fstream
#endif
#endif
static inline int __attribute__((always_inline)) fflush( FILE *F ){
return(0);
}
#ifndef mini_fstream
static int fileno( FILE *F ){
if ( F==stdin )
return ( 0 );
if ( F==stdout )
return(1);
if ( F==stderr )
return(2);
exit(-1);
return(-1);
}
#else
int snprintf( char *buf, size_t size, const char *fmt, ... );
static int fileno( FILE *f ){
return( (f==0) ? 0 : (*f & FD_MASK) );
}
#ifdef mini_fclose
static inline int __attribute__((always_inline)) fclose( FILE* f ){
int fd = fileno(f);
*f = -1;
if ( f[1] == mlgl->stream[mlgl->pstream] )
for ( mlgl->pstream--; mlgl->stream[mlgl->pstream-1] == -1; mlgl->pstream-- );
return( close(fd) );
}
#endif
#define printf(...) fprintf(stdout,__VA_ARGS__)
#define fprint(...) fprintf(__VA_ARGS__)
#define vfprintf(...) fprintf(__VA_ARGS__)
static inline size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f){
const void *p = ptr;
int a;
for ( a = 0; a<nmemb; a++ ){
if ( write( fileno(f), p, size ) != size ){
*f = *f | ERR_FLAG;
return(a);
}
p = p + size;
}
return(a);
}
#ifdef mini_lseek
static inline long ftell(FILE *f){
return(lseek( fileno(f), 0, SEEK_CUR ));
}
static inline void fgetpos(FILE *f, long *pos ){
*pos = ftell(f);
}
static inline int fsetpos(FILE *f, int pos ){
int r = lseek( fileno(f), pos, SEEK_SET );
if ( r==pos ){ //
*f = *f & FD_MASK; // unset feof
return(r);
}
return(r); // todo set errno
}
static inline int fseek(FILE *f, long offset, int whence ){
int r = lseek( fileno(f), offset, whence );
if ( r>0 )
*f = *f & FD_MASK; // clear feof
return(r);
}
static inline void rewind( FILE *f ){
fseek(f, 0, SEEK_SET);
}
#endif
#ifdef mini_fread
static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f){
void *p = ptr;
int a;
for ( a = 0; a<nmemb; a++ ){
if ( read( fileno(f), p, size ) != size ){
*f = *f | FEOF_FLAG ; // set feof. Could have also been another error.
return(a);
}
p = p + size;
}
return(a);
}
#endif
static inline int feof(FILE *f){
if ( *f & FLAG_MASK )
return(1);
return(0);
}
static inline int ferror(FILE *f){
if ( *f & FLAG_MASK )
return(1);
return(0);
}
static inline void clearerr(FILE *f){
*f = *f & FD_MASK;
}
static inline void clearerror(FILE *f){
*f = *f & FD_MASK;
}
static void setbuf(FILE *stream, char *buf){
}
static int setvbuf(FILE *stream, char *buf, int mode, size_t size){
return(0);
}
#endif
#endif
#endif
#ifdef minilib_include_fputs_h
#ifndef fputs_h
#define fputs_h
int strlen(const char*str);
static inline int volatile fputs(const char *c, FILE *F){
return(write(fileno(F), c, strlen(c)));
}
#endif
#endif
#ifdef minilib_include_ansicolors_h
#ifdef mini_shortcolornames
#ifndef mini_ansicolors
#define mini_ansicolors
#endif
#endif
#ifdef mini_ansicolors
#define AC_NORM "\033[0;38;40m"
#define AC_BLACK "\033[0;30m"
#define AC_RED "\033[0;31m"
#define AC_GREEN "\033[0;32m"
#define AC_BROWN "\033[0;33m"
#define AC_BLUE "\033[0;34m"
#define AC_MAGENTA "\033[0;35m"
#define AC_MARINE "\033[0;36m"
#define AC_CYAN "\033[0;36m"
#define AC_LGREY "\033[0;37m"
#define AC_WHITE "\033[0;38m"
#define AC_GREY "\033[1;30m"
#define AC_LRED "\033[1;31m"
#define AC_LGREEN "\033[1;32m"
#define AC_YELLOW "\033[1;33m"
#define AC_LBLUE "\033[1;34m"
#define AC_LMAGENTA "\033[1;35m"
#define AC_LMARINE "\033[1;36m"
#define AC_LCYAN "\033[1;36m"
#define AC_LWHITE "\033[1;37m"
#define AC_BGBLACK "\033[40m"
#define AC_BGRED "\033[41m"
#define AC_BGGREEN "\033[32;0m"
#define AC_BGBROWN "\033[43m"
#define AC_BGBLUE "\033[44m"
#define AC_BGMAGENTA "\033[45m"
#define AC_BGMARINE "\033[46m"
#define AC_BGLGREY "\033[47m"
#define AC_BGWHITE "\033[48m"
#define AC_BOLD "\033[1m"
#define AC_FAINT "\033[2m"
#define AC_CURSIVE "\033[3m"
#define AC_UNDERLINE "\033[4m"
#define AC_LIGHTBG "\033[5m"
#define AC_BLINK "\033[6m"
#define AC_INVERTED "\033[7m"
#define AC_INVERSE "\033[8m"
#ifdef mini_shortcolornames
#define NORM     AC_NORM
#define INVERSE  AC_INVERSE
#define BLINK    AC_BLINK
#define BLACK    AC_BLACK
#define RED      AC_RED
#define GREEN    AC_GREEN
#define BROWN    AC_BROWN
#define BLUE     AC_BLUE
#define MAGENTA  AC_MAGENTA
#define MARINE   AC_MARINE
#define CYAN     AC_MARINE
#define LGREY    AC_LGREY
#define WHITE    AC_WHITE
#define GREY     AC_GREY
#define LRED     AC_LRED
#define LGREEN   AC_LGREEN
#define YELLOW   AC_YELLOW
#define LBLUE    AC_LBLUE
#define LMAGENTA AC_LMAGENTA
#define LMARINE  AC_LMARINE
#define LCYAN    AC_LMARINE
#define LWHITE   AC_LWHITE
#define BGBLACK    AC_BGBLACK
#define BGRED      AC_BGRED
#define BGGREEN    AC_BGGREEN
#define BGBROWN    AC_BGBROWN
#define BGBLUE     AC_BGBLUE
#define BGMAGENTA  AC_BGMAGENTA
#define BGMARINE   AC_BGMARINE
#define BGLGREY    AC_BGLGREY
#define BGWHITE    AC_BGWHITE
#endif
#ifdef SHRTSHORTCOLORNAMES
#define cN   AC_NORM
#define cBL  AC_BLACK
#define cR   AC_RED
#define cG   AC_GREEN
#define cBR  AC_BROWN
#define cB   AC_BLUE
#define cMG  AC_MAGENTA
#define cM   AC_MARINE
#define cLG  AC_LGREY
#define cW   AC_WHITE
#define cG   AC_GREY
#define cLR  AC_LRED
#define cLGN AC_LGREEN
#define cY   AC_YELLOW
#define cLB  AC_LBLUE
#define cLMG AC_LMAGENTA
#define cLM  AC_LMARINE
#define cLW  AC_LWHITE
#endif
#endif
#endif
#ifdef minilib_include_fputc_h
#ifndef fputc_c
#define fputc_c
static inline int volatile fputc(int c, FILE* F){
write(fileno(F), &c, 1);
return(c);
}
#endif
#endif
#ifdef minilib_include_errstrshort_h
#ifndef ERRNO_MAX
#define ERRNO_MAX 133
#endif
const char* short_errstr(int num){
const char* unknown = "UNKNOWN";
if ( num > ERRNO_MAX || num < 0 ){
return("UNKNOWN");
}
const char *errstr[] = { "ERRNO=0",
"EPERM",
"ENOENT",
"ESRCH",
"EINTR",
"EIO",
"ENXIO",
"E2BIG",
"ENOEXEC",
"EBADF",
"ECHILD",
"EAGAIN",
"ENOMEM",
"EACCES",
"EFAULT",
"ENOTBLK",
"EBUSY",
"EEXIST",
"EXDEV",
"ENODEV",
"ENOTDIR",
"EISDIR",
"EINVAL",
"ENFILE",
"EMFILE",
"ENOTTY",
"ETXTBSY",
"EFBIG",
"ENOSPC",
"ESPIPE",
"EROFS",
"EMLINK",
"EPIPE",
"EDOM",
"ERANGE",
"EDEADLK",
"ENAMETOOLONG",
"ENOLCK",
"ENOSYS",
"ENOTEMPTY",
"ELOOP",
"EWOULDBLOCK",
"ENOMSG",
"EIDRM",
"ECHRNG",
"EL2NSYNC",
"EL3HLT",
"EL3RST",
"ELNRNG",
"EUNATCH",
"ENOCSI",
"EL2HLT",
"EBADE",
"EBADR",
"EXFULL",
"ENOANO",
"EBADRQC",
"EBADSLT",
"EDEADLOCK",
"EBFONT",
"ENOSTR",
"ENODATA",
"ETIME",
"ENOSR",
"ENONET",
"ENOPKG",
"EREMOTE",
"ENOLINK",
"EADV",
"ESRMNT",
"ECOMM",
"EPROTO",
"EMULTIHOP",
"EDOTDOT",
"EBADMSG",
"EOVERFLOW",
"ENOTUNIQ",
"EBADFD",
"EREMCHG",
"ELIBACC",
"ELIBBAD",
"ELIBSCN",
"ELIBMAX",
"ELIBEXEC",
"EILSEQ",
"ERESTART",
"ESTRPIPE",
"EUSERS",
"ENOTSOCK",
"EDESTADDRREQ",
"EMSGSIZE",
"EPROTOTYPE",
"ENOPROTOOPT",
"EPROTONOSUPPORT",
"ESOCKTNOSUPPORT",
"EOPNOTSUPP",
"EPFNOSUPPORT",
"EAFNOSUPPORT",
"EADDRINUSE",
"EADDRNOTAVAIL",
"ENETDOWN",
"ENETUNREACH",
"ENETRESET",
"ECONNABORTED",
"ECONNRESET",
"ENOBUFS",
"EISCONN",
"ENOTCONN",
"ESHUTDOWN",
"ETOOMANYREFS",
"ETIMEDOUT",
"ECONNREFUSED",
"EHOSTDOWN",
"EHOSTUNREACH",
"EALREADY",
"EINPROGRESS",
"ESTALE",
"EUCLEAN",
"ENOTNAM",
"ENAVAIL",
"EISNAM",
"EREMOTEIO",
"EDQUOT",
"ENOMEDIUM",
"EMEDIUMTYPE",
"ECANCELED",
"ENOKEY",
"EKEYEXPIRED",
"EKEYREVOKED",
"EKEYREJECTED",
"EOWNERDEAD",
"ENOTRECOVERABLE",
"ERFKILL",
"MEMPAGEFAULT",
};
return(errstr[num]);
}
#endif
#ifdef INCLUDESRC
#ifndef included_minilib_c
#ifndef included_minilib_c
#define included_minilib_c
#ifndef included_minilib_h
#endif
#ifndef start_c
#define start_c
#ifndef OSX
#ifdef mini_vsyscalls
int __mini_vsys = 0;
#endif
#ifdef mini_start
#ifdef X64
#ifdef mini_start
void volatile __attribute__((naked,noreturn))_start(){
__asm__ volatile("\
#.global _start\n\
#_start:\n\
xorl %ebp, %ebp\n\
popq %rdi\n\
movq %rsp,%rsi\n\
movq %rdi,%rax\n\
leaq  8(%rsi,%rdi,8),%rdx\n"
#ifdef mini_globals
"call _startup\n"
#else
"call main\n"
#endif
"movq %rax, %rdi\n\
.global __exit\n\
__exit:\n\
movq $60, %rax\n\
syscall\n"
);
__builtin_unreachable();
};
#endif
#else
#ifdef mini_start
void _start(){
__asm__("\
#.global _start\n\
#_start:\n\
pop %eax\n\
leal  12(%esp,%eax,4),%ebx\n"
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
void start(){
__asm__ volatile (
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
#ifdef mini_globals_on_stack
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_errno
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_environ
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_buf
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_globals
#ifndef mini_globals_on_stack
minilib_globals __mlgl;
minilib_globals * __restrict__ mlgl = &__mlgl;
#ifdef mini_errno
int errno;
#endif
#ifdef mini_environ
char **environ;
#endif
#else // globals_on_stack
#endif
#endif //mini_globals
#endif
#ifdef mini_prints
#ifndef mini_dprints_c
#define mini_dprints_c
#ifndef mini_prints
#define mini_prints
#endif
int dprints(int fd, const char *msg,...){
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
#endif
#endif
#ifdef mini_errno
#ifndef mini_globals_on_stack
int errno;
#endif
int sysret;
#endif
#ifdef mini_getopt
#ifndef GETOPT_H
#define GETOPT_H
#ifndef ctype_h
#define ctype_h
#define isalpha(a) (0 ? 1 : (((unsigned)(a)|32)-'a') < 26)
#define isdigit(a) (0 ? 1 : ((unsigned)(a)-'0') < 10)
#define islower(a) (0 ? 1 : ((unsigned)(a)-'a') < 26)
#define isupper(a) (0 ? 1 : ((unsigned)(a)-'A') < 26)
#define isprint(a) (0 ? 1 : ((unsigned)(a)-(0x20)) < 0x5f)
#define isgraph(a) (0 ? 1 : ((unsigned)(a)-0x21) < 0x5e)
#define isspace(a) ((a==' ')||(a=='\t')||(a=='\n')||(a=='\f')||(a=='\r')||(a=='\v'))
#define isalnum(a) (isalpha(a) || isdigit(a))
#define _tolower(a) ((a)|0x20)
#define tolower(a) ((a)|0x20)
#define _toupper(a) ((a)&0x5f)
#define toupper(a) ((a)&0x5f)
#define isascii(a) (0 ? isascii(a) : (unsigned)(a) < 128)
#endif
static int optind = 1;
static int opterr = 1;
static int optopt;
static char *optarg;
static int
getopt(int argc, char * const argv[], const char *optstring)
{
static int optpos = 1;
const char *arg;
(void)argc;
if (optind == 0) {
optind = 1;
optpos = 1;
}
arg = argv[optind];
if (arg && strcmp(arg, "--") == 0) {
optind++;
return -1;
} else if (!arg || arg[0] != '-' || !isalnum(arg[1])) {
return -1;
} else {
const char *opt = strchr(optstring, arg[optpos]);
optopt = arg[optpos];
if (!opt) {
if (opterr && *optstring != ':')
fprintf(stderr, "%s: illegal option: %c\n", argv[0], optopt);
return '?';
} else if (opt[1] == ':') {
if (arg[optpos + 1]) {
optarg = (char *)arg + optpos + 1;
optind++;
optpos = 1;
return optopt;
} else if (argv[optind + 1]) {
optarg = (char *)argv[optind + 1];
optind += 2;
optpos = 1;
return optopt;
} else {
if (opterr && *optstring != ':')
fprintf(stderr,
"%s: option requires an argument: %c\n",
argv[0], optopt);
return *optstring == ':' ? ':' : '?';
}
} else {
if (!arg[++optpos]) {
optind++;
optpos = 1;
}
return optopt;
}
}
}
#endif
#endif
#ifndef mini_startup_c
#define mini_startup_c
#ifdef mini_globals
int main();//int argc, char **argv, char **envp );
int _startup(int argc, char **argv, char **envp ){
#ifdef mini_globals_on_stack
minilib_globals __mlgl;
mlgl=&__mlgl;
#else
#endif
#ifdef mini_buf
mlgl=&__mlgl;
mlgl->mbufsize = mini_buf-4;
int a = 0;
for (; a<3; a++ )
mlgl->stream[a]=a;
mlgl->pstream = a;
#endif
#ifdef mini_errno
errno = 0;
#endif
#ifdef mini_environ
environ = envp;
#endif
#ifdef mini_atexit
mlgl->atexitp[0]=0;
#endif
#ifdef mini_pwent
mlgl->passwdfile.file = 0;
mlgl->pwent.pw_name = 0;
#endif
#ifdef mini_groupfile
mlgl->groupfile.file = 0;
mlgl->grent.gr_name = 0;
#endif
mlgl->brk=0;
mlgl->malloc_start=0;
int ret = main(argc,argv,envp);
#ifdef mini_atexit
#ifdef X64
asm volatile(".global _atexit\n_atexit:":"=D"(ret));
#else
asm volatile(".global _atexit\n_atexit:":"=d"(ret));
#endif
if ( mlgl->atexitp[0] ){
int p;
for ( p=0; mlgl->atexitp[p]!=0 && p<=ATEXIT_MAX; p++ );
while ( p>0 ){
p--;
mlgl->atexitp[p]();
}
}
#endif
_exit(ret);
#ifdef mini_globals
OPTFENCE((void*)mlgl);
#endif
return(ret);
}
#endif
#endif
#ifndef included_minilib_h
#endif
#ifdef mini_prints
#endif
#ifdef mini_errno
#ifndef mini_globals_on_stack
int errno;
#endif
int sysret;
#endif
#ifdef mini_getopt
#endif
#ifdef include_minilib_src_streams_fopen_c
#ifndef inc_mini_fopen_c
#define inc_mini_fopen_c
FILE *fopen(const char* filename, const char* mode){
return(_fopen(0,filename, mode,0));
}
FILE *fdopen(int fd, const char* mode){
return(_fopen(fd,0, mode,0));
}
FILE *freopen(const char* filename, const char* mode, FILE *F){
return(_fopen(0,filename, mode,F));
}
#endif
#endif
#ifdef include_minilib_src_process_wait_c
#ifndef wait_c
#define wait_c
pid_t wait(int *wstatus){
return(wait4(-1,wstatus,0,0));
}
pid_t waitpid(pid_t pid, int *wstatus, int options){
return(wait4(pid,wstatus,options,0));
}
#endif
#endif
#ifdef include_minilib_src_conversions_ltodec_c
#ifndef mini_ltodec_c
#define mini_ltodec_c
int ultodec(unsigned long ui, char *buf, int prec, char limiter ){
long l;
l= (long)1000000000000000000;
int p = 19;
int a = 0;
int c = 0;
if ( ui>=((unsigned long)1000000000000000000*10) ){
a=1;
ui-=((unsigned long)1000000000000000000*10);
*buf='1';
buf++;
c=1;
}  else {
if ( prec >=20 ){
a=1;
*buf='0';
buf++;
c=1;
}
}
while ( p>0 ){
if ( p<=prec )
a=1;
if ( a || ( (long)(ui-l) >= (long)0) ){
a=1;
int b=0;
while ( ui>=l ){
b++;
ui-=l;
}
if ( limiter ){
if ( p%3 == 0 ){
*buf=limiter;
buf++;
c++;
}
}
*buf='0'+b;
buf++;
c++;
}
p--;
l=l/10;
}
*buf=0;
return(c);
}
int ltodec(long i, char *buf, int prec, char limiter ){
if ( i < 0 ){
buf[0]='-';
i = -i;
return(ultodec((unsigned long)i,&buf[1],prec,limiter) + 1 );
}
return(ultodec((unsigned long)i,buf,prec,limiter) );
}
#endif
#endif
#ifdef include_minilib_src_string_strcmp_c
#ifndef mini_strcmp_c
#define mini_strcmp_c
int _strcmp(const char*c1,const char*c2,int len){
int a = 0;
while ( (c1[a] != 0) && (c1[a]==c2[a] ) && a != len ){
a++;
}
if ( c1[a] > c2[a] )
return(1);
if ( c1[a] < c2[a] )
return(-1);
return(0);
}
int _strcasecmp(const char*c1,const char*c2,int len){
int a = 0;
while ( (c1[a] != 0) && (c2[a]!=0 ) && a != len ){
if ( c1[a] != c2[a] ){
if ( tolower( c1[a] ) > tolower( c2[a] ) )
return(1);
if ( tolower( c1[a] ) < tolower( c2[a] ) )
return(-1);
}
a++;
}
if ( (c1[a] == 0 ) && ( c2[a] == 0 ) )
return(0);
return (1);
}
int strcasecmp(const char*c1,const char*c2){
return( _strcasecmp(c1,c2,-1) );
}
int strncasecmp(const char*c1,const char*c2,int len){
if ( len <=0 )
return(-1);
return(_strcasecmp(c1,c2,len) );
}
int strcmp(const char*c1,const char*c2){
return( _strcmp(c1,c2,-1) );
}
int strncmp(const char*c1,const char*c2,int len){
if ( len <=0 )
return(-1);
return(_strcmp(c1,c2,len) );
}
#endif
#endif
#ifdef include_minilib_src_conversions_itohex_c
#ifndef itohex_c
#define itohex_c
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
int itohex(int i,char* buf,int padding){
return(_itohex(i,buf,padding,0));
}
int itoHEX(int i,char* buf,int padding){
return(_itohex(i,buf,padding,1));
}
#endif
#endif
#ifdef include_minilib_src_userdb_userdb_c
#ifndef mini_userdb_c
#define mini_userdb_c
char *token_s( userdb *udb, char **p ){
char *ptmp = *p;
while ( (*p < udb->file+udb->size) &&  **p) {
if ( **p == ':' || **p == '\n' ){
**p = 0;
} else {
(*p)++;
}
};// while (**p);
(*p)++;
return(ptmp);
}
int token_i( userdb* udb, char **p ){
int i = 0;
while ( (*p < udb->file+udb->size) && **p>='0' && **p <= '9' ){
i += i + (i<<3) + (**p-'0');
(*p)++;
}
(*p)++;
return(i);
}
#endif
#endif
#ifdef include_minilib_src_termios_isatty_c
int isatty(int fd){
struct termios term;
return( tcgetattr(fd, &term) == 0 );
}
#endif
#ifdef include_minilib_src_output_sprintf_c
#ifndef msprintf_c
#define msprintf_c
#ifndef mini_write
#define mini_write
#endif
#ifndef mini_prints
#define mini_prints
#endif
#ifndef overrun_h
#define overrun_h
#ifndef mini_prints
#define mini_prints
#endif
#ifndef minilib_exit_h
#define minilib_exit_h
#ifdef mini_atexit
#ifdef X64
#define exit(ret) asm("jmp _atexit"::"D"(ret))
static inline void __attribute__((noreturn))_exit(int ret){
asm("jmp __exit"::"D"(ret));
__builtin_unreachable();
}
#else
#define exit(ret) asm("jmp _atexit"::"b"(ret))
#define _exit(ret) asm("jmp __exit"::"b"(ret))
#endif
#else
#ifdef X64
static inline void __attribute__((noreturn))exit(int ret){
asm("jmp __exit"::"D"(ret));
__builtin_unreachable();
}
static inline void __attribute__((noreturn))_exit(int ret){
asm("jmp __exit"::"D"(ret));
__builtin_unreachable();
}
#else
#define exit(ret) asm("jmp __exit"::"b"(ret))
#define _exit(ret) asm("jmp __exit"::"b"(ret))
#endif
#endif
#endif
#ifndef prints_h
#define prints_h
extern int dprints(int fd, const char *msg,...);
#define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)
#define prints(...) _mprints(__VA_ARGS__,0)
#define eprints(...) dprints(STDERR_FILENO,__VA_ARGS__,0)
#define fprints(F,...) dprints(fileno(F),__VA_ARGS__,0)
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)
#define eprintsl(...) dprints(STDERR_FILENO,__VA_ARGS__,"\n",0)
#endif
#define MINI_TEST_OVERRUN(pos) if (pos > ml.mbufsize){\
printsl("Buffer Overrun. Aborting.");\
exit(1);}
#endif
#undef MINI_TEST_OVERRUN
#define MINI_TEST_OVERRUN(pos) if ( pos>= size ){ overflow=1; goto msprintfout;}
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args ){
int a = 0;
int b = 0;
int overflow = 0;
int end, padding, c,groups=0;
char sep,pad;
char tmp[16];
char *s;
int mod;  // modifier. : 0==int, 1==long
#if 1
while ( fmt[a] != 0){
if ( fmt[a] == '%' ){
end=0;
padding = 0;
sep = 0;
groups=0;
mod = 0;
pad = ' ';
do {
a++;
if ( fmt[a] == '0' ){
a++;
pad = '0';
}
while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
padding*=10;
padding+=fmt[a]-48;
a++;
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
if ( mod == 0 ){
MINI_TEST_OVERRUN(b+13);
b = b + uitodec(va_arg(args,unsigned int),&buf[b],(padding?padding:1),sep,pad);
}
#endif
#ifdef mini_ultodec
if ( mod == 1 ){
MINI_TEST_OVERRUN(b+27);
b = b + ultodec(va_arg(args,long),&buf[b],(padding?padding:1),sep);
}
#endif
end=1;
break;
case 'd':
#ifdef mini_itodec
if ( mod == 0 ){
MINI_TEST_OVERRUN(b+13);
b = b + itodec(va_arg(args,int),&buf[b],padding,sep,pad);
}
#endif
#ifdef mini_ltodec
if ( mod == 1 ){
MINI_TEST_OVERRUN(b+27);
b = b + ltodec(va_arg(args,long),&buf[b],(padding?padding:1),sep);
}
#endif
end=1;
break;
#endif
case 'f':
#ifdef mini_dtodec
MINI_TEST_OVERRUN(b+27);
if ( padding==0 )
padding = 9;
b = b + dtodec(va_arg(args,double),&buf[b],(padding?padding:1));
#endif
end=1;
break;
case 'l':
mod = 1;
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
#ifdef mini_itoHEX
MINI_TEST_OVERRUN(b+8);
b = b + itoHEX(va_arg(args,int),&buf[b],padding);
#endif
end=1;
break;
case 'o':
#ifdef mini_itooct
MINI_TEST_OVERRUN(b+16);
b = b + itooct(va_arg(args,int),&buf[b]);
#endif
end=1;
break;
case 'b':
#ifdef mini_itobin
MINI_TEST_OVERRUN(b+32);
b += itobin(va_arg(args,int),&buf[b],(padding?padding:1),groups);
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
if ( padding ){
int l=strlen(s);
while ( padding > l ){
buf[b] = ' ';
b++;l++;
}
}
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
if ( overflow )
return(-b);
else
return(b);
#endif
}
#endif
#endif
#ifdef include_minilib_src_file_open_c
#ifndef open_c
#define open_c
#ifndef mini_filemodes_h
#define mini_filemodes_h
#ifdef OSX
#define	O_RDONLY	0x0000		
#define	O_WRONLY	0x0001		
#define	O_RDWR		0x0002		
#define	O_ACCMODE	0x0003		
#define	FREAD		0x0001
#define	FWRITE		0x0002
#define	O_NONBLOCK	0x0004		
#define	O_APPEND	0x0008		
#define	O_SHLOCK	0x0010		
#define	O_EXLOCK	0x0020		
#define	O_ASYNC		0x0040		
#define	O_FSYNC		O_SYNC		
#define O_NOFOLLOW  0x0100      
#define	O_CREAT		0x0200		
#define	O_CREATE		0x0200		
#define	O_TRUNC		0x0400		
#define	O_EXCL		0x0800		
#define	O_EVTONLY	0x8000		
#define	O_NOCTTY	0x20000		
#define O_DIRECTORY	0x100000
#define O_SYMLINK	0x200000	
#define	O_CLOEXEC	0x1000000	
#define O_DP_GETRAWENCRYPTED	0x0001
#define O_DP_GETRAWUNENCRYPTED	0x0002
#else
#define O_ACCMODE	00000003
#define O_RDONLY	00000000
#define O_WRONLY	00000001
#define O_RDWR		00000002
#define O_CREAT		00000100	
#define O_EXCL		00000200	
#define O_NOCTTY	00000400	
#define O_TRUNC		00001000	
#define O_APPEND	00002000
#define O_NONBLOCK	00004000
#define O_DSYNC		00010000	
#define FASYNC		00020000	
#define O_ASYNC      020000
#define O_DIRECT	00040000	
#define O_LARGEFILE	00100000
#define O_DIRECTORY	00200000	
#define O_NOFOLLOW	00400000	
#define O_NOATIME	01000000
#define O_CLOEXEC	02000000	
#define O_PATH    010000000
#define O_SYNC     04010000
#define O_RSYNC    04010000
#endif
#endif
#ifndef stdarg_h
#define stdarg_h
#if 1
#if __GNUC__ >= 3
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#else
#ifdef __GNUC__
typedef __builtin_va_list va_list;
#define __VA_ALIGNED_SIZE(x) ((sizeof(x) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, last) ((ap) = (void *)(((char *)&(last)) + __VA_ALIGNED_SIZE(last)))
#define va_end(ap) ((void)0)
#define va_copy(dest, src) ((dest) = (src))
#define va_arg(ap, type) ( ((ap) = (va_list)((char *)(ap) + __VA_ALIGNED_SIZE(type))),	*(type *)(void *)((char *)(ap) - __VA_ALIGNED_SIZE(type)) )
#else
#ifdef __x86_64__
#ifndef _WIN64
typedef void *va_list;
va_list __va_start(void *fp);
void *__va_arg(va_list ap, int arg_type, int size);
va_list __va_copy(va_list src);
void __va_end(va_list ap);
#define va_start(ap, last) ((ap) = __va_start(__builtin_frame_address(0)))
#define va_arg(ap, type) (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type))))
#define va_copy(dest, src) ((dest) = __va_copy(src))
#define va_end(ap) __va_end(ap)
#else 
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+7)&~7)
#define va_arg(ap,type) (ap += (sizeof(type)+7)&~7, *(type *)(ap - ((sizeof(type)+7)&~7)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif
#else 
typedef char *va_list;
#define va_start(ap,last) ap = ((char *)&(last)) + ((sizeof(last)+3)&~3)
#define va_arg(ap,type) (ap += (sizeof(type)+3)&~3, *(type *)(ap - ((sizeof(type)+3)&~3)))
#define va_copy(dest, src) (dest) = (src)
#define va_end(ap)
#endif
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED
#endif
#endif
#endif
#endif
int volatile open( const char *s, int flags, ... ){
int ret;
va_list args;
va_start(args,flags);
int mode = va_arg(args,int);
va_end(args);
syscall3(ret,SCALL(open),(POINTER)s,flags,mode);
#ifdef mini_errno
if ( ret<0 )
errno = -ret;
#endif
return(ret);
}
int volatile creat( const char *s, int mode ){
return(open( s, O_CREAT|O_WRONLY|O_TRUNC, mode) );
}
#endif
#endif
#ifdef include_minilib_src_process_sleep_c
#ifndef mini_sleep_c
#define mini_sleep_c
unsigned int volatile sleep(unsigned int seconds){
unsigned int res;
struct timespec ts = { .tv_sec = (long int) seconds, .tv_nsec = 0 };
res = nanosleep(&ts, &ts);
if (res) res = (unsigned int) ts.tv_sec + (ts.tv_nsec >= 500000000L);
return res;
}
unsigned int volatile usleep(unsigned int useconds){
struct timespec ts;
ts.tv_nsec = (long)((long)useconds*1000 % 1000000000 );// & (long)0xFFFFFFFF;
ts.tv_sec = 0;
if( useconds >= 1000000 )
ts.tv_sec = ((long)useconds/1000000);
return( nanosleep(&ts, &ts) );
}
#endif
#endif
#ifdef include_minilib_src_memory_malloc_c
#ifndef mini_malloc_c
#define mini_malloc_c
#ifdef __NR_brk
#define BRK
#else
#ifdef SYS_brk
#define BRK
#endif
#endif
#ifndef minilib_global_h
#define minilib_global_h
#ifdef mini_globals_on_stack
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_errno
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_environ
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifndef mini_pwent
#ifdef mini_getpwent
#define mini_pwent
#endif
#ifdef mini_getpwuid
#define mini_pwent
#endif
#ifdef mini_getpwnam
#define mini_pwent
#endif
#ifdef mini_setpwent
#define mini_pwent
#endif
#endif
#ifndef mini_grent
#ifdef mini_getgrent
#define mini_grent
#endif
#ifdef mini_getgrnam
#define mini_grent
#endif
#ifdef mini_getgroups
#define mini_grent
#endif
#ifdef mini_getgrgid
#define mini_grent
#endif
#endif
#ifdef mini_buf
#if mini_buf > 0
#else
#warning mini_buf defaults to 2048 Bytes
#define mini_buf 2048
#endif
#endif
#ifdef mini_buf
#define mini_bufsize mini_buf
#ifndef mini_globals
#define mini_globals
#endif
#else
#define mini_bufsize 0
#endif
typedef struct {
int errno;
int sysret;
int srand;
int pstream;
int mbufsize;
int align[1];
char **environ;
unsigned long brk;
unsigned long malloc_start;
#ifdef mini_atexit
functionp* atexitp[ATEXIT_MAX];
#endif
void *appdata; // can be used freely.
int stream[mini_FOPEN_MAX];
#ifdef mini_pwent
userdb passwdfile;
struct passwd pwent; // quite some overhead. But needed for threadsafety.
#endif
#ifdef mini_grent
userdb groupfile;
struct group groupent;
#endif
#ifdef mini_inet_ntoa
char inet_ntoa_addr[16];
#endif
union {
int ibuf[(mini_bufsize>>2)];
char mbuf[mini_bufsize];
};
} minilib_globals;
static void __attribute__((noipa,cold)) optimization_fence(void*p){}
#ifdef mini_globals_on_stack
#ifndef mini_globals
#define mini_globals
#endif
#endif
#ifdef mini_globals
#ifndef mini_globals_on_stack
extern minilib_globals*__restrict__ mlgl;
extern minilib_globals __mlgl;
#ifdef mini_errno
extern int errno;
#endif
#ifdef mini_environ
extern char **environ;
#endif
#else //mini_globals_on_stack
register minilib_globals __attribute__((used))*__restrict__ mlgl asm("r15");
#define errno mlgl->errno
#ifdef mini_environ
#define environ mlgl->environ
#endif
#endif //mini_globals_on_stack
#else
#endif
#endif
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
static int brk( const void* addr );
static void* sbrk( long incr );
static long getbrk();
#define MBUF_FREE 0x80000000
#define MALLOC_FREE MBUF_FREE
#define MBUF_FREEMASK 0x8FFFFFFF
#define MBUF_OCC 0x40000000
#define MALLOC_BRK_END MBUF_OCC
#define MBUF_CHK 0xC0000000
#define MBUF_PREVISFREE 0x20000000
#define MALLOC_PREVISFREE MBUF_PREVISFREE
#define MALLOC_BRK 0x10000000
#define MBUF_V 0xFFFFFFF
#define MALLOC_SIZE MBUF_V
void* malloc(int size){
#ifndef mini_buf
#error malloc needs a defined mini_buf
#endif
size = ((size-1) >> 2 ) + 2; // alignment and reserving space for the "pointer",
if( mlgl->mbufsize-(size<<2)<64 ){
write( STDERR_FILENO, "Out of memory.\n",15 );
return((void*)0);
}
mlgl->ibuf[(mlgl->mbufsize>>2)] = mlgl->ibuf[(mlgl->mbufsize>>2)] & MBUF_V; // clear flag prev_isfree
mlgl->mbufsize -= (size<<2);
mlgl->ibuf[(mlgl->mbufsize>>2)] = size;
return( &mlgl->mbuf[mlgl->mbufsize+4] );
}
void free(void *p){
if ( p == 0 )
return;
char *c = p;
int *i = p;
i--; // point to the size of the block
c-=4;
#ifdef mini_malloc_brk
if ( i[0] & MALLOC_BRK ){
if ( (long)(p+(i[0]&MALLOC_SIZE)) >= getbrk()  ){ // at the end of the data segment
brk(i);
} else {
i[0]=(i[0]|MALLOC_FREE);
}
return;
}
#endif
if ( &mlgl->mbuf[mlgl->mbufsize] == (char*)c ){ // at the bottom of the stack
mlgl->mbufsize += (i[0] & MBUF_V) <<2;
if ( mlgl->mbufsize == mini_buf )
return;
if ( mlgl->ibuf[mlgl->mbufsize>>2] & MBUF_FREE )
mlgl->mbufsize += ( ( mlgl->ibuf[mlgl->mbufsize>>2] & MBUF_V ) << 2 );
return;
} else { // Not at the bottom
if ( ( i[0] & MBUF_PREVISFREE )){ // prev area is free
i[ - i[-1] -1 ] = ( ( i[ - i[-1] -1 ] + i[0] ) & MBUF_V ) | MBUF_FREE; // add this to prev.
i = i - ( i[-1] + 1 );
}
if ( (i[( i[0] & MBUF_V)] & MBUF_FREE) ){ // next area free
i[0] = ((i[0] + i[( i[0] & MBUF_V)]) & MBUF_V) | MBUF_FREE; // add next to current.
i[( i[0] & MBUF_V) - 1 ] = ( i[0] & MBUF_V) - 1;
return;
} // prev area not free, next area not free
i[( i[0] & MBUF_V) - 1 ] = ( i[0] & MBUF_V) - 1;
i[( i[0] & MBUF_V)] = ( i[( i[0] & MBUF_V)] | MBUF_PREVISFREE );
i[0] = i[0] | MBUF_FREE;
return;
}
}
void* realloc(void *p, int size){
if ( size == 0 ){
free(p);
return((void*)0);
}
if ( p == 0 ){
return(malloc(size)); // just alloc
}
char *c = p;
int *i = p;
i--;
c-=4;
int oldsize = (i[0] & MBUF_V); //<<2;
size = (((size-1) >> 2 ) + 2)<<2; // alignment and reserving space for the "pointer"(int)
if ( oldsize == size )
return( p );
#ifdef mini_malloc_brk
if ( *i & MALLOC_BRK ){ // has been allocated with malloc_brk
if ( (long)(p+oldsize) >= getbrk()  ){ // at the end of the data segment
int ret = brk(c+size);
if ( ret != 0 ){
return(0);
}
*i = MALLOC_BRK | (size);
return(p);
}
}
#endif
if ( size < oldsize ){ // shrink. But can't free. so do nothing.
return(p);
} // if shrink.
if( mlgl->mbufsize-(size)+(oldsize<<2)<64 ){
write( STDERR_FILENO, "Out of memory.\n",15 );
free(p);
return((void*)0);
}
free(p);
int *s = (int*)p;
void *n = malloc(size);
if ( p > n ){
for ( int *d = (int*)n; d<=(int*)((void*)n+(oldsize<<2)); d++ ){
*d = *s;
s++;
}
} else { // p<n
int *s = (int*)n;
for ( int *d = (int*)p; d<=(int*)((void*)p+(oldsize<<2)); d++ ){
*d = *s;
s++;
}
}
return( n );
}
#endif
#endif
#ifdef include_minilib_src_process_sigaction_c
#ifndef mini_sigaction_c
#define mini_sigaction_c
static int sigemptyset(sigset_t *set){
#ifdef X64
set->sig=0;
#else
set->sig[0]=0;
if ((8/sizeof(long)) > 1)
set->sig[1]=0;
#endif
return 0;
}
#if 1
static int sigfillset(sigset_t *set){
#ifdef X64
set->sig=0x7FFFFFFF; // doesn't work. ?
#else
#error implemented only for X64
#endif
return 0;
}
#endif
int sigaddset(sigset_t *set, int sig){
unsigned s = sig-1;
if (sig >= _NSIG-1 || sig <0 ) {
#ifdef mini_errno
errno = EINVAL;
#endif
return -1;
}
#ifdef X64
set->sig |= (1<<s);
#else
#error implemented only for X64
#endif
return(0);
}
#ifdef mini_sigsuspend
static int sigsuspend( const sigset_t *mask ){
return( rt_sigsuspend( mask, sizeof(sigset_t) ) );
}
#endif
#ifdef mini_sigprocmask
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset){
return( rt_sigprocmask( how, (sigset_t*)set, oldset, sizeof(sigset_t) ) );
}
#endif
int sigdelset(sigset_t *set, int sig){
unsigned s = sig-1;
if (sig >= _NSIG-1 || sig <0 ) {
#ifdef mini_errno
errno = EINVAL;
#endif
return -1;
}
#ifdef X64
set->sig &= ~(1<<s);
#else
#error implemented only for X64
#endif
return(0);
}
int sigismember(sigset_t *set, int sig){
unsigned s = sig-1;
if (sig >= _NSIG-1 || sig <0 ) {
#ifdef mini_errno
errno = EINVAL;
#endif
return -1;
}
#ifdef X64
return( set->sig & (1<<s) );
#else
#error implemented only for X64
return(-1);
#endif
}
#ifdef mini_sigaction
extern void _sigrestore();
__asm__ ( "\
.global _sigrestore\n\
_sigrestore:\n\
mov $15,%rax\n\
syscall");
static int volatile sigaction(int sig, const struct sigaction *act, struct sigaction *oact){
struct sigaction sa;
#ifdef X64
sa.sa_mask.sig=act->sa_mask.sig;
#else
sa.sa_mask.sig[0]=act->sa_mask.sig[0];
if ((8/sizeof(long)) > 1)
sa.sa_mask.sig[1]=act->sa_mask.sig[1];
#endif
sa.sa_handler=act->sa_handler;
sa.sa_flags = act->sa_flags | SA_RESTORER;
sa.restorer = &_sigrestore;
return( rt_sigaction( sig, &sa, oact, sizeof(sigset_t) ) );
}
#endif
#ifdef mini_raise
static inline int raise(int signr){
return(kill(getpid(),signr));
}
#endif
#endif
#endif
#ifdef mini_dtodec
int dtodec(double d, char* buf, int precision){
int i = (int) d;
unsigned int i2;
if ( d >= 0 )
i2 = (unsigned int)((d-i)*1000000000+0.1);
else
i2 = (unsigned int)((double)(-d+i)*1000000000+0.1);
int p;
if ( (d<=-1) || (d>0) )
p = itodec(i,buf,0,0,0);
else {
buf[0] = '-';
buf[1] = '0';
p = 1;
}
buf[p+1]='.';
int p2 = uitodec(i2,&buf[p+2],9,0,0);
return(p+p2+2-9+precision);
}
#endif
#ifdef mini_unmap_protected
void* map_protected(int len){
len=len+(PAGESIZE-len%PAGESIZE) + 2*PAGESIZE;
void *p = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE,-1,0 );
if ( p<=0 )
return(p);
mprotect(p,1,PROT_NONE);
mprotect(p+len-PAGESIZE,1,PROT_NONE);
return( p+PAGESIZE );
}
int unmap_protected(void *p, int len){
len=len+(PAGESIZE-len%PAGESIZE);
int ret = munmap((long)p-PAGESIZE,len+2*PAGESIZE);
return(ret);
}
#endif
#ifdef mini_djb_cksum
unsigned int djb_cksum( const char* p, unsigned int len ){
unsigned int hash = 5381;
while ( len-->0 ){
hash = ((hash<<5)+hash) + *p;
p++;
}
return( hash );
}
unsigned int bsd_cksumblock( unsigned int hash, const char* p, unsigned int len ){
while (len-->0 ){
hash = (hash>>1) + ((hash & 1)<<15);
hash+= *p;
hash &= 0xffff;
p++;
}
return( hash );
}
unsigned int bsd_cksum( const char* p, unsigned int len ){
return( bsd_cksumblock(0,p,len) );
}
#endif
#ifdef mini_ungetc
static int ungetc(int c, FILE *F){
*F = (*F & ~UNGETC_MASK) | (c<<24);
return(c);
}
#endif
#ifdef mini_vsprintf
int vsprintf( char *buf, const char *fmt, ... ){
va_list args;
va_start(args,fmt);
int r = vsnprintf(buf, 4096, fmt, args);
va_end(args);
return(r);
}
#endif
#ifdef mini_ntohs
#ifndef mini_byteorder_h
#define mini_byteorder_h
static uint16_t htons(uint16_t i){
union { uint16_t i; char c[2]; } u = { .i=i };
u.c[0] ^= u.c[1];
u.c[1] ^= u.c[0];
u.c[0] ^= u.c[1];
return( u.i );
}
static uint32_t htonl(uint32_t i){
union { uint32_t i; char c[4]; } u = { .i=i };
u.c[0] ^= u.c[3];
u.c[1] ^= u.c[2];
u.c[3] ^= u.c[0];
u.c[2] ^= u.c[1];
u.c[0] ^= u.c[3];
u.c[1] ^= u.c[2];
return( u.i );
}
#endif
#endif
#ifdef mini_ioctl
#ifndef mini_ioctl_h
#define mini_ioctl_h
int volatile  __attribute__((optimize("O0"))) ioctl( int fd, unsigned long int request, ... ){
va_list args;
va_start(args,request);
int ret;
syscall3(ret, SCALL(ioctl),fd,request,(long int)va_arg(args,void*));
OPTFENCE(&ret,&fd,&request,(void*)args);
va_end(args);
return(ret);
}
#endif
#endif
#ifdef mini_getgrent
struct group* getgrent(){
if ( !mlgl->groupfile.file ){
if ( !userdb_open(&mlgl->groupfile,GROUPFILE) )
return(0);
}
if ( mlgl->groupfile.p >= (mlgl->groupfile.file+mlgl->groupfile.size) )
return(0);
char *p = token_s( &mlgl->groupfile,&mlgl->groupfile.p);
if ( *p == 0 )
return(0); //error or end.
mlgl->groupent.gr_name = p;
mlgl->groupent.gr_passwd = token_s( &mlgl->groupfile,&mlgl->groupfile.p);
mlgl->groupent.gr_gid = token_i( &mlgl->groupfile,&mlgl->groupfile.p);
int count = 0;
if ( *mlgl->groupfile.p2 == 0 ){
char* members =  token_s( &mlgl->groupfile,&mlgl->groupfile.p);
char *mbr = members;
while ( members < mlgl->groupfile.p ){
if ( *members == ',' ){
*members = 0;
}
if ( *members == 0 ){
mlgl->groupent.gr_mem[count] = mbr; // 0, when no members.
mbr=(members+1);
count++;
if ( count >= MAX_GROUPMEMBERS ){
ewrites("Error: too many groupmembers.\n");
return(0);
}
}
members++;
}
*mlgl->groupfile.p2 = mlgl->groupfile.p;
*mlgl->groupfile.p2++;
} else {
do {
mlgl->groupent.gr_mem[count] = token_s( &mlgl->groupfile,&mlgl->groupfile.p);
count++;
if ( count >= MAX_GROUPMEMBERS ){
ewrites("Error: too many groupmembers. 2\n");
return(0);
}
} while ( mlgl->groupfile.p < *mlgl->groupfile.p2 );
*mlgl->groupfile.p2++;
}
mlgl->groupent.gr_mem[count] = 0;
return(&mlgl->groupent);
}
#endif
#ifdef mini_errx
#ifndef mini_error_c
#define mini_error_c
#define error( status, errnum, fmt ... ) { fprintf(stderr,fmt ); if (errnum) fprints(stderr,":",strerror(errnum)); if ( status ) exit(status); }
#define err( status, fmt ... ) { fprintf(stderr,fmt ); fprints(stderr,":",strerror(errno)); exit(status); }
#define errx( status, fmt ... ) { fprintf(stderr,fmt); exit(status); }
#define warn( fmt ... ) { fprintf(stderr,fmt ); }
#endif
#endif
#ifdef mini_htons
#endif
#ifdef mini_execvp
static inline int execvp(const char *file, char *const argv[]){
return( execvpe( file, argv, environ ) );
};
#endif
#ifdef mini_memset
void *memset( void *s, int c, int n){
int a;
char *sp = s;
for ( a=0; a<n; a++)
sp[a] = (char)c;
return(s);
}
#endif
#ifdef mini_match
#ifndef mini_match_c
#define mini_match_c
int match(char *text, const char *re, text_match *st_match){
int r = 1;
if ( ( *re == '*' && *(re+1)=='@' && ( r=2 ) ) ||
( *re=='@' ) ){ // beginning of text or line, here of the text
if ( _match( text, (re+r), st_match ) == RE_MATCH )
return( RE_MATCH );
}
return( _match( text, re, st_match ) );
}
int _match(char *text, const char *re, text_match *st_match){
int n_match=0;
char *matchpos = 0;
int neg = 0;
if ( st_match ) st_match->len=0;
while ( *text!=0 ){
int match_char = 0;
neg = 0;
if ( *re == '!' ){
re++;
neg=1;
}
switch ( *re ){
case '?':
if ( neg )
return(RE_NOMATCH);
break; // matches, but only if there's a char (not 0)
case '[':
for ( re++; *re && *re!=*text; re++ )
if ( *re==']' )
return(neg ^ RE_NOMATCH);
while ( *re && *re != ']' )
re++;
if ( !*re )
return( RE_ERROR );
if ( neg )
return( RE_NOMATCH );
break;
case '#': // match end of text, or space chars; here a space
if ( isspace( *text )){
if ( neg ) return( RE_NOMATCH );
break;
}
if ( neg ) break;
return( RE_NOMATCH );
case '@': // match beginning of text or endofline - here endofline
if ( *text == '\n' ){
if ( neg ) return( RE_NOMATCH );
break;
}
if ( neg ) break;
return( RE_NOMATCH );
case '%':
matchpos=text;
case '+': // match one or more chars
text++;
if ( !*text ) return(neg ^ RE_NOMATCH);//
case '*': // match 0 or more chars
re++;
if ( *re == 0){ // match. end of regex.
if ( matchpos && ( st_match ) ){
while ( *text )	// find end of text
text++;
if ( st_match ){
st_match->pos = matchpos;
st_match->len = text-matchpos;
}
}
return(neg ^ RE_MATCH); // no chars anymore. so a match
}
while ( !_match(text,re,st_match) ){
text++;
if ( !*text ){
if ( (*re == '#' || *re == '$') && ( re[1]==0 ) )
goto __MATCHEND2;
return(neg ^ RE_NOMATCH);
}
}
__MATCHEND2:
if ( matchpos ){
if ( st_match ){
st_match->pos = matchpos;
st_match->len = text-matchpos;
}
}
return(neg ^ RE_MATCH);
case '\\': // match escaped *,?,backslashes, %
re++;
default:
if ( *re==0 ) //partial match ( could be spared )
return(RE_NOMATCH);
if ( neg ^ (*re!=*text) ){
return(RE_NOMATCH);
}
}
re++; text++;
}
if ( ( *re=='#' ) || ( *re=='$') ){ // match end of text
re++;
}
if ( *re==0 || ( *re=='*' && re[1]==0 ) ){
return(RE_MATCH); //matched
}
return(RE_NOMATCH);
}
#endif
#endif
#ifdef mini_scandir_bufsize
int scandir(const char *path, struct dirent **listing[], int (*fp_select)(const struct dirent *),	int (*cmp)(const struct dirent **, const struct dirent **)){
#ifndef mini_scandir_bufsize
#define _BUFSIZE 4096
#else
#define _BUFSIZE mini_scandir_bufsize
#endif
struct dirent **names=0, **tmp;
int cnt=0, len=0;
int fd;
if ((fd = open(path, O_RDONLY|O_DIRECTORY|O_CLOEXEC)) < 0){
seterrno(fd);
return(fd);
}
char *buf;
buf= malloc_brk(_BUFSIZE);
if ( buf==0 ){
seterrno(ENOMEM);
return(-ENOMEM);
}
int pos = 0;
int cp = 0;
int oldcp = 0;
int bufpos=0;
int oldpos=0;
while ( (len = getdents( fd, (struct dirent*) (buf+bufpos), _BUFSIZE) )>0){
while ( pos < len + bufpos ){
struct dirent *de = (void *)(buf+pos);
pos+=de->d_reclen;
if ( !(fp_select && !(fp_select(de))) ){ // selected
cnt++;
cp += de->d_reclen;
}
if ( oldcp < oldpos ){
memcpy(buf+oldcp,buf+oldpos,de->d_reclen);
}
oldcp=cp;
oldpos=pos;
}
bufpos=pos;
buf=realloc(buf,bufpos+_BUFSIZE);
if ( !buf) {
seterrno(ENOMEM);
close(fd);
return(-ENOMEM);
break;
}
}
if ( len<0 ){
close(fd);
seterrno(len);
return(len);
}
close(fd);
if ( cnt*sizeof(POINTER) > _BUFSIZE+(pos-cp) ){
realloc(buf,cp+(cnt*sizeof(POINTER)));
if ( !buf ){
seterrno(ENOMEM);
return(-ENOMEM);
}
}
struct dirent *de;
de = (void*)buf;
struct dirent **list;
list= (void*)(buf+cp);
for(int a=0;a<cnt;a++){
*list = de;
*list++;
de=(void*)de+de->d_reclen;
}
list = (void*)(buf+cp);
*listing = (void*)(buf+cp);
if (cmp){
qsort(*listing,cnt,sizeof(struct dirent*),(int (*)(const void*,const void *))cmp);
}
return(cnt);
}
#endif
#ifdef mini_strtol
long int strtol(const char *c, const char **endp, int base){
while(isspace(*c)){
c++;
};
if ( !c ){
goto strtol_err;
}
int sign = 0;
if ( *c=='-' ){
sign = 1;
c++;
}
if ( base == 0 ){
if ( *c=='0' ){
c++;
if ( *c== 'x' ){
c++;
base=16;
} else {
base=8;
}
} else {
base=10;
}
}
long ret = 0;
while ( 1 ){
if ( endp )
*endp=c;
int add = -1;
if ( *c>='0' && *c<='9' )
add = (*c-48);
if ( *c>= 'A' && *c<= 'Z' )
add = (*c-'A'+10);
if ( *c>= 'a' && *c<= 'z' )
add = (*c-'a'+10);
if ( add > base || add == -1 )
return( sign?-ret:ret );
c++;
ret *= base;
ret += add;
}
strtol_err:
#ifdef mini_errno
errno=EINVAL;
#endif
if ( endp ){
*endp = 0;
}
return(0);
}
#endif
#ifdef mini_rand
#ifndef rand_c
#define rand_c
void srand( unsigned int i ){
mlgl->srand = i;
}
unsigned int rand(){
if ( mlgl->srand==0 ){
mlgl->srand=1;
}
mlgl->srand ^= mlgl->srand << 13;
mlgl->srand ^= mlgl->srand >> 17;
mlgl->srand ^= mlgl->srand << 5;
unsigned int t = mlgl->srand;
mlgl->srand ^= mlgl->srand << 13;
mlgl->srand ^= mlgl->srand >> 17;
mlgl->srand ^= mlgl->srand << 5;
return(t-1);
}
#endif
#endif
#ifdef mini_getgroups
int getgroups(int maxgroups, int *list){
int uid = getuid();
struct passwd* user = getpwuid(uid);
if ( !user )
return(-1);
return(getusergroups(user->pw_name,maxgroups,list));
}
#endif
#ifdef mini_strlen
int strlen(const char*str){
int a = 0;
while ( str[a] != 0 ){
a++;
}
return (a);
}
#endif
#ifdef mini_map_protected
#endif
#ifdef mini_swap
#ifndef mini_qsort_c
#define mini_qsort_c
static inline void swap(void* a, void* b,int size){
if ( size==sizeof(int) ){
asm ("xor %0,%1\nxor %1,%0\nxor %0,%1"
:"+r"(*(int*)a),"+g"(*(int*)b) );
return;
}
if ( size==sizeof(long) ){
asm ("xor %0,%1\nxor %1,%0\nxor %0,%1"
:"+r"(*(long*)a),"+g"(*(long*)b) );
return;
}
for ( int n=size;n--;){
asm ("xor %0,%1\nxor %1,%0\nxor %0,%1"
:"+r"(*(char*)a),"+g"(*(char*)b) );
a++;b++;
}
}
void qsort(void  *base,	size_t nel,	size_t width,	int (*comp)(const void *, const void *)){
size_t wnel, gap, wgap, i, j, k;
char *a, *b, tmp;
wnel = width * nel;
for (gap = 0; ++gap < nel;)
gap *= 3;
while ((gap /= 3) != 0) {
wgap = width * gap;
for (i = wgap; i < wnel; i += width) {
for (j = i - wgap; ;j -= wgap) {
a = j + (char *)base;
b = a + wgap;
if ((*comp)(a, b) <= 0)
break;
swap(a,b,width);
if (j < wgap)
break;
}
}
}
}
#endif
#endif
#ifdef mini_free_brk
int free_brk(){
if ( mlgl->malloc_start && getbrk() > mlgl->malloc_start ){
return(brk((void*)mlgl->malloc_start));
}
return(1);
}
#endif
#ifdef mini_getgrouplist
int getgrouplist(const char* user, gid_t group, gid_t *groups, int *ngroups){
int gr = getusergroups(user,*ngroups,groups);
for ( int a = 0; a<gr; a++ ){
if ( group == groups[a] )
return(gr); // group already within the list
}
if ( gr>=*ngroups-1 )
return(-1);
groups[gr] = group; // append group
return(gr+1);
}
#endif
#ifdef mini_vexec
int vexec( const char* path, char* const* argv, char* const* envp ){
int pid = vfork();
if ( pid == 0 ){
int ret = execve(path, argv, envp );
seterrno(ret);
exit(ret); // exit with failure
}
int ws;
int wpid;
do {
wpid = waitpid( pid, &ws, 0 ); // wait for any child (reap zombies)
} while ( !( (wpid == pid) && (WIFEXITED(ws) || WIFSIGNALED(ws) )));
return(WEXITSTATUS(ws));
}
int vexec_q( const char* path, char* const* argv, char* const* envp ){
int pid = vfork();
if ( pid == 0 ){
close(1);
int ret = execve(path, argv, envp );
seterrno(ret);
exit(ret); // exit with failure
}
int ws;
int wpid;
do {
wpid = waitpid( pid, &ws, 0 ); // wait for any child (reap zombies)
} while ( !( (wpid == pid) && (WIFEXITED(ws) || WIFSIGNALED(ws) )));
return(WEXITSTATUS(ws));
}
#endif
#ifdef mini_strchr
#ifndef strchr_c
#define strchr_c
char *strchrnul(const char *s, int c){
while ( *s != 0 ){
if ( *s==c ){
return((char*)s);
}
s++;
}
return((char*)s);
}
char *strchr(const char *s, int c){
char *ret = strchrnul(s,c);
if ( c==0 )
return(ret);
if ( *ret==0 )
return(0);
return(ret);
}
char *strrchr(const char *s, int c){
char *ret = 0;
char *tmp = (char*)s-1;
while ( (tmp = strchrnul(tmp+1,c) ) && ( *tmp != 0 ) ){
ret=tmp;
}
return(ret);
}
#endif
#endif
#ifdef mini_getenv
char* getenv(const char* name){
int b;
for ( int a=0; environ[a]; a++ ){
for ( b = 0; environ[a][b] == name[b]; b++ ){}
if ( ( environ[a][b] == '=' ) && (name[b]==0) ){
return( &environ[a][b+1] );
}
}
return(0);
}
#endif
#ifdef mini_memfrob
void* memfrob(void* s, unsigned int len){
while (len-->0)
*s^=42;
return(s);
}
#endif
#ifdef mini_match_ext2
#ifndef mini_match_ext2_c
#define mini_match_ext2_c
int match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char),text_match *st_match){
int r = 1;
char *ret = 0;
if ( ( *re == '*' && *(re+1)=='@' && ( r=2 ) ) ||
( *re=='@' ) ){ // beginning of text or line, here of the text
if ( _match_ext2( text, (re+r), p_matched_cb, p_wildcard_cb, st_match ) > (long)0 )
return( RE_MATCH );
}
if ( (ret = _match_ext2( text, re, p_matched_cb, p_wildcard_cb, st_match )) > 0 )
return( RE_MATCH );
return ( (int)(long)ret ); // needs a double cast to prevent compiler warnings
}
char* _match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char), text_match *st_match){
int n_match=0;
char *matchpos = 0;
int neg = 0;
char *rematch = (char*)RE_MATCH;
#define REMATCH text
if ( st_match )
st_match->len=0;
char *matchstarpos = 0; // set up a loop for a star, instead of recursion.
while ( *text!=0 ){
int match_char = 0;
neg = 0;
int count = 1;
switch (*re){
case '!':
neg=1;
case ',': // separate e.g. %,1
re++;
}
if ( *re == ')' ){
re++;
if ( ( _match_ext2(text,re,p_matched_cb,p_wildcard_cb,st_match ) ) <=0 )
return( RE_NOMATCH );
return( text );
}
if ( *re == '}' ){
writesl("  == closing }");
return( text ); // match
}
if ( *re == '{' ){
re++;
char *ret = text;
char *r2;
int c = 0;
switch ( *re ){
case '+':
re++;
if ( (ret = _match_ext2(text,re,
p_matched_cb,p_wildcard_cb,st_match ) ) <=0 )
return(RE_NOMATCH);
c = -1;
break;
case '*':
c = -1;
re++;
break;
default:
while ( isdigit(*re) ){
c += (c*10) + (*re-'0');
re++;
}
}
r2 = ret;
while ( c!=0  && ((r2=_match_ext2(ret,re,
p_matched_cb,p_wildcard_cb,st_match ) ) >0 ) ){
write(1,r2,10);
write(1,"\n",1);
write(1,re,4);
ret=r2;
c--;
printf(" -- while, c: %d\n",c);
}
if ( c > 0 )
return(RE_NOMATCH);
for ( ;*re != '}'; re++ )
if ( !*re )
return( RE_ERROR ); // bracket error
re++;
return(_match_ext2(ret,re,p_matched_cb,p_wildcard_cb,st_match ));
}
char *pos = re;
while ( count --> 0 ){
re=pos;
switch ( *re ){
case '?':
if ( neg )
return(RE_NOMATCH); // !? breaks down to $
break; // matches, but only if there's a char (not 0)
case '@': // match beginning of text or endofline - here endofline
if ( *text == '\n' ){
if ( neg ) return( RE_NOMATCH );
break;
}
if ( neg ) break;
return( RE_NOMATCH );
case '[':
for ( re++; *re && *re!=*text; re++ )
if ( *re==']' )
return(neg?REMATCH:RE_NOMATCH);
while ( *re && *re != ']' )
re++;
if ( !*re )
return( RE_ERROR );
if ( neg )
return( RE_NOMATCH );
break;
case '(':
re++;
char *bpos = re;
char *mpos = text;
while ( *re && *re!=')' )
re++;
if ( !*re )
return(RE_ERROR);
text=_match_ext2(text,bpos,p_matched_cb,p_wildcard_cb,st_match);
if ( text<=(long)0 )
return(RE_NOMATCH);
printf("bracket match: %lx - %lx - rematch: %lx\n",mpos,text,rematch);
write(1,mpos,text-mpos);
writesl("\n==========");
if ( ! count ){
writesl("retc");
return(text); // MATCH
}
break;
case '#': // match end of text, space, linebreak, tab;
if ( isspace( *text )){
if ( neg ) return( RE_NOMATCH );
break;
}
if ( neg ) break;
return( RE_NOMATCH );
case '$': // match end of text, linebreak
if ( *text=='\n'){
if ( neg ) return( RE_NOMATCH );
break;
}
if ( neg ) break;
return( RE_NOMATCH );
case '&':
match_char = 1;
case '%':
if ( re[1]!=0 && re[1] >='0' && re[1] <= '9' ){
n_match = re[1]-'0';
*re++;
}
if ( match_char ){ // match &
if ( p_wildcard_cb ){
int m = p_wildcard_cb(n_match,text);
if ( m==RE_NOMATCH ){
if ( neg ) break;
return( RE_NOMATCH );
}
if ( m==RE_MATCHEND ){
return(neg?RE_NOMATCH:REMATCH);
}
text=text+m;
}
if ( neg ) return( RE_NOMATCH );
break; // matched, also for p_wildcard_cb == 0
}
matchpos=text;
case '+': // match one or more chars . not needed. no gain. (can be written as ?*)
text++;
if ( !*text ) return(neg?REMATCH:RE_NOMATCH);//
case '*': // match 0 or more chars
re++;
if ( *re == 0){ // match. end of regex.
if ( matchpos && ( p_matched_cb || st_match ) ){
while ( *text )	// find end of text
text++;
if ( p_matched_cb )
p_matched_cb(n_match, matchpos,text-matchpos);
if ( st_match ){
st_match->pos = matchpos;
st_match->len = text-matchpos;
}
}
if ( !count ){
printf("starmatch, count: %d rematch: %lx\n",count,rematch);
return(REMATCH); //rpl
}
else break;
}
char *pos;
while ( (rematch=_match_ext2(text,re,p_matched_cb,p_wildcard_cb,st_match)) == RE_NOMATCH ){
text++;
if ( !*text ){
if ( (*re == '#' || *re == '$')  )
goto __MATCHEND;
return(RE_NOMATCH); //rpl
}
}
__MATCHEND:
if ( matchpos ){
if ( p_matched_cb )
p_matched_cb(n_match,matchpos,text-matchpos);
if ( st_match ){
st_match->pos = matchpos;
st_match->len = text-matchpos;
}
}
if ( !count )
return(rematch); //rpl
else break;
return(neg?RE_NOMATCH:REMATCH);
case '\\': // match escaped *,?,backslashes, %
re++;
#define _MATCH(a,condition) if ( *re == a ){\
if ( neg ^ (condition) ) break;\
else return(RE_NOMATCH);}
_MATCH('n',*text=='\n'); // match 'escaped' escape sequence
_MATCH('t',*text=='\t'); // match 'escaped' escape sequence
_MATCH('d',isdigit(*text));
_MATCH('D',!isdigit(*text));
_MATCH('s',isspace(*text));
_MATCH('S',!isspace(*text));
_MATCH('w',(*text>=32 && *text <= 126 ) || ( *text>=160 ) );
_MATCH('W',(*text<32 ) || (( *text > 126 ) && ( *text<160 )) );
_MATCH('x',isdigit(*text) ||
('a'<=*text && *text<='f') ||
('A'<=*text && *text<='F') );
default:
if ( *re==0 ) //partial match ( could be spared )
return(RE_NOMATCH);
if ( neg ^ (*re!=*text) ){
return(RE_NOMATCH);
}
}
text++;
}
re++;
}
if ( *re == ',' )
re++;
if ( ( *re=='#' ) || ( *re=='$') ){ // match end of text
printsl("re_match end");
return(REMATCH);
}
if ( *re==0 || ( *re=='*' && re[1]==0 ) ){
return(REMATCH); //matched
}
return(RE_NOMATCH);
}
#endif
#endif
#ifdef mini_getusergroups
int getusergroups(const char* user, int maxgroups, int *list){
int groups = 0;
setgrent(); // set groups to the first entry
struct group* gr = 0;
while ( groups<maxgroups ){
gr = getgrent();
if ( !gr ) // last entry, or error
return(groups);
int a=0;
for ( char* u=*gr->gr_mem;u;u=gr->gr_mem[++a] ){
if ( strcmp( u,user ) == 0 ){
*list=gr->gr_gid;
list++;
groups++;
break;
}
}
}
#ifdef mini_errno
errno=EINVAL;
#endif
return(-1);
}
#endif
#ifdef mini_strcpy
char *strcpy(char *dest, const char *src){
char *d;
for ( d = dest; *src; src++,d++ )
*d=*src;
*d = 0;
return(dest);
}
#endif
#ifdef mini_basename
char *basename(char *path){
if (path == 0 || *path == 0 )
return ( ".");
char *p;
char *pos1 = path-1;
char *pos2 = path-1;
for ( p=path; *p!=0; p++ ){
if ( *p=='/' ){
if ( p>pos2+1 ){
pos1 = pos2;
}
pos2 = p;
}
}
if ( p-pos2>1 ) // chars after last /
return(pos2+1);
if ( pos2 == (path-1) ) // no / at all
return(path);
if ( pos1 == (path-1) )
return(pos2);
if ( *(pos2-1) == '/' ){
*(pos2-1) = 0;
}
*pos2 = 0; // set trailing / to 0
return( pos1+1 );
}
#endif
#ifdef mini_memcpy
void* memcpy( void*d, const void *s, int n ){
#ifndef mini_OPTIMIZE
for ( int a=0; a<n; a++ ){
*(char*)(d+a)=*(char*)(s+a);
}
return(d);
#else
if ( !n ) return(d);
int e, a = 0;
for ( e=n>>3; a<e; a++ ){
*(long*)(d+a)=*(long*)(s+a);
}
if ( a == n ) return(d);
for ( e=n>>2; a<e; a++ ){
*(int*)(d+a)=*(int*)(s+a);
}
if ( a == n ) return(d);
for ( ; a<n; a++ ){
*(char*)(d+a)=*(char*)(s+a);
}
return(d);
#endif
}
#endif
#ifdef mini_fprintfs
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
if (fmt[a] == 'c'){
ret += write(fd,&fmt[p],a-1-p);
p=a+1;
char c = va_arg(args,int);
ret += write( fd,&c,1 );
}
}
a++;
}
ret += write(fd,&fmt[p],a-p);
va_end(args);
return(ret);
}
#endif
#ifdef mini_strtoll
long long int strtoll(const char *c, const char **endp, int base){
return((long long)strtol(c,endp,base));
}
#endif
#ifdef mini_strrchr
#endif
#ifdef mini_posix_openpt
#ifndef pty_c
#define pty_c
int posix_openpt(int flags){
return open("/dev/ptmx", flags);
}
int unlockpt(int fd){
int unlock = 0;
return ioctl(fd, TIOCSPTLCK, &unlock);
}
int ptsname_r(int fd, char *buf, size_t len){
int pty, err;
if (!buf) len = 0;
if ((err = ioctl( fd, TIOCGPTN, &pty))) return -err;
if (sprintf(buf, "/dev/pts/%d", pty) >= len) return ERANGE;
return 0;
}
char *ptsname(int fd){
static char buf[9 + sizeof(int)*3 + 1];
int err = ptsname_r(fd, buf, sizeof buf);
if (err) {
#ifdef mini_errno
errno = err;
#endif
return 0;
}
return buf;
}
int grantpt(int fd){
struct stat st;
if ((fstat(fd, &st))<0) return -1;
if ((chmod((char*)ptsname(fd), st.st_mode | S_IRUSR | S_IWUSR | S_IWGRP))<0)
return -1;
return 0;
}
#endif
#endif
#ifdef mini_die
#ifndef mini_die_c
#define mini_die_c
void _die(){
#ifdef mini_errno
int errnum=errno;
#else
int errnum=0;
#endif
if ( errnum )
exit_errno(errnum);
exit(-1);
}
#endif
#endif
#ifdef mini_brk
#ifndef mini_brk_c
#define mini_brk_c
static long sys_brk(unsigned long addr){
long ret;
syscall1( ret,( __SYSCALL(_brk) | NCONST ), addr );
return(ret);
}
#define _sys_brk sys_brk
static int brk( const void* addr ){
long newbrk = _sys_brk((unsigned long)addr);
int ret = 0;
if ( newbrk >0 ){
#ifdef mini_globals
mlgl->brk = newbrk;
#endif
return(0);
}
#ifdef mini_errno
errno = -ret;
ret = -1;
#endif
return(ret);
}
static int setbrk(long addr){
return(brk((void*)addr));
}
static long getbrk(){
#ifdef mini_globals
if ( !mlgl->brk ){
mlgl->brk=_sys_brk(0); // get the old brk
}
return(mlgl->brk);
#else
return(_sys_brk(0));
#endif
}
static void* sbrk(long incr){
long ret = getbrk();
long addr = ret + (long)incr;
long newbrk = _sys_brk(addr);
if ( newbrk >0 ){ // success
#ifdef mini_globals
mlgl->brk = newbrk;
#endif
return((void*)ret);
}
#ifdef mini_errno
errno = -newbrk;
newbrk = 0;
#endif
return((void*)newbrk);
}
#endif
#endif
#ifdef mini_strstr
char* strstr(const char *big, const char *little){
register char *s = (char*)big;
register char *p = (char*)little;
char *sp = s;
if ( *little == 0 )
return(s);
do {
if (*s==*p){
sp = s;
do {
p++;s++;
if ( *p == 0 )
return( sp ); // match
} while ( *s==*p );
s=sp;
p=(char*)little;
}
s++;
} while ( *s != 0 ); // end of big reached
return(0);
}
#endif
#ifdef mini_dirfd
int dirfd(DIR *d){
return d->fd;
}
#endif
#ifdef mini_fgets
char* fgets(char *buf, int size, FILE* F){
char *ret = buf;
*buf = (char)fgetc(F);
if ( !*buf ) // EOF
return(0);
if ( *buf == '\n' )
size=0;
while( --size >0 ){
buf++;
*buf = (char)fgetc(F);
if ( *buf == 0 )
return(ret);
if ( *buf == '\n' )
size=0;
}
buf++;
*buf = 0;
return(ret);
}
#endif
#ifdef mini_dprintf
int dprintf( int fd, const char *fmt, ... ){
va_list args;
va_start(args,fmt);
int r = vsnprintf(mlgl->mbuf, mlgl->mbufsize, fmt, args);
if ( r<0 ){
write(2,"Buffer Overrun.\n",16);
exit(1);
}
write( fd, mlgl->mbuf, r );
va_end(args);
return(r);
}
#endif
#ifdef mini_cfmakeraw
void cfmakeraw(struct termios *tp){
tp->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
tp->c_oflag &= ~OPOST;
tp->c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
tp->c_cflag &= ~(CSIZE|PARENB);
tp->c_cflag |= CS8;
tp->c_cc[VMIN] = 1;
tp->c_cc[VTIME] = 0;
}
#endif
#ifdef mini_snprintfs
int snprintfs( char* buf, int size, char *fmt, ...){
va_list args;
va_start(args,fmt);
char *msg;
int a;
char *p = buf;
char *e = (p+size);
int ret = 0;
a = 0;
while ( (fmt[a] != 0) && ( p<e ) ){
if ( fmt[a] == '%' ){
a++;
if (fmt[a] == 's'){
msg = va_arg(args,char*);
p = stpncpy( p, msg, (e-p) );
}
if (fmt[a] == 'c'){
char c = va_arg(args,int);
*p = c;
p++;
}
} else {
*p = fmt[a];
p++;
}
a++;
}
*p=0;
va_end(args);
return(p-buf);
}
#endif
#ifdef mini_dief_if
#endif
#ifdef mini_strerror
#ifndef strerror_r
#define strerror_r
static char* strerror( int errnum ){
#ifndef mini_verbose_errstr
static char errstr[18];
char* msg = "Error, errno: 000";
for ( char *c = errstr; (*c=*msg); c++ && msg++ );
errstr[14]+=errnum/100;
errstr[15]+=(errnum%=100)/10;
errstr[16]+=errnum%10; // 0+errnum..
return( errstr );
#else
return((char*)verbose_errstr(errnum));
#endif
}
#endif
#endif
#ifdef mini_dies_if
#endif
#ifdef mini_itooct
int itooct(int i, char *buf){
int p = 0;
int count = 0;
char tmp[16];
if ( i == 0 ){
*buf = '0';
buf++;
count++;
}
if ( i<0 ){
i=-i;
*buf='-';
buf++;
count++;
}
while(i!=0){
tmp[p]=(i&7)+'0';
i=i>>3;
p++;
}
count += p;
while(p>=0){
*buf = tmp[p];
buf++;
p--;
}
*buf=0;
return(count+1);
}
#endif
#ifdef mini_execl
static int execl(const char *pathname, const char* arg0,... ){
va_list ap;
va_start(ap, arg0);
int argc = 1;
while (va_arg(ap, const char *))
argc++;
va_end(ap);
{
int i;
char *argv[argc+1];
va_start(ap, arg0);
argv[0] = (char *)arg0;
for (i=1; i<argc; i++)
argv[i] = va_arg(ap, char *);
argv[i] = 0;
va_end(ap);
return(execve(pathname, argv, environ));
}
}
#endif
#ifdef mini_strcat
char *strcat(char *dest, const char *src ){
size_t dest_len = strlen(dest);
size_t i;
for (i = 0 ; src[i] != '\0' ; i++)
dest[dest_len + i] = src[i];
dest[dest_len + i] = '\0';
return dest;
}
#endif
#ifdef mini_stplcpy
char *stplcpy(char *dest, const char *src, int size){
char *d = dest;
char *e = (dest+size);
while ( *src && ( d<e) ){
*d=*src;
d++;
src++;
}
*d= 0;
return(d);
}
#endif
#ifdef mini_setbrk
#endif
#ifdef mini_ptsname_r
#endif
#ifdef mini_snprintf
int snprintf( char *buf, size_t size, const char *fmt, ... ){
va_list args;
va_start(args,fmt);
int r = vsnprintf(buf, size, fmt, args);
va_end(args);
return(r);
}
#endif
#ifdef mini_execvpe
#ifndef mini_exevp_c
#define mini_exevp_c
int where(const char *file,char *buf){
char *path = getenv("PATH");
if ( !path ){
path = "/bin:/usr/bin:/sbin:/usr/sbin:/usr/local/bin:/local/bin";
}
char *p = buf;
do {
*p = *path;
p++; path++;
if ( *path == ':' || *path == 0 ){
*p++ = '/';
for ( char *c= (char*)file; (*p++ = *c++); );
if ( access( buf, R_OK | X_OK ) == 0 ){
return( 1 );
}
if ( !*path )
return(0);
p=buf;
path++;
}
} while (1);
}
static int execvpe(const char *file, char *const argv[], char *const envp[]){
if ( file[0] == 0 || file[0] == '.' || file[0] == '/' )
return( execve( file, argv, envp ) );
char buf[PATH_MAX];
if ( where( file, buf ))
return( execve( buf, argv, envp ) );
return(-1);
};
#endif
#endif
#ifdef mini_getpwuid
struct passwd *getpwuid(uid_t uid){
if ( !mlgl->passwdfile.file ){
if ( !userdb_open(&mlgl->passwdfile,PASSWDFILE) )
return(0);
} else {
if ( ( mlgl->pwent.pw_name != 0 ) && (uid == mlgl->pwent.pw_uid ) )
return( &mlgl->pwent );
}
char *p = mlgl->passwdfile.file;
do {
char *pw_name = token_s( &mlgl->passwdfile,&p);
char *pw_passwd = token_s( &mlgl->passwdfile,&p);
int euid = token_i( &mlgl->passwdfile,&p);
if ( euid == uid ){ // found
mlgl->pwent.pw_name = pw_name;
mlgl->pwent.pw_passwd = pw_passwd;
mlgl->pwent.pw_uid = euid;
mlgl->pwent.pw_gid = token_i( &mlgl->passwdfile,&p);
mlgl->pwent.pw_gecos = token_s( &mlgl->passwdfile,&p);
mlgl->pwent.pw_dir = token_s( &mlgl->passwdfile,&p);
mlgl->pwent.pw_shell = token_s( &mlgl->passwdfile,&p);
return(&mlgl->pwent);
}
for ( int a = 0; a<4; a++ )
token_s( &mlgl->passwdfile,&p);
} while ( p < (mlgl->passwdfile.file+mlgl->passwdfile.size) );
return(0); // not found
}
#endif
#ifdef mini_memmove
void* memmove(void *dest, const void *src, int n){
char *d;
const char *s;
d = dest;
s = src;
while(n-- > 0)
*d++ = *s++;
return dest;
}
#endif
#ifdef mini_dies
#endif
#ifdef mini_getpwent
struct passwd* getpwent(){
if ( !mlgl->passwdfile.file ){
if ( !userdb_open(&mlgl->passwdfile,PASSWDFILE) )
return(0);
}
if ( mlgl->passwdfile.p >= (mlgl->passwdfile.file+mlgl->passwdfile.size) )
return(0);
char *p = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);
if ( *p == 0 )
return(0);
mlgl->pwent.pw_name = p;
mlgl->pwent.pw_passwd = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);
mlgl->pwent.pw_uid = token_i( &mlgl->passwdfile,&mlgl->passwdfile.p);
mlgl->pwent.pw_gid = token_i( &mlgl->passwdfile,&mlgl->passwdfile.p);
mlgl->pwent.pw_gecos = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);
mlgl->pwent.pw_dir = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);
mlgl->pwent.pw_shell = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);
return(&mlgl->pwent);
}
#endif
#ifdef mini_getgrgid
struct group *getgrgid(gid_t gid){
if ( mlgl->groupfile.file==0 ){
if ( !userdb_open(&mlgl->groupfile,GROUPFILE) ) {
ewrites("Unable to access " GROUPFILE "\n" );
return(0);
}
} else {
if ( mlgl->groupent.gr_gid == gid ){
return( &mlgl->groupent );
}
}
setgrent();
for ( struct group* ret=getgrent();ret;ret=getgrent() ){
if ( mlgl->groupent.gr_gid == gid ){
return(ret);
}
}
return(0);
}
#endif
#ifdef mini_dief
#endif
#ifdef mini_sdbm_hash
unsigned long sdbm_hash(const unsigned char *str){
unsigned long hash = 0;
int c;
while ((c = *str++))
hash = c + (hash << 6) + (hash << 16) - hash;
return hash;
}
#endif
#ifdef mini_malloc_brk
#define MALLOC_BRK 0x10000000
void* malloc_brk(int size){
if ( size<0 )
return(0);
if ( size == 0 )
size = 4;
else
size = (((size-1) >> 2 ) + 2)<<2; // alignment and reserving space for the "pointer"(int)
void *mem = sbrk(size);
if ( mem <= 0 )
return(0);
if ( !mlgl->malloc_start)
mlgl->malloc_start = (long)mem;
int *i = mem;
*i=( MALLOC_BRK | (size));
i++;
return(mem+4);
}
#endif
#ifdef mini_exit_errno
void exit_errno( int errnum ){
if ( errnum < 0 )
errnum = -errnum;
char *args[3];
args[0] = "errno";
args[1] = (char*)errno_str( errnum );
args[2] = 0;
execve("/bin/errno",args,0);
ewrites("Error, errno: ");
write(STDERR_FILENO, args[1], 3 );
ewrites("\n");
exit(errnum);
}
#endif
#ifdef mini_strncpy
char *strncpy(char *dest, const char *src, int n){
int a;
for ( a=0; src[a] != 0; a++){
if ( a>=n )
return(dest);
dest[a] = src[a];
}
for (;a<n;a++)
dest[a] = 0;
return(dest);
}
#endif
#ifdef mini_qsort
#endif
#ifdef mini_perror
void perror(const char *msg){
if ( msg !=0 && msg[0] != '\0' )
fputs( msg, stderr );
fputs( strerror( errno ), stderr );
}
#endif
#ifdef mini_term_width
int term_width(){
char *p = getenv("COLUMNS");
if ( !p ) return(80);
int ret = 0;
while ( *p ){
ret = ret*10 + *p-'0';
p++;
}
return(ret);
}
#endif
#ifdef mini_inet_ntoa
char* inet_ntoa( struct in_addr in){
union { uint32_t i; char c[4]; } u = { .i=in.s_addr };
char *p = mlgl->inet_ntoa_addr-1;
for ( int n=0; n<4; n++ ){
p++;
if ( u.c[n] > 9 ){
if ( u.c[n] > 199 ){
*p = '2';
p++;
u.c[n]-=200;
} else if ( u.c[n] > 99 ){
*p = '1';
p++;
u.c[n]-=100;
}
*p = '0';
while ( u.c[n] > 9 ){
u.c[n]-=10;
*p += 1;
}
p++;
}
*p = '0' + u.c[n];
p++;
*p = '.';
}
*p = 0;
return( mlgl->inet_ntoa_addr );
}
#endif
#ifdef mini_djb2_hash
unsigned long djb2_hash(const unsigned char *str){
unsigned long hash = 5381;
int c;
while ((c = *str++))
hash = ((hash << 5) + hash) + c; 
return hash;
}
#endif
#ifdef mini_gethostname
static int gethostname(char *name,int len){
struct new_utsname u;
int ret=uname(&u);
if (ret==0) {
if (len > sizeof(u.nodename)) len = sizeof(u.nodename);
int i;
for (i=0; i<len && (name[i] = u.nodename[i]); i++);
if (i && i==len) name[i-1] = 0;
}
return(ret);
}
#endif
#ifdef mini_unlockpt
#endif
#ifdef mini_die_if
#endif
#ifdef mini_setpwent
void setpwent(){
mlgl->passwdfile.p = mlgl->passwdfile.file;
}
#endif
#ifdef mini_userdb_open
int userdb_open(userdb *udb, const char* file){
if ( udb->file )
return(1);
int fd = open( file, O_RDONLY );
if ( fd<=0 ){
ewrites("Error opening passwdfile/group" );
return(0);
}
struct stat ststat;
fstat(fd, &ststat );
udb->file = mmap( 0, ststat.st_size * 2, PROT_READ | PROT_WRITE,
MAP_PRIVATE, fd, 0 );
close(fd);
udb->p = udb->file;
udb->size = ststat.st_size;
udb->p2 = (char**)(udb->file+ststat.st_size);
return(1);
}
#endif
#ifdef mini_alphasort
int alphasort( const struct dirent** de1, const struct dirent** de2 ){
return(strcmp((*de1)->d_name,(*de2)->d_name) );
}
#endif
#ifdef mini_uitodec
#ifndef mini_itodec_c
#define mini_itodec_c
int __attribute__((optimize("Os")))uitodec(unsigned int i, char *buf, int prec, char limiter, char pad ){
int p = 0;
int a;
int t1,t2,t3,dec;
char n;
char trail=' ';
if ( pad )
trail = pad;
prec = prec - 10; // Maximale Stellenanzahl
if ( i==0 ){
buf[0] = '0';
}
int trailing = 1;
const int div[13] = {0, 100000000, 10000000, 1000000, 0, 100000, 10000, 1000, 0, 100, 10, 1};
if ( i >= 1000000000){
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
buf[p] = trail;
else
buf[p] = n;
p++;
} else
prec++;
}
}
if ( p==0 ){
buf[0]='0';
p=1;
}
buf[p] = 0;
return(p);
}
int itodec(int i, char *buf, int prec, char limiter, char pad ){
if ( i < 0 ){
buf[0]='-';
i = -i;
return(uitodec((unsigned int)i,&buf[1],prec,limiter,pad) + 1);
}
return(uitodec((unsigned int)i,buf,prec,limiter,pad) );
}
#endif
#endif
#ifdef mini_closedir
#ifndef closedir_c
#define closedir_c
int closedir(DIR *dir){
int ret = close(dir->fd);
free(dir);
return(ret);
}
#endif
#endif
#ifdef mini__itobin
#ifndef mini_itobin_h
#define mini_itobin_h
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
#endif
#endif
#ifdef mini_memcmp
int memcmp(const void* c1,const void* c2,int len){
const char* cc1 = c1;
const char* cc2 = c2;
if ( len <=0 )
return(-1);
int a = 0;
len--;
while ( (a < len) && (cc1[a]==cc2[a]) ) a++;
if ( cc1[a] > cc2[a] )
return(1);
if ( cc1[a] < cc2[a] )
return(-1);
return(0);
}
#endif
#ifdef mini_warn
#endif
#ifdef mini_tcsetattr
#ifndef tcsetattr_h
#define tcsetattr_h
#ifdef OSX
#else
#endif
int tcsetattr(int fd, int opt, const struct termios *io){
return(ioctl(fd, TCSETA +opt, io));
}
#endif
#endif
#ifdef mini_getgrnam
struct group *getgrnam(const char* name){
if ( mlgl->groupfile.file==0 ){
if ( !userdb_open(&mlgl->groupfile,GROUPFILE) ) {
ewrites("Unable to access " GROUPFILE "\n" );
return(0);
}
} else {
if ( strcmp( mlgl->groupent.gr_name, name) == 0 ){
return( &mlgl->groupent );
}
}
setgrent();
for ( struct group* ret=getgrent();ret;ret=getgrent() ){
if ( strcmp( name, ret->gr_name ) == 0 )
return(ret);
}
return(0);
}
#endif
#ifdef mini_signal
sighandler_t signal(int sig, sighandler_t func ){
struct sigaction sa_old = { .sa_handler=0, .sa_flags=0 };
struct sigaction sa = { .sa_handler = func, .sa_flags = SA_RESTART };
if (sigaction(sig, &sa, &sa_old) < 0){
ewrites("SIGNAL - ERR\n");
return SIG_ERR;
}
return sa_old.sa_handler;
}
#endif
#ifdef mini_opendir
#ifndef mini_opendir_c
#define mini_opendir_c
static DIR *opendir(const char *name ){
DIR *dir;
dir = DIRBUF_MALLOC(sizeof(*dir));
if ( dir == 0 ){
ewrites("No memory in opendir\n");
return 0;
}
DIR* ret = opendirp(name,dir);
if ( ret == 0 ){
free(dir);
return(0);
}
return(dir);
}
#endif
#endif
#ifdef mini_strdup
#ifndef strdup_c
#define strdup_c
char *strdup(const char *source){
char *d =  malloc(strlen(source));
if ( !d ) return(0);
strcpy(d,source);
return(d);
}
#endif
#endif
#ifdef mini_tcgetattr
#ifndef tcgetattr_h
#define tcgetattr_h
#ifndef	_TERMIOS_H
#define	_TERMIOS_H
#endif
#ifdef OSX
#else
#endif
int tcgetattr(int fd, struct termios *io){
return(ioctl(fd, TCGETA, io));
}
#endif
#endif
#ifdef mini_atexit
static int atexit( functionp* func ){
int p=0;
while( mlgl->atexitp[p] != 0 ){
p++;
if ( p>=ATEXIT_MAX )
return( ENOMEM );
}
mlgl->atexitp[p] = func;
if ( p<ATEXIT_MAX-1 )
mlgl->atexitp[p+1] = 0;
return(0);
}
#endif
#ifdef mini_fgetsp
char* fgetsp(char *buf, int size, FILE* F){
while( --size >0 ){
*buf = (char)fgetc(F);
switch ( *buf ){
case '\n':
*buf=0;
case 0:
return(buf);
}
buf++;
}
*buf = 0;
return(buf);
}
#endif
#ifdef mini_stpncpy
char *stpncpy(char *dest, const char *src, int size){
char *d = dest;
char *e = (dest+size);
while ( *src && ( d<e) ){
*d=*src;
d++;
src++;
}
char *r = d;
while ( d<e ){
*d++= 0;
}
return(r);
}
#endif
#ifdef mini_bsd_cksum
#endif
#ifdef mini_opendirp
static DIR *opendirp(const char *name, DIR *dir){
int fd;
if ((fd = open(name, O_RDONLY|O_DIRECTORY|O_CLOEXEC)) < 0)
return 0;
dir->fd = fd;
dir->buf_pos=dir->buf_end=0;
return dir;
}
#endif
#ifdef mini_srand
#endif
#ifdef mini_inet_aton
int inet_aton(const char* s, struct in_addr *addr){
union { uint32_t i; char c[4]; } u = { .i=0 };
int p = 0;
char *pc = (char*)s;
do {
while ( ( '0' <= *pc ) && ( *pc <= '9' ) ){
u.c[p] = u.c[p]*10 + ( *pc-'0' );
pc++;
}
if ( !*pc )
break;
p++;
pc++;
}	while (p<4);
if ( p<3 ){
u.c[3] = u.c[p];
u.c[p] = 0;
}
addr->s_addr = u.i;
return(1);
}
#endif
#ifdef mini_sys_brk
#endif
#ifdef mini_itodec
#endif
#ifdef mini_scandir
#endif
#ifdef mini_endpwent
void endpwent(){
munmap( (void*)mlgl->passwdfile.file, mlgl->passwdfile.size );
mlgl->passwdfile.file = 0;
}
#endif
#ifdef mini_ntohl
#endif
#ifdef mini_where
#endif
#ifdef mini_errno_str
static char *errno_str(int err){
static char e[5];
char *p = e;
if ( err<0 )
err=-err;
if ( err>99 ){
err-=100;
} else {
p++;
}
e[0] = '1';
e[1]=(err/10)+'0';
e[2]=(err%10)+'0';
e[3]=0;
e[4]=0;
return(p);
}
#endif
#ifdef mini_bsd_cksumblock
#endif
#ifdef mini_htonl
#endif
#ifdef mini_strlcpy
char *strlcpy(char *dest, const char *src, int n){
int a = -1;
do {
a++;
if ( a>=(n-1) ){
dest[n-1] = 0;
return(dest);
}
dest[a] = src[a];
} while ( src[a] != 0 );
return(dest);
}
#endif
#ifdef mini_match_ext
int match_ext(char *text, const char *re, void(*p_match)(int number, char *pos,int len, void *userdata), int(*p_match_char)(int number, char *match_char, void *userdata), tmatch_ext *st_match, void *userdata){
int n_match=0;
char *matchpos = 0;
int neg = 0;
if ( st_match ) st_match->len=0;
while ( *text!=0 ){
int match_char = 0;
neg = 0;
if ( *re == '!' ){
re++;
neg=1;
}
int count = 0;
if ( *re == '}' )
re++;
if ( *re == '{' ){
while ( re++ && isdigit(*re) ){
count += (count*10) + (*re-'0');
}
} else {
count = 1;
}
if ( *re == ',' ) // separate e.g. %,1
re++;
const char *pos = re;
while ( count --> 0 ){
re=pos;
switch ( *re ){
case '?':
if ( neg )
return(RE_NOMATCH);
break; // matches, but only if there's a char (not 0)
case '[':
for ( re++; *re && *re!=*text; re++ )
if ( *re==']' )
return(neg ^ RE_NOMATCH);
while ( *re && *re != ']' )
re++;
if ( !*re )
return( RE_ERROR );
if ( neg )
return( RE_NOMATCH );
break;
case '#': // match end of text, or a space; here a space
if ( isspace( *text )){
if ( neg ) return( RE_NOMATCH );
break;
}
if ( neg ) break;
return( RE_NOMATCH );
case '&':
match_char = 1;
case '%':
if ( re[1]!=0 && re[1] >='0' && re[1] <= '9' ){
n_match = re[1]-'0';
*re++;
}
if ( match_char ){ // match &
if ( p_match_char ){
int m = p_match_char(n_match,text,userdata);
if ( m==RE_NOMATCH ){
if ( neg ) break;
return( RE_NOMATCH );
}
if ( m==RE_MATCHEND ){
return(neg^RE_MATCH);
}
text=text+m;
}
if ( neg ) return( RE_NOMATCH );
break; // matched, also for p_match_char == 0
}
matchpos=text;
case '+': // match one or more chars . not needed. no gain. (can be written as ?*)
text++;
if ( !*text ) return(neg ^ RE_NOMATCH);//
case '*': // match 0 or more chars
re++;
if ( *re == 0){ // match. end of regex.
if ( matchpos && ( p_match || st_match ) ){
while ( *text )	// find end of text
text++;
if ( p_match )
p_match(n_match, matchpos,text-matchpos,userdata);
if ( st_match ){
st_match->pos = matchpos;
st_match->len = text-matchpos;
}
}
return(neg ^ RE_MATCH); // no chars anymore. so a match
}
while ( !match_ext(text,re,p_match,p_match_char,st_match,userdata) ){
text++;
if ( !*text ){
if ( (*re == '#' || *re == '$') && ( re[1]==0 ) )
goto __MATCHEND;
return(neg ^ RE_NOMATCH);
}
}
__MATCHEND:
if ( matchpos ){
if ( p_match )
p_match(n_match,matchpos,text-matchpos,userdata);
if ( st_match ){
st_match->pos = matchpos;
st_match->len = text-matchpos;
}
}
return(neg ^ RE_MATCH);
case '\\': // match escaped *,?,backslashes, %
re++;
#define _MATCH(a,condition) if ( *re == a ){\
if ( neg ^ condition ) break;\
else return(RE_NOMATCH);}
_MATCH('d',isdigit(*text));
_MATCH('D',!isdigit(*text));
_MATCH('s',isspace(*text));
_MATCH('S',!isspace(*text));
_MATCH('w',(*text>=32 && *text <= 126 ) || ( *text>=160 ) );
_MATCH('W',(*text<32 ) || (( *text > 126 ) && ( *text<160 )) );
default:
if ( *re==0 ) //partial match ( could be spared )
return(RE_NOMATCH);
if ( neg ^ (*re!=*text) ){
return(RE_NOMATCH);
}
}
text++;
}
re++;
}
if ( ( *re=='#' ) || ( *re=='$') ){ // match end of text
re++;
}
if ( *re==0 || ( *re=='*' && re[1]==0 ) ){
return(RE_MATCH); //matched
}
return(RE_NOMATCH);
}
#endif
#ifdef mini_fgetul
unsigned long int fgetul(FILE* F){
unsigned long int ret = 0;
char c = 0;
while ( ( c = (char)fgetc(F) ) && isdigit(c) ){
ret = ret*10 + (c-48);
}
return(ret);
}
#endif
#ifdef mini_clone_t
int clone_t(int flags){
long tid,ptid;
long int sysret;
register long int r10 asm ("r10") = &ptid;
OPTFENCE(r10,tid,flags,sysret,ptid);
__SYSCALL_ASM(sysret,__NR_clone) , "D" (flags), "S" (0), "d" (&tid), "r" (r10)  __callend;
return(sysret);
}
#endif
#ifdef mini__match_ext2
#endif
#ifdef mini_vexec_q
#endif
#ifdef mini_execv
static inline int execv(const char *pathname, char *const argv[]){
return( execve( pathname, argv, environ ) );
};
#endif
#ifdef mini_getbrk
#endif
#ifdef mini_system
int system( const char* command ){
int pid = vfork();
char* const arg[4] = { "sh", "-c", (char*)command, 0 };
if ( pid==0 ){
execve( "/bin/sh", arg, (char* const*)environ );
ewrites("Error. Couldn't exec sh in system()\n");
exit(-1);
}
int ws;
do {
waitpid( pid, &ws, 0 );
} while ( !WIFEXITED(ws) );
return(WEXITSTATUS(ws));
}
#endif
#ifdef mini_readdir
#ifndef readdir_c
#define readdir_c
struct dirent *readdir(DIR *dir){
struct dirent *de;
if (dir->buf_pos >= dir->buf_end) {
int len = getdents( dir->fd, (struct dirent*) dir->buf, sizeof(dir->buf));
if (len <= 0) {
#ifdef mini_errno
if (len < 0 && len != -ENOENT){
errno = -len;
}
#endif
return(0);
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
#ifdef mini_mmap
static void* __attribute__((optimize("O0"))) mmap(void* addr,  size_t len,  int prot,  int flags,  int fd,  off_t off){
long ret;
if ( fd <0 )
fd=0;
syscall6( ret,( __SYSCALL(_mmap) | NCONST ), addr, len, prot, flags, fd, off );
#ifdef mini_errno
if (ret<0 ){
errno = -ret;
ret=-1;
}
#endif
return((void*)ret);
}
#endif
#ifdef mini_setenv
int setenv( const char *name, const char *value, int overwrite ){
char **envp;
int len = strlen(name);
for ( envp=environ; *envp; envp++ ) {
if ( strncmp((char*)*envp, (char*)name, len) == 0 ) {
if ( overwrite == 0 )
return(0);
*envp=malloc(len+1+strlen(value));
if ( !*envp )
ret_errno(ENOMEM);
char *c = stpcpy(*envp,value);
*c = '=';
c++;
strcpy(c,value);
return(0);
}
}
*envp=malloc(len+1+strlen(value));
if ( !*envp )
ret_errno(ENOMEM);
char *c = stpcpy(*envp,value);
*c = '=';
c++;
strcpy(c,value);
envp++;
*envp=0;
return(0);
}
#endif
#ifdef mini_atol
long atol(const char *c){
long ret = 0;
int sign = 0;
if ( *c == '-' ){
sign=1;
c++;
}
while( (*c>='0') && (*c<='9') ){
ret*=10;
ret=ret+(*c-48);
c++;
}
if ( sign )
return(-ret);
return(ret);
}
#endif
#ifdef mini_error
#endif
#ifdef mini_gets
#endif
#ifdef mini_endgrent
void endgrent(){
munmap( (void*)mlgl->groupfile.file, mlgl->groupfile.size*2 );
mlgl->groupfile.file = 0;
}
#endif
#ifdef mini_grantpt
#endif
#ifdef mini_stpcpy
char *stpcpy(char *dest, const char *src){
char *d = dest;
while ( *src ){
*d=*src;
d++;
src++;
}
*d = 0;
return(d);
}
#endif
#ifdef mini_sbrk
#endif
#ifdef mini_abort
void abort(){
raise(SIGABRT);
signal(SIGABRT,SIG_DFL);
raise(SIGABRT);
exit(125);
}
#endif
#ifdef mini_rewinddir
void rewinddir(DIR *dir){
lseek(dir->fd, 0, SEEK_SET);
dir->buf_pos = dir->buf_end = 0;
dir->tell = 0;
}
#endif
#ifdef mini_putenv
int putenv( char *string ){
char **envp;
int   pos=0;
for ( ; string[pos]!=0 && string[pos] != '='; pos ++ );
if ( ! pos || ! string[pos] )
ret_errno(EINVAL); // error.
for ( envp=environ; *envp; envp++ ) {
if ( strncmp((char*)*envp, (char*)string, pos) == 0 ) {
*envp=string;
return(0);
}
}
*envp=string;
envp++;
*envp=0;
return(0);
}
#endif
#ifdef mini_strchrnul
#endif
#ifdef mini_seekdir
void seekdir(DIR *dir, long off){
dir->tell = lseek(dir->fd, off, SEEK_SET);
dir->buf_pos = dir->buf_end = 0;
}
#endif
#ifdef mini_itobin
#endif
#ifdef mini_dprints
#endif
#ifdef mini_atoi
int atoi(const char *c){
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
#ifdef mini_fgetsn
int fgetsn(char *buf, int size, FILE* F){
char *ret = buf;
*buf = (char)fgetc(F);
if ( !*buf ) // EOF
return(0);
if ( *buf == '\n' )
size=0;
while( --size >0 ){
buf++;
*buf = (char)fgetc(F);
if ( *buf == 0 )
return(buf-ret);
if ( *buf == '\n' )
size=0;
}
buf++;
*buf = 0;
return(buf-ret);
}
#endif
#ifdef mini__fopen
#ifndef mini__fopen_c
#define mini__fopen_c
int volatile open( const char *s, int flags, ... );
FILE *_fopen(int fd, const char* filename, const char* mode, FILE *f){
int imode;
switch (mode[0]){
case 'r': imode = O_RDONLY;
break;
case 'w': imode = O_WRONLY | O_TRUNC | O_CREAT;
break;
case 'a': imode = O_APPEND | O_RDWR; // somehow only "a+" works. Not sure, why.
break;
default: return((FILE*)0); // hopefully a fd cannot be 0.? By reading the manual,
}
for ( int a=1; (mode[a] != 0) && ( a<6 ); a++ ){
if ( mode[a] == '+' ){
imode = ( ( imode | O_RDWR ) & ~( O_WRONLY | O_RDONLY) );
} else {
}
}
if ( f == 0 ){
int a;
if ( mlgl->pstream >= mini_FOPEN_MAX){ // Too many opened streams. Look for an empty storage location
for ( a=3; mlgl->stream[a]>=0; a++ )
if ( a >= mini_FOPEN_MAX ) //
return(0);
} else {
a = mlgl->pstream;
mlgl->pstream++;
}
f = &mlgl->stream[a];
} else { // freopen - error handling?
close(fileno(f));
}
if ( filename != 0 )
*f	 =  open( filename, imode, 0666 );
else
*f = fd;
if ( *f < 0 )
return(0);
return ( f ); //
}
#endif
#endif
#ifdef mini__match
#endif
#ifdef mini_setgrent
void setgrent(){
mlgl->groupfile.p = mlgl->groupfile.file;
mlgl->groupfile.p2 = (char**)(mlgl->groupfile.file+mlgl->groupfile.size);
}
#endif
#ifdef mini_err
#endif
#ifdef mini__die
#endif
#ifdef mini_dirname
char *dirname(char *s){
size_t i;
if (!s || !*s) return ".";
i = strlen(s)-1;
for (; s[i]=='/'; i--) if (!i) return "/";
for (; s[i]!='/'; i--) if (!i) return ".";
for (; s[i]=='/'; i--) if (!i) return "/";
s[i+1] = 0;
return s;
}
#endif
#ifdef mini_getpwnam
struct passwd *getpwnam(const char* name){
if ( !mlgl->passwdfile.file ){
if ( !userdb_open(&mlgl->passwdfile,PASSWDFILE) )
return(0);
} else {
if ( strcmp( mlgl->pwent.pw_name, name) == 0 )
return( &mlgl->pwent );
}
char *p = mlgl->passwdfile.file;
do {
char *pw_name = token_s( &mlgl->passwdfile,&p);
if ( strcmp( name, pw_name ) == 0 ){ // found
mlgl->pwent.pw_name = pw_name;
mlgl->pwent.pw_passwd = token_s( &mlgl->passwdfile,&p);
mlgl->pwent.pw_uid = token_i( &mlgl->passwdfile,&p);
mlgl->pwent.pw_gid = token_i( &mlgl->passwdfile,&p);
mlgl->pwent.pw_gecos = token_s( &mlgl->passwdfile,&p);
mlgl->pwent.pw_dir = token_s( &mlgl->passwdfile,&p);
mlgl->pwent.pw_shell = token_s( &mlgl->passwdfile,&p);
return(&mlgl->pwent);
}
for ( int a = 0; a<6; a++ )
token_s( &mlgl->passwdfile,&p);
} while ( p < (mlgl->passwdfile.file+mlgl->passwdfile.size) );
return(0); // not found
}
#endif
#ifdef mini_telldir
long telldir(DIR *dir){
return(dir->tell);
}
#endif
#ifdef mini_ptsname
#endif
#ifdef mini_fgetc
static inline int fgetc(FILE *F){
POINTER buf = 0;
#ifdef mini_ungetc
if ( *F >> 24 ){
int r =  *F >> 24;
*F =  *F & (~UNGETC_MASK);
return(r);
}
#endif
read(fileno(F), &buf, 1 );
return((int)buf);
}
#endif
#ifdef mini_calloc
void* calloc(int nmemb, int size){
char* p = malloc(size*nmemb);
if ( !p )
return(0);
char *pp=p;
#ifdef mini_OPTIMIZATIONS
#ifdef X64
for(char *e = p+size-7; pp<e;pp+=8)
*(long*)pp=0;
#endif
for(char *e = p+size-3; pp<e;pp+=4)
*(int*)pp=0;
#endif
for(char *e = p+size; pp<e;pp++)
*pp=0;
return(p);
}
#endif
#ifdef mini_initgroups
int initgroups(const char* user, gid_t group){
struct passwd* pw = getpwnam(user);
if ( !pw )
return(-1);
int grl[MAXGROUPS];
int c = getusergroups(user,MAXGROUPS,grl);
int ret = setgroups(c,grl);
if ( ret<0 )
return(-1);
if (setgid(pw->pw_gid) < 0 )
return(-1);
return(0);
}
#endif
#ifdef mini_fgetud
unsigned int fgetud(FILE* F){
unsigned int ret = 0;
char c = 0;
while ( ( c = (char)fgetc(F) ) && isdigit(c) ){
ret = ret*10 + (c-48);
}
return(ret);
}
#endif
#endif
#endif
#endif
#endif
#else
#ifdef LDSCRIPT_bloating
PHDRS {
text PT_LOAD FILEHDR PHDRS ;
}
ENTRY(_start)
SECTIONS
{
start = _start;
. = 0x08048000 + SIZEOF_HEADERS;
.text           :
{
*(.text.unlikely .text.*_unlikely)
*(.text.exit .text.exit.*)
*(.text.startup .text.startup.*)
*(.text.hot .text.hot.*)
*(.text .stub .text.* .gnu.linkonce.t.*)
*(.gnu.warning)
}
.bss            :
{
*(.dynbss)
*(.bss .bss.* .gnu.linkonce.b.*)
*(.bss)
*(.shstrtab)
*(COMMON)
*(.rodata .rodata.* .gnu.linkonce.r.*)
. = ALIGN(. != 0 ? 32 / 8 : 1);
_bssend = . ;
_brk = .;
} :text
/DISCARD/ : {
*(.note.GNU-stack)
*(.gnu_debuglink)
*(.gnu.lto_*)
*(.iplt*)
*(.igot*)
*(.rel*)
*(.comment)
*(.eh_frame)
*(.plt*)
*(.got.plt*)
*(.rel.*)
*(.note*)
}
}
#endif
#ifdef LDSCRIPT_default
PHDRS {
text PT_LOAD FILEHDR PHDRS FLAGS(0x5) ;
data PT_LOAD FLAGS(0x7);
bss PT_LOAD FLAGS(0x7);
stack PT_GNU_STACK FLAGS(0x6) ;
}
SECTIONS {
start = _start;
. = 0x08048000 + SIZEOF_HEADERS;
.text           :
{
*(.text.unlikely .text.*_unlikely)
*(.text._start)
*(.text.exit .text.exit.*)
*(.text._startup)
*(.text.main)
*(.text.hot .text.hot.*)
*(.text .stub .text.* .gnu.linkonce.t.*)
*(.gnu.warning)
*(.rodata .rodata.* .gnu.linkonce.r.*)
} :text
.data :
{
*(.data .data.*)
} : data
.bss           :
{
*(COMMON)
*(.dynbss)
*(.bss .bss.* .gnu.linkonce.b.*)
. = ALIGN(. != 0 ? 32 / 8 : 1);
} :bss
. = ALIGN(64 / 8);
_end = .;
PROVIDE (_end = .);
/DISCARD/ : {
*(.note.GNU-stack)
*(.note*)
*(.gnu_debuglink)
*(.gnu.lto_*)
*(.iplt*)
*(.igot*)
*(.rel*)
*(.comment)
*(.eh_frame)
*(.plt*)
*(.got.plt*)
*(.rel.*)
}
}
#endif
#ifdef LDSCRIPT_default_execstack
PHDRS {
text PT_LOAD FILEHDR PHDRS FLAGS(0x5) ;
data PT_LOAD FLAGS(0x7);
bss PT_LOAD FLAGS(0x7);
stack PT_GNU_STACK FLAGS(0x7) ;
}
SECTIONS {
start = _start;
. = 0x08048000 + SIZEOF_HEADERS;
.text           :
{
*(.text.unlikely .text.*_unlikely)
*(.text._start)
*(.text.exit .text.exit.*)
*(.text._startup)
*(.text.main)
*(.text.hot .text.hot.*)
*(.text .stub .text.* .gnu.linkonce.t.*)
*(.gnu.warning)
*(.rodata .rodata.* .gnu.linkonce.r.*)
} :text
.data :
{
*(.data .data.*)
} : data
.bss           :
{
*(COMMON)
*(.dynbss)
*(.bss .bss.* .gnu.linkonce.b.*)
. = ALIGN(. != 0 ? 32 / 8 : 1);
} :bss
. = ALIGN(64 / 8);
_end = .;
PROVIDE (_end = .);
/DISCARD/ : {
*(.note.GNU-stack)
*(.note*)
*(.gnu_debuglink)
*(.gnu.lto_*)
*(.iplt*)
*(.igot*)
*(.rel*)
*(.comment)
*(.eh_frame)
*(.plt*)
*(.got.plt*)
*(.rel.*)
}
}
#endif
#ifdef LDSCRIPT_exec
PHDRS {
text PT_LOAD FILEHDR PHDRS FLAGS(0x7) ;
data PT_LOAD FLAGS(0x7);
bss PT_LOAD FLAGS(0x7);
stack PT_GNU_STACK FLAGS(0x7) ;
}
SECTIONS {
start = _start;
. = 0x08048000 + SIZEOF_HEADERS;
.text           :
{
*(.text.unlikely .text.*_unlikely)
*(.text._start)
*(.text.exit .text.exit.*)
*(.text._startup)
*(.text.main)
*(.text.hot .text.hot.*)
*(.text .stub .text.* .gnu.linkonce.t.*)
*(.gnu.warning)
*(.rodata .rodata.* .gnu.linkonce.r.*)
} :text
.data :
{
*(.data .data.*)
} : data
.bss           :
{
*(COMMON)
*(.dynbss)
*(.bss .bss.* .gnu.linkonce.b.*)
. = ALIGN(. != 0 ? 32 / 8 : 1);
} :bss
. = ALIGN(64 / 8);
_end = .;
PROVIDE (_end = .);
/DISCARD/ : {
*(.note.GNU-stack)
*(.note*)
*(.gnu_debuglink)
*(.gnu.lto_*)
*(.iplt*)
*(.igot*)
*(.rel*)
*(.comment)
*(.eh_frame)
*(.plt*)
*(.got.plt*)
*(.rel.*)
}
}
#endif
#ifdef LDSCRIPT_onlytext
PHDRS {
text PT_LOAD FILEHDR PHDRS;
stack PT_GNU_STACK FLAGS(0x6) ;
}
ENTRY(_start)
SECTIONS
{
start = _start;
. = 0x08048000 + SIZEOF_HEADERS;
.text           :
{
*(.text.unlikely .text.*_unlikely)
*(.text._start .text._start.*)
*(.text._exit .text._exit.*)
*(.text.__exit .text.__exit.*)
*(.text._startup .text._startup.*)
*(.text.main .text.main.*)
*(.text.cexit)
*(.text.hot .text.hot.*)
*(.text .stub .text.* .gnu.linkonce.t.*)
*(.gnu.warning)
*(.dynbss)
*(.bss .bss.* .gnu.linkonce.b.*)
*(COMMON)
*(.rodata .rodata.* .gnu.linkonce.r.*)
*(.data .data.*)
} :text
/DISCARD/ : {
*(.note.GNU-stack)
*(.note*)
*(.gnu_debuglink)
*(.gnu.lto_*)
*(.iplt*)
*(.igot*)
*(.rel*)
*(.comment)
*(.eh_frame)
*(.plt*)
*(.got.plt*)
*(.rel.*)
*(*)
}
}
#endif
#ifdef LDSCRIPT_onlytext_tiny
PHDRS {
text PT_LOAD FILEHDR PHDRS;
}
ENTRY(_start)
SECTIONS
{
start = _start;
. = 0x08048000 + SIZEOF_HEADERS;
.text           :
{
*(.text.unlikely .text.*_unlikely)
*(.text._start .text._start.*)
*(.text._exit .text._exit.*)
*(.text.__exit .text.__exit.*)
*(.text._startup .text._startup.*)
*(.text.main .text.main.*)
*(.text.cexit)
*(.text.hot .text.hot.*)
*(.text .stub .text.* .gnu.linkonce.t.*)
*(.gnu.warning)
*(.dynbss)
*(.bss .bss.* .gnu.linkonce.b.*)
*(COMMON)
*(.rodata .rodata.* .gnu.linkonce.r.*)
*(.data .data.*)
} :text
/DISCARD/ : {
*(.note.GNU-stack)
*(.note*)
*(.gnu_debuglink)
*(.gnu.lto_*)
*(.iplt*)
*(.igot*)
*(.rel*)
*(.comment)
*(.eh_frame)
*(.plt*)
*(.got.plt*)
*(.rel.*)
*(*)
}
}
#endif
#ifdef LDSCRIPT_text_and_bss
PHDRS {
text PT_LOAD FILEHDR PHDRS FLAGS(0x5) ;
bss PT_LOAD FLAGS(0x7);
stack PT_GNU_STACK FLAGS(0x6) ;
}
ENTRY(_start)
SECTIONS
{
start = _start;
. = 0x08048000 + SIZEOF_HEADERS;
.text           :
{
*(.text.unlikely .text.*_unlikely)
*(.text._start)
*(.text.exit .text.exit.*)
*(.text._startup)
*(.text.main)
*(.text.hot .text.hot.*)
*(.text .stub .text.* .gnu.linkonce.t.*)
*(.gnu.warning)
} :text
.bss           :
{
*(.dynbss)
*(.bss .bss.* .gnu.linkonce.b.*)
*(COMMON)
*(.data .data.*)
*(.rodata .rodata.* .gnu.linkonce.r.*)
} :bss
. = ALIGN(64 / 8);
_end = .;
PROVIDE (_end = .);
/DISCARD/ : {
*(.note.GNU-stack)
*(.note*)
*(.gnu_debuglink)
*(.gnu.lto_*)
*(.iplt*)
*(.igot*)
*(.rel*)
*(.comment)
*(.eh_frame)
*(.plt*)
*(.got.plt*)
*(.rel.*)
}
}
#endif
#ifdef LDSCRIPT_textandbss
PHDRS {
text PT_LOAD FILEHDR PHDRS FLAGS(0x5) ;
bss PT_LOAD FLAGS(0x7);
stack PT_GNU_STACK FLAGS(0x6) ;
}
ENTRY(_start)
SECTIONS
{
start = _start;
. = 0x08048000 + SIZEOF_HEADERS;
.text           :
{
*(.text.unlikely .text.*_unlikely)
*(.text._start)
*(.text.exit .text.exit.*)
*(.text._startup)
*(.text.main)
*(.text.hot .text.hot.*)
*(.text .stub .text.* .gnu.linkonce.t.*)
*(.gnu.warning)
} :text
.bss           :
{
*(.dynbss)
*(.bss .bss.* .gnu.linkonce.b.*)
*(COMMON)
*(.data .data.*)
*(.rodata .rodata.* .gnu.linkonce.r.*)
} :bss
. = ALIGN(64 / 8);
_end = .;
PROVIDE (_end = .);
/DISCARD/ : {
*(.note.GNU-stack)
*(.note*)
*(.gnu_debuglink)
*(.gnu.lto_*)
*(.iplt*)
*(.igot*)
*(.rel*)
*(.comment)
*(.eh_frame)
*(.plt*)
*(.got.plt*)
*(.rel.*)
}
}
#endif
#endif
#endif
