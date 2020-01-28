#if 0
mini_io_setup
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
  volatile  unsigned  a1=0;
  volatile   aio_context_t * a2=0;
  io_setup(a1,a2);
  return(ret);
}
