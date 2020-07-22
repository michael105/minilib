#if 0
mini_start

mini_scandir
mini_malloc
mini_prints
mini_writes

mini_eprintfs

mini_buf 256

INCLUDESRC

return
#endif

typedef enum {
		a=0x1,b=0x2,c=0x4,d=0x8,e=0x10,
		f=0x20,g=0x40,h=0x80,i=0x100,j=0x200,
		k=0x400,l=0x800,m=0x1000,n=0x2000,o=0x4000,
		p=0x8000,q=0x10000,r=0x20000,s=0x40000,
		t=0x80000,u=0x100000,v=0x200000,w=0x400000,
		x=0x800000,y=0x1000000,z=0x2000000 } mini_shortopts;

typedef struct {
		mini_shortopts shortopt;
		int (*callback)(char **argv);
} shortopt_callback;

void usage(){
		writes("Usage: ls \n");
		exit(1);
}


void noopt(char *c){
		usage();
}

char** parseopts( char **argv, void (*unrecognized)(char *c),
				mini_shortopts shortopts, int* shortoptions, shortopt_callback callbacks[] ){
		int tmp = 0;
		for ( *argv++; argv[0] && argv[0][0] == '-'; *argv++ ){
				for (  char *c = argv[0]+1; *c != 0 && *c!='-'; c++ ){
						int ti; char option;
						tmp |= (ti=1<< ((option=*c-97) ) );
						if ( ! ( (shortopts) & ti ) ){
								if ( unrecognized )
										unrecognized(c);
								else {
										eprintfs("Unrecognized option: -%c\n",*c);
										exit(1);
								}
						}
						if ( *c && *c=='-' ){
								// long option
						}
				}
		}




		return(0);
}



int main(int argc, char **argv){
		
		argv = parseopts( argv, &usage, a|b, 0,0);



		return(0);
}
