#ifndef mini_ltodec_c
#define mini_ltodec_c

//+include
//+def
int ultodec(unsigned long ui, char *buf, int prec, char limiter ){
	long l;
	l= (long)1000000000000000000;
	int p = 19;
	int a = 0;
	int c = 0;
	// getting compiler warnings, when defining the value direct.
	if ( ui>=((unsigned long)1000000000000000000*10) ){
			a=1;
			ui-=((unsigned long)1000000000000000000*10);
			*buf='1';
			buf++;
			c=1;
	}  else {
			if ( prec >=20 ){
					a=1;
					*buf='0';
					buf++;
					c=1;
			}
	}

	while ( p>0 ){
			if ( p<=prec )
					a=1;
			if ( a || ( (long)(ui-l) >= (long)0) ){
					a=1;
					int b=0;
					while ( ui>=l ){
							b++;
							ui-=l;
					}
					if ( limiter ){
							if ( p%3 == 0 ){
									*buf=limiter;
									buf++;
									c++;
							}
					}

					*buf='0'+b;
					buf++;
					c++;
			}
			p--;
			l=l/10;
	}
	*buf=0;
	return(c);
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

