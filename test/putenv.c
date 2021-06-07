#if 0
mini_start
mini_putenv
mini_getenv
mini_environ


mini_prints
mini_printsl
mini_writes
mini_ret_errno

mini_buf 512
mini_malloc
mini_strcpy

INCLUDESRC

return
#endif


int main(int argc, char **argv){
		writes("putenv\n");

		//printsl(getenv("HOME"));
		putenv("HOME=/home/test");
		printsl(getenv("HOME"));

		if ( getenv("testvar22") )
				printsl(getenv("testvar22"));
		else writes("testvar22 doesn't exist\n");

		putenv("testvar22=test_var22: 42");
		printsl(getenv("testvar22"));

		char *c = malloc(32);
		strcpy(c,"vartochange=env var to change");
		putenv(c);
		
		printsl(getenv("vartochange"));
		strcpy(c,"vartochange=changed now.");
		printsl(getenv("vartochange"));

		return(0);
}
