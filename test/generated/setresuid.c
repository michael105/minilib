#if 0
mini_setresuid
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
  volatile  uid_t * a1=0;
  volatile   uid_t * a2=0;
  volatile   uid_t * a3=0;
  setresuid(a1,a2,a3);
  return(ret);
}
