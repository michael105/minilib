#ifndef rand_c
#define rand_c


//+header stdlib.h
//+def
void srand( unsigned int i ){
		mlgl->srand = i;
}
	


//+header stdlib.h
//+def
unsigned int rand(){
		// xorshift, algorithm af marsaglia.
		// second round added, it doesn't give more randomness,
		// but isn't so expensive on the other hand.
		if ( mlgl->srand==0 ){
				mlgl->srand=1;
		}
		mlgl->srand ^= mlgl->srand << 13;
 		mlgl->srand ^= mlgl->srand >> 17;
 		mlgl->srand ^= mlgl->srand << 5;
		unsigned int t = mlgl->srand;
		mlgl->srand ^= mlgl->srand << 13;
 		mlgl->srand ^= mlgl->srand >> 17;
 		mlgl->srand ^= mlgl->srand << 5;
		return(t-1);
}









#endif

