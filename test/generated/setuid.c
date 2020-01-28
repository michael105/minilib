#if 0
mini_setuid
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
  volatile  uid_t  a1=0;
  setuid(a1);
  return(ret);
}
