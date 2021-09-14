#ifndef mini_qsort_p_c
#define mini_qsort_p_c


//+doc (quick) shell sort routine, optimized for arrays of pointers
// following the tradition, this isn't exactly a quicksort algorithm,
// albite named quicksort.
// It is a shell sort implementation, originally done by Ray Gardner, 5/90.
//+def qsort_p
void qsort_p(void  *array,	size_t count,	int (*comp)(const void *, const void *)){
/*
 * **  ssort()  --  Fast, small, qsort()-compatible Shell sort
 * **
 * **  by Ray Gardner,  public domain   5/90
 * 
void ssort(void  *base,	size_t nel,	size_t width,	int (*comp)(const void *, const void *)){
 * */
		size_t wnel, gap, wgap, i, j, k;
		char *a, *b, tmp;

		//wnel = count * sizeof(void*);
		for (gap = 0; ++gap < count;)
				gap *= 3;
		while ((gap /= 3) != 0) {
				wgap = gap;
				for (i = wgap; i < count; i ++) {
						for (j = i - wgap; ;j -= wgap) {
								a = j + array;
								b = a + wgap;
								if ((*comp)(a, b) <= 0)
										break;
//								swap(a,b,width);
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
						:"+r"(*a),"+m"(*b) );

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

