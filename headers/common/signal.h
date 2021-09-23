#ifndef signal_h
#define signal_h

//#include "sys/signal.h"

#define SIG_ERR  ((void (*)(int))-1)
#define SIG_DFL  ((void (*)(int)) 0)
#define SIG_IGN  ((void (*)(int)) 1)


/*typedef struct {
	unsigned long sig[2];
} sigset_t;
*/

#if 0
typedef union sigval {
		int sival_int;
		void *sival_ptr;
} sigval_t;

#define SI_MAX_SIZE 128
#if __WORDSIZE == 64
#define SI_PAD_SIZE ((SI_MAX_SIZE/sizeof(int32_t)) - 4)
#else
#define SI_PAD_SIZE ((SI_MAX_SIZE/sizeof(int32_t)) - 3)
#endif

typedef long __band_t;

typedef struct siginfo {
		int32_t si_signo;
		int32_t si_errno;
		int32_t si_code;
		union {
				int32_t _pad[SI_PAD_SIZE];
				/* kill() */
				struct {
						pid_t _pid;   /* sender's pid */
						uid_t _uid;   /* sender's uid */
				} _kill;
				/* POSIX.1b timers */
				struct {
						uint32_t _timer1;
						uint32_t _timer2;
				} _timer;
				/* POSIX.1b signals */
				struct {
						pid_t _pid;   /* sender's pid */
						uid_t _uid;   /* sender's uid */
						sigval_t _sigval;
				} _rt;
				/* SIGCHLD */
				struct {
						pid_t _pid;   /* which child */
						uid_t _uid;   /* sender's uid */
						int32_t _status;    /* exit code */
						clock_t _utime;
						clock_t _stime;
				} _sigchld;
				/* SIGILL, SIGFPE, SIGSEGV, SIGBUS */
				struct {
						void *_addr; /* faulting insn/memory ref. */
				} _sigfault;
				/* SIGPOLL */
				struct {
						__band_t _band; /* POLL_IN, POLL_OUT, POLL_MSG */
						int32_t _fd;
				} _sigpoll;
		} _sifields;
} siginfo_t;



#define _SIGSET_WORDS (1024 / (8 * sizeof (unsigned long int)))
#warning sigset: (1024 / (8 * sizeof (unsigned long int)))

typedef struct {
		unsigned long sig[_SIGSET_WORDS];
} sigset_t;

struct sigaction {
 /* arm, i386, ppc, s390, sparc, saprc64, x86_64 */
		union {
				sighandler_t _sa_handler;
				void (*_sa_sigaction)(int, siginfo_t*, void*);
		} _u;
		unsigned long sa_flags;
		void (*sa_restorer)(void);
		sigset_t sa_mask;
};

#define sa_handler  _u._sa_handler
#define sa_sigaction  _u._sa_sigaction


/*
struct sigaction {
		void     (*sa_handler)(int);
		//void     (*sa_sigaction)(int, siginfo_t *, void *);
		unsigned long sa_flags;
		void     (*sa_restorer)(void);
		sigset_t   sa_mask;
};*/

/*
typedef struct {
#ifdef __SI_SWAP_ERRNO_CODE
	int si_signo, si_code, si_errno;
#else
	int si_signo, si_errno, si_code;
#endif
	union {
		char __pad[128 - 2*sizeof(int) - sizeof(long)];
		struct {
			union {
				struct {
					pid_t si_pid;
					uid_t si_uid;
				} __piduid;
				struct {
					int si_timerid;
					int si_overrun;
				} __timer;
			} __first;
			union {
				union sigval si_value;
				struct {
					int si_status;
					clock_t si_utime, si_stime;
				} __sigchld;
			} __second;
		} __si_common;
		struct {
			void *si_addr;
			short si_addr_lsb;
			union {
				struct {
					void *si_lower;
					void *si_upper;
				} __addr_bnd;
				unsigned si_pkey;
			} __first;
		} __sigfault;
		struct {
			long si_band;
			int si_fd;
		} __sigpoll;
		struct {
			void *si_call_addr;
			int si_syscall;
			unsigned si_arch;
		} __sigsys;
	} __si_fields;
} siginfo_t;
*/
/*
struct sigaction {
	union {
		void (*sa_handler)(int);
		void (*sa_sigaction)(int, siginfo_t *, void *);
	} __sa_handler;
	sigset_t sa_mask;
	int sa_flags;
	void (*sa_restorer)(void);
};
*/
/*
typedef void __signalfn_t(int);
typedef __signalfn_t *__sighandler_t;

typedef void __restorefn_t(void);
typedef __restorefn_t *sigrestore_t;


struct sigaction {
	union {
		void (*sa_handler)(int);
		void (*sa_sigaction)(int, siginfo_t *, void *);
	} __sa_handler;
	unsigned long sa_flags;
#ifdef SA_RESTORER
	sigrestore_t sa_restorer;
#endif
	sigset_t sa_mask;		// mask last for extensibility 
};

#define sa_handler   __sa_handler.sa_handler
#define sa_sigaction __sa_handler.sa_sigaction
*/



/*
struct sigaction {
		void (*sa_handler)(int);
	sigset_t sa_mask;
	int sa_flags;
	void (*sa_restorer)(void);
};
*/
#endif

#endif
