//+def
char *basename(char *path){
	if (path == 0 || *path == 0 )
		return ( ".");

	char *p;
	char *pos1 = path-1;
	char *pos2 = path-1;
	for ( p=path; *p!=0; p++ ){
			if ( *p=='/' ){
					if ( p>pos2+1 ){
							pos1 = pos2;
					}
					pos2 = p;
			}
	}

	if ( p-pos2>1 ) // chars after last /
			return(pos2+1);

	if ( pos2 == (path-1) ) // no / at all
			return(path);

	if ( pos1 == (path-1) )
			return(pos2);

	if ( *(pos2-1) == '/' ){
			*(pos2-1) = 0;
	}
			
	*pos2 = 0; // set trailing / to 0
	return( pos1+1 );
}
