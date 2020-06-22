/* Miscellaneous system dependent routines for splitsh */

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<signal.h>


#ifdef HAVE_TERMIO_H
#ifndef MLIB
#include	<termio.h>
#endif
#else
#include	<sys/ioctl.h>
#endif  /* HAVE_TERMIO_H */

#ifdef HAVE_BSDTTY_H
#include	<sys/bsdtty.h>
#ifndef TIOCNOTTY
#define TIOCNOTTY	_IO('t', 113)	/* HP-UX void tty definition */
#endif
#endif /* HAVE_BSDTTY_H */

#ifdef NEED_INET_H
/*#define STTY_HACK*/
#endif

/*
 * Initialize a pty, fork a command running under it, and then 
 * return the master file descriptor
 */

extern int WU_lines, WL_lines, W_columns;	/* From vt100.c */
int tty_reset(int fd);

#define UPPER	0		/* Upper window definition */
#define LOWER	1		/* Lower window definition */

extern char **environ;// = {0};


int pty_open( char *argv[], int *childpid, int win )		/* win :0 for upper, 1 for lower */
{

	void dropctty(), pty_setwin();
	int get_master_pty(), get_slave_pty();
	char *get_ttyname(), *myputenv();

	char LINES[12], COLUMNS[12], SPLITVT[24];
	int returnfd, slave_fd;

	/* Get the master pty file descriptor */
	if ( (returnfd=get_master_pty()) < 0 )
		return(-1);

	/* Fork and go! */
	if ( ((*childpid)=fork()) < 0 )
		return(-1);
	else if ( (*childpid) == 0 )
	{
		dropctty();	/* Lose controlling tty */

		if ( (slave_fd=get_slave_pty()) < 0 )
		{
			perror("Can't open slave tty");
			exit(128);
		}
		close(0); close(1); close(2);
		dup(slave_fd); dup(slave_fd); dup(slave_fd);
		close(slave_fd); close(returnfd);

		/* Reattatch the new tty as the controlling terminal */
		/* Under old UNIX, just opening the new tty after
		   losing the controlling tty is good enough.
		   Under newer Unices, it requires an ioctl().  */
#if 1
		(void) ioctl(0, TIOCSCTTY, 0);
#endif

		/* Set the lines and columns on the new tty */
#ifdef TIOCGWINSZ	/* We don't want to set the environment if possible */
		pty_setwin(0, win);
#else
		if ( win == UPPER )
			sprintf(LINES, "LINES=%d", WU_lines);
		else
			sprintf(LINES, "LINES=%d", WL_lines);
		myputenv(LINES);
		sprintf(COLUMNS, "COLUMNS=%d", W_columns);
		myputenv(COLUMNS);
#endif /* TIOCGWINSZ */
		/* Set the SPLITVT environment variable for shell scripts */
		if ( win == UPPER )
			sprintf(SPLITVT, "SPLITVT=upper");
		else
			sprintf(SPLITVT, "SPLITVT=lower");
		myputenv(SPLITVT);
		myputenv("TERM=vt100");	/* Put the new TERM in the env. */

#ifdef SIGTSTP
		signal(SIGTSTP, SIG_IGN);
#endif
#if 0
		system("stty sane echo echoe intr '^C' erase '^H'");
#else
		(void) tty_reset(0);
#endif
		/* "touch" the tty so 'w' reports proper idle times */
		(void) utime(get_ttyname(), NULL);

		/* Set our uid to our real uid if necessary */
		//(void) setuid(getuid());
			
		/* Run the requested program, with possible leading dash. */
		//printf("exec..> %s\n",argv[0]);
		execve(((*argv[0] == '-') ? argv[0]+1 : argv[0]), (char* const*)argv,(char* const*)environ);

		printf("ERROR: exec..> %s\n",argv[0]);
		perror(argv[0]);
		exit(255);
	}
	return(returnfd);
}



/*
 * Pseudo-terminal routines for Unix System V Release 3.2 and BSD4.2-3
 */


extern int errno;
int master_fd;

char tty_name[64]={'\0'};
char pty_name[64]={'\0'};

