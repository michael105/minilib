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

//+depends _itobin
//+macro itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )


#endif
