
/* These are the screen manipulation routines in terminal.c that are 
   exported for use in vt100.c
*/

extern char *vt_initterm();	/* Initialize the termcap, return NULL if successful */
extern void vt_bell();		/* Sound the terminal bell */
extern void vt_goto();		/* Goto a specific x y coordinate */
extern void vt_up();		/* Move cursor up */
extern void vt_down();		/* Move cursor down */
extern void vt_right();		/* Move cursor right */
extern void vt_left();		/* Move cursor left */
extern void vt_clrscr();	/* Clear whole screen */
extern void vt_clreos();	/* Clear to end of screen, include currline */
extern void vt_clrbgs();	/* Clear to beginning of screen, include currline */
extern void vt_clrline();	/* Clear line under cursor */
extern void vt_clreol();	/* Clear to the end of line */
extern void vt_clrbgl();	/* Clear to the beginning of line, including cursor */
extern void vt_delline();	/* Delete line under cursor */
extern void vt_delunder();	/* Delete character under cursor */
extern void vt_insline();	/* Insert open line under cursor */
extern void vt_bold();		/* Toggle bold display */
extern void vt_underline();	/* Toggle underlined display */
extern void vt_blink();		/* Toggle blinking display */
extern void vt_reverse();	/* Toggle reversed display */
extern void vt_setattr();	/* Set display attributes */
extern void vt_setfg();		/* Set foreground color */
extern void vt_setbg();		/* Set background color */
extern void vt_resetattr();	/* Reset display attributes */
extern void vt_setscroll();	/* Set scrolling region */
extern void vt_revscroll();	/* Reverse scroll */
extern void vt_altcharset();	/* Toggle alternate character set (graphics) */
extern void vt_savecursor();	/* Save current hardware cursor position */
extern void vt_restcursor();	/* Restore saved hardware cursor position */
extern void vt_keystate();	/* Set and reset application mode keys */
extern void vt_widemode();	/* Set and reset 132 column mode */
extern void vt_rows_cols();	/* Return the rows and cols from termcap */
extern void vt_insertchar();	/* Insert character in line */
extern void vt_update();	/* Flush any pending output */
