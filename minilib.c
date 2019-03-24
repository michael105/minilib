/* This file is part of minilib, (c) 2012-2019 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of a BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. */


#ifndef included_minilib_c
#define included_minilib_c


#include "minilib.conf"
#include "src/asm/start.c"

// minilib/src/src/ioctl.c
#ifdef mini_ioctl
#include "minilib/src/src/ioctl.c"
#endif

// minilib/src/src/itodec.c
#ifdef mini_itodec
#include "minilib/src/src/itodec.c"
#endif

// minilib/src/src/strcat.c
#ifdef mini_strcat
#include "minilib/src/src/strcat.c"
#endif

// minilib/src/src/itodec.c
#ifdef mini_uitodec
#include "minilib/src/src/itodec.c"
#endif

// minilib/src/src/malloc.c
#ifdef mini_free
#include "minilib/src/src/malloc.c"
#endif

// minilib/src/src/malloc.c
#ifdef mini_malloc
#include "minilib/src/src/malloc.c"
#endif

// minilib/src/src/mstrlen.c
#ifdef mini_strlen
#include "minilib/src/src/mstrlen.c"
#endif

// minilib/src/src/isspace.c
#ifdef mini_isspace
#include "minilib/src/src/isspace.c"
#endif

// minilib/src/src/mfprintf.c
#ifdef mini_fprintf
#include "minilib/src/src/mfprintf.c"
#endif

// minilib/src/src/memfrob.c
#ifdef mini_memfrob
#include "minilib/src/src/memfrob.c"
#endif

// minilib/src/src/mstrcmp.c
#ifdef mini_memcmp
#include "minilib/src/src/mstrcmp.c"
#endif

// minilib/src/src/mstrcmp.c
#ifdef mini_strncmp
#include "minilib/src/src/mstrcmp.c"
#endif

// minilib/src/src/mstrcmp.c
#ifdef mini_strcmp
#include "minilib/src/src/mstrcmp.c"
#endif

// minilib/src/src/memcpy.c
#ifdef mini_strncpy
#include "minilib/src/src/memcpy.c"
#endif

// minilib/src/src/dtodec.c
#ifdef mini_dtodec
#include "minilib/src/src/dtodec.c"
#endif

// minilib/src/src/memset.c
#ifdef mini_memset
#include "minilib/src/src/memset.c"
#endif

// minilib/src/src/atoi.c
#ifdef mini_atoi
#include "minilib/src/src/atoi.c"
#endif

// minilib/src/src/itohex.c
#ifdef mini_itohex
#include "minilib/src/src/itohex.c"
#endif

// minilib/src/src/memcpy.c
#ifdef mini_strcpy
#include "minilib/src/src/memcpy.c"
#endif

// minilib/src/src/open.c
#ifdef mini_open
#include "minilib/src/src/open.c"
#endif

// minilib/src/src/memcpy.c
#ifdef mini_memcpy
#include "minilib/src/src/memcpy.c"
#endif

// minilib/src/src/mprint.c
#ifdef mini_printl
#include "minilib/src/src/mprint.c"
#endif

// minilib/src/src/msprintf.c
#ifdef mini_sprintf
#include "minilib/src/src/msprintf.c"
#endif

// minilib/src/src/itobin.c
#ifdef mini__itobin
#include "minilib/src/src/itobin.c"
#endif

// minilib/src/src/open.c
#ifdef mini_creat
#include "minilib/src/src/open.c"
#endif

// minilib/src/src/mprint.c
#ifdef mini_print
#include "minilib/src/src/mprint.c"
#endif

#endif
