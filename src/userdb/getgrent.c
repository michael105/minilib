//+cat userdb
//+depends open userdb
//+def
struct group* getgrent(){
	if ( !mlgl->groupfile.file ){
		if ( !userdb_open(&mlgl->groupfile,GROUPFILE) ) 
			return(0);
	}
	// end of file
	if ( mlgl->groupfile.p >= (mlgl->groupfile.file+mlgl->groupfile.size) )
		return(0);

	char *p = token_s( &mlgl->groupfile,&mlgl->groupfile.p);
	if ( *p == 0 )
		return(0); //error or end.
	mlgl->groupent.gr_name = p;
	mlgl->groupent.gr_passwd = token_s( &mlgl->groupfile,&mlgl->groupfile.p);
	mlgl->groupent.gr_gid = token_i( &mlgl->groupfile,&mlgl->groupfile.p);
	char* members =  token_s( &mlgl->groupfile,&mlgl->groupfile.p);
	char *mbr = members;
	int count = 0;
	while ( members < mlgl->groupfile.p ){
		if ( *members == ',' ){
			*members = 0; 
		}
		if ( *members == 0 ){
			mlgl->groupent.gr_mem[count] = mbr; // 0, when no members.
			mbr=(members+1);
			count++;
			if ( count >= MAX_GROUPMEMBERS ){
				ewrites("Error: too many groupmembers.\n");
				return(0);
			}
		}
		members++;
	}
	mlgl->groupent.gr_mem[count] = 0;
	return(&mlgl->groupent);
}


