
/* Routines to parse the ~/.splitvtrc file and set default options */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <pwd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "splitvt.h"

#define SPLITVTRC "/.splitvtrc"

extern char *myputenv();  /* Portable setenv() function in misc.c */

/* These are used only here in this file. */
char *startupfile=NULL;
char *rcfile_buf;

static int lineno=0;	/* The current line in the startup file */


static void warn(message)
char *message;
{
	fprintf(stderr, "Warning in %s, line %d\n", rcfile_buf, lineno);
	fprintf(stderr, "\t%s\n", message);
	sleep(2);
}

static char extract(arg)	/* get a char from x/^x format */
char *arg;
{
	if ( ! *arg ) {
		warn("Couldn't extract control character");
		return('\0');
	}
	if ( *arg == '^' ) {
		++arg;
		if ( ! *arg ) {
			warn("Couldn't extract control character");
			return('\0');
		}
		if ( islower(*arg) )
			*arg=toupper(*arg);
		return(*arg-'@');
	}
	return(*arg);
}


static void set_something(args)
char *args[];
{
	int i;

	if ( ! args[1] ) {
		warn("No argument to 'set'");
		return;
	}
	if ( strcmp(args[1], "command_char") == 0 ) {
		if ( ! args[2] ) {
			warn("No command_char to set");
			return;
		}
		command_c=extract(args[2]);
	} else if ( strcmp(args[1], "switch_char") == 0 ) {
		if ( ! args[2] ) {
			warn("No switch_char to set");
			return;
		}
		switch_c=extract(args[2]);
	} else if ( strcmp(args[1], "quote_char") == 0 ) {
		if ( ! args[2] ) {
			warn("No switch_char to set");
			return;
		}
		quote_c=extract(args[2]);
	} else if ( strcmp(args[1], "upper_lines") == 0 ) {
		if ( ! args[2] ) {
			warn("No number of lines to set");
			return;
		}
		if ( (i=atoi(args[2])) == 0 ) {
			warn("Invalid number of lines");
			return;
		} else
			UU_lines=i;
	} else if ( strcmp(args[1], "login") == 0 ) {
		if ( ! args[2] )
			warn("Usage: set login [on|off]\n");
		else if ( strcmp(args[2], "on") == 0 )
			dologin=1;
		else if ( strcmp(args[2], "off") == 0 )
			dologin=0;
		else
			warn("Usage: set login [on|off]\n");
	} else if ( strcmp(args[1], "bottom") == 0 ) {
		if ( ! args[2] )
			warn("Usage: set bottom [on|off]\n");
		else if ( strcmp(args[2], "on") == 0 )
			stbottom=1;
		else if ( strcmp(args[2], "off") == 0)
			stbottom=0;
		else
			warn("Usage set bottom [on|off]\n");
	} else
		warn("Invalid parameter to 'set'");
}

static void set_argv(args)
char *args[];
{
	int i;

	if ( ! args[1] ) {
		warn("Nothing to run");
		return;
	}
	if ( (*args[1] == '-') && (strlen(args[1]) > 1) ) {
		if ( strcmp(&args[1][1], "upper") == 0 ) {
			for ( i=2; args[i] && i-2 < MAX_ARGS; ++i ) {
				if ( (upper_args[i-2]=
				(char *)malloc(strlen(args[i])+1)) == NULL ) {
					perror("malloc");
					exit(5);
				}
				strcpy(upper_args[i-2], args[i]);
			}
			upper_args[i-2]=NULL;
		} else if ( strcmp(&args[1][1], "lower") == 0 ) {
			for ( i=2; args[i] && i-2 < MAX_ARGS; ++i ) {
				if ( (lower_args[i-2]=
				(char *)malloc(strlen(args[i])+1)) == NULL ) {
					perror("malloc");
					exit(5);
				}
				strcpy(lower_args[i-2], args[i]);
			}
			lower_args[i-2]=NULL;
		} else
			warn("Invalid argument to 'run'");
		return;
	}

	/* Straight command line for both upper and lower windows */
	for ( i=1; args[i] && i-1 < MAX_ARGS; ++i ) {
			if ( ((upper_args[i-1]=(char *)malloc(strlen(args[i])+1)) == NULL) ||
			     ((lower_args[i-1]=(char *)malloc(strlen(args[i])+1)) == NULL) ) {
				perror("malloc");
				exit(5);
			}
			strcpy(upper_args[i-1], args[i]);
			strcpy(lower_args[i-1], args[i]);
	}
	upper_args[i-1]=NULL;
	lower_args[i-1]=NULL;
}

