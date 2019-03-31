/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_minilib_c
#define included_minilib_c


//#include "minilib.conf"
#include "minilib.h"
#include "minilib/asm/start.c"
#include "minilib/src/minilib_global.c"

#ifdef mini_prints
#include "minilib/src/mprints.c"
#endif

#ifdef mini_errno
int errno;
int sysret;
#endif


/* header.in */

#include "minilib/include/globaldefs.h"
#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/include/timeval.h"
#include "minilib/headers/common/sys/types.h"



// minilib/src/mstrcmp.c
#ifdef mini_memcmp
#include "minilib/src/mstrcmp.c"
#endif

// minilib/src/mfprintf.c
#ifdef mini_fprintf
#include "minilib/src/mfprintf.c"
#endif

// minilib/src/memfrob.c
#ifdef mini_memfrob
#include "minilib/src/memfrob.c"
#endif

// minilib/src/msprintf.c
#ifdef mini_sprintf
#include "minilib/src/msprintf.c"
#endif

// minilib/src/itohex.c
#ifdef mini_itohex
#include "minilib/src/itohex.c"
#endif

// minilib/src/itobin.c
#ifdef mini__itobin
#include "minilib/src/itobin.c"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strcmp
#include "minilib/src/mstrcmp.c"
#endif

// minilib/src/mstrlen.c
#ifdef mini_strlen
#include "minilib/src/mstrlen.c"
#endif

// minilib/src/atoi.c
#ifdef mini_atoi
#include "minilib/src/atoi.c"
#endif

// minilib/src/memset.c
#ifdef mini_memset
#include "minilib/src/memset.c"
#endif

// minilib/src/malloc.c
#ifdef mini_free
#include "minilib/src/malloc.c"
#endif

// minilib/src/memcpy.c
#ifdef mini_strncpy
#include "minilib/src/memcpy.c"
#endif

// minilib/src/ioctl.c
#ifdef mini_ioctl
#include "minilib/src/ioctl.c"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strncmp
#include "minilib/src/mstrcmp.c"
#endif

// minilib/src/itodec.c
#ifdef mini_itodec
#include "minilib/src/itodec.c"
#endif

// minilib/src/fopen.c
#ifdef mini_fopen
#include "minilib/src/fopen.c"
#endif

// minilib/src/strcat.c
#ifdef mini_strcat
#include "minilib/src/strcat.c"
#endif

// minilib/src/isspace.c
#ifdef mini_isspace
#include "minilib/src/isspace.c"
#endif

// minilib/src/memcpy.c
#ifdef mini_strcpy
#include "minilib/src/memcpy.c"
#endif

// minilib/src/malloc.c
#ifdef mini_malloc
#include "minilib/src/malloc.c"
#endif

// minilib/src/dtodec.c
#ifdef mini_dtodec
#include "minilib/src/dtodec.c"
#endif

// minilib/src/mprint.c
#ifdef mini_printl
#include "minilib/src/mprint.c"
#endif

// minilib/src/open.c
#ifdef mini_open
#include "minilib/src/open.c"
#endif

// minilib/src/mprint.c
#ifdef mini_print
#include "minilib/src/mprint.c"
#endif

// minilib/src/open.c
#ifdef mini_creat
#include "minilib/src/open.c"
#endif

// minilib/src/itodec.c
#ifdef mini_uitodec
#include "minilib/src/itodec.c"
#endif

// minilib/src/memcpy.c
#ifdef mini_memcpy
#include "minilib/src/memcpy.c"
#endif

#endif
