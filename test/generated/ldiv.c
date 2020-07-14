#if 0
mini_ldiv
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
  volatile  long int  a2=0;
  ldiv(a1,a2);
  return(ret);
}
