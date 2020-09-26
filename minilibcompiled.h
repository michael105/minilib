#ifdef UNDEF
ifdef UNDEF

This file is part of minilib,
a C system library with a focus on small sizes
and being configurable.
(www.github.com/michael105/minilib)


-------------------------------------------------
 Copyright (c) 2012-2020, Michael (misc) Myer 
 (misc.myer@zoho.com, www.github.com/michael105)
 Donations welcome: Please contact me.
 All rights reserved.
-------------------------------------------------


I did this minilib out of enthuiasm.
One side, I`d like to have this project being opensource.
On the other hand, I spent really much time with the development.
In an ideal world, someone would sponsor me for this time.
It is, however, not an ideal world we are living in.
Therefore I do have to insist on attributions and what
I`d like to call `fair use`.

In short, you are allowed to do with this project what you wish,
as long you show the copyright notice at a prominent place, 
and include the file NOTICE in distributions.

That`s the intention of this license,
which I`d like to name "Fair use with attribution".



License

   The terms `minilib`, `source code`, `redistribution` or `linked with`
   apply to the minilib in full as well as to parts of minilib
  
   All files belonging to this project are subject to this license,
   besides files, where within the header explicitely other licensing terms are noted
    
   Michael (misc) Myer is a Pseudonym. When your local laws don`t permit usage of pseudonyms,
   one of the conditions below would be not legal, or you do not comply to this license,
   you may neither use minilib nor parts of this project.
   The author is under this condition still the owner of this software.
   Please contact me for differing licensing terms in this case,
   and explain your situation
  

Redistribution, use and derived works in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above full notice,
   the file NOTICE, this list of conditions and the following disclaimer in 
   the documentation and other materials provided with the distribution

 * Redistributions in binary form must reproduce the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer in 
   the documentation and other materials provided with the distribution

 * Software linked with, or derived from minilib must reproduce 
   the file NOTICE, this list of conditions and the following disclaimer
   in the documentation, and other materials

 * Applications and software linked with, or derived from minilib must 
   in addition reproduce one of the according full notices below for derived or 
	 linked works within a documentation accessible at runtime:
   - `--help` documentation
   - online manual for web applications
   - Alternatively within a for every user clearly visible and
	   readable message at the application startup
 
 * Software and applications without a textual or graphical user interface
   linked with, or derived from minilib must 
   reproduce the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer in 
   the documentation and all other materials like advertisements, 
   manuals, datasheets, etc.
	 
 * Neither the name of the minilib nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission
  
 * You inform me with an email with the subject `minilib usage` 
   about your usage of minilib and agree to a possible announcement 
	 with your and/or your companie`s name at the homepage of minilib


Disclaimer:

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

End of the license.


Please contact me, if you are in need of differing licensing terms.


Notices:


(Notice for linked works)
................................................
Linked with minilib,
Copyright (c) 2012-2021, Michael (misc) Myer 
(misc.myer@zoho.com, www.github.com/michael105)
Donations welcome: Please contact me.
All rights reserved.
................................................


(Notice for derived works)
................................................
Based on minilib,
Copyright (c) 2012-2021, Michael (misc) Myer 
(misc.myer@zoho.com, www.github.com/michael105)
Donations welcome: Please contact me.
All rights reserved.
................................................


Some files in the folders headers and contrib have other licensing terms.
Please look at the sources.


endif
#endif
#ifndef minilibcompiled_h
#define minilibcompiled_h
#ifndef LDSCRIPT
#ifndef included_minilib_h
#define included_minilib_h
#ifdef HEADERGUARDS
#ifndef mini_HEADERGUARDS
#define mini_HEADERGUARDS
#endif
#endif
#ifndef mini_environ
#ifdef mini_getenv
#define mini_environ
#endif
#ifdef mini_system
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
#define _SYS_TTYCHARS_H
#define _SYS_TTYDEFAULTS_H
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
#define mini_FOPEN_MAX 16
#ifndef common_allheaders_h
#define common_allheaders_h
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
#ifndef termios_xxxxx
#define termios_xxxxx
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
#ifndef ctype_h
#define ctype_h
#define isalpha(a) (0 ? 1 : (((unsigned)(a)|32)-'a') < 26)
#define isdigit(a) (0 ? 1 : ((unsigned)(a)-'0') < 10)
#define islower(a) (0 ? 1 : ((unsigned)(a)-'a') < 26)
#define isupper(a) (0 ? 1 : ((unsigned)(a)-'A') < 26)
#define isprint(a) (0 ? 1 : ((unsigned)(a)-(0x20)) < 0x5f)
#define isgraph(a) (0 ? 1 : ((unsigned)(a)-0x21) < 0x5e)
#define isspace(a) ((a==' ')||(a=='\t')||(a=='\n')||(a=='\f')||(a=='\r')||(a=='\v'))
#define _tolower(a) ((a)|0x20)
#define tolower(a) ((a)|0x20)
#define _toupper(a) ((a)&0x5f)
#define toupper(a) ((a)&0x5f)
#define isascii(a) (0 ? isascii(a) : (unsigned)(a) < 128)
#endif
#ifndef mini_ELF_H
#define mini_ELF_H
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
typedef i