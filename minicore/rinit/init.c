#if 0
mini_start
mini_writes
mini_vfork
mini_execve
mini_sleep
mini_exit

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
// starts /etc/rinit/1 and hands all over all arguments, invoked with.
//
// after "1" has been started, 
// init reads from the named pipe /etc/rinit/initpipe,
// and handles signals.
//
// depending on signal/pipe input, 
// the next runlevel is started.
//
// 
// 
int main(int argc, char **argv, char **envp){
		
		writes("Start init\n");
		writes("Start /etc/rinit/1\n");

		int pid = vfork();

		if ( pid == 0 ){
				execve("/etc/rinit/1", argv, envp );
				writes("Error. Couldn't execute /etc/rinit/1\n");
				sleep(5);
				exit(1);
		}

		return(0); // exit
}

