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

// finally. somehow, possibly this would have worked, without. well. 
static inline void swap_p(POINTER*a,POINTER*b){
		printf("SWAP_P %l x %l\n",a,b);
		printf("SWAP_P r: %l x %l\n",&a,&b);
		printf("SWAP_P r: %l x %l\n",*a,*b);
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"(*a),"+g"(*b) );
		printf("SWAP_P r: %l x %l\n",*a,*b);
}
	

void  _qsort_pp(void ***base, int left, int right, int size, int(*cmp)(void***,void***)) {
		void*p = **base;
		printf("sort, addr: %l\n",p);
		if(left >= right) return;
		int i = left, j = right;
		while(1) {
				printf("s1\n");
				while(cmp((base+i), (base+left)) >0){
						i++;
						if ( i==j )
								goto OUT;
				}
				printf("ss2\n");
				while(cmp((base+left), (base+j))<0){
						j--;
						if ( i==j )
								goto OUT;
				}
				printf("sort s3\n");
#if 0
				printf("swap, %l x %l\n",(POINTER*)(base+i),(POINTER*)(base+j));
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"((POINTER*)(base+i)),"+g"((POINTER*)(base+j)) );
				printf("swap, %l x %l\n",(POINTER*)(base+i),(POINTER*)(base+j));

				//swap_p((POINTER*)(base+i),(POINTER*)(base+j));
#else
				void **tmp = *(base+i);
				void **tmp2 = *(base+j);
				printf("sort2, addr: %l, i:%d, j:%d\n",**base,i,j);

				printf("swap, %s x %s\n",**(base+i),**(base+j));
				printf("swap, %l x %l\n",*(base+i),*(base+j));
			   asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"(*(void**)(base+i)),"+g"(*(void**)(base+j)) );

				//*(base+i) = tmp2;
				//*(base+j) = tmp;

				printf("swapped, %l x %l\n",*(base+i),*(base+j));
				printf("swapped, %s x %s\n",**(base+i),**(base+j));
#endif

				i++; j--;
		}
OUT:
		_qsort_pp(base, left, i-1,size,cmp);
		_qsort_pp(base, j+1, right,size,cmp);
}




int s_cmp(void *** a, void *** b){
		char *c1=**a;
		char *c2=**b;
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
	
		_qsort_pp((void***)s_array, 0,(S-1),1, s_cmp);

		prints("XXXX\n");

		for(i=0; i<S; i++){
				//s_array[i] = &strings[i];
				write(1, strings[i],4);
				write(1, *s_array[i],4);
				write(1,"\n",1);
		}
	

		return(0);
}
