#ifndef strerror_r
#define strerror_r


char *errstr = "err: 00";

//+header string.h
//+def
char* strerror( int errnum ){
		errstr[5] = '0';
		while ( errnum>9 ){
				errnum-=10;
				errstr[5]++;
		}
		errstr[6] = 48+errnum; // 0+errnum..
		return( errstr );
}




#endif

