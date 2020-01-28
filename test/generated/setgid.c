#if 0
mini_setgid
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
  volatile  gid_t  a1=0;
  setgid(a1);
  return(ret);
}
