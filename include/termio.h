#ifdef mini_termio

//+doc termios structures and definitions
//+def termio

typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;

#define NCCS 32


struct termios {
	tcflag_t c_iflag;
	tcflag_t c_oflag;
	tcflag_t c_cflag;
	tcflag_t c_lflag;
	cc_t c_line;
	cc_t c_cc[NCCS];
	speed_t __c_ispeed;
	speed_t __c_ospeed;
};

// the old termio struct
#define NCC 8
struct termio
{
		unsigned short int c_iflag;   /* input mode flags */
		unsigned short int c_oflag;   /* output mode flags */
		unsigned short int c_cflag;   /* control mode flags */
		unsigned short int c_lflag;   /* local mode flags */
		unsigned char c_line;   /* line discipline */
		unsigned char c_cc[NCC];    /* control characters */
};


#endif
