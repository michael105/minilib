
/// creat
//+depends open
//+def
int volatile creat( const char *s, int mode ){
		return(open( s, O_CREAT|O_WRONLY|O_TRUNC, mode) );
}



