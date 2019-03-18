#ifndef strcmp_c
#define strcmp_c

//+ansi string.h

//TODO: not implemented correct. need to return also -1.

int _strcmp(const char*c1,const char*c2,int len){
		int a = 0;
		while ( (c1[a] != 0) && (c2[a]!=0 ) && a != len ){
				//write(1,&c1[a],1);
				if ( c1[a] != c2[a] )
						return(1);
				a++;
		}
		if ( (c1[a] == 0 ) && ( c2[a] == 0 ) )
				return(0);
		return (1);
}



//+def
int strcmp(const char*c1,const char*c2){
		return( _strcmp(c1,c2,-1) );
}

//+def
int strncmp(const char*c1,const char*c2,int len){
		if ( len <=0 )
				return(-1);
		return(_strcmp(c1,c2,len) );
}

//+def
int memcmp(const void* c1,const void* c2,int len){
		const char* cc1 = c1;
		const char* cc2 = c2;
		if ( len <=0 )
				return(-1);
		int a = 0;
		while ( a != len ){
				//write(1,&c1[a],1);
				if ( cc1[a] != cc2[a] )
						return(1);
				a++;
		}
	 return(0);
}


#endif
