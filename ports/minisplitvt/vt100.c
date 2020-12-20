
/* This file contains the terminal "driver" code for splitsh.
   It is designed to keep track of the position of the cursor
   while handling a split window of vt100 emulation.
   All of the routines assume that there is no other output 
   going onto the standard output screen, to mess it up.

   Many thanks to Matt Ostanik who wrote the ANSI Handbook.
*/

#ifndef MLIB
#include	<sys/types.h>
#ifdef HAVE_TERMIO_H
#include	<termios.h>		/* Used only for TIOCGWINSZ */
#else
#include	<sys/ioctl.h>		/* Used only for TIOCGWINSZ */
#endif
#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	<ctype.h>
#endif

#include	"vt100.h"
#include	"video.h"
#include	"terminal.h"

#define SEP_CHAR	'-'		/* Separator bar character */

int TABSTOP=8;				/* The default tabstop value */

/* Two virtual windows + a pointer to the current one */
static window upper, lower;
window *curwin;

/* One physical window */
struct physical physical;

static char terminal_type[BUFSIZ];	/* Our terminal type */
static char *sep;	        	/* The window separator string */

/* The various output processing functions, based on state */
void scan_for_esc();
void E_(), E_brac(), E_brac_Q(), E_lparen(), E_rparen(), E_pound();

/* Make these four variables accessable to the calling program */
int UU_lines=0;         /* The user requested lines for the upper window */
int WU_lines=0;         /* The number of lines for the upper window */
int WL_lines=0;         /* The number of lines for the lower window */
int W_columns=0;        /* The number of columns per window */

static int LU_lines;    /* A local copy of UU_lines that is modified */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Reset the escape scanning sequence: */
static void reset_escape(win)
window *win;
{
	int i;

	win->process_char=scan_for_esc;
	for ( i=0; i<MAX_PARAMS; ++i )
		win->esc_param[i]=0;
	win->param_idx=0;
	win->cur_param=(&win->esc_param[win->param_idx]);
}
static void reset_esc()
{
	reset_escape(curwin);
}
/* Initialize a window structure: */
static void vt_resetwin(win)
window *win;
{
	win->cursor.x=1;
	win->cursor.y=1;
	win->saved_cursor.x=1;
	win->saved_cursor.y=1;
	win->cols=physical.cols;
	win->scr_upper=1;
	win->scr_lower=win->rows;
	win->saved_cursor.x=0;
	win->saved_cursor.y=0;
	win->key_state=normal;
	win->textattr=NORMAL;
	win->saved_textattr=NORMAL;
	win->charset[G0]=US_CHARSET;
	win->charset[G1]=US_CHARSET;
	reset_escape(win);
}
/* Check to make sure the window cursor values are sane. */
static void vt_checkwin(win)
window *win;
{
	if ( win->cursor.x > win->rows )
		win->cursor.x=win->rows;
	if ( win->cursor.y > win->cols )
		win->cursor.y=win->cols;
	if ( win->scr_lower > win->rows )
		win->scr_lower=win->rows;
}
/* Set the current window: */
static int lastwin = (-1);
void set_win(which)
int which;
{
	window *other;
	int i;

	/* Are we already in position? */
	if ( which == lastwin )
		return;

	/* Set the current window and move the cursor into position */
	curwin = physical.subwins[which];
	other = physical.subwins[!which];
	vt_setscroll(curwin->scr_upper+curwin->row_offset, 
					curwin->scr_lower+curwin->row_offset);
	vt_goto(curwin->cursor.x+curwin->row_offset, curwin->cursor.y);

	/* Make sure the terminal is in the current window's state */
	for ( i=0; i<NCHARSETS; ++i ) {
		if ( curwin->charset[i] != other->charset[i] )
			vt_altcharset(i, curwin->charset[i]);
	}
	if ( curwin->key_state != other->key_state )
		vt_keystate(curwin->key_state);
	if ( curwin->textattr != other->textattr )
		vt_setattr((int)curwin->textattr);
	vt_update();
	lastwin=which;
}

/* Set the terminal attributes to those of the specified window */
/* This must be called _after_ vt_restcursor(), or it won't work */
static void set_attr(win)
window *win;
{
	unsigned char on=NORMAL;

	vt_resetattr();
	(void) check_attr(0, win->textattr, &on);
}

/* Process the ^[[X;Xm escape.  Made into a separate routine to support
   ansi color. */
