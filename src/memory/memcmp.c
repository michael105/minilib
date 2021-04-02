//+depends
//+def
int memcmp(const void* c1,const void* c2,int len){
		const char* cc1 = c1;
		const char* cc2 = c2;
		if ( len <=0 )
				return(-1);
		int a = 0;
		len--;
		while ( (a < len) && (cc1[a]==cc2[a]) ) a++;

		if ( cc1[a] > cc2[a] )
				return(1);
		if ( cc1[a] < cc2[a] )
				return(-1);

	 return(0);
}


