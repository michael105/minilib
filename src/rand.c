#ifndef rand_c
#define rand_c


//+header stdlib.h
//+def
void srand( unsigned int i ){
		ml.srand = i;
}
	


//+header stdlib.h
//+def
unsigned int rand(){
		// xorshift, algorithm af marsaglia.
		// second round added, it doesn't give more randomness,
		// but isn't so expensive on the other hand.
		if ( ml.srand==0 ){
				ml.srand=1;
		}
		ml.srand ^= ml.srand << 13;
 		ml.srand ^= ml.srand >> 17;
 		ml.srand ^= ml.srand << 5;
		unsigned int t = ml.srand;
		ml.srand ^= ml.srand << 13;
 		ml.srand ^= ml.srand >> 17;
 		ml.srand ^= ml.srand << 5;
		return(t-1);
}









#endif

