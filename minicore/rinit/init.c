#if 0
mini_start
mini_writes
mini_vfork
mini_execve
mini_sleep
mini_exit
mini_waitpid
mini_prints
mini_printsl
mini_sigaction
mini_sigaddset
mini_sigemptyset
mini_sigfillset


LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/06
// BSD license
//
// a minimal init
// 
// starts /etc/rinit/boot and hands all over all arguments, invoked with.
//
// after "boot" has been started, 
// init reads from the named pipe /etc/rinit/initpipe,
// and handles signals.
//
// depending on signal/pipe input, 
// the next runlevel is started.
//
// 
// 

#define STAGE1 "/hd/sda8/home/micha/prog/minilib/minicore/rinit/test1.sh"
#define STAGE2 "/hd/sda8/home/micha/prog/minilib/minicore/rinit/test2.sh"
#define STAGE3 "/hd/sda8/home/micha/prog/minilib/minicore/rinit/test3.sh"

#define HL "\033[1;36m"
#define RED "\033[31m"
#define NORM "\033[0;37m"
#define PREF HL "--- " NORM

int shutdown;


void error(const char*c){
		writes( RED "Error: " NORM );
		printsl( c );
}

void warning(const char*c){
		writes( RED "Warning: " NORM );
		printsl( c );
}

void log(const char*c){
		writes( HL "--- " NORM );
		printsl( c );
}


void sighandler(int signal){
		writes("Within handler\n");
		sleep(3);
		if ( signal == SIGINT ){
				shutdown = 1;
		}
}



int vexec( const char* exec, char* const* argv, char* const* envp ){
		int pid = vfork();

		if ( pid == 0 ){
				execve(exec, argv, envp );
				error("Couldn't execute");
				error(exec);
				sleep(5);
				return(1); // exit with failure
		}

		int ws;
		int w;
		do {
				w = waitpid( pid, &ws, 0 );
		} while ( ! ( WIFEXITED(ws) || WIFSIGNALED(ws) ) );

		return(0);
}

int main(int argc, char **argv, char **envp){
		shutdown = 0;
	
		log("start init");

   struct sigaction sa;

   sigfillset(&sa.sa_mask);
   sa.sa_flags = 0;
   sa.sa_handler = sighandler;

	 if ( sigaction (SIGTERM, &sa, 0) ||
		 		sigaction (SIGQUIT, &sa, 0) ||
		 		sigaction (SIGINT, &sa, 0) 
				){
			 error("Couldn't install signal handler");
	 }

		log( "exec " STAGE1);
		if ( vexec( STAGE1, argv, envp ) )
				return(-1);

		int a = 0;
		do {
				log("exec " STAGE2 );
				if ( vexec(STAGE2, argv, envp) )
						return(-1);
				if ( (a++) > 1 ){ // prevent spinning 
						warning("stage2 seems to die unexpectedly\nSleeping");
						a=0;
						sleep(5);
				}
		} while (!shutdown);


		return(0); // exit
}

