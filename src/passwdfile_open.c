//+depends globals pwent ewrites
//+def
int passwdfile_open(){

	if ( mlgl->passwdfile )
		return(1);

	int fd = open( PASSWDFILE, O_RDONLY );
	if ( fd<=0 ){
		ewrites("Couldn't access " PASSWDFILE "\n" );
		return(0);
	}
	struct stat ststat;
	fstat(fd, &ststat );
	mlgl->passwdfile = mmap( 0, ststat.st_size, PROT_READ, 
			MAP_PRIVATE| MAP_LOCKED | MAP_POPULATE , fd, 0 );

	return(1);
}

