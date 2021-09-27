#ifndef linux_types_h
#define linux_types_h


typedef long long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;

typedef int sig_atomic_t;

typedef void (*__sighandler_t) (int);


// BSD nomenclature
typedef __sighandler_t sig_t;


typedef unsigned long __u64;
typedef unsigned int __u32;
typedef signed long __s64;
typedef signed int __s32;

typedef unsigned short __u16;
typedef signed short __s16;




#endif

