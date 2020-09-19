//+cat userdb
//+doc get the passwd entry of the user "name".
// the last result is cached, multiple calls with the same
// name will return the cached result.
//+depends pwent mmap userdb_open ewrites open strcmp token_s  token_i
//+def
struct passwd *getpwnam(const char* name){
	if ( !mlgl->passwdfile.file ){
		if ( !userdb_open(&mlgl->passwdfile,PASSWDFILE) ) 
			return(0);
	} else {
		// return "cached" entry 
	if ( strcmp( mlgl->pwent.pw_name, name) == 0 )
		return( &mlgl->pwent );
	}

	char *p = mlgl->passwdfile.file;

	do {
		char *pw_name = token_s( &mlgl->passwdfile,&p);

		//printf("euid: %d\n",euid);
		if ( strcmp( name, pw_name ) == 0 ){ // found
			mlgl->pwent.pw_name = pw_name;
			mlgl->pwent.pw_passwd = token_s( &mlgl->passwdfile,&p);
			mlgl->pwent.pw_uid = token_i( &mlgl->passwdfile,&p);
			mlgl->pwent.pw_gid = token_i( &mlgl->passwdfile,&p);
			mlgl->pwent.pw_gecos = token_s( &mlgl->passwdfile,&p);
			mlgl->pwent.pw_dir = token_s( &mlgl->passwdfile,&p);
			mlgl->pwent.pw_shell = token_s( &mlgl->passwdfile,&p);
			return(&mlgl->pwent);
		}

		for ( int a = 0; a<6; a++ )
			token_s( &mlgl->passwdfile,&p);

	} while ( p < (mlgl->passwdfile.file+mlgl->passwdfile.size) );

	return(0); // not found
}


