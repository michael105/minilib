#ifndef strerror_r
#define strerror_r


char *errstr = "error: 00";

//+header string.h
//+def
char* strerror( int errnum ){
#ifndef mini_verbose_errstr
		errstr[7] = '0';
		while ( errnum>9 ){
				errnum-=10;
				errstr[7]++;
		}
		errstr[8] = 48+errnum; // 0+errnum..
		return( errstr );
#else
		return((char*)verbose_errstr(errnum));
#endif
}

//+header stdio.h
//+depends fputs strerror strlen
//+def
void perror(const char *msg){
		if ( msg !=0 && msg[0] != '\0' )
				fputs( msg, stderr );

		fputs( strerror( errno ), stderr );
}


//+doc convert errno to str, with 3 chars length
// ending the string (located on the stack (!) 
// with two \0\0, when errno<100
//+def
const char *errno_str(int err){
		char *e="100\0";
		char *p = e;
		if ( err>99 ){
				err-=100;
		} else {
				p++;
		}
		e[1]+=err/10;
		e[2]+=err%10;

		return(p);
}



#endif

