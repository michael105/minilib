// Check, if referencing pos would overrun the buffer.
#ifndef overrun_h
#define overrun_h
#ifndef mini_prints
#define mini_prints
#endif
#include "../include/exit.h"
#include "../include/mprints.h"
#define MINI_TEST_OVERRUN(pos) if (pos > ml.mbufsize){\
		mprintsl("Buffer Overrun. Aborting.");\
		exit(1);}
#endif

