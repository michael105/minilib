#if 0
mini_start
#globals_on_stack

mini_errno_str
mini_strerror
mini_prints
mini_write

#mini_buf 256
#mini_printf
#mini_itodec

INCLUDESRC
#LDSCRIPT textandbss

return
#endif


char *r1(){

	 char *c = "strerror.\n";
	 return(c);
}
char *r2(){

	 char *c = "xxxxxxxxx.\n";
	 return(c);
}



int main(int argc, char **argv){


/*
		c[0]='x';
		c[1]='x';
		c[2]='x';
		c[3]='\n';
		*/
		//c = "strerror\n";
		char *x = r1();
		write(1,x,10);
		char *y = r2();
		write(1,x,10);
		write(1,y,10);

		prints(strerror(11));
		prints(strerror(223));

//		int i = 230;
//		printf("erg: %d\n",i%=100);
//		printf("erg: %d\n",i);

		return(0);
}

