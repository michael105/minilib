#ifndef fgetc_h
#define fgetc_h




//+header stdio.h
//+depends fileno read
//+needs mini_fstream.h
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


//+depends fgetc fileno read
//+macro getc(F) fgetc(F)

//+depends fgetc fileno read
//+macro getchar() fgetc(0)

//+doc pushes one char back to the stream.
// Overwrites a previously pushed char
// (conforming to the posix spec) 
//+def
static int ungetc(int c, FILE *F){
		*F = (*F & ~UNGETC_MASK) | (c<<24);
		return(c);
}		


#endif
