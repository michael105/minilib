
/* The cut-paste module for splitvt */

#include	<stdio.h>
#include	<string.h>
#include	"vt100.h"
#include	"video.h"

#define RIGHT 0x01
#define LEFT  0x02
#define Min(A,B)	((A>B)?B:A)
#define Max(A,B)	((A>B)?A:B)

/* Variables used by the cut-paste motion functions */
static int marked, oldattr;
static unsigned char on;

extern struct physical physical;
static int lastdirection=0;

/* This function assumes that it alone will print selected text */
static void put_sel_char(win, x, y, oldattr, on, direction)
window *win;
int x, y;
int *oldattr;
unsigned char *on;
int direction;
{
	int c, selected=0;

	c = get_video(win, x, y);
	/* Toggle selection highlighting */
	if ( direction ) {
/*fprintf(stderr, "Turning %s...\n", direction == RIGHT ? "right" : "left");*/
		if ( lastdirection && lastdirection != direction )
			/* We turned... */ ;
		else {
			c ^= (SELECTED<<8);
			selected = ( ((c>>8)&SELECTED) ? 1 : 0 );
		}
		lastdirection=direction;
	} else
		c ^= (SELECTED<<8);

	(*oldattr)=check_attr(c, *oldattr, on);
	put_video(c, win, x, y);

	if ( c&0xFF )
		printf("%c", c&0xFF);
	else
		printf(" ");

	if ( direction ) {
		if ( !selected ) {
			if ( direction == RIGHT ) {
				if ( y < win->cols )
					++y;
				else
					goto end;
			} else {
				if ( y > 1 )
					--y;
				else
					goto end;
				vt_left(2);
			}
			c = get_video(win, x, y);
			if ( c&0xFF )
				printf("%c", c&0xFF);
			else
				printf(" ");
			vt_left(1);
		} else if ( direction == LEFT )
			vt_left(2);
	}
end:
	fflush(stdout);
	return;
}


/* If this function returns 0, no selection was made */

static char *extract_sel(win, buf, len, mark1, mark2)
window *win;
char *buf;
int len;
position *mark1, *mark2;
{
	int selection=0;
	position startsel, endsel;

	if ( mark1->x == mark2->x )
	{
		if ( mark1->y == mark2->y ) {
			vt_info("Selection cancelled.");
			clrsel_video(win);
			reset_bar(1);
			return(NULL);
		}
		if ( mark1->y < mark2->y ) {
			startsel = (*mark1);
			endsel = (*mark2);
			++endsel.y;
		} else {
			startsel = (*mark2);
			endsel = (*mark1);
			++endsel.y;
		}
	} else if ( mark1->x < mark2->x ) {
		startsel = (*mark1);
		endsel = (*mark2);
	} else if ( mark1->x > mark2->x ) {
		startsel = (*mark2);
		endsel = (*mark1);
	}
	getsel_video(win,buf,len, startsel.x, endsel.x, startsel.y, endsel.y);
	clrsel_video(win);
	vt_info("Region selected.");
	reset_bar(1);
	return(buf);
}

static void line_down(win, cursor)
window *win;
position *cursor;
{
	int j;

	if ( cursor->x < win->rows ) {
		if ( marked ) {
			for (j=cursor->y; j<win->cols; ++j) {
		put_sel_char(win, cursor->x, j, &oldattr, &on, 0);
			}
			printf("\r");
			vt_down(1);
			++cursor->x;
			for ( j=1; j<cursor->y; ++j ) {
		put_sel_char(win, cursor->x, j, &oldattr, &on, 0);
			}
		} else {
			vt_down(1);
			++cursor->x;
		}
	}
}

static void line_up(win, cursor)
window *win;
position *cursor;
{
	int j;

	if ( cursor->x > 1 ) {
		--cursor->x;
		if ( marked ) {
			vt_up(1);
			for (j=cursor->y; j<win->cols; ++j) {
		put_sel_char(win, cursor->x, j, &oldattr, &on, 0);
			}
			printf("\r");
			vt_down(1);
			++cursor->x;
			for ( j=1; j<cursor->y; ++j ) {
		put_sel_char(win, cursor->x, j, &oldattr, &on, 0);
			}
			vt_up(1);
			--cursor->x;
		} else 
			vt_up(1);
	}
}

static void move_left(win, cursor)
window *win;
position *cursor;
{
	if ( cursor->y > 1 ) {
		if ( marked ) {
	put_sel_char(win, cursor->x, cursor->y, &oldattr, &on, LEFT);
		} else
			vt_left(1);
		--cursor->y;
	}
}

