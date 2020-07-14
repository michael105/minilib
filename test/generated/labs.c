#if 0
mini_labs
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
  volatile long int  a1=0;
  labs(a1);
  return(ret);
}
