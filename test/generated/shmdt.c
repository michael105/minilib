#if 0
mini_shmdt
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
  volatile  char * a1="";
  shmdt(a1);
  return(ret);
}
