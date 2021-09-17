/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_minilib_c
#define included_minilib_c

/* templates/minilib.c.in */

#ifndef included_minilib_h
//#include "minilib.h"
#endif

#include "minilib/asm/start.c"
#include "minilib/src/intern/minilib_global.c"

#ifdef mini_prints
#include "minilib/src/output/dprints.c"
#endif

#ifdef mini_errno
#ifndef mini_globals_on_stack
int errno;
#endif
int sysret;
#endif

#ifdef mini_getopt
#include "contrib/getopt/getopt.h"
#endif

#include "src/intern/startup.c"

/* end templates/minilib.c.in */
/* templates/minilib.c.in */

#ifndef included_minilib_h
//#include "minilib.h"
#endif

#include "minilib/asm/start.c"
#include "minilib/src/intern/minilib_global.c"

#ifdef mini_prints
#include "minilib/src/output/dprints.c"
#endif

#ifdef mini_errno
#ifndef mini_globals_on_stack
int errno;
#endif
int sysret;
#endif

#ifdef mini_getopt
#include "contrib/getopt/getopt.h"
#endif

#include "src/intern/startup.c"

/* end templates/minilib.c.in */

// minilib/src/memory/malloc.c
#ifdef include_minilib_src_memory_malloc_c
#include "minilib/src/memory/malloc.c"
#endif

// minilib/src/string/strcmp.c
#ifdef include_minilib_src_string_strcmp_c
#include "minilib/src/string/strcmp.c"
#endif

// minilib/src/process/wait.c
#ifdef include_minilib_src_process_wait_c
#include "minilib/src/process/wait.c"
#endif

// minilib/src/userdb/userdb.c
#ifdef include_minilib_src_userdb_userdb_c
#include "minilib/src/userdb/userdb.c"
#endif

// minilib/src/process/sleep.c
#ifdef include_minilib_src_process_sleep_c
#include "minilib/src/process/sleep.c"
#endif

// minilib/src/conversions/itohex.c
#ifdef include_minilib_src_conversions_itohex_c
#include "minilib/src/conversions/itohex.c"
#endif

// minilib/src/conversions/ltodec.c
#ifdef include_minilib_src_conversions_ltodec_c
#include "minilib/src/conversions/ltodec.c"
#endif

// minilib/src/file/open.c
#ifdef include_minilib_src_file_open_c
#include "minilib/src/file/open.c"
#endif

// minilib/src/process/sigaction.c
#ifdef include_minilib_src_process_sigaction_c
#include "minilib/src/process/sigaction.c"
#endif

// minilib/src/output/sprintf.c
#ifdef include_minilib_src_output_sprintf_c
#include "minilib/src/output/sprintf.c"
#endif

// minilib/src/termios/isatty.c
#ifdef include_minilib_src_termios_isatty_c
#include "minilib/src/termios/isatty.c"
#endif

// minilib/src/streams/fopen.c
#ifdef include_minilib_src_streams_fopen_c
#include "minilib/src/streams/fopen.c"
#endif

// minilib/src/exec/vexec.c
#ifdef mini_vexec
#include "minilib/src/exec/vexec.c"
#endif

// minilib/src/termios/cfmakeraw.c
#ifdef mini_cfmakeraw
#include "minilib/src/termios/cfmakeraw.c"
#endif

// minilib/src/network/gethostname.c
#ifdef mini_gethostname
#include "minilib/src/network/gethostname.c"
#endif

// minilib/src/memory/memcmp.c
#ifdef mini_memcmp
#include "minilib/src/memory/memcmp.c"
#endif

// minilib/src/process/abort.c
#ifdef mini_abort
#include "minilib/src/process/abort.c"
#endif

// minilib/src/process/clone.c
#ifdef mini_clone_t
#include "minilib/src/process/clone.c"
#endif

// minilib/src/directories/scandir.c
#ifdef mini_scandir
#include "minilib/src/directories/scandir.c"
#endif

// minilib/src/process/die.c
#ifdef mini_dies_if
#include "minilib/src/process/die.c"
#endif

// minilib/src/process/errno_str.c
#ifdef mini_errno_str
#include "minilib/src/process/errno_str.c"
#endif

// minilib/src/conversions/itodec.c
#ifdef mini_itodec
#include "minilib/src/conversions/itodec.c"
#endif

