#if 0
mini_buf 256
#globals_on_stack
mini_errno
mini_start
mini_printf
mini_prints
mini_itodec
mini_atoi
mini_getenv
mini_writes
mini_environ
mini_getgrent
mini_setgrent
mini_getgrnam

mini_getgrgid

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

		struct group *gr;


		gr = getgrgid(2);
		dumpgr(gr);

			gr = getgrgid(10000);
		dumpgr(gr);

	gr = getgrgid(1000);
		dumpgr(gr);

		gr = getgrgid(2);
		dumpgr(gr);



		return(0);
}


