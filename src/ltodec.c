//+include
//+def
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
//+def
int ltodec(long i, char *buf, int prec, char limiter ){
	if ( i < 0 ){
			buf[0]='-';
			i = -i;
			return(ultodec((unsigned long)i,&buf[1],prec,limiter) + 1 );
	}
	return(ultodec((unsigned long)i,buf,prec,limiter) );
}

