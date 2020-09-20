//+cat userdb
//+doc get the group entry of the group "name".
// the last result is cached, multiple calls with the same
// name will return the cached result.
//+depends pwent mmap userdb_open ewrites open strcmp token_s  token_i
//+def
struct group *getgrnam(const char* name){
	if ( mlgl->groupfile.file==0 ){
		printsl("Open");
		if ( !userdb_open(&mlgl->groupfile,GROUPFILE) ) {
			ewrites("Unable to access " GROUPFILE "\n" );
			return(0);
		}
	} else {
		// return "cached" entry 
//	printsl("grname: ", mlgl->groupent.gr_name,"  name: ",name);
	if ( strcmp( mlgl->groupent.gr_name, name) == 0 ){
		printsl("cached");
		return( &mlgl->groupent );
	}
	}

//	printsl("grname2 : ", mlgl->groupent.gr_name,"  name: ",name);
	setgrent();
	struct group *ret;
	for ( ret=getgrent();ret;ret=getgrent() ){
		if ( strcmp( name, ret->gr_name ) == 0 )
			return(ret);
	}
	return(0);
}

