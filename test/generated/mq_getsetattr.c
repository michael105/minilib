#if 0
mini_mq_getsetattr
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
  volatile   const struct mq_attr * a2=0;
  volatile   struct mq_attr * a3=0;
  mq_getsetattr(a1,a2,a3);
  return(ret);
}
