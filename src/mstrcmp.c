#ifndef strcmp_c
#define strcmp_c

//TODO: not implemented correct. need to return also -1.

int _mstrcmp(char*c1,char*c2,int len){
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




int mstrcmp(char*c1,char*c2){
		return( _mstrcmp(c1,c2,-1) );
}


int mstrncmp(char*c1,char*c2,int len){
		if ( len <=0 )
				return(-1);
		return(_mstrcmp(c1,c2,len) );
}


#endif
