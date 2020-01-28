#if 0
mini_inotify_rm_watch
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
  volatile   __s32  a2=0;
  inotify_rm_watch(a1,a2);
  return(ret);
}
