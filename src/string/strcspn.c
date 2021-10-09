//+doc look for the first place in s1,
// containing one of the chars of s2.
// Optimizes a bit (+16Bytes code),
// when OPTIMIZE is defined
//+def
int strcspn(const char *s1, const char *s2){
	const char *p= s1;

#ifdef OPTIMIZE
	// build a bitmask of all accepted chars
	char bm = 0;
	for ( const char *acc = s2; *acc; acc++ ){
		bm |= *acc;
	}
#endif


	while( *p ){
#ifdef OPTIMIZE
		if ( *p & bm )
#endif
		for ( const char *acc = s2; *acc; acc++ ){
			if ( *acc == *p )
				return(p-s1);
		}
		p++;
	}
	return( p-s1 );
}

