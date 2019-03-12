
#ifndef minilib_header_h
#include "include/minilib_header.h"
#endif


#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER int
#endif



#ifdef mini_buf
#include "src/mbuf.c"
#endif

#ifdef mini_itohex
#include "src/itohex.c"
#endif

#ifdef mini_itodec
#include "src/itodec.c"
#endif

#ifdef mini_dtodec
#include "src/dtodec.c"
#endif

#ifdef mini_atoi
#include "src/atoi.c"
#endif

#ifdef mini_itobin
#include "src/itobin.c"
#endif




#ifdef mini_puts
#define mini_print
#endif

#ifdef mini_print
#include "src/mprint.c"

#define mini_errno
#endif


#ifdef mini_mfprintf
#include "src/mfprintf.c"
#define mini_errno
#endif



#ifdef mini_errno
int errno;
#endif
//int sysret=0;

#ifndef OSX

#ifdef mini_vsyscalls
int __mini_vsys = 0;
#include "src/start_c.c"
#endif

#ifdef mini_start
#ifdef X64
#include "asm/start-linux-x64.c"
#else
#include "asm/start.c"
#endif
#endif


#else

#ifdef mini_start
#include "asm/start-osx.c"
#endif


#endif


#ifdef mini_mprints
#include "src/mprints.c"
#endif

#ifdef mini_msprintf
#include "src/msprintf.c"
#endif

#ifdef mini_isspace
#include "src/isspace.c"
#endif

#ifdef mini_ioctl
#include "src/ioctl.c"
#endif

#ifdef mini_tcgetattr
#include "src/tcgetattr.c"
#endif

#ifdef mini_tcsetattr
#include "src/tcsetattr.c"
#endif

#ifdef mini_strcat
#include "src/strcat.c"
#endif


#ifdef mini_memcmp
#include "src/mstrcmp.c"
#endif


#ifdef mini_mstrcmp
#include "src/mstrcmp.c"
#endif

#ifdef mini_mstrlen
#include "src/mstrlen.c"
#endif

#ifdef mini_memset
#include "src/memset.c"
#endif

#ifdef mini_memcpy
#include "src/memcpy.c"
#endif


#ifdef mini_memfrob
#include "src/memfrob.c"
#endif

#ifdef mini_select
#include "src/select.c"
#endif

#ifdef mini_malloc
#include "src/malloc.c"
#endif

#ifdef mini_powers
#include "src/powers.c"
#endif


#include "include/syscall_stubs.h"

