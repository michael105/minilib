#if 0
mini_quotactl
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
  volatile  unsigned int  a1=0;
  volatile   const char * a2="";
  volatile   qid_t  a3=0;
  volatile   void * a4=0;
  quotactl(a1,a2,a3,a4);
  return(ret);
}
