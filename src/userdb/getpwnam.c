//+cat userdb
//+doc get the passwd entry of the user "name".
// the last result is cached, multiple calls with the same
// name will return the cached result.
//+depends pwent mmap passwdfile_open ewrites open strcmp token_s token_i
//+def
struct passwd *getpwnam(const char* name){
	if ( !mlgl->passwdfile ){
		if ( !passwdfile_open() ) 
			return(0);
	} else {
		// return "cached" entry 
	if ( strcmp( mlgl->pwent.pw_name, name) == 0 )
		return( &mlgl->pwent );
	}

	char *p = mlgl->passwdfile;

	do {
		char *pw_name = token_s(&p);

		//printf("euid: %d\n",euid);
		if ( strcmp( name, pw_name ) == 0 ){ // found
			mlgl->pwent.pw_name = pw_name;
			mlgl->pwent.pw_passwd = token_s(&p);
			mlgl->pwent.pw_uid = token_i(&p);
			mlgl->pwent.pw_gid = token_i(&p);
			mlgl->pwent.pw_gecos = token_s(&p);
			mlgl->pwent.pw_dir = token_s(&p);
			mlgl->pwent.pw_shell = token_s(&p);
			return(&mlgl->pwent);
		}

		for ( int a = 0; a<6; a++ )
			token_s(&p);

	} while ( p < (mlgl->passwdfile+mlgl->passwdfilesize) );

	return(0); // not found
}


