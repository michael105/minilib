#ifndef fgets_c
#define fgets_c
//+header stdio.h
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
						size=0;
		}
		buf++;
		*buf = 0;
		return(ret);
}

//+depends fgets fgetc fileno read
//+macro gets(F) fgets(F,0xfffffff,stdin)



#endif
