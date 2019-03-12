#ifndef string_h
#define string_h

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

#include "sys/types.h"

#include "src/mstrcmp.c"
#include "src/mstrlen.c"
#include "src/memcpy.c"
#include "src/strcat.c"

#endif

