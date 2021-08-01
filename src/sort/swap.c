
//+doc swap a with b, with 'size' bytes
// swaps integers and longs at once, when size eq sizeof(int/long)
//+def
static inline void swap(void* a, void* b,int size){
		if ( size==sizeof(int) ){
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1"
						:"+r"(*(int*)a),"+g"(*(int*)b) );
				return;
		}
		if ( size==sizeof(long) ){
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
						:"+r"(*(long*)a),"+g"(*(long*)b) );
				return;
		}
		for ( int n=size;n--;){
        asm ("xor %0,%1\nxor %1,%0\nxor %0,%1" 
						:"+r"(*(char*)a),"+g"(*(char*)b) );
				a++;b++;
		}
}
// todo: test for last3 bits -> eq modulo 8
// last 2 bits-> eq modulo 4.
// loopfor swappinglongs/integers.


