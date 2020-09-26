//+doc needs rewrite.
// now nonstandard.
//+depends getusergroups
//+def
int getgrouplist(const char* user, gid_t group, gid_t *groups, int *ngroups){
	
	int gr = getusergroups(user,*ngroups,groups);

	for ( int a = 0; a<gr; a++ ){
		if ( group == groups[a] )
			return(gr); // group already within the list
	}
	if ( gr>=*ngroups-1 )
		return(-1);

	groups[gr] = group; // append group

	return(gr+1);
}
