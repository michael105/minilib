//+header stdlib.h
//+depends execve vfork environ ewrites waitpid
//+def
int system( const char* command ){
	
		int pid = vfork();

		char* const arg[4] = { "sh", "-c", (char*)command, 0 };

		if ( pid==0 ){
				execve( "/bin/sh", arg, (char* const*)environ );
				ewrites("Error. Couldn't exec sh in system()\n");
				exit(-1);
		}
		int ws;
		do {
				waitpid( pid, &ws, 0 );
		} while ( !WIFEXITED(ws) );

		return(WEXITSTATUS(ws));
}
