#if 0
mini_start

mini_group_write

mini_exit_errno
mini_sleep
mini_clone_t

mini_printf
mini_buf 256
mini_itodec
mini_select
mini_open

COMPILE pipe read close dup2

INCLUDESRC

return
#endif


#define BUFSIZE 256

// create a new thread for each daemon, 
// fork, drop privileges, exec

// save output from fd1 and fd2 to file,tee to output
// Append to file, if it exists.
// doesn't return.
void savelog(char *path, int fd1, int fd2 ){
	char buf[BUFSIZE];
	fd_set rs;
	FD_ZERO (&rs);
	FD_SET(fd1,&rs); //
	FD_SET(fd2,&rs); //
	fd_set set = rs;
	// do logrotation here, when size> some amount.
	int logfd = open( path, O_RDWR | O_CREAT | O_APPEND, 0644 );
	int l;
	while(1){
		int l = select(fd2+1, &rs,0,0,0);
		int r = 0;
		if ( FD_ISSET(fd1,&rs) ){
				r = read(fd1, buf, BUFSIZE );
				write( 1, buf, r );
				while ( r>0 )
						r -= write( logfd, buf, r );
				
		}
		if ( FD_ISSET(fd2,&rs) ){
				r = read(fd2, buf, BUFSIZE );
				while ( r>0 )
						r -= write( logfd, buf, r );
		}		
		rs = set;				
	  // do logrotation here, when size> some amount.
		// (spawn an external program..)
		// (or just rename the file, and create a new log.
		// The daemon, collecting all logs into one file,
		// has to monitor the log directories already.)
	}
}






//+run a daemon.
int daemon( char *name, char *path, char **argv, char **envp ){

		int tid = clone_t(0);
		if ( tid > 0 )
				return(tid);

		


		return(0);
}


void usage(){
		writes("Usage: rd.servicename [-h] \'command1 arguments...\' \'command2 arguments...\'\n"
						"Run command(s), and restart them on exit. Log from stderr to syslog\n"
						"Collect all output in /var/log/rinit/daemon/'name'.log");
		exit(1);
}


int main(int argc, char **argv){

		if ( argc<2 || ( argv[1][0] == '-' && argv[1][1] == 'h' ))
				usage();

		typedef struct __service {
				char name[32];
				char path[256];
				char **arguments;
				char chroot[256];

				int delay;
		} service;

		int pfd[2];
		int pfd2[2];

		int e = pipe(pfd);
		if ( e<0 )
				exit_errno(e);

		e = pipe(pfd2);
		if ( e<0 )
				exit_errno(e);


	//	int pid = clone_t(0);
	
		long tid,ptid;
		
		//long ret = clone( 0|flags, 0, &tid, &ptid );
		long pid = clone_t(CLONE_SIGHAND );

	
		if ( pid == 0 ){ // child
				close(pfd[0]);
				close(pfd2[0]);
				dup2(pfd[1],STDOUT_FILENO);
				dup2(pfd2[1],STDERR_FILENO);
				writes("Hello\n");
				sleep(1);
				write(STDERR_FILENO,"soso\n",5);
				writes("xx Hello xx !!\n");
				sleep(3);
				write(STDERR_FILENO,"2: oso\n",7);
				exit(0);
		}

		savelog("test", pfd[0], pfd2[0] );

		char buf[128];
		int r = 0;
		while( r = read( pfd[0],buf,16 )){
				write( 1, buf, r );
		}

		sleep(3);
				




		return(0);
}
