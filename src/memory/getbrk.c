
//+doc get the current brk
// does either a syscall to brk,
// or returns the globally saved var
//+def
static long getbrk(){
#ifndef _sys_brk
#define _sys_brk sys_brk
#endif
#ifdef mini_globals
	if ( !mlgl->brk ){
		mlgl->brk=_sys_brk(0); // get the old brk
	}
	return(mlgl->brk);
#else
	return(_sys_brk(0));
#endif
}


