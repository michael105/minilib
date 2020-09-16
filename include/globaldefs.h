#ifndef globaldefs_h
#define globaldefs_h

// definitions

#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER unsigned int
#endif

#ifndef uint32_t
#define uint32_t unsigned int
#endif

#ifndef uint8_t
#define uint8_t unsigned char
#endif

#ifndef size_t
#define size_t long
#endif

#define PATH_MAX 4096

#define FOPEN_MAX 16

#ifndef SEEK_SET
#define SEEK_SET        0       /* seek relative to beginning of file */
#define SEEK_CUR        1       /* seek relative to current file position */
#define SEEK_END        2       /* seek relative to end of file */
#define SEEK_MAX        SEEK_END
#endif

#ifndef ENOENT
#define ENOENT           2
#endif

#define SIG_BLOCK     0
#define SIG_UNBLOCK   1
#define SIG_SETMASK   2

#define RE_NOMATCH 0
#define RE_ERROR 0
#define RE_MATCH 1
#define RE_MATCHEND -1

typedef struct _regex_match { char *pos; int len; } regex_match;

#define mini_FOPEN_MAX 16

#ifndef NULL
#define NULL 0
#endif
#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif

struct utimbuf{
		time_t actime;    /* Access time.  */
		time_t modtime;   /* Modification time.  */
};

#define AT_STATX_SYNC_AS_STAT 0x0000
#define AT_NO_AUTOMOUNT 0x800
#define AT_EMPTY_PATH 0x1000
#define AT_STATX_SYNC_TYPE 0x6000
#define AT_STATX_FORCE_SYNC 0x2000
#define AT_STATX_DONT_SYNC 0x4000
#define AT_RECURSIVE 0x8000


#define BUFSIZ 1024


//+def
typedef int FILE;

#if 0
// thats the old masks/flags.
// possibly better change the fd/FILE len to long
// not sure about that.
// but the hard kernel limit on open fd's is
// about 17 bits here. so. might be ok.
// feeling a bit uncomfortable with that decision,
// however.
#define FEOF_FLAG 0x80000000
#define ERR_FLAG 0x40000000
#define FLAG_MASK 0xc0000000
#define FD_MASK 0x3fffffff
#else

#define FEOF_FLAG 0x800000
#define ERR_FLAG 0x400000
#define FLAG_MASK 0xc00000
#define FD_MASK 0x3fffff
#define UNGETC_MASK 0xff000000

#endif

#ifdef X64
typedef union { FILE *F; int i, fd;} mfl_union;
#else
//typedef union { FILE *F; int fd;} mfl_union;
#warning checkme
#warning typedef union { FILE *F; int fd;} mfl_union;
#endif
//(untested for x32) better commenting this out for now.
//Might be better to find later
//also: endiannes. problem: ungetc. (in fgetc.h)

#define EOF (-1)

#ifdef mini_buf
#ifndef stdin
#define stdin &mlgl->stream[0]
#endif
#ifndef stdout
#define stdout &mlgl->stream[1]
#endif
#ifndef stderr
#define stderr &mlgl->stream[2]
#endif
#else 
// no minibuf -> no stream descriptors.
#ifndef stdin
#define stdin (int*)0
#endif
#ifndef stdout
#define stdout (int*)1
#endif
#ifndef stderr
#define stderr (int*)2
#endif
#endif

// TODO: ifdef mini_buf -> get mlgl->stream->fd
#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#endif

#include <bits/alltypes.h>
#include <bits/ioctl.h>
#include <sys/utsname.h>
#include <sys/termios.h>

typedef struct { int quot; int rem; } div_t;
typedef struct { long int quot; long int rem; } ldiv_t;

typedef void (*sighandler_t)(int);

typedef void (functionp)(void);
#ifdef mini_atexit
#if (mini_atexit>0)
#define ATEXIT_MAX mini_atexit
#else
#define ATEXIT_MAX 8
#endif
#endif

#ifdef mini_ioctl
//int ioctl( int fd, unsigned long int request, ... );
#endif

// the current implementation of malloc has this max,
// equal to 256MB
// so better keep it save.
// todo: reimplement malloc to 64bit
#define SIZE_MAX 0xfffffff


#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timezone {
		int     tz_minuteswest; /*	minutes	west of	Greenwich */
		int     tz_dsttime;     /*	type of	dst correction */
};
#endif


// from musl
#define FD_SETSIZE 1024

		typedef unsigned long fd_mask;

		typedef struct
		{
				  unsigned long fds_bits[FD_SETSIZE / 8 / sizeof(long)];
		} fd_set;

// switch pwent
//+def pwent

