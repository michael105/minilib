/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Licensed under the terms of the BSD 3-clause License.
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_minilib_c
#define included_minilib_c

/* templates/header.in */


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

#ifndef mini_environ
#ifdef mini_getenv
#define mini_environ
#endif
#ifdef mini_system
#define mini_environ
#endif
#endif

#ifdef HEADERGUARDS
#include "minilib/include/headerguards.h"
#endif

//#define mini_start
//#define mini_exit

#include "minilib/macros/defgroups.h"

#include "minilib/headers/common/allheaders.h"
#include "minilib/headers/linux_x64/allheaders.h"

#include "minilib/include/globaldefs.h"
#include "minilib/include/minilib_global.h"
#include "minilib/include/ctype.h"
#include "minilib/include/dirent.h"
#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"


#ifdef mini_GETOPTS
#include "minilib/macros/getoptm.h"
#endif

/* end templates/header.in */
/* templates/minilib.c.in */

//#include "minilib.conf"

#ifndef included_minilib_h
#include "minilib.h"
#endif

#include "minilib/asm/start.c"
#include "minilib/src/minilib_global.c"

#ifdef mini_prints
#include "minilib/src/prints.c"
#endif

#ifdef mini_errno
#ifndef mini_globals_on_stack
int errno;
#endif
int sysret;
#endif

#include "src/startup.c"

/* end templates/minilib.c.in */

// minilib/src/itobin.c
#ifdef mini_itobin
#include "minilib/src/itobin.c"
#endif

// minilib/src/sigaction.c
#ifdef mini_raise
#include "minilib/src/sigaction.c"
#endif

// minilib/src/itodec.c
#ifdef mini_uitodec
#include "minilib/src/itodec.c"
#endif

// minilib/src/memset.c
#ifdef mini_memset
#include "minilib/src/memset.c"
#endif

// minilib/src/itohex.c
#ifdef mini__itohex
#include "minilib/src/itohex.c"
#endif

// minilib/src/fgets.c
#ifdef mini_gets
#include "minilib/src/fgets.c"
#endif

// minilib/src/strchr.c
#ifdef mini_strchrnul
#include "minilib/src/strchr.c"
#endif

// minilib/src/strcmp.c
#ifdef mini_memcmp
#include "minilib/src/strcmp.c"
#endif

// minilib/src/malloc.c
#ifdef mini_realloc
#include "minilib/src/malloc.c"
#endif

// minilib/src/qsort.c
#ifdef mini_swap
#include "minilib/src/qsort.c"
#endif

// minilib/src/brk.c
#ifdef mini_getbrk
#include "minilib/src/brk.c"
#endif

// minilib/src/execl.c
#ifdef mini_execl
#include "minilib/src/execl.c"
#endif

// minilib/src/mmap.c
#ifdef mini_mmap
#include "minilib/src/mmap.c"
#endif

// minilib/src/dprintf.c
#ifdef mini_dprintf
#include "minilib/src/dprintf.c"
#endif

// minilib/src/basename.c
#ifdef mini_basename
#include "minilib/src/basename.c"
#endif

// minilib/src/strdup.c
#ifdef mini_strdup
#include "minilib/src/strdup.c"
#endif

// minilib/src/open.c
#ifdef mini_open
#include "minilib/src/open.c"
#endif

// minilib/src/exit_errno.c
#ifdef mini_exit_errno
#include "minilib/src/exit_errno.c"
#endif

// minilib/src/strcmp.c
#ifdef mini_strncmp
#include "minilib/src/strcmp.c"
#endif

// minilib/src/brk.c
#ifdef mini_brk
#include "minilib/src/brk.c"
#endif

// minilib/src/memfrob.c
#ifdef mini_memfrob
#include "minilib/src/memfrob.c"
#endif

// minilib/src/dirent/closedir.c
#ifdef mini_closedir
#include "minilib/src/dirent/closedir.c"
#endif

// minilib/src/vexec.c
#ifdef mini_vexec
#include "minilib/src/vexec.c"
#endif

// minilib/src/signal.c
#ifdef mini_signal
#include "minilib/src/signal.c"
#endif

// minilib/src/strcmp.c
#ifdef mini__strcasecmp
#include "minilib/src/strcmp.c"
#endif

// minilib/src/snprintf.c
#ifdef mini_snprintf
#include "minilib/src/snprintf.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_fprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/memcpy.c
#ifdef mini_strcpy
#include "minilib/src/memcpy.c"
#endif

// minilib/src/qsort.c
#ifdef mini_qsort
#include "minilib/src/qsort.c"
#endif

// minilib/src/sigaction.c
#ifdef mini_sigaddset
#include "minilib/src/sigaction.c"
#endif

// minilib/src/prints.c
#ifdef mini_dprints
#include "minilib/src/prints.c"
#endif

// minilib/src/sleep.c
#ifdef mini_usleep
#include "minilib/src/sleep.c"
#endif

