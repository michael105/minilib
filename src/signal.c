#ifndef signal_c
#define signal_c

// musl

//+header signal.h
//+depends sigaction
//+def
sighandler_t signal(int sig, sighandler_t func ){
		struct sigaction sa_old, sa = { .sa_handler = func, .sa_flags = SA_RESTART };
		if (sigaction(sig, &sa, &sa_old) < 0)
				return SIG_ERR;
		return sa_old.sa_handler;
}





#endif
