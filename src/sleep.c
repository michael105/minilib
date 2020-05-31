#ifndef mini_sleep_c
#define mini_sleep_c

//+header unistd.h
//+include
//+needs nanosleep
//+doc nonconformant sleep
// TODO: ignore blocked signals, sigchld
//+def
unsigned int sleep(unsigned int seconds){
		unsigned int res;
		struct timespec ts = { .tv_sec = (long int) seconds, .tv_nsec = 0 };
		res = nanosleep(&ts, &ts);
		if (res) res = (unsigned int) ts.tv_sec + (ts.tv_nsec >= 500000000L);
		return res;
}

#endif

