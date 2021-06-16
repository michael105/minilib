//+header stdio.h
//+needs mini_fstream.h
//+depends fileno read
//+inline
static inline int fgetc(FILE *F){
		POINTER buf = 0;
#ifdef mini_ungetc
		if ( *F >> 24 ){
				int r =  *F >> 24;
				*F =  *F & (~UNGETC_MASK);
				return(r);
		}
#endif
		read(fileno(F), &buf, 1 );
		return((int)buf);
}


