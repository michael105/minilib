#ifndef	_mlsys_stat_h
#define	_mlsys_stat_h
#ifdef __cplusplus
extern "C" {
#endif


#include "../bits/alltypes.h"


#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif


//#include <features.h>
/* copied from kernel definition, but with padding replaced
 * by the corresponding correctly-sized userspace types. */

//#ifndef stat_defined
//#define stat_defined
#if 0
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

	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	long __unused[3];
};
#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec


#endif


#define S_TYPEISMQ(buf)  0
#define S_TYPEISSEM(buf) 0
#define S_TYPEISSHM(buf) 0
#define S_TYPEISTMO(buf) 0

#define UTIME_NOW  0x3fffffff
#define UTIME_OMIT 0x3ffffffe

/*
int stat(const char *__restrict, struct stat *__restrict);
int fstat(int, struct stat *);
int lstat(const char *__restrict, struct stat *__restrict);
int fstatat(int, const char *__restrict, struct stat *__restrict, int);
int chmod(const char *, mode_t);
int fchmod(int, mode_t);
int fchmodat(int, const char *, mode_t, int);
mode_t umask(mode_t);
int mkdir(const char *, mode_t);
int mkfifo(const char *, mode_t);
int mkdirat(int, const char *, mode_t);
int mkfifoat(int, const char *, mode_t);

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
int mknod(const char *, mode_t, dev_t);
int mknodat(int, const char *, mode_t, dev_t);
#endif

int futimens(int, const struct timespec [2]);
int utimensat(int, const char *, const struct timespec [2], int);
*/
#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
//int lchmod(const char *, mode_t);
//#define S_IREAD S_IRUSR
//#define S_IWRITE S_IWUSR
//#define S_IEXEC S_IXUSR
#endif

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define stat64 stat
#define fstat64 fstat
#define lstat64 lstat
#define fstatat64 fstatat
#define blkcnt64_t blkcnt_t
#define fsblkcnt64_t fsblkcnt_t
#define fsfilcnt64_t fsfilcnt_t
#define ino64_t ino_t
#define off64_t off_t
#endif

#ifdef __cplusplus
}
#endif
#endif


