// clone wrapper functions
//



//+def
int clone_t(int flags){
	
		long tid,ptid;
		
		//long ret = clone( 0|flags, 0, &tid, &ptid );
		long ret = clone(CLONE_VM|CLONE_SIGHAND|CLONE_PARENT|
						CLONE_THREAD|CLONE_FS|CLONE_IO | flags, 0, &tid, &ptid );

		return(ret);
}


