#if 0
mini_start
mini_printsl
mini_writes
mini_ewrites
mini_uitodec
mini_getgrnam

mini_atoi
mini_getgrgid


INCLUDESRC
SHRINKELF

return
#endif


void usage(){
	writes("gid [groupname] [-g gid]\nGet the gid of groupname,\nor the groupname of gid\n");
	exit(0);
}

void printud(uint gid){
	char buf[16];
	uitodec( gid, buf, 0,0,0 );
	printsl(buf);
	exit(0);
}


int main(int argc, char *argv[]){

	if ( argc > 1 && argv[1][0]=='-' && argv[1][1]=='h' )
		usage();


	if ( argc==1 ){
		int gid = getuid();
		if (gid<0){
			ewrites("Couldn't get gid\n");
			exit(1);
		}
		printud(gid);
	}

	if (argv[1][0]=='-' && argv[1][1]=='g'){
		if ( argc < 3 )
			usage();

		int gid = atoi( argv[2] );
		struct group *g = getgrgid(gid);
		if ( !g ){
			eprintsl("Groupid not found: ",argv[2]);
			exit(1);
		}
		printsl(g->gr_name);
		exit(0);
	}


	struct group *g = getgrnam(argv[1]);
	if ( !g ){
		eprintsl("Group not found: ",argv[1]);
		exit(1);
	}
	printud( g->gr_gid );


	return(0);
}

