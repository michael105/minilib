#if 0
mini_start
mini_ewrites
mini_writes
mini_eprints
mini_exit_errno
mini_syscalls
mini_strcpy


INCLUDESRC
SHRINKELF
#LDSCRIPT text_and_bss

return
#endif

// sudo for root, to drop privileges

#define uid_nobody 65534
#define gid_nobody 65534



void usage(){
		writes("usage: udo [-h] [-u uid] [-g gid] [-G gid1,gid2,...] [-G ...] [-G gid32] command [arguments]\n");
		exit(1);
}

int getint( const char *c ){
		if ( !c )
				usage();
		int ret = 0;
		while( (*c>='0') && (*c<='9') ){
				ret*=10;
				ret=ret+(*c-48);
				c++;
		}
		if ( *c != 0 )
				usage();

		return(ret);
}

int main(int argc,	char **argv, char **envp ){

		int uid = uid_nobody;
		int gid = gid_nobody;
		static gid_t groups[32];
		int groupcount = 0;

		if (argc < 2 ){
				usage();
		}

		for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
				switch ( argv[0][1] ){
						case 'h':
						usage();
						case 'u':
								uid = getint(argv[1]);
								break;
						//case 'H': (todo: set HOME var)
						// For now prepend udo with the setting 
						// ( e.g. 'HOME=/tmp udo -u 1000 id' )
						//		break;
						case 'g':
								gid = getint(argv[1]);
								break;
						case 'G': { 
													char *c = argv[1];
													do { 
															groups[groupcount] = 0;
															for( int i=0; (*c>='0') && (*c<='9'); c++ )
																	groups[groupcount] = groups[groupcount]*10 + *c-'0';
															groupcount++;
													} while ( *c && *c==',' && c++ );
											}
										
				}
				*argv++;
		}

		if ( !*argv )
				usage();

		if ( groupcount == 0){
				groupcount = 1;
				groups[0] = gid;
		}

		int ret;

#define IFFAIL(a,str) if ( (ret=a) ){ewrites(str); goto failed;}

		IFFAIL(sys_setgroups(groupcount,groups),"setgroups()");
		IFFAIL(setgid(gid),"setgid()");
		IFFAIL(setuid(uid),"setuid()");


		for ( char *c = *argv; c<(*envp-1); c++ ){
				if ( !*c )
						*c = ' ';
		}

		char* arg[] = { "sh", "-c", *argv };

		ret = execve("/bin/sh", arg, envp );

		ewrites("Executing /bin/sh");
failed:
		ewrites(" failed\n");
		exit_errno(ret);
}
