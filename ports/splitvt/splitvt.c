
/* 
	splitvt

  A fun utility designed to split your screen into twin shells.

				-Sam Lantinga  10/5/93

  An interesting note:
  1.6.3 was released in 1995, and 1.6.4 in 2000 - 5 years between patches!
  1.6.4 was released in 2001, and 1.6.6 in 2006 - 5 years between patches!

	14 years later, stripped all x/mouse related code. misc 2020
	aiming at minilib compatibility
	Stripped all code, I didn't need for rinit.
	So doing a backward version bump seems more honest;
	1.6.6 -> 0.7
*/

static char *version=
"@(#)Splitvt 1.6.6  3/11/2006  -Sam Lantinga   (slouken@devolution.com)\n0.7 (stripped) misc 2020\n";


#include	<sys/types.h>
#include	<sys/time.h>
#include	<sys/wait.h>
#include	<fcntl.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
//#include	<pwd.h>
#ifdef HAVE_UNISTD_H
#include	<unistd.h>
#endif


#include	"splitvt.h"
#include	"vt100.h"
#include	"vtmouse.h"

// include sources.
// results in more possiblities to optize
#include "misc.c"
#include "vt100.c"
//#include "videomem.c" 
//#include "terminal.c" 
//#include "vtmouse.c"

// default shell
#define SHELL "/bin/mksh"


/* With xterm support, cut and paste is disabled and the title bar is
   reset to the string "xterm" after splitvt quits.  Not desirable in
   some cases.. ;^)
*/
#define X_SUPPORT	/* Define X_SUPPORT if you want xterm support */
//#define XTITLE		/* Define this for an xterm title bar */

#ifdef NEED_SELECT_H
#include	<sys/select.h>
#endif

#ifdef NEED_INET_H
#include	<sys/inet.h>
#endif

#ifndef SIGCLD	/* BSD */
#define SIGCLD SIGCHLD
#endif


extern char tty_name[];			/* From misc.c about get_master_pty() */
static char upper_tty[64]={'\0'};	/* tty_name of the upper window */
static char lower_tty[64]={'\0'};	/* tty_name of the lower window */	
static struct passwd *pw=NULL;		/* Our passwd entry pointer */

static void finish(), move_bar(), winch();
#ifdef LOCK
extern void lock_screen();		/* From lock.c */
#endif
void normal_input();
static int  insert_dash();
static int  isalive();
char extract();
//void splitvtrc();

void (*do_input)() = normal_input;

static char selection[BUFSIZ];		/* Screen selection buffer */

static int topok=1, bottomok=1;		/* I/O flags */
static int toppid=0, bottompid=0;	/* Children */
static int ttyfd=0, thisfd;		/* I/O file descriptors */
static int topfd, bottomfd;		/* Master file descriptors */

int stbottom=0;			/* Start in the bottom vt? */ 

/* Special characters */
char 	command_c=COMMAND,
	switch_c=SWITCH, 
	quote_c=QUOTE; 
int     dologin=0;		/* Do the shells run as login shells? */

/* The command to run in each window */
char *upper_args[MAX_ARGS+1]={NULL}, *lower_args[MAX_ARGS+1]={NULL};
int upper_empty=1, lower_empty=1;
extern char **environ;

