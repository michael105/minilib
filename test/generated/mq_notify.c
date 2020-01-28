#if 0
mini_mq_notify
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
  volatile   const struct sigevent * a2=0;
  mq_notify(a1,a2);
  return(ret);
}
