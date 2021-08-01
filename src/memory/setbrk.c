
//+doc set the current brk
// wrapper for brk(), with type of brk changed to long
//+depends brk
//+def
static int setbrk(long addr){
		return(brk((void*)addr));
}


