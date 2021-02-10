#if 0
#globals_on_stack
mini_errno
mini_start
mini_writes
mini_writesl
mini_ewrites
mini_match_ext2
mini_mmap
mini_open
mini_die
mini_die_if
mini_printsl
mini_printl
mini_group_printf

#DEBUG
#FULLDEBUG
#STRIPFLAG
#OPTFLAG -O0
mini_INCLUDESRC
LDSCRIPT default
#SHRINKELF
return
#endif

#include "minilib/minilibcompiled.h"


int main( int argc, char *argv[], char *envp[] ){
		if ( argc < 2 ){
				writes("usage: rgrep pattern [file[...]]");
				exit(1);
		}
		char *pattern = argv[1];
		struct stat ststat;
		printsl(pattern);

		while ( argc-->2 ){
				text_match stm;
				  int fd = open(argv[argc],O_RDONLY);
					int r = fstat(fd,&ststat);
					die_if( r, r, "Couldn't stat" );
				  char *f = mmap(0,ststat.st_size, PROT_READ, MAP_PRIVATE, fd,0);
					//prints(f);

					if ( match_ext2( f, pattern, 0,0, &stm ) > 0){
							writes("MATCH\n");
							write(1,stm.pos,stm.len);
							write(1,"\n2\n",3);
					}
							write(1,stm.pos,stm.len);
							write(1,"\n1\n",3);
	

				munmap(f, ststat.st_size);	
				close(fd);
		}
		return(0);
}
