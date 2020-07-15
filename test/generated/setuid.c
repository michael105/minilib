#if 0
mini_setuid
mini_buf 128
globals_on_stack
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT default
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile  uid_t  a1=0;
  setuid(a1);
  return(ret);
}
