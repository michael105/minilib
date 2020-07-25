

void  _qsort_pp(void ***base, int left, int right, int(*cmp)(void***,void***)) {
		if(right-left<1) return;
		int i = left, j = right;
		int piv = ((right-left)>>1)+left;
		while(1) {
				while((i<j) && cmp((base+i), (base+piv))<0 )
						i++;

				//printf("sort, i: %d, j:%d, piv: %d\n",i,j,piv);

				while( (j>i) && cmp(base+piv,base+j)<0 )
						j--;
				
				//printf("sort2, i: %d, j:%d, piv: %d\n",i,j,piv);
				if ( i>=j )
								goto _qsppOUT;
				
				printf("swap, i: %d, j:%d, piv: %d\n",i,j,piv);
				asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"(*(base+i)),"+g"(*(base+j)) );

				//i++; j--;
						i++;
						j--;
		}
_qsppOUT:
				printf("sortX, i: %d, j:%d, piv: %d, left:%d, right:%d\n",i,j,piv,left,right);
		_qsort_pp(base, left, i,cmp);
		_qsort_pp(base, i+1, right,cmp);
}

//+doc sort an array of pointers to pointers,
// sort the pointers to the pointers 
//+def qsort_pp
void qsort_pp(void ***base, int count, int(*cmp)(void***,void***)) {
		_qsort_pp(base,0,count-1,cmp);
	  //_qsort_pp(base,0,count-1,cmp);
}


