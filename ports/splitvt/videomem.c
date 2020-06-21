
/* This file holds the functions for manipulating video memory */

#include	<stdio.h>
#include	<stdlib.h>
#include	"video.h"
#include	"terminal.h"

/* This function returns a pointer to a video memory area of ints.
   Integers are used to encode both the characters and the flags.
   If this function fails, it should be a fatal error.  Allocated
   memory is not freed if the function fails.
 */

int **alloc_video(rows, cols)
int rows;
int cols;
{
	int **videomem;
	int i, j;

	/* Allocate row pointers */
	if ( (videomem=(int **)malloc(rows*sizeof(int *))) == NULL )
		return(NULL);

	/* Allocate the columns for each row */
	for ( i=0; i<rows; ++i ) {
		if ( (videomem[i]=(int *)malloc(cols*sizeof(int))) == NULL )
			return(NULL);
		for ( j=0; j<cols; ++j )
			videomem[i][j]=0;
	}
	return(videomem);
}

/* This function copies an existing window to a new buffer, 
   truncating lines if necessary, and translates the cursor position  */
void copy_video(win, newarea, rows, cols, newcursor)
window *win;
int **newarea;
int rows;
int cols;
position *newcursor;
{
	int i, j, ni, nj;

	/* Copy from the bottom up... */
	newcursor->x=0;
	for ( i=win->rows, ni=rows; i && ni; --i, --ni ) {
		if ( win->cursor.x == i ) {
			if ( (newcursor->x=(i+rows-win->rows)) < 1 )
				newcursor->x=1;
		}
		for ( j=0, nj=0; (j<win->cols) && (nj<cols); ++j, ++nj )
			newarea[ni-1][nj]=win->videomem[i-1][j];
	}
	if ( ! newcursor->x )	/* We never reached the old cursor */
		newcursor->x=1;
	newcursor->y=(win->cursor.y > cols ? cols : win->cursor.y);
}

/* This function adds a character to the video memory at the cursor position */
void add_video(win, c)
window *win;
char c;
{
	win->videomem[win->cursor.x - 1][win->cursor.y - 1] = (int)c;
	win->videomem[win->cursor.x - 1][win->cursor.y - 1] |= 
						(((int)win->textattr)<<8);
}

/* This function returns a character from video at a specific position */
int get_video(win, x, y)
window *win;
int x, y;
{
	return(win->videomem[x-1][y-1]);
}

/* This function sets a character position in video memory */
void put_video(c, win, x, y)
int c;
window *win;
int x, y;
{
	win->videomem[x-1][y-1]=c;
}

/* This function returns the array index of the end of the specified line
   in the specified window.  lineno should start as 1 for the first line.
*/
static int video_eol(win, lineno)
window *win;
int lineno;
{
	int eol=(-1), j;

	for ( j=0; j<win->cols; ++j ) {
		if ( (win->videomem[lineno-1][j]&0xFF) != 0 )
			eol=j;
	}
	++eol;
	return(eol);
}

/* This function copies a specified section of video memory to a buffer */
/* x1 is the first line, x2 is the second line, y1 is the y on the first
   line, and y2 is the y on the last line.
*/
void getsel_video(win, buf, maxlen, x1, x2, y1, y2)
window *win;
char *buf;
int maxlen;
int x1, x2;
int y1, y2;
{
	int l=0, i, j, eol, eos;

	--maxlen;	/* Account for trailing null */
	for ( i=(x1-1); (i<x2 && l<maxlen); ++i ) {
		eol=video_eol(win, i+1);
		if ( i == (x1-1) ) {
			j=(y1-1);
			eos=eol;
		} else
			j=0;
		if ( i == (x2-1) )
			eos=((y2-1) < eol ? (y2-1) : eol);
		for ( ; j<eos; ++j ) {
			if ( (win->videomem[i][j]&0xFF) == '\0' )
				*(buf++) = ' ';
			else
				*(buf++) = (win->videomem[i][j]&0xFF);
			++l;
		}
		if ( l<maxlen && j >= eol ) {
			*(buf++) = '\r';
			++l;
		}
	}
	*buf='\0';
	return;
}

/* This function clears the SELECTED bit in a whole window */
void clrsel_video(win)
window *win;
{
	int i, j;

	for ( i=0; i<win->rows; ++i ) {
		for ( j=0; j<win->cols; ++j ) {
			if ( ((win->videomem[i][j]>>8)&SELECTED) == SELECTED )
				win->videomem[i][j] &= ~(SELECTED<<8);
		}
	}
}

/* This function erases a specified section of video memory */
void erase_video(win, x1, x2, y1, y2)
window *win;
int x1, x2;
int y1, y2;
{
	int i, j;

	for ( i=(x1-1); i<x2; ++i ) {
		for ( j=(y1-1); j<y2; ++j )
			win->videomem[i][j] = 0;
	}
	return;
}

