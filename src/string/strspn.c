//+def
int strspn(const char *s1, const char *s2){
	const char *p= s1;
	const char *acc= s2;

	do { 
		if ( *acc == *p ){
			p++; acc = s2;
		}
	} while(	*p && *(acc++) );
	
	return( p-s1 );
}

