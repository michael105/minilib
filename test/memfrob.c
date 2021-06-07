#if 0
mini_buf 256
mini_start
mini_prints
mini_memfrob
mini_INCLUDESRC
return
#endif



int main( int argc, char *argv[] ){

		char *c = "memfrob\ntest\n";
		prints(c);

		memfrob(c,1);

		prints(c);

		memfrob(c,8);
		prints(c);


		return(0);
}
