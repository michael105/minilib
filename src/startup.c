// This is "callen" just before main.
// 
// dbg("Startup -xx"); // no arguments allowed here. 
// otherwise argv[] gets confused
// Or we would have to add some further bloating bytes
#ifdef mini_buf
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
// some trouble. guessing, the compiler does bad things with environ.
environ = 0;
#endif


