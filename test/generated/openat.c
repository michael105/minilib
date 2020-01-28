#if 0
mini_openat
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
  volatile   const char * a2="";
  volatile   int  a3=0;
  volatile   int  a4=0;
  openat(a1,a2,a3,a4);
  return(ret);
}
