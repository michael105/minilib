#ifndef MINI_MBUF
#define MINI_MBUF
#ifndef mini_buf
#define mini_buf 1024
#endif

//int mbufsize=mini_buf; // crash.
//int mbufsize=0;

//+def
//int ibuf[mini_buf>>2];
//char *mbuf = (char*)ibuf;

//char __attribute__ ((aligned (4))) mbuf[mini_buf];
//int *ibuf = (int*)mbuf; // Also alignment of mbuf.. hopefully.

#endif
