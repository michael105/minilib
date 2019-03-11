#ifndef strcmp_c
#define strcmp_c

//TODO: not implemented correct. need to return also -1.

int _strcmp(char*c1,char*c2,int len){
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




int strcmp(char*c1,char*c2){
		return( _strcmp(c1,c2,-1) );
}


int strncmp(char*c1,char*c2,int len){
		if ( len <=0 )
				return(-1);
		return(_strcmp(c1,c2,len) );
}

int memcmp(const char* c1,const char* c2,int len){
		if ( len <=0 )
				return(-1);
		int a = 0;
		while ( a != len ){
				//write(1,&c1[a],1);
				if ( c1[a] != c2[a] )
						return(1);
				a++;
		}
	 return(0);
}


#endif
