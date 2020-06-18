#if 0
mini_start
mini_puts
mini_environ
mini_getenv

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/06
// BSD license

int main(int argc, char *argv[], char *envp[] ){

		if ( argc == 1 )
				for ( int a = 0;envp[a]; a++ )
						puts(envp[a]);
		else
				for ( int a = 1; argv[a]; a++ )
						puts(getenv(argv[a]));

		return(0);
}
