#if 0
#globals_on_stack
mini_errno
mini_start
mini_printsl
mini_prints
mini_writes
mini_getenv
mini_environ
mini_where
mini_INCLUDESRC
LDSCRIPT default
SHRINKELF
return
#endif


int main( int argc, char *argv[], char *envp[] ){
		if ( argc < 2 ){
				writes("usage: where executable executable ..");
				exit(1);
		}
		char buf[PATH_MAX];
		int r = 1;

		while ( argc-->1 ){
		if ( where(argv[argc],buf) ){
				printsl(buf);
				r = 0;
		} else {
				prints( argv[argc], " not found\n" );
		}
		}
		return(r);
}
