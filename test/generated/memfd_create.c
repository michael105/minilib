#if 0
mini_memfd_create
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
  volatile  const char  * a1="";
  volatile   unsigned int  a2=0;
  memfd_create(a1,a2);
  return(ret);
}