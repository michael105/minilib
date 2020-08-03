#if 0
mini_start
mini_group_print
mini_ext_match2
mini_writes
mini_fgets

INCLUDESRC

return
#endif

void p_match(int n, char *pos, int len){
		writes("p_match\n");
		write(1,pos,len);
		writes("\n");
}

int main(int argc, char **argv){
		char *matched = 0;
		char buf[1024]; // max line len

		if ( argc>2 ){
				matched = ext_match2(argv[1],argv[2],p_match,0,0);
		if ( matched )
				writes("match\n");
		else
				writes("no match\n");
		} else { //argc=2 
				 while ( fgets(buf, 1024, stdin) ){
						 prints("\n==== ",buf);
						 matched = ext_match2(buf,argv[1],p_match,0,0);
						 if ( matched )
								 writes("match\n");
						 else
								 writes("no match\n");
				 }
		}






		return(matched-argv[1]);
}
