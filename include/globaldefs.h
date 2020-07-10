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

#ifdef mini_ioctl
//int ioctl( int fd, unsigned long int request, ... );
#endif


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




#endif
