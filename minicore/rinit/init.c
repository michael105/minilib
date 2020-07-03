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
mini_raise

#mini_printf
#mini_itodec
#mini_buf 256

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif


/*
 
 misc 2020/06
 BSD license

 a minimal init
 
 starts /etc/rinit/1 and hands all over all arguments, invoked with.

 after "1" has exited, 
 /etc/rinit/2 is started, and restarted if it should exit.

 on signals SIGINT, Ctrl+Alt+Del (->reboot) and SIGTERM (->shutdown)
 /etc/rinit/2 is sent SIGTERM, when not responding SIGKILL,
 and after it's termination
 /etc/rinit/3 is executed.

 SIGQUIT: send the current stage a sigterm.
    when the current stage is stage 2, 
		restart the process after termination


(todo)
 SIGABRT: cancel a shutdown.
 		if stage 3 is running, send SIGABRT to the process, and restart at stage 1.
		is stage 2 is still running, and a shutdown is in progress,
		send stage 2 SIGABRT. If the process exits restart stage 2
*/
 

#if 0
#define STAGE1 "/hd/sda8/home/micha/prog/minilib/minicore/rinit/test1.sh"
#define STAGE2 "/hd/sda8/home/micha/prog/minilib/minicore/rinit/test2.sh"
#define STAGE3 "/hd/sda8/home/micha/prog/minilib/minicore/rinit/test3.sh"
#else
#define STAGE1 "/etc/rinit/1"
#define STAGE2 "/etc/rinit/2"
#define STAGE3 "/etc/rinit/3"
#endif

// After signalling the current stage with SIGTERM,
// wait this time (in seconds). When the (running) stage still runs 
// kill it with SIGTERM, when still not responding within WAITTIME seconds
// continue anyways
#define WAITTIME 30

#define HL "\033[1;36m"
#define RED "\033[31m"
#define NORM "\033[0;37m"
#define PREF HL "--- " NORM

int shutdown;
int stagepid;
int zombie;


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

// set a timer, which calls sigalarm
void settimer(int secs){
		struct itimerval timer = { 
				.it_value.tv_sec  = secs,
				.it_value.tv_usec = 0 };
		setitimer (ITIMER_REAL, &timer, 0);
}


void sighandler(int signal){
		if ( signal == SIGTERM ){
				shutdown = 1; // halt
				log("init: Shutdown");
		}
		if ( signal == SIGINT ){
				shutdown = 2; // reboot
				log("init: Reboot");
		}

		kill(stagepid,SIGTERM);
	
		// set a timer, 
		// and kill the curent stage, 
		// when init is still running at that time
		settimer(WAITTIME);
}

void sigalarm(int signal){
		if ( shutdown ){
				warning("Shutdown: timeout reached. Send kill.");
				kill(stagepid, SIGKILL);
				if ( zombie == stagepid ){ // stage process hangs, didn't respond to sigkill
					 raise(SIGTERM); // kill ourselves / meaning continue in vexec, waitpid
				}
				zombie = stagepid; // save stagepid.
				settimer(WAITTIME); // when the stage process doesn't respond to the sigkill,
				// kill ourselves after "waittime"
		}
}

void sigabrt(int signal){
		if ( shutdown ){
				shutdown = 0;
				warning("Abort shutdown");
				kill(stagepid, SIGABRT);
		}
}

int vexec( const char* exec, char* const* argv, char* const* envp ){
		stagepid = vfork();

		if ( stagepid == 0 ){
				execve(exec, argv, envp );
				error("Couldn't execute");
				error(exec);
				sleep(3);
				return(1); // exit with failure
		}

		int ws;
		int pid;
		do {
				pid = waitpid( -1, &ws, 0 ); // wait for any child (reap zonbies)
		} while ( !( ( (pid == stagepid) && (WIFEXITED(ws) || WIFSIGNALED(ws) ) ) || zombie ) );

		return(0);
}



int main(int argc, char **argv, char **envp){
		// setup 
		shutdown = 0;
		stagepid = 0;
		zombie = 0;

		log("start init");

		// install signal handlers
		struct sigaction sa;

		sigfillset(&sa.sa_mask);
		sa.sa_flags = 0;
		sa.sa_handler = sighandler;

		if ( sigaction (SIGTERM, &sa, 0) ||
						sigaction (SIGQUIT, &sa, 0) ||
						sigaction (SIGINT, &sa, 0) ){
				error("Couldn't install signal handler");
				// try to continue anyways.
		}

		sa.sa_handler = sigalarm;
		if ( sigaction (SIGALRM, &sa, 0) ){
				error("Couldn't install alarm handler");
		}

		sa.sa_handler = sigabrt;
		if ( sigaction (SIGABRT, &sa, 0) ){
				error("Couldn't install sigabrt handler");
		}

		// Ctrl-Alt-Del: send sigint to init, but do not reboot
		reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_CAD_OFF,0);

		// stage 1
STAGE1_START:
		zombie = 0;
		log("Run " STAGE1);
		vexec( STAGE1, argv, envp );

		int a = 0;

		// stage 2
		while (!shutdown){
				log("Run " STAGE2);
				if ( vexec(STAGE2, argv, envp) )
						return(-1);
				if ( (a++) > 1 ){ // prevent spinning 
						warning("stage2 seems to die unexpectedly\nSleeping");
						a=0;
						sleep(5);
				}
		};

		// stage 3
		if ( shutdown==1 )
				log("Shutdown");
		else
				log("Reboot");

		log("Run " STAGE3);
		settimer(WAITTIME);
		zombie = 0;
		vexec(STAGE3, argv, envp);

		log("Sync remaining file systems");
		sync();

		// shutdown
		if ( shutdown == 1 ){
				log("Power off");
				sync();
				reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_POWER_OFF,0);
				reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_HALT,0);
		}

		if ( shutdown == 2 ){
				log("Reboot");
				sync();
				reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_RESTART,0);
		}

		if ( shutdown == 0 )
				goto STAGE1_START; // shutdown aborted. start with stage1 again

		// shouldn't get here.
		log("Exit init.");
		
		return(0); // exit
}

