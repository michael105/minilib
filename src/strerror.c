#ifndef strerror_r
#define strerror_r


char *errstr = "error: 00";

//+header string.h
//+def
char* strerror( int errnum ){
		errstr[7] = '0';
		while ( errnum>9 ){
				errnum-=10;
				errstr[7]++;
		}
		errstr[8] = 48+errnum; // 0+errnum..
		return( errstr );
}

//+header stdio.h
//+depends fputs strerror strlen
//+def
void perror(const char *msg){
		if ( msg !=0 && msg[0] != '\0' )
				fputs( msg, stderr );

		fputs( strerror( errno ), stderr );
}


#endif

