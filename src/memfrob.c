void* memfrob(void* s, unsigned int len){
		unsigned int a;
		char *c = s;
		for ( a=0; a<len;a++)
				c[a] = 	c[a] ^ 42;
		return ( s );
}
		
