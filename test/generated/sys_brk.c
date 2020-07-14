#if 0
mini_sys_brk
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
  volatile unsigned long  a1=0;
  sys_brk(a1);
  return(ret);
}
