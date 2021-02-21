//+def
void* calloc(int size){

	char* p = malloc(size);
	if ( !p )
		return(0);

	char *pp=p;

#ifdef mini_OPTIMIZATIONS
#ifdef X64
		for(char *e = p+size-7; pp<e;pp+=8)
			*(long*)pp=0;
#endif

		for(char *e = p+size-3; pp<e;pp+=4)
			*(int*)pp=0;

#endif

		for(char *e = p+size; pp<e;pp++)
			*pp=0;

//	for(char *pp = p; size-->0;pp++)
//		*pp=0;

	return(p);
}
