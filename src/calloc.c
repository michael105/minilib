//+def
void* calloc(int size){
	char* p = malloc(size);
	if ( !p )
		return(0);

	// OPTIMIZE here
	// assign integers or longs.

	for(char *pp = p; size-->0;pp++)
		*pp=0;

	return(p);
}
