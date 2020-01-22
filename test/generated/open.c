#if 0
mini_open
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
  volatile  const char * a1="";
  volatile  int  a2=0;
  volatile   a3=0;
  open(a1,a2,a3);
  return(ret);
}
