//+doc conversion
// doesn't check for overflow(!)
// For linux x64, long long and long both have 64 bit.
// Therefore, strtoll just calls strtol
//+needs isspace strtol
//+def
long long int strtoll(const char *c, const char **endp, int base){
	return((long long)strtol(c,endp,base));
}

