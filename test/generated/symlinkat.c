#if 0
mini_symlinkat
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
  volatile   int  a2=0;
  volatile   const char * a3="";
  symlinkat(a1,a2,a3);
  return(ret);
}