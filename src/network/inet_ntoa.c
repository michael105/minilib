//+doc convert a address
// This returns a pointer to a string in the globals,
// therefore the routine isn't reentrant.
// (whoever thought this might be a good idea..)
//+depends network
//+def
char* inet_ntoa( struct in_addr in){
	union { uint32_t i; char c[4]; } u = { .i=in.s_addr };
	char *p = mlgl->inet_ntoa_addr-1;

	for ( int n=0; n<4; n++ ){
		p++;
		if ( u.c[n] > 9 ){
			if ( u.c[n] > 199 ){
				*p = '2';
				p++;
				u.c[n]-=200;
			} else if ( u.c[n] > 99 ){
				*p = '1';
				p++;
				u.c[n]-=100;
			} 
			*p = '0';
			while ( u.c[n] > 9 ){
				u.c[n]-=10;
				*p += 1;
			}
			p++;
		}
		*p = '0' + u.c[n];

		p++;
		*p = '.';
	}

	*p = 0;
	return( mlgl->inet_ntoa_addr );
}
