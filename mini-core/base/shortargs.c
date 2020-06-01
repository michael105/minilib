#if 0
mini_start
mini_writes
mini_chroot
INCLUDESRC
HEADERGUARDS
shrinkelf
return
#endif
#include "minilib.h"


static struct {
	const char *argv0;
	bool all : 1;
	int opts;
} opt;

//TODO: this is worth a separate header file within minilib.
// It's simple and has low footprint.
enum options { a, l, h };
#define SET_OPT(args,opt) { args = ( args | (0x1 << opt) ); }
#define GET_OPT(args,opt)  ( args & (0x1 << opt) )
//#define SET_OPT(args,opt) { args = ( args | OPTBIT_##opt ) }
//#define OPTBIT_a 0x1

#define OPT(a) (1<<(a-96)) 
#define OPTIONS(opt) ( (1<<('a'-96)) | 

/* Usage: ls [-a] [PATH...] */
int main(int argc, const char *argv[])
{
	int i;

	int args = 0;



	for (i = 1; i < argc; i++) {
		if (argv[i][0] != '-') {
			break;
		} 
		switch (argv[i][1]) {
			case 'a':
				opt.all = 1;
				SET_OPT(args,a);
				break;
			case 'l':
				SET_OPT(args,l);
				break;
			case 'h':
				writes( "ls [-a] [-l] [-h] [file(s) / dir(s)]\n" );
				return(0);
		default:
			fprintfs(stderr, "ls: invalid argument: %s\n", argv[i]);
			return(1);
		}
	}
	//printf("opt: %d\n", args );

	if (i == argc) {
		if (list(".", 0, args))
			return 1;
	} else if (i == argc - 1) {
		if (list(argv[i], 0, args))
			return 1;
	} else for (; i < argc; i++) {
		if (list(argv[i], 1, args))
			return 1;
	}
	return(0);
}
