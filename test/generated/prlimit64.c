#if 0
mini_prlimit64
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
  volatile   unsigned int  a2=0;
  volatile   const struct rlimit64 * a3=0;
  volatile   struct rlimit64 * a4=0;
  prlimit64(a1,a2,a3,a4);
  return(ret);
}
