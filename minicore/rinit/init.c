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

mini_printf
mini_itodec
mini_buf 256

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

// After this time in seconds, after signalling the current stage with SIGTERM,
// the (running) stage is killed with SIGKILL
#define WAITTIME 3

#define HL "\033[1;36m"
#define RED "\033[31m"
#define NORM "\033[0;37m"
#define PREF HL "--- " NORM

int shutdown;
int stagepid;
int zombie;
int initpid;


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
		//writes("Within handler\n");
		if ( signal == SIGTERM ){
				shutdown = 1; // halt
		}
		if ( signal == SIGINT ){
				shutdown = 2; // reboot
		}

		printf("sighandler stagepid: %d yombie %d\n",stagepid,zombie);
		kill(stagepid,SIGTERM);
	
		// set a timer, 
		// and kill the curent stage, 
		// when init is still running at that time
		settimer(WAITTIME);
}


void sigalarm(int signal){
		writes("alarm handler\n");
		if ( shutdown ){
				printf("shutdown: %d\n",shutdown);
				printf("stagepid: %d yombie %d\n",stagepid,zombie);
				kill(stagepid, SIGKILL);
				if ( zombie == stagepid ){ // stage hangs, didn't respond to sigkill
					 raise(SIGTERM); // kill ourselves / meaning continue in vexec, waitpid
				}
				zombie = stagepid; // save stagepid.
				settimer(WAITTIME); // when the stage process doesn't respond to the sigkill,
				// kill ourselves after "waittime"
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
		int w;
		do {
				w = waitpid( stagepid, &ws, 0 );
		} while ( ! ( WIFEXITED(ws) || WIFSIGNALED(ws)  || zombie ) );

		return(0);
}



int main(int argc, char **argv, char **envp){
		shutdown = 0;
		stagepid = 0;
		zombie = 0;

		log("start init");

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

		// Ctrl-Alt-Del sends sigint to init, but doesn't reboot
		reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_CAD_OFF,0);

START:
		zombie = 0;
		log("exec " STAGE1);
		vexec( STAGE1, argv, envp );

		int a = 0;

		while (!shutdown){
				log("exec " STAGE2);
				if ( vexec(STAGE2, argv, envp) )
						return(-1);
				if ( (a++) > 1 ){ // prevent spinning 
						warning("stage2 seems to die unexpectedly\nSleeping");
						a=0;
						sleep(5);
				}
		};

		if ( shutdown==1 )
				log("Shutdown");
		else
				log("Reboot");

		log("exec " STAGE3);
		settimer(WAITTIME);
		zombie = 0;
		vexec(STAGE3, argv, envp);

		if ( shutdown == 0 )
				goto START; // shutdown aborted. start with stage1 again

		log("Sync remaining file systems");
		sync();

		if ( shutdown == 1 ){
				log("Power off");
				reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_POWER_OFF,0);
				reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_HALT,0);
		}

		if ( shutdown == 2 ){
				log("Reboot");
				reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_RESTART,0);
		}

		log("Exit init.");
		
		return(0); // exit
}

