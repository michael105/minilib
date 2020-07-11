#ifndef minilib_global_h
#define minilib_global_h

// Don't like this pattern.
// Will most likely "bloat" minilib.
// But other options do not seem sensible.

//#ifndef mini_buf
//#warning defining mini_buf
//#define mini_buf 1024
//#endif

#ifdef mini_buf
#define mini_bufsize mini_buf
#else
#define mini_bufsize 0
#endif


typedef struct {
		int errno;
		int sysret;
		int srand;	
		int pstream;
		int mbufsize;
		int align[1];
		char **environ;
		int stream[mini_FOPEN_MAX];
		union {
				int ibuf[(mini_bufsize>>2)];
				char mbuf[mini_bufsize];
		};
} minilib_globals;

//+doc prevent optimizations.
// cast a var to void*, and calling this,
// leaves the compiler unknown on what he can strip.
// (noipa) means the compiler doesn't know, what the function itself does.
// (the function does nothing, but don't tell that gcc, please..)
// therefore, everything used as parameter to this function,
// will be calculated, defined, and so on before.
// It's used for the globals, 
// shich are pushed within _start onto the stack.
// since _start itself only provides a global pointer,
// and initialitzes some of the globals,
// but doesn't use them again,
// this construction is needed.
// more funnily, the function will never be called.
// It's past the asm inline syscall to exit.
// But again, luckily gcc doesn't know.
// All other options, like having the globals volatile, 
// setting the optimization flag of _start to 0, 
// having a volatile asm call with the globals as param, and so on,
// have been useless. All after all, seems to me, ai has it's restrictions.
//+macro
static void __attribute__((noipa)) optimization_fence(void*p){
};

// void __attribute__((noipa,naked))prevent_optimization(void*p){
// strangely, naked results in a bigger binary. (+4 Bytes)
// and will result in a runtime error. undefined opcode. so.

extern minilib_globals *mlgl;
#ifdef mini_buf


#ifndef mini_globals_on_stack
extern minilib_globals __mlgl;
#ifdef mini_errno
extern int sysret;
extern int errno;
#endif

#else

#define errno mlgl->errno
//#define sysret mlgl->sysret

#endif

#else

//#warning no mini_buf

#endif

#ifdef mini_environ
//+doc pointer to env, when mini_getenv is defined.
//extern char **environ;
#define environ mlgl->environ
#endif

#endif
