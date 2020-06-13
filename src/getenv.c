#ifndef getenv_c
#define getenv_c

//+header stdlib.h
//+depends environ
//+def
char *getenv(const char* name){
		int b;
		for ( int a=0; environ[a]; a++ ){
				for ( b = 0; environ[a][b] == name[b]; b++ ){}
				if ( environ[a][b] == '=' ){
						return( &environ[a][b+1] );
				}
		}
		return(0);
}


//+depends environ getenv
//+def
int todo_putenv( char *s ){


	return(0);
}

#endif
