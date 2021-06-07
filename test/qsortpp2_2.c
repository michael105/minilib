#if 0
mini_start
mini_prints
mini_printf
mini_buf 256
mini_itodec
mini_ltodec
mini_strcmp

OPTFLAG -O0
STRIPFLAG

INCLUDESRC

return
#endif

// finally. 
// working.


static inline void swap_p(POINTER*a,POINTER*b){
		printf("SWAP_P %l x %l\n",a,b);
		printf("SWAP_P r: %l x %l\n",&a,&b);
		printf("SWAP_P r: %l x %l\n",*a,*b);
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"(*a),"+g"(*b) );
		printf("SWAP_P r: %l x %l\n",*a,*b);
}
	

void  _qsort_pp(void ***base, int left, int right, int(*cmp)(void*,void*)) {
		if(left >= right) return;
		int i = left, j = right;
		while(i<j) {

				while(cmp(**(base+i), **(base+left)) >0)
						if ( ++i==j )
								goto OUT;

				while(cmp(**(base+left), **(base+j))<0)
						if ( i==--j )
								goto OUT;
				
				asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"(*(base+i)),"+g"(*(base+j)) );

				i++; j--;
		}
OUT:
		_qsort_pp(base, left, i-1,cmp);
		_qsort_pp(base, j+1, right,cmp);
}

// sort an array of pointers to pointers,
// sort the pointers to the pointers 
void  qsort_pp(void ***base, int count, int(*cmp)(void*,void*)) {
		_qsort_pp(base,0,count-1,cmp);
}

int s_cmp(void * a, void * b){
		char *c1=a;
		char *c2=b;
		prints("CMP: ");
		prints(c1);
		prints(c2);

		//int ret=strcmp(c1,c2);
		int ret=0;
		while ( *c1 != 0 && *c1==*c2 ){
				c1++;
				c2++;
		}
		if ( *c1>*c2 )
				ret=1;
		if ( *c1<*c2 )
				ret=-1;

		printf("ret: %d\n",ret);
		return(ret);
}


int main(){
		prints("sort.\n");

		int i;
#define S 4
		// !!!!!! static. seems to be related to indirect addressing
		// ok. finally. took me some time
		char** s_array[S];
		char *strings[S+1] = { "str3", "str1", "str2", "str0", "str9" };
		for(i=0; i<S; i++){
				s_array[i] = &strings[i];
				write(1, strings[i],4);
				write(1, *s_array[i],4);
				prints("\n");
				printf("addr: %l\n",&strings[i]);
				printf("addr2: %l\n",s_array[i]);
				prints("\n");
		}
		printf("\n");

		//s_array[2]=s_array[0];
		for(i=0; i<S; i++){
				//s_array[i] = &strings[i];
				write(1, strings[i],4);
				write(1, *s_array[i],4);
				write(1,"\n",1);
		}
	
		//_qsort_pp((void***)s_array, 0,(S-1), s_cmp);
		qsort_pp((void***)s_array, S, s_cmp);

		prints("XXXX\n");

		for(i=0; i<S; i++){
				//s_array[i] = &strings[i];
				write(1, strings[i],4);
				write(1, *s_array[i],4);
				write(1,"\n",1);
		}
	

		return(0);
}
