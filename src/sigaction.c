#ifndef sigaction_c
#define sigaction_c
//+header signal.h
//+include

//+inline
static int sigemptyset(sigset_t *set){
#ifdef X64
		set->sig=0;
#else
		set->sig[0]=0;
		if ((8/sizeof(long)) > 1)
				set->sig[1]=0;
#endif
		return 0;
}

#if 1
//+inline
static int sigfillset(sigset_t *set){
#ifdef X64
		set->sig=0x7FFFFFFF; // doesn't work. ?
#else
#error implemented only for X64
//		set->sig[0]=0x1FFFFFFF;
//		if ((8/sizeof(long)) > 1)
//				set->sig[1]=0;
#endif
		return 0;
}
#endif

//+def
int sigaddset(sigset_t *set, int sig){
		unsigned s = sig-1;
		if (sig >= _NSIG-1 || sig <0 ) {
#ifdef mini_errno
				errno = EINVAL;
#endif
				return -1;
		}
#ifdef X64
		set->sig |= (1<<s);
#else
#error implemented only for X64
#endif
		return(0);
}


//+def
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset){
		return( rt_sigprocmask( how, (sigset_t*)set, oldset, sizeof(sigset_t) ) );
}


//+def
int sigdelset(sigset_t *set, int sig){
		unsigned s = sig-1;
		if (sig >= _NSIG-1 || sig <0 ) {
#ifdef mini_errno
				errno = EINVAL;
#endif
				return -1;
		}
#ifdef X64
		set->sig &= ~(1<<s);
#else
#error implemented only for X64
#endif
		return(0);
}

//+def
int sigismember(sigset_t *set, int sig){
		unsigned s = sig-1;
		if (sig >= _NSIG-1 || sig <0 ) {
#ifdef mini_errno
				errno = EINVAL;
#endif
				return -1;
		}
#ifdef X64
		return( set->sig & (1<<s) );
#else
#error implemented only for X64
		return(-1);
#endif
}




#ifdef mini_sigaction

extern void _sigrestore();
__asm__ ( "\
.global _sigrestore\n\
_sigrestore:\n\
	mov $15,%rax\n\
	syscall");

//+header signal.h
//+include
//+depends memcpy
//+def
static int volatile sigaction(int sig, const struct sigaction *act, struct sigaction *oact){
		struct sigaction sa;
		//memcpy(&sa,act,sizeof(sigaction));

#ifdef X64
		sa.sa_mask.sig=act->sa_mask.sig;
#else
		sa.sa_mask.sig[0]=act->sa_mask.sig[0];
		if ((8/sizeof(long)) > 1)
				sa.sa_mask.sig[1]=act->sa_mask.sig[1];
#endif

		sa.sa_handler=act->sa_handler;
		sa.sa_flags = act->sa_flags | SA_RESTORER;
    sa.restorer = &_sigrestore;
				
		return( rt_sigaction( sig, &sa, oact, sizeof(sigset_t) ) );
}

#endif

// memo: needs static definition, cause the +include
// (meaning, including the definition into the header.
// What is the right thing to do for a wrapper call.)


//+depends getpid 
//+def
static inline int raise(int signr){
		return(kill(getpid(),signr));
}


#endif