// minilib/src/itohex.c
#ifdef mini_itohex
#include "minilib/src/itohex.c"
#endif

// minilib/src/wait.c
#ifdef mini_waitpid
#include "minilib/src/wait.c"
#endif

// minilib/src/atexit.c
#ifdef mini_atexit
#include "minilib/src/atexit.c"
#endif

// minilib/src/strtol.c
#ifdef mini_strtol
#include "minilib/src/strtol.c"
#endif

// minilib/src/vsprintf.c
#ifdef mini_vsprintf
#include "minilib/src/vsprintf.c"
#endif

// minilib/src/malloc.c
#ifdef mini_free
#include "minilib/src/malloc.c"
#endif

// minilib/src/strchr.c
#ifdef mini_strchr
#include "minilib/src/strchr.c"
#endif

// minilib/src/isatty.c
#ifdef mini_isatty
#include "minilib/src/isatty.c"
#endif

// minilib/src/dirent/opendir.c
#ifdef mini_opendir
#include "minilib/src/dirent/opendir.c"
#endif

// minilib/src/prints.c
#ifdef mini__mprints
#include "minilib/src/prints.c"
#endif

// minilib/src/strchr.c
#ifdef mini_strrchr
#include "minilib/src/strchr.c"
#endif

// minilib/src/ext_match.c
#ifdef mini_ext_match
#include "minilib/src/ext_match.c"
#endif

// minilib/src/pty.c
#ifdef mini_ptsname_r
#include "minilib/src/pty.c"
#endif

// minilib/src/dirent/scandir.c
#ifdef mini_scandir_bufsize
#include "minilib/src/dirent/scandir.c"
#endif

// minilib/src/strcat.c
#ifdef mini_strcat
#include "minilib/src/strcat.c"
#endif

// minilib/src/malloc.c
#ifdef mini_malloc_brk
#include "minilib/src/malloc.c"
#endif

// minilib/src/fopen.c
#ifdef mini_fdopen
#include "minilib/src/fopen.c"
#endif

// minilib/src/wait.c
#ifdef mini_wait
#include "minilib/src/wait.c"
#endif

// minilib/src/brk.c
#ifdef mini_sbrk
#include "minilib/src/brk.c"
#endif

// minilib/src/fprintfs.c
#ifdef mini_fprintfs
#include "minilib/src/fprintfs.c"
#endif

// minilib/src/system.c
#ifdef mini_system
#include "minilib/src/system.c"
#endif

// minilib/src/sleep.c
#ifdef mini_sleep
#include "minilib/src/sleep.c"
#endif

// minilib/src/getenv.c
#ifdef mini_getenv
#include "minilib/src/getenv.c"
#endif

// minilib/src/itooct.c
#ifdef mini_itooct
#include "minilib/src/itooct.c"
#endif

// minilib/src/pty.c
#ifdef mini_ptsname
#include "minilib/src/pty.c"
#endif

// minilib/src/pty.c
#ifdef mini_posix_openpt
#include "minilib/src/pty.c"
#endif

// minilib/src/memcpy.c
#ifdef mini_strncpy
#include "minilib/src/memcpy.c"
#endif

// minilib/src/sigaction.c
#ifdef mini_sigemptyset
#include "minilib/src/sigaction.c"
#endif

// minilib/src/pty.c
#ifdef mini_unlockpt
#include "minilib/src/pty.c"
#endif

// minilib/src/memcpy.c
#ifdef mini_memcpy
#include "minilib/src/memcpy.c"
#endif

// minilib/src/execvp.c
#ifdef mini_execv
#include "minilib/src/execvp.c"
#endif

// minilib/src/atoi.c
#ifdef mini_atoi
#include "minilib/src/atoi.c"
#endif

// minilib/src/strcmp.c
#ifdef mini_strcasecmp
#include "minilib/src/strcmp.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_sprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/itohex.c
#ifdef mini_itoHEX
#include "minilib/src/itohex.c"
#endif

// minilib/src/strstr.c
#ifdef mini_strstr
#include "minilib/src/strstr.c"
#endif

// minilib/src/strcmp.c
#ifdef mini__strcmp
#include "minilib/src/strcmp.c"
#endif

// minilib/src/execvp.c
#ifdef mini_execvp
#include "minilib/src/execvp.c"
#endif

// minilib/src/ltodec.c
#ifdef mini_ultodec
#include "minilib/src/ltodec.c"
#endif

// minilib/src/dirent/seekdir.c
#ifdef mini_seekdir
#include "minilib/src/dirent/seekdir.c"
#endif

// minilib/src/sigaction.c
#ifdef mini_sigfillset
#include "minilib/src/sigaction.c"
#endif

// minilib/src/memmove.c
#ifdef mini_memmove
#include "minilib/src/memmove.c"
#endif

// minilib/src/fopen.c
#ifdef mini_freopen
#include "minilib/src/fopen.c"
#endif