/* Um, some security routines --
	Note: if these are truly secure, they can be freely re-used elsewhere.
*/
static int safe_chdir(directory)
char *directory;
{
	extern int errno;

	char *subdir=NULL;
	struct stat sb;
	int nslashes=0, chdir_ret;

	/* Make sure we can access every part of the path */
	if ( (subdir=strchr(((*directory=='/')? directory+1 : directory), '/'))
								!= NULL ) {
		*subdir = '\0';

		/* Skip double slashes */
		do {
			++subdir;
			++nslashes;
		} while ( *subdir && (*subdir == '/') );
	}
	/* Is there a race condition here?  stat() first, chdir() later */
	/* Does it really matter? */
	if ( stat(directory, &sb) < 0 )
		return(-1);

	/* Check our access */
	if ( (sb.st_uid == getuid()) && ((sb.st_mode&0500) == 0500) )
		chdir_ret = chdir(directory);
	else if ( (sb.st_gid == getgid()) && ((sb.st_mode&0050) == 0050) )
		chdir_ret = chdir(directory);
	else if ( (sb.st_mode&0005) == 0005 )
		chdir_ret = chdir(directory);
	else {
		errno = EACCES;
		return(-1);
	}
	if ( subdir ) {
		/* Put back that slash */
		*(subdir-nslashes) = '/';

		/* Check out the subdirectory */
		if ( *subdir && safe_chdir(subdir) < 0 )
			return(-1);
	}
	return(chdir_ret);
}
/* End of security check routines */


