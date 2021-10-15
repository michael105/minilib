//+doc get a line like fgets, but return the len of the read string.
//+depends fgetc
//+def
int fgetsn(char *buf, int size, FILE* F){
	char *ret = buf;

	*buf = (char)fgetc(F);
	if ( !*buf ) // EOF
		return(0);
	if ( *buf == '\n' )
		size=0;

	while( --size >0 ){
		buf++;
		*buf = (char)fgetc(F);
		if ( *buf == 0 )
			return(buf-ret);
		if ( *buf == '\n' )
			size=0;
	}
	buf++;
	*buf = 0;
	return(buf-ret);
}


