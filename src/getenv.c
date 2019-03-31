#ifndef getenv_c
#define getenv_c

#ifndef dumbsyntaxchecker
char **mini_env;
#endif


//+header stdlib.h
//+def
char *getenv(const char* name){
		int b;
		for ( int a=0; mini_env[a]; a++ ){
				for ( b = 0; mini_env[a][b] == name[b]; b++ ){}
				if ( mini_env[a][b] == '=' ){
						return( &mini_env[a][b+1] );
				}
		}
		return(0);
}



#endif
