#ifndef minilibcombined_c
#define minilibcombined_c

// f: minilib_implementation.c

// Current path: /home/micha/prog/readkey/minilib


#ifndef minilib_header_h
// XXXXXXXXXXXXXXXXXX*************** file: include/minilib_header.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: include  Name minilib_header.h
// O: include/minilib_header.h
#ifndef minilib_header_h
#define minilib_header_h



#ifdef X64
#define POINTER long int
#else
#define POINTER int
#endif

#ifndef uint32_t
#define uint32_t unsigned int
#endif

#ifndef uint8_t
#define uint8_t unsigned char
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

// Current path: /home/micha/prog/readkey/minilib

// Path: ../macros  Name vararg.h
// O: include/vararg.h
// O: src/vararg.h
// O: asm/vararg.h
// O: macros/vararg.h
#ifndef vararg_h
#define vararg_h

#define VARARG(A,B) ((A+0) ?: B )
#define SHIFT(A,...) A
#define ARG(A,...) __VA_ARGS__

#endif


//#ifdef mini_syscall
// XXXXXXXXXXXXXXXXXX*************** file: syscall.h 

// Current path: /home/micha/prog/readkey/minilib

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
// XXXXXXXXXXXXXXXXXX*************** file: i386syscalls.h 

// Current path: /home/micha/prog/readkey/minilib

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
#define __callend : "memory" )

#ifdef OSX
#define __SYSCALL_ASM(ret,call) asm volatile ("syscall" : "=a" (ret)  : "a" ( (call | NCONST ) )
#else
#ifdef mini_vsyscalls
#define __SYSCALL_ASM(ret,call) asm volatile ("call *__mini_vsys" : "=a" (ret)  : "a" (call)
#else
#define __SYSCALL_ASM(ret,call) asm volatile ("int $0x80" : "=a" (ret)  : "a" (call)
#endif
#endif

#ifdef OSX
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

// Current path: /home/micha/prog/readkey/minilib

// O: include/timeval.h
#ifndef timeval_h
#define timeval_h
// XXXXXXXXXXXXXXXXXX*************** file: time_t.h 

// Current path: /home/micha/prog/readkey/minilib

// O: include/time_t.h
#ifndef type_t_h
#define type_t_h
typedef long time_t;
#endif
struct timeval { time_t tv_sec; long tv_usec; };

struct timezone {
		int     tz_minuteswest; /*	minutes	west of	Greenwich */
		int     tz_dsttime;     /*	type of	dst correction */
};
#endif
// XXXXXXXXXXXXXXXXXX*************** file: ../src/syscall_stubs.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../src  Name syscall_stubs.c
// O: include/syscall_stubs.c
// O: src/syscall_stubs.c
// These are just wrapped syscalls.
// errno is set, anyway.
#ifndef SYSCALL_STUBS
#define SYSCALL_STUBS

//#include "../include/syscall.h"

static int sysret;
extern int errno;



DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )

DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

#ifndef OSX
DEF_syscallret(time,*a1,1,unsigned int *a1 )
#else

#endif




#endif


#ifdef mini_read
// XXXXXXXXXXXXXXXXXX*************** file: read.h 

// Current path: /home/micha/prog/readkey/minilib

// O: include/read.h
#ifndef minilib_read_h
#define minilib_read_h

//#include "syscall.h"
// XXXXXXXXXXXXXXXXXX*************** file: ../macros/overrun.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../macros  Name overrun.h
// O: include/overrun.h
// O: src/overrun.h
// O: asm/overrun.h
// O: macros/overrun.h
// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
// XXXXXXXXXXXXXXXXXX*************** file: ../include/exit.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name exit.h
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
// XXXXXXXXXXXXXXXXXX*************** file: ../include/mprints.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name mprints.h
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
#define MINI_TEST_OVERRUN(pos) if (pos > mini_buf){\
		mprintsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif

