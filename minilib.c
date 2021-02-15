/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_minilib_c
#define included_minilib_c

/* templates/minilib.c.in */

//#include "minilib.conf"

//#ifdef INCLUDESRC
//#ifndef mini_INCLUDESRC
//#define mini_INCLUDESRC
//#endif
//#endif

#ifndef included_minilib_h
//#include "minilib.h"
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
/* templates/minilib.c.in */

//#include "minilib.conf"

//#ifdef INCLUDESRC
//#ifndef mini_INCLUDESRC
//#define mini_INCLUDESRC
//#endif
//#endif

#ifndef included_minilib_h
//#include "minilib.h"
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

// minilib/src/fgetul.c
#ifdef mini_fgetul
#include "minilib/src/fgetul.c"
#endif

// minilib/src/qsort.c
#ifdef mini_swap
#include "minilib/src/qsort.c"
#endif

// minilib/src/ioctl.c
#ifdef mini_ioctl
#include "minilib/src/ioctl.c"
#endif

// minilib/src/brk.c
#ifdef mini_sbrk
#include "minilib/src/brk.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_sprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/getenv.c
#ifdef mini_getenv
#include "minilib/src/getenv.c"
#endif

// minilib/src/signal/sigaction.c
#ifdef mini_sigaddset
#include "minilib/src/signal/sigaction.c"
#endif

// minilib/src/userdb/getpwent.c
#ifdef mini_getpwent
#include "minilib/src/userdb/getpwent.c"
#endif

// minilib/src/die.c
#ifdef mini_die_if
#include "minilib/src/die.c"
#endif

// minilib/src/dirent/dirfd.c
#ifdef mini_dirfd
#include "minilib/src/dirent/dirfd.c"
#endif

// minilib/src/signal/sigaction.c
#ifdef mini_sigfillset
#include "minilib/src/signal/sigaction.c"
#endif

// minilib/src/exec/system.c
#ifdef mini_system
#include "minilib/src/exec/system.c"
#endif

// minilib/src/string/strcmp.c
#ifdef mini_strcmp
#include "minilib/src/string/strcmp.c"
#endif

// minilib/src/userdb/getgrent.c
#ifdef mini_getgrent
#include "minilib/src/userdb/getgrent.c"
#endif

// minilib/src/match_ext2.c
#ifdef mini__match_ext2
#include "minilib/src/match_ext2.c"
#endif

// minilib/src/signal/sigaction.c
#ifdef mini_sigsuspend
#include "minilib/src/signal/sigaction.c"
#endif

// minilib/src/string/strcat.c
#ifdef mini_strcat
#include "minilib/src/string/strcat.c"
#endif

// minilib/src/ltodec.c
#ifdef mini_ltodec
#include "minilib/src/ltodec.c"
#endif

// minilib/src/itodec.c
#ifdef mini_itodec
#include "minilib/src/itodec.c"
#endif

// minilib/src/hashes.c
#ifdef mini_djb2_hash
#include "minilib/src/hashes.c"
#endif

// minilib/src/userdb/getgrouplist.c
#ifdef mini_getgrouplist
#include "minilib/src/userdb/getgrouplist.c"
#endif

// minilib/src/string/strerror.c
#ifdef mini_strerror
#include "minilib/src/string/strerror.c"
#endif

// minilib/src/isatty.c
#ifdef mini_isatty
#include "minilib/src/isatty.c"
#endif

// minilib/src/putenv.c
#ifdef mini_putenv
#include "minilib/src/putenv.c"
#endif

// minilib/src/string/strchr.c
#ifdef mini_strchr
#include "minilib/src/string/strchr.c"
#endif

// minilib/src/wait.c
#ifdef mini_waitpid
#include "minilib/src/wait.c"
#endif

// minilib/src/dirent/readdir.c
#ifdef mini_readdir
#include "minilib/src/dirent/readdir.c"
#endif

// minilib/src/string/strstr.c
#ifdef mini_strstr
#include "minilib/src/string/strstr.c"
#endif

// minilib/src/signal/sigaction.c
#ifdef mini_sigprocmask
#include "minilib/src/signal/sigaction.c"
#endif

