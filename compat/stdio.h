#ifndef stdio_h
#define stdio_h


#ifndef NULL
#define NULL 0
#endif

#ifndef stdin
#define stdin 0
#endif
#ifndef stdout
#define stdout 1
#endif
#ifndef stderr
#define stderr 2
#endif

#ifndef mini_buf
#define mini_buf 4096
#endif

extern int mbufsize;

#define BUFSIZ 1024

#include "include/syscall.h"

#include "include/fputc.h"
#include "include/fputs.h"

#define putchar(c) fputc(c,stdout)
#define vfprintf(...) fprintf(__VA_ARGS__)
#define fprintf(...) mfprintf(__VA_ARGS__)
#define perror(...) fprintf(stderr,__VA_ARGS__)

#include "include/gen/stdio.h"

#endif
