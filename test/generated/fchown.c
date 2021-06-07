#if 0
mini_fchown
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
  volatile  unsigned int  a1=0;
  volatile  uid_t  a2=0;
  volatile  gid_t  a3=0;
  fchown(a1,a2,a3);
  return(ret);
}
