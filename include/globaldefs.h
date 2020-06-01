#ifndef globaldefs_h
#define globaldefs_h

// definitions

#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER unsigned int
#endif

#ifndef uint32_t
#define uint32_t uint
#endif

#ifndef uint8_t
#define uint8_t uchar
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

#define BUFSIZ 1024


//+def
typedef int FILE;

#define FEOF_FLAG 0x80000000
#define ERR_FLAG 0x40000000
#define FLAG_MASK 0xc0000000
#define FD_MASK 0x3fffffff

#ifdef X64
typedef union { FILE *F; int i, fd;} mfl_union;
#else
//typedef union { FILE *F; int fd;} mfl_union;
#error checkme
#endif
//(untested for x32) better commenting this out for now.
//Might be better to find later
//also: endiannes.

#define EOF (-1)

#ifdef mini_buf
#ifndef stdin
#define stdin &ml.stream[0]
#endif
#ifndef stdout
#define stdout &ml.stream[1]
#endif
#ifndef stderr
#define stderr &ml.stream[2]
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

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#endif

#include <bits/alltypes.h>
#include <bits/ioctl.h>
#include <sys/utsname.h>
#include <sys/termios.h>

typedef void (*sighandler_t)(int);

#ifdef mini_ioctl
int ioctl( int fd, unsigned long int request, ... );
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



#endif
