#if 0
mini_pread64
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
  volatile  unsigned long  a1=0;
  volatile   char * a2="";
  volatile   size_t  a3=0;
  volatile   loff_t  a4=0;
  pread64(a1,a2,a3,a4);
  return(ret);
}
