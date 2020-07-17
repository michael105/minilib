#ifndef strerror_r
#define strerror_r


//+header string.h
//+inline
static char* strerror( int errnum ){
#ifndef mini_verbose_errstr
		static char *errstr = "error: 000";
		static errstr[7] = '0';
		while ( errnum>99 ){
				errnum-=100;
				errstr[7]++;
		}
		errstr[8] = '0';
		while ( errnum>9 ){
				errnum-=10;
				errstr[8]++;
		}
		errstr[9] = 48+errnum; // 0+errnum..
		return( errstr );
#else
		return((char*)verbose_errstr(errnum));
#endif
}

#endif

