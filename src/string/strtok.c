//+depends strtok_r
//+def
char* strtok(char *s, const char *delim){
	static char *last;
	return strtok_r(s, delim, &last);
}
