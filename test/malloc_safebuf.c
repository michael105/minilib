#if 0

mini_start
mini_malloc_safebuf

mini_group_print
mini_group_printf
mini_buf 256

mini_fork

INCLUDESRC

return
#endif

int main(int argc, char **argv){

		
		char *buf = malloc_safebuf(7000);


		int a = 0;

		// buf[-1] = 0; // ok segfault
		for ( a=0; a<16000;a+= 256){
				printf("a: %d\n",a);
				buf[a] = a; // segfault at pagesize. ok.
		}

		return(0);
}
