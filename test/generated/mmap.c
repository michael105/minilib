#if 0
mini_mmap
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
  volatile void* a1=0;
  volatile   size_t  a2=0;
  volatile   int  a3=0;
  volatile   int  a4=0;
  volatile   int  a5=0;
  volatile   off_t  a6=0;
  mmap(a1,a2,a3,a4,a5,a6);
  return(ret);
}
