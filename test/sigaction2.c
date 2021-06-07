#if 0
mini_buf 256
mini_start
mini_printf
mini_nanosleep
mini_sleep
mini_itodec
mini_atoi
mini_fork
mini_writes
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"

void handler(int signal){
		writes("Within handler\n");
}



struct msigaction {
#ifndef __ARCH_HAS_IRIX_SIGACTION
		  m__sighandler_t  sa_handler;
			  unsigned long sa_flags;
#else
				  unsigned int  sa_flags;
					  m__sighandler_t  sa_handler;
#endif
#ifdef __ARCH_HAS_SA_RESTORER
						  m__sigrestore_t sa_restorer;
#endif
							  msigset_t  sa_mask;  /* mask last for extensibility */
};

struct mk_sigaction {
		  struct msigaction sa;
#ifdef __ARCH_HAS_KA_RESTORER
			  m__sigrestore_t ka_restorer;
#endif
};


extern void m_sigrestore();
volatile void m__sigrestore(){
__asm__ volatile( "\
.global m_sigrestore\n\
m_sigrestore:\n\
	mov $15,%rax\n\
	syscall");
}

#endif

//+header signal.h
//+include
//+depends memcpy
//+def
int volatile msigaction(int sig, const struct msigaction *act, struct msigaction *oact){
		struct msigaction sa;
		//memcpy(&sa,act,sizeof(sigaction));
		sa.sa_mask.sig[0]=act->sa_mask.sig[0];
		//sa.sa_mask.sig[1]=act->sa_mask.sig[1];
		sa.sa_handler=act->sa_handler;
		sa.sa_flags = act->sa_flags | SA_RESTORER;
    sa.restorer = &_sigrestore;
				
		return( rt_sigaction, 4, sig, &sa, oact, sizeof(msigset_t) );
}



int msigemptyset(sigset_t *set){

		set->sig[0]=0;
		//if ((128/sizeof(long)) > 1)
	//			set->sig[1]=0;
/*		if ((128/sizeof(long)) > 2){
				set->sig[2]=0;
				set->sig[3]=0;
		};*/

		return 0;
}



int main( int argc, char *argv[] ){
		printf("Fork.\n");

   struct msigaction action;

   msigemptyset(&action.sa_mask);
   //sigaddset(&action.sa_mask, signo);
   action.sa_flags = 0;
   action.sa_handler = handler;

		errno=0;
   int r;
	 int e;
/*
	 r = sigaction (SIGINT, &action,0);
	 e = errno;
	 printf("errno: %d\n",e);
	 printf("r: %d\n",r);
*/
 r = msigaction (SIGUSR1, &action,0);
	 e = errno;
	 printf("errno: %d\n",e);
	 printf("r: %d\n",r);

//		int pid = fork();
		int pid = 0;
		printf("Pid: %d\n",pid);
		if ( pid ){
				sleep(30);


				writes("Exit parent\n");
				exit(0);
		}

		writes("Child\n");
		sleep(30);




		writes("Exit child\n");

		return(0);
}