// minilib/src/conversions/itobin.c
#ifdef mini_itobin
#include "minilib/src/conversions/itobin.c"
#endif

// minilib/src/network/htons.c
#ifdef mini_htons
#include "minilib/src/network/htons.c"
#endif

// minilib/src/streams/fgetc.c
#ifdef mini_fgetc
#include "minilib/src/streams/fgetc.c"
#endif

// minilib/src/string/strcat.c
#ifdef mini_strcat
#include "minilib/src/string/strcat.c"
#endif

// minilib/src/output/snprintf.c
#ifdef mini_snprintf
#include "minilib/src/output/snprintf.c"
#endif

// minilib/src/termios/tcgetattr.c
#ifdef mini_tcgetattr
#include "minilib/src/termios/tcgetattr.c"
#endif

// minilib/src/userdb/getgroups.c
#ifdef mini_getgroups
#include "minilib/src/userdb/getgroups.c"
#endif

// minilib/src/conversions/itooct.c
#ifdef mini_itooct
#include "minilib/src/conversions/itooct.c"
#endif

// minilib/src/streams/fgetud.c
#ifdef mini_fgetud
#include "minilib/src/streams/fgetud.c"
#endif

// minilib/src/match/match_ext2.c
#ifdef mini_match_ext2
#include "minilib/src/match/match_ext2.c"
#endif

// minilib/src/output/vsprintf.c
#ifdef mini_vsprintf
#include "minilib/src/output/vsprintf.c"
#endif

// minilib/src/userdb/getpwent.c
#ifdef mini_getpwent
#include "minilib/src/userdb/getpwent.c"
#endif

// minilib/src/userdb/getgrouplist.c
#ifdef mini_getgrouplist
#include "minilib/src/userdb/getgrouplist.c"
#endif

// minilib/src/file/cksum.c
#ifdef mini_djb_cksum
#include "minilib/src/file/cksum.c"
#endif

// minilib/src/match/match_ext.c
#ifdef mini_match_ext
#include "minilib/src/match/match_ext.c"
#endif

// minilib/src/termios/term_width.c
#ifdef mini_term_width
#include "minilib/src/termios/term_width.c"
#endif

// minilib/src/process/error.c
#ifdef mini_error
#include "minilib/src/process/error.c"
#endif

// minilib/src/string/strdup.c
#ifdef mini_strdup
#include "minilib/src/string/strdup.c"
#endif

// minilib/src/string/stpcpy.c
#ifdef mini_stpcpy
#include "minilib/src/string/stpcpy.c"
#endif

// minilib/src/directories/rewinddir.c
#ifdef mini_rewinddir
#include "minilib/src/directories/rewinddir.c"
#endif

// minilib/src/userdb/endgrent.c
#ifdef mini_endgrent
#include "minilib/src/userdb/endgrent.c"
#endif

// minilib/src/string/strerror.c
#ifdef mini_strerror
#include "minilib/src/string/strerror.c"
#endif

// minilib/src/userdb/getgrgid.c
#ifdef mini_getgrgid
#include "minilib/src/userdb/getgrgid.c"
#endif

// minilib/src/memory/memcpy.c
#ifdef mini_memcpy
#include "minilib/src/memory/memcpy.c"
#endif

// minilib/src/directories/dirname.c
#ifdef mini_dirname
#include "minilib/src/directories/dirname.c"
#endif

// minilib/src/streams/fgets.c
#ifdef mini_fgets
#include "minilib/src/streams/fgets.c"
#endif

// minilib/src/string/stplcpy.c
#ifdef mini_stplcpy
#include "minilib/src/string/stplcpy.c"
#endif

// minilib/src/process/die.c
#ifdef mini_dief_if
#include "minilib/src/process/die.c"
#endif

// minilib/src/string/strchrnul.c
#ifdef mini_strchrnul
#include "minilib/src/string/strchrnul.c"
#endif

// minilib/src/directories/dirfd.c
#ifdef mini_dirfd
#include "minilib/src/directories/dirfd.c"
#endif

// minilib/src/conversions/itobin.c
#ifdef mini__itobin
#include "minilib/src/conversions/itobin.c"
#endif

// minilib/src/conversions/dtodec.c
#ifdef mini_dtodec
#include "minilib/src/conversions/dtodec.c"
#endif

