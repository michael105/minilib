#if 0
mini_setgroups
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
  volatile   gid_t * a2=0;
  setgroups(a1,a2);
  return(ret);
}