/* The main cazunga, the reason we are here at all... */
void splitvtrc()
{
	struct passwd *pwd;
	char *home;
	int   rcfd;
	struct stat rc_statbuf;
	FILE *rcfile;
	char line[BUFSIZ], newline[BUFSIZ*2], *parsed[256];
	char *head, *tail, *ptr, *subptr;
	char *envptr, envbuf[128];
	int  i, n, quoted=0;
	int  ignoring=0, ifs=0;

	/* Get our home directory */
	if ( (home=(char *)getenv("HOME")) == NULL ) {
		/* Try to get it from the password file */
		if ( (pwd=getpwuid(getuid())) == NULL ) {
			/* Who are you?  But I don't really care... */
			home="";
		} else {
			home = pwd->pw_dir;
		}
	}

	/* Create the startup filename */
	if ( startupfile == NULL ) {
		rcfile_buf=(char *)malloc(strlen(home)+sizeof(SPLITVTRC));
		if ( rcfile_buf == NULL ) {
			/* Maybe warn of malloc() error? */
			return;
		}
		strcpy(rcfile_buf, home);
		strcat(rcfile_buf, SPLITVTRC);
	} else {
		rcfile_buf=(char *)malloc(strlen(startupfile)+1);
		if ( rcfile_buf == NULL ) {
			/* Maybe warn of malloc() error? */
			return;
		}
		strcpy(rcfile_buf, startupfile);
	}

	/* Since we're root, we need to do some security checking on
	   the file we're opening.  It must either be owned by the 
	   user calling us, or be world-readable.
	*/
	if ( (rcfd=open(rcfile_buf, O_RDONLY, 0)) < 0 ) {
		/* No worries, just ignore startup file */
		return;
	}
	if ( fstat(rcfd, &rc_statbuf) < 0 ) {
		/* Huh?  What's this? */
		perror("Couldn't call fstat() on startup file descriptor");
		fprintf(stderr, "Not using startup file '%s'.\n", rcfile_buf);
		close(rcfd);
		sleep(2);
		return;
	}
	/* Security check */
	/* Note: This doesn't check the path of the file, just the file
	         itself.  Is this a serious problem?  Not here, I think.
	*/
	if ( (rc_statbuf.st_uid != getuid()) &&
			((rc_statbuf.st_mode&0004) != 0004) ) {
		fprintf(stderr, "Warning: You don't own your startup file!\n");
		fprintf(stderr, "Not using startup file '%s'.\n", rcfile_buf);
		close(rcfd);
		sleep(2);
		return;
	}
	/* Open a file stream */
	if ( (rcfile=fdopen(rcfd, "r")) == NULL ) {
		perror("Warning: Couldn't create FILE stream on rcfd");
		fprintf(stderr, "Not using startup file '%s'.\n", rcfile_buf);
		close(rcfd);
		sleep(2);
		return;
	}

	while ( fgets(line, BUFSIZ-1, rcfile) ) {
		++lineno;
		/* Clean up leading and tailing whitespace */
		for ( head=line; WHITESPACE(*head); ++head );
		for ( tail=(head+strlen(head)); 
			(WHITESPACE(*(tail-1)) && (tail > head)); --tail );
		*tail='\0';
		if ( (*head == '\0') || (*head == '#') )
			continue;

		/* Parse the line, make sure newline isn't too big */
		tail=head; 
		for ( i=0, head=ptr=newline; ((ptr-newline)<(BUFSIZ*2-2))
								&& *tail; ) {
			if ( WHITESPACE(*tail) ) {
				*(ptr++)='\0';
				parsed[i++]=head;
				do {
					++tail;
				} while ( *tail && WHITESPACE(*tail) );
				head=ptr;
			}
			/* Not whitespace */

			/* Environment variable expansion */		
			if ( *tail == '$' ) {
				n=0;
				for (subptr=(tail+1);
				(n<127)&&(isalpha(*subptr)||(*subptr=='_'));
								++subptr)
					envbuf[n++]=(*subptr);
				envbuf[n]='\0';
				tail=subptr;
				if ( (envptr=(char *)getenv(envbuf)) ) {
					/* Make sure there is no overflow */
					if ( (ptr+strlen(envptr)-newline) <
								(BUFSIZ*2-2) ) {
						strcpy(ptr, envptr);
						ptr+=strlen(envptr);
					}
				}
				continue;
			}
				
			/* Support backslash escape */
			if ( *tail == '\\' )
				++tail;

			if ( *tail )
				*(ptr++) = *(tail++);
		}
		*ptr='\0';  /* cap the new buffer with a null */
		parsed[i++]=head;
		parsed[i++]=NULL;

		/* Perform flow control (no nested if statements) */
		/* Maybe rewritten as YACC someday? :-) */
		if ( strcmp(parsed[0], "if") == 0 ) {
			if ( !parsed[1] ) {
				warn("bad if syntax");
				continue;
			}
			if ( ifs ) {
				warn("ignoring nested if statement");
				continue;
			} ++ifs;

			/* if <> syntax */
			if ( ! parsed[2] ) {
				if ( *parsed[1] )
					ignoring=0;
				else
					ignoring=1;
				continue;
			}

			/* if <> operand <> syntax */
			if ( strcmp(parsed[2], "==") == 0 ) {
				if ( strcmp(parsed[1], parsed[3]) == 0 )
					ignoring=0;
				else
					ignoring=1;
			} else if ( strcmp(parsed[2], "!=") == 0 ) {
				if ( strcmp(parsed[1], parsed[3]) == 0 )
					ignoring=1;
				else
					ignoring=0;
			} else
				warn("unknown if conditional");
			continue;
		}
		if ( strcmp(parsed[0], "else") == 0 ) {
			if ( ignoring )
				ignoring=0;
			else
				ignoring=1;
			continue;
		}
		if ( strcmp(parsed[0], "endif") == 0 ) {
			--ifs;
			ignoring=0;
			continue;
		}
		if ( ignoring )
			continue;

		/* Check for a variable setting */
		if ( parsed[1] == NULL ) {
			for ( n=0; parsed[0][n]; ++n ) {
				if ( parsed[0][n] == '=' )
					break;
			}
			if ( parsed[0][n] ) {
				myputenv(parsed[0]);
				continue;
			}
		}

		/* Check for various commands */
		if ( strcmp(parsed[0], "set") == 0 )
			set_something(parsed);
		else if ( strcmp(parsed[0], "run") == 0 )
			set_argv(parsed);
		else if ( strcmp(parsed[0], "cd") == 0 ) {
			if ( parsed[1] ) {
				if ( safe_chdir(parsed[1]) < 0 ) {
			fprintf(stderr, "Warning: cannot cd to %s: ", 
							parsed[1]);
					perror("");
					sleep(2);
				}
			} else
				warn("Usage: cd <directory>");
		} else
			warn("Invalid directive");
	}
	return;
}
