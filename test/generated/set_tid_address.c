#if 0
mini_set_tid_address
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
  volatile  int * a1=0;
  set_tid_address(a1);
  return(ret);
}
