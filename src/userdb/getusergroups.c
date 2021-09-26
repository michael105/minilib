//+doc get the supplementary groups for the user uid.
// does not necessarily contain the primary group,
// which is given in the passwd entry.
// This function calls internally setgrent() and getgrent();
// therefore any iteration with getgrent will be resetted.
//+depends getpwuid setgrent strcmp grent pwent getgrent
//+def
int getusergroups(const char* user, int maxgroups, int *list){
	int groups = 0;
	setgrent(); // set groups to the first entry

	struct group* gr = 0;

	while ( groups<maxgroups ){
		gr = getgrent();
		if ( !gr ) // last entry, or error
			return(groups);
		int a=0;
		for ( char* u=*gr->gr_mem;u;u=gr->gr_mem[++a] ){
			//printsl( "u ",u );
			if ( strcmp( u,user ) == 0 ){
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
