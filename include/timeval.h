#ifndef timeval_h
#define timeval_h
#include "time_t.h"

#ifndef timevaldefined
#define timevaldefined
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
#endif


struct timezone {
		int     tz_minuteswest; /*	minutes	west of	Greenwich */
		int     tz_dsttime;     /*	type of	dst correction */
};
#endif
