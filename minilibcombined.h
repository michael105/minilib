// f: include/minilib_header.h

// Current path: /home/micha/prog/minilib

// Path: include  Name minilib_header.h
// f: include/minilib_header.h
#ifndef minilib_header_h
#define minilib_header_h



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

#ifndef stdin
#define stdin 0
#endif
#ifndef stdout
#define stdout 1
#endif
#ifndef stderr
#define stderr 2
#endif




// XXXXXXXXXXXXXXXXXX*************** file: ../macros/vararg.h 

// Current path: /home/micha/prog/minilib

// Path: ../macros  Name vararg.h
// f: ../macros/vararg.h
// O: include/../macros/vararg.h
#ifndef vararg_h
#define vararg_h

#define VARARG(A,B) ((A+0) ?: B )
#define SHIFT(A,...) A
#define ARG(A,...) __VA_ARGS__

#endif


//#ifdef mini_syscall
// XXXXXXXXXXXXXXXXXX*************** file: syscall.h 

// Current path: /home/micha/prog/minilib

// f: syscall.h
// O: include/syscall.h
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
#include <sys/syscall.h>

#else

#define NCONST 0
#define SCALL(call) __NR_##call

#ifdef X64
#include <sys/syscall.h>
#else
// XXXXXXXXXXXXXXXXXX*************** file: i386syscalls.h 

// Current path: /home/micha/prog/minilib

// f: i386syscalls.h
// O: include/i386syscalls.h
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

// memory clobber is needed, gcc optimizes syscalls very likely away without
//#define __callend : "rcx" )
#define __callend : "memory" )

// Seems linux x86_64 has same convention as osx darwin
#ifdef X64
//(also osx)
#define __SYSCALL_ASM(ret,call) asm volatile ("syscall" : "=a" (ret)  : "a" ( (call | NCONST ) )
#else
#ifdef mini_vsyscalls
#define __SYSCALL_ASM(ret,call) asm volatile ("call *__mini_vsys" : "=a" (ret)  : "a" (call)
#else
//linux32bit
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
#define DEF_syscall( name, argcount, ... ) static inline \
		int __attribute__((always_inline)) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, (SCALL(name) | NCONST ) );\
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}
#else
#define DEF_syscall( name, argcount, ... ) static inline \
		int __attribute__((always_inline)) name( __VA_ARGS__ ){\
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
#define DEF_syscallret( name, ret, argcount, ... ) static inline \
		int __attribute__((always_inline)) name( __VA_ARGS__ ){\
				__DO_syscall( argcount, SCALL(name));\
				if ( sysret<0 ){\
						errno = -sysret;\
						return(-1);}\
				return(ret);\
		}\






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
//#endif


// XXXXXXXXXXXXXXXXXX*************** file: timeval.h 

// Current path: /home/micha/prog/minilib

// f: timeval.h
// O: include/timeval.h
#ifndef timeval_h
#define timeval_h
// XXXXXXXXXXXXXXXXXX*************** file: time_t.h 

// Current path: /home/micha/prog/minilib

// f: time_t.h
// O: include/time_t.h
#ifndef type_t_h
#define type_t_h
typedef long time_t;
#endif
//struct timeval { time_t tv_sec; long tv_usec; };

struct timezone {
		int     tz_minuteswest; /*	minutes	west of	Greenwich */
		int     tz_dsttime;     /*	type of	dst correction */
};
#endif
// XXXXXXXXXXXXXXXXXX*************** file: syscall_stubs.h 

// Current path: /home/micha/prog/minilib

// f: syscall_stubs.h
// O: include/syscall_stubs.h
#ifndef SYSCALL_STUBS
#define SYSCALL_STUBS
/*
 These are just wrapped syscalls.
 errno is set, anyway.

 The arguments need to be named a1,a2,..

*/


// XXXXXXXXXXXXXXXXXX*************** file: syscall.h 

// Current path: /home/micha/prog/minilib

// YYYYYYYYYYYYYY   Already included: syscall.h
// f: syscall.h
// O: include/syscall.h
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
#include <sys/syscall.h>

#else

#define NCONST 0
#define SCALL(call) __NR_##call

#ifdef X64
#include <sys/syscall.h>
#else
// XXXXXXXXXXXXXXXXXX*************** file: i386syscalls.h 

// Current path: /home/micha/prog/minilib

// YYYYYYYYYYYYYY   Already included: i386syscalls.h
// f: i386syscalls.h
// O: include/i386syscalls.h
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

// memory clobber is needed, gcc optimizes syscalls very likely away without
//#define __callend : "rcx" )
#define __callend : "memory" )

// Seems linux x86_64 has same convention as osx darwin
#ifdef X64
//(also osx)
#define __SYSCALL_ASM(ret,call) asm volatile ("syscall" : "=a" (ret)  : "a" ( (call | NCONST ) )
#else
#ifdef mini_vsyscalls
#define __SYSCALL_ASM(ret,call) asm volatile ("call *__mini_vsys" : "=a" (ret)  : "a" (call)
#else
//linux32bit
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
#define DEF_syscall( name, argcount, ... ) static inline \
		int __attribute__((always_inline)) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, (SCALL(name) | NCONST ) );\
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}
#else
#define DEF_syscall( name, argcount, ... ) static inline \
		int __attribute__((always_inline)) name( __VA_ARGS__ ){\
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
#define DEF_syscallret( name, ret, argcount, ... ) static inline \
		int __attribute__((always_inline)) name( __VA_ARGS__ ){\
				__DO_syscall( argcount, SCALL(name));\
				if ( sysret<0 ){\
						errno = -sysret;\
						return(-1);}\
				return(ret);\
		}\






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
// XXXXXXXXXXXXXXXXXX*************** file: sys/types.h 

// Current path: /home/micha/prog/minilib

// Path: sys  Name types.h
// f: sys/types.h
// O: include/sys/types.h
// O: src/sys/types.h
// O: asm/sys/types.h
// O: macros/sys/types.h
// O: headers/common/sys/types.h
#ifndef	_SYS_TYPES_H
#define	_SYS_TYPES_H
#ifdef __cplusplus
extern "C" {
#endif

#ifndef POINTER
#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER int
#endif
#endif


#include <bits/alltypes.h>

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
#include <endian.h>

#define blkcnt64_t blkcnt_t
#define fsblkcnt64_t fsblkcnt_t
#define fsfilcnt64_t fsfilcnt_t
#define ino64_t ino_t
#define off64_t off_t

#ifdef __cplusplus
}
#endif
#endif
// XXXXXXXXXXXXXXXXXX*************** file: sys/syscall.h 

// Current path: /home/micha/prog/minilib

// Path: sys  Name syscall.h
// f: sys/syscall.h
// O: include/sys/syscall.h
// O: src/sys/syscall.h
// O: asm/sys/syscall.h
// O: macros/sys/syscall.h
// O: headers/common/sys/syscall.h
// O: headers/linux_x64/sys/syscall.h
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

static int sysret;
extern int errno;



DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )

DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

//rename a1=oldpath a2=newpath
DEF_syscall(rename,2, const char* a1, const char* a2 )		


#ifndef OSX
DEF_syscallret(time,*a1,1,unsigned int *a1 )
#else

#endif




#endif


#ifdef mini_read
// XXXXXXXXXXXXXXXXXX*************** file: read.h 

// Current path: /home/micha/prog/minilib

// f: read.h
// O: include/read.h
#ifndef minilib_read_h
#define minilib_read_h

//#include "syscall.h"
// XXXXXXXXXXXXXXXXXX*************** file: ../macros/overrun.h 

// Current path: /home/micha/prog/minilib

// Path: ../macros  Name overrun.h
// f: ../macros/overrun.h
// O: include/../macros/overrun.h
// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
// XXXXXXXXXXXXXXXXXX*************** file: ../include/exit.h 

// Current path: /home/micha/prog/minilib

// Path: ../include  Name exit.h
// f: ../include/exit.h
// O: include/../include/exit.h
#ifndef minilib_exit_h
#define minilib_exit_h

//#include "syscall.h"
//#undef write
//#undef exit
static inline void __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
}


#endif
// XXXXXXXXXXXXXXXXXX*************** file: ../include/mprints.h 

// Current path: /home/micha/prog/minilib

// Path: ../include  Name mprints.h
// f: ../include/mprints.h
// O: include/../include/mprints.h
#ifndef mprints_h
#define mprints_h
extern int _mprints(char*msg,...);
#define mprints(...) _mprints(__VA_ARGS__,0)
#define mprintl(...) _mprints(__VA_ARGS__,"\n",0)
#define mprintsl(...) _mprints(__VA_ARGS__,"\n",0)
//TODO: Macro: define print(str) write(stdout,str,sizeof(str)-1)
//#define print(...) _mprints(__VA_ARGS__)
#endif
#define MINI_TEST_OVERRUN(pos) if (pos > mini_buf){\
		mprintsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif

