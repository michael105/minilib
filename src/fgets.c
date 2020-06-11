
//+depends fgetc
//+def
char* fgets(char *buf, int size, FILE* F){
		char *ret = buf;

		*buf = (char)fgetc(F);
		if ( !*buf ) // EOF
				return(0);

		while( --size >0 ){
				buf++;
				*buf = (char)fgetc(F);
				if ( *buf == 0 )
						return(ret);
				if ( *buf == '\n' )
						size=-0;
		}
		buf++;
		*buf = 0;
		return(ret);
}
