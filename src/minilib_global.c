#ifndef minilib_globals_c
#define minilib_globals_c

// 
//#ifndef mini_buf
//#warning defining minibuf
//#define mini_buf 1024
//#endif
//
#ifdef mini_buf
minilib_globals __mlgl;
minilib_globals *mlgl = &__mlgl;

#else

#endif


// pointer to env**
// gets assigned in asm/start-*.c
#ifdef mini_environ
char **environ;
#endif


#ifdef mini_errno
int sysret;
int errno;
#endif



#endif
