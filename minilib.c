/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_minilib_c
#define included_minilib_c

/* header.in */


#ifndef mini_INCLUDESRC
#ifdef INCLUDESRC
#define mini_INCLUDESRC
#endif
#endif


#ifdef HEADERGUARDS
#ifndef mini_HEADERGUARDS
#define mini_HEADERGUARDS
#endif
#endif


#ifdef HEADERGUARDS
#include "minilib/include/headerguards.h"
#endif

//#define mini_start
//#define mini_exit

#include "minilib/include/globaldefs.h"
#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/include/timeval.h"
#include "minilib/headers/common/sys/types.h"



//#include "minilib.conf"
#include "minilib.h"
#include "minilib/asm/start.c"
#include "minilib/src/minilib_global.c"

#ifdef mini_prints
#include "minilib/src/prints.c"
#endif

#ifdef mini_errno
int errno;
int sysret;
#endif



// minilib/src/dirent/readdir.c
#ifdef mini_readdir
#include "minilib/src/dirent/readdir.c"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strcmp
#include "minilib/src/mstrcmp.c"
#endif

// minilib/src/fprintfs.c
#ifdef mini_fprintfs
#include "minilib/src/fprintfs.c"
#endif

// minilib/src/rand.c
#ifdef mini_rand
#include "minilib/src/rand.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_dprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_fprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/dirent/closedir.c
#ifdef mini_closedir
#include "minilib/src/dirent/closedir.c"
#endif

// minilib/src/itohex.c
#ifdef mini__itohex
#include "minilib/src/itohex.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_snprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/malloc.c
#ifdef mini_malloc
#include "minilib/src/malloc.c"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_memcmp
#include "minilib/src/mstrcmp.c"
#endif

// minilib/src/itodec.c
#ifdef mini_uitodec
#include "minilib/src/itodec.c"
#endif

// minilib/src/itohex.c
#ifdef mini_itohex
#include "minilib/src/itohex.c"
#endif

// minilib/src/strerror.c
#ifdef mini_strerror
#include "minilib/src/strerror.c"
#endif

// minilib/src/itodec.c
#ifdef mini_itodec
#include "minilib/src/itodec.c"
#endif

// minilib/src/malloc.c
#ifdef mini_free
#include "minilib/src/malloc.c"
#endif

// minilib/src/dirent/opendir.c
#ifdef mini_opendir
#include "minilib/src/dirent/opendir.c"
#endif

// minilib/src/itobin.c
#ifdef mini__itobin
#include "minilib/src/itobin.c"
#endif

// minilib/src/memcpy.c
#ifdef mini_strcpy
#include "minilib/src/memcpy.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_vsnprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/memcpy.c
#ifdef mini_strncpy
#include "minilib/src/memcpy.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_sprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/mstrcmp.c
#ifdef mini_strncmp
#include "minilib/src/mstrcmp.c"
#endif

// minilib/src/basename.c
#ifdef mini_basename
#include "minilib/src/basename.c"
#endif

// minilib/src/fopen.c
#ifdef mini_fopen
#include "minilib/src/fopen.c"
#endif

// minilib/src/itohex.c
#ifdef mini_itoHEX
#include "minilib/src/itohex.c"
#endif

// minilib/src/rand.c
#ifdef mini_srand
#include "minilib/src/rand.c"
#endif

// minilib/src/memcpy.c
#ifdef mini_memcpy
#include "minilib/src/memcpy.c"
#endif

// minilib/src/open.c
#ifdef mini_open
#include "minilib/src/open.c"
#endif

// minilib/src/getenv.c
#ifdef mini_getenv
#include "minilib/src/getenv.c"
#endif

// minilib/src/dtodec.c
#ifdef mini_dtodec
#include "minilib/src/dtodec.c"
#endif

// minilib/src/strlen.c
#ifdef mini_strlen
#include "minilib/src/strlen.c"
#endif

// minilib/src/memfrob.c
#ifdef mini_memfrob
#include "minilib/src/memfrob.c"
#endif

// minilib/src/prints.c
#ifdef mini__mprints
#include "minilib/src/prints.c"
#endif

// minilib/src/atoi.c
#ifdef mini_atoi
#include "minilib/src/atoi.c"
#endif

// minilib/src/ioctl.c
#ifdef mini_ioctl
#include "minilib/src/ioctl.c"
#endif

// minilib/src/strerror.c
#ifdef mini_perror
#include "minilib/src/strerror.c"
#endif

// minilib/src/strcat.c
#ifdef mini_strcat
#include "minilib/src/strcat.c"
#endif

// minilib/src/open.c
#ifdef mini_creat
#include "minilib/src/open.c"
#endif

// minilib/src/memset.c
#ifdef mini_memset
#include "minilib/src/memset.c"
#endif

// minilib/src/isspace.c
#ifdef mini_isspace
#include "minilib/src/isspace.c"
#endif

#endif
