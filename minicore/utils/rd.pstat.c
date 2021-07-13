#if 0
mini_start
mini_group_write


mini_group_print

mini_sprintf
mini_printf
mini_itodec

mini_waitpid
mini_vfork
mini_system
mini_strcpy
mini_atoi

mini_syscalls

OPTFLAG -O0
STRIPFLAG
INCLUDESRC
#LDSCRIPT text_and_bss

return
#endif

void usage(){
		writes("usage: [arguments]\n"
						"... \n" );
		exit(1);
}



int main(int argc, char **argv, char **envp){
		if ( argc<2 || ( argv[1][0] == '-' && argv[1][1] == 'h' ) )
				usage();


		int ret = 0;
		ret = sys_prctl(PR_SET_CHILD_SUBREAPER,1,0,0,0);
		int pid = vfork();
		if ( pid == 0 ){
				execve(argv[1],&argv[1], envp );
		}

		//char pn[64] = "/proc/";
		char pn[64];

		if ( pid ){
				printf("ret: %d\n",ret);
				int cpid;
				int ws;
			
				do {
						cpid = waitpid( -1, &ws, 0 );
						//if ( cpid > 0 ){
								sprintf( pn, "/proc/%d/status", cpid);
								prints("exit: ",pn);
						//}
				} while ( cpid != pid );


		}



		return(0);
}
