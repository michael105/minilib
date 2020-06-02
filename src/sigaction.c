#ifndef sigaction_c
#define sigaction_c

//+header signal.h
//+include
//+def
static int sigaction(int sig, const struct sigaction *act, struct sigaction *oact){
		return( rt_sigaction, 4, sig, act, oact, sizeof(act->sa_mask) );
}

#endif