char *get_ttyname()
{
	if ( tty_name[0] )
		return(tty_name);
	return(NULL);
}

#if 0	/* IRIX System V for SGI machines */
//#ifdef IRIX	/* IRIX System V for SGI machines */

extern char *_getpty();

int get_master_pty()
{

	char 	*ttyptr;

	ttyptr=_getpty(&master_fd, O_RDWR, 0600, 0);
	if ( ttyptr == NULL || strlen(ttyptr)+1 > sizeof(tty_name) )
		return(-1);
	else
		strcpy(tty_name, ttyptr);

	return(master_fd);
}

/*
 * Open the slave half of a pseudo-terminal.
 */

int get_slave_pty()
{
	int	slave_fd;
	char	*slavename;

	slavename=tty_name;

	if (slavename == NULL) {
		close(master_fd);
		return(-1);
	}

	if ( (slave_fd=open(slavename, O_RDWR)) < 0 )	/* open the slave */
	{
		close(master_fd);
		return(-1);
	}

	return(slave_fd);
}
#else /* ! IRIX */


//#if defined(SOLARIS) || defined(linux)		/* System V.4 pty routines from W. Richard Stevens */
#if 1

#ifdef SOLARIS
#include <stropts.h>
#endif

#define DEV_CLONE	"/dev/ptmx"

extern char *ptsname();

int get_master_pty()
{

	char 	*ttyptr;

	if ( (master_fd=open(DEV_CLONE, O_RDWR)) < 0 )
		return(-1);

	if ( grantpt(master_fd) < 0 )	/* grant access to slave */
	{
		close(master_fd);
#ifdef DEBUG
		perror("grantpt()");
#endif
		return(-1);
	}

	if ( unlockpt(master_fd) < 0 )	/* clear slave's lock flag */
	{
		close(master_fd);
		return(-1);
	}

	ttyptr=ptsname(master_fd);

	//printf("ttyname: %s\n",tty_name);

	if ( ttyptr == NULL || strlen(ttyptr)+1 > sizeof(tty_name) )
	{
		close(master_fd);
		return(-1);
	}
	else
		strcpy(tty_name, ttyptr);

	return(master_fd);
}

/*
 * Open the slave half of a pseudo-terminal.
 */

int get_slave_pty()
{
	int	slave_fd;
	char	*slavename;

	//printf("ttyname XX: %s\n",tty_name);
	slavename=tty_name;

	if ( (slave_fd=open(slavename, O_RDWR)) < 0 )	/* open the slave */
	{
		close(master_fd);
		return(-1);
	}

#ifdef SOLARIS
	if ( ioctl(slave_fd, I_PUSH, "ptem") < 0 )
	{
		close(master_fd);
		close(slave_fd);
		return(-1);
	}

	if ( ioctl(slave_fd, I_PUSH, "ldterm") < 0 )
	{
		close(master_fd);
		close(slave_fd);
		return(-1);
	}

	if ( ioctl(slave_fd, I_PUSH, "ttcompat") < 0 )
	{
		close(master_fd);
		close(slave_fd);
		return(-1);
	}
#endif

	return(slave_fd);
}

#else	/* BSD, Sun/OS, AIX, ULTRIX, HP-UX, AT&T SYSV */

#include	<setjmp.h>

#ifndef X_OK
#define	R_OK	4	/* Test for Read permission */
#define	W_OK	2	/* Test for Write permission */
#define	X_OK	1	/* Test for eXecute permission */
#endif  /* X_OK */

jmp_buf next;

void trynext()
{
	longjmp(next, 2);
}


