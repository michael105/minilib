
#ifdef SPLITVT_SOURCE
#include "vt100.h"
#include "video.h"
#endif

#define REPORT_SELECTION

/* Definitions for button_state bitmasks */
#define BUTTON_MASK		0x03
#define BUTTON_1		0x00
#define BUTTON_2		0x01
#define BUTTON_3		0x02
#define RELEASE			0x03
//#define SHIFT			0x04
#define META			0x08
#define CONTROL			0x0F
#define SELECTED		0xF0

struct event {
	int happening;
	unsigned char button_state;
	unsigned int x;
	unsigned int y;
#ifdef REPORT_SELECTION
	struct {
		int begin_col;
		int begin_row;
		int end_col;
		int end_row;
		} selection;
#endif
};
#define BUTTON_ISSET(X, B)	((X.button_state&BUTTON_MASK) == B)
   
extern int terminal_input;	/* Set true if event_getc() can read input */

extern int  event_init();
extern int  event_getc();
extern void event_quit();
