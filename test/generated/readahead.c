#if 0
mini_readahead
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
  volatile   loff_t  a2=0;
  volatile   size_t  a3=0;
  readahead(a1,a2,a3);
  return(ret);
}