int get_master_pty()
{
	int i, master_fd;
	char *ptr;
	struct stat statbuff;
#ifdef PTYCHAR
	static char ptychar[]=PTYCHAR;			/* X */ 
	static char hexdigit[]=HEXDIGIT;		/* Y */
#else
	static char ptychar[]="pqrstuvwxyzPQRST";	/* X */ 
	static char hexdigit[]="0123456789abcdef";	/* Y */
#endif

	for (ptr=ptychar; *ptr != 0; ptr++)
	{
		strcpy(pty_name, "/dev/ptyXY");
		pty_name[8]=(*ptr);  /* X */
		pty_name[9]='0';   /* Y */

		if ( stat(pty_name, &statbuff) < 0 )
			break;
#ifdef OLDDEBUG
		fprintf(stderr, "statted.\n");
#endif
		i=(-1);		/* Initialize i */

		/* Set a time limit for the open */
		if ( setjmp(next) == -1 )
			return(-1);
		signal(SIGALRM, trynext);

		for ( ++i; hexdigit[i]; ++i)
		{
			pty_name[5]='p';
			pty_name[9]=hexdigit[i];

			alarm(2);	/* Set an open timeout */

			if ( (master_fd=open(pty_name, O_RDWR)) >= 0 )
			{
				alarm(0); 	/* Reset the alarm */

				pty_name[5]='t';
				sprintf(tty_name, "%s", pty_name);
#ifdef OLDDEBUG
				fprintf(stderr, "tty: %s\n", tty_name);
#endif
				if ( access(tty_name, R_OK|W_OK) == 0 ) {
					signal(SIGALRM, SIG_DFL);
					return (master_fd);
				} else {
					pty_name[5]='p';
					(void) close(master_fd);
				}
			}
			/* reset the alarm */
			alarm(0);
		}
	}
	return(-1);
}


/* Open the slave half of a pseudo-terminal. */

int get_slave_pty()
{
	int slave_fd;

	if ( (slave_fd=open(tty_name, O_RDWR)) < 0 )
	{
		close(master_fd);
		return(-1);
	}
	return(slave_fd);
}

#endif  /* if linux or SOLARIS */
#endif  /* if IRIX */


/* These are the binary data functions that I am using instead of 
   bcopy() and bzero(), written by Richard A. O'Keefe.
     Thanks!
*/

void d_copy(src, dst, len)
    register char *src, *dst;
    register int len;
    {
	while (--len >= 0) *dst++ = *src++;
    }

void d_zero(dst, len)
    register char *dst;
    register int len;
    {
	while (--len >= 0) *dst++ = 0;
    }



/* Here are the Terminal manipulation routines...  */


/* Code to disassociate from my tty. Yay! :) */

void dropctty()
{
	int fd;

#if defined(_POSIX_SOURCE) || defined(SOLARIS) || \
				defined(__386BSD__) || defined(__FreeBSD__)
	setsid();		/* The POSIX solution is simple. :) */
#else
#ifdef TIOCNOTTY  /* We want to get HP-UX, BSD, and Sun/OS here */
	//setpgrp(0, 0);

#ifndef CIBAUD   /* Sun/OS doesn't need to do TIOCNOTTY.  */
	if ( (fd=open("/dev/tty", O_RDWR)) > (-1) ) 
	{
		if (ioctl(fd, TIOCNOTTY, 0) < 0)
		{
			perror("ioctl TIOCNOTTY error");
			fprintf(stderr, "\r");
		}
		close(fd);
	}
#endif /* CIBAUD */
#else /*  SYSV 	*/
	//setpgrp();
#endif /* TIOCNOTTY */
#endif /* _POSIX_SOURCE */
}


#if 1
//#ifdef HAVE_TERMIO_H

/* Get the modes of the controlling tty and save them.  Saves
   ttymodes in tty_mode and returns -1 if ioctl fails. */

struct termio tty_mode;  /* Save tty mode here */
static int tty_init=0;

int tty_getmode(fd)
int fd;
{
	d_zero((char *)&tty_mode, sizeof(struct termio));
	tty_init=1;	/* Flag: we have initialized the tty_mode struct */

	if ( ! isatty(fd) )
		return(0);

#ifdef OLDDEBUG
	fprintf(stderr, "Getting tty modes for tty_mode.\r\n");
#endif

	if (ioctl(fd, TCGETA, (char *) &tty_mode) < 0)
	{
#ifdef DEBUG
		perror("tty_getmode(): ioctl error");
#endif
		return(-1);  
	}

	return(0);
}


/* Set a tty to a sane mode */

