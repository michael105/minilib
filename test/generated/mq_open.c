#if 0
mini_mq_open
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
  volatile  const char * a1="";
  volatile   int  a2=0;
  volatile   mode_t  a3=0;
  volatile   struct mq_attr * a4=0;
  mq_open(a1,a2,a3,a4);
  return(ret);
}