void print_usage(argv)
char *argv;
{
	fprintf(stderr, "\nUsage: %s [options] [shell]\n\n", argv);
	fprintf(stderr, "Options:\n");
	fprintf(stderr, "\t-s numlines\t\tSets 'numlines' to the number of lines\n");
	fprintf(stderr, "\t\t\t\tin the top window.  This number will\n");
	fprintf(stderr, "\t\t\t\tbe modified if the screen isn't big\n");
	fprintf(stderr, "\t\t\t\tenough to handle the full size.\n\n");
	fprintf(stderr, "\t-t title\t\tSets the xterm title bar to 'title'\n");
	fprintf(stderr, "\t-upper command\t\tRuns 'command' in the upper window\n");
	fprintf(stderr, "\t-lower command\t\tRuns 'command' in the lower window\n");
	fprintf(stderr, "\t-bottom\t\t\tStarts in the lower window\n");
	fprintf(stderr, "\t-login\t\t\tRuns programs as if they were login shells\n");
	fprintf(stderr, "\t-nologin\t\tOverrides \"set login on\" in startup file\n");
	fprintf(stderr, "\t-rcfile file\t\tLoads 'file' at startup instead of ~/.splitvtrc\n");
	fprintf(stderr, "\t-norc\t\t\tSuppresses loading your startup file\n");
	fprintf(stderr, "\t-v\t\t\tPrint out the version number\n");
	fprintf(stderr, "\n");
	exit(1);
}

 
int main(int argc, char **argv, char **envp){
	extern int errno, optind;
	extern char *optarg;
	//environ = envp;

	int i, len, maxfds, numready;
	char buffer[BUFSIZ], *ptr;
	char *xterm_title=NULL;
	struct timeval tv, *tvptr;
	fd_set read_mask;
	//static struct passwd pwdata;	/* Our passwd entry */

	struct event X_event;
	int on_separator=0;

	/* Are we called sanely? */
	if ( argv == NULL || argv[0] == NULL ) {
		fprintf(stderr, "%s is NULL! aborting.\n",
			argv == NULL ? "argv" : "argv[0]");
		exit(-1);
	}

#ifdef NEED_INET_H
        /* There is a bug in the Wallabong Group's implementation
           of select().  It will not work properly with fd 0 */

        if ( (ttyfd=dup(0)) < 0 )
        {
                perror("dup() error");
                exit(2);
        }
#endif

#ifdef RC
	/* First, get default options from ~/.splitvtrc */
	for ( i=1; argv[i]; ++i ) {
		if ( strcmp(argv[i], "-norc") == 0 ) {
			i=0;
			break;
		} else if ( strcmp(argv[i], "-rcfile") == 0 ) {
			if ( ! argv[++i] )
				print_usage(argv[0]);
			startupfile=argv[i];
		}
	}
	if ( i )
		splitvtrc();
#endif

#if 0
	/* Parse command line options */
	while ( (i=getopt(argc, argv, "n:u:l:r:b:s:t:vh")) != EOF )
	{
		switch (i)
		{
			case 'n': if ( strcmp(optarg, "ologin") == 0 )
					dologin=0;
				  else if ( strcmp(optarg, "orc") != 0 )
					print_usage(argv[0]);
				  /* Already handled above */
				  break;
			case 'u': if ( strcmp(optarg, "pper") != 0 )
					print_usage(argv[0]);
				  tokenize(upper_args, MAX_ARGS+1,
						  argv[optind++], " ");
				  upper_empty=0;
				  break;
			case 'l': if ( strcmp(optarg, "ower") == 0 ) {
				  	tokenize(lower_args, MAX_ARGS+1,
							argv[optind++], " ");
				  	lower_empty=0;
				  } else if ( strcmp(optarg, "ogin") == 0 ) {
					dologin=1;
				  } else
					print_usage(argv[0]);
				  break;
			case 'b': if ( strcmp(optarg, "ottom") ==0) 
					  stbottom=1;
				  else
					  print_usage(argv[0]);
				  break;

			case 'r': if ( strcmp(optarg, "cfile") != 0 )
					print_usage(argv[0]);
				  else /* Already handled above */
					++optind;
				  break;
			case 's': UU_lines=atoi(optarg);
				  break;
			case 't': xterm_title=optarg;
				  break;
			case 'v': printf("%s", version+4);
				  exit(0);
				  break;
			case 'h':
			default:  print_usage(argv[0]);
				  break;
		}
	}
	argv+=(optind-1);
#endif

#ifdef ORI
	/* Retrieve and save our passwd entry */
	if ( (pw=(struct passwd *)getpwuid(getuid())) == NULL ) {
		fprintf(stderr, 
		"Warning: Can't find your passwd entry; no utmp logging.\n");
		sleep(2);
	} else { /* Save the passwd entry for future reference */
		d_copy((char *)pw, (char *)&pwdata, sizeof(pwdata));
		pw=(&pwdata);
	}
#else
	pw=0;
#endif

	if ( tty_getmode(ttyfd) < 0 ) 
	{
		fprintf(stderr, "Can't get terminal settings.\n");
		exit(2);
	}
	(void) tty_raw(0);   /* Set the tty raw here to prevent lost input */

	if ( (ptr=init_vt100()) != NULL )
	{
		if ( tty_reset(0) < 0 )	
			(void) tty_sane(0);

		fprintf(stderr, "\rCan't initialize screen: %s\n", ptr);
		exit(3);
	}
#ifdef X_SUPPORT
#ifdef XTITLE
	/* Make the title bar the version string, strip extraneous info. */
	if ( xterm_title == NULL ) {
		strcpy(buffer, version+4);
		buffer[39]='\0';
		xterm_title=buffer;
	}
#endif
	/* This must be called before pty_open() */
	(void) event_init(stdin, stdout, xterm_title);
#endif /* X_SUPPORT */
	selection[0]='\0';

	if ( argv[1] ) {
		if ( upper_empty ) {
			for ( i=0; argv[i+1] && i<MAX_ARGS; ++i )
				upper_args[i]=argv[i+1];
			upper_args[i]=NULL;
		}
		if ( lower_empty ) {
			for ( i=0; argv[i+1] && i<MAX_ARGS; ++i )
				lower_args[i]=argv[i+1];
			lower_args[i]=NULL;
		}
	} else { // no args
		if ( upper_args[0] == NULL ) {
			if (((upper_args[0]=(char *)getenv("SHELL")) == NULL) ||
			     (*upper_args[0] == '\0') )
				upper_args[0]=SHELL;
			upper_args[1]=NULL;
		}
		if ( lower_args[0] == NULL ) {
			if (((lower_args[0]=(char *)getenv("SHELL")) == NULL) ||
			     (*lower_args[0] == '\0') )
				lower_args[0]=SHELL;
			lower_args[1]=NULL;
		}
	}
	if ( dologin ) {
		(void) insert_dash(upper_args);
		(void) insert_dash(lower_args);
	}
	//printf("upper: %s\n",upper_args[0]);
#ifdef NEED_INET_H
	signal(SIGCLD, SIG_IGN);
#endif

#ifdef ORI
	(void) remove_me();
#endif
	if ( (topfd=pty_open(upper_args, &toppid, UPPER)) < 0 )
	{
		end_vt100();
		switch (errno) {
		   case EIO:
		   case EPERM:
		   case ENOENT:
			fprintf(stderr, "No available pseudo terminals.\n");
			break;
			case EAGAIN:
			fprintf(stderr, "No more processes, try again later.\n");
			break;
		   default:
			perror("pty_open() error");
		}
		finish(0);
	} else if ( pw ) {
		(void) strcpy(upper_tty, tty_name);
#ifdef ORI
		(void) addutmp(pw->pw_name, pw->pw_uid, upper_tty);
#endif
	}

	if ( (bottomfd=pty_open(lower_args, &bottompid, LOWER)) < 0 )
	{
		end_vt100();
		switch (errno) {
		   case EIO:
		   case EPERM:
		   case ENOENT:
			fprintf(stderr, "No available pseudo terminals.\n");
			break;
			case EAGAIN:
			fprintf(stderr, "No more processes, try again later.\n");
			break;
		   default:
			perror("pty_open() error");
		}
		finish(0);
	} else if ( pw ) {
		(void) strcpy(lower_tty, tty_name);
#ifdef ORI
		(void) addutmp(pw->pw_name, pw->pw_uid, lower_tty); 
#endif
	}
	if (stbottom)
		thisfd=bottomfd;
	else thisfd=topfd;

#if defined(_POSIX_SOURCE) || defined(m88k)
#include <limits.h>
	/* This is lifted from Richard Stevens. -Thanks! */
#ifdef OPEN_MAX
	maxfds=OPEN_MAX;
#else
#define OPEN_MAX_GUESS 256 /* if OPEN_MAX is indeterminate */
                           /* this may be inadequate       */
	if ( (maxfds = sysconf(_SC_OPEN_MAX)) < 0) {
		maxfds=OPEN_MAX_GUESS;
	}
#endif
#else /* Not POSIX SOURCE */
#if defined(SOLARIS) || defined(HAVE_BSDTTY_H) || defined(HP_UX)
        maxfds=32;              /* Any comments?  This is a WAG */
#else
        //maxfds=getdtablesize();
        maxfds=FOPEN_MAX-1;
#endif
#endif /* _POSIX_SOURCE */

        /* Set select() timeout, and zero out the read mask */
#if 0
        tv.tv_sec=3;
        tv.tv_usec=0;
        tvptr=&tv;
#else
        tvptr=0;
#endif
	signal(SIGHUP, finish);
	signal(SIGINT, finish);
	signal(SIGQUIT, finish);
	signal(SIGTERM, finish);
	signal(SIGSEGV, finish);
#ifdef SIGBUS
	signal(SIGBUS, finish);
#endif
//#ifdef SIGWINCH
	signal(SIGWINCH, winch);
	//#endif
	//printf("DBG. XX. fd's: %d, %d\n", topfd, bottomfd );
	for ( SET_WIN(); (topok || bottomok); ){
			FD_ZERO(&read_mask);
			FD_SET(ttyfd, &read_mask);

			/* Make sure the children are still alive */
			if ( ! isalive() )
					break;

			if ( topok ){
					//printf("topok\n");
					FD_SET(topfd, &read_mask);
			}

			if ( bottomok ){
					//printf("bottomok\n");
					FD_SET(bottomfd, &read_mask);
			}

			errno = 0;
			//if ( (numready=select(maxfds, &read_mask, NULL, NULL, tvptr)) <= 0 ){
			if ( (numready=select(16, &read_mask, 0, 0, 0 )) <= 0 ){
					printf("Err. errno %d maxfd %d fd's: %d, %d\n", errno, maxfds, topfd, bottomfd );
					sleep(1);
					tvptr=0;
					if ( (numready=select(maxfds, &read_mask, NULL, NULL, tvptr)) <= 0 )
					{
#if 1                    /* Wallabong select() is buggy */
							//#ifndef NEED_INET_H                     /* Wallabong select() is buggy */
							switch (errno)
							{
									case EIO:    /* The program is finished. */
											break;
									case EINTR:  /* Probably SIGWINCH */
											break;
									default:        

											fprintf(stderr, "errno: %d\n",errno);
											perror("select() error");
											fprintf(stderr, "\r");
											break;
							}
					
							if ( errno != EINTR )
									finish(0);
							else
									continue;
#endif
					}
			}


			if ( FD_ISSET(ttyfd, &read_mask) )
			{
					do {
							int c;

							if ( (c=event_getc(&X_event)) == EOF )
									finish(0);
#ifdef VTMOUSE

							if ( X_event.happening ) {
									/* Work only on button press */
									if ( ! BUTTON_ISSET(X_event, RELEASE) ) {
											/* Mouse click in which winow? */
											if ( X_event.x <= WU_lines )
											{ 
													if ( topok )
															thisfd=topfd;
													SET_WIN();
											} else 
													if ( X_event.x > (WU_lines+1) )
													{ 
															if ( bottomok )
																	thisfd=bottomfd;
															SET_WIN();
													} else
															on_separator=X_event.x;

											if ( BUTTON_ISSET(X_event, BUTTON_2) ) {
													strcpy(selection, vt_getselbuf());
													write(thisfd, selection, strlen(selection));
											}
									} else if ( on_separator ) {
											move_bar(X_event.x-on_separator);
											on_separator=0;
									}
#ifdef REPORT_SELECTION
#ifdef ORI
									if ( (X_event.button_state&SELECTED) == SELECTED ) {
											vt_setsel(selection, BUFSIZ-1,
															X_event.selection.begin_row, 
															X_event.selection.end_row, 
															X_event.selection.begin_col, 
															X_event.selection.end_col); 
											vt_setselbuf(selection);
									}
#endif
#endif
							} else 
#endif
									if ( c )
											do_input(c);
					} while (terminal_input);
			}

			if  ( FD_ISSET(bottomfd, &read_mask) )
			{
					if ( (len=read(bottomfd, buffer, BUFSIZ)) <= 0 )
					{
							switch (errno)
							{
									case EIO: /*break;*/
									default:  if ( isalive() < 0 )
																finish(0);
							}
					}
					else {
							(void) vt_write(LOWER, buffer, len, &bottomfd);
							if ( thisfd == topfd )
									SET_WIN();
					}
			}

			if  ( FD_ISSET(topfd, &read_mask) )
			{
					if ( (len=read(topfd, buffer, BUFSIZ)) <= 0 )
					{
							switch (errno)
							{
									case EIO: /*break;*/
									default:  if ( isalive() < 0 )
																finish(0);
							}
					}
					else {
							(void) vt_write(UPPER, buffer, len, &topfd);
							if ( thisfd == bottomfd ) 
									SET_WIN();
					}
			}
	}
	finish(0);
	return(0);	
}