int tty_sane(fd)
int fd;
{
	struct termio temp_mode;

	if ( ! isatty(fd) )
		return(0);

	if ( ! tty_init )
	{
		if (ioctl(fd, TCGETA, (char *) &tty_mode) < 0)
			return(-1);  
	}

#ifdef SEVEN_BIT
	temp_mode.c_iflag=(tty_mode.c_iflag|(BRKINT|IGNPAR|ISTRIP|ICRNL|IXON));
	temp_mode.c_oflag=(tty_mode.c_oflag|(OPOST|ONLCR));
#else
	temp_mode.c_iflag=(tty_mode.c_iflag|(BRKINT|IGNPAR|ICRNL|IXON));
	temp_mode.c_cflag=(tty_mode.c_cflag|(CS8|CREAD));
#endif
	temp_mode.c_lflag=(tty_mode.c_lflag|(ISIG|ICANON|ECHO|ECHOE|ECHOK));
	temp_mode.c_cflag=(tty_mode.c_cflag|(CS7|PARENB|CREAD));
	temp_mode.c_cc[VERASE]=('H'^64);
	temp_mode.c_cc[VKILL]=('U'^64);
	temp_mode.c_cc[VQUIT]=('\\'^64);
	temp_mode.c_cc[VINTR]=('C'^64);
	temp_mode.c_cc[VEOF]=('D'^64);
	
	/* TCSETAW is important for letting tty input drain. */
	if ( ioctl(fd, TCSETAW, (char *)&temp_mode) < 0 )
	{
#ifdef DEBUG
		perror("Can't set tty modes");
#endif
		return(-1);
	}

	return(0);
}


/* Set a terminal in raw mode */

int tty_raw(fd)
int fd;     /* of tty device */
{
	struct termio temp_mode;

	if ( ! tty_init )
		return(-1);

	if ( ! isatty(fd) )
		return(0);

	if ( ioctl(fd, TCGETA, (char *)&temp_mode) < 0 )
		return(-1);

#ifdef SEVEN_BIT
	temp_mode.c_iflag=(IGNBRK | ISTRIP);	/* turn off all input control */
#else
	temp_mode.c_iflag=(IGNBRK);		/* turn off all input control */
#endif
	temp_mode.c_oflag &= ~(OLCUC | ONLCR | OCRNL | ONLRET);
					/* disable output post-processing */
	temp_mode.c_lflag = 0;
	temp_mode.c_cc[VMIN]=1;		/* 1 or more chars satisfy read */
	temp_mode.c_cc[VTIME]=0;	/* 10'ths of seconds between chars */

	/* TCSETAW is important for letting tty input drain. */
	if (ioctl(fd, TCSETAW, (char *) &temp_mode) < 0)
		return(-1);
	return(0);
}


/* Restore terminal's mode to whatever it was on the most
   recent call to the tty_getmode() function. */

int tty_reset(fd)
int fd;
{
	if ( ! tty_init )
		return(-1);

	if ( ! isatty(fd) )
		return(0);

	/* TCSETAW is important for letting tty input drain. */
	if (ioctl(fd, TCSETAW, (char *) &tty_mode) < 0)
		return(-1);
	return(0);
}

#else  /* no /usr/include/termio.h */
#ifdef NEED_COMPAT_H		/* FreeBSD needs this */
#include <sys/ioctl_compat.h>
#endif /* NEED_COMPAT_H */

/* Set a tty to a sane mode */

int tty_sane(fd)
int fd;
{
	struct sgttyb temp_mode;

	if ( ! isatty(fd) )
		return(0);

	if (ioctl(fd, TIOCGETP, (char *) &temp_mode) < 0)
		return(-1);

	temp_mode.sg_flags|=ECHO;
	
	if (ioctl(fd, TIOCSETP, (char *) &temp_mode) < 0)
		return(-1);

	return(0);
}



/* Get the modes of the controlling tty and save them.  Saves
   ttymodes in tty_mode and returns 1 if ioctl fails. */

static struct sgttyb	tty_mode;	/* save tty mode here */

