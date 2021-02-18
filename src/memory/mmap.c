//+doc mmap wrapper
// address length is rounded up to a multiple of pagesize (4096 Bytes here)
// for the description, please look up the according manpage
// errno is only set, when mini_errno is defined
// if not, on error the negative errno value is returned.
// (e.g. -22 for "invalid argument")
//+def
static void* __attribute__((optimize("O0"))) mmap(void* addr,  size_t len,  int prot,  int flags,  int fd,  off_t off){
		long ret;
		if ( fd <0 )
				fd=0;
		syscall6( ret,( __SYSCALL(_mmap) | NCONST ), addr, len, prot, flags, fd, off );
#ifdef mini_errno
		if (ret<0 ){
				errno = -ret;
				ret=-1;
		}
#endif
		return((void*)ret);
}