static inline int __attribute__((always_inline)) read( int fd, void* buf, int len ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
		//MINI_TEST_OVERRUN(len);
		int ret;
		syscall3(ret,SCALL(read),fd,(POINTER)buf,len);
		return(ret);
}


#endif
#endif


#ifdef mini_udiv
//struct div_t { int quot, rem; };
struct udiv_t { unsigned int quot, rem; };
#endif
//inline div_t div( int numer, int denom ){
//		asm ("div" : 

#ifdef mini_mfprintf
#define mini_mprintf
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
#define mini_itohex
#define mini_itodec  // also conversion %d in printf
#define mini_ditodec  // also conversion %d in printf

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
// XXXXXXXXXXXXXXXXXX*************** file: mprints.h 

// Current path: /home/micha/prog/minilib

// f: mprints.h
// O: include/mprints.h
#ifndef mprints_h
#define mprints_h
extern int _mprints(char*msg,...);
#define mprints(...) _mprints(__VA_ARGS__,0)
#define mprintl(...) _mprints(__VA_ARGS__,"\n",0)
#define mprintsl(...) _mprints(__VA_ARGS__,"\n",0)
//TODO: Macro: define print(str) write(stdout,str,sizeof(str)-1)
//#define print(...) _mprints(__VA_ARGS__)
#endif
#endif

#ifdef mini_putchar
#define mini_fputc
#define putchar(c) fputc(c,stdout)
#endif

#ifdef mini_fputc
// XXXXXXXXXXXXXXXXXX*************** file: fputc.h 

// Current path: /home/micha/prog/minilib

// f: fputc.h
// O: include/fputc.h
#ifndef fputc_c
#define fputc_c

// XXXXXXXXXXXXXXXXXX*************** file: write.h 

// Current path: /home/micha/prog/minilib

// f: write.h
// O: include/write.h
#ifndef minilib_write_h
#define minilib_write_h

//#include "syscall.h"
//#undef write
/*static inline int __attribute__((always_inline)) write( int fd, const char *s, int len ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
		int ret;
		syscall3(ret,__NR_write,fd,(int)s,len);
//  asm volatile ("call *__mini_vsys"
//					: "=a" (ret): "a" (4) , "b" (fd), "c" ((int)s), "d" (len) : "memory" ); //WORKS! FINALLY

		return(ret);
}*/
// +64 bytes.
DEF_syscall(write,3,int a1,const void *a2, int a3 )


/*volatile static inline int __attribute__((always_inline)) write( register int fd, const char *s, int len ){
		register int a asm("a") = 4;
		register int b asm("b") = fd;
		register int c asm("c") = (int)s;
		register int d asm("d") = len;
		__asm__ volatile( "call *__mini_vsys");

		return(0);
}*/


#endif


int fputc(int c, int fd){
		write(fd, &c, 1);
		return(c);
}



#endif
#endif

#ifdef mini_fputs
// XXXXXXXXXXXXXXXXXX*************** file: fputs.h 

// Current path: /home/micha/prog/minilib

// f: fputs.h
// O: include/fputs.h
#ifndef fputs_c
#define fputs_c

// XXXXXXXXXXXXXXXXXX*************** file: write.h 

// Current path: /home/micha/prog/minilib

// YYYYYYYYYYYYYY   Already included: write.h
// f: write.h
// O: include/write.h
#ifndef minilib_write_h
#define minilib_write_h

//#include "syscall.h"
//#undef write
/*static inline int __attribute__((always_inline)) write( int fd, const char *s, int len ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
		int ret;
		syscall3(ret,__NR_write,fd,(int)s,len);
//  asm volatile ("call *__mini_vsys"
//					: "=a" (ret): "a" (4) , "b" (fd), "c" ((int)s), "d" (len) : "memory" ); //WORKS! FINALLY

		return(ret);
}*/
// +64 bytes.
DEF_syscall(write,3,int a1,const void *a2, int a3 )


