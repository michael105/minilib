//+doc execute a path, wait until the executed file exits.
// instead of system() an absolute pathname is taken.
//+def
int vexec( const char* path, char* const* argv, char* const* envp ){
		int pid = vfork();

		if ( pid == 0 ){
				int ret = execve(path, argv, envp );
				return(ret); // exit with failure
		}

		int ws;
		int wpid;
		do {
				wpid = waitpid( pid, &ws, 0 ); // wait for any child (reap zombies)
		} while ( !( (wpid == pid) && (WIFEXITED(ws) || WIFSIGNALED(ws) )));

		return(WEXITSTATUS(ws));
}



