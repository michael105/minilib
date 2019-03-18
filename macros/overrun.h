// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
#include "../include/exit.h"
#include "../include/mprints.h"
#define MINI_TEST_OVERRUN(pos) if (pos > mini_buf){\
		mprintsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif

