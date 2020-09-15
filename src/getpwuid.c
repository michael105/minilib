//+depends pwent mmap passwdfile_open ewrites open
//+def
struct passwd *getpwuid(uid_t uid){
		if ( !mlgl->passwdfile ){
			if ( !passwdfile_open() ) 
				return(0);
		}

		char *p = mlgl->passwdfile;

		write(1,p,64);
		do {
			char *puid = p;
			for ( int a = 0; a<2; a++ )
				do { 
					puid++; 
				} while (*puid != ':');
			puid++;
			int euid = 0;
			while ( *puid>='0' && *puid <= '9' ){
				euid = euid*10 + *puid-'0';
				puid++;
			}
			printf("euid: %d\n",euid);
			if ( euid == uid ){ // found


			}
			for ( p++; *p && *(p-1)!='\n'; p++ );
		} while ( *p );

		return(0); // not found
}