// minilib/src/atol.c
#ifdef mini_atol
#include "minilib/src/atol.c"
#endif

// minilib/src/perror.c
#ifdef mini_perror
#include "minilib/src/perror.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_fprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/fopen.c
#ifdef mini_fopen
#include "minilib/src/fopen.c"
#endif

// minilib/src/atoi.c
#ifdef mini_atoi
#include "minilib/src/atoi.c"
#endif

// minilib/src/rand.c
#ifdef mini_rand
#include "minilib/src/rand.c"
#endif

// minilib/src/open.c
#ifdef mini_creat
#include "minilib/src/open.c"
#endif

// minilib/src/dtodec.c
#ifdef mini_dtodec
#include "minilib/src/dtodec.c"
#endif

// minilib/src/brk.c
#ifdef mini_sys_brk
#include "minilib/src/brk.c"
#endif

// minilib/src/fgetsn.c
#ifdef mini_fgetsn
#include "minilib/src/fgetsn.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_grantpt
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/rand.c
#ifdef mini_srand
#include "minilib/src/rand.c"
#endif

// minilib/src/userdb/getgrnam.c
#ifdef mini_getgrnam
#include "minilib/src/userdb/getgrnam.c"
#endif

// minilib/src/exec/vexec.c
#ifdef mini_vexec_q
#include "minilib/src/exec/vexec.c"
#endif

// minilib/src/itobin.c
#ifdef mini_itobin
#include "minilib/src/itobin.c"
#endif

// minilib/src/string/strchr.c
#ifdef mini_strrchr
#include "minilib/src/string/strchr.c"
#endif

// minilib/src/match_ext2.c
#ifdef mini_match_ext2
#include "minilib/src/match_ext2.c"
#endif

// minilib/src/termios/tcsetattr.c
#ifdef mini_tcsetattr
#include "minilib/src/termios/tcsetattr.c"
#endif

// minilib/src/setenv.c
#ifdef mini_setenv
#include "minilib/src/setenv.c"
#endif

// minilib/src/userdb/getpwnam.c
#ifdef mini_getpwnam
#include "minilib/src/userdb/getpwnam.c"
#endif

// minilib/src/fgets.c
#ifdef mini_gets
#include "minilib/src/fgets.c"
#endif

// minilib/src/malloc.c
#ifdef mini_malloc
#include "minilib/src/malloc.c"
#endif

// minilib/src/string/strlcpy.c
#ifdef mini_strlcpy
#include "minilib/src/string/strlcpy.c"
#endif

// minilib/src/fgetsp.c
#ifdef mini_fgetsp
#include "minilib/src/fgetsp.c"
#endif

// minilib/src/basename.c
#ifdef mini_basename
#include "minilib/src/basename.c"
#endif

// minilib/src/userdb/getgroups.c
#ifdef mini_getgroups
#include "minilib/src/userdb/getgroups.c"
#endif

// minilib/src/map_protected.c
#ifdef mini_map_protected
#include "minilib/src/map_protected.c"
#endif

// minilib/src/userdb/setpwent.c
#ifdef mini_setpwent
#include "minilib/src/userdb/setpwent.c"
#endif

// minilib/src/dirent/closedir.c
#ifdef mini_closedir
#include "minilib/src/dirent/closedir.c"
#endif

// minilib/src/dirname.c
#ifdef mini_dirname
#include "minilib/src/dirname.c"
#endif

// minilib/src/die.c
#ifdef mini_dies_if
#include "minilib/src/die.c"
#endif

// minilib/src/userdb/userdb_open.c
#ifdef mini_userdb_open
#include "minilib/src/userdb/userdb_open.c"
#endif

// minilib/src/sleep.c
#ifdef mini_usleep
#include "minilib/src/sleep.c"
#endif

// minilib/src/userdb/setgrent.c
#ifdef mini_setgrent
#include "minilib/src/userdb/setgrent.c"
#endif

// minilib/src/string/stplcpy.c
#ifdef mini_stplcpy
#include "minilib/src/string/stplcpy.c"
#endif

// minilib/src/fopen.c
#ifdef mini_fdopen
#include "minilib/src/fopen.c"
#endif

