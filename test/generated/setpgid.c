#if 0
mini_setpgid
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
  volatile  pid_t  a1=0;
  volatile  pid_t  a2=0;
  setpgid(a1,a2);
  return(ret);
}
