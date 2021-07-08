#if 0
mini_start
mini_ewrites
mini_writes
mini_exit_errno
COMPILE chroot getcwd execve setreuid getuid errno chdir

INCLUDESRC
SHRINKELF
#LDSCRIPT text_and_bss

return
#endif

#define CHROOT "/home/arch"


void usage(){
		writes("usage: rdo command [arguments]\n");
		writes("chroot into "CHROOT",\nchange into current directory and execute command\n");
		exit(1);
}

#define IFF( e, msg ) if ( e ){ ewrites(msg); goto failed; }

int main(int argc, char **argv, char **envp ){

	if ( argc < 2 )
		usage();

	char cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	IFF( errno, "getcwd" );


	IFF( chroot( CHROOT ), "chroot" );

	IFF(chdir(cwd),"chdir");

	// Drop suid privileges
	IFF(setreuid( -1, getuid() ), "setreuid" );

	*argv++;
	// replace 0's between arguments
	for ( char *c = *argv; c<(*envp-1); c++ ){
		if ( !*c )
			*c = ' ';
	}

	char* arg[] = { "sh", "-c", *argv ,0 };

	execve("/bin/sh", arg, envp );

	ewrites("Executing /bin/sh");
failed:
	ewrites(" failed\n");
	exit_errno(errno);
}
