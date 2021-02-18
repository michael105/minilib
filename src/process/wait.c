#ifndef wait_c
#define wait_c
//+header sys/wait.h

//+depends wait4
//+include
//+def
pid_t wait(int *wstatus){
	return(wait4(-1,wstatus,0,0));
}


//+depends wait4
//+include
//+def
pid_t waitpid(pid_t pid, int *wstatus, int options){
	return(wait4(pid,wstatus,options,0));
}


#endif
