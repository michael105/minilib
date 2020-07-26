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
//
// Somehow - the quicksort implementations, I found in the net,
// are buggy. or I'm doing something wrong.
// I don't know. 
// I did another sort algorithm some time before, but
// albite my algorithm is good for integers or longs,
// it's not as well suited for generic data.
// So, finally, I'm copying the shellsort of Ray Gardner in here.
// Found it within musl.
// I replaced the swap routine.

//+doc swap a with b, with 'size' bytes
// swaps integers and longs at once, when size eq sizeof(int/long)
//+def
static inline void swap(void* a, void* b,int size){
		if ( size==sizeof(int) ){
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1"
						:"+r"(*(int*)a),"+m"(*(int*)b) );
				return;
		}
		if ( size==sizeof(long) ){
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
						:"+r"(*(long*)a),"+m"(*(long*)b) );
				return;
		}
		for ( int n=size;n--;){
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
						:"+r"(*(char*)a),"+m"(*(char*)b) );
				a++;b++;
		}
}



//+doc (quick) shell sort routine
// following the tradition, this isn't exactly a quicksort algorithm,
// albite named quicksort.
// It is a shell sort implementation, originally done by Ray Gardner, 5/90;
// which in turn I did find within musl.
//+def qsort
void qsort(void  *base,	size_t nel,	size_t width,	int (*comp)(const void *, const void *)){
/*
 * **  ssort()  --  Fast, small, qsort()-compatible Shell sort
 * **
 * **  by Ray Gardner,  public domain   5/90
 * 
void ssort(void  *base,	size_t nel,	size_t width,	int (*comp)(const void *, const void *)){
 * */
		size_t wnel, gap, wgap, i, j, k;
		char *a, *b, tmp;

		wnel = width * nel;
		for (gap = 0; ++gap < nel;)
				gap *= 3;
		while ((gap /= 3) != 0) {
				wgap = width * gap;
				for (i = wgap; i < wnel; i += width) {
						for (j = i - wgap; ;j -= wgap) {
								a = j + (char *)base;
								b = a + wgap;
								if ((*comp)(a, b) <= 0)
										break;
								swap(a,b,width);
								/*k = width;
								do {
										tmp = *a;
										*a++ = *b;
										*b++ = tmp;
								} while (--k);*/
								if (j < wgap)
										break;
						}
				}
		}
}



#if 0
static void swap(void* a, void* b,int size){
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
			/*	*(long*)a^=*(long*)b;
				*(long*)b^=*(long*)a;
				*(long*)a^=*(long*)b; */
				long t=*(long*)(a);
				*(long*)(a)=*(long*)(b);
				*(long*)(b)=*(long*)(a);
				*(long*)(a)=t;
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
#endif

#if 0

//possible: replace the recursion with loops.
// would give some performance gain.
// somehow my brain stucks now, 
// and there are other more important things to do.
// so. And it would need benchmarking.
// Again - without knowledge of the individual datasets and usecases,
// well. So. I leave this as compact as it is.
// (besides the swap routine, which is vectorized.)

static void _qsort(void *base, int left, int right, int size, int(*cmp)(const void*,const void*)){
		if(left >= right) return;
		int i = left, j = right;
		while(i<j) {
				while( cmp(base+i, base+left) > 0 && (i<j) ) i+=size;
				while( cmp(base+left, base+j) < 0 && (i<j) ) j-=size;
				if(i >= j) break;
				swap(base+i,base+j,size);
				i+=size; j-=size;
		}
		_qsort(base, left, i-size,size,cmp);
		_qsort(base, j+size, right,size,cmp);
}

////+doc qsort, implemented as recursive function
// buggy. sometimes - I modified a existing implementation.
// to find out, the algorithm has been wrong.
// even worse - I looked up several other implementations -
// say, half of them is simply wrong.
// some of them might work, e.g., since java might not segfault on
// an access to pointers pointing to -1.
// however. darnit.
////+depends swap
////+def qsort
static void qsort(void *base, int count, int size, int(*cmp)(const void*,const void*)){
		_qsort(base,0,(count-1)*size,size,cmp);
}


#endif

#endif

