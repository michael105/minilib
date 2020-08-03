#if 0
mini_start

mini_scandir
mini_malloc
mini_prints
mini_writes
mini_open
mini_errno
mini_readdir
mini_qsort

mini_match
mini_strcmp

mini_eprintfs

mini_buf 4096
mini_printf
mini_sprintf
mini_itodec
mini_ltodec
mini_free_brk

OPTFLAG -O0

LDSCRIPT exec
INCLUDESRC
HEADERGUARDS

return
#endif



void usage(){
		writes("Usage: ls [-h]  \n");
		exit(1);
}

int de_match(const struct dirent *de){
		//if ( match(de->d_name,"*.c",0) == 0 )
		//		return(1);
		return(1);
}

int main(int argc, char **argv){
		
	
// define to something other for parsing the docu
#ifndef OPT
#define OPT(flag,desc) case flag:
#endif

	struct dirent **list;
	for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
			for ( char *c = argv[0]+1; *c != 0; c++ ){
					switch ( *c ){
							OPT('h',Show usage)
									usage();
					}
			}
	}
	
	if ( *argv == 0 ){
			printf("Here.");
			int r = scandir("/", &list, 0,0);
			printf("scandir: %d\n",r);
			printf("errno: %d\n",errno);
			while(r-->0){
					printsl(list[r]->d_name);
			}


	}

	for (;*argv; *argv++){
				int r = scandir(*argv, &list,&de_match ,0);
			printf("scandir: %d\n",r);
			printf("errno: %d\n",errno);
			while(r-->0){
					printsl(list[r]->d_name);
			}

			free_brk();	
	}
	

					writes("yy\n");
//	optimization_fence(*list);

		return(0);
}
