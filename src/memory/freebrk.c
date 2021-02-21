
//+doc free all memory,
// which has been allocated with malloc_brk.
// Returns 0, if memory has been freed;
// 1, when there hasn't been any memory allocations with
// malloc_brk before.
// Then brk() gives an error, return the return value of brk
//+def
int free_brk(){
		if ( mlgl->malloc_start && getbrk() > mlgl->malloc_start ){ 
				// there has been some allocation before
				return(brk((void*)mlgl->malloc_start));
		}
		return(1);
}


