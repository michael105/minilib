
/* Miscellaneous defines and variables for the main splitvt module */

/* Returns true if 'ch' is a whitespace character */
#define WHITESPACE(ch)	((ch == ' ') || (ch == '\t') || (ch == '\n'))

#define toctrl(X)	(X-'@')		/* uppercase-to-control macro */
#define unctrl(X)	(X+'@')		/* control-to-uppercase macro */

#define SWITCH	toctrl('W')	/* Switch window key */
#define QUOTE	toctrl('V')	/* Quote next character key */
#define COMMAND	toctrl('O')	/* Go into command mode */

/* The command prompt shown by vt_prompt() */
#define PROMPT	"splitvt command: "

/* A Macro to set the window in the proper place.   */
#define CUR_WIN()	((thisfd == topfd) ? UPPER : LOWER)
#define SET_WIN()	set_win(CUR_WIN())

/* Special characters (from splitvt.c) */
extern char	command_c, switch_c, quote_c;
extern int	dologin;	/* Do the shells run as login shells? */

/* The command to run in each window */
#define MAX_ARGS 0xff
extern char *upper_args[MAX_ARGS+1], *lower_args[MAX_ARGS+1];

/* The name of the startup file to parse */
extern char *startupfile;

/* The number of lines requested for the upper window (from vt100.c) */
extern int UU_lines;

/* An option to start with the bottom window in focus (from splitvt.c) */
extern int stbottom;

/* Functions exported from splitvt.c */
extern void reset_bar();
