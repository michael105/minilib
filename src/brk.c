//+doc the kernel syscall brk.
//+def 
static long sys_brk(unsigned long addr){
		long ret;
		syscall1( ret,( __SYSCALL(_brk) | NCONST ), addr );
		return(ret);
}

//+doc conformant brk, when mini_errno is defined
// if no errno is available,
// returns the negative errno value on error,
// 0 on success
//+def
static int brk( const void* addr ){
		long newbrk = sys_brk((unsigned long)addr);
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

//+doc conformant sbrk, when mini_errno is defined
// if no errno is available,
// returns the negative errno value on error,
// or the new break on success. 
//+def
static void* sbrk(int incr){
		long ret;
#ifdef mini_globals
		if ( mlgl->brk ){
				ret=mlgl->brk;
		} else {
				ret = sys_brk(0);
		}
#else
		ret = sys_brk(0);
#endif

		long addr = ret + incr;

		long newbrk = sys_brk(addr);
		if ( newbrk >0 ){
#ifdef mini_globals
				mlgl->brk = newbrk;
#endif
				return((void*)ret);
		}

#ifdef mini_errno
		errno = -newbrk;
		newbrk = 0;
#endif
		return((void*)newbrk);
}
