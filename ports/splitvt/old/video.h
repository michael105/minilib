
/* Definitions of character sets and types of character sets */
#define NCHARSETS	2
#define G0		0
#define G1		1
#define UK_CHARSET	0x01
#define US_CHARSET	0x02
#define GRAPHICS	0x04

/* Variables */
#define MAX_PARAMS	12	/* Max number of params for an escape */

typedef struct {        /* Cursor coordinate structure */
        int x;          /* Line position */
        int y;          /* Column position */
        } position;

enum keystate { normal, application };

typedef struct {
	position cursor;		/* The current position of cursor */
	int rows;			/* The number of rows in window */
	int cols;			/* The number of cols in window */
	int row_offset;			/* The physical offset of upper edge */
	int scr_upper;			/* Upper limit of scroll region */
	int scr_lower;			/* Lower limit of scroll region */
	void (*process_char)();		/* Next output processing function */
	enum keystate key_state;		/* For vt100 keypad */
	unsigned char charset[NCHARSETS];	/* Current character set */
	unsigned char textattr;			/* Current text attributes */
	int esc_param[MAX_PARAMS], *cur_param;	/* Escape parameters */
	int param_idx;			/* Current index into esc_param */
	int **videomem;			/* Storage for the virtual screen */
	int *tabstops;			/* Tabstops in the columns */
	position saved_cursor;		/* Saved cursor position */
	unsigned char saved_textattr;	/* Saved text attributes */
	} window;

struct physical {
	window *subwins[2];	/* The smaller, split sub-windows */
	int rows;		/* The number of rows on the screen */
	int cols;		/* The number of cols on the screen */
};

extern int TABSTOP;			/* Default value for tabstops */

/* Definitions of text attributes */
#define NORMAL		0x00
#define BOLD		0x01
#define UNDERLINE	0x02
#define BLINK		0x04
#define REVERSE		0x08
#define SELECTED	0xF0

int **alloc_video();		/* Allocate a video memory buffer */
void copy_video();		/* Copy a video buffer to an empty one */
void add_video();		/* Add a character to a video buffer */
void erase_video();		/* Erase a two-dimensional section */
void scroll_video();		/* Scroll a section of the buffer */
void revscroll_video();		/* Reverse-scroll a section of the buffer */
void rshift_video();		/* Shift part of a line right */
void paint_video();		/* Repaint the video buffer onto the screen */
void getsel_video();		/* Get a selection from the video buffer */
void clrsel_video();		/* Clear a selection from the video buffer */
void put_video();		/* Set a character in the video buffer */
int  get_video();		/* Get a character from the video buffer */
