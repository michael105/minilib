#ifndef	_SYS_TYPES_H
#define	_SYS_TYPES_H
#ifdef __cplusplus
extern "C" {
#endif
#include <bits/alltypes.h>

typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned u_int32_t;
typedef char *caddr_t;
typedef unsigned char u_char;
typedef unsigned short u_short, ushort;
typedef unsigned u_int, uint;
typedef unsigned long u_long, ulong;
typedef long long quad_t;
typedef unsigned long long u_quad_t;
#include <endian.h>

#define blkcnt64_t blkcnt_t
#define fsblkcnt64_t fsblkcnt_t
#define fsfilcnt64_t fsfilcnt_t
#define ino64_t ino_t
#define off64_t off_t

#ifdef __cplusplus
}
#endif
#endif
