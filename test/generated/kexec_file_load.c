#if 0
mini_kexec_file_load
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
  volatile   int  a2=0;
  volatile   unsigned long  a3=0;
  volatile   const char  * a4="";
  volatile   unsigned long  a5=0;
  kexec_file_load(a1,a2,a3,a4,a5);
  return(ret);
}
