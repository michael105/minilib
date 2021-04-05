#ifndef mini_startup_c
#define mini_startup_c
// This is "callen" from _start,
// 

#ifdef mini_globals

int main();//int argc, char **argv, char **envp );

int _startup(int argc, char **argv, char **envp ){
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
minilib_globals __mlgl;
//{ .errno = 0, .mbuf[0] = 0, .environ=envp };
mlgl=&__mlgl;
#else
#endif

#ifdef mini_buf
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
errno = 0;
//sysret = 0;
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

	_exit(ret); 
	// exits here. 
	// This does a jump to _exit:
	// As a sideeffect, also if there would have been a overrun in the
	// globals (when located at the stack), the "return address" is unaffected.
	// The buffer of minilib for malloc, printf, andsoon is located at the end of the globals,
	// so that's the main danger.
	//
	// the next call prevents gcc from optimizing the assignments 
	// to the globals out.
	// gcc doesn't know, we exit before.
	// all other options, like using the global struct within a asm volatile,
	// and so on, have shown up to be unreliable.
#ifdef mini_globals
	//optimization_fence((void*)mlgl);
	OPTFENCE((void*)mlgl);
#endif
	// silence compiler warning.
	return(ret);
}

#endif

#endif
