#if 0
mini_setreuid
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
  volatile   uid_t  a2=0;
  setreuid(a1,a2);
  return(ret);
}
