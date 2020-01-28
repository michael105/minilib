#if 0
mini_ustat
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
  volatile   struct ustat * a2=0;
  ustat(a1,a2);
  return(ret);
}
