#if 0
 mini_start
 mini_printf
 mini_dprintf
 mini_prints
 mini_itooct
 mini_itohex
 mini_itobin
 mini_stat
 mini_writes

 mini_buf 256
 INCLUDESRC
 shrinkelf
return
#endif

void usage(){
		writes("usage: stat [-h] path1 [path2...]\n");
		exit(0);
}

int main(int argc, char *argv[]){

		if ( argc>1 && argv[1][0] == '-' && argv[1][1] == 'h' ) 
				usage();

		struct stat st;

		for ( *argv++; *argv; *argv++ ){
				prints( *argv,"\n");
				stat(*argv, &st );
				printf("mode: %o - %b\n",st.st_mode,st.st_mode);


		}

		return 0;
}
