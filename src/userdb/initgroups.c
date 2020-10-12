//+def
int initgroups(const char* user, gid_t group){
	struct passwd* pw = getpwnam(user);
	if ( !pw )
		return(-1);

	int grl[MAXGROUPS];
	int c = getusergroups(user,MAXGROUPS,grl);
	int ret = setgroups(c,grl);

	if ( ret<0 )
		return(-1);

	if (setgid(pw->pw_gid) < 0 )
		return(-1);

	return(0);
}
