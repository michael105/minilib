// start the runlevel, supplied either on the commandline,
// the kernel's commandline (runlevel=xxx),
// or the runlevel default.
// Keep a getty open at tty1

#include "config.h"

#include "common.c"

static int shutdown;

int main( int argc, char **argv, char **envp ){
		log("rinit.run");

		char dir[PATHMAX];
		char runlevel[32];
		char buf[CMDLINEMAX]; 

		shutdown = 0;

		if ( argc < 2 ){
				// we need an empty argument or the runlevel supplied,
				// with extending empty spaces.
				// just exit for now. 
				// If you'd like to use this without init (rinit),
				// please supply an according argument.
				error("rinit.run should be executed by init. Abort.\n","",1);
				exit(1);
		}

		putenv("PATH=" PATH );

		strcpy(dir,RC_BASE_PATH);
	
		regex_match stm;
		match(argv[1],"% *", &stm ); // match nongreedy
		int pos = 0;

		if ( stm.len < 2 ){ // runlevel not supplied as argument
				FILE *cmdline = fopen("/proc/cmdline","r");
				fgets(buf,CMDLINEMAX,cmdline);
				match(buf,"*runlevel=%",&stm);
				fclose(cmdline);
		}

		if ( stm.len < 2 ){ // no match, no parameter runlevel=xxx given to the kernel
				stm.pos = RC_DEFAULT;
				stm.len = sizeof(RC_DEFAULT);
		}

		for ( pos=0;stm.len-->0;pos++ ){
				dir[pos+sizeof(RC_BASE_PATH)-1] = stm.pos[pos];
				argv[1][pos] = stm.pos[pos];
		}

		dir[pos+sizeof(RC_BASE_PATH)-1] = '/';
		dir[pos+sizeof(RC_BASE_PATH)] = 0;

		printsl( "Starting ",dir );

		int r = rundir(dir, 'B', argv, envp);

		char *gav[5] = { "getty", "38400", "/dev/tty1", "linux", 0 };

		while ( !shutdown ){ // keep one getty open for tty1,
				// in case something is going wrong
				int ret = vexec( GETTY, gav, envp );
				if ( errno )
						error( "Couldn't exec ",GETTY,errno);
				sleep(1);
		}

		return(r);
}