// minilib/src/signal/sigaction.c
#ifdef mini_sigemptyset
#include "minilib/src/signal/sigaction.c"
#endif

// minilib/src/open.c
#ifdef mini_open
#include "minilib/src/open.c"
#endif

// minilib/src/exec/_execv.c
#ifdef mini_execv
#include "minilib/src/exec/_execv.c"
#endif

// minilib/src/mem/memmove.c
#ifdef mini_memmove
#include "minilib/src/mem/memmove.c"
#endif

// minilib/src/string/stpncpy.c
#ifdef mini_stpncpy
#include "minilib/src/string/stpncpy.c"
#endif

// minilib/src/exec/execvp.c
#ifdef mini_where
#include "minilib/src/exec/execvp.c"
#endif

// minilib/src/match.c
#ifdef mini_match
#include "minilib/src/match.c"
#endif

// minilib/src/termios/term_width.c
#ifdef mini_term_width
#include "minilib/src/termios/term_width.c"
#endif

// minilib/src/die.c
#ifdef mini_dies
#include "minilib/src/die.c"
#endif

// minilib/src/string/strtol.c
#ifdef mini_strtol
#include "minilib/src/string/strtol.c"
#endif

// minilib/src/string/stpcpy.c
#ifdef mini_stpcpy
#include "minilib/src/string/stpcpy.c"
#endif

// minilib/src/dirent/scandir.c
#ifdef mini_scandir_bufsize
#include "minilib/src/dirent/scandir.c"
#endif

// minilib/src/sleep.c
#ifdef mini_sleep
#include "minilib/src/sleep.c"
#endif

// minilib/src/termios/tcgetattr.c
#ifdef mini_tcgetattr
#include "minilib/src/termios/tcgetattr.c"
#endif

// minilib/src/abort.c
#ifdef mini_abort
#include "minilib/src/abort.c"
#endif

// minilib/src/string/strncpy.c
#ifdef mini_strncpy
#include "minilib/src/string/strncpy.c"
#endif

// minilib/src/wait.c
#ifdef mini_wait
#include "minilib/src/wait.c"
#endif

// minilib/src/userdb/getgrgid.c
#ifdef mini_getgrgid
#include "minilib/src/userdb/getgrgid.c"
#endif

// minilib/src/_fopen.c
#ifdef mini__fopen
#include "minilib/src/_fopen.c"
#endif

// minilib/src/prints.c
#ifdef mini_dprints
#include "minilib/src/prints.c"
#endif

// minilib/src/string/strdup.c
#ifdef mini_strdup
#include "minilib/src/string/strdup.c"
#endif

// minilib/src/itohex.c
#ifdef mini_itoHEX
#include "minilib/src/itohex.c"
#endif

// minilib/src/string/strcpy.c
#ifdef mini_strcpy
#include "minilib/src/string/strcpy.c"
#endif

// minilib/src/atexit.c
#ifdef mini_atexit
#include "minilib/src/atexit.c"
#endif

// minilib/src/dirent/rewinddir.c
#ifdef mini_rewinddir
#include "minilib/src/dirent/rewinddir.c"
#endif

// minilib/src/ltodec.c
#ifdef mini_ultodec
#include "minilib/src/ltodec.c"
#endif

// minilib/src/signal/sigaction.c
#ifdef mini_sigdelset
#include "minilib/src/signal/sigaction.c"
#endif

// minilib/src/string/strcmp.c
#ifdef mini_strcasecmp
#include "minilib/src/string/strcmp.c"
#endif

// minilib/src/snprintfs.c
#ifdef mini_snprintfs
#include "minilib/src/snprintfs.c"
#endif

// minilib/src/calloc.c
#ifdef mini_calloc
#include "minilib/src/calloc.c"
#endif

// minilib/src/clone.c
#ifdef mini_clone_t
#include "minilib/src/clone.c"
#endif

// minilib/src/fgets.c
#ifdef mini_fgets
#include "minilib/src/fgets.c"
#endif

// minilib/src/string/strcmp.c
#ifdef mini_memcmp
#include "minilib/src/string/strcmp.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_ptsname_r
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/qsort.c
#ifdef mini_qsort
#include "minilib/src/qsort.c"
#endif

