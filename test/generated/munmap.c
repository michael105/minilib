#if 0
mini_munmap
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
  volatile  unsigned long  a1=0;
  volatile   size_t  a2=0;
  munmap(a1,a2);
  return(ret);
}