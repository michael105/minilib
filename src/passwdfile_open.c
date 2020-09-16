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
	// map to memory, copy on write
	mlgl->passwdfile = mmap( 0, ststat.st_size, PROT_READ | PROT_WRITE, 
			MAP_PRIVATE, fd, 0 );

	close(fd);
	// append a 0, so two 00's are at the end
//	mlgl->passwdfile[ststat.st_size] = 0;
//	mlgl->passwdfile[ststat.st_size+1] = 0;

	mlgl->passwdfilesize = ststat.st_size;
	mlgl->passwd_p = mlgl->passwdfile;

	return(1);
}

