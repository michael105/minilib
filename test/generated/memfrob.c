#if 0
mini_memfrob
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
  volatile  unsigned int  a2=0;
  memfrob(a1,a2);
  return(ret);
}
