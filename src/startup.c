// This is "callen" from _start,
// 

int main();//int argc, char **argv, char **envp );

int _startup(int argc, char **argv, char **envp ){

#ifdef mini_globals_on_stack
minilib_globals __mlgl;
//{ .errno = 0, .mbuf[0] = 0, .environ=envp };
mlgl=&__mlgl;
#else
#endif

#ifdef mini_buf
mlgl=&__mlgl;
mlgl->mbufsize = mini_buf-4;
mlgl->stream[0]=0;
mlgl->stream[1]=1;
mlgl->stream[2]=2;
mlgl->pstream = 3;

#endif

#ifdef mini_errno
errno = 0;
sysret = 0;
#endif

#ifdef mini_environ
environ = envp;
#endif

	// forces gcc to assign the mlgl data structure, 
	// and put the whole struct on the stack.
	// Or whatever is needed. 
	optimization_fence((void*)mlgl);
	//asm volatile("jmp main");
	return(main(argc,argv,envp));
}

