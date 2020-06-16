#ifndef linux_x64_signal_h
#define linux_x64_signal_h





struct sigaction {
		void (*sa_handler)(int);
		unsigned long sa_flags;
		void (*restorer)(void);
		sigset_t sa_mask;
};





#endif
