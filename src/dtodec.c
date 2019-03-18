//convert double to string
//return number of bytes written to buf.
//doesn't convert numbers > 2^31 (!!!)
//doesn't round(!)
//max. prec after the dot: 8 digits. (!!)

//+ansi stdio.h
//+def
int dtodec(double d, char* buf, int precision){
		int i = (int) d;
		unsigned int i2;
		if ( d >= 0 )
			 i2 = (unsigned int)((d-i)*1000000000+0.1);
		else 
			 i2 = (unsigned int)((double)(-d+i)*1000000000+0.1);


		int p;
		if ( (d<=-1) || (d>0) )
				p = itodec(i,buf,0,0);
		else {
				buf[0] = '-';
				buf[1] = '0';
				p = 1;
		}

	
		buf[p+1]='.';
		int p2 = uitodec(i2,&buf[p+2],9,0);
		return(p+p2+2-9+precision);
}
