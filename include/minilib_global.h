#ifndef minilib_global_h
#define minilib_global_h


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

#ifndef mini_pwent
#ifdef mini_getpwent
#define mini_pwent
#endif
#ifdef mini_getpwuid
#define mini_pwent
#endif
#ifdef mini_getpwnam
#define mini_pwent
#endif
#ifdef mini_setpwent
#define mini_pwent
#endif
#endif


#ifndef mini_grent
#ifdef mini_getgrent
#define mini_grent
#endif
#ifdef mini_getgrnam
#define mini_grent
#endif
#ifdef mini_getgroups
#define mini_grent
#endif
#ifdef mini_getgrgid
#define mini_grent
#endif

#endif



#ifdef mini_buf
#if mini_buf > 0
#else
#warning mini_buf defaults to 2048 Bytes
#define mini_buf 2048
#endif 
#endif


#ifdef mini_buf
#define mini_bufsize mini_buf
#ifndef mini_globals
#define mini_globals
#endif
#else
#define mini_bufsize 0
#endif

// the structure keeping the files
// passwd and group
typedef struct {
	char* file;
	char* p;
	char** p2;
	int size;
} userdb;

typedef struct {
		int errno;
		int sysret;
		int srand;	
		int pstream;
		int mbufsize;
		int align[1];
		char **environ;
		unsigned long brk;
		unsigned long malloc_start;
#ifdef mini_atexit
		functionp* atexitp[ATEXIT_MAX];
#endif
		void *appdata; // can be used freely. 
		// intended to be used for globals,
		// which can be located on the stack.
		// just define a struct on stack,
		// (e.g. within main),
		// and set this pointer to the struct.
		int stream[mini_FOPEN_MAX];
#ifdef mini_pwent
		userdb passwdfile;
		struct passwd pwent; // quite some overhead. But needed for threadsafety.
		// leaving it here for now. possibly todo: make pwent a switch,
		// either with or without threadsafety of getpwuid and family.
		// (keeping this struct within the globals, or not)
#endif
#ifdef mini_grent
		userdb groupfile;
		//int groupnamecount; TODO: enlarge the array to the groupname pointers,
		// when needed. (shrinking the minibuf) ->getgrent
		struct group groupent;
#endif
#ifdef mini_inet_ntoa
		char inet_ntoa_addr[16];
#endif

		union {
				int ibuf[(mini_bufsize>>2)];
				char mbuf[mini_bufsize];
		};
} minilib_globals;

//+doc prevent optimizations.
// cast a var to void*, and calling this,
// leaves the compiler unknown on what he can strip.
// The function attribute noipa means,
// the compiler doesn't know, what the function itself does.
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
//
// With less overhead the macro OPTFENCE(...) goes.
// There the call to the "ipa" function is jumped over,
// via asm inline instructions. 
//+def optimization_fence
static void __attribute__((noipa,cold)) optimization_fence(void*p){}



// void __attribute__((noipa,naked))prevent_optimization(void*p){
// strangely, naked results in a bigger binary. (+4 Bytes)
// and will result in a runtime error. undefined opcode. so.
#ifdef mini_globals_on_stack
#ifndef mini_globals
#define mini_globals
#endif
#endif




#ifdef mini_globals




#ifndef mini_globals_on_stack

extern minilib_globals*__restrict__ mlgl;
extern minilib_globals __mlgl;
#ifdef mini_errno
//extern int sysret;
extern int errno;
#endif
#ifdef mini_environ
//+doc pointer to env, when mini_getenv is defined.
extern char **environ;
#endif

#else //mini_globals_on_stack

#define errno mlgl->errno
//#define sysret mlgl->sysret
#ifdef mini_environ
//+doc pointer to env, when mini_getenv is defined.
//extern char **environ;
#define environ mlgl->environ

#endif

// when the global are located on the stack, 
// (globals_on_stack), the position needs to be saved.
// Using r15 for the position.
// Locating all globals on the stack might only in some special cases
// give advantages. (sparing the .data and .bss segments, for example)
register minilib_globals __attribute__((used))*__restrict__ mlgl asm("r15");


#endif //mini_globals_on_stack

#else 

//#warning no globals

#endif

#endif