/*volatile static inline int __attribute__((always_inline)) write( register int fd, const char *s, int len ){
		register int a asm("a") = 4;
		register int b asm("b") = fd;
		register int c asm("c") = (int)s;
		register int d asm("d") = len;
		__asm__ volatile( "call *__mini_vsys");

		return(0);
}*/


#endif
// XXXXXXXXXXXXXXXXXX*************** file: src/mstrlen.c 

// Current path: /home/micha/prog/minilib

// Path: src  Name mstrlen.c
// f: src/mstrlen.c
#ifndef strlen_c
#define strlen_c
int strlen(const char*str){
		int a = 0;
		while ( str[a] != 0 ){
				a++;
		}
		return (a);
}


#endif

int fputs(const char *c, int fd){
		return(write(fd, c, strlen(c)));
}



#endif
#endif



#ifdef mini_puts
#define puts(a1) printl(a1)
#define mini_print
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
// XXXXXXXXXXXXXXXXXX*************** file: exit.h 

// Current path: /home/micha/prog/minilib

// f: exit.h
// O: include/exit.h
#ifndef minilib_exit_h
#define minilib_exit_h

//#include "syscall.h"
//#undef write
//#undef exit
static inline void __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
}


#endif
#endif

#ifdef mini_write
// XXXXXXXXXXXXXXXXXX*************** file: write.h 

// Current path: /home/micha/prog/minilib

// YYYYYYYYYYYYYY   Already included: write.h
// f: write.h
// O: include/write.h
#ifndef minilib_write_h
#define minilib_write_h

//#include "syscall.h"
//#undef write
/*static inline int __attribute__((always_inline)) write( int fd, const char *s, int len ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
		int ret;
		syscall3(ret,__NR_write,fd,(int)s,len);
//  asm volatile ("call *__mini_vsys"
//					: "=a" (ret): "a" (4) , "b" (fd), "c" ((int)s), "d" (len) : "memory" ); //WORKS! FINALLY

		return(ret);
}*/
// +64 bytes.
DEF_syscall(write,3,int a1,const void *a2, int a3 )


/*volatile static inline int __attribute__((always_inline)) write( register int fd, const char *s, int len ){
		register int a asm("a") = 4;
		register int b asm("b") = fd;
		register int c asm("c") = (int)s;
		register int d asm("d") = len;
		__asm__ volatile( "call *__mini_vsys");

		return(0);
}*/


#endif
#endif

#ifdef mini_isprint
// XXXXXXXXXXXXXXXXXX*************** file: isprint.h 

// Current path: /home/micha/prog/minilib

// f: isprint.h
// O: include/isprint.h
#ifndef mini_isprint_h
#define mini_isprint_h
#define misprint(A) isprint(A)


static inline int __attribute__((always_inline)) isprint(const char c){
		if ( (c>31) && ( c<127 ))
				return(1);
		return(0);
}


#endif

#endif

#ifdef mini_isspace
extern int isspace(int c);
#endif





#ifdef mini_open
// XXXXXXXXXXXXXXXXXX*************** file: open.h 

// Current path: /home/micha/prog/minilib

// f: open.h
// O: include/open.h
#ifndef minilib_open_h
#define minilib_open_h

//#include "syscall.h"
// XXXXXXXXXXXXXXXXXX*************** file: filemodes.h 

// Current path: /home/micha/prog/minilib

// f: filemodes.h
// O: include/filemodes.h
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


// XXXXXXXXXXXXXXXXXX*************** file: ../include/stdarg.h 

// Current path: /home/micha/prog/minilib

// Path: ../include  Name stdarg.h
// f: ../include/stdarg.h
// O: include/../include/stdarg.h
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


//#undef open
static inline int open( const char *s, int flags, ... ){
		int ret;
		va_list args;
		va_start(args,flags);
		int mode = va_arg(args,int);
		va_end(args);

		syscall3(ret,SCALL(open),(POINTER)s,flags,mode);
		return(ret);
}


static inline int __attribute__((always_inline)) creat( const char *s, int mode ){
		return(open( s, O_CREAT|O_WRONLY|O_TRUNC, mode) );
}


#endif
#ifndef mini_filemodes
#define mini_filemodes
#endif
#ifndef mini_errno
#define mini_errno
#endif
#endif

#ifdef mini_lseek
// XXXXXXXXXXXXXXXXXX*************** file: lseek.h 

// Current path: /home/micha/prog/minilib