static inline int __attribute__((always_inline)) read( int fd, char *buf, int len ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
		//MINI_TEST_OVERRUN(len);
		int ret;
		syscall3(ret,SCALL(read),fd,(long int)buf,len);
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

// Current path: /home/micha/prog/readkey/minilib

// YYYYYYYYYYYYYY   Already included: mprints.h
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

// Current path: /home/micha/prog/readkey/minilib

// YYYYYYYYYYYYYY   Already included: exit.h
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

// Current path: /home/micha/prog/readkey/minilib

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
DEF_syscall(write,3,int a1,const char *a2, int a3 )


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

// Current path: /home/micha/prog/readkey/minilib

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

// Current path: /home/micha/prog/readkey/minilib

// O: include/open.h
#ifndef minilib_open_h
#define minilib_open_h

//#include "syscall.h"
// XXXXXXXXXXXXXXXXXX*************** file: filemodes.h 

// Current path: /home/micha/prog/readkey/minilib

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


//#undef open
static inline int __attribute__((always_inline)) open( const char *s, int flags, int mode ){
		int ret;
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

// Current path: /home/micha/prog/readkey/minilib

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

// Current path: /home/micha/prog/readkey/minilib

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

// Current path: /home/micha/prog/readkey/minilib

// YYYYYYYYYYYYYY   Already included: filemodes.h
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

#ifdef mini_errno
// XXXXXXXXXXXXXXXXXX*************** file: errno.h 

// Current path: /home/micha/prog/readkey/minilib

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
// XXXXXXXXXXXXXXXXXX*************** file: select.h 

// Current path: /home/micha/prog/readkey/minilib

// O: include/select.h
#ifndef select_h
#define select_h
// XXXXXXXXXXXXXXXXXX*************** file: timeval.h 

// Current path: /home/micha/prog/readkey/minilib

// YYYYYYYYYYYYYY   Already included: timeval.h
// O: include/timeval.h
#ifndef timeval_h
#define timeval_h
// XXXXXXXXXXXXXXXXXX*************** file: time_t.h 

// Current path: /home/micha/prog/readkey/minilib

// YYYYYYYYYYYYYY   Already included: time_t.h
// O: include/time_t.h
#ifndef type_t_h
#define type_t_h
typedef long time_t;
#endif
struct timeval { time_t tv_sec; long tv_usec; };

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


extern	int select (int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait);
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

// Current path: /home/micha/prog/readkey/minilib

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
extern int mstrcmp(char*,char*);
extern int mstrncmp(char*,char*,int);
extern int memcmp(char*,char*,int);
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
#define strcmp(A,B) mstrcmp(A,B)
#define strncmp(A,B,LEN) mstrncmp(A,B,LEN)
#define strlen(A) mstrlen(A)
#endif


#endif
#endif


#ifdef X64
#define POINTER long int
#else
#define POINTER int
#endif



#ifdef mini_buf
// XXXXXXXXXXXXXXXXXX*************** file: src/mbuf.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name mbuf.c
// O: include/mbuf.c
// O: src/mbuf.c
#ifndef MINI_MBUF
#define MINI_MBUF
static char mbuf[mini_buf];
#endif
#endif

#ifdef mini_itohex
// XXXXXXXXXXXXXXXXXX*************** file: src/itohex.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name itohex.c
// O: include/itohex.c
// O: src/itohex.c

int itohex(int i,char* buf,int padding){

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
										c = c + 87; // 55 for big abc ..
								buf[p] = c;
								p++;
						} else
								padding++;
				}
		}
		buf[p] = 0 ;
		return(p);
}



#endif

#ifdef mini_itodec
// XXXXXXXXXXXXXXXXXX*************** file: src/itodec.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name itodec.c
// O: include/itodec.c
// O: src/itodec.c
// convert int to string.
// prec: precision, e.g. 4=> 0087 
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

	const int div[13] = {0, 100000000, 10000000, 1000000, 0, 100000, 10000, 1000, 0, 100, 10, 1};
	
	if ( i >= 1000000000){
			//mprints("hier.\n");
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
	} else {
			if ( prec == 0 ){
					buf[0] = '0';
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
					buf[p] = n;
					p++;
			} else
					prec++;

			}
	}
	if ( p==0 )
			p=1;
	buf[p] = 0;

	return(p);
}

	

int itodec(int i, char *buf, int prec, char limiter ){
	if ( i < 0 ){
			buf[0]='-';
			i = -i;
			return(uitodec((unsigned int)i,&buf[1],prec,limiter) + 1 );
	}
	return(uitodec((unsigned int)i,buf,prec,limiter) );
}