void reset_bar(sleeptime)
int sleeptime;
{
	sleep(sleeptime);
	vt_info(NULL);
}

/* Print out a help screen for the escapes */
void print_help()
{
	static char *help[] = {
"Escape commands: ", 
"	'-'	Shrink the current window",
"	'+'	Expand the current window",
"	'k'	Kill the current window",
"	'r'	Refresh the screen",
"	'c'	Copy selection",
"	'p'	Paste selection",
"	'x'	Lock the screen",
"	'h'	Show this help screen",
"	'q'	Quickly quit splitvt",
NULL
};
	vt_showscreen("Splitvt HELP screen:", help);
}

void normal_input(c)
char c;
{
	char message[BUFSIZ];
	int pid;
	static int param=0;

	if ( c == quote_c ) {
		read(ttyfd, &c, 1);
		goto writeit;
	} else if ( c == switch_c ) {
		if ( (thisfd == topfd) && bottomok )
			thisfd=bottomfd;
		else if ( topok )
			thisfd=topfd;
		SET_WIN();
	} else if ( c == command_c ) {
promptch:
		c=vt_prompt(PROMPT);
		switch (c) {
			/* Shrink current window */
			case '-': if ( ! param )
					param=1;
				  move_bar(thisfd == topfd ? -param : param);
				  param=0;
				  break;
			/* Grow current window */
			case '+': if ( ! param )
					param=1;
				  move_bar(thisfd == topfd ? param : -param);
				  param=0;
				  break;
			/* Kill a window */
			case 'k': sprintf(message, "Kill %s window? [Y/n]: ",
					(thisfd == topfd) ? "upper" : "lower");
				  switch(vt_prompt(message)) {
					case 'N':
					case 'n': break;
					/* Kill with hangup signal */
					default:  pid=((thisfd == topfd) ? 
							toppid : bottompid);
						  (void) kill(pid, SIGHUP);
						  break;
				  }
				  vt_info(NULL);
				  break;
#ifdef ORI
			/* Copy selection */
			case 'c': vt_getsel(CUR_WIN(), selection, BUFSIZ);
				  vt_setselbuf(selection);
				  reset_bar(1);
				  break;
			/* Paste selection */
			case 'p': strcpy(selection, vt_getselbuf());
				  write(thisfd, selection, strlen(selection));
				  break;
#endif
#ifdef LOCK
			/* Lock the screen */
			case 'x': vt_info("Enter password: ");
				  do_input=lock_screen;
				  break;
#endif
			/* Repaint the screen */
			case 'r': vt_redraw();
				  break;
			/* Quick exit */
			case 'q': finish(0);
				  break;
			/* Print a quick help screen */
			case '?':
			case 'h': print_help();
				  break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': /* Set numeric parameter */
				  param *= 10;
				  param += (c-'0');
				  goto promptch;
				  break;
			default:  break;
		}
	}
	else { writeit:
		write(thisfd, &c, 1);
	}
}

