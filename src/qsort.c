// the qsort implementation
// I'm unhappy with the swap.
// Should do another implemenation as macro,
// so the swap can be supplied as argument,
// as well as the compare function can get a macro.
// But to stay c89 conform, I leave this as it is.
void _qsort(void *base, int left, int right, int size, int(*cmp)(const void*,const voi
						d*)) {
		if(left >= right) return;
		int i = left, j = right;
		while(1) {
				while(cmp(base+i, base+left) >0) i+=size;
				while(cmp(base+left, base+j)<0) j-=size;
				if(i >= j) break;
				char *a = (base+i);
				char *b = (base+j);
				for ( int n=size;n--;){
						*a^=*b;
						*b^=*a;
						*a^=*b;
						a++;b++;
				}
				i+=size; j-=size;
		}
		_qsort(base, left, i-size,size,cmp);
		_qsort(base, j+size, right,size,cmp);
}

//+doc qsort, implemented as recursive function
//+def
void qsort(void *base, int count, int size, int(*cmp)(const void*,const void*)){
		_qsort(base,0,(count-1)*size,size,cmp);
}


