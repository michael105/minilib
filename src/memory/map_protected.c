//+cat memory
//+doc allocate a buffer, which is surrounded by protected pages. 
// mprotect(PROT_NONE)
// When there is a buffer overflow,
// neither the stack, nor other structures can be overwritten.
// Instead the overflow (or underflow) touches the next protected page,
// what results in a segfault.
// Most probably you'd like to catch the segfault signal.
// (By installing a segfault signal handler)
//
// The size is always a mutliple of the systems pagesize, 4kB here.
// The len of the mapped memory area is rounded up to the next pagesize.
// The mapped area can only be freed by call(s) to munmap,
// neither realloc nor free are allowed.
// There is one page before, and one page after the mapped area
// protected with PROT_NONE, and len rounded up to the next
// pagebreak. So this is the overhead. 
// If an error occures, errno is set (when defined by the switch mini_errno), 
// and -1 returned, or the negative errno value, when errno isn't defined.
//+depends mmap mprotect
//+def
void* map_protected(int len){
		// round up, and reserve space for the protected pages
		len=len+(PAGESIZE-len%PAGESIZE) + 2*PAGESIZE;

		void *p = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE,-1,0 );
		if ( p<=0 ) 
				return(p);

		mprotect(p,1,PROT_NONE);
		mprotect(p+len-PAGESIZE,1,PROT_NONE);

		return( p+PAGESIZE );
}

//+cat memory
//+doc free an area, allocated before with map_protected
// (len must be the same, when at the invocation of map_protected)
// returns the value of munmap, when an error occures.
// errno is set, when defined.
// return 0 on success.
//+depends munmap mprotect
//+def
int unmap_protected(void *p, int len){
		len=len+(PAGESIZE-len%PAGESIZE);

		int ret = munmap((long)p-PAGESIZE,len+2*PAGESIZE);
		
		 return(ret);
}





