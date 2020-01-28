#if 0
mini_io_destroy
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
  io_destroy(a1);
  return(ret);
}
