#ifndef mini_sleep_c
#define mini_sleep_c

//+header unistd.h
//+include
//+needs nanosleep
//+doc nonconformant sleep
// TODO: ignore blocked signals, sigchld
//+def
unsigned int volatile sleep(unsigned int seconds){
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
// Sleep useconds.
// I just hope, noone relies on an exact sleep time.
// which isn't possible without a real time os, anyways.
// When for whatever reason you'd need nanoseconds exact times,
// best shot might be a spinloop, and looking for cpu ticks.
//
// TODO: ignore blocked signals, sigchld
//+def
unsigned int volatile usleep(unsigned int useconds){
		// do a bit shift. this results in a slightly longer sleep time,
		// 1 micro has a duration of 1.024 microseconds now.
		// I just hope, noone relies on an exact sleep time.
		// which isn't possible without a real time os, anyways.
		// When for whatever reason you'd need nanoseconds exact times,
		// best shot might be a spinloop, and looking for cpu ticks.
		struct timespec ts; 
		//ts.tv_nsec = (long)((long)useconds<<10);// & (long)0xFFFFFFFF;
		//ts.tv_sec = ((long)useconds>>20);
		ts.tv_nsec = (long)((long)useconds*1000 % 1000000000 );// & (long)0xFFFFFFFF;
		ts.tv_sec = 0;
		if( useconds >= 1000000 )
				ts.tv_sec = ((long)useconds/1000000);
		return( nanosleep(&ts, &ts) );
}


#endif

