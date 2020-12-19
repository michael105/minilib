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

		char *path = getenv("PATH");
		if ( !path ){
				//return(-1);
				path = "/bin:/usr/bin";
		}

		char e[PATH_MAX];
		char *p = e;
		do {
				*p = *path;
				p++; path++;
				if ( *path == ':' || *path == 0 ){
						*p++ = '/';
						char *c= (char*)file;
						do {
								*p++ = *c++;
						} while ( *c );
						*p = 0;
						//printfs("access: %s\n", e );
						if ( access( e, R_OK | X_OK ) == 0 ){
								//printfs("exec: %s\n", e );
								return( execve( e, argv, envp ) );
						}
						p=e;
						if ( *path == 0 ){
								return(-1);
						}
						path++;
				}
		} while (1);
		//return(-1);
};


#endif
