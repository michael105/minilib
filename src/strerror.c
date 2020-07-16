#ifndef strerror_r
#define strerror_r


//+header string.h
//+def
char* strerror( int errnum ){
#ifndef mini_verbose_errstr
		char *errstr = "error: 000";
		errstr[7] = '0';
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

//+doc convert errno to str, with 3 chars length
// ending the string (located in the bss section)
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

