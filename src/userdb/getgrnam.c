//+cat userdb
//+doc get the group entry of the group "name".
// the last result is cached, multiple calls with the same
// name will return the cached result.
//+depends grent setgrent getgrent mmap userdb_open ewrites open strcmp token_s  token_i
//+def
struct group *getgrnam(const char* name){
	if ( mlgl->groupfile.file==0 ){
		if ( !userdb_open(&mlgl->groupfile,GROUPFILE) ) {
			ewrites("Unable to access " GROUPFILE "\n" );
			return(0);
		}
	} else {
		if ( strcmp( mlgl->groupent.gr_name, name) == 0 ){
			// return "cached" entry 
			return( &mlgl->groupent );
		}
	}

	setgrent();
	for ( struct group* ret=getgrent();ret;ret=getgrent() ){
		if ( strcmp( name, ret->gr_name ) == 0 )
			return(ret);
	}
	return(0);
}

