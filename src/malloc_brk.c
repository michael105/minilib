
#define MALLOC_BRK 0x10000000

//+doc allocate via setting the brk
// free and realloc can be used normally.
// The intention of malloc_brk is for subsequent calls to realloc.
// The saved data has not to be copied,
// instead realloc just writes the new size and sets 
// the brk accordingly.
// if the break is saved before one or more calls to malloc_brk,
// the allocated memory can also be free'd by setting the brk to the saved value
// with brk(saved_brk)
// free_brk() free's all memory, which has been allocated with malloc_brk
//+depends sbrk
//+def
void* malloc_brk(int size){
		if ( size<0 )
				return(0);

		if ( size == 0 )
			size = 4;
		else
			size = (((size-1) >> 2 ) + 2)<<2; // alignment and reserving space for the "pointer"(int)

		void *mem = sbrk(size);
		if ( mem <= 0 )
				return(0);
		if ( !mlgl->malloc_start)
				mlgl->malloc_start = (long)mem;

		int *i = mem;
		
		*i=( MALLOC_BRK | (size));
		//i = mem+size+4;
		//*i = MALLOC_BRK_END; // at the end
		i++;

		return(mem+4);
}


