#if 0
mini_read
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
  volatile  void * a2=0;
  volatile  int  a3=0;
  read(a1,a2,a3);
  return(ret);
}
