#if 0
mini_seccomp
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
  volatile  unsigned int  a1=0;
  volatile   unsigned int  a2=0;
  volatile   const char  * a3="";
  seccomp(a1,a2,a3);
  return(ret);
}
