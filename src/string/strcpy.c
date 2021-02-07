
//+def
char *strcpy(char *dest, const char *src){
	char *d;
	for ( d = dest; *src; src++,d++ )
		*d=*src;
	*d = 0;
	return(dest);
}


