#if 0
mini_start
mini_vexec
mini_writes
mini_waitpid


INCLUDESRC
SHRINKELF
LDSCRIPT onlytext

return
#endif

void usage(){
		writes("Usage: su [-h] [options for kinit and ksu]\n"
						"Get root and keep the kerberos ticket.\n");
		exit(1);
}
	

int main(int argc,char**argv,char**envp){

		if ( argc>1 && argv[1][0]=='-' && argv[1][1]=='h' )
				usage();

		int r = vexec("/usr/bin/klist",argv,envp);
		int i = 0;

		while ( r ){
				if ( i++ > 2 )
						exit(1);
				r = vexec("/usr/bin/kinit",argv,envp);
		}

		execve("/usr/bin/ksu", argv, envp );
		writes("Couldn't execute ksu.\n");

		exit(1);
}

				
				
