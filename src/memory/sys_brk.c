
//+doc the kernel syscall brk.
//+def 
static long sys_brk(unsigned long addr){
		long ret;
		syscall1( ret,( __SYSCALL(_brk) | NCONST ), addr );
		return(ret);
}


