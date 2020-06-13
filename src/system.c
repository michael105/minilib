//+header stdlib.h
//+depends execve vfork environ fwrites waitpid
//+def
int system( const char* command ){
	
		int pid = vfork();

		const char *arg[4] = { "sh", "-c", (char*)command, 0 };

		if ( pid==0 ){
				execve( "/bin/sh", arg, (const char**)environ );
				fwrites(fileno(stderr), "Error. Coudln't exec sh in system()\n");
				exit(-1);
		}
		int ws;
		waitpid( pid, &ws, 0 );

		return(WEXITSTATUS(ws));
}
