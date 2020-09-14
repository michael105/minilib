//+header stdlib.h

//+depends environ
//+def
char* getenv(const char* name){
		int b;
		for ( int a=0; environ[a]; a++ ){
				for ( b = 0; environ[a][b] == name[b]; b++ ){}
				if ( ( environ[a][b] == '=' ) && (name[b]==0) ){
						return( &environ[a][b+1] );
				}
		}
		return(0);
}

