#ifndef vararg_h
#define vararg_h

#define VARARG(A,B) ((A+0) ?: B )
#define SHIFT(A,...) A
#define ARG(A,...) __VA_ARGS__

#endif

