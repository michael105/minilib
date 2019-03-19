#ifndef minilib_globals_c
#define minilib_globals_c

// 
#ifndef mini_buf
#warning defining minibuf
#define mini_buf 1024
#endif


minilib_globals ml;

void minilib_global_init(){ // this is callen by startup.c
#ifdef mini_buf
	ml.mbufsize = mini_buf;
//ibuf = (int*)mbuf;
#endif
}

#endif
