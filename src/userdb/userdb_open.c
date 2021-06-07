//+depends globals ewrites
//+def
int userdb_open(userdb *udb, const char* file){

	if ( udb->file )
		return(1);

	int fd = open( file, O_RDONLY );
	if ( fd<=0 ){
		ewrites("Error opening passwdfile/group" );
		return(0);
	}
	struct stat ststat;
	fstat(fd, &ststat );
	// map to memory, copy on write
	udb->file = mmap( 0, ststat.st_size * 2, PROT_READ | PROT_WRITE, 
			MAP_PRIVATE, fd, 0 );

	close(fd);

	udb->p = udb->file;
	udb->size = ststat.st_size;
	//printsl("1");
	udb->p2 = (char**)(udb->file+ststat.st_size);
	//printsl("1");
//	for ( char *p = udb->p2; p<udb->file+ ststat.st_size*2; p++ ){
//		*p=0;
//	}

	return(1);
}

