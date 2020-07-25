

void  _qsort_pp(void ***base, int left, int right, int(*cmp)(void*,void*)) {
		if(left >= right) return;
		int i = left, j = right;
		while(i<j) {

				while(cmp(**(base+i), **(base+left)) >0)
						if ( ++i==j )
								goto _qsppOUT;

				while(cmp(**(base+left), **(base+j))<0)
						if ( i==--j )
								goto _qsppOUT;
				
				asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"(*(base+i)),"+g"(*(base+j)) );

				i++; j--;
		}
_qsppOUT:
		_qsort_pp(base, left, i-1,cmp);
		_qsort_pp(base, j+1, right,cmp);
}

//+doc sort an array of pointers to pointers,
// sort the pointers to the pointers 
//+def qsort_pp
void qsort_pp(void ***base, int count, int(*cmp)(void*,void*)) {
		_qsort_pp(base,0,count-1,cmp);
}


