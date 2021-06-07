//+doc get the groups of the calling process
// does not necessarily contain the primary group,
// which is given in the passwd entry.
// This function calls internally setgrent() and getgrent();
// therefore any iteration with getgrent will be resetted.
//+depends getpwuid setgrent strcmp grent pwent getusergroups getuid
//+def
int getgroups(int maxgroups, int *list){
	int uid = getuid();
	struct passwd* user = getpwuid(uid);
	if ( !user )
		return(-1);
	return(getusergroups(user->pw_name,maxgroups,list));
}
