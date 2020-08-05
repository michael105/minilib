
//+depends memcpy
//+def
char *strncpy(char *dest, const char *src, int n){
		return( memcpy( dest, src, n ) );
}