/* A better child checker. :)  It gathers the status of the child,
   rendering it free and un-zombied. :) */

static int isalive()
{
	int status;

#if ! defined(WNOHANG) || defined(NEED_INET_H)
	if ( topok )
		if (  kill(toppid, 0) < 0 )
		{
#ifdef ORI
			if ( pw ) 
				(void) delutmp(pw->pw_name, upper_tty);
#endif
			if ( thisfd == topfd )
				thisfd=bottomfd;
			(void) close(topfd);
			topok=0;
			SET_WIN();
		}

	if ( bottomok )
		if ( kill(bottompid, 0) < 0 )
		{
#ifdef ORI
			if ( pw ) 
				(void) delutmp(pw->pw_name, lower_tty);
#endif
			if ( thisfd == bottomfd )
				thisfd=topfd;
			(void) close(bottomfd);
			bottomok=0;
			SET_WIN();
		}

#else
#ifdef HAVE_WAIT4	/* For BSD 4.3 */
#define waitpid(pid, status, options)	wait4(pid, status, options, NULL)
#endif /* HAVE_WAIT4 */

	if ( topok )
		if ( waitpid(toppid, &status, WNOHANG) != 0 )
		{
#ifdef ORI
			if ( pw ) 
				(void) delutmp(pw->pw_name, upper_tty);
#endif
			if ( thisfd == topfd )
				thisfd=bottomfd;
			(void) close(topfd);
			topok=0;
			SET_WIN();
		}

	if ( bottomok )
		if ( waitpid(bottompid, &status, WNOHANG) != 0 )
		{
#ifdef ORI
			if ( pw ) 
				(void) delutmp(pw->pw_name, lower_tty);
#endif
			if ( thisfd == bottomfd )
				thisfd=topfd;
			(void) close(bottomfd);
			bottomok=0;
			SET_WIN();
		}
#endif
	if ( topok || bottomok )
		return(1);
	return(0);
}

	
/* Cleanup routine */
static void finish(sig)
int sig;
{
	/* Only call this routine after tty_getmode() has been called */
	/* The tty_reset() call flushes the tty's input buffers. */
	if ( tty_reset(0) < 0 )	
		(void) tty_sane(0);

	/* Reset the vt100 window */
	end_vt100();
	event_quit();

#ifdef ORI
	/* Reset our utmp entries */
	if ( pw && topok && upper_tty[0] )
		(void) delutmp(pw->pw_name, upper_tty);
	if ( pw && bottomok && lower_tty[0] )
		(void) delutmp(pw->pw_name, lower_tty);
	(void) replace_me();
#endif

	if ( sig )
		printf("Exiting due to signal: %d\n", sig);
	exit(sig);
}

