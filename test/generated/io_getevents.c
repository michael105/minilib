#if 0
mini_io_getevents
mini_buf 0
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT text_and_bss
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile  aio_context_t  a1=0;
  volatile   long  a2=0;
  volatile   long  a3=0;
  volatile   struct io_event * a4=0;
  io_getevents(a1,a2,a3,a4);
  return(ret);
}
