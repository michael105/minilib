
//+include

//+doc macros for alignment.
// They take a number or pointer, and align upwards to 2,4,8,..256
// There are the macros ALIGN_2 ALIGN_4 ALIGN_8 ...,
// and ALIGN_P, which aligns to the size of a pointer. (8 for amd64)
//+def ALIGN

#define __ALIGNSHIFT2 1
#define __ALIGNSHIFT4 2
#define __ALIGNSHIFT8 3
#define __ALIGNSHIFT16 4
#define __ALIGNSHIFT32 5
#define __ALIGNSHIFT64 6
#define __ALIGNSHIFT128 7
#define __ALIGNSHIFT256 8
#define __ALIGN(shift,base,p) p = (typeof(p))(((( (POINTER)p - (POINTER)1 ) >> shift ) << shift ) +base)
#define _ALIGN( base, p ) __ALIGN( base,base,p)

#define _ALIGNBASE( base, p ) __ALIGN( __ALIGNSHIFT##base,base,p)

#define ALIGN_2(p) _ALIGNBASE(2,p)
#define ALIGN_4(p) _ALIGNBASE(4,p)
#define ALIGN_8(p) _ALIGNBASE(8,p)
#define ALIGN_16(p) _ALIGNBASE(16,p)
#define ALIGN_32(p) _ALIGNBASE(32,p)
#define ALIGN_64(p) _ALIGNBASE(64,p)
#define ALIGN_128(p) _ALIGNBASE(128,p)
#define ALIGN_256(p) _ALIGNBASE(256,p)
#define ALIGN_P(p)	_ALIGN( __SIZEOF_POINTER__ ,p)


