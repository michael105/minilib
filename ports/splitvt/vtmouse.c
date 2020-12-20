
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

#include "vtmouse.h"

extern FILE *safe_popen();		/* From misc.c */

#if 0
void event_loop()
{
	int c, event_flag;
	struct event X_event;

	while ( (c=event_getc(&X_event)) != EOF ) {
#ifdef ORI
		if ( X_event.happening ) {
			printf("\r\n************\r\n");
			printf("Mouse Event: 0x%x\r\n", X_event.button_state);
			printf("\tX coordinate: %d\r\n", X_event.x);
			printf("\tY coordinate: %d\r\n", X_event.y);
			/* One example of getting the mouse state */
			printf("\tX Event: ");
			switch(X_event.button_state&BUTTON_MASK) {
				case RELEASE:	printf("Button was released!\r\n");
						break;
				default:	printf("Button %d was pressed!\r\n", 
							(X_event.button_state&BUTTON_MASK)+1);
						break;
			}
			/* Another example of getting the mouse state */
			printf("\tMouse %s buttons <%c|%c|%c>\r\n",
				(BUTTON_ISSET(X_event, RELEASE) ? "released" : "pressed"),
				(BUTTON_ISSET(X_event, BUTTON_1) ? 'X' : ' '),
				(BUTTON_ISSET(X_event, BUTTON_2) ? 'X' : ' '),
				(BUTTON_ISSET(X_event, BUTTON_3) ? 'X' : ' '));
#ifdef REPORT_SELECTION
			if ( (X_event.button_state&SELECTED) == SELECTED )
				printf("Selection: Start x=%d, y=%d; End x=%d, y=%d\r\n",
						X_event.selection.begin_col,
						X_event.selection.begin_row,
						X_event.selection.end_col,
						X_event.selection.end_row);
#endif /* REPORT_SELECTION */
			printf("************\r\n");
		} else {
#endif
			if ( c == '\r' ) {
				putc('\r', stdout);
				putc('\n', stdout);
			} else if ( c < ' ' ) {
				putc('^', stdout);
				putc(c+'@', stdout);
			} else if ( c == 'Q' )
				return;
			else
				putc(c, stdout);
		}
	}
}

int main(int argc, char *argv[])
{
	if ( event_init(stdin, stdout, NULL) < 0 ) {
		printf("Not running under an xterm.\n");
		exit(2);
	}
	system("stty -echo raw");

	event_loop();

	system("stty -raw echo");
	event_quit();

	exit(0);
}
#endif

/* I/O streams default to stdin and stdout. */
static FILE *xt_input, *xt_output;
static int have_xterm=0;
static int set_title=0;
static char *old_title=NULL;
int terminal_input=0;		/* Is there pending terminal input? */

#ifdef ORI
static char *get_xtitle()
{
	char buffer[512], *title;
	FILE *pipe;

	strcpy(buffer, "xterm");
	if ( (title=(char *)getenv("WINDOWID")) ) {
		if ( (strlen("xprop -id ")+strlen(title)+1) > 512 )
			goto NoTitle;
		sprintf(buffer, "xprop -id %s", title);
		if ( (pipe=safe_popen(buffer, "r")) ) {
			while ( fgets(buffer, 511, pipe) );
			/* Last line should be 'WM_NAME(STRING) = "title"' */
			if (strlen(buffer) > strlen("WM_NAME(STRING) = \"")) {
				buffer[strlen(buffer)-2]='\0';
				title=(buffer+strlen("WM_NAME(STRING) = \""));
				strcpy(buffer, title);
			} else
				strcpy(buffer, "xterm");
			safe_pclose(pipe);
		} else NoTitle:
			strcpy(buffer, "xterm");
	}
	if ( (title=(char *)malloc(strlen(buffer)+1)) == NULL )
		return(NULL);
	strcpy(title, buffer);
	return(title);
}
#endif
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
#ifdef REPORT_SELECTION
	static int last_row, last_col;
#endif
	int c;
	static char prefix[8], *next;
#ifdef SPLITVT_SOURCE
	extern struct physical physical;
	window *thiswin;
