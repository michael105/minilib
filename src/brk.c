#ifndef mini_brk_c
#define mini_brk_c

//+doc the kernel syscall brk.
//+def 
static long sys_brk(unsigned long addr){
		long ret;
		syscall1( ret,( __SYSCALL(_brk) | NCONST ), addr );
		return(ret);
}
#define _sys_brk sys_brk

//+doc set the brk to addr
// return 0 on success.
// conformant brk, when mini_errno is defined
// if errno isn't available,
// returns the negative errno value on error
//+def
static int brk( const void* addr ){
		long newbrk = _sys_brk((unsigned long)addr);
		int ret = 0;
		if ( newbrk >0 ){
#ifdef mini_globals
				mlgl->brk = newbrk;
#endif
				return(0);
		}
#ifdef mini_errno
		errno = -ret;
		ret = -1;
#endif
		return(ret);
}

//+doc get the current brk
// does either a syscall to brk,
// or returns the globally saved var
//+def
static long getbrk(){
#ifdef mini_globals
		if ( mlgl->brk ){
				return(mlgl->brk);
		} else {
				return(_sys_brk(0)); // get the old brk
		}
#else
		return(_sys_brk(0));
#endif
}


//+doc Set the new brk, increment/decrement by incr bytes.
// return the old brk on success.
// conformant sbrk, when mini_errno is defined
// if no errno is available,
// returns the negative errno value on error
//+def
static void* sbrk(long incr){
		long ret = getbrk();

		long addr = ret + (long)incr;

		long newbrk = _sys_brk(addr);
		if ( newbrk >0 ){ // success
#ifdef mini_globals
				mlgl->brk = newbrk;
#endif
				return((void*)ret);
		}

#ifdef mini_errno
		errno = -newbrk;
		newbrk = 0;
#endif
		// this is errno
		return((void*)newbrk);
}


#endif
