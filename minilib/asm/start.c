#ifndef start_c
#define start_c

#ifndef OSX

#ifdef mini_vsyscalls
int __mini_vsys = 0;
#include "../src/start_c.c"
#endif

#ifdef mini_start
#ifdef X64
#include "start-linux-x64.c"
#else
#include "start-linux-x32.c"
#endif
#endif


#else

#ifdef mini_start
#include "start-osx.c"
#endif


#endif




#endif
