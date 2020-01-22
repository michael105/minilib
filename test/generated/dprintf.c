#if 0
mini_dprintf
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
  volatile  int  a1=0;
  volatile  const char * a2="";
  volatile   a3=0;
  dprintf(a1,a2,a3);
  return(ret);
}
