#ifndef mini_math_h
#define mini_math_h
// mathematical functions.
//


//+def
static div_t div(int numerator, int denominator){
		div_t ret;
		ret.quot = numerator/denominator;
		ret.rem = numerator-(ret.quot*denominator);
		return(ret);
}
	
//+def
static ldiv_t ldiv(long int numerator, long int denominator){
		ldiv_t ret;
		ret.quot = numerator/denominator;
		ret.rem = numerator-(ret.quot*denominator);
		return(ret);
}
	

//+def
static int abs(int i){
		  return( (i >= 0) ? i : -i);
}

//+def
static long int labs(long int i){
		  return( (i >= 0) ? i : -i);
}

#endif
