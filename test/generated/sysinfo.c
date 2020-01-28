#if 0
mini_sysinfo
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
  volatile  struct sysinfo * a1=0;
  sysinfo(a1);
  return(ret);
}