// minilib/src/fopen.c
#ifdef mini__fopen
#include "minilib/src/fopen.c"
#endif

// minilib/src/dirent/readdir.c
#ifdef mini_readdir
#include "minilib/src/dirent/readdir.c"
#endif

// minilib/src/open.c
#ifdef mini_creat
#include "minilib/src/open.c"
#endif

// minilib/src/hashes.c
#ifdef mini_sdbm_hash
#include "minilib/src/hashes.c"
#endif

// minilib/src/putenv.c
#ifdef mini_putenv
#include "minilib/src/putenv.c"
#endif

// minilib/src/perror.c
#ifdef mini_perror
#include "minilib/src/perror.c"
#endif

// minilib/src/malloc.c
#ifdef mini_malloc
#include "minilib/src/malloc.c"
#endif

// minilib/src/hashes.c
#ifdef mini_djb2_hash
#include "minilib/src/hashes.c"
#endif

// minilib/src/dirent/opendir.c
#ifdef mini_opendirp
#include "minilib/src/dirent/opendir.c"
#endif

// minilib/src/dirent/telldir.c
#ifdef mini_telldir
#include "minilib/src/dirent/telldir.c"
#endif

// minilib/src/dirent/dirfd.c
#ifdef mini_dirfd
#include "minilib/src/dirent/dirfd.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_vsnprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/atoi.c
#ifdef mini_atol
#include "minilib/src/atoi.c"
#endif

// minilib/src/errno_str.c
#ifdef mini_errno_str
#include "minilib/src/errno_str.c"
#endif

// minilib/src/fopen.c
#ifdef mini_fopen
#include "minilib/src/fopen.c"
#endif

// minilib/src/strlen.c
#ifdef mini_strlen
#include "minilib/src/strlen.c"
#endif

// minilib/src/dirent/rewinddir.c
#ifdef mini_rewinddir
#include "minilib/src/dirent/rewinddir.c"
#endif

// minilib/src/match.c
#ifdef mini_match
#include "minilib/src/match.c"
#endif

// minilib/src/dtodec.c
#ifdef mini_dtodec
#include "minilib/src/dtodec.c"
#endif

// minilib/src/strcmp.c
#ifdef mini_strcmp
#include "minilib/src/strcmp.c"
#endif

// minilib/src/itobin.c
#ifdef mini__itobin
#include "minilib/src/itobin.c"
#endif

// minilib/src/dirent/alphasort.c
#ifdef mini_alphasort
#include "minilib/src/dirent/alphasort.c"
#endif

// minilib/src/sigaction.c
#ifdef mini_sigprocmask
#include "minilib/src/sigaction.c"
#endif

// minilib/src/sigaction.c
#ifdef mini_sigaction
#include "minilib/src/sigaction.c"
#endif

// minilib/src/pty.c
#ifdef mini_grantpt
#include "minilib/src/pty.c"
#endif

// minilib/src/fgets.c
#ifdef mini_fgets
#include "minilib/src/fgets.c"
#endif

// minilib/src/strcmp.c
#ifdef mini_strncasecmp
#include "minilib/src/strcmp.c"
#endif

// minilib/src/strerror.c
#ifdef mini_strerror
#include "minilib/src/strerror.c"
#endif

// minilib/src/sigaction.c
#ifdef mini_sigismember
#include "minilib/src/sigaction.c"
#endif

// minilib/src/sigaction.c
#ifdef mini_sigdelset
#include "minilib/src/sigaction.c"
#endif

// minilib/src/vexec.c
#ifdef mini_vexec_q
#include "minilib/src/vexec.c"
#endif

// minilib/src/execvp.c
#ifdef mini_execvpe
#include "minilib/src/execvp.c"
#endif

// minilib/src/dirname.c
#ifdef mini_dirname
#include "minilib/src/dirname.c"
#endif

// minilib/src/malloc.c
#ifdef mini_free_brk
#include "minilib/src/malloc.c"
#endif

// minilib/src/dirent/scandir.c
#ifdef mini_scandir
#include "minilib/src/dirent/scandir.c"
#endif

// minilib/src/brk.c
#ifdef mini_sys_brk
#include "minilib/src/brk.c"
#endif

// minilib/src/ioctl.c
#ifdef mini_ioctl
#include "minilib/src/ioctl.c"
#endif

// minilib/src/rand.c
#ifdef mini_rand
#include "minilib/src/rand.c"
#endif

// minilib/src/abort.c
#ifdef mini_abort
#include "minilib/src/abort.c"
#endif

// minilib/src/itodec.c
#ifdef mini_itodec
#include "minilib/src/itodec.c"
#endif

// minilib/src/ltodec.c
#ifdef mini_ltodec
#include "minilib/src/ltodec.c"
#endif

// minilib/src/rand.c
#ifdef mini_srand
#include "minilib/src/rand.c"
#endif

#endif