/* This function "scrolls" video memory forward */
void scroll_video(win, numlines)
window *win;
int numlines;
{
	int i, n, *tmp;

	/* Don't scroll memory if cursor is outside of scroll region */
	if ( win->cursor.x > win->scr_lower )
		return;

	/* Otherwise, scroll away! */
	for ( i=0; i<numlines; ++i ) {
		/* Clear out the line that has been scrolled off the edge */
		tmp=win->videomem[win->scr_upper-1];
		for ( n=0; n<win->cols; ++n )
			tmp[n]=0;

		/* Now perform the scroll */
		for ( n=(win->scr_upper-1); n<(win->scr_lower-1); ++n )
			win->videomem[n]=win->videomem[n+1];
		win->videomem[n]=tmp;
	}
	/* That's it! */
	return;
}

/* This function "scrolls" video memory backward */
void revscroll_video(win, numlines)
window *win;
int numlines;
{
	int i, n, *tmp;

	/* Don't scroll memory if cursor is outside of scroll region */
	if ( win->cursor.x < win->scr_upper )
		return;

	/* Otherwise, scroll away! */
	for ( i=0; i<numlines; ++i ) {
		/* Clear out the line that has been scrolled off the edge */
		tmp=win->videomem[win->scr_lower-1];
		for ( n=0; n<win->cols; ++n )
			tmp[n]=0;

		/* Now perform the scroll */
		for ( n=(win->scr_lower-1); n>(win->scr_upper-1); --n )
			win->videomem[n]=win->videomem[n-1];
		win->videomem[n]=tmp;
	}
	/* That's it! */
	return;
}

/* This function inserts nulls in a line, shifting everything right */
void rshift_video(win, numcols)
window *win;
int numcols;
{
	int i;

	for ( i=(win->cols-1); i > (win->cursor.y-1); --i ) {
		if ( (i-numcols) >= 0 )
			win->videomem[win->cursor.x-1][i] = 
				win->videomem[win->cursor.x-1][i-numcols];
		else
			win->videomem[win->cursor.x-1][i] = 0;
	}
}

int check_attr(int pixel, int lastattr, unsigned char* currattr){
	unsigned char simplepixel, lastpixel;
	unsigned char change;
	unsigned char selected, reversed;

	/* Set the simplepixel REVERSE bit if SELECTED ^ REVERSE */
	simplepixel = ((pixel>>8)&(~SELECTED)&(~REVERSE));
	selected = ( ((pixel>>8)&(~SELECTED)) ? 1 : 0 );
	reversed = ( ((pixel>>8)&(~REVERSE)) ? 1 : 0 );
	if ( selected ^ reversed )
		simplepixel |= REVERSE;

	/* Set the lastpixel REVERSE bit if SELECTED ^ REVERSE */
	lastpixel = ((lastattr>>8)&(~SELECTED)&(~REVERSE));
	selected = ( ((lastattr>>8)&(~SELECTED)) ? 1 : 0 );
	reversed = ( ((lastattr>>8)&(~REVERSE)) ? 1 : 0 );
	if ( selected ^ reversed )
		lastpixel |= REVERSE;

	/* Thanks to Dan Dorough for the XOR code */
checkchange:
	change = (lastpixel ^ simplepixel);
	if ( change ) {
		if ( change&REVERSE ) {
			if ( (*currattr)&REVERSE ) {
#define GOTO_HACK	/* vt_reverse(0) doesn't work on xterms :-( */
#ifdef GOTO_HACK	/* This goto hack resets all current attributes */
				vt_resetattr();
				*currattr &= ~REVERSE;
				simplepixel=0;
				lastpixel &= (~REVERSE);
				goto checkchange;
#else /* ideal code */
				vt_reverse(0);
				*currattr &= ~REVERSE;
#endif
			} else {
				vt_reverse(1);
				*currattr |= REVERSE;
			}
		}
		if ( change&BOLD ) {
			if ( (*currattr)&BOLD ) {
				vt_bold(0);
				*currattr &= ~BOLD;
			} else {
				vt_bold(1);
				*currattr |= BOLD;
			}
		}
		if ( change&UNDERLINE ) {
			if ( (*currattr)&UNDERLINE ) {
				vt_underline(0);
				*currattr &= ~UNDERLINE;
			} else {
				vt_underline(1);
				*currattr |= UNDERLINE;
			}
		}
		if ( change&BLINK ) {
			if ( (*currattr)&BLINK ) {
				vt_blink(0);
				*currattr &= ~BLINK;
			} else {
				vt_blink(1);
				*currattr |= BLINK;
			}
		}
	}
	return(pixel);
}

void paint_video(win)
window *win;
{
	unsigned char change, on=NORMAL;
	int i, j, oldattr=0;

	vt_setscroll(0,0);
	vt_resetattr();
	vt_goto(1+win->row_offset, 1);
	for ( i=0; i<win->rows; ++i ) {
		for ( j=0; j<win->cols; ++j ) {
			if ( win->videomem[i][j]&0xFF ) {
				oldattr=check_attr(win->videomem[i][j],
						 		oldattr, &on);
				printf("%c", (win->videomem[i][j]&0xFF));
			} else {
				oldattr=0;
				if ( on != NORMAL ) {
					vt_resetattr();
					on=NORMAL;
				}
				printf(" ");
			}
		}
		printf("\r");
		vt_down(1);		/* This shouldn't cause scroll */
	}
	vt_setscroll(win->scr_upper+win->row_offset, 
					win->scr_lower+win->row_offset);
	vt_goto(win->cursor.x+win->row_offset, win->cursor.y);
	vt_update();
}
