#if 0
mini_lchown
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
  volatile   uid_t  a2=0;
  volatile   gid_t  a3=0;
  lchown(a1,a2,a3);
  return(ret);
}