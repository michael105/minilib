
/* Global functions exported by vt100.c */

extern char *init_vt100();		/* Initialize the window */
extern void  set_win();			/* Move the cursor to current window */
extern int   vt_write();		/* Write a buffer to a window */
extern char  vt_prompt();		/* Prompt the user and return a char */
extern void  vt_info();			/* Print out an info message */
extern char *vt_getsel();		/* Get a selection on the window */
extern char *vt_setselbuf();		/* Set the selection buffer */
extern char *vt_getselbuf();		/* Get the selection buffer */
extern void  vt_redraw();		/* Repaint a window from RAM */
extern void  vt_showscreen();		/* Show a (help) screen */
extern void  end_vt100();		/* End the vt100 scrolling and such */

/* Handy definitions, sometimes passed to vt100.c functions */

#define UPPER	0				/* The upper window */
#define LOWER	1				/* The lower window */
#define	ESC	'\033'				/* ^[ */

/* These four variables are accessable to the calling program */
extern int UU_lines;	/* The user requested lines for the upper window */
extern int WU_lines;	/* The number of lines for the upper window */
extern int WL_lines;	/* The number of lines for the lower window */
extern int W_columns;	/* The number of columns per window */



extern int check_attr(int pixel, int lastattr, unsigned char* currattr);