#endif

#ifdef mini_dtodec
// XXXXXXXXXXXXXXXXXX*************** file: src/dtodec.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name dtodec.c
// O: include/dtodec.c
// O: src/dtodec.c
//convert double to string
//return number of bytes written to buf.
//doesn't convert numbers > 2^31 (!!!)
//doesn't round(!)
//max. prec after the dot: 8 digits. (!!)
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

#ifdef mini_atoi
// XXXXXXXXXXXXXXXXXX*************** file: src/atoi.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name atoi.c
// O: include/atoi.c
// O: src/atoi.c
#ifndef atoi_c
#define atoi_c

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

#ifdef mini_itobin
// XXXXXXXXXXXXXXXXXX*************** file: src/itobin.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name itobin.c
// O: include/itobin.c
// O: src/itobin.c

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




#ifdef mini_puts
#define mini_print
#endif

#ifdef mini_print
// XXXXXXXXXXXXXXXXXX*************** file: src/mprint.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name mprint.c
// O: include/mprint.c
// O: src/mprint.c
#ifndef mprint_c
#define mprint_c
// XXXXXXXXXXXXXXXXXX*************** file: ../include/write.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name write.h
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
DEF_syscall(write,3,int a1,const char *a2, int a3 )


/*volatile static inline int __attribute__((always_inline)) write( register int fd, const char *s, int len ){
		register int a asm("a") = 4;
		register int b asm("b") = fd;
		register int c asm("c") = (int)s;
		register int d asm("d") = len;
		__asm__ volatile( "call *__mini_vsys");

		return(0);
}*/


#endif

int print(const char *msg){
		int a=0;
		while (msg[a] != 0 ){
				a++;
		}
		return( write(1,msg,a) );
}


int printl(const char *msg){
		int ret = print(msg);
		write(1,"\n",1);
		ret++;
		return(ret);
}

#ifdef mini_puts
//int puts( const char *c ){
//		return(printl(c));
//}
#endif

#endif

#define mini_errno
#endif


#ifdef mini_mfprintf
// XXXXXXXXXXXXXXXXXX*************** file: src/mfprintf.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name mfprintf.c
// O: include/mfprintf.c
// O: src/mfprintf.c
#ifndef mfprintf_c
#define mfprintf_c

#ifndef mini_write
#define mini_write
#endif


#ifndef mini_prints
#define mini_prints
#endif

// XXXXXXXXXXXXXXXXXX*************** file: ../macros/overrun.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../macros  Name overrun.h
// O: include/overrun.h
// O: src/overrun.h
// O: asm/overrun.h
// O: macros/overrun.h
// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
// XXXXXXXXXXXXXXXXXX*************** file: ../include/exit.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name exit.h
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
// XXXXXXXXXXXXXXXXXX*************** file: ../include/mprints.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name mprints.h
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
#define MINI_TEST_OVERRUN(pos) if (pos > mini_buf){\
		mprintsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif
// XXXXXXXXXXXXXXXXXX*************** file: ../include/write.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name write.h
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
DEF_syscall(write,3,int a1,const char *a2, int a3 )


/*volatile static inline int __attribute__((always_inline)) write( register int fd, const char *s, int len ){
		register int a asm("a") = 4;
		register int b asm("b") = fd;
		register int c asm("c") = (int)s;
		register int d asm("d") = len;
		__asm__ volatile( "call *__mini_vsys");

		return(0);
}*/


#endif
//#include "../include/exit.h" // Needed for testing for mbuffer overrun
// XXXXXXXXXXXXXXXXXX*************** file: mprints.c 

// Current path: /home/micha/prog/readkey/minilib

// O: include/mprints.c
// O: src/mprints.c
#ifndef mprints_c
#define mprints_c
// XXXXXXXXXXXXXXXXXX*************** file: ../include/write.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name write.h
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
DEF_syscall(write,3,int a1,const char *a2, int a3 )


/*volatile static inline int __attribute__((always_inline)) write( register int fd, const char *s, int len ){
		register int a asm("a") = 4;
		register int b asm("b") = fd;
		register int c asm("c") = (int)s;
		register int d asm("d") = len;
		__asm__ volatile( "call *__mini_vsys");

		return(0);
}*/


