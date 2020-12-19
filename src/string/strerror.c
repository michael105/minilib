#ifndef strerror_r
#define strerror_r


//+header string.h
//+def
static char* strerror( int errnum ){
#ifndef mini_verbose_errstr
		static char errstr[18];
		char* msg = "Error, errno: 000";
		for ( char *c = errstr; (*c=*msg); c++ && msg++ );
		// code below works. would be faster.
		// but adds more than 60 Bytes,
		// and performance might be irrelevant at this location.
		/*while ( errnum>99 ){
				errnum-=100;
				errstr[14]++;
		}
		while ( errnum>9 ){
				errnum-=10;
				errstr[15]++;
		}*/
		errstr[14]+=errnum/100;
		errstr[15]+=(errnum%=100)/10;
		errstr[16]+=errnum%10; // 0+errnum..
		return( errstr );
#else
		return((char*)verbose_errstr(errnum));
#endif
}

#endif

