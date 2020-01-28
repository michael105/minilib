#if 0
mini_newfstatat
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
  volatile   struct stat * a3=0;
  volatile   int  a4=0;
  newfstatat(a1,a2,a3,a4);
  return(ret);
}
