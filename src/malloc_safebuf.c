//+doc allocate a buffer, which is surrounded by protected pages. 
// mprotect(PROT_NONE)
// When there is a buffer overflow,
// neither the stack, nor other structures can be overwritten.
// Instead the overflow (or underflow) touches the next protected page,
// what results in a segfault.
// The size is always a mutliple of the systems pagesize, 4kB here.
// The len of the mapped memory area is rounded up to the next pagesize.
// The mapped area can only be freed by calls to munmap,
// neither realloc nor free are allowed.
//+depends mmap mprotect
//+def
void* malloc_safebuf(int len){
		len=len+(PAGESIZE-len%PAGESIZE) + 2*PAGESIZE;

		void *p = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE,-1,0 );
		mprotect(p,1,PROT_NONE);
		mprotect(p+len-PAGESIZE,1,PROT_NONE);

		return( p+PAGESIZE );
}






