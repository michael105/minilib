#if 0
mini_start
mini_prints
mini_signal
mini_abort

mini_sigaction 
mini_ewrites
mini_writes

#LDSCRIPT textandbss
#STRIPFLAG


INCLUDESRC
#FULLDEBUG


if [ -n "$CLANG" ]; then
	OPTFLAG -O2
	mini_memset
fi

return
#endif

static sighandler_t __attribute__((optnone))signaln(int sig, sighandler_t func ){
		struct sigaction sa_old = { .sa_handler=0, .sa_flags=0 };
		struct sigaction sa = { .sa_handler = func, .sa_flags = SA_RESTART };
		if (sigaction(sig, &sa, &sa_old) < 0){
				ewrites("SIGNAL - ERR\n");
				return SIG_ERR;
		}
		return sa_old.sa_handler;
}

void __attribute__((optnone,used))sigabrt(int num){
		writes("Handler Sigabrt\n");
}

int main(int argc, char **argv){

		writes("abort. Install handler\n");
		signaln(SIGABRT, &sigabrt );

		writes("abort.\n");


		abort();
		writes("abort failed\n");
		return(1);
}
