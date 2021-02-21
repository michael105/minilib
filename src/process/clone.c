// clone wrapper functions
//



//+def
int clone_t(int flags){
	
		long tid,ptid;
		long int sysret;
		
		//long ret = clone( 0|flags, 0, &tid, &ptid );
		register long int r10 asm ("r10") = &ptid; 
//		long ret = clone(CLONE_VM|CLONE_SIGHAND|CLONE_PARENT|
//						CLONE_THREAD|CLONE_FS|CLONE_IO | flags, 0, &tid, &ptid );

		OPTFENCE(r10,tid,flags,sysret,ptid);
		__SYSCALL_ASM(sysret,__NR_clone) , "D" (flags), "S" (0), "d" (&tid), "r" (r10)  __callend;
		return(sysret);
}


