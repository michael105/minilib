
//+depends strchrnul
//+def
char *strrchr(const char *s, int c){
	char *ret = 0;
	char *tmp = (char*)s-1;
	while ( (tmp = strchrnul(tmp+1,c) ) && ( *tmp != 0 ) ){
			ret=tmp;
	}
	return(ret);
}


