#if 0
mini_add_key
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
  volatile   const char * a2="";
  volatile   const void * a3=0;
  volatile   size_t  a4=0;
  add_key(a1,a2,a3,a4);
  return(ret);
}