// f: lseek.h
// O: include/lseek.h
#ifndef mini_lseek_h
#define mini_lseek_h

//#include "syscall.h"

#define SEEK_SET        0       /* seek relative to beginning of file */
#define SEEK_CUR        1       /* seek relative to current file position */
#define SEEK_END        2       /* seek relative to end of file */
#define SEEK_MAX        SEEK_END

static int sysret;
extern int errno;

DEF_syscallret(lseek,a1,3,unsigned int a1, int a2, int a3 )

DEF_syscall(ftruncate,2,unsigned int a1, unsigned int a2 )
DEF_syscall(fsync,1,int a1 )




#endif

#endif

#ifdef mini_close
// XXXXXXXXXXXXXXXXXX*************** file: close.h 

// Current path: /home/micha/prog/minilib

// f: close.h
// O: include/close.h
#ifndef minilib_close_h
#define minilib_close_h

//#include "syscall.h"
static inline int __attribute__((always_inline)) close( int fd ){
		int ret;
		syscall1(ret,SCALL(close),(int)fd);
		return(ret);
}


#endif
#endif



#ifdef mini_filemodes
// XXXXXXXXXXXXXXXXXX*************** file: filemodes.h 

// Current path: /home/micha/prog/minilib

// YYYYYYYYYYYYYY   Already included: filemodes.h
// f: filemodes.h
// O: include/filemodes.h
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

#endif

//#ifdef mini_errno / No reason to not define errno Macros by default
// XXXXXXXXXXXXXXXXXX*************** file: errno.h 

// Current path: /home/micha/prog/minilib

// f: errno.h
// O: include/errno.h
#ifndef mini_errno_h
#define mini_errno_h
#define EPERM            1
#define ENOENT           2
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
//extern int errno;
#endif
//#endif



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
// XXXXXXXXXXXXXXXXXX*************** file: select.h 

// Current path: /home/micha/prog/minilib

// f: select.h
// O: include/select.h
#ifndef select_h
#define select_h
// XXXXXXXXXXXXXXXXXX*************** file: timeval.h 

// Current path: /home/micha/prog/minilib

// YYYYYYYYYYYYYY   Already included: timeval.h
// f: timeval.h
// O: include/timeval.h
#ifndef timeval_h
#define timeval_h
// XXXXXXXXXXXXXXXXXX*************** file: time_t.h 

// Current path: /home/micha/prog/minilib

// YYYYYYYYYYYYYY   Already included: time_t.h
// f: time_t.h
// O: include/time_t.h
#ifndef type_t_h
#define type_t_h
typedef long time_t;
#endif
//struct timeval { time_t tv_sec; long tv_usec; };

struct timezone {
		int     tz_minuteswest; /*	minutes	west of	Greenwich */
		int     tz_dsttime;     /*	type of	dst correction */
};
#endif
//#include "syscall.h"


// from musl
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

// end of musl 


static inline	int __attribute__((always_inline)) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait){
		int ret;
		syscall5(ret, SCALL(select),&fd,readfd,(POINTER)writefd,(POINTER)exceptfd,(POINTER) wait);
		return(ret);
}
/*
		//return(syscall5(__NR_select,(long)fd,(long)readfd,(long)writefd,(long)exceptfd, (long)wait));
		int ret;
		syscall5(ret,__NR_select,&fd,readfd,writefd,exceptfd, wait);
		return(ret);
		//return(syscall5(__NR_select,fd,readfd,,0,0));
}
*/



		//int pselect (int, fd_set *, fd_set *, fd_set *, const struct timespec *, const sigset_t *);


#endif

#endif

#ifdef mini_epoll
// XXXXXXXXXXXXXXXXXX*************** file: epoll.h 

// Current path: /home/micha/prog/minilib

// f: epoll.h
// O: include/epoll.h
#ifndef epoll_h
#define epoll_h

// TODO: doesn't ork

typedef struct { unsigned long __bits[128/sizeof(long)]; } sigset_t;

#define EPOLL_CLOEXEC 02000000
#define EPOLL_NONBLOCK 04000

enum EPOLL_EVENTS { __EPOLL_DUMMY };
#define EPOLLIN 0x001
#define EPOLLPRI 0x002
#define EPOLLOUT 0x004
#define EPOLLRDNORM 0x040
#define EPOLLRDBAND 0x080
#define EPOLLWRNORM 0x100
#define EPOLLWRBAND 0x200
#define EPOLLMSG 0x400
#define EPOLLERR 0x008
#define EPOLLHUP 0x010
#define EPOLLRDHUP 0x2000
#define EPOLLONESHOT (1U<<30)
#define EPOLLET (1U<<31)

