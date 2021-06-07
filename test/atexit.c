#if 0
mini_start
mini_writes
mini_atexit 4

OPTFLAG
INCLUDESRC

return
#endif

void func(void){
		writes("in the func\n");
}

void func2(void){
		writes("in the func2\n");
}



int main(int argc, char **argv){

		typedef void (function)(void);
		function *f[8];

		writes("Calling functions\n");

		f[0] = &func;
		f[1] = &func2;

		function *f2;
		f2=&func;
		f2();
		f[0]();
		f[1]();

		writes("Registering atexit\n");

		atexit( &func2 );
		atexit( &func );

		writes("Exit.\n");

		exit(0);

		writes("Error.\n");
		return(1);
}
