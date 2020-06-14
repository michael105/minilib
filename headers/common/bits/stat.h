#ifndef __bits_stat_h
#define __bits_stat_h


#define S_IFMT  0170000


/* File types.  */
#define	S_IFDIR	0040000	/* Directory.  */
#define	S_IFCHR	0020000	/* Character device.  */
#define	S_IFBLK	0060000	/* Block device.  */
#define	S_IFREG	0100000	/* Regular file.  */
#define	S_IFIFO	0010000	/* FIFO.  */
#define	S_IFLNK	0120000	/* Symbolic link.  */
#define	S_IFSOCK 0140000	/* Socket.  */

/* Protection bits.  */
#define	S_ISUID	04000	/* Set user ID on execution.  */
#define	S_ISGID	02000	/* Set group ID on execution.  */
#define	S_ISVTX	01000	/* Save swapped text after use (sticky).  */
#define	S_IREAD	0400	/* Read by owner.  */
#define	S_IWRITE 0200	/* Write by owner.  */
#define	S_IEXEC	0100	/* Execute by owner.  */


#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#define S_ISCHR(mode)  (((mode) & S_IFMT) == S_IFCHR)
#define S_ISBLK(mode)  (((mode) & S_IFMT) == S_IFBLK)
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#define S_ISFIFO(mode) (((mode) & S_IFMT) == S_IFIFO)
#define S_ISLNK(mode)  (((mode) & S_IFMT) == S_IFLNK)
#define S_ISSOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)


#define S_ISUID 04000
#define S_ISGID 02000
#define S_ISVTX 01000
#define S_IRUSR 0400
#define S_IWUSR 0200
#define S_IXUSR 0100
#define S_IRWXU 0700
#define S_IRGRP 0040
#define S_IWGRP 0020
#define S_IXGRP 0010
#define S_IRWXG 0070
#define S_IROTH 0004
#define S_IWOTH 0002
#define S_IXOTH 0001
#define S_IRWXO 0007



#ifdef X64

struct stat {
		dev_t st_dev;
		ino_t st_ino;
		nlink_t st_nlink;

		mode_t st_mode;
		uid_t st_uid;
		gid_t st_gid;
		unsigned int    __pad0;
		dev_t st_rdev;
		off_t st_size;
		blksize_t st_blksize;
		blkcnt_t st_blocks;

		struct timespec st_atime;
		struct timespec st_mtime;
		struct timespec st_ctime;
		long __unused[3];
};
#else

#endif
#endif
