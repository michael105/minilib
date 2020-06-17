#ifndef linux_x64_signal_h
#define linux_x64_signal_h



typedef struct __sigset_t { unsigned long sig; } sigset_t;


struct sigaction {
		void (*sa_handler)(int);
		unsigned long sa_flags;
		void (*restorer)(void);
		sigset_t sa_mask;
};





#endif
