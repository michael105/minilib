#if 0
mini_mq_timedreceive
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
  volatile  mqd_t  a1=0;
  volatile   char * a2="";
  volatile   size_t  a3=0;
  volatile   unsigned int * a4=0;
  volatile   const struct timespec * a5=0;
  mq_timedreceive(a1,a2,a3,a4,a5);
  return(ret);
}
