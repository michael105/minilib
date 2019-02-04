#ifndef atoi_c
#define atoi_c

int atoi(char *c){
		int t,a=0;
		int ret=0;
		int dez = 1;

		while( c[a] != 0 ){ 
				a++; 
		}
		while ( a>0 ){
				a--;
				if ( (c[a] > 48 ) && ( c[a] < 58 ) ){
						t = c[a] - 48;
						if ( t & 1 )
								ret += dez;
						dez <<= 1;
						if ( t & 2 )
								ret += dez;
						dez <<= 1;
						if ( t & 4 )
								ret += dez;
						dez <<= 1;
						if ( t & 8 )
								ret += dez;
				} else {
						dez <<= 3;
				}
				dez += (dez >> 2);
		}
		if ( c[0] == '-' )
				ret = -ret;
		return(ret);
}


#endif
		
