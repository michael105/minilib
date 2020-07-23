#if 0
mini_start

mini_scandir
mini_malloc
mini_prints
mini_writes
mini_open
mini_errno
mini_readdir

mini_re_match

mini_eprintfs

mini_buf 4096
mini_printf
mini_sprintf
mini_itodec
mini_ltodec
mini_free_brk

OPTFLAG -O0

INCLUDESRC
HEADERGUARDS

return
#endif



void usage(){
		writes("Usage: ls [-h]  \n");
		exit(1);
}

int match(const struct dirent *de){
		if ( re_match(de->d_name,"*x*") == 0 )
				return(1);
		return(0);
}

int main(int argc, char **argv){
		
	
// define to something other for parsing the docu
#ifndef OPT
#define OPT(flag,desc) case flag:
#endif

	for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
			for ( char *c = argv[0]+1; *c != 0; c++ ){
					switch ( *c ){
							OPT('h',Show usage)
									usage();
					}
			}
	}
	
	struct dirent ***list;
	if ( *argv == 0 ){
			int r = scandir("/", list, 0,0);
			printf("scandir: %d\n",r);
			printf("errno: %d\n",errno);
			while(r-->0){
					writes("z\n");
			}


	}

	for (;*argv; *argv++){
				int r = scandir(*argv, list,&match ,0);
			printf("scandir: %d\n",r);
			printf("errno: %d\n",errno);
			while(r-->0){
					writes("z\n");
			}

			free_brk();	
	}
	


		return(0);
}
