#if 0
mini_start
mini_writes
mini_perror
mini_errno
mini_prints
mini_putc
mini_strcmp

#mini_buf 256
#mini_printf
#mini_itodec
#mini_dtodec
LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

#define SIGMAX 31
const char* sig[]={ "", "HUP","INT","QUIT","ILL","TRAP",
		"ABRT","BUS","FPE","KILL","USR1","SEGV","USR2",
		"PIPE","ALRM","TERM","STKFLT","CHLD","CONT",
		"STOP","TSTP","TTIN","TTOU","URG","XCPU","XFSZ",
		"VTALRM","PROF","WINCH","POLL","PWR","SYS"};


int toint(const char *c){
	int ret = 0;

	while ( *c > 47 && *c < 58 ){
			ret *= 10;
			ret += (*c-48);
			*c++;		
	}
	return(ret);
}


void usage(){
		writes("Usage: kill [-l] [-SIGNAL/-signalnum] [PID1] [PID2] ...\n");
		exit(1);
}

void print_names(){
		for ( int a = 1; a<32; a++ ){
				prints( sig[a] );
				putc(' ',stdout);
		}
		putc('\n',stdout);
		exit(0);
}

int nokill(int p, int s){
		//printf("nokill: %d, %d\n",p,s);
		return(0);
}

int cmp(const char *p, const char *p2 ){

		int *l = (int*)p;
		int *l2 = (int*)p2;

		if ((*l) == (*l2)) 
				return(0);
		return(1);
}

int to_number( const char *p ){
		for ( int ret = 1; ret <= SIGMAX; ret ++ ){
				if ( cmp( p, sig[ret]) == 0 )
						return(ret);
		}
		writes("Unknown Signal: ");
		prints(p);
		putc('\n',stdout);
		exit(1);
		return(0);
}

int main(int argc, char *argv[])
{
	int signum=SIGTERM; 
	pid_t pid;

	if (argc == 1) {
			usage();
	}

#define AV argv[0]
	for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
			if ( AV[1] == 'h' )
					usage();
			if ( AV[1] == 'l' )
					print_names();
		
			if ( AV[1] >= '0' && AV[1] <= '9' )
					signum = toint( (AV +1 ) );

			int tmp =1;
			if ( AV[1] == 'S' && AV[2] == 'I' && AV[3] == 'G' )
					tmp = 4;

			if ( AV[tmp] >= 'A' && AV[tmp] <= 'X' ){
					signum = to_number( AV+tmp );
			}

	}

	int ret = 0;
	while (*argv){
		pid = toint(*argv);
		if (kill(pid, signum)) {
				perror("kill: ");
			ret = 1;
		}
		*argv++;
	}

	return ret;
}
