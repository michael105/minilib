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


//+header unistd.h
//+include
//+needs nanosleep
//+doc nonconformant usleep. 
// Sleep useconds, one usecond equals 1.024 microseconds.
// TODO: ignore blocked signals, sigchld
//+def
unsigned int usleep(unsigned int useconds){
		unsigned int res;
		// do a bit shift. this results in a slightly longer sleep time,
		// 1 micro has a duration of 1.024 microseconds now.
		// I just hope, noone relies on an exact sleep time.
		// which isn't possible without a real time os, anyways.
		// When for whatever reason you'd need nanoseconds exatly times,
		// best shot might be a spinloop, and looking for cpu ticks.
		struct timespec ts = { .tv_sec = (long int) 0, .tv_nsec = (useconds<<10) };
		return( nanosleep(&ts, &ts) );
}


#endif

