//+doc execute a path, wait until the executed file exits.
// Deviating of system() an absolute pathname is taken.
// sets errno on error.
//+depends seterrno waitpid exit execve vfork
//+def
int vexec( const char* path, char* const* argv, char* const* envp ){
		int pid = vfork();

		if ( pid == 0 ){
				int ret = execve(path, argv, envp );
				seterrno(ret);
				exit(ret); // exit with failure
		}

		int ws;
		int wpid;
		do {
				wpid = waitpid( pid, &ws, 0 ); // wait for any child (reap zombies)
		} while ( !( (wpid == pid) && (WIFEXITED(ws) || WIFSIGNALED(ws) )));

		return(WEXITSTATUS(ws));
}


