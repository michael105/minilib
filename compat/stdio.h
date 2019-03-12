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



#define BUFSIZ 1024

#include "include/syscall.h"

#include "src/mfprintf.c"
#include "src/mprints.c"
#include "src/mprint.c"
#include "src/msprintf.c"


#include "include/fputc.h"
#include "include/fputs.h"

#define putchar(c) fputc(c,stdout)


#define vfprintf(...) fprintf(__VA_ARGS__)
#define perror(...) fprintf(stderr,__VA_ARGS__)



#endif