int tty_getmode(fd)
int fd;
{
	if ( ! isatty(fd) )
		return(0);

	if (ioctl(fd, TIOCGETP, (char *) &tty_mode) < 0)
		return(-1);

	return(0);
}

/*
 * Put a terminal device into RAW mode with ECHO off.
 * Before doing so we first save the terminal's current mode,
 * assuming the caller will call the tty_reset() function
 * (also in this file) when it's done with raw mode.
 */

int tty_raw(fd)
int	fd;		/* of terminal device */
{
	struct sgttyb	temp_mode;

	if ( ! isatty(fd) )
		return(0);

	temp_mode = tty_mode;

	temp_mode.sg_flags |= RAW;	/* turn RAW mode on */
	temp_mode.sg_flags &= ~ECHO;	/* turn ECHO off */
	if (ioctl(fd, TIOCSETP, (char *) &temp_mode) < 0)
		return(-1);

	return(0);
}

/*
 * Restore a terminal's mode to whatever it was on the most
 * recent call to the tty_getmode() function above.
 */

int tty_reset(fd)
int	fd;		/* of terminal device */
{
	if ( ! isatty(fd) )
		return(0);

	if (ioctl(fd, TIOCSETP, (char *) &tty_mode) < 0)
		return(-1);

	return(0);
}
#endif /* HAVE_TERMIO_H */


/* Set the pty window size to the size of the virtual window */

#ifdef TIOCSWINSZ

static struct /* winsize */ {
		unsigned short	ws_row;		/* rows, in characters */
		unsigned short	ws_col;		/* columns, in characters */
		unsigned short	ws_xpixel;	/* horizontal size - not used */
		unsigned short	ws_ypixel;	/* vertical size - not used */
	} mywinz;

void pty_setwin(fd, win)
int fd;			/* The pty file descriptor */
int win;		/* 0 for upper, 1 for lower window */
{
	if ( win == UPPER )
		mywinz.ws_row=WU_lines;
	else
		mywinz.ws_row=WL_lines;
	mywinz.ws_col=W_columns;
	mywinz.ws_xpixel=0;
	mywinz.ws_ypixel=0;
	(void) ioctl(fd, TIOCSWINSZ, &mywinz);
}

#else
void pty_setwin(fd, win)
int fd;
int win;
{
	/* Bogus routine */
}
#endif /* TIOCSWINSZ */

/*
 * Write "n" bytes to a descriptor.
 * Use in place of write() when fd is a stream socket.
 */

int writen(fd, ptr, nbytes)
register int	fd;
register char	*ptr;
register int	nbytes;
{
	int	nleft, nwritten;

	nleft = nbytes;
	while (nleft > 0) {
		nwritten = write(fd, ptr, nleft);
		if (nwritten <= 0)
			return(nwritten);		/* error */

		nleft -= nwritten;
		ptr   += nwritten;
	}
	return(nbytes - nleft);
}


/* 
   A function to put strings in the environment using malloc(). 
   Returns a pointer to the environment string or NULL if malloc() fails.
 */

char *myputenv(string)
char *string;
{
//	extern char **environ;	/* The process environment strings */

	char *newptr, **envptr;
	char *tmptr, temp[BUFSIZ];
	int   distance, n=0;

	for ( distance=0; ((*(string+distance)) && 
		          ((*(string+distance)) != '=')); ++distance );
	if ( ! (*(string+distance)) )
		return(NULL);
	else
		++distance;
								
	if ( (newptr=(char *)malloc(strlen(string)+1)) == NULL )
		return(NULL);
	else
		strcpy(newptr, string);

	for ( envptr=environ; *envptr; ++envptr, ++n ) {
		if ( strncmp(*envptr, string, distance) == 0 ) {
			*envptr=newptr;
			return(newptr);
		}
	}

	*envptr=newptr;
	++envptr;
	*envptr=NULL;
	
	return(newptr);
}


/* * * * * * * Routines to parse a line into an array of tokens * * * * * * */

static int istoken(c, tokens)
char c;
char *tokens;
{
	while ( *tokens ) {
		if ( c == *(tokens++) )
			return(1);
	}
	return(0);
}

