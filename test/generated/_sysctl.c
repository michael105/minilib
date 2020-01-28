#if 0
mini__sysctl
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
  volatile  struct __sysctl_args * a1=0;
  _sysctl(a1);
  return(ret);
}
