//+doc locate an executable in PATH
//+depends access getenv
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


