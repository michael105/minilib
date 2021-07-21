
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


