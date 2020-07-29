// clone wrapper functions
//



//+def
int clone_t(int flags){
	
		long tid,ptid;
		
		//long ret = clone( 0|flags, 0, &tid, &ptid );
		long ret = clone( flags, 0, &tid, &ptid );

		return(ret);

					


		return(0);
}


