
/* This is a program to show how mouse events can be handled by programs
   running under an xterm window.

		-Sam Lantinga		5/11/94
*/

#define SPLITVT_SOURCE


#ifndef MLIB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#include "vtevent.h"

extern FILE *safe_popen();		/* From misc.c */

/* I/O streams default to stdin and stdout. */
static FILE *xt_input, *xt_output;
static int have_xterm=0;
static int set_title=0;
static char *old_title=NULL;
int terminal_input=0;		/* Is there pending terminal input? */

static void set_xtitle(titlebar)
char *titlebar;
{
	fprintf(xt_output, "\033]0;%s\07", titlebar);
	fflush(xt_output);
}

int event_init(input, output, titlebar)
FILE *input, *output;
char *titlebar;
{
	char *termtype;

	/* A program can assume that input is unbuffered after this routine */
	setbuf(input, NULL);
	xt_input=input;
	xt_output=output;

	/* Check for xterm terminal type */
	if ( (termtype=(char *)getenv("TERM")) && strcmp(termtype, "xterm") == 0 ) {
#ifdef REPORT_SELECTION
		fprintf(xt_output, "\033[?1001h");
#else
		fprintf(xt_output, "\033[?1000h");
#endif /* REPORT_SELECTION */
		fflush(xt_output);
		have_xterm=1;
		//old_title=get_xtitle();
		old_title=0;
		if ( titlebar ) {
			set_xtitle(titlebar);
			set_title=1;
		}
	} else {
		return(-1);
	}
	return(0);
}

int event_getc(X_event)
struct event *X_event;
{
	return(getc(xt_input));
}

void event_quit()
{
}

