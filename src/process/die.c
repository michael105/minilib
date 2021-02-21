#ifndef mini_die_c
#define mini_die_c

//+doc write msg to stderr and exit with failure
// if errno is defined and set, /bin/errno is executed to give a verbose error 
// message
// if errno is either not defined or not set,
// exit with -1
// 
//+depends execve errno_str exit ewritesl exit_errno _die
//+macro die(errnum,msg) {ewritesl(msg);exit_errno(errnum);}

//+doc write fmt andargs via fprintf to stderr and exit with failure
// if errno is defined and set, /bin/errno is executed to give a verbose error 
// message
// if errno is either not defined or not set,
// exit with -1
// 
//+depends execve errno_str exit exit_errno _die fprintf
//+macro dief(errnum,fmt,...) {fprintf(stderr,fmt,__VA_ARGS__);exit_errno(errnum);}


//+doc write variable string list to stderr and exit with failure
// if errno is defined and set, /bin/errno is executed to give a verbose error 
// message
// if errno is either not defined or not set,
// exit with -1
// 
//+depends execve errno_str exit exit_errno _die eprintsl dprints
//+macro dies(errnum,...) {eprintsl(__VA_ARGS__);exit_errno(errnum);}



//+doc internal implementation of die
//+def
void _die(){
#ifdef mini_errno
	int errnum=errno;
#else 
	int errnum=0;
#endif

	//write(STDERR_FILENO,msg,sizeof(msg));
	//ewrites(msg);
	
	if ( errnum )
		exit_errno(errnum);

	exit(-1);
}

//+doc when arg1 is true, write msg to stderr and exit with failure
// if errno is defined and set, /bin/errno is executed to give a verbose error 
// message
// if errno is either not defined or not set,
// exit with -1
// 
//+depends execve errno_str exit ewritesl exit_errno die
//+macro die_if( when, errnum, msg ) if( when ) die( errnum, msg )


//+doc when arg1 is true, vall dief(errnum,fmt)
// if errno is defined and set, /bin/errno is executed to give a verbose error 
// message
// if errno is either not defined or not set,
// exit with -1
// 
//+depends execve errno_str exit ewritesl exit_errno die
//+macro dief_if( when, errnum, fmt,... ) if( when ) dief( errnum, fmt, __VA_ARGS__ )



//+doc when arg1 is true, vall dies(errnum, ... )
// if errno is defined and set, /bin/errno is executed to give a verbose error 
// message
// if errno is either not defined or not set,
// exit with -1
// 
//+depends execve errno_str exit exit_errno dies
//+macro dies_if( when, errnum, ... ) if( when ) dies( errnum, __VA_ARGS__ )



#endif
