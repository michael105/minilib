#ifndef mini_itobin_h
#define mini_itobin_h



//+ansi stdio.h
//+def
int _itobin(int i, char*buf, int prec, int groups ){
		prec -= 32;
		int a,p=0;
		int g = 0;
		for ( a=0; a<32; a++ ){
				if (i&0x80000000 ){
						prec = 0;
						buf[p] = '1';
						p++;
				} else {
						if ( prec == 0 ){
								buf[p] = '0';
								p++;
						} else
								prec++;
				}
				i <<= 1;
				g++;
				if ( (prec==0) && (g>=groups) ){
						g=0;
						buf[p] = ' ';
						p++;
				}
		}
		if ( p == 0 ){
				buf[0] = '0';
				p++;
		}
		buf[p] = 0;
		return(p);
}

//+doc convert a number to a binary representation.
// the conversion assumes a size of 32bits for integers,
// negative values are represented as they are stored internally.
// ( -1 is 11111111111111111111111111111111,
//   -2    11111111111111111111111111111110, ...)
//+depends _itobin
//+macro itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )


#endif
