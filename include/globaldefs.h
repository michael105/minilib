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
#define FLAG_MASK 0xFFFFFFF

#ifdef X64
typedef union { FILE *F; int i, fd;} mfl_union;
#else
//typedef union { FILE *F; int fd;} mfl_union;
#error checkme
#endif
//(untested for x32) better commenting this out for now.
//Might be better to find later
//also: endiannes.


#ifndef stdin
#define stdin (FILE*)0
#endif
#ifndef stdout
#define stdout (FILE*)1
#endif
#ifndef stderr
#define stderr (FILE*)2
#endif


#endif
