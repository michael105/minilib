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

		//printsl("dgb");
	char *p = token_s( &mlgl->groupfile,&mlgl->groupfile.p);
	//if ( *mlgl->groupfile.p2 < p ){ TODO
	if ( *mlgl->groupfile.p2 == 0 ){
		//printsl("dgb");
		//printsl(p);
		*mlgl->groupfile.p2 = p;
		*mlgl->groupfile.p2++;
		//*mlgl->groupfile.p2 = 0; mmap sets to 0. according to the manpage
	} else {
		//printsl("no - dbg");
		*mlgl->groupfile.p2++;
	}

	if ( *p == 0 )
		return(0); //error or end.

	mlgl->groupent.gr_name = p;
	mlgl->groupent.gr_passwd = token_s( &mlgl->groupfile,&mlgl->groupfile.p);
	mlgl->groupent.gr_gid = token_i( &mlgl->groupfile,&mlgl->groupfile.p);

	int count = 0;

	if ( *mlgl->groupfile.p2==0){
		char* members =  token_s( &mlgl->groupfile,&mlgl->groupfile.p);
		char *mbr = members;

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
	} else {
		do {
			mlgl->groupent.gr_mem[count] = token_s( &mlgl->groupfile,&mlgl->groupfile.p);
			//printsl( "member: ",mlgl->groupent.gr_mem[count] );
			count++;
			if ( count >= MAX_GROUPMEMBERS ){
				ewrites("Error: too many groupmembers. 2\n");
				return(0);
			}

		} while ( mlgl->groupfile.p < *mlgl->groupfile.p2 );
	}

	mlgl->groupent.gr_mem[count] = 0;
	return(&mlgl->groupent);
}


