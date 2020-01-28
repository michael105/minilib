#if 0
mini_mount
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
  volatile  char * a1="";
  volatile   char * a2="";
  volatile   char * a3="";
  volatile   unsigned long  a4=0;
  volatile   void * a5=0;
  mount(a1,a2,a3,a4,a5);
  return(ret);
}
