#if 0
mini_uname
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
  volatile struct old_utsname * a1=0;
  uname(a1);
  return(ret);
}
