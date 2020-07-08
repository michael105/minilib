#ifndef mini_ltodec_c
#define mini_ltodec_c

//+include
//+def
int ultodec(unsigned long ui, char *buf, int prec, char limiter ){
	long i = ui;
	unsigned long l;
	l= (unsigned long)10000000000000000000;
	int p = 20;
	int a = 0;
	while ( p>0 ){
			if ( a || ( (long)i-l > (long)0) ){
					a=1;
					int b=0;
					while ( i>=l ){
							b++;
							i=i-l;
					}
					*buf='0'+b;
					buf++;
			}
			p--;
			l=l/10;
	}
	*buf=0;
	return(p);
}




#if 0
int ultodec(unsigned long i, char *buf, int prec, char limiter ){
		int p = 0;
		if ( i>2^16 ){
				p=itodec((unsigned int)i-2^16, buf, prec, limiter);
				strcpy(&buf[p], "*2^16+"); // rude hack. Correct, but..
#todo: write ltodec
				p+=7;
		}
		return(uitodec((uint)i, &buf[p], prec, limiter));
}
#endif



//+def
int ltodec(long i, char *buf, int prec, char limiter ){
	if ( i < 0 ){
			buf[0]='-';
			i = -i;
			return(ultodec((unsigned long)i,&buf[1],prec,limiter) + 1 );
	}
	return(ultodec((unsigned long)i,buf,prec,limiter) );
}



#endif

