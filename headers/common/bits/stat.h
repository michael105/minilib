/* File types.  */
#define	S_IFDIR	0040000	/* Directory.  */
#define	S_IFCHR	0020000	/* Character device.  */
#define	S_IFBLK	0060000	/* Block device.  */
#define	S_IFREG	0100000	/* Regular file.  */
#define	S_IFIFO	0010000	/* FIFO.  */
#define	S_IFLNK	0120000	/* Symbolic link.  */
#define	S_IFSOCK	0140000	/* Socket.  */

/* Protection bits.  */
#define	S_ISUID	04000	/* Set user ID on execution.  */
#define	S_ISGID	02000	/* Set group ID on execution.  */
#define	S_ISVTX	01000	/* Save swapped text after use (sticky).  */
#define	S_IREAD	0400	/* Read by owner.  */
#define	S_IWRITE	0200	/* Write by owner.  */
#define	S_IEXEC	0100	/* Execute by owner.  */

