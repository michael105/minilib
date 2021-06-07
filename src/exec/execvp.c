#ifndef mini_exevp_c
#define mini_exevp_c
//+header unistd.h
////+include

//+doc locate an executable in PATH
//+def
int where(const char *file,char *buf){
		char *path = getenv("PATH");
		if ( !path ){
				path = "/bin:/usr/bin:/sbin:/usr/sbin:/usr/local/bin:/local/bin";
		}

		char *p = buf;
		do {
				*p = *path;
				p++; path++;
				if ( *path == ':' || *path == 0 ){
						*p++ = '/';
						for ( char *c= (char*)file; (*p++ = *c++); );
						//printfs("access: %s\n", e );
						if ( access( buf, R_OK | X_OK ) == 0 ){
								//printfs("exec: %s\n", e );
								return( 1 );
						}
						if ( !*path )
								return(0);

						p=buf;
						path++;
				}
		} while (1);
}

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
