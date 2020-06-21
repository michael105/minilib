
/* The screen locking module for splitvt */

#include	<stdio.h>
#include	<pwd.h>
#include	"vt100.h"

#define UNLOCKED	0
#define ENTERED1	1
#define ENTERED2	2
#define LOCKED		3

static int lock_state=UNLOCKED;

/* The number of characters entered (prevent overflow) */
static int cnt=0;

static char entered1[BUFSIZ], entered2[BUFSIZ];
static char *nextbuf=entered1;
static struct passwd *pw=NULL;

/* Used to release our input when the screen is unlocked */
extern void (*do_input)(), normal_input();

/* Since this function is called as an input function, we need to handle
   all state here. 
*/
void lock_screen(c)
char c;
{
	char message[512];

	if ( c == '\r' ) {
		switch (lock_state) {
			case UNLOCKED:	/* No password entered, cancel lock */
					vt_info("Lock cancelled.");
					reset_bar(1);
					do_input=normal_input;
					break;
			case ENTERED1:	/* First password has been entered */
					*nextbuf='\0';
					nextbuf=entered2;
					cnt=0;
					vt_info("Re-enter password: ");
					lock_state=ENTERED2;
					break;
			case ENTERED2:	/* Second password has been entered */
					*nextbuf='\0';
					nextbuf=entered1;
					cnt=0;
					if (strcmp(entered1, entered2) == 0) {
						sprintf(message,
				"Screen locked by %s.  Enter password: ", 
							pw?pw->pw_name:"user");
						vt_info(message);
						lock_state=LOCKED;
					} else {
						sprintf(message,
				"Passwords do not match.  Try again: ");
						vt_info(message);
						lock_state=UNLOCKED;
					}
					break;
			case LOCKED:	/* Verify password  */
					*nextbuf='\0';
					nextbuf=entered1;
					cnt=0;
					if (strcmp(entered1, entered2) == 0) {
						vt_info(NULL);
						do_input=normal_input;
						lock_state=UNLOCKED;
					} else {
						sprintf(message,
					"Password incorrect.  Try again: ");
						vt_info(message);
					}
					break;
			default:	/* What?? */
					break;
		}
	} else {
		switch (lock_state) {
			case UNLOCKED:	/* No password entered, start lock */
					pw=getpwuid(getuid()); /* Can fail */
					nextbuf=entered1;
					lock_state=ENTERED1;
					/* Fall through */
			case ENTERED1:
			case ENTERED2:
			case LOCKED:
					++cnt;
					if (cnt < BUFSIZ-1) { *(nextbuf++) = c; cnt++; }
					break;
		}
	}
	return;
}

