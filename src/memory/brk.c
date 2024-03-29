//+doc set the brk to addr
// return 0 on success.
// conformant brk, when mini_errno is defined return -1 and set errno.
// if errno isn't available,
// returns the negative errno value on error
//+depends sys_brk
//+def
static int brk( const void* addr ){
#ifndef _sys_brk
#define _sys_brk sys_brk
#endif
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

