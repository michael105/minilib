#if 0
mini_memcmp
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
  volatile const void* a1=0;
  volatile const void* a2=0;
  volatile int  a3=0;
  memcmp(a1,a2,a3);
  return(ret);
}
