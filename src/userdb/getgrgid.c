//+cat userdb
//+doc get the group entry of the group "gid".
// the last result is cached, multiple calls with the same
// name will return the cached result.
//+depends grent setgrent getgrent mmap userdb_open ewrites open strcmp token_s token_i pwent
//+def
struct group *getgrgid(gid_t gid){
	if ( mlgl->groupfile.file==0 ){
		if ( !userdb_open(&mlgl->groupfile,GROUPFILE) ) {
			ewrites("Unable to access " GROUPFILE "\n" );
			return(0);
		}
	} else {
		if ( mlgl->groupent.gr_gid == gid ){
			// return "cached" entry 
			return( &mlgl->groupent );
		}
	}

	setgrent();
	for ( struct group* ret=getgrent();ret;ret=getgrent() ){
		if ( mlgl->groupent.gr_gid == gid ){
			return(ret);
	}
	}
	return(0);
}


