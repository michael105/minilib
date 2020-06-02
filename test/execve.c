#if 0

mini_start
mini_fprintf
mini_printf
mini_sprintf
mini_print
mini_itodec
mini_execve
mini_fork
mini_nanosleep
mini_buf 1024
mini_INCLUDESRC

return
#endif


#include "minilib/minilib.h"


int main(int argc, char**argv, char** envp){

		char *av[] = {
				av[0] = "echo",
				av[1] = "output of echo",
				av[2] = 0
		};

		char *av2[] = {
				av2[0] = "echo",
				av2[1] = "forked, echo",
				av2[2] = 0
		};


		int pid = fork();
		//printf("pid: %d\n",pid);
		
		if ( pid > 0 ){
				execve("/bin/echo", (const char**)av, (const char**)envp );
		}

		for ( int i=0; i<100000; i++ ){
				pid++;
		}
		execve("/bin/echo", (const char**)av2,  (const char**)envp );



		return(0);
}
