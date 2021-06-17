#if 0
mini_buf 256
#globals_on_stack
mini_errno
mini_start
mini_printf
mini_prints
mini_printsl
mini_itodec
mini_atoi
mini_getenv
mini_writes
mini_environ
mini_getgrgid
mini_getgroups
mini_getpwnam
mini_grent

mini_getpwent
mini_endpwent

source common.conf

mini_INCLUDESRC
STRIPFLAG
OPTFLAG -Os
LDSCRIPT text_and_bss
return
#endif

void dumpgr( struct group* gr){

//	prints("XX\n");
	//	printsl("= ",*mlgl->groupfile.p2);
if ( gr ){
		printf("> %s - %d -", gr->gr_name,gr->gr_gid);
		for ( char **m = gr->gr_mem; *m; *m++ ){
			prints( " " , *m );
		}
		printsl("");
} else {
	printsl("nope");
}
}



int main( int argc, char *argv[], char *envp[] ){
		printsl(argv[0]);

		int grids[64];

		int ret = getgroups(64,grids);

		printf("ret: %d\n",ret);

		for ( int a=0;a<ret;a++){
				printf("gr: %d uid: %d\n",a,grids[a]);
				dumpgr(getgrgid(grids[a]));
		}




		return(0);
}
