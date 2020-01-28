#if 0
mini_eventfd2
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
  volatile  unsigned int  a1=0;
  volatile   int  a2=0;
  eventfd2(a1,a2);
  return(ret);
}
