#ifndef mini_itodec_c
#define mini_itodec_c
//+ansi stdio.h
//
// convert int to string.
// prec: precision, e.g. 4=> 0087 
//+def
int uitodec(unsigned int i, char *buf, int prec, char limiter ){
		int p = 0;
		int a;
		int t1,t2,t3,dec;
		//unsigned int ut1,ut2,ut3;
		char n;
		prec = prec - 10; // Maximale Stellenanzahl 


		if ( i==0 ){
				buf[0] = '0';
				//p++;
				//return(
		}

		int trailing = 1;

	const int div[13] = {0, 100000000, 10000000, 1000000, 0, 100000, 10000, 1000, 0, 100, 10, 1};
	
	if ( i >= 1000000000){
			//prints("hier.\n");
			p=1;
			prec=0;
			if ( i>=2000000000 ){
					i-=2000000000;
				if ( i>=1000000000 ){
						if ( i>=2000000000 ){
								buf[0] = '4';
								i-=2000000000;
						} else {
								buf[0] = '3';
								i-=1000000000;
						}
					} else {
						buf[0] = '2';
						//i-=2000000000;
					}
			}	else {
					buf[0] = '1'; 
					i-=1000000000;
			}
	trailing = 0;
	} else {
			if ( prec == 0 ){
					buf[0] = ' ';
					p++;
			} else
					prec++;
	}


	for (a=0;a<12;a++){
			if ( div[a] == 0 ){
					if ( (limiter != 0 ) && (prec==0) ){
							buf[p] = limiter;
							p++;
					}
			} else {
			n = '0';

			if ( (t1=(i - div[a])) >= 0 ){
					prec = 0;
					trailing = 0;
					n = '1';
					if ( (t2=(t1-(dec=(div[a]<<2)))) >= 0){
							if ( (t3=t2-dec) >= 0 ){
									n = '9';
									i = t3;
									goto write;
							} else {
									n = '5';
									t1 = t2;
							}
					} 
					if ( (t2=(t1-(div[a]<<1) ) ) >=0 ){
							t1=t2;
							n += 2;
					}
					if ( (t2=(t1-(div[a]) ) ) >=0 ){
							t1=t2;
							n += 1;
					}
					i = t1;
			}

			if ( prec == 0 ){
			write:
					if ( trailing )
							buf[p] = ' ';
					else
							buf[p] = n;
					p++;
			} else
					prec++;
					//buf[p] = 'x';
					//p++;
			}
	}
	if ( p==0 )
			p=1;
	buf[p] = 0;

	return(p);
}

	
//+depends uitodec
//+def
int itodec(int i, char *buf, int prec, char limiter ){
	if ( i < 0 ){
			buf[0]='-';
			i = -i;
			return(uitodec((unsigned int)i,&buf[1],prec,limiter) + 1 );
	}
	return(uitodec((unsigned int)i,buf,prec,limiter) );
}


#endif
