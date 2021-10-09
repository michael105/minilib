#ifndef linux_fcntl_h
#define linux_fcntl_h

// (source: linux kernel) SPDX


/*
 *  * Types of directory notifications that may be requested.
 *   */
#define DN_ACCESS 0x00000001  /* File accessed */
#define DN_MODIFY 0x00000002  /* File modified */
#define DN_CREATE 0x00000004  /* File created */
#define DN_DELETE 0x00000008  /* File removed */
#define DN_RENAME 0x00000010  /* File renamed */
#define DN_ATTRIB 0x00000020  /* File changed attibutes */
#define DN_MULTISHOT  0x80000000  /* Don't remove notifier */

#define AT_FDCWD    -100    /* Special value used to indicate openat should use the current working directory. */
#define AT_SYMLINK_NOFOLLOW 0x100   /* Do not follow symbolic links.  */
#define AT_REMOVEDIR    0x200   /* Remove directory instead of unlinking file.  */
#define AT_SYMLINK_FOLLOW 0x400   /* Follow symbolic links.  */
#define AT_NO_AUTOMOUNT   0x800 /* Suppress terminal automount traversal */
#define AT_EMPTY_PATH   0x1000  /* Allow empty relative pathname */

#define AT_STATX_SYNC_TYPE  0x6000  /* Type of synchronisation required from statx()*/
#define AT_STATX_SYNC_AS_STAT 0x0000  /* - Do whatever stat() does */
#define AT_STATX_FORCE_SYNC 0x2000  /* - Force the attributes to be sync'd with the server */
#define AT_STATX_DONT_SYNC  0x4000  /* - Don't sync attributes with the server */

#define AT_RECURSIVE    0x8000  /* Apply to the entire subtree */


#define FD_CLOEXEC	1	/* actually anything with low bit set goes */


#endif
