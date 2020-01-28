#if 0
mini_process_vm_writev
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
  volatile   const struct iovec * a2=0;
  volatile   unsigned long  a3=0;
  volatile   const struct iovcc * a4=0;
  volatile   unsigned long  a5=0;
  volatile   unsigned long  a6=0;
  process_vm_writev(a1,a2,a3,a4,a5,a6);
  return(ret);
}
