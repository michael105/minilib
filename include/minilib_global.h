#ifndef minilib_global_h
#define minilib_global_h

// Don't like this pattern.
// Will most likely "bloat" minilib.
// But other options do not seem sensible.

#ifndef mini_buf
#warning defining mini_buf
#define mini_buf 4096
#endif

typedef struct {
		int mbufsize;
		union {
				int ibuf[mini_buf>>2];
				char mbuf[mini_buf];
		};
} minilib_globals;

extern minilib_globals ml;



#endif
