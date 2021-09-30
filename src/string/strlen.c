//+header string.h

//+doc return len of str.
// if str points to 0, return 0
//+def
int strlen(const char*str){
	if ( !str )
		return(0);

	int a = 0;
	while ( str[a] != 0 ){
		a++;
	}
	return (a);
}

