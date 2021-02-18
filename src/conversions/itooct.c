//+doc convert int to octal
// return the number of chars written.
//+def
int itooct(int i, char *buf){
		int p = 0;
		int count = 0;
		char tmp[16];
		if ( i == 0 ){
				*buf = '0';
				buf++;
				count++;
		} 
		if ( i<0 ){
				i=-i;
				*buf='-';
				buf++;
				count++;
		}

		while(i!=0){
				tmp[p]=(i&7)+'0';
				i=i>>3;
				p++;
		}
		count += p;
		while(p>=0){
				*buf = tmp[p];
				buf++;
				p--;
		}
		*buf=0;

		return(count+1);
}