#endif

	X_event->happening=0;

	if ( have_xterm ) {
		if ( terminal_input == 0 ) { /* Brand new input */
			strcpy(prefix, "\033[");	/* Sequence prefix */
			next=prefix;
			while ( (c=getc(xt_input)) != EOF ) {
				if ( *next ) {
					if ( c != *next ) {
						*next = c;
						terminal_input=(next-prefix);
						next=prefix;
						return(*(next++));
					} else
						++next;
				} else
					break;
			}
		} else { /* We already have input to return */
			--terminal_input;
			return(*(next++));
		}

		/* If we got here, we got prefix + c */
		switch (c) {
#ifdef MISC_UNSURE
			case 'M':	/* ^[[M%d%d%d  (assume getc() is ok) */
					X_event->button_state =
							(getc(xt_input)-' ');
					X_event->y=(getc(xt_input)-' ');
					last_col=X_event->y;
					X_event->x=(getc(xt_input)-' ');
					last_row=X_event->x;
#ifdef REPORT_SELECTION
					if (BUTTON_ISSET((*X_event), BUTTON_1))
					{ /* Tell xterm to start selection */
#ifdef SPLITVT_SOURCE
        	if ( X_event->x < (physical.subwins[LOWER])->row_offset )
			thiswin=physical.subwins[UPPER];
		else if ( X_event->x > (physical.subwins[LOWER])->row_offset )
			thiswin=physical.subwins[LOWER];
		else { /* On separator bar -- don't start cut-paste there */
			fprintf(xt_output, "\033[0;0;0;0;0T");
			fflush(xt_output);
			X_event->happening=1;
			break;
		}
		fprintf(xt_output, "\033[1;%d;%d;%d;%dT",
					/* startcol, startrow, */
					X_event->y, X_event->x,
					/* first row */
					1 + thiswin->row_offset,
					/* last row */
					thiswin->rows + thiswin->row_offset+1);
#else
						fprintf(xt_output, 
							"\033[1;%d;%d;%d;%dT",
						/* startcol, startrow, */
							X_event->y, X_event->x,
						/* firstrow, lastrow */
							1, 24);
#endif /* SPLITVT_SOURCE */
						fflush(xt_output);
					}
#endif /* REPORT_SELECTION */
					X_event->happening=1;
					break;
#ifdef REPORT_SELECTION
			case 't':	/* ^[[t%d%d */
					X_event->button_state = 
							(RELEASE|SELECTED);
					X_event->selection.begin_row=last_row;
					X_event->selection.begin_col=last_col;
					X_event->selection.end_col =
							(getc(xt_input)-' ');
					X_event->selection.end_row =
							(getc(xt_input)-' ');
					X_event->happening=1;
					break;
			case 'T':	/* ^[[T%d%d%d%d%d%d */
					X_event->y=(getc(xt_input)-' ');
					X_event->x=(getc(xt_input)-' ');
					X_event->button_state = 
							(RELEASE|SELECTED);
					X_event->selection.begin_col =
							(getc(xt_input)-' ');
					X_event->selection.begin_row =
							(getc(xt_input)-' ');
					X_event->selection.end_col =
							(getc(xt_input)-' ');
					X_event->selection.end_row =
							(getc(xt_input)-' ');
					X_event->happening=1;
					break;
#endif
#endif /* REPORT_SELECTION */
			case EOF:	/* We got EOF, return EOF */
					return(EOF);
					break;
			default:	/* It's not an event sequence */
					*next = c;
					terminal_input=(next-prefix);
					next=prefix;
					return(*(next++));
					break;
		}
	} else
		return(getc(xt_input));
	return(0);
}

void event_quit()
{
	if ( have_xterm ) {
#ifdef REPORT_SELECTION
		fprintf(xt_output, "\033[?1001l");
#else
		fprintf(xt_output, "\033[?1000l");
#endif /* REPORT_SELECTION */
		fflush(xt_output);
		if ( set_title && old_title ) {
			set_xtitle(old_title);
			(void) free(old_title);
		}
	}
}

