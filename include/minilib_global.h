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


typedef struct {
		int errno;
		int sysret;
		int srand;	
		int pstream;
		int mbufsize;
		int _intbufsize;
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
#ifdef mini_ether_ntoa
		char ether_ntoa_addr[20]; // padded to %4
#endif


} __globals_shadow;


typedef struct {
		int errno;
		int sysret;
		int srand;	
		int pstream;
		int mbufsize;
		int _intbufsize;
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
#ifdef mini_ether_ntoa
		char ether_ntoa_addr[20]; // padded to %4
#endif

#if mini_GLOBALS & MINI_GUARDED_GLOBALS && GLOBALS & BSS_SECTION
		char __padding1[PAGESIZE-sizeof(__globals_shadow)];
		char __guardpage1[PAGESIZE];
#define __mini_guardpage1
#endif

#ifdef mini_internalbuf
		union {
				int intibuf[(mini_internalbufsize>>2)];
				char intmbuf[mini_internalbufsize];
		};
#if mini_GLOBALS & MINI_GUARDED_GLOBALS
		char __padding2[ PAGESIZE - (mini_internalbufsize % PAGESIZE) ];
		char __guardpage2[ PAGESIZE ];
#define __mini_guardpage2
#endif
#endif

		union {
				int ibuf[(mini_bufsize>>2)];
				char mbuf[mini_bufsize];
		};

#if mini_GLOBALS & MINI_GUARDED_GLOBALS
		char __padding3[ PAGESIZE - (mini_bufsize % PAGESIZE) ];
		char __guardpage3[ PAGESIZE ];
#define __mini_guardpage3
#endif
} minilib_globals;

#ifndef __clang__

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
// Doesn't work with clang.
// But yet I also didn't it with clang.
//+def optimization_fence
static void __attribute__((noipa,cold)) optimization_fence(void*p){}

#endif


// void __attribute__((noipa,naked))prevent_optimization(void*p){
// strangely, naked results in a bigger binary. (+4 Bytes)
// and will result in a runtime error. undefined opcode. so.
#ifdef mini_globals_on_stack
#ifndef mini_globals
#define mini_globals
#endif
#ifndef mini_globalregister
// use register r15 by default (GCC only)
#define mini_globalregister "r15"
#endif
#endif




#ifdef mini_globals




#ifndef mini_globalregister

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

#else //mini_globalregister

// when the global are located on the stack, 
// (globals_on_stack), the position needs to be saved.
// Using r15 for the position.
// Locating all globals on the stack might only in some special cases
// give advantages. (sparing the .data and .bss segments, for example)
// Same when loading "plugins"
//
// Seems to me the easiest way, mixing position independent code
// and common "globals".
// Especially, since (here r15) is rarely used with amd64 and gcc.
// for Saving the register, it would also be possible to store the address
// of the globals at a fixed position, e.g. the beginning of the text section.
// Or allocating the globals at a fixed memory position..
//
// However.
// The option to have the globals at a varying address gives as a sideeffect
// a certain security advantage. Albite, well.
// I leave this at it is for now.
//
#ifndef __clang__
register minilib_globals __attribute__((used))*__restrict__ mlgl asm(mini_globalregister);
#else
minilib_globals __attribute__((used))*__restrict__ mlgl;
#endif

#define errno mlgl->errno
#ifdef mini_environ
//+doc pointer to env, when mini_getenv is defined.
//extern char **environ;
#define environ mlgl->environ

#endif



#endif //mini_globals_on_stack

#else 


#endif

#endif

