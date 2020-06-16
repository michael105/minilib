#ifndef sigaction_c
#define sigaction_c
//+header signal.h
//+include

#ifdef mini_sigaction
extern void _sigrestore();
//volatile void __sigrestore(){
__asm__ ( "\
.global _sigrestore\n\
_sigrestore:\n\
	mov $15,%rax\n\
	syscall");
//}

#endif

//+header signal.h
//+include
//+depends memcpy
//+def
int volatile sigaction(int sig, const struct sigaction *act, struct sigaction *oact){
		struct sigaction sa;
		//memcpy(&sa,act,sizeof(sigaction));
		sa.sa_mask.sig[0]=act->sa_mask.sig[0];
		if ((8/sizeof(long)) > 1)
				sa.sa_mask.sig[1]=act->sa_mask.sig[1];

		sa.sa_handler=act->sa_handler;
		sa.sa_flags = act->sa_flags | SA_RESTORER;
    sa.restorer = &_sigrestore;
				
		return( rt_sigaction( sig, &sa, oact, sizeof(sigset_t) ) );
}

// memo: needs static definition, cause the +include
// (meaning, including the definition into the header.
// What is the right thing to do for a wrapper call.)

#endif
