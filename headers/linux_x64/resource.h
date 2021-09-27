
#define RLIMIT_CPU		0	/* CPU time in sec */
#define RLIMIT_FSIZE		1	/* Maximum filesize */
#define RLIMIT_DATA		2	/* max data size */
#define RLIMIT_STACK		3	/* max stack size */
#define RLIMIT_CORE		4	/* max core file size */

#ifndef RLIMIT_RSS
# define RLIMIT_RSS		5	/* max resident set size */
#endif

#ifndef RLIMIT_NPROC
# define RLIMIT_NPROC		6	/* max number of processes */
#endif

#ifndef RLIMIT_NOFILE
# define RLIMIT_NOFILE		7	/* max number of open files */
#endif

#ifndef RLIMIT_MEMLOCK
# define RLIMIT_MEMLOCK		8	/* max locked-in-memory address space */
#endif

#ifndef RLIMIT_AS
# define RLIMIT_AS		9	/* address space limit */
#endif

#define RLIMIT_LOCKS		10	/* maximum file locks held */
#define RLIMIT_SIGPENDING	11	/* max number of pending signals */
#define RLIMIT_MSGQUEUE		12	/* maximum bytes in POSIX mqueues */
#define RLIMIT_NICE		13	/* max nice prio allowed to raise to
					   0-39 for nice level 19 .. -20 */
#define RLIMIT_RTPRIO		14	/* maximum realtime priority */
#define RLIMIT_RTTIME		15	/* timeout for RT tasks in us */
#define RLIM_NLIMITS		16

/*
 * SuS says limits have to be unsigned.
 * Which makes a ton more sense anyway.
 *
 * Some architectures override this (for compatibility reasons):
 */
#ifndef RLIM_INFINITY
# define RLIM_INFINITY		(~0UL)
#endif


#define	RUSAGE_SELF	0
#define	RUSAGE_CHILDREN	(-1)
#define RUSAGE_BOTH	(-2)		/* sys_wait4() uses this */
#define	RUSAGE_THREAD	1		/* only the calling thread */

struct	rusage {
	struct timeval ru_utime;	/* user time used */
	struct timeval ru_stime;	/* system time used */
	__kernel_long_t	ru_maxrss;	/* maximum resident set size */
	__kernel_long_t	ru_ixrss;	/* integral shared memory size */
	__kernel_long_t	ru_idrss;	/* integral unshared data size */
	__kernel_long_t	ru_isrss;	/* integral unshared stack size */
	__kernel_long_t	ru_minflt;	/* page reclaims */
	__kernel_long_t	ru_majflt;	/* page faults */
	__kernel_long_t	ru_nswap;	/* swaps */
	__kernel_long_t	ru_inblock;	/* block input operations */
	__kernel_long_t	ru_oublock;	/* block output operations */
	__kernel_long_t	ru_msgsnd;	/* messages sent */
	__kernel_long_t	ru_msgrcv;	/* messages received */
	__kernel_long_t	ru_nsignals;	/* signals received */
	__kernel_long_t	ru_nvcsw;	/* voluntary context switches */
	__kernel_long_t	ru_nivcsw;	/* involuntary " */
};

struct rlimit {
	__kernel_ulong_t	rlim_cur;
	__kernel_ulong_t	rlim_max;
};


#define RLIM64_INFINITY		(~0ULL)

struct rlimit64 {
	__u64 rlim_cur;
	__u64 rlim_max;
};

#define	PRIO_MIN	(-20)
#define	PRIO_MAX	20

#define	PRIO_PROCESS	0
#define	PRIO_PGRP	1
#define	PRIO_USER	2

/*
 * Limit the stack by to some sane default: root can always
 * increase this limit if needed..  8MB seems reasonable.
 */
#define _STK_LIM	(8*1024*1024)

/*
 * GPG2 wants 64kB of mlocked memory, to make sure pass phrases
 * and other sensitive information are never written to disk.
 */
/* No one currently defines PAGE_SIZE bigger than 64kB */
#define MLOCK_LIMIT	(64 * 1024)