typedef struct passwd {
	char   *pw_name;       /* username */
	char   *pw_passwd;     /* user password */
	uid_t   pw_uid;        /* user ID */
	gid_t   pw_gid;        /* group ID */
	char   *pw_gecos;      /* user information */
	char   *pw_dir;        /* home directory */
	char   *pw_shell;      /* shell program */
} _passwd;

#define PASSWDFILE "/etc/passwd"

typedef struct group {
	char   *gr_name;        /* group name */
	char   *gr_passwd;      /* group password */
	gid_t   gr_gid;         /* group ID */
	char  **gr_mem;         /* NULL-terminated array of pointers
														 to names of group members */
}_group;

#define GROUPFILE "/etc/group"

#define FD_ZERO(s) do { int __i; unsigned long *__b=(s)->fds_bits; for(__i=sizeof (fd_set)/sizeof (long); __i; __i--) *__b++=0; } while(0)
#define FD_SET(d, s)   ((s)->fds_bits[(d)/(8*sizeof(long))] |= (1UL<<((d)%(8*sizeof(long)))))
#define FD_CLR(d, s)   ((s)->fds_bits[(d)/(8*sizeof(long))] &= ~(1UL<<((d)%(8*sizeof(long)))))
#define FD_ISSET(d, s) !!((s)->fds_bits[(d)/(8*sizeof(long))] & (1UL<<((d)%(8*sizeof(long)))))

// end of musl 

#define LOGIN_NAME_MAX 256
#define HOST_NAME_MAX 64

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define F_OK 0
#define X_OK 1
#define W_OK 2
#define R_OK 4


#define WNOHANG    1
#define WUNTRACED  2

#define WSTOPPED   2
#define WEXITED    4
#define WCONTINUED 8
#define WNOWAIT    0x1000000


#define WEXITSTATUS(s) (((s) & 0xff00) >> 8)
#define WTERMSIG(s) ((s) & 0x7f)
#define WSTOPSIG(s) WEXITSTATUS(s)
#define WCOREDUMP(s) ((s) & 0x80)
#define WIFEXITED(s) (!WTERMSIG(s))
#define WIFSTOPPED(s) ((short)((((s)&0xffff)*0x10001)>>8) > 0x7f00)
#define WIFSIGNALED(s) (((s)&0xffff)-1U < 0xffu)
#define WIFCONTINUED(s) ((s) == 0xffff)


#define MAP_FAILED ((void *) -1)
#define MAP_FILE       0
#define MAP_SHARED     0x01
#define MAP_PRIVATE    0x02
#define MAP_SHARED_VALIDATE 0x03
#define MAP_TYPE       0x0f
#define MAP_FIXED      0x10
#define MAP_ANON       0x20
#define MAP_ANONYMOUS  MAP_ANON
#define MAP_NORESERVE  0x4000
#define MAP_GROWSDOWN  0x0100
#define MAP_DENYWRITE  0x0800
#define MAP_EXECUTABLE 0x1000
#define MAP_LOCKED     0x2000
#define MAP_POPULATE   0x8000
#define MAP_NONBLOCK   0x10000
#define MAP_STACK      0x20000
#define MAP_HUGETLB    0x40000
#define MAP_SYNC       0x80000
#define MAP_FIXED_NOREPLACE 0x100000

#define PROT_NONE      0
#define PROT_READ      1
#define PROT_WRITE     2
#define PROT_EXEC      4
#define PROT_GROWSDOWN 0x01000000
#define PROT_GROWSUP   0x02000000

#define MREMAP_MAYMOVE 1
#define MREMAP_FIXED 2


#define CLONE_VM  0x00000100
#define CLONE_FS  0x00000200
#define CLONE_FILES 0x00000400
#define CLONE_SIGHAND 0x00000800
#define CLONE_PTRACE  0x00002000
#define CLONE_VFORK 0x00004000
#define CLONE_PARENT  0x00008000
#define CLONE_THREAD  0x00010000
#define CLONE_NEWNS 0x00020000
#define CLONE_SYSVSEM 0x00040000
#define CLONE_SETTLS  0x00080000
#define CLONE_PARENT_SETTID 0x00100000
#define CLONE_CHILD_CLEARTID  0x00200000
#define CLONE_DETACHED  0x00400000
#define CLONE_UNTRACED  0x00800000
#define CLONE_CHILD_SETTID  0x01000000
#define CLONE_NEWCGROUP 0x02000000
#define CLONE_NEWUTS  0x04000000
#define CLONE_NEWIPC  0x08000000
#define CLONE_NEWUSER 0x10000000
#define CLONE_NEWPID  0x20000000
#define CLONE_NEWNET  0x40000000
#define CLONE_IO  0x80000000




#endif
