#ifndef strdup_c
#define strdup_c

//+header string.h
//+depends malloc strcpy strlen
//+def
char *strdup(const char *source){
	char *d =  malloc(strlen(source));
	if ( !d ) return(0);
	strcpy(d,source);
	return(d);
}



#endif

