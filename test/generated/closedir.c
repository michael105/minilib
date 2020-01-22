#if 0
mini_closedir
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
  volatile DIR * a1=0;
  closedir(a1);
  return(ret);
}
