// source: musl
#ifndef alltypes_h
#define alltypes_h



#define _Addr long
#define _Int64 long
#define _Reg long

#ifndef size_t
#define size_t long
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

//typedef __builtin_va_list va_list;

//typedef __builtin_va_list __isoc_va_list;

typedef int wchar_t;

typedef long double double_t;

typedef float float_t;

typedef struct { long long __ll; long double __ld; } max_align_t;

//typedef long time_t;

//typedef long suseconds_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;

typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;

//typedef unsigned _Addr size_t;
//#define __DEFINED_size_t

typedef unsigned _Addr uintptr_t;

typedef _Addr ptrdiff_t;

typedef _Addr ssize_t;

typedef _Addr intptr_t;

typedef _Addr regoff_t;

typedef _Reg register_t;

typedef signed char     int8_t;

typedef signed short    int16_t;

typedef signed int      int32_t;

typedef signed _Int64   int64_t;

typedef signed _Int64   intmax_t;

typedef unsigned char   uint8_t;

typedef unsigned short  uint16_t;

typedef unsigned int    uint32_t;

typedef unsigned _Int64 uint64_t;

typedef unsigned _Int64 u_int64_t;

typedef unsigned _Int64 uintmax_t;

typedef unsigned mode_t;

typedef unsigned _Reg nlink_t;

typedef _Int64 off_t;

typedef unsigned _Int64 ino_t;

typedef unsigned _Int64 dev_t;

typedef long blksize_t;

typedef _Int64 blkcnt_t;

typedef unsigned _Int64 fsblkcnt_t;

typedef unsigned _Int64 fsfilcnt_t;

typedef unsigned wint_t;

typedef unsigned long wctype_t;

typedef void * timer_t;

typedef int clockid_t;

typedef long clock_t;

//struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timespec { time_t tv_sec; long tv_nsec; };

typedef int pid_t;

typedef unsigned id_t;

typedef unsigned uid_t;

typedef unsigned gid_t;

typedef int key_t;

//typedef unsigned useconds_t;

//typedef struct _IO_FILE FILE;

typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;

typedef struct __locale_struct * locale_t;

typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;

struct iovec { void *iov_base; size_t iov_len; };

typedef unsigned socklen_t;

typedef unsigned short sa_family_t;

#undef _Addr
#undef _Int64
#undef _Reg

#endif

