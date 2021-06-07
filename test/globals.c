#if 0
mini_start
#mini_buf 256
#mini_fprintf
mini_prints
#mini_printf
#mini_ltodec
#mini_itodec
mini_writes
#mini_errno

#globals_on_stack

OPTFLAG -Os
STRIPFLAG
#LDSCRIPT onlytext
LDSCRIPT text_and_bss

INCLUDESRC
SHRINKELF

return
#endif

int main(int argc, char **argv){
		//writes("Hello world!\n");
		//write(1,"val: ",5);
		//char buf[8];
		//buf[0]=48+mlgl->stream[1];
		//write(1,buf,1);

	 //printf("globals.\n");
	 writes("globals.\n");
	//int i = 21;
	//printf("21: %d\n",i);


		return(0);
}

