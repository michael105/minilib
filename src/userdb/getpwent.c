//+cat userdb
//+depends open userdb
//+def
struct passwd* getpwent(){
	if ( !mlgl->passwdfile.file ){
		if ( !userdb_open(&mlgl->passwdfile,PASSWDFILE) ) 
			return(0);
	}
	// end of file
	if ( mlgl->passwdfile.p >= (mlgl->passwdfile.file+mlgl->passwdfile.size) )
		return(0);

	char *p = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);
	if ( *p == 0 )
		return(0);
	mlgl->pwent.pw_name = p;
	mlgl->pwent.pw_passwd = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);
	mlgl->pwent.pw_uid = token_i( &mlgl->passwdfile,&mlgl->passwdfile.p);
	mlgl->pwent.pw_gid = token_i( &mlgl->passwdfile,&mlgl->passwdfile.p);
	mlgl->pwent.pw_gecos = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);
	mlgl->pwent.pw_dir = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);
	mlgl->pwent.pw_shell = token_s( &mlgl->passwdfile,&mlgl->passwdfile.p);

	return(&mlgl->pwent);
}


