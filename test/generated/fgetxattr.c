#if 0
mini_fgetxattr
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
  volatile  int  a1=0;
  volatile   const char * a2="";
  volatile   void * a3=0;
  volatile   size_t  a4=0;
  fgetxattr(a1,a2,a3,a4);
  return(ret);
}
