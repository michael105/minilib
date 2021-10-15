#if 0
mini_start
mini_writes
mini_prints
mini_printsl
mini_chroot
mini_execve
INCLUDESRC
LDSCRIPT text_and_bss
HEADERGUARDS
shrinkelf
return
#endif




int main(int argc, char *argv[],const char*envp[]){

	int e;
	char cwd[PATH_MAX];
	if ( (e=getcwd(cwd, sizeof(cwd)))) {
		ewrites("Couldn't get current path\n");
		return( -e );
	}


	if ( (e= chroot( argv[1]) )){
		ewrites("Couldn't chroot");
		return( -e );
	}


	// Drop suid privileges
	setreuid( -1, getuid() );


	return(execvpe(argv[0],argv,(char*const*)envp));
}