#endif
// XXXXXXXXXXXXXXXXXX*************** file: ../include/mprints.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name mprints.h
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
// XXXXXXXXXXXXXXXXXX*************** file: ../include/stdarg.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name stdarg.h
// O: include/stdarg.h
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


#ifndef mini_mprints
#define mini_mprints
#endif

//TODO: Handle errors of write (ret == -1)

#if 0
int _mprints(char *msg,...){
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
int _mprints(char *msg,...){
		va_list args;
		va_start(args,msg);
		int a;
		int ret = 0;

		do {
				a = 0;
				while (msg[a] != 0 ){
						a++;
				}
				ret += write(1,msg,a);
				msg = va_arg(args,char*);
		} while ( msg != 0 );
		va_end(args);
		return(ret);
}
#endif

#endif
// XXXXXXXXXXXXXXXXXX*************** file: ../include/stdarg.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name stdarg.h
// O: include/stdarg.h
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

//#include <stdarg.h>
// XXXXXXXXXXXXXXXXXX*************** file: mbuf.c 

// Current path: /home/micha/prog/readkey/minilib

// YYYYYYYYYYYYYY   Already included: mbuf.c
// O: include/mbuf.c
// O: src/mbuf.c
#ifndef MINI_MBUF
#define MINI_MBUF
static char mbuf[mini_buf];
#endif

/// mfprintf
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
int mfprintf(int fd, const char* fmt, ... ){
/*		va_list args, ca;
		va_start(args,fmt);
		va_copy(ca,args);
		int len = msprintf(mbuf,fmt,&ca);
		va_end(args);
		va_end(ca);
		return(write(fd,mbuf,len));
}*/ //no ork.

		va_list args;
		va_start(args,fmt);
		int a = 0;
		int b = 0;
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
												mbuf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
#if 1
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&mbuf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&mbuf[b],padding,sep);
#endif
												end=1;
												break;
#endif
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&mbuf[b],padding);
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
												b = b + itohex(va_arg(args,int),&mbuf[b],padding);
#endif
												end=1;
												break;
										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&mbuf[b],padding,groups);
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
														mbuf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												mbuf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						mbuf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
		mbuf[b] = 0;
		va_end(args);
		return(write(fd,mbuf,b));
		//return(b);
#endif
}


#endif
#define mini_errno
#endif



#ifdef mini_errno
int errno;
#endif
//int sysret=0;

#ifndef OSX

#ifdef mini_vsyscalls
int __mini_vsys = 0;
// XXXXXXXXXXXXXXXXXX*************** file: src/start_c.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name start_c.c
// O: include/start_c.c
// O: src/start_c.c
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
// XXXXXXXXXXXXXXXXXX*************** file: asm/start-linux-x64.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: asm  Name start-linux-x64.c
// O: include/start-linux-x64.c
// O: src/start-linux-x64.c
// O: asm/start-linux-x64.c
void _start(){
#ifdef mini_start
__asm__ (
		"popq %rdi\n\t"
		"movq %rsp,%rsi\n\t"
		"leaq  8(%rsi,%rdi,8),%rdx\n\t"
		"call main\n\t"
		"movq %rax, %rbx\n\t"
		"movq $1, %rax\n\t"
		"int $0x80\n\t"
	);
};
#endif

#else
// XXXXXXXXXXXXXXXXXX*************** file: asm/start.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: asm  Name start.c
// O: include/start.c
// O: src/start.c
// O: asm/start.c
void _start(){
#ifdef mini_start
__asm__ (
		"pop %eax\n\t"
		"leal  12(%esp,%eax,4),%ebx\n\t"
		"push %ebx\n\t"
		"call __start_c\n\t"
		"pop %ebx\n\t"
		"pop %eax\n\t"
		"mov %esp,%ecx\n\t"
		"push %ebx\n\t"
		"push %ecx\n\t"
		"push %eax\n\t"
		"call main\n\t"
		"mov %eax, %ebx\n\t"
		"mov $1, %eax\n\t"
		"int $0x80\n\t"
	);
};
#endif

#endif
#endif


#else