/* This version of tokenize is destructive to the line it parses. */

void tokenize(array, size, line, tokens)
char *array[];
int size;
char *line;
char *tokens;
{
	char *head, *ptr;
	int i=0;

	for ( head=line; *line && i < size-2; ) {
		if ( istoken(*line, tokens) ) {
			*(line++)='\0';
			array[i++]=head;
			while ( istoken(*line, tokens) )
				++line;
			head=line;
		} else
			++line;
	}
	array[i++]=head;
	array[i]=NULL;
}


/* Return the pathname of the command, or NULL if it's not in our PATH */
/* Warning: We use a static buffer that is overwritten at each invocation. */

char *pathsearch(command, secure)
char *command;
int secure;
{
#ifndef S_IFREG
#define S_IFREG 0100000
#endif
	char *path, *newpath, *paths[256];
	static char buffer[1024];
	int i;
	struct stat sb;

	if ( (path=(char *)getenv("PATH")) == NULL )
		return(NULL);
	if ( (newpath=(char *)malloc(strlen(path)+1)) == NULL )
		return(NULL);
	strcpy(newpath, path);

	tokenize(paths, 256, newpath, ":");
	for ( i=0; paths[i]; ++i ) {
		if ( secure && paths[i][0] != '/' ) {
			/* Only allow full pathnames */
			continue;
		}

		/* Make sure the file exists */
		sprintf(buffer, "%s/%s", paths[i], command);
		if ( stat(buffer, &sb) != 0 )
			continue;

		/* Make sure it's a regular file */
		if ( (sb.st_mode & S_IFREG) != S_IFREG )
			continue;

		/* Now make sure we can execute it */
		if ( sb.st_uid == getuid() ) {
			/* User execute permission? */
			if ( sb.st_mode & 0100 )
				break;
		} else if ( sb.st_gid == getgid() ) {
			/* Group execute permission? */
			if ( sb.st_mode & 0010 )
				break;
		} else {
			/* Other execute permission? */
			if ( sb.st_mode & 0001 )
				break;
		}
	}
	(void) free(newpath);

	if ( paths[i] == NULL )
		return(NULL);
	else
		return(buffer);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

/* Safe version of popen() and pclose(), they reset the uid and gid. */

FILE *safe_popen(command, type)
char *command;
char *type;
{
	char *argv[4];
	int pipe_fds[2];
	int rw, child;

	if ( strcmp(type, "r") == 0 )
		rw=0;	/* READ access for parent */
	else if ( strcmp(type, "w") == 0 )
		rw=1;	/* WRITE access for parent */
	else
		return(NULL);	/* Unsupported type */

	if ( pipe(pipe_fds) < 0 ) {
		return(NULL);
	}

	switch(fork()) {
		case 0:  /* Child runs here */
			/* Reassign file descriptors */
			if ( rw == 0 ) {
				close(1); dup(pipe_fds[1]); close(0);
			} else {
				close(0); dup(pipe_fds[0]); close(1);
			}
			close(pipe_fds[0]); close(pipe_fds[1]); 

			/* Set our uid to our real uid if necessary */
			(void) setuid(getuid());
			
			/* Run the requested program */
			argv[0]="/bin/sh";
			argv[1]="-c";
			argv[2]=command;
			argv[3]=NULL;
			//fprintf(stderr,"execing\n");
			execve(argv[0], (char* const*)argv,(char* const*)environ);
			fprintf(stderr, "Can't execute %s: ", argv[0]);
			perror("");
			exit(255);

		case -1: /* fork() error */
			close(pipe_fds[0]);
			close(pipe_fds[1]);
			return(NULL);
			break;

		default: /* Parent runs */
			break;
	}
	if ( rw == 0 ) 
		close(pipe_fds[1]);
	else
		close(pipe_fds[0]);
	return(fdopen(pipe_fds[rw], type));
}

int safe_pclose(pipefp)
FILE *pipefp;
{
	int status;

	/* Close the pipe */
	fclose(pipefp);

	/* Wait for the child to terminate */
	wait(&status);
	return(status);
}
