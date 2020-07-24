#if 0
mini_start
mini_prints
mini_printf
mini_buf 256
mini_itodec
mini_ltodec
mini_strcmp

OPTFLAG -O2
STRIPFLAG

INCLUDESRC

return
#endif

// ok. this sorts an array of pointers.
// what is not, what I did want.
// but. ok. I finally called it qsort_p.
// so. :/ no wonder. wrong name.
// need qsort_pp
// found a bug, anyways.


static inline void swap_p(POINTER*a,POINTER*b){
		printf("SWAP_P %l x %l\n",a,b);
		printf("SWAP_P r: %l x %l\n",&a,&b);
		printf("SWAP_P r: %l x %l\n",*a,*b);
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"(*a),"+g"(*b) );
		printf("SWAP_P r: %l x %l\n",*a,*b);
}
	

void  _qsort_p(char **base, int left, int right, int size, int(*cmp)(char**,char**)) {
		char*p = *base;
		printf("sort, addr: %l\n",p);
		if(left >= right) return;
		int i = left, j = right;
		while(1) {
				printf("s1\n");
				while((cmp((base+i), (base+left)) >0) && ( i<j ) ) i+=size;
				printf("ss2\n");
				while((cmp((base+left), (base+j))<0) && ( i<j )) j-=size;
				printf("s3\n");
				if(i >= j) break;
				printf("sort\n");
#if 0
				printf("swap, %l x %l\n",(POINTER*)(base+i),(POINTER*)(base+j));
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
								: "+r"((POINTER*)(base+i)),"+g"((POINTER*)(base+j)) );
				printf("swap, %l x %l\n",(POINTER*)(base+i),(POINTER*)(base+j));

				//swap_p((POINTER*)(base+i),(POINTER*)(base+j));
#else
				char **tmp = *(base+i);
				printf("sort2, addr: %l\n",**base);

				printf("swap, %s x %s\n",*(char**)(base+i),*(char**)(base+j));
				printf("swap, %l x %l\n",*(char*)(base+i),*(char*)(base+j));

				*(base+i) = *(base+j);
				*(base+j) = tmp;

				printf("swapped, %l x %l\n",*(char*)(base+i),*(char*)(base+j));
				printf("swapped, %s x %s\n",*(char**)(base+i),*(char**)(base+j));
#endif

				i+=size; j-=size;
		}
		_qsort_p(base, left, i-size,size,cmp);
		_qsort_p(base, j+size, right,size,cmp);
}




int s_cmp(char ** a, char ** b){
		char *c1=*a;
		char *c2=*b;
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
		static char** s_array[S];
		static char *strings[S+1] = { "str3", "str1", "str2", "str0", "str9" };
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

		s_array[2]=s_array[0];
		for(i=0; i<S; i++){
				//s_array[i] = &strings[i];
				write(1, strings[i],4);
				write(1, *s_array[i],4);
				write(1,"\n",1);
		}
	
		_qsort_p(*s_array, 0,(S-1),1, s_cmp);

		prints("XXXX\n");

		for(i=0; i<S; i++){
				//s_array[i] = &strings[i];
				write(1, strings[i],4);
				write(1, *s_array[i],4);
				write(1,"\n",1);
		}
	

		return(0);
}