#define EPOLL_CTL_ADD 1
#define EPOLL_CTL_DEL 2
#define EPOLL_CTL_MOD 3

typedef union epoll_data {
		  void *ptr;
			  int fd;
				int u32;
				long u64;
} epoll_data_t;

struct epoll_event {
		  int events;
			  epoll_data_t data;
} __attribute__ ((__packed__));


static inline int epoll_create(int size)
{
		  return syscall1(SCALL(epoll_create), size);
}

static inline int epoll_ctl(int fd, int op, int fd2, struct epoll_event *ev)
{
		  return syscall4(SCALL(epoll_ctl), fd, op, fd2, (int)ev);
}

static inline int epoll_wait(int fd, struct epoll_event *ev, int cnt, int to)
{
		  return syscall4(SCALL(epoll_wait), fd, (int)ev, cnt, to);
}



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

struct pollfd
{
		        int fd;
		        short events;
		        short revents;
};


static inline int poll(struct pollfd *fds, nfds_t cnt, int timeout)
{
		  return syscall3(SCALL(epoll_wait), (int)fds, (int)cnt, timeout);
}







#endif
#endif

#ifdef mini_mstrcmp
extern int strcmp(const char*,const char*);
extern int strncmp(const char*,const char*,int);
extern int memcmp(const void*,const void*,int);
#endif

#ifdef mini_strcat
extern char *strcat(char *dest, const char *src )
#define mini_mstrlen
#endif

#ifdef mini_mstrlen
extern int strlen(const char*);
#endif

#ifdef mini_memset
extern void *memset( void *s, int c, int n);
#endif

#ifdef mini_strncpy
#ifndef strncpy
#define strncpy(a,b,c) memcpy(a,b,c)
#define mini_memcpy
#endif
#endif

#ifdef mini_memcpy
#ifndef memcpy
extern void *memcpy( void *d, const void *s, int n);
#endif
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
extern void* malloc(POINTER size);
#endif
#ifdef OSX
#ifndef PROTO_READ
#define	PROT_NONE	0x00	/* [MC2] no permissions */
#define	PROT_READ	0x01	/* [MC2] pages can be read */
#define	PROT_WRITE	0x02	/* [MC2] pages can be written */
#define	PROT_EXEC	0x04	/* [MC2] pages can be executed */

#define	MAP_SHARED	0x0001		/* [MF|SHM] share changes */
#define	MAP_PRIVATE	0x0002		/* [MF|SHM] changes are private */

#define	MAP_FIXED	 0x0010	/* [MF|SHM] interpret addr exactly */
#define	MAP_RENAME	 0x0020	/* Sun: rename private pages to file */
#define	MAP_NORESERVE	 0x0040	/* Sun: don't reserve needed swap area */
#define	MAP_RESERVED0080 0x0080	/* previously unimplemented MAP_INHERIT */
#define	MAP_NOEXTEND	 0x0100	/* for MAP_FILE, don't change file size */
#define	MAP_HASSEMAPHORE 0x0200	/* region may contain semaphores */
#define MAP_NOCACHE	 0x0400 /* don't cache pages for this mapping */
#define MAP_JIT		 0x0800 /* Allocate a region that will be used for JIT purposes */

/*
 * Mapping type
 */
#define	MAP_FILE	0x0000	/* map from file (default) */
#define	MAP_ANON	0x1000	/* allocated from memory, swap space */
#define	MAP_ANONYMOUS	MAP_ANON



#endif
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


static inline int XOR(int i1, int i2 ){
		asm volatile ( "xor %2,%0" : "=m" (i1) : "m" (i1), "r" (i2) );
		return(i1);
}



#ifdef mini_overwrite
#define printf(...) mprintf(__VA_ARGS__)
#define fprintf(...) mfprintf(__VA_ARGS__)
#define sprintf(...) msprintf(__VA_ARGS__)
#define fileno(F) F
//#define strcmp(A,B) mstrcmp(A,B)
//#define strncmp(A,B,LEN) mstrncmp(A,B,LEN)
//#define strlen(A) mstrlen(A)
#endif


#endif
