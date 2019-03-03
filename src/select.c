/*
volatile inline int select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait){
		//return(syscall5(__NR_select,(long)fd,(long)readfd,(long)writefd,(long)exceptfd, (long)wait));
		int ret;
		//syscall5(ret,__NR_select,&fd,readfd,writefd,exceptfd, 0);
#ifdef OSX
		syscall5(ret, SCALL(select),&fd,readfd,writefd,exceptfd, (POINTER) wait);
#else
		syscall5(ret, SCALL(select),&fd,readfd,(POINTER)writefd,(POINTER)exceptfd,(POINTER) wait);
#endif
		return(ret);
		//return(syscall5(__NR_select,fd,readfd,,0,0));
}
*/

