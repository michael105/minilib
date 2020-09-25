//+doc get the groups of the calling process
//+depends getpwuid setgrent strcmp grent pwent
//+def
int getgroups(int maxgroups, int *list){
	int uid = getuid();
	int groups = 0;
	struct passwd* user = getpwuid(uid);
	if ( !user )
		return(-1);

	setgrent(); // set groups to the first entry

	struct group* gr = 0;

	while ( groups<maxgroups ){
		gr = getgrent();
		if ( !gr ) // last entry, or error
			return(groups);
		int a=0;
		for ( char* u=*gr->gr_mem;u;u=gr->gr_mem[++a] ){
			//printsl( "u ",u );
			if ( strcmp( u,user->pw_name ) == 0 ){
				*list=gr->gr_gid;
				list++;
				groups++;
				break;
			}
		}
	}

#ifdef mini_errno
	errno=EINVAL;
#endif
	return(-1);
}
