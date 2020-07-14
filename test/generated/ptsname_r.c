#if 0
mini_ptsname_r
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
  volatile int  a1=0;
  volatile  char * a2="";
  volatile  size_t  a3=0;
  ptsname_r(a1,a2,a3);
  return(ret);
}
