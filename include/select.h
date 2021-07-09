#ifndef select_h
#define select_h

// Some syscalls do give trouble with gcc.
// Amongst other problems, parts of the code are optimized out,
// what results in hard to track bugs, which (even worse)
// show up only sometimes.
// The code below showed up to work.
// (Amongst other things, volatile is not really accepted by gcc.
// Only SOMETIMES. :// )

//+header unistd.h
//+inc
//
//+def
static int volatile ATTR_OPT("O0") select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait){

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"


		// somehow, when using fd directly, this leads to trouble. 
		// might be gcc related.
		int sysret = fd;
		//__DO_syscall( 5, (SCALL(name) | NCONST ) );
		register long int r10 asm ("r10") = exceptfd; 
		register long int r8 asm ("r8") = wait;
		__SYSCALL_ASM(sysret,__NR_select) , "D" (sysret), "S" (readfd), "d" (writefd), "r" (r10), "r" (r8) __callend;


#ifdef mini_errno
		if ( sysret<0){
				OPTFENCE(r10,r8);
				errno = -sysret;
				return(-1);}
#endif
		return(sysret);

#pragma GCC diagnostic pop
}

#endif

