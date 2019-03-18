#ifndef mini_isprint_h
#define mini_isprint_h
#define misprint(A) isprint(A)

//+ansi ctype.h
//+inc
//+def
inline int __attribute__((always_inline)) isprint(const char c){
		if ( (c>31) && ( c<127 ))
				return(1);
		return(0);
}


#endif

