#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>


// Hardcode full path and arguments to Xorg to prevent users 
// of placing another binary into the search path,
// which would be executed with admin rights.
// For the same reason, it shouldn't be possible to submit 
// arbitrary arguments to xorg for users,
// nor should be Xorg itself be suid or executable by users.
// xorg is a quite complex executable, so I believe it's better to have 
// a small static binary being suid,
// which can be checked for security flaws
// with sametime known vulnerabilities of the xserver
//
#define XSERV_CMD { "/usr/bin/Xorg", "-nolisten", "tcp", "-displayfd", displayfd, 0 }


// the shell which parses $HOME/.xinitrc
// with the rights of the user calling sx
// The full path should be hardcoded for the same reasons
#define SHELL "/bin/sh"


// The default xinitrc, in case either HOME is not set,
// or HOME/.xinitrc not present
#define DEFAULT_XINITRC "/etc/X11/xinitrc"


#define PROGNAME "sxinit"

// globals
#define DISPLAY_ENV "DISPLAY=:0"
char display[] = DISPLAY_ENV;

static pid_t xserv_pid = 0;
static pid_t xinit_pid = 0;
static int signalpipe[2];
extern char** environ;

// signal handler
void handler(int s) {
	write(signalpipe[1], "", 1);
}

// setup signal handler
static void handle_signals(void (*func)(int)) {
	struct sigaction sa = {0};
	sa.sa_handler = handler;
	sa.sa_flags = func == handler ? SA_RESTART : 0;
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGCHLD, &sa, NULL);
}

// cleanup
static void cleanup() {
	if (xserv_pid > 0) kill(xserv_pid, SIGTERM);
	if (xinit_pid > 0) kill(xinit_pid, SIGTERM);
	if (xserv_pid > 0) waitpid(xserv_pid, NULL, 0);
	if (xinit_pid > 0) waitpid(xinit_pid, NULL, 0);
}

// exit with failure
static void die(const char *msg) {
	int e = errno;
	fputs( PROGNAME ": ", stderr );
	fputs(msg, stderr);
	fputc( '\n', stderr );
	fputs( strerror(e),stderr);
	fputc( '\n', stderr );
	
	cleanup();

	exit(EXIT_FAILURE);
}

// start the xserver
static void start_xserv(){
	int fd[2];
	if (-1 == pipe(fd))
		die("pipe:");

	char displayfd[2] = "?";
	displayfd[0] = '0'+fd[1];

	xserv_pid = fork();
	if (xserv_pid == -1)
		die("fork:");
	
	if (xserv_pid == 0) {
		close(signalpipe[0]);
		close(signalpipe[1]);
		handle_signals(SIG_DFL);
		close(fd[0]);
		char *xservcmd[] = XSERV_CMD;
		fputs( displayfd, stderr );
		fputc('\n',stderr);
		execve( xservcmd[0], xservcmd, environ );
		die("Couldn't start the xserver");
	}
	
	close(fd[1]);

	// read the diplay fd number and set the enviromental variable
	int n = read(fd[0], display+sizeof(DISPLAY_ENV)-2, 1);

	if (n == -1){
		die("Couldn't read from pipe");
	}
	
	close(fd[0]);
	fputs(display,stderr);

	putenv(display);
}

// execute xinitrc
static void start_xinit(int argc, char *argv[]) {
	pid_t xinit_pid = fork();
	if (xinit_pid == -1)
		die("fork:");

	if (xinit_pid == 0) {
		char buf[PATH_MAX];
		char *home = getenv("HOME");
		if ( !home ){
			strcpy(buf,DEFAULT_XINITRC);
		} else {
			char *c = stpcpy(buf,home);
			strcpy(c,"/.xinitrc");
		}

		close(signalpipe[0]);
		close(signalpipe[1]);
		handle_signals(SIG_DFL);

		char *xinitcmd[argc+3];
		xinitcmd[0] = SHELL;
		xinitcmd[1] = buf;

		// copy arguments
		char **xp = xinitcmd+2;
		while( ( *xp = *argv ) ){
			xp++; argv++;
		}

		execve( xinitcmd[0], xinitcmd, environ);

		// shouldn't get here
		die("Couldn't execute xinitrc");
	}
}


int main( int argc, char *argv[], char *envp[] ){
	if (-1 == pipe(signalpipe))
		die("pipe:");

	handle_signals(handler);

	char *home = getenv("HOME");
	if (home == NULL)
		die("HOME enviroment variable is not set");
	
	if (-1 == chdir(home))
		die("chdir:");

	start_xserv();
	fputs( PROGNAME ": Xorg started\n",stderr);

	// Drop suid privileges
	setreuid( -1, getuid() );

	argv++;
	start_xinit(argc-1,argv);

	char running = 1;
	while (running)
		read(signalpipe[0], &running, 1);
	
	cleanup();
	
	return EXIT_SUCCESS;
}
