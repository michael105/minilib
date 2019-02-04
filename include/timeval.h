#ifndef timeval_h
#define timeval_h
#include "time_t.h"
struct timeval { time_t tv_sec; long tv_usec; };
#endif
