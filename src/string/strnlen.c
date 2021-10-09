//+header string.h

//+doc return len of str.
// if str points to 0, return 0
// if no 0 is within max chars of str,
// return max
//+def
int strnlen(const char*str, int max){
	if ( !str )
		return(0);

	int a = 0;
	while ( str[a] != 0 ){
		a++;
		if ( a >= max )
			return(max);
	}
	return (a);
}

