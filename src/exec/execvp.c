#ifndef mini_exevp_c
#define mini_exevp_c
//+header unistd.h
////+include

//+depends environ execve getenv access
//+doc When invoked with a filename, starting with "." or "/",
// interprets this as absolute path. (calls execve with the pathname)
// Looks for file in the PATH environment, othwerise.
//+def
static int execvpe(const char *file, char *const argv[], char *const envp[]){
		if ( file[0] == 0 || file[0] == '.' || file[0] == '/' )
				return( execve( file, argv, envp ) );

		char buf[PATH_MAX];
		if ( where( file, buf ))
				return( execve( buf, argv, envp ) );

		return(-1);
};


#endif
