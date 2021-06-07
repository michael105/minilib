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

		if ( !buf  ){
				printf("Got: trouble\n");
		}




		int a = 0;

		// buf[-1] = 0; // ok segfault
		for ( a=0; a<4000;a+= 256){
				printf("a: %d\n",a);
				buf[a] = a; // segfault at pagesize. ok.
		}
		int r=0;
		r = free_safebuf(buf,7000);
		printsl("Freed");
		if ( r ){
				printf("Got: %d\n",r);
		}

		//for ( a=0; a<4000;a+= 256){ // ok. segfaults
		//		printf("a: %d\n",a);
		//		buf[a] = a; // segfault at pagesize. ok.
		//}
	

		return(0);
}