// minilib/src/string/stpncpy.c
#ifdef mini_stpncpy
#include "minilib/src/string/stpncpy.c"
#endif

// minilib/src/memory/calloc.c
#ifdef mini_calloc
#include "minilib/src/memory/calloc.c"
#endif

// minilib/src/process/exit_errno.c
#ifdef mini_exit_errno
#include "minilib/src/process/exit_errno.c"
#endif

// minilib/src/process/error.c
#ifdef mini_warn
#include "minilib/src/process/error.c"
#endif

// minilib/src/userdb/setpwent.c
#ifdef mini_setpwent
#include "minilib/src/userdb/setpwent.c"
#endif

// minilib/src/system/putenv.c
#ifdef mini_putenv
#include "minilib/src/system/putenv.c"
#endif

// minilib/src/process/die.c
#ifdef mini_dief
#include "minilib/src/process/die.c"
#endif

// minilib/src/directories/alphasort.c
#ifdef mini_alphasort
#include "minilib/src/directories/alphasort.c"
#endif

// minilib/src/memory/freebrk.c
#ifdef mini_free_brk
#include "minilib/src/memory/freebrk.c"
#endif

// minilib/src/exec/_execvp.c
#ifdef mini_execvp
#include "minilib/src/exec/_execvp.c"
#endif

// minilib/src/directories/closedir.c
#ifdef mini_closedir
#include "minilib/src/directories/closedir.c"
#endif

// minilib/src/streams/gets.c
#ifdef mini_gets
#include "minilib/src/streams/gets.c"
#endif

// minilib/src/output/fprintfs.c
#ifdef mini_fprintfs
#include "minilib/src/output/fprintfs.c"
#endif

// minilib/src/network/htonl.c
#ifdef mini_htonl
#include "minilib/src/network/htonl.c"
#endif

// minilib/src/match/match.c
#ifdef mini__match
#include "minilib/src/match/match.c"
#endif

// minilib/src/process/die.c
#ifdef mini__die
#include "minilib/src/process/die.c"
#endif

// minilib/src/directories/opendirp.c
#ifdef mini_opendirp
#include "minilib/src/directories/opendirp.c"
#endif

// minilib/src/userdb/getpwnam.c
#ifdef mini_getpwnam
#include "minilib/src/userdb/getpwnam.c"
#endif

// minilib/src/string/strstr.c
#ifdef mini_strstr
#include "minilib/src/string/strstr.c"
#endif

// minilib/src/directories/scandir_bufsize.c
#ifdef mini_scandir_bufsize
#include "minilib/src/directories/scandir_bufsize.c"
#endif

// minilib/src/exec/where.c
#ifdef mini_where
#include "minilib/src/exec/where.c"
#endif

// minilib/src/directories/readdir.c
#ifdef mini_readdir
#include "minilib/src/directories/readdir.c"
#endif

// minilib/src/match/match.c
#ifdef mini_match
#include "minilib/src/match/match.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_ptsname
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/termios/tcsetattr.c
#ifdef mini_tcsetattr
#include "minilib/src/termios/tcsetattr.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_grantpt
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/network/htonl.c
#ifdef mini_ntohl
#include "minilib/src/network/htonl.c"
#endif

// minilib/src/memory/memset.c
#ifdef mini_memset
#include "minilib/src/memory/memset.c"
#endif

// minilib/src/process/error.c
#ifdef mini_err
#include "minilib/src/process/error.c"
#endif

// minilib/src/output/dprints.c
#ifdef mini_dprints
#include "minilib/src/output/dprints.c"
#endif

// minilib/src/sort/qsort.c
#ifdef mini_qsort
#include "minilib/src/sort/qsort.c"
#endif

// minilib/src/process/die.c
#ifdef mini_die
#include "minilib/src/process/die.c"
#endif

// minilib/src/process/die.c
#ifdef mini_dies
#include "minilib/src/process/die.c"
#endif

// minilib/src/string/strlen.c
#ifdef mini_strlen
#include "minilib/src/string/strlen.c"
#endif

// minilib/src/exec/execl.c
#ifdef mini_execl
#include "minilib/src/exec/execl.c"
#endif

// minilib/src/userdb/endpwent.c
#ifdef mini_endpwent
#include "minilib/src/userdb/endpwent.c"
#endif

