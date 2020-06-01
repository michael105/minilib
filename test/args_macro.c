#define mini_start
#define mini_buf 1024
#define mini_printf
#define mini_printsl
#define mini_fwrites
#define mini_write
#define mini_atoi
#define mini_itodec
#define mini_itobin
#define mini_GETOPTS
#define INCLUDESRC



#include "minilib.h"

//#define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

//#define TEST(...) test( VARARG(SHIFT(__VA_ARGS__),0) , VARARG(SHIFT(ARG(__VA_ARGS__)),0),  VARARG(SHIFT(ARG(__VA_ARGS__)),0) )

//#define T(...) t2( VARARG(SHIFT(__VA_ARGS__) + T( SHIFT(__VA_ARGS__))))




//#define OPT(x) (1<<(x-63)) 


#define OPTIONS(var, opts) 	{ \
				enum options { a=0x1,b=0x2,c=0x4,d=0x8,e=0x10,f=0x20,g=0x40,h=0x80,i=0x100,j=0x200,\
						k=0x400,l=0x800,m=0x1000,n=0x2000,o=0x4000,p=0x8000,q=0x10000,r=0x20000,s=0x40000,\
						t=0x80000,u=0x100000,v=0x200000,w=0x400000,x=0x800000,y=0x1000000,z=0x2000000 };\
				var = opts;\
		}




int main(int argc, char **argv, char **env ){

		int opt;
		OPTIONS(opt, a+c+h );

		printf("opts: %b\n", opt );
		int args = 0;

		for ( int a =1; argv[a]; a++ ){
				if ( argv[a][0] == '-' ){
						for ( int b=1; argv[a][b]; b++ ){
								int t;
								if ( opt & (t=1<< (argv[a][b]-97) ) )
										args |= t;
								else
										printf ( "No such arg: -%c\n", argv[a][b] );

						}
				}
		}

		printf("args: %b\n", args );


	 	int p;
		p= PARSEOPTS_short( opt, argv, a+c+l, { fprintf(stderr, "Unrecognized option: -%c\n",option); } );

		printf("args: %b\n", args );
		printf("p: %d\n", p );

		return(0);
}
