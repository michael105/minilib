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

mini_getpwent
mini_endgrent

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

		gr=getgrnam("bin");
		dumpgr(gr);
		gr=getgrnam("bin");
		dumpgr(gr);

		gr=getgrnam("root");
		dumpgr(gr);

		gr=getgrnam("micha");
		dumpgr(gr);

		gr=getgrnam("bin");
		dumpgr(gr);

		endgrent();

		gr=getgrnam("bin");
		dumpgr(gr);
		gr=getgrnam("bin");
		dumpgr(gr);

		gr=getgrnam("root");
		dumpgr(gr);

		gr=getgrnam("micha");
		dumpgr(gr);

		gr=getgrnam("bin");
		dumpgr(gr);



		return(0);
}


