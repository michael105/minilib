#ifndef alltypes_h
#define alltypes_h



#define _Addr long
#define _Int64 long
#define _Reg long

#ifndef size_t
#define size_t long
#endif

typedef __builtin_va_list va_list;
#define __DEFINED_va_list

typedef __builtin_va_list __isoc_va_list;
#define __DEFINED___isoc_va_list

typedef int wchar_t;
#define __DEFINED_wchar_t


typedef long double double_t;
#define __DEFINED_double_t

typedef float float_t;
#define __DEFINED_float_t


typedef struct { long long __ll; long double __ld; } max_align_t;
#define __DEFINED_max_align_t

typedef long time_t;
#define __DEFINED_time_t

typedef long suseconds_t;
#define __DEFINED_suseconds_t

typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;
#define __DEFINED_pthread_attr_t

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;
#define __DEFINED_pthread_mutex_t

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;
#define __DEFINED_mtx_t

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;
#define __DEFINED_pthread_cond_t

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;
#define __DEFINED_cnd_t

typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;
#define __DEFINED_pthread_rwlock_t

typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;
#define __DEFINED_pthread_barrier_t

//typedef unsigned _Addr size_t;
//#define __DEFINED_size_t

typedef unsigned _Addr uintptr_t;
#define __DEFINED_uintptr_t

typedef _Addr ptrdiff_t;
#define __DEFINED_ptrdiff_t

typedef _Addr ssize_t;
#define __DEFINED_ssize_t

typedef _Addr intptr_t;
#define __DEFINED_intptr_t

typedef _Addr regoff_t;
#define __DEFINED_regoff_t

typedef _Reg register_t;
#define __DEFINED_register_t

typedef signed char     int8_t;
#define __DEFINED_int8_t

typedef signed short    int16_t;
#define __DEFINED_int16_t

typedef signed int      int32_t;
#define __DEFINED_int32_t

typedef signed _Int64   int64_t;
#define __DEFINED_int64_t

typedef signed _Int64   intmax_t;
#define __DEFINED_intmax_t

typedef unsigned char   uint8_t;
#define __DEFINED_uint8_t

typedef unsigned short  uint16_t;
#define __DEFINED_uint16_t

typedef unsigned int    uint32_t;
#define __DEFINED_uint32_t

typedef unsigned _Int64 uint64_t;
#define __DEFINED_uint64_t

typedef unsigned _Int64 u_int64_t;
#define __DEFINED_u_int64_t

typedef unsigned _Int64 uintmax_t;
#define __DEFINED_uintmax_t

typedef unsigned mode_t;
#define __DEFINED_mode_t

typedef unsigned _Reg nlink_t;
#define __DEFINED_nlink_t

typedef _Int64 off_t;
#define __DEFINED_off_t

typedef unsigned _Int64 ino_t;
#define __DEFINED_ino_t

typedef unsigned _Int64 dev_t;
#define __DEFINED_dev_t

typedef long blksize_t;
#define __DEFINED_blksize_t

typedef _Int64 blkcnt_t;
#define __DEFINED_blkcnt_t

typedef unsigned _Int64 fsblkcnt_t;
#define __DEFINED_fsblkcnt_t

typedef unsigned _Int64 fsfilcnt_t;
#define __DEFINED_fsfilcnt_t

typedef unsigned wint_t;
#define __DEFINED_wint_t

typedef unsigned long wctype_t;
#define __DEFINED_wctype_t

typedef void * timer_t;
#define __DEFINED_timer_t

typedef int clockid_t;
#define __DEFINED_clockid_t



typedef long clock_t;
#define __DEFINED_clock_t


#ifndef timeval
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#define __DEFINED_struct_timeval
#endif


struct timespec { time_t tv_sec; long tv_nsec; };
#define __DEFINED_struct_timespec




typedef int pid_t;
#define __DEFINED_pid_t



typedef unsigned id_t;
#define __DEFINED_id_t



typedef unsigned uid_t;
#define __DEFINED_uid_t



typedef unsigned gid_t;
#define __DEFINED_gid_t



typedef int key_t;
#define __DEFINED_key_t



typedef unsigned useconds_t;
#define __DEFINED_useconds_t





typedef struct _IO_FILE FILE;
#define __DEFINED_FILE




typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;
#define __DEFINED_mbstate_t




typedef struct __locale_struct * locale_t;
#define __DEFINED_locale_t




typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;
#define __DEFINED_sigset_t




struct iovec { void *iov_base; size_t iov_len; };
#define __DEFINED_struct_iovec




typedef unsigned socklen_t;
#define __DEFINED_socklen_t



typedef unsigned short sa_family_t;
#define __DEFINED_sa_family_t



#undef _Addr
#undef _Int64
#undef _Reg

#endif
