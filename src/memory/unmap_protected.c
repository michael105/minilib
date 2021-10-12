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