#ifdef mini_start
// XXXXXXXXXXXXXXXXXX*************** file: asm/start-osx.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: asm  Name start-osx.c
// O: include/start-osx.c
// O: src/start-osx.c
// O: asm/start-osx.c
#ifdef mini_start
__asm__ (
		".globl start\n\t"
		"start:	pushq	$0\n\t"
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
		"movl $0x2000001, %eax\n\t"
		"syscall\n\t"
	);
#endif

#endif


#endif


#ifdef mini_mprints
// XXXXXXXXXXXXXXXXXX*************** file: src/mprints.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name mprints.c
// O: include/mprints.c
// O: src/mprints.c
#ifndef mprints_c
#define mprints_c
// XXXXXXXXXXXXXXXXXX*************** file: ../include/write.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name write.h
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
DEF_syscall(write,3,int a1,const char *a2, int a3 )


/*volatile static inline int __attribute__((always_inline)) write( register int fd, const char *s, int len ){
		register int a asm("a") = 4;
		register int b asm("b") = fd;
		register int c asm("c") = (int)s;
		register int d asm("d") = len;
		__asm__ volatile( "call *__mini_vsys");

		return(0);
}*/


#endif
// XXXXXXXXXXXXXXXXXX*************** file: ../include/mprints.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name mprints.h
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
// XXXXXXXXXXXXXXXXXX*************** file: ../include/stdarg.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name stdarg.h
// O: include/stdarg.h
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


#ifndef mini_mprints
#define mini_mprints
#endif

//TODO: Handle errors of write (ret == -1)

