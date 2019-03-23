#ifndef timeval_h
#define timeval_h
#include "time_t.h"
//struct timeval { time_t tv_sec; long tv_usec; };

struct timezone {
		int     tz_minuteswest; /*	minutes	west of	Greenwich */
		int     tz_dsttime;     /*	type of	dst correction */
};
#endif
