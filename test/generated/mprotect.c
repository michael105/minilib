#if 0
mini_mprotect
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
  volatile  POINTER * a1=0;
  volatile  POINTER  a2=0;
  volatile  int  a3=0;
  mprotect(a1,a2,a3);
  return(ret);
}
