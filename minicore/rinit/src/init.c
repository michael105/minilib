#if 0
# minilib configuration

COMPILE start,writes,vfork,execve,sleep,exit,waitpid,prints,printsl,sigaction,\
			  sigaddset,sigemptyset,sigfillset,raise

# debugging definitions
# COMPILE printf,itodec; mini_buf 256

#LDSCRIPT text_and_bss
SHRINKELF
INCLUDESRC
return
#endif

/*
 misc 2020/06

		rinit init tools
    Copyright (C) 2020,2021  Michael (misc) Myer

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.



Based on minilib,
Copyright (c) 2012-2021, Michael (misc) Myer
(misc.myer@zoho.com, www.github.com/michael105)
Donations welcome: Please contact me.
All rights reserved.
The licensing terms of minilib are in the file LICENSE.minilib.
(Opensource, free to use also commercially with attribution)

----------------

 a minimal init
 
 starts /etc/rinit/rinit.boot and hands all over all arguments, invoked with.
 rinit.boot executes all files within /etc/rinit/boot, starting with B,
 in order of the numbering.

 after "rinit.boot" has exited, 
 /etc/rinit/rinit.run is started, and restarted if it should exit.
 rinit.run is supplied with the runlevel to start 
 (defaults to "default", so all files in /etc/rinit/default,
 starting with B, are executed.




 on signals SIGINT, SIGTERM (->shutdown) and Ctrl+Alt+Del (->reboot)
 /etc/rinit/rinit.run is sent SIGTERM, 
 when not responding past WAITTIME seconds SIGKILL,
 and after it's termination
 /etc/rinit/rinit.shutdown is executed.


 SIGQUIT: send the current stage a sigterm.
    when the current stage is stage rinit.run, 
		restart the process after termination


 SIGABRT: cancel a shutdown.
 		if stage 3 is running, send SIGABRT to the process, and restart at stage 1.
		is stage 2 is still running, and a shutdown is in progress,
		send stage 2 SIGABRT. If the process exits restart stage 2
*/
 
#include "config.h"

int shutdown;
int stagepid;
int zombie;

// log functions
void _log(const char *pref, const char *msg){
	printsl(pref,NORM,msg);
}

void error(const char *msg){
	_log( COLOR_ERROR "init - error: ", msg );
}

void warning(const char *msg){
	_log( COLOR_WARNING "init - warning: ", msg );
}

void log(const char *msg){
	_log( COLOR_LOG "--- " NORM "init: ", msg );
}

// set a timer, which calls sigalarm
void settimer(int secs){
	struct itimerval timer = { 
		.it_value.tv_sec  = secs,
		.it_value.tv_usec = 0 };
	setitimer (ITIMER_REAL, &timer, 0);
}

// handle shutdown and reboot
void sighandler(int signal){
	if ( signal == SIGTERM ){
		shutdown = 1; // halt
		log("Shutdown");
	}
	if ( signal == SIGINT ){
		shutdown = 2; // reboot
		log("Reboot");
	}

	kill(stagepid,SIGTERM);

	// set a timer, 
	// and kill the curent stage, 
	// when init is still running after WAITTIME seconds
	settimer(WAITTIME);
}

// timeout after signalling the currently running stage
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

// abort a shutdown
void sigabrt(int signal){
	if ( shutdown ){
		shutdown = 0;
		warning("Abort shutdown");
		kill(stagepid, SIGABRT);
	}
}

// execute 'exec' and wait for it's termination
// reap all children
int vexec( const char* exec, char* const* argv, char* const* envp ){
	stagepid = vfork();

	if ( stagepid == 0 ){
		execve(exec, argv, envp );
		error("Couldn't execute");
		error(exec);
		sleep(3);
		exit(1); // exit with failure
	}

	int ws;
	int pid;
	// the main loop, while running a stage ( pid != stagepid )
	do {
		pid = waitpid( -1, &ws, 0 ); // wait for any child (reap zombies)
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

	while (1){
		// stage 1
		zombie = 0;
		log("Run " STAGE1);
		vexec( STAGE1, argv, envp );

		int a = 0;
		char *st2av[3] = { STAGE2, "                ",0 };

		// stage 2
		while (!shutdown){
			log("Run " STAGE2);
			vexec(STAGE2, st2av, envp);
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
			sync();
			reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_POWER_OFF,0);
			reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_HALT,0);
		}

		if ( shutdown == 2 ){
			log("Reboot");
			sync();
			sync();
			reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_RESTART,0);
		}

		// ( shutdown == 0 )
	}; // shutdown aborted. start with stage1 again

	return(0); // silence compiler warning
}

