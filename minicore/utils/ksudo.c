#if 0
mini_start

mini_vexec_q
mini_writes
mini_waitpid


INCLUDESRC
SHRINKELF
LDSCRIPT onlytext

return
#endif

void usage(){
		writes("Usage: ksudo [-h] [command and options for sh]\n"
						"Get a kerberos ticket, execute command as root, keep the ticket.\n");
		exit(1);
}
	

int main(int argc,char**argv,char**envp){

		if ( argc<2 || (argv[1][0]=='-' && argv[1][1]=='h') )
				usage();

		char *arg[6]; 
		arg[0]="klist";
		arg[1]=0;


		int r = vexec_q("/usr/bin/klist",arg,envp);
		int i = 0;

		arg[0]="kinit";
		while ( r ){
				if ( i++ > 2 )
						exit(1);
				r = vexec("/usr/bin/kinit",arg,envp);
		}

		arg[0] = "ksu";
		arg[1] = "-q";
		arg[2] = "-e";
		arg[3] = "/bin/sh";
		arg[4] = "-c";
		arg[5] = argv[1];

		for ( *argv++; *argv; *argv++ )
				argv[0][-1]=' ';

				

		execve("/usr/bin/ksu", arg, envp );
		writes("Couldn't execute ksu.\n");

		exit(1);
}
// ksu -q -e /bin/sh -c "$*"	
