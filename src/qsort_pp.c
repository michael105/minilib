

void  _qsort_pp(void ***base, int left, int right, int(*cmp)(void***,void***)) {
		if(left >= right) return;
		int i = left, j = right;
		int piv = (left+right)>>1;
		while(i<j) {

				while(cmp((base+i), (base+piv))<0 && ( i<=piv))
						i++;
					//	if ( ++i>=piv )
						//		goto _qsppOUT;

				while(cmp((base+piv), (base+j))<0 && ( j-- >= piv ));
				
				if ( i>=j )
								goto _qsppOUT;
				
				asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"(*(base+i)),"+g"(*(base+j)) );

				i++; j--;
		}
_qsppOUT:
		_qsort_pp(base, left, i,cmp);
		_qsort_pp(base, j+1, right,cmp);
}

//+doc sort an array of pointers to pointers,
// sort the pointers to the pointers 
//+def qsort_pp
void qsort_pp(void ***base, int count, int(*cmp)(void***,void***)) {
		_qsort_pp(base,0,count-1,cmp);
}


