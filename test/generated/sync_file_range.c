#if 0
mini_sync_file_range
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
  volatile  long  a1=0;
  volatile   loff_t  a2=0;
  volatile   loff_t  a3=0;
  volatile   long  a4=0;
  sync_file_range(a1,a2,a3,a4);
  return(ret);
}
