#if 0
mini_sdbm_hash
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
  volatile const unsigned char * a1="";
  sdbm_hash(a1);
  return(ret);
}
