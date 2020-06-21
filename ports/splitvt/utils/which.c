
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

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

void tokenize(array, line, tokens)
char *array[];
char *line;
char *tokens;
{
	char *head, *ptr;
	int i=0;

	for ( head=line; *line; ) {
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

	tokenize(paths, newpath, ":");
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
	

main(argc, argv)
int argc;
char *argv[];
{
	char *path;

	if ( argc != 2 ) {
		fprintf(stderr, "Usage: %s command\n", argv[0]);
		exit(1);
	}

	if ( (path=pathsearch(argv[1], 0)) )
		printf("%s\n", path);
	exit(0);
}
