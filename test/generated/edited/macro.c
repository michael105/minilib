#if 0
#mini_macro
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
  //macro(a1);
  return(ret);
}