static void process_m(win, n)
window *win;
int n;
{
	switch (n) {
		case 0:	/* Turn all attributes off */
			win->textattr=NORMAL;
			vt_resetattr();
			break;
		case 1:	/* Turn on bold */
			win->textattr |= BOLD;
			vt_bold(1);
			break;
		case 2:	/* Half brightness */
			/* UNSUPPORTED */
			break;
		case 4:	/* Turn on underlining */
			win->textattr |= UNDERLINE;
			vt_underline(1);
			break;
		case 5:	/* Turn on blinking */
			win->textattr |= BLINK;
			vt_blink(1);
			break;
		case 7:	/* Turn on reverse */
			win->textattr |= REVERSE;
			vt_reverse(1);
			break;
		case 21: /* Normal brightness */
			/* UNSUPPORTED */
			break;
		case 22: /* Turn off bold */
			win->textattr &= ~BOLD;
			vt_bold(0);
			break;
		case 24: /* Turn off underlining */
			win->textattr &= ~UNDERLINE;
			vt_underline(0);
			break;
		case 25: /* Turn off blinking */
			win->textattr &= ~BLINK;
			vt_blink(0);
			break;
		case 27: /* Turn off reverse */
			win->textattr &= ~REVERSE;
			vt_reverse(0);
			break;
		case 30:
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 37: /* Set foreground color */
			vt_setfg(n-30);
			break;
		case 40:
		case 41:
		case 42:
		case 43:
		case 44:
		case 45:
		case 46:
		case 47: /* Set background color */
			vt_setbg(n-40);
			break;
		default: /* Unknown escape */
			break;
	}
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void scan_for_esc(c, source)
int c;
int *source;
{
	int i;

	switch (c) {
		/* Taken from vt102.codes */
		case '\000':	/* NULL (fill character) */
		case '\003':	/* EXT  (half duplex turnaround) */
		case '\004':	/* EOT  (can be disconnect char) */
		case '\005':	/* ENQ  (generate answerback) */
				printf("%c", c);
				break;
		case '\007':	/* BEL  (sound terminal bell) */
				vt_bell();
				break;
		case '\b':	/* Backspace; move left one character */
				if ( curwin->cursor.y != 1 ) {
					--curwin->cursor.y;
					vt_left(curwin->esc_param[0]);
				}
				break;
		case '\t':	/* Tab.  Handle with direct motion (Buggy) */
				i=curwin->cursor.y;
				do {
					++curwin->cursor.y;
				} while ( !curwin->tabstops[curwin->cursor.y-1]
				        && (curwin->cursor.y < curwin->cols) );
				vt_right(curwin->cursor.y - i);
				break;
		case '\013':	/* Processed as linefeeds */
		case '\014':	/* Don't let the cursor move below window or scrolling region */
		case '\n':	if ( curwin->cursor.x < curwin->scr_lower )
					++curwin->cursor.x;
				else
					scroll_video(curwin, 1);
				printf("\n");
				break;
		case '\r':	/* Move cursor to left margin */
				curwin->cursor.y = 1;
				printf("\r");
				break;
		case '\016':	/* S0 (selects G1 charset) */
		case '\017':	/* S1 (selects G0 charset) */
		case '\021':	/* XON (continue transmission) */
		case '\022':	/* XOFF (stop transmission) */
				printf("%c", c);
				break;
		case '\030':	/* Processed as escape cancel */
		case '\032':	reset_esc();
				break;
		case '\033':	curwin->process_char=E_;
				break;
		default:	if ( curwin->cursor.y > curwin->cols )
				{	/* Wrap */
					if (curwin->cursor.x<curwin->scr_lower)
					{
						++curwin->cursor.x;
					} else
						scroll_video(curwin, 1);
					printf("\r\n");
					curwin->cursor.y=1;
				}
				add_video(curwin, c); printf("%c", c);
				++curwin->cursor.y;
				break;
	}
	return;
}
void E_(c, source)
int c;
int *source;
{
	/* Return inside the switch to prevent reset_esc() */
	switch (c) {
		case '\030':	/* Processed as escape cancel */
		case '\032':	reset_esc();
				return;
		case '[':	curwin->process_char=E_brac;
				return;
		case '(':	curwin->process_char=E_lparen;
				return;
		case ')':	curwin->process_char=E_rparen;
				return;
		case '#':	curwin->process_char=E_pound;
				return;
		case 'D':	/* Cursor down with scroll up at margin */
				if ( curwin->cursor.x < curwin->scr_lower ) {
					++curwin->cursor.x;
				} else
					scroll_video(curwin, 1);
				printf("\n");
				break;
		case 'M':	/* Reverse scroll (move up; scroll at top) */
				if ( (curwin->cursor.x > curwin->scr_upper) )
					--curwin->cursor.x;
				else
					revscroll_video(curwin, 1);
				vt_revscroll();
				break;
		case 'E':	/* Next line (CR-LF) */
				if ( curwin->cursor.x < curwin->scr_lower )
					++curwin->cursor.x;
				else 
					scroll_video(curwin, 1);
				curwin->cursor.y = 1;
				printf("\r\n");
				break;
		case '7':	/* Save cursor and attribute */
				curwin->saved_cursor=curwin->cursor;
				curwin->saved_textattr=curwin->textattr;
				break;
		case '8':	/* Restore saved cursor and attribute */
				curwin->cursor=curwin->saved_cursor;
				if ( curwin->cursor.x > curwin->rows )
					curwin->cursor.x = curwin->rows;
				if ( curwin->cursor.y > curwin->cols )
					curwin->cursor.y = curwin->cols;
				vt_goto(curwin->cursor.x+curwin->row_offset, 
							curwin->cursor.y);
				curwin->textattr=curwin->saved_textattr;
				set_attr(curwin);
				break;
		case '=':	/* Set application keypad mode */
				curwin->key_state=application;
				vt_keystate(curwin->key_state);
				break;
		case '>':	/* Set numeric keypad mode */
				curwin->key_state=normal;
				vt_keystate(curwin->key_state);
				break;
		case 'N':	/* Select charset G2 for one character */
				/* UNSUPPORTED */
				break;
		case 'O':	/* Select charset G3 for one character */
				/* UNSUPPORTED */
				break;
		case 'H':	/* Set horizontal tab */
				curwin->tabstops[curwin->cursor.y-1]=1;
				break;
		case 'Z':	/* Request terminal identification string */
				/* Respond with "I am a vt102" */
				write(*source, "\033[?6c", 5);
				break;
		case 'c':	/* Terminal reset */
				vt_resetwin(curwin);
				break;
		default:	/* Unrecognized escape: ignore */
				break;
	}
	reset_esc();
}
void E_brac(c, source)
int c;
int *source;
{
	int newx, newy, i;
	char reply[128];

	/* Check for numeric argument first */
	if ( isdigit(c) ) {
		*curwin->cur_param *= 10;
		*curwin->cur_param += (c-'0');
		return;
	}

	/* Return inside the switch to prevent reset_esc() */
	switch (c) {
		case '\030':	/* Processed as escape cancel */
		case '\032':	reset_esc();
				return;
		case '?':	/* Format should be \E[?<n> */
				if ( *curwin->cur_param )
					reset_esc();
				else
					curwin->process_char=E_brac_Q;
				return;
		case ';':	if ( ++curwin->param_idx < MAX_PARAMS ) {
					curwin->cur_param =
					&curwin->esc_param[curwin->param_idx];
				}
				return;
		case 'h':	/* Set modes */
			switch (curwin->esc_param[0]) {
				case 2:	 /* Lock keyboard */
					 /* UNSUPPORTED */
				case 4:	 /* Character insert mode */
					 /* UNSUPPORTED */
				case 12: /* Local echo on */
					 /* UNSUPPORTED (easily supported) */
				case 20: /* <Return> = CR */
					 /* UNSUPPORTED (easily supported) */
				default: break;
			}
			break;
		case 'l':	/* Reset modes */
			switch (curwin->esc_param[0]) {
				case 2:	 /* Unlock keyboard */
					 /* UNSUPPORTED */
				case 4:	 /* Character overstrike mode */
					 /* UNSUPPORTED */
				case 12: /* Local echo off */
					 /* UNSUPPORTED (easily supported) */
				case 20: /* <Return> = CR-LF */
					 /* UNSUPPORTED (easily supported) */
				default: break;
			}
			break;
		case 'r':	/* Set scroll region */
			if ( ! curwin->esc_param[0] && ! curwin->esc_param[1] ) {
				curwin->scr_upper=1;
				curwin->scr_lower=curwin->rows;
			} else {
				/* Check parameters: VERY important. :) */
				if (curwin->esc_param[0] < 1) /* Not needed */
					curwin->scr_upper=1;
				else
					curwin->scr_upper=curwin->esc_param[0];

				if ( curwin->esc_param[1] > curwin->rows )
					curwin->scr_lower=curwin->rows;
				else
					curwin->scr_lower=curwin->esc_param[1];

				if ( curwin->scr_upper > curwin->scr_lower ) {
					/* Reset scroll region */
					curwin->scr_upper=1;
					curwin->scr_lower=curwin->rows;
				}
			}
			curwin->cursor.x=1;
			curwin->cursor.y=1;
			vt_setscroll(curwin->scr_upper+curwin->row_offset, 
					curwin->scr_lower+curwin->row_offset);
			vt_goto(curwin->cursor.x+curwin->row_offset, 1);
			break;
		case 'A':	/* Cursor UP */
			if ( curwin->cursor.x == curwin->scr_upper )
				break;
			if ( ! curwin->esc_param[0] )
				curwin->esc_param[0]=1;
			newx = (curwin->cursor.x - curwin->esc_param[0]);
			if ( newx > curwin->scr_upper ) {
				curwin->cursor.x=newx;
				vt_up(curwin->esc_param[0]);
			} else {
				curwin->cursor.x=curwin->scr_upper;
				vt_goto(curwin->cursor.x+curwin->row_offset,
							curwin->cursor.y);
			}
			break;
		case 'B':	/* Cursor DOWN */
			if ( curwin->cursor.x == curwin->scr_lower )
				break;
			if ( ! curwin->esc_param[0] )
				curwin->esc_param[0]=1;
			newx = (curwin->cursor.x + curwin->esc_param[0]);
			if ( newx <= curwin->scr_lower ) {
				curwin->cursor.x=newx;
				vt_down(curwin->esc_param[0]);
			} else {
				curwin->cursor.x=curwin->scr_lower;
				vt_goto(curwin->cursor.x+curwin->row_offset,
							curwin->cursor.y);
			}
			break;
		case 'C':	/* Cursor RIGHT */
			if ( curwin->cursor.y == curwin->cols )
				break;
			if ( ! curwin->esc_param[0] )
				curwin->esc_param[0]=1;
			newy = (curwin->cursor.y + curwin->esc_param[0]);
			if ( newy < curwin->cols ) {
				curwin->cursor.y=newy;
				vt_right(curwin->esc_param[0]);
			} else {
				curwin->cursor.y=curwin->cols;
				vt_goto(curwin->cursor.x+curwin->row_offset,
							curwin->cursor.y);
			}
			break;
		case 'D':	/* Cursor LEFT */
			if ( curwin->cursor.y == 1 )
				break;
			if ( ! curwin->esc_param[0] )
				curwin->esc_param[0]=1;
			newy = (curwin->cursor.y - curwin->esc_param[0]);
			if ( newy > 1 ) {
				curwin->cursor.y=newy;
				vt_left(curwin->esc_param[0]);
			} else {
				curwin->cursor.y=1;
				printf("\r");
			}
			break;
		case 'f':
		case 'H':	/* Move cursor to coordinates */
			if ( ! curwin->esc_param[0] )
				curwin->esc_param[0]=1;
			if ( ! curwin->esc_param[1] )
				curwin->esc_param[1]=1;
			if ( (curwin->cursor.x=curwin->esc_param[0]) >
								curwin->rows )
				curwin->cursor.x=curwin->rows;
			if ( (curwin->cursor.y=curwin->esc_param[1]) >
								curwin->cols )
				curwin->cursor.y=curwin->cols;
			vt_goto(curwin->cursor.x+curwin->row_offset,
							curwin->cursor.y);
			break;
		case 'g':	/* Clear tabstops */
			switch (curwin->esc_param[0]) {
				case 0:	/* Clear a tabstop */
					curwin->tabstops[curwin->cursor.y-1]=0;
					break;
				case 3:	/* Clear all tabstops */
					for (newy=0; newy<curwin->cols; ++newy)
						curwin->tabstops[newy]=0;
					break;
				default: break;
			}
			break;
		case 'm':	/* Set terminal attributes */
			process_m(curwin, curwin->esc_param[0]);
			for ( i=1; curwin->esc_param[i] && i<MAX_PARAMS; ++i )
				process_m(curwin, curwin->esc_param[i]);
			break;
		case 'J':	/* Clear screen */
			switch (curwin->esc_param[0]) {
				case 0:	/* Clear from cursor down */
					erase_video(curwin, 
						curwin->cursor.x, curwin->rows,
						1, curwin->cols);
					newx=curwin->cursor.x;
					vt_savecursor();
					printf("\r");
					while ( newx++ < curwin->rows ) {
						vt_clreol();
						printf("\n");
					}
					vt_clreol();
					vt_restcursor();
					break;
				case 1:	/* Clear from cursor up */
					erase_video(curwin, 
						1, curwin->cursor.x,
						1, curwin->cols);
					newx=curwin->cursor.x;
					vt_savecursor();
					printf("\r");
					while ( --newx > 0 ) {
						vt_clreol();
						vt_up(1);
					}
					vt_clreol();
					vt_restcursor();
					break;
				case 2:	/* Clear whole screen */
					erase_video(curwin, 
						1, curwin->rows,
						1, curwin->cols);
					vt_goto(curwin->row_offset+1, 1);
					curwin->cursor.x=1;
					curwin->cursor.y=1;
					newx=curwin->cursor.x;
					vt_savecursor();
					printf("\r");
					while ( newx++ < curwin->rows ) {
						vt_clreol();
						printf("\n");
					}
					vt_clreol();
					vt_restcursor();
					break;
				default: break;
			}
			break;
		case 'K':	/* Clear line */
			switch (curwin->esc_param[0]) {
				case 0:	/* Clear to end of line */
					erase_video(curwin, 
						curwin->cursor.x, curwin->cursor.x,
						curwin->cursor.y, curwin->cols);
					vt_clreol();
					break;
				case 1:	/* Clear to beginning of line */
					erase_video(curwin, 
						curwin->cursor.x, curwin->cursor.x,
						1, curwin->cursor.y);
					vt_clrbgl();
					break;
				case 2:	/* Clear whole line */
					erase_video(curwin, 
						curwin->cursor.x, curwin->cursor.x,
						1, curwin->cols);
					vt_clrline();
					break;
			}
			break;
		case 'P':	/* Delete under cursor */
				erase_video(curwin, 
					curwin->cursor.x, curwin->cursor.x,
					curwin->cursor.y, curwin->cursor.y);
				vt_delunder(curwin->esc_param[0]);
				break;
		case 'M':	/* Delete lines */
				revscroll_video(curwin, 1);
				vt_delline(curwin->esc_param[0]);
				break;
		case 'L':	/* Insert lines */
				vt_insline(curwin->esc_param[0]);
				break;
		case '@':	/* Insert characters */
				if ( ! curwin->esc_param[0] )
					curwin->esc_param[0] = 1;
				vt_insertchar(curwin->esc_param[0]);
				rshift_video(curwin, curwin->esc_param[0]);	
				break;
		case 'i':	/* Printing (UNSUPPORTED) */
				break;
		case 'n':	/* Device status request */
			switch (curwin->esc_param[0]) {
				case 5:	/* Status report request */
					/* Say we're just fine. */
					write(*source, "\033[0n", 4);
					break;
				case 6: /* Cursor position request */
					sprintf(reply, "\033[%d;%dR", 
							curwin->cursor.x,
							curwin->cursor.y);
					write(*source, reply, strlen(reply));
					break;
			}
			break;
		case 'c':	/* Request terminal identification string */
				/* Respond with "I am a vt102" */
				write(*source, "\033[?6c", 5);
				break;
		default:	/* Unrecognized escape: ignore */
				break;
	}
	reset_esc();
}
void E_brac_Q(c, source)
int c;
int *source;
{
	/* Check for numeric argument first */
	if ( isdigit(c) ) {
		*curwin->cur_param *= 10;
		*curwin->cur_param += (c-'0');
		return;
	}

	/* Return inside the switch to prevent reset_esc() */
	switch (c) {
		case '\030':	/* Processed as escape cancel */
		case '\032':	reset_esc();
				return;
		case 'h':	/* Set modes */
			switch (curwin->esc_param[0]) {
				case 1: /* Cursorkeys in application mode */
					curwin->key_state=application;
					vt_keystate(curwin->key_state);
					break;
				case 2: /* Set ansi mode */
					/* UNSUPPORTED */
					break;
				case 3: /* 132 char/row */
					if ( physical.cols != 132 ) {
						upper.cols=132;
						lower.cols=132;
						physical.cols=132;
						vt_widemode(1);
					}
					break;
				case 4: /* Set jump scroll */	
					/* UNSUPPORTED */
					break;
				case 5: /* Set reverse screen */
					/* UNSUPPORTED */
					break;
				case 6: /* Set relative coordinates */
					/* UNSUPPORTED */
					break;
				case 7: /* Set auto wrap on */
					/* UNSUPPORTED */
					break;
				case 8: /* Set auto repeat on */
					/* UNSUPPORTED */
					break;
				case 25: /* Set cursor on */
					/* UNSUPPORTED */
					break;
				case 47: /* Switch to alternate buffer */
					/* UNSUPPORTED (xterm sequence) */
					break;
				default:
					/* UNSUPPORTED */
					break;
			}
			break;
		case 'l':	/* Reset modes */
			switch (curwin->esc_param[0]) {
				case 1: /* Cursorkeys in normal mode */
					curwin->key_state=normal;
					vt_keystate(curwin->key_state);
					break;
				case 2: /* Set VT52 mode */
					/* UNSUPPORTED */
					break;
				case 3: /* 80 char/row */
					if ( physical.cols == 132 ) {
						vt_rows_cols(terminal_type, 
							NULL, &physical.cols);
						upper.cols=physical.cols;
						lower.cols=physical.cols;
						vt_widemode(0);
					}
					break;
				case 4: /* Set smooth scroll */	
					/* UNSUPPORTED */
					break;
				case 5: /* Set non-reversed (normal) screen */
					/* UNSUPPORTED */
					break;
				case 6: /* Set absolute coordinates */
					/* UNSUPPORTED */
					break;
				case 7: /* Set auto wrap off */
					/* UNSUPPORTED */
					break;
				case 8: /* Set auto repeat off */
					/* UNSUPPORTED */
					break;
				case 25: /* Set cursor off */
					/* UNSUPPORTED */
					break;
				case 47: /* Switch from alternate buffer */
					/* UNSUPPORTED (xterm sequence) */
					break;
				default:
					/* UNSUPPORTED */
					break;
			}
			break;
		default:	/* Unrecognized escape: ignore */
			break;
	}
	reset_esc();
}
void E_lparen(c, source)
int c;
int *source;
{
	/* Return inside the switch to prevent reset_esc() */
	switch (c) {
		case '\030':	/* Processed as escape cancel */
		case '\032':	reset_esc();
				return;
		/* Select character sets */
		case 'A':	/* UK as G0 */
				curwin->charset[G0]=UK_CHARSET;
				vt_altcharset(G0, UK_CHARSET);
				break;
		case 'B':	/* US as G0 */
				curwin->charset[G0]=US_CHARSET;
				vt_altcharset(G0, US_CHARSET);
				break;
		case '0':	/* Special character set as G0 */
				curwin->charset[G0]=GRAPHICS;
				vt_altcharset(G0, GRAPHICS);
				break;
		case '1':	/* Alternate ROM as G0 */
		case '2':	/* Alternate ROM special character set as G0 */
		default:	/* Unrecognized escape: ignore */
				break;
	}
	reset_esc();
}
void E_rparen(c, source)
int c;
int *source;
{
	/* Return inside the switch to prevent reset_esc() */
	switch (c) {
		case '\030':	/* Processed as escape cancel */
		case '\032':	reset_esc();
				return;
		/* Select character sets */
		case 'A':	/* UK as G1 */
				curwin->charset[G1]=UK_CHARSET;
				vt_altcharset(G1, UK_CHARSET);
				break;
		case 'B':	/* US as G1 */
				curwin->charset[G1]=US_CHARSET;
				vt_altcharset(G1, US_CHARSET);
				break;
		case '0':	/* Special character set as G1 */
				curwin->charset[G1]=GRAPHICS;
				vt_altcharset(G1, GRAPHICS);
		case '1':	/* Alternate ROM as G1 */
		case '2':	/* Alternate ROM special character set as G1 */
		default:	/* Unrecognized escape: ignore */
				break;
	}
	reset_esc();
}
void E_pound(c, source)
int c;
int *source;
{
	switch (c) {   /* Line attributes not supported */
		case '3':	/* Double height (top half) */
		case '4':	/* Double height (bottom half) */
		case '5':	/* Single width, single height */
		case '6':	/* Double width */
		default:
			reset_esc();
			break;
	}
	return;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Routine to initialize the vt100 screening, returning an error message,
   or NULL if all went well. */

static int setup_vt100 = 0;	/* Have we initialized the vt100 system? */

char *init_vt100()
{
#ifdef TIOCGWINSZ
	struct /* winsize */ {
		unsigned short	ws_row;		/* rows, in characters */
		unsigned short	ws_col;		/* columns, in characters */
		unsigned short	ws_xpixel;	/* horizontal size - not used */
		unsigned short	ws_ypixel;	/* vertical size - not used */
	} mywinz;
#endif
	int i, **videomem, oldrows, newrows, newcols;
	oldrows=0;
	position newpos;
	char *ptr, *errmesg;

	/* Check to make sure it's okay to run */
	if ( ! isatty(0) || ! isatty(1) )
		return("Standard input and output must be a tty");

	/* Initialize the termcap environment */
	if ( ! setup_vt100 ) {
		if ( (errmesg=vt_initterm(terminal_type,
				&physical.rows, &physical.cols)) != NULL )
			return(errmesg);
		//vt_initsel();
	}

#ifdef TIOCGWINSZ
	if ( ioctl(0, TIOCGWINSZ, &mywinz) == 0 ) {
		if ( mywinz.ws_row )
			physical.rows=mywinz.ws_row;
		if ( mywinz.ws_col )
			physical.cols=mywinz.ws_col;
	}
#endif
	if ( (ptr=(char *)getenv("LINES")) != NULL )
		physical.rows=atoi(ptr);
	if ( (ptr=(char *)getenv("COLUMNS")) != NULL )
		physical.cols=atoi(ptr);

	/* Now set defaults if we can't find the window size */
	if ( ! physical.rows )	physical.rows=24;
	if ( ! physical.cols )	physical.cols=80;
	physical.subwins[UPPER] = &upper;
	physical.subwins[LOWER] = &lower;

	/* Check that each window is at least 3 lines tall */
	if ( physical.rows < 7 )
		return("Screen is not tall enough to split.");

	/* If physical.cols has been set to 132, assume we are on a
	   vt100 wide terminal, and set 132 column mode.  Note that
	   setting COLUMNS in the environment will override termcap */
	if ( physical.cols == 132 )
		vt_widemode(1);

	/* Set the exportable variables */
	if ( UU_lines ) {
		/* Check the user set # of lines */
		if ( UU_lines > (physical.rows-1-3) )
			LU_lines=(physical.rows-1-3);
		else if ( UU_lines < 3 )
			LU_lines=3;
		else
			LU_lines=UU_lines;

		WU_lines=LU_lines;
		WL_lines=(physical.rows-1-LU_lines);
	} else
		WL_lines=WU_lines=((physical.rows-1)/2);
	W_columns=physical.cols;

	/* Set up the window structures */
	newcols=physical.cols;
	newrows=WU_lines;
	if ( (videomem=alloc_video(newrows, newcols)) == NULL )
		return("Out of memory");
	if ( setup_vt100 ) {
		oldrows=upper.rows;
		copy_video(&upper, videomem, newrows, newcols, &newpos);
		for ( i=0; i<upper.rows; ++i )
			(void) free(upper.videomem[i]);
		(void) free(upper.videomem);
		(void) free(upper.tabstops);
	}
	if ( (upper.tabstops=(int *)malloc_brk(newcols*sizeof(int))) == NULL )
		return("Out of memory");
	for ( i=0; i<newcols; ++i ) {
		if ( (i%TABSTOP) == 0 )
			upper.tabstops[i]=1;
		else
			upper.tabstops[i]=0;
	}
	upper.videomem=videomem;
	upper.cols=physical.cols;
	upper.rows=newrows;
	upper.row_offset=0;
	if ( setup_vt100 ) {
		if ( upper.scr_lower == oldrows )
			upper.scr_lower=newrows;
		upper.cursor=newpos;
		vt_checkwin(&upper);
	} else 
		vt_resetwin(&upper);
	newrows=WL_lines;
	if ( (videomem=alloc_video(newrows, newcols)) == NULL )
		return("Out of memory");
	if ( setup_vt100 ) {
		oldrows=lower.rows;
		copy_video(&lower, videomem, newrows, newcols, &newpos);
		for ( i=0; i<lower.rows; ++i )
			(void) free(lower.videomem[i]);
		(void) free(lower.videomem);
		(void) free(lower.tabstops);
	}
	if ( (lower.tabstops=(int *)malloc_brk(newcols*sizeof(int))) == NULL )
		return("Out of memory");
	for ( i=0; i<newcols; ++i ) {
		if ( (i%TABSTOP) == 0 )
			lower.tabstops[i]=1;
		else
			lower.tabstops[i]=0;
	}
	lower.videomem=videomem;
	lower.cols=physical.cols;
	lower.rows=newrows;
	lower.row_offset=(upper.rows+1);
	if ( setup_vt100 ) {
		if ( lower.scr_lower == oldrows )
			lower.scr_lower=newrows;
		lower.cursor=newpos;
		vt_checkwin(&lower);
	} else 
		vt_resetwin(&lower);

	/* Set up the separator (cols-1) */
	if ( setup_vt100 )
		(void) free(sep);
	if ( (sep=(char *)malloc_brk(physical.cols+1)) == NULL )
		return("Out of memory");
	for ( i=0; i<(physical.cols-1); ++i )
		sep[i]=SEP_CHAR;
	sep[i]='\0';

	/* Clear the screen, and set up the windows */
	if ( ! setup_vt100 ) {
		curwin=(&upper);
		vt_clrscr(); 
		vt_goto((WU_lines+1), 1);		/* Move past the top win */
		//vt_reverse(1);
		printf("%s", sep);			/* Print separator */
		vt_resetattr();
		vt_update();
		lastwin=(-1);
	} else
		vt_redraw();

	++setup_vt100;				/* Set setup_vt100 flag */
	return(NULL);
}

int vt_write(win, data, len, source)
int win;		/* The window; 0 if top, 1 if bottom */
char *data;		/* The data to write */
int len;		/* The amount of data to write */
int *source;		/* File descriptor through which to reply to Esc-Z */
{
	int i;

	/* First set the proper window */
	set_win(win);

	/* Now cycle through the input */
	for ( i=0; i<len; ++i )
		(*curwin->process_char)((int)*(data++), source);
	vt_update();
	return len;
}

/* Print out a prompt on the screen, get a character in response, and 
   return it.  (Assume a one line prompt)
*/

char vt_prompt(prompt)
char *prompt;
{
	char format[BUFSIZ], buff[1];

	/* Save cursor position, go home, clear line and print prompt */
	if ( prompt ) {
		vt_savecursor();
		vt_resetattr();
		vt_goto(WU_lines+1, 0);
		vt_clreol();
		sprintf(format, "%%.%ds", physical.cols);
		vt_bold(1);
		printf(format, prompt);
		vt_update();
	}
	
	/* Read the response */
	if ( read(0, buff, 1) <= 0 )
		buff[0]='\0';

	/* Print out the top separator and go back to where we were */
	if ( prompt ) {
		vt_resetattr();
		//vt_reverse(1);
		printf("\r%s", sep);
		vt_restcursor();
		set_attr(curwin);
		vt_update();
	}

	return(buff[0]);
}

/* Print out information at the bottom of the screen */

void vt_info(info)
char *info;
{
	char format[80];

	/* Save cursor, go to info bar, clear it */
	vt_savecursor();
	vt_resetattr();
	vt_goto(WU_lines+1, 0);
	vt_clreol();

	if ( info ) {
		sprintf(format, "%%.%ds", physical.cols);
		vt_bold(1);
		printf(format, info);
	} 
	else { /* Get rid of the info message */
		vt_reverse(1);
		printf("\r%s", sep);
	}

	/* Then go back where we were supposed to be and update it */
	vt_restcursor();
	set_attr(curwin);
	vt_update();
}

/* Repaint both of the screens */
void vt_redraw()
{
	/* We need to paint current window last so scrolling works */
	vt_clrscr();
	paint_video(lastwin == UPPER ? &lower : &upper);
	vt_goto(WU_lines+1, 0);
	//vt_reverse(1);
	printf("%s", sep);
	paint_video(lastwin == UPPER ? &upper : &lower);
	vt_update();
}

/* Show a (help) screen, wait, then refresh the screen */
void vt_showscreen(title, text)
char *title;
char *text[];
{
	int i;

	vt_clrscr();
	vt_setscroll(0,0);
	vt_goto(1,1);
	vt_bold(1);
	printf("%s\r\n\r\n", title);
	vt_resetattr();
	for ( i=0; text[i]; ++i )
		printf("%s\r\n", text[i]);
	printf("\n");
	vt_reverse(1);
	printf("Press any key to continue: ");
	vt_resetattr();
	vt_update();
	getchar();
	vt_redraw();
}

/* Clean up the screen and clear the scrolling regions */
void end_vt100()
{
	int i;

	if ( ! setup_vt100 )
		return;

	/* Clear any old setup */
	lastwin=(-1);
	for ( i=0; i<upper.rows; ++i )
		(void) free(upper.videomem[i]);
	(void) free(upper.videomem);
	(void) free(upper.tabstops);
	for ( i=0; i<lower.rows; ++i )
		(void) free(lower.videomem[i]);
	(void) free(lower.videomem);
	(void) free(lower.tabstops);
	setup_vt100=0;

	/* Fix up the display */
	vt_setscroll(0,0);
	vt_goto(physical.rows, 1);
	vt_clreol();
	vt_resetattr();
	vt_update();
}

