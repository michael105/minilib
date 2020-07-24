#ifndef mini_qsort_c
#define mini_qsort_c
// a qsort implementation
// I'm unhappy with the swap.
// Should do another implemenation as macro,
// so the swap can be supplied as argument,
// as well as the compare function can get a macro.
// But to stay c89 conform, I leave this as it is.

// tried to optimize at least the swap a bit.
// the generated assembly looks. "not perfect".
// And it would be possible to swap also multiples
// of 4 or 8. But. leaving this for now.
// Would be better to leave the standard here,
// and write a macro. What would give some advantages.
// Anyways.

//+doc swap a with b, with 'size' bytes
// swaps integers and longs at once, when size eq sizeof(int/long)
//+def
static inline void __attribute__((always_inline)) swap(void* a, void* b,int size){
/*		if ( size==1 ){
				*(char*)a^=*(char*)b;
				*(char*)b^=*(char*)a;
				*(char*)a^=*(char*)b;
				return;
		} */ // commented this out. impossible to predict the individual cases.
		// but better save some bytes.
		if ( size==sizeof(int) ){
				*(int*)a^=*(int*)b;
				*(int*)b^=*(int*)a;
				*(int*)a^=*(int*)b;
				return;
		}
		if ( size==sizeof(long) ){
				*(long*)a^=*(long*)b;
				*(long*)b^=*(long*)a;
				*(long*)a^=*(long*)b;
				return;
		} 
		char *c1 = (char*)a;
		char *c2 = (char*)b;
		for ( int n=size;n--;){
				*c1^=*c2;
				*c2^=*c1;
				*c1^=*c2;
				c1++;c2++;
		}

}

//possible: replace the recursion with loops.
// would give some performance gain.
// somehow my brain stucks now, 
// and there are other more important things to do.
// so. And it would need benchmarking.
// Again - without knowledge of the individual datasets and usecases,
// well. So. I leave this as compact as it is.
// (besides the swap routine, which is vectorized.)

void _qsort(void *base, int left, int right, int size, int(*cmp)(const void*,const voi
						d*)) {
		if(left >= right) return;
		int i = left, j = right;
		while(1) {
				while( cmp(base+i, base+left) > 0 ) i+=size;
				while( cmp(base+left, base+j) < 0 ) j-=size;
				if(i >= j) break;
				swap(base+i,base+j,size);
				i+=size; j-=size;
		}
		_qsort(base, left, i-size,size,cmp);
		_qsort(base, j+size, right,size,cmp);
}

//+doc qsort, implemented as recursive function
//+depends swap
//+def qsort
void qsort(void *base, int count, int size, int(*cmp)(const void*,const void*)){
		_qsort(base,0,(count-1)*size,size,cmp);
}

#endif

