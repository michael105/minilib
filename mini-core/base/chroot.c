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
#include "minilib.h"

int main(int argc, char *argv[],const char*envp[]){

		if (argc<2){
				writes("chroot root [cmd] [arg1] [arg2] ...\n");
				return(0);
		} 

		if ( chroot( argv[1] )){
				prints("Couldn't chroot into ");
				printsl(argv[1]);
				return(1);
		}

		if ( argc < 3 ){
				char *av[]={av[0]="sh",av[1]=0 };
				return(execve("/bin/sh",av,envp));
		}

		return(execve(argv[2],&argv[2],envp));
}
