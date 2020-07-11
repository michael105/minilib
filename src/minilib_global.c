#ifndef minilib_globals_c
#define minilib_globals_c

// 
//#ifndef mini_buf
//#warning defining minibuf
//#define mini_buf 1024
//#endif
//
#ifdef mini_buf

#ifndef mini_globals_on_stack
// goes into .data/.bss section
// if globals are on the stack, 
// the structure is defined in startup.c
// (which is included in _start)
minilib_globals __mlgl;
minilib_globals *mlgl;
#else

register minilib_globals  __attribute__((used)) *mlgl asm("r15");

#endif

#else

#endif


// pointer to env**
// gets assigned in asm/start-*.c
#ifdef mini_environ
char **environ;
#endif


#ifdef mini_errno
#ifndef mini_globals_on_stack
int errno;
#endif
int sysret;
#endif



#endif
