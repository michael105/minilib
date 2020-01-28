#if 0
mini_fchownat
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
  volatile   uid_t  a3=0;
  volatile   gid_t  a4=0;
  volatile   int  a5=0;
  fchownat(a1,a2,a3,a4,a5);
  return(ret);
}
