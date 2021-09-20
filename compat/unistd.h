/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_unistd_h
#define included_unistd_h

#warning compat headers are instable.
#warning Better include minilib.h or use mlcc, when possible


#ifndef mini_INCLUDESRC
#ifdef INCLUDESRC
#define mini_INCLUDESRC
#endif
#endif


#define mini_start
#define mini_exit

#ifndef mini_buf
#define mini_buf 1024
#endif



#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER int
#endif

#ifndef uint32_t
#define uint32_t uint
#endif

#ifndef uint8_t
#define uint8_t uchar
#endif

#ifndef size_t
#define size_t long
#endif


#ifndef NULL
#define NULL 0
#endif

//#include "minilib/include/timeval.h"
#include "minilib/include/filemodes.h"

#include "minilib/headers/common/bits/alltypes.h"
#include "minilib/include/globaldefs.h"
#include "minilib/include/minilib_global.h"
#include "minilib/headers/common/dirent.h"
#include "minilib/headers/common/bits/signal.h"
#include "minilib/headers/common/bits/stat.h"
#include "minilib/headers/common/signal.h"
#include "minilib/headers/common/ctype.h"
#include "minilib/include/ctype.h"
#include "minilib/include/syscall.h"
#include "minilib/headers/linux_x64/sys/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"


#include "minilib/headers/common/allheaders.h"
#include "minilib/headers/linux_x64/allheaders.h"

#include "minilib/include/minilib_global.h"
#include "minilib/include/dirent.h"


#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"

#include "include/exit.h"

#include "minilib/include/globaldefs.h"
#include "include/minilib_global.h"

#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"

#include "minilib/include/headerguards.h"


#include "sys/termios.h"
#include "ioctl.h"
// file: minilib/include/exit.h
#include "minilib/include/exit.h"
// file: minilib/include/lseek.h
#include "minilib/include/lseek.h"
// file: minilib/include/select.h
#include "minilib/include/select.h"
// file: minilib/include/tcgetattr.h
#include "minilib/include/tcgetattr.h"
// file: minilib/include/tcsetattr.h
#include "minilib/include/tcsetattr.h"
// file: minilib/src/exec/_execv.c
static inline int execv(const char *pathname, char *const argv[]);

// file: minilib/src/exec/_execvp.c
static inline int execvp(const char *file, char *const argv[]);

// file: minilib/src/exec/execl.c
static int execl(const char *pathname, const char* arg0,... );

// file: minilib/src/exec/execvp.c
static int execvpe(const char *file, char *const argv[], char *const envp[]);

// file: minilib/src/network/gethostname.c
static int gethostname(char *name,int len);

// file: minilib/src/process/sleep.c
#include "minilib/src/process/sleep.c"
// file: minilib/src/process/sleep.c
#include "minilib/src/process/sleep.c"
// file: minilib/src/termios/isatty.c
#include "minilib/src/termios/isatty.c"
// file: minilib/src/userdb/getgroups.c
int getgroups(int maxgroups, int *list);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/exec/execvp.c"
#include "minilib/src/userdb/getgroups.c"
#include "minilib/src/exec/_execv.c"
#include "minilib/src/exec/_execvp.c"
#include "minilib/src/network/gethostname.c"
#include "minilib/src/exec/execl.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
