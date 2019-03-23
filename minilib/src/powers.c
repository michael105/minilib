// calc powers.
// stolen (modified slightly) from Eric Jablow.
// http://c2.com/cgi/wiki?IntegerPowerAlgorithm / http://c2.com/cgi/wiki?EricJablow

/*
float fpowerui(float x, unsigned int n) {
		float aux = 1.0;
		while (n > 0) {
				if (n & 1) {    // odd?
						aux *= x;
						if (n == 1) return aux;
				}
				x *= x;
				n >>= 1;
		}
		return aux;
}

int ipoweriui(int x, unsigned int n) {
		int aux = 1;
		while (n > 0) {
				if (n & 1) {    // odd?
						aux *= x;
						if (n == 1) return aux;
				}
				x *= x;
				n >>= 1;
		}
		return aux;
}*/

 /* ------------------------------------------------------------------------- */
// written by me..
// todo: negative: x^n == x/x^n+1 ... ->ret float..
int ipoweriui(int x, unsigned int n){
		int t;
		switch (n){
			case 0: return( 1 );
			case 1:	return( x );
		}

		if ( n & 1 ){
				t = ipoweriui(x,((n-1)>>1) );
				return( t * t * x );
		} else {
				t = ipoweriui(x,n>>1);
				return( t*t );
		}
}

// useless. but would work for doubles.
int ipoweri(int x, int n){
		if ( n >0 )
				return(ipoweriui(x,n));
		//n<0
		return(1/ipoweriui(x,n));
}





