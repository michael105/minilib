#if 0
mini_lookup_dcookie
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
  volatile  u64  a1=0;
  volatile   long  a2=0;
  volatile   long  a3=0;
  lookup_dcookie(a1,a2,a3);
  return(ret);
}
