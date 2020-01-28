#if 0
mini_fanotify_mark
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
  volatile  long  a1=0;
  volatile   long  a2=0;
  volatile   __u64  a3=0;
  volatile   long  a4=0;
  volatile  long  a5=0;
  fanotify_mark(a1,a2,a3,a4,a5);
  return(ret);
}
