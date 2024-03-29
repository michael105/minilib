#ifndef mini_startup_c
#define mini_startup_c
// This is "callen" from _start,
// 

#ifdef mini_globals

int main();

void __attribute__((noreturn))_startup(int argc, char **argv, char **envp ){
	// these init instructions
	// I guess, it would be better 
	// writing the assembly from hand,
	// and omit this whole 
	// _startup function.
	// Finally, this is unnecessary overhead.
	// at the latest with the optimization fence,
	// the jump to main isn't possible anymore.


#ifdef mini_globals_on_stack
		// put the globals onto the stack.
		// (the return address of _startup isn't used,
		// so an overflow would result in a segfault)
#ifdef DOESNT_ORK_GUARDED_GLOBALS // todo: file bugreport.
#warning guard
struct { 
	char guard1[PAGESIZE*2];
	minilib_globals __mlgl;
	char guard2[PAGESIZE*2];
} gl;
mlgl=&gl.__mlgl;

int r = mprotect( (gl.guard2 + ( (long)(&gl.guard2)%PAGESIZE )), 1, PROT_NONE );
sprintf(mlgl->mbuf,"a: %lx - %lx - ret: %d", gl.guard2,(gl.guard2 + ( (long)(&gl.guard2)%PAGESIZE )),r );

#else 
minilib_globals __mlgl;
mlgl=&__mlgl;
#endif

#else // globals_on_stack
mlgl=&__mlgl;
#endif

#ifdef mini_buf
// didn't change the size.
// but possible to dynamically allocate the globals.
//mlgl=__buf;
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
errno = 0;
#endif

#ifdef mini_environ
environ = envp;
#endif

#ifdef mini_atexit
mlgl->atexitp[0]=0;
#endif

#ifdef mini_pwent
mlgl->passwdfile.file = 0;
mlgl->pwent.pw_name = 0;
#endif

#ifdef mini_groupfile
mlgl->groupfile.file = 0;
mlgl->grent.gr_name = 0;
#endif


	mlgl->brk=0;
	mlgl->malloc_start=0;
	
	// call main
	int ret = main(argc,argv,envp);
	//asm volatile("jmp main");

#ifdef mini_atexit
#ifdef X64
	asm volatile(".global _atexit\n_atexit:":"=D"(ret));
#else
	asm volatile(".global _atexit\n_atexit:":"=d"(ret));
#endif
	if ( mlgl->atexitp[0] ){
			int p;
			for ( p=0; mlgl->atexitp[p]!=0 && p<=ATEXIT_MAX; p++ );
			while ( p>0 ){
					p--;
					mlgl->atexitp[p]();
			}
	}
#endif


#ifdef X64
	asm("jmp __exit"::"D"(ret));
#else
	asm("jmp __exit"::"b"(ret););
#endif
	// exits here. 
	// This does a jump to __exit:
	// As a sideeffect, also if there would have been a overrun in the
	// globals (when located at the stack), the "return address" is unaffected.
	// The buffer of minilib for malloc, printf, andsoon is located at the end of the globals,
	// so that's the main danger.
	//
	// the next call prevents gcc from optimizing the assignments 
	// to the globals out.
	// gcc doesn't recognize, we exit before,
	// the optimizer doesn't (yet) recognize the inline assembly jmp.
	// all other options, like using the global struct within a asm volatile,
	// and so on, have shown up to be unreliable.
#ifdef mini_globals
#ifndef __clang__
	opt_fence((void*)mlgl);
#endif
#endif
	// silence compiler warning.
	__builtin_unreachable();
}

#endif

#endif
