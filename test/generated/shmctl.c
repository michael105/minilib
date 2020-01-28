#if 0
mini_shmctl
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
  volatile   int  a2=0;
  volatile   struct shmid_ds * a3=0;
  shmctl(a1,a2,a3);
  return(ret);
}
