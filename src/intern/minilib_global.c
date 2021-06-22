#ifndef minilib_globals_c
#define minilib_globals_c


#ifdef mini_globals_on_stack
#ifndef mini_globals
#define mini_globals
#endif
#endif

#ifdef mini_errno
#ifndef mini_globals
#define mini_globals
#endif
#endif


#ifdef mini_environ
#ifndef mini_globals
#define mini_globals
#endif
#endif


#ifdef mini_buf
#ifndef mini_globals
#define mini_globals
#endif
#endif



#ifdef mini_globals

#ifndef mini_globals_on_stack
// goes into .data/.bss section
// if globals are on the stack, 
// the structure is defined in startup.c
// (which is included in _start)
//static char __buf[8192];
minilib_globals __mlgl;
minilib_globals * __restrict__ mlgl;// = &__buf;
//minilib_globals * __restrict__ mlgl = &__mlgl;

//char secondbuf[2048];

#ifdef mini_errno
int errno;
#endif

// pointer to env**
// gets assigned in src/startup.c
#ifdef mini_environ
char **environ;
#endif

#else // globals_on_stack

// is defined in the header. Must be defined for every source file.
//register minilib_globals  __attribute__((used))*__restrict__ mlgl asm("r15");

#endif


//#ifdef mini_errno
//int sysret;
//#endif


#endif //mini_globals

#endif
