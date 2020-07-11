// This is "callen" just before main,
// it's included within _start.
// 
// dbg("Startup -xx"); // no arguments allowed here. 
// otherwise argv[] gets confused
// Or we would have to add some further bloating bytes

int main();//int argc, char **argv, char **envp );

int startup(int argc, char **argv, char **envp ){
		write(1,argv[0],3);
		write(1,envp[0],3);
#ifdef mini_globals_on_stack
minilib_globals __mlgl;
//{ .errno = 0, .mbuf[0] = 0, .environ=envp };
mlgl=&__mlgl;
#else
#endif

#ifdef mini_buf
//mlgl=&__mlgl;
mlgl->mbufsize = mini_buf-4;
mlgl->stream[0]=0;
mlgl->stream[1]=1;
mlgl->stream[2]=2;
mlgl->pstream = 3;

// this is callen within _start (past exit)
//optimization_fence((void*)mlgl);
#endif

#ifdef mini_errno
errno = 0;
sysret = 0;
#endif

#ifdef mini_environ
// some trouble. guessing, the compiler does bad things with environ.
environ = envp;
#endif

	optimization_fence((void*)mlgl);
//	optimization_fence((void*)&__mlgl);
	//asm volatile("jmp main");
	return(main(argc,argv,envp));
}

