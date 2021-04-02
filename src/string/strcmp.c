#ifndef mini_strcmp_c
#define mini_strcmp_c

//+include
//+header string.h
//+needs ctype.h

//+inc
//+def
int _strcmp(const char*c1,const char*c2,int len){
		int a = 0;
		while ( (c1[a] != 0) && (c1[a]==c2[a] ) && a != len ){
				a++;
		}
		if ( c1[a] > c2[a] )
				return(1);
		if ( c1[a] < c2[a] )
				return(-1);

		return(0);
}

//+inc
//+depends tolower
//+needs ctype.h
//+def
int _strcasecmp(const char*c1,const char*c2,int len){
		int a = 0;
		while ( (c1[a] != 0) && (c2[a]!=0 ) && a != len ){
				if ( c1[a] != c2[a] ){
						if ( tolower( c1[a] ) > tolower( c2[a] ) )
								return(1);
						if ( tolower( c1[a] ) < tolower( c2[a] ) )
								return(-1);
				}
				a++;
		}
		if ( (c1[a] == 0 ) && ( c2[a] == 0 ) )
				return(0);
		return (1);
}


//+inc
//+depends _strcasecmp
//+needs ctype.h
//+def
int strcasecmp(const char*c1,const char*c2){
		return( _strcasecmp(c1,c2,-1) );
}


//+depends _strcasecmp
//+inc
//+def
int strncasecmp(const char*c1,const char*c2,int len){
		if ( len <=0 )
				return(-1);
		return(_strcasecmp(c1,c2,len) );
}



//+depends _strcmp
//+inc
//+def
int strcmp(const char*c1,const char*c2){
		return( _strcmp(c1,c2,-1) );
}


//+depends _strcmp
//+inc
//+def
int strncmp(const char*c1,const char*c2,int len){
		if ( len <=0 )
				return(-1);
		return(_strcmp(c1,c2,len) );
}


#endif