// minilib/src/memory/getbrk.c
#ifdef mini_getbrk
#include "minilib/src/memory/getbrk.c"
#endif

// minilib/src/directories/opendir.c
#ifdef mini_opendir
#include "minilib/src/directories/opendir.c"
#endif

// minilib/src/process/signal.c
#ifdef mini_signal
#include "minilib/src/process/signal.c"
#endif

// minilib/src/math/rand.c
#ifdef mini_rand
#include "minilib/src/math/rand.c"
#endif

// minilib/src/exec/_execv.c
#ifdef mini_execv
#include "minilib/src/exec/_execv.c"
#endif

// minilib/src/system/getenv.c
#ifdef mini_getenv
#include "minilib/src/system/getenv.c"
#endif

// minilib/src/userdb/getgrent.c
#ifdef mini_getgrent
#include "minilib/src/userdb/getgrent.c"
#endif

// minilib/src/file/cksum.c
#ifdef mini_bsd_cksumblock
#include "minilib/src/file/cksum.c"
#endif

// minilib/src/memory/memmove.c
#ifdef mini_memmove
#include "minilib/src/memory/memmove.c"
#endif

// minilib/src/match/match_ext2.c
#ifdef mini__match_ext2
#include "minilib/src/match/match_ext2.c"
#endif

// minilib/src/math/sdbm_hash.c
#ifdef mini_sdbm_hash
#include "minilib/src/math/sdbm_hash.c"
#endif

// minilib/src/memory/sbrk.c
#ifdef mini_sbrk
#include "minilib/src/memory/sbrk.c"
#endif

// minilib/src/memory/map_protected.c
#ifdef mini_unmap_protected
#include "minilib/src/memory/map_protected.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_posix_openpt
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/output/fprintf.c
#ifdef mini_fprintf
#include "minilib/src/output/fprintf.c"
#endif

// minilib/src/process/die.c
#ifdef mini_die_if
#include "minilib/src/process/die.c"
#endif

// minilib/src/system/ioctl.c
#ifdef mini_ioctl
#include "minilib/src/system/ioctl.c"
#endif

// minilib/src/exec/vexec_q.c
#ifdef mini_vexec_q
#include "minilib/src/exec/vexec_q.c"
#endif

// minilib/src/userdb/initgroups.c
#ifdef mini_initgroups
#include "minilib/src/userdb/initgroups.c"
#endif

// minilib/src/string/strtoll.c
#ifdef mini_strtoll
#include "minilib/src/string/strtoll.c"
#endif

// minilib/src/memory/memfrob.c
#ifdef mini_memfrob
#include "minilib/src/memory/memfrob.c"
#endif

// minilib/src/memory/map_protected.c
#ifdef mini_map_protected
#include "minilib/src/memory/map_protected.c"
#endif

// minilib/src/memory/malloc_brk.c
#ifdef mini_malloc_brk
#include "minilib/src/memory/malloc_brk.c"
#endif

// minilib/src/userdb/getpwuid.c
#ifdef mini_getpwuid
#include "minilib/src/userdb/getpwuid.c"
#endif

// minilib/src/output/perror.c
#ifdef mini_perror
#include "minilib/src/output/perror.c"
#endif

// minilib/src/streams/fgetul.c
#ifdef mini_fgetul
#include "minilib/src/streams/fgetul.c"
#endif

// minilib/src/process/atexit.c
#ifdef mini_atexit
#include "minilib/src/process/atexit.c"
#endif

// minilib/src/string/strncpy.c
#ifdef mini_strncpy
#include "minilib/src/string/strncpy.c"
#endif

// minilib/src/math/rand.c
#ifdef mini_srand
#include "minilib/src/math/rand.c"
#endif

// minilib/src/userdb/userdb_open.c
#ifdef mini_userdb_open
#include "minilib/src/userdb/userdb_open.c"
#endif

// minilib/src/streams/ungetc.c
#ifdef mini_ungetc
#include "minilib/src/streams/ungetc.c"
#endif

// minilib/src/string/strpbrk.c
#ifdef mini_strpbrk
#include "minilib/src/string/strpbrk.c"
#endif

// minilib/src/exec/execvp.c
#ifdef mini_execvpe
#include "minilib/src/exec/execvp.c"
#endif

// minilib/src/output/vsnprintf.c
#ifdef mini_vsnprintf
#include "minilib/src/output/vsnprintf.c"
#endif

