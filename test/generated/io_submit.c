#if 0
mini_io_submit
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
  volatile   struct iocb ** a3=0;
  io_submit(a1,a2,a3);
  return(ret);
}
