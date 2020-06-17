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


typedef struct __sigset_t { unsigned long sig; } sigset_t;


struct sigaction {
		void (*sa_handler)(int);
		unsigned long sa_flags;
		void (*restorer)(void);
		sigset_t sa_mask;
};





#endif
