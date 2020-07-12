// This is "callen" from _start,
// 

int main();//int argc, char **argv, char **envp );

int _startup(int argc, char **argv, char **envp ){

#ifndef mini_globals
		// no globals, no initialization needed.
		// the jmp to main is possible,
		// since everyhing is set up and unchanged.
		// return from main will return directly to _start
//	asm volatile("jmp main");
//	seems to give trouble due to optimizations.
#endif

	// these init instructions
	// I guess, it would be better 
	// writing the assembly from hand,
	// and omit this whole 
	// _startup function.
	// Finally, this is unnecessary overhead.
	// at the latest with the optimization fence,
	// the jump to main isn't possible anymore.
#ifdef mini_globals_on_stack
#ifndef mini_globals
#define mini_globals
#endif
minilib_globals __mlgl;
//{ .errno = 0, .mbuf[0] = 0, .environ=envp };
mlgl=&__mlgl;
#else
#endif

#ifdef mini_buf
#ifndef mini_globals
#define mini_globals
#endif
mlgl=&__mlgl;
mlgl->mbufsize = mini_buf-4;
int a = 0;
for (; a<3; a++ )
	mlgl->stream[a]=a;
mlgl->pstream = a;
//mlgl->stream[0]=0;
//mlgl->stream[1]=1;
//mlgl->stream[2]=2;
//mlgl->pstream = 3;

#endif

#ifdef mini_errno
#ifndef mini_globals
#define mini_globals
#endif
errno = 0;
//sysret = 0;
#endif

#ifdef mini_environ
#ifndef mini_globals
#define mini_globals
#endif
environ = envp;
#endif

	// forces gcc to assign the mlgl data structure, 
	// and put the whole struct on the stack.
	// Or whatever is needed. 
#ifdef mini_globals
	optimization_fence((void*)mlgl);
#endif
	//asm volatile("jmp main");
	return(main(argc,argv,envp));
}

