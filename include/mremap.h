//+inc
//
//+def
static void* volatile ATTR_OPT("O0") mremap(void* addr, size_t old_len, size_t new_len, int flags, void* new_addr){
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"

		long sysret;

		//__DO_syscall( 5, (SCALL(name) | NCONST ) );
		register long int r10 asm ("r10") = flags; 
		register long int r8 asm ("r8") = new_addr;
		__SYSCALL_ASM(sysret,__NR_select) , "D" (addr), "S" (old_len), "d" (new_len), "r" (r10), "r" (r8) __callend;

#ifdef mini_errno
		if ( sysret<0){
				errno = -sysret;
				return(-1);}
#endif
		return((void*)sysret);

#pragma GCC diagnostic pop
}