// minilib/src/exec/execl.c
#ifdef mini_execl
#include "minilib/src/exec/execl.c"
#endif

// minilib/src/die.c
#ifdef mini_die
#include "minilib/src/die.c"
#endif

// minilib/src/dirent/opendir.c
#ifdef mini_opendir
#include "minilib/src/dirent/opendir.c"
#endif

// minilib/src/signal/signal.c
#ifdef mini_signal
#include "minilib/src/signal/signal.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_posix_openpt
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/exec/_execvp.c
#ifdef mini_execvp
#include "minilib/src/exec/_execvp.c"
#endif

// minilib/src/malloc.c
#ifdef mini_realloc
#include "minilib/src/malloc.c"
#endif

// minilib/src/string/strlen.c
#ifdef mini_strlen
#include "minilib/src/string/strlen.c"
#endif

// minilib/src/map_protected.c
#ifdef mini_unmap_protected
#include "minilib/src/map_protected.c"
#endif

// minilib/src/dirent/telldir.c
#ifdef mini_telldir
#include "minilib/src/dirent/telldir.c"
#endif

// minilib/src/die.c
#ifdef mini__die
#include "minilib/src/die.c"
#endif

// minilib/src/signal/sigaction.c
#ifdef mini_sigaction
#include "minilib/src/signal/sigaction.c"
#endif

// minilib/src/brk.c
#ifdef mini_getbrk
#include "minilib/src/brk.c"
#endif

// minilib/src/dirent/opendirp.c
#ifdef mini_opendirp
#include "minilib/src/dirent/opendirp.c"
#endif

// minilib/src/string/strtoll.c
#ifdef mini_strtoll
#include "minilib/src/string/strtoll.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_unlockpt
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/mem/memfrob.c
#ifdef mini_memfrob
#include "minilib/src/mem/memfrob.c"
#endif

// minilib/src/match.c
#ifdef mini__match
#include "minilib/src/match.c"
#endif

// minilib/src/freebrk.c
#ifdef mini_free_brk
#include "minilib/src/freebrk.c"
#endif

// minilib/src/itobin.c
#ifdef mini__itobin
#include "minilib/src/itobin.c"
#endif

// minilib/src/string/strchr.c
#ifdef mini_strchrnul
#include "minilib/src/string/strchr.c"
#endif

// minilib/src/exit_errno.c
#ifdef mini_exit_errno
#include "minilib/src/exit_errno.c"
#endif

// minilib/src/dirent/scandir.c
#ifdef mini_scandir
#include "minilib/src/dirent/scandir.c"
#endif

// minilib/src/match_ext.c
#ifdef mini_match_ext
#include "minilib/src/match_ext.c"
#endif

// minilib/src/dprintf.c
#ifdef mini_dprintf
#include "minilib/src/dprintf.c"
#endif

// minilib/src/cksum.c
#ifdef mini_djb_cksum
#include "minilib/src/cksum.c"
#endif

// minilib/src/exec/execvp.c
#ifdef mini_execvpe
#include "minilib/src/exec/execvp.c"
#endif

// minilib/src/signal/sigaction.c
#ifdef mini_sigismember
#include "minilib/src/signal/sigaction.c"
#endif

// minilib/src/mem/memset.c
#ifdef mini_memset
#include "minilib/src/mem/memset.c"
#endif

// minilib/src/hashes.c
#ifdef mini_sdbm_hash
#include "minilib/src/hashes.c"
#endif

// minilib/src/sprintf.c
#ifdef mini_vsnprintf
#include "minilib/src/sprintf.c"
#endif

// minilib/src/userdb/getpwuid.c
#ifdef mini_getpwuid
#include "minilib/src/userdb/getpwuid.c"
#endif

// minilib/src/itooct.c
#ifdef mini_itooct
#include "minilib/src/itooct.c"
#endif

// minilib/src/cksum.c
#ifdef mini_bsd_cksumblock
#include "minilib/src/cksum.c"
#endif

// minilib/src/brk.c
#ifdef mini_brk
#include "minilib/src/brk.c"
#endif

