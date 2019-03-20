#ifndef minilib_globals_c
#define minilib_globals_c

// 
//#ifndef mini_buf
//#warning defining minibuf
//#define mini_buf 1024
//#endif
//
#ifdef mini_buf
minilib_globals ml;

void minilib_global_init(){ // this is callen by startup.c
	ml.mbufsize = mini_buf;
//ibuf = (int*)mbuf;
}

#else

void minilib_global_init(){} // this is callen by startup.c

#endif

#endif
