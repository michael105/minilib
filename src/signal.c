#ifndef signal_c
#define signal_c


//+header signal.h
//+depends sigaction
//+def
sighandler_t signal(int sig, sighandler_t func ){
		struct sigaction sa_old = { .sa_handler=0, .sa_flags=0 };
		struct sigaction sa = { .sa_handler = func, .sa_flags = SA_RESTART };
		if (sigaction(sig, &sa, &sa_old) < 0){
				prints("SIGNAL - ERR\n");
				return SIG_ERR;
		}
		return sa_old.sa_handler;
}



#endif