// minilib/src/die.c
#ifdef mini_dief_if
#include "minilib/src/die.c"
#endif

// minilib/src/dirent/alphasort.c
#ifdef mini_alphasort
#include "minilib/src/dirent/alphasort.c"
#endif

// minilib/src/userdb/initgroups.c
#ifdef mini_initgroups
#include "minilib/src/userdb/initgroups.c"
#endif

// minilib/src/userdb/userdb.c
#ifdef mini_token_s
#include "minilib/src/userdb/userdb.c"
#endif

// minilib/src/string/strcmp.c
#ifdef mini__strcasecmp
#include "minilib/src/string/strcmp.c"
#endif

// minilib/src/userdb/endpwent.c
#ifdef mini_endpwent
#include "minilib/src/userdb/endpwent.c"
#endif

// minilib/src/malloc.c
#ifdef mini_free
#include "minilib/src/malloc.c"
#endif

// minilib/src/cksum.c
#ifdef mini_bsd_cksum
#include "minilib/src/cksum.c"
#endif

// minilib/src/fgetud.c
#ifdef mini_fgetud
#include "minilib/src/fgetud.c"
#endif

// minilib/src/string/strcmp.c
#ifdef mini_strncmp
#include "minilib/src/string/strcmp.c"
#endif

// minilib/src/exec/vexec.c
#ifdef mini_vexec
#include "minilib/src/exec/vexec.c"
#endif

// minilib/src/userdb/endgrent.c
#ifdef mini_endgrent
#include "minilib/src/userdb/endgrent.c"
#endif

// minilib/src/termios/cfmakeraw.c
#ifdef mini_cfmakeraw
#include "minilib/src/termios/cfmakeraw.c"
#endif

// minilib/src/snprintf.c
#ifdef mini_snprintf
#include "minilib/src/snprintf.c"
#endif

// minilib/src/userdb/getusergroups.c
#ifdef mini_getusergroups
#include "minilib/src/userdb/getusergroups.c"
#endif

// minilib/src/fprintfs.c
#ifdef mini_fprintfs
#include "minilib/src/fprintfs.c"
#endif

// minilib/src/mem/mmap.c
#ifdef mini_mmap
#include "minilib/src/mem/mmap.c"
#endif

// minilib/src/die.c
#ifdef mini_dief
#include "minilib/src/die.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_ptsname
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/malloc_brk.c
#ifdef mini_malloc_brk
#include "minilib/src/malloc_brk.c"
#endif

// minilib/src/dirent/seekdir.c
#ifdef mini_seekdir
#include "minilib/src/dirent/seekdir.c"
#endif

// minilib/src/fopen.c
#ifdef mini_freopen
#include "minilib/src/fopen.c"
#endif

// minilib/src/itodec.c
#ifdef mini_uitodec
#include "minilib/src/itodec.c"
#endif

// minilib/src/itohex.c
#ifdef mini__itohex
#include "minilib/src/itohex.c"
#endif

// minilib/src/userdb/userdb.c
#ifdef mini_token_i
#include "minilib/src/userdb/userdb.c"
#endif

// minilib/src/string/strcmp.c
#ifdef mini__strcmp
#include "minilib/src/string/strcmp.c"
#endif

// minilib/src/mem/memcpy.c
#ifdef mini_memcpy
#include "minilib/src/mem/memcpy.c"
#endif

// minilib/src/itohex.c
#ifdef mini_itohex
#include "minilib/src/itohex.c"
#endif

// minilib/src/brk.c
#ifdef mini_setbrk
#include "minilib/src/brk.c"
#endif

// minilib/src/signal/sigaction.c
#ifdef mini_raise
#include "minilib/src/signal/sigaction.c"
#endif

// minilib/src/errno_str.c
#ifdef mini_errno_str
#include "minilib/src/errno_str.c"
#endif

// minilib/src/vsprintf.c
#ifdef mini_vsprintf
#include "minilib/src/vsprintf.c"
#endif

// minilib/src/string/strcmp.c
#ifdef mini_strncasecmp
#include "minilib/src/string/strcmp.c"
#endif

#endif
