
#ifndef minilib_header_h
#include "include/minilib_header.h"
#endif


#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER int
#endif



#ifdef mini_buf
//#include "src/mbuf.c"
#endif

#include "src/minilib_global.c"
// Obvoiusly, this will ad some extra bytes.
// But I don't seem another sensible way.

#ifdef mini_itohex
#include "src/itohex.c"
#endif

#ifdef mini_itodec
#include "src/itodec.c"
#endif

#ifdef mini_dtodec
#include "src/dtodec.c"
#endif

#ifdef mini_ltodec
#include "src/ltodec.c"
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


#ifdef mini_fprintf
#include "src/mfprintf.c"
#define mini_errno
#define mfprintf(...) fprintf(__VA_ARGS__)
#endif



#ifdef mini_errno
int errno;
#endif
//int sysret=0;

#include "asm/start.c"

#ifdef mini_prints
#include "src/mprints.c"
#endif

#ifdef mini_sprintf
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


#ifdef mini_strcmp
#include "src/mstrcmp.c"
#endif

#ifdef mini_strlen
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

#ifdef mini_open
#include "src/open.c"
#endif



#include "include/syscall_stubs.h"

