//+cat userdb
//+depends open userdb
//+def
struct passwd* getpwent(){
	if ( !mlgl->passwdfile ){
		if ( !passwdfile_open() ) 
			return(0);
	}
	// end of file
	if ( mlgl->passwd_p >= (mlgl->passwdfile+mlgl->passwdfilesize) )
		return(0);

	char *p = token_s(&mlgl->passwd_p);
	if ( *p == 0 )
		return(0);
	mlgl->pwent.pw_name = p;
	mlgl->pwent.pw_passwd = token_s(&mlgl->passwd_p);
	mlgl->pwent.pw_uid = token_i(&mlgl->passwd_p);
	mlgl->pwent.pw_gid = token_i(&mlgl->passwd_p);
	mlgl->pwent.pw_gecos = token_s(&mlgl->passwd_p);
	mlgl->pwent.pw_dir = token_s(&mlgl->passwd_p);
	mlgl->pwent.pw_shell = token_s(&mlgl->passwd_p);

	return(&mlgl->pwent);
}


