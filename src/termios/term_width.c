//+doc get the terminal width
// reads the environmental var COLS,
// if not present, returns 80.
// Doesn't check for the existence of a terminal.
//+depends termio getenv environ
//+def
int term_width(){
	char *p = getenv("COLUMNS");
	if ( !p ) return(80);
	int ret = 0;
	while ( *p ){
		ret = ret*10 + *p-'0';
		p++;
	}
	return(ret);
}

