
/*  utmp.c    Shareware Copyright by Sam Lantinga	10/6/93	*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<utmp.h>
#include	<stdio.h>
#include	<string.h>

#ifdef DEBUG_UTMP
#undef  UTMP_FILE
#define UTMP_FILE  "/tmp/utmp"
#else
#ifndef UTMP_FILE
#define UTMP_FILE  "/etc/utmp"
#endif /* UTMP_FILE */
#endif /* DEBUG_UTMP */


/* Remove us from the utmp file, saving our entry to replace later */

static struct utmp saved_utmp;
static int utmp_saved=0;
static char saved_tty[128];

int remove_me()
{
	struct utmp ut;
	char *tty;
	time_t now;

	if ( ! isatty(0) )
		return(-1);

	tty=(char *)ttyname(0);
	if ( tty == NULL || strlen(tty)+1 > sizeof(saved_tty) )
		return(-1);

	/* Retrieve our utmp record */
	(void) time(&now);
	if ( get_utmp(tty, &ut) == 0 ) {
		/* Save the utmp entry and tty pathname */
		utmp_saved=1;
		d_copy((char *)&ut, (char *)&saved_utmp, sizeof(ut));
		strcpy(saved_tty, tty);

		/* Clean out the entry and return */
		ut.ut_name[0]='\0';
		ut.ut_time=now;
#ifdef USER_PROCESS
		ut.ut_type = DEAD_PROCESS;
#endif
#ifdef HAVE_UTHOST
		ut.ut_host[0]='\0';
#endif
		return(set_utmp(tty, &ut));
	}
	/* Nothing to clean out, good. */
	return(0);
}


int replace_me()
{
	if ( utmp_saved )
		return(set_utmp(saved_tty, &saved_utmp));
	return(0);
}
	
int get_utmp(tty, save)
char *tty;
struct utmp *save;
{
	int fd;
	char *ttyptr;
	struct utmp ut;

	/* See if we can open the utmp file */
	if ( (fd=open(UTMP_FILE, O_RDWR)) < 0 )
		return(-1);

	/* Get the ttyxy form of the tty pathname if possible. */
	if ( *tty == '/' ) {
		for ( ttyptr=(tty+1); *ttyptr; ++ttyptr ) {
			if ( *ttyptr == '/' )
				break;
		}
		if ( *ttyptr == '/' )
			++ttyptr;
	} else
		ttyptr=tty;

	while (read(fd,(char *) &ut, sizeof(ut)) == sizeof(ut)) {
  		if (strncmp(ttyptr, ut.ut_line, sizeof(ut.ut_line)) == 0) {
			/* Break out; we've found our entry! */
			if ( save )
				d_copy((char *)&ut, save, sizeof(ut));
			close(fd);
			return(0);
    		}
  	}
	/* We never found an entry for our tty */
	close(fd);
	return(-1);
}

int set_utmp(tty, save)
char *tty;
struct utmp *save;
{
	int fd, found=0;
	char *ttyptr;
	struct utmp ut;

	/* See if we can open the utmp file */
	if ( (fd=open(UTMP_FILE, O_RDWR)) < 0 )
		return(-1);

	/* Get the ttyxy form of the tty pathname if possible. */
	if ( *tty == '/' ) {
		for ( ttyptr=(tty+1); *ttyptr; ++ttyptr ) {
			if ( *ttyptr == '/' )
				break;
		}
		if ( *ttyptr == '/' )
			++ttyptr;
	} else
		ttyptr=tty;

	while (read(fd,(char *) &ut, sizeof(ut)) == sizeof(ut)) {
  		if (strncmp(ttyptr, ut.ut_line, sizeof(ut.ut_line)) == 0) {
			found=1;
			lseek(fd, -(long)sizeof(struct utmp), 1);
     			break;
    		}
  	}

	/* Add a new entry to the utmp file if we can't find our entry */
	if ( ! found )
  	{ /* Reopen to avoid a race with other end-of-utmp entries. */
   		(void) close(fd);
   		if ( (fd=open(UTMP_FILE, (O_RDWR|O_APPEND))) < 0 )
     			return -1;
  	}

 	if (write(fd, (char *)save, sizeof(*save)) != sizeof(*save)) {
   		(void) close(fd);
   		return -1;
  	}
 	return(close(fd));
}

	
/* Set up a utmp entry and tty for a user */

int addutmp(user, uid, tty)
char *user;		/* The user to add to the utmp file */
int uid;		/* The uid corresponding to user */
char *tty;		/* /dev/ttyxx */
{
	struct stat sb;
	struct utmp ut;
	char *ttyptr;

	/* Retrieve any existing utmp entry */
	d_zero((char *)&ut, sizeof(ut));
	(void) get_utmp(tty, &ut);

	/* Get the ttyxy form of the tty pathname if possible. */
	if ( *tty == '/' ) {
		for ( ttyptr=(tty+1); *ttyptr; ++ttyptr ) {
			if ( *ttyptr == '/' )
				break;
		}
		if ( *ttyptr == '/' )
			++ttyptr;
	} else
		ttyptr=tty;

	/* Customize the utmp entry */
	strncpy(ut.ut_name, user, sizeof(ut.ut_name)-1);
	ut.ut_name[sizeof(ut.ut_name)-1]='\0';
	strncpy(ut.ut_line, ttyptr, sizeof(ut.ut_line)-1);
	ut.ut_line[sizeof(ut.ut_line)-1]='\0';
#ifdef USER_PROCESS
	ut.ut_type=USER_PROCESS;
	ut.ut_pid=getpid();
#endif
#if defined(HAVE_UTHOST)
	/* remove_me() should be called before this function */
	if ( utmp_saved ) {
		strncpy(ut.ut_host, saved_utmp.ut_host, sizeof(ut.ut_host)-1);
		ut.ut_host[sizeof(ut.ut_host)-1]='\0';
	}
#endif
	(void) time(&ut.ut_time);

#if !defined(SOLARIS) && !defined(IRIX)
	/* Solaris and Irix machines do this automatically */
	/* Change the ownership and mode of the tty */
	if ( stat(tty, &sb) == 0 ) {
		(void) chmod(tty, 0620);  /* crw--w---- */
		(void) chown(tty, uid, sb.st_gid);
	}
#endif
	return(set_utmp(tty, &ut));
}
	

/* End a utmp entry and tty for a user and a tty */

int delutmp(user, tty)
char *user;
char *tty;		/* /dev/ttyxx */
{
	struct stat sb;
	struct utmp ut;
	int retval=0;

	/* Retrieve any existing utmp entry */
	d_zero((char *)&ut, sizeof(ut));
	if ( get_utmp(tty, &ut) == 0 ) {
		/* Clear the utmp entry */
		ut.ut_name[0]='\0';
#ifdef USER_PROCESS
		ut.ut_type=DEAD_PROCESS;
#endif
#if defined(HAVE_UTHOST)
		ut.ut_host[0]='\0';
#endif
		(void) time(&ut.ut_time);
		retval=set_utmp(tty, &ut);
	}

#if !defined(SOLARIS) && !defined(IRIX)
	/* Solaris and Irix machines do this automatically */
	/* Reset the owner and mode of the tty */
	if ( stat(tty, &sb) == 0 ) {
		(void) chmod(tty, 0666);	/* crw-rw-rw- */
		(void) chown(tty, 0, sb.st_gid);
	}
#endif
	return(retval);
}