// minilib/src/output/dprintf.c
#ifdef mini_dprintf
#include "minilib/src/output/dprintf.c"
#endif

// minilib/src/network/inet_ntoa.c
#ifdef mini_inet_ntoa
#include "minilib/src/network/inet_ntoa.c"
#endif

// minilib/src/userdb/getusergroups.c
#ifdef mini_getusergroups
#include "minilib/src/userdb/getusergroups.c"
#endif

// minilib/src/userdb/getgrnam.c
#ifdef mini_getgrnam
#include "minilib/src/userdb/getgrnam.c"
#endif

// minilib/src/conversions/atol.c
#ifdef mini_atol
#include "minilib/src/conversions/atol.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_unlockpt
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/string/strlcpy.c
#ifdef mini_strlcpy
#include "minilib/src/string/strlcpy.c"
#endif

// minilib/src/sort/swap.c
#ifdef mini_swap
#include "minilib/src/sort/swap.c"
#endif

// minilib/src/termios/pty.c
#ifdef mini_ptsname_r
#include "minilib/src/termios/pty.c"
#endif

// minilib/src/string/strcpy.c
#ifdef mini_strcpy
#include "minilib/src/string/strcpy.c"
#endif

// minilib/src/memory/mmap.c
#ifdef mini_mmap
#include "minilib/src/memory/mmap.c"
#endif

// minilib/src/string/strtol.c
#ifdef mini_strtol
#include "minilib/src/string/strtol.c"
#endif

// minilib/src/process/error.c
#ifdef mini_errx
#include "minilib/src/process/error.c"
#endif

// minilib/src/exec/system.c
#ifdef mini_system
#include "minilib/src/exec/system.c"
#endif

// minilib/src/string/strrchr.c
#ifdef mini_strrchr
#include "minilib/src/string/strrchr.c"
#endif

// minilib/src/directories/telldir.c
#ifdef mini_telldir
#include "minilib/src/directories/telldir.c"
#endif

// minilib/src/memory/sys_brk.c
#ifdef mini_sys_brk
#include "minilib/src/memory/sys_brk.c"
#endif

// minilib/src/memory/brk.c
#ifdef mini_brk
#include "minilib/src/memory/brk.c"
#endif

// minilib/src/network/inet_aton.c
#ifdef mini_inet_aton
#include "minilib/src/network/inet_aton.c"
#endif

// minilib/src/output/snprintfs.c
#ifdef mini_snprintfs
#include "minilib/src/output/snprintfs.c"
#endif

// minilib/src/math/hashes.c
#ifdef mini_djb2_hash
#include "minilib/src/math/hashes.c"
#endif

// minilib/src/memory/setbrk.c
#ifdef mini_setbrk
#include "minilib/src/memory/setbrk.c"
#endif

// minilib/src/directories/seekdir.c
#ifdef mini_seekdir
#include "minilib/src/directories/seekdir.c"
#endif

// minilib/src/system/setenv.c
#ifdef mini_setenv
#include "minilib/src/system/setenv.c"
#endif

// minilib/src/userdb/setgrent.c
#ifdef mini_setgrent
#include "minilib/src/userdb/setgrent.c"
#endif

// minilib/src/string/strchr.c
#ifdef mini_strchr
#include "minilib/src/string/strchr.c"
#endif

// minilib/src/streams/fgetsp.c
#ifdef mini_fgetsp
#include "minilib/src/streams/fgetsp.c"
#endif

// minilib/src/file/cksum.c
#ifdef mini_bsd_cksum
#include "minilib/src/file/cksum.c"
#endif

// minilib/src/conversions/atoi.c
#ifdef mini_atoi
#include "minilib/src/conversions/atoi.c"
#endif

// minilib/src/conversions/itodec.c
#ifdef mini_uitodec
#include "minilib/src/conversions/itodec.c"
#endif

// minilib/src/streams/fgetsn.c
#ifdef mini_fgetsn
#include "minilib/src/streams/fgetsn.c"
#endif

// minilib/src/streams/_fopen.c
#ifdef mini__fopen
#include "minilib/src/streams/_fopen.c"
#endif

// minilib/src/directories/basename.c
#ifdef mini_basename
#include "minilib/src/directories/basename.c"
#endif

#endif

#endif