/* Move the separator bar up and down.  We can do this now, because
   init_vt100() properly refreshes the screen (we hope) ;-)
*/

static void move_bar(howfar)
int howfar;
{
	int tmp_uulines;

	/* Don't redraw the screen if there is no movement on the bar */
	if ( ! howfar )
		return;

	tmp_uulines=UU_lines;
	UU_lines=WU_lines;
	UU_lines += howfar;	/* Positive to go down, negative to go up */
	init_vt100();		/* Reset the windows to the new size */

	/* Tell the running processes about the size change */
	if ( topok )
		pty_setwin(topfd, UPPER);
	if ( bottomok )
		pty_setwin(bottomfd, LOWER);
	UU_lines=tmp_uulines;
}	

/* Resize the window... unfortunately, this means that the
   current window is erased.  Oh well.. :)
   Ah hah!  As of 1.6.0, the window is refreshed. :)
 */

static void winch(sig)
int sig;
{
	char *ptr;

	signal(sig, winch);

	if ( (ptr=init_vt100()) != NULL ) {
		fprintf(stderr, "Can't resize window: %s. (exiting)\n", ptr);
		finish(0);
	} else
		SET_WIN();
	if ( topok )
		pty_setwin(topfd, UPPER);
	if ( bottomok )
		pty_setwin(bottomfd, LOWER);
}

static int insert_dash(args)
char *args[];
{
	char *temp;

	if ( (temp=(char *)malloc(strlen(args[0])+2)) == NULL )
		return(-1);
	sprintf(temp, "-%s", args[0]);
	args[0]=temp;		/* Possible memory leak.. who cares? */
	return(0);
}