static void move_right(win, cursor)
window *win;
position *cursor;
{
	if ( cursor->y < win->cols ) {
		if ( marked )
	put_sel_char(win, cursor->x, cursor->y, &oldattr, &on, RIGHT);
		else
			vt_right(1);
		++cursor->y;
	}
}

static int use_xcb=0;	/* Do we use xcb to access X selection buffers? */
void vt_initsel()
{
	extern char *pathsearch();	/* From misc.c */
	char *display;

#ifdef USE_XCB
	/* Use xcb if we have both an X display and the command. */
	/* xcb needs to support my hacked '-R' option. */
	if ( (display=(char *)getenv("DISPLAY")) && pathsearch("xcb", 1) )
		use_xcb=1;
	else
#endif
		use_xcb=0;
}

static char selbuf[BUFSIZ];
char *vt_getselbuf()
{
	FILE *safe_popen();		/* From misc.c */
	FILE *xcb;
	char buffer[BUFSIZ];
	int len;

	if ( use_xcb ) {
		if ( (xcb=safe_popen("xcb -S 0 && xcb -p 0", "r")) == NULL )
			return(selbuf);
		len=fread(buffer, sizeof(char), BUFSIZ-1, xcb);
		(void) safe_pclose(xcb);

		if ( len > 0 ) {
			buffer[len]='\0';
			strcpy(selbuf, buffer);
		}
	}
	return(selbuf);
}
char *vt_setselbuf(buffer)
char *buffer;
{
	FILE *safe_popen();		/* From misc.c */
	FILE *xcb;
	
	strncpy(selbuf, buffer, BUFSIZ-1);
	selbuf[BUFSIZ-1]='\0';
	if (use_xcb && (xcb=safe_popen("xcb -s 0; xcb -RT 0", "w")) != NULL) {
		(void) fwrite(selbuf, sizeof(char), strlen(selbuf), xcb);
		(void) safe_pclose(xcb);
	}
	return(selbuf);
}

/* Get a window selection */
char *vt_getsel(win, buf, len)
int win;
char *buf;
int len;
{
	int c, state=NORMAL;
	position here, cursor, mark1, mark2;
	window *thiswin;
	
	thiswin = physical.subwins[win];
	here=cursor=thiswin->cursor;
	marked=lastdirection=0;
	vt_info("Mark beginning of selection: ");
	while ( (c=getchar()) != EOF ) {
		switch (c) {
			case 'j':	/* Move down one line */
					line_down(thiswin, &cursor);
					break;
			case 'k':	/* Move up one line */
					line_up(thiswin, &cursor);
					break;
			case 'l':	/* Move right one char */
					move_right(thiswin, &cursor);
					break;
			case 'h':	/* Move left one char */
					move_left(thiswin, &cursor);
					break;
			case ' ':	/* Mark selection */
					if ( marked ) {
						mark2=cursor;
						/* Copy and deselect area */
						buf=extract_sel(thiswin, buf,
							len, &mark1, &mark2); 
						/* Repaint the screen */
						paint_video(thiswin);
						return(buf);
					} else {
						mark1=cursor;
						oldattr = get_video(thiswin,
							mark1.x, mark1.y);
						on = (oldattr>>8);
						marked=1;
						vt_info(
						"Mark end of selection: ");
						/* Set reverse here */
						vt_update();
					}
					break;
			case '\033':
			case 'q':	/* Cancel selection */
					clrsel_video(thiswin);
					vt_goto((here.x+thiswin->row_offset),
									here.y);
					vt_info("Selection cancelled.");
					sleep(1);
					/* Repaint the screen */
					paint_video(thiswin);
					return(NULL);
					break;
			default:	break;
		}
	}
	return;	/* Hopefully, we never reach here */
}


/* Set a window selection */
char *vt_setsel(buf, len, startx, endx, starty, endy)
char *buf;
int len;
int startx, starty;
int endx, endy;
{
	window *thiswin;

	/* If nothing selected, return old selection */
	if ( (startx == endx) && (starty == endy) )
		return(buf);

	if ( startx == (physical.subwins[LOWER])->row_offset ) {
		/* Separator bar; return */
		return(buf);
	} else if ( startx < (physical.subwins[LOWER])->row_offset ) {
		thiswin = physical.subwins[UPPER];
	} else {
		thiswin = physical.subwins[LOWER];
		startx-=thiswin->row_offset;
		endx-=thiswin->row_offset;
	}
	getsel_video(thiswin, buf, len, startx, endx, starty, endy);
	return(buf);
}