#if 0
int _mprints(char *msg,...){
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
int _mprints(char *msg,...){
		va_list args;
		va_start(args,msg);
		int a;
		int ret = 0;

		do {
				a = 0;
				while (msg[a] != 0 ){
						a++;
				}
				ret += write(1,msg,a);
				msg = va_arg(args,char*);
		} while ( msg != 0 );
		va_end(args);
		return(ret);
}
#endif

#endif
#endif

#ifdef mini_msprintf
// XXXXXXXXXXXXXXXXXX*************** file: src/msprintf.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name msprintf.c
// O: include/msprintf.c
// O: src/msprintf.c
#ifndef msprintf_c
#define msprintf_c

#ifndef mini_write
#define mini_write
#endif


#ifndef mini_prints
#define mini_prints
#endif

// XXXXXXXXXXXXXXXXXX*************** file: ../macros/overrun.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../macros  Name overrun.h
// O: include/overrun.h
// O: src/overrun.h
// O: asm/overrun.h
// O: macros/overrun.h
// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
// XXXXXXXXXXXXXXXXXX*************** file: ../include/exit.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name exit.h
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
// XXXXXXXXXXXXXXXXXX*************** file: ../include/mprints.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name mprints.h
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
#define MINI_TEST_OVERRUN(pos) if (pos > mini_buf){\
		mprintsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif
// XXXXXXXXXXXXXXXXXX*************** file: ../include/write.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name write.h
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
DEF_syscall(write,3,int a1,const char *a2, int a3 )


/*volatile static inline int __attribute__((always_inline)) write( register int fd, const char *s, int len ){
		register int a asm("a") = 4;
		register int b asm("b") = fd;
		register int c asm("c") = (int)s;
		register int d asm("d") = len;
		__asm__ volatile( "call *__mini_vsys");

		return(0);
}*/


#endif
// XXXXXXXXXXXXXXXXXX*************** file: ../include/exit.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name exit.h
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
// XXXXXXXXXXXXXXXXXX*************** file: ../include/stdarg.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name stdarg.h
// O: include/stdarg.h
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




int msprintf(char *buf, const char* fmt, ... ){
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
												b = b + uitodec(va_arg(args,unsigned int),&mbuf[b],padding,sep);
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

#ifdef mini_isspace
// XXXXXXXXXXXXXXXXXX*************** file: src/isspace.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name isspace.c
// O: include/isspace.c
// O: src/isspace.c
#ifndef isspace_c
#define isspace_c

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

#ifdef mini_ioctl
// XXXXXXXXXXXXXXXXXX*************** file: src/ioctl.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name ioctl.c
// O: include/ioctl.c
// O: src/ioctl.c
#ifndef mini_ioctl_h
#define mini_ioctl_h

//#include "../include/syscall.h"
#ifdef LINUX
#include <linux/ioctl.h> //changed from linux/ioctl.h
#else
#include <sys/ioctl.h> //changed from linux/ioctl.h
#endif
// XXXXXXXXXXXXXXXXXX*************** file: ../include/stdarg.h 

// Current path: /home/micha/prog/readkey/minilib

// Path: ../include  Name stdarg.h
// O: include/stdarg.h
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

#ifdef mini_tcgetattr
// XXXXXXXXXXXXXXXXXX*************** file: src/tcgetattr.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name tcgetattr.c
// O: include/tcgetattr.c
// O: src/tcgetattr.c
#ifndef tcgetattr_h
#define tcgetattr_h

#include <sys/termios.h>
//#include "ioctl.h"
#ifdef OSX
#include <sys/ttycom.h>
#else
#include <asm-generic/ioctls.h>
#endif

#ifndef TCGETS
//#warning TCGETS not defined. Applying ugly hack.
#define TCGETS TIOCGETA
#endif



int tcgetattr(int fd, struct termios *io)
{
	//return(ioctl(fd, 0x5401, io));
	return(ioctl(fd, TCGETS, io));

}



#endif
#endif

#ifdef mini_tcsetattr
// XXXXXXXXXXXXXXXXXX*************** file: src/tcsetattr.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name tcsetattr.c
// O: include/tcsetattr.c
// O: src/tcsetattr.c
#ifndef tcsetattr_h
#define tcsetattr_h

//#include <termios.h>
//#include "ioctl.h"
#ifdef OSX
#include <sys/ttycom.h>
#else
#include <asm-generic/ioctls.h>
#endif



#ifndef TCSETS
//#warning TCSETS not defined. Applying ugly hack.
#define TCSETS TIOCSETA
#endif

int tcsetattr(int fd, int opt, const struct termios *io)
{
	return(ioctl(fd, TCSETS +opt, io));
	//return(ioctl(fd, 0x5402+opt, io));
}



#endif
#endif



#ifdef mini_mstrcmp
// XXXXXXXXXXXXXXXXXX*************** file: src/mstrcmp.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name mstrcmp.c
// O: include/mstrcmp.c
// O: src/mstrcmp.c
#ifndef strcmp_c
#define strcmp_c

//TODO: not implemented correct. need to return also -1.

int _mstrcmp(char*c1,char*c2,int len){
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




int mstrcmp(char*c1,char*c2){
		return( _mstrcmp(c1,c2,-1) );
}


int mstrncmp(char*c1,char*c2,int len){
		if ( len <=0 )
				return(-1);
		return(_mstrcmp(c1,c2,len) );
}

int memcmp(char*c1,char*c2,int len){
		if ( len <=0 )
				return(-1);
		int a = 0;
		while ( a != len ){
				//write(1,&c1[a],1);
				if ( c1[a] != c2[a] )
						return(1);
				a++;
		}
	 return(0);
}


#endif
#endif

#ifdef mini_mstrlen
// XXXXXXXXXXXXXXXXXX*************** file: src/mstrlen.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name mstrlen.c
// O: include/mstrlen.c
// O: src/mstrlen.c
#ifndef strlen_c
#define strlen_c
int mstrlen(const char*str){
		int a = 0;
		while ( str[a] != 0 ){
				a++;
		}
		return (a);
}


#endif
#endif

#ifdef mini_memset
// XXXXXXXXXXXXXXXXXX*************** file: src/memset.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name memset.c
// O: include/memset.c
// O: src/memset.c
void *memset( void *s, int c, int n){
		int a;
		char *sp = s;
		for ( a=0; a<n; a++)
				sp[a] = (char)c;
		return(s);
}
#endif

#ifdef mini_memcpy
// XXXXXXXXXXXXXXXXXX*************** file: src/memcpy.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name memcpy.c
// O: include/memcpy.c
// O: src/memcpy.c
void *memcpy( void *d, const void *s, int n ){
		char *dp=d;
		const char *sp = s;
		int a;
		for ( a=0; a<n; a++ )
				dp[a] = sp[a];
		return(d);
}


#endif


#ifdef mini_memfrob
// XXXXXXXXXXXXXXXXXX*************** file: src/memfrob.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name memfrob.c
// O: include/memfrob.c
// O: src/memfrob.c
void* memfrob(void* s, unsigned int len){
		unsigned int a;
		char *c = s;
		for ( a=0; a<len;a++)
				c[a] = 	c[a] ^ 42;
		return ( s );
}
		
#endif

#ifdef mini_select
// XXXXXXXXXXXXXXXXXX*************** file: src/select.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name select.c
// O: include/select.c
// O: src/select.c

int select (int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait){
		//return(syscall5(__NR_select,(long)fd,(long)readfd,(long)writefd,(long)exceptfd, (long)wait));
		int ret;
		//syscall5(ret,__NR_select,&fd,readfd,writefd,exceptfd, 0);
		syscall5(ret, SCALL(select),&fd,readfd,writefd,exceptfd, (POINTER) wait);
		return(ret);
		//return(syscall5(__NR_select,fd,readfd,,0,0));
}


#endif

#ifdef mini_malloc
// XXXXXXXXXXXXXXXXXX*************** file: src/malloc.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name malloc.c
// O: include/malloc.c
// O: src/malloc.c
// just malloc. no free yet.
//#include "../include/syscall.h"

//bad bad and doesnt ork
#ifndef SYS_brk
//#define SYS_brk 69
#endif

#ifdef __NR_brk
#define BRK
#else
#ifdef SYS_brk
#define BRK
#endif
#endif
	
static int brk=0;

void* malloc(POINTER size){
		POINTER ret;
#ifdef BRK	
		if ( brk == 0 ){
				syscall1(ret,SCALL(brk),0);
		} else {
				ret=brk;
		}
		syscall1(brk,SCALL(brk),size+ret);
#else 
//#todo: doesnt ork at all
//		syscall6(ret, SCALL(mmap), 0, size, PROT_READ|PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
		//size = 4096;
	  register long int r8 asm ("r8") = -1 ; 
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
		return((void*)ret);
#endif
}


#endif

#ifdef mini_powers
// XXXXXXXXXXXXXXXXXX*************** file: src/powers.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name powers.c
// O: include/powers.c
// O: src/powers.c
// calc powers.
// stolen (modified slightly) from Eric Jablow.
// http://c2.com/cgi/wiki?IntegerPowerAlgorithm / http://c2.com/cgi/wiki?EricJablow

/*
float fpowerui(float x, unsigned int n) {
		float aux = 1.0;
		while (n > 0) {
				if (n & 1) {    // odd?
						aux *= x;
						if (n == 1) return aux;
				}
				x *= x;
				n >>= 1;
		}
		return aux;
}

int ipoweriui(int x, unsigned int n) {
		int aux = 1;
		while (n > 0) {
				if (n & 1) {    // odd?
						aux *= x;
						if (n == 1) return aux;
				}
				x *= x;
				n >>= 1;
		}
		return aux;
}*/

 /* ------------------------------------------------------------------------- */
// written by me..
// todo: negative: x^n == x/x^n+1 ... ->ret float..
int ipoweriui(int x, unsigned int n){
		int t;
		switch (n){
			case 0: return( 1 );
			case 1:	return( x );
		}

		if ( n & 1 ){
				t = ipoweriui(x,((n-1)>>1) );
				return( t * t * x );
		} else {
				t = ipoweriui(x,n>>1);
				return( t*t );
		}
}

// useless. but would work for doubles.
int ipoweri(int x, int n){
		if ( n >0 )
				return(ipoweriui(x,n));
		//n<0
		return(1/ipoweriui(x,n));
}





#endif


// XXXXXXXXXXXXXXXXXX*************** file: src/syscall_stubs.c 

// Current path: /home/micha/prog/readkey/minilib

// Path: src  Name syscall_stubs.c
// O: include/syscall_stubs.c
// O: src/syscall_stubs.c
// These are just wrapped syscalls.
// errno is set, anyway.
#ifndef SYSCALL_STUBS
#define SYSCALL_STUBS

//#include "../include/syscall.h"

static int sysret;
extern int errno;



DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )

DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

#ifndef OSX
DEF_syscallret(time,*a1,1,unsigned int *a1 )
#else

#endif




#endif

#endif
