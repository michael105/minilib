#if 0
mini_lgetxattr
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
  volatile   void * a3=0;
  volatile   size_t  a4=0;
  lgetxattr(a1,a2,a3,a4);
  return(ret);
}
