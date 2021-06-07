#if 0
mini_start
mini_strcmp
mini_prints


INCLUDESRC

return
#endif

int main(int argc, char **argv){
		
#define cmp(a,b) prints("strcmp("a","b")"); if ( strcmp(a,b) > 0 ) prints(">0\n"); else if ( strcmp(a,b)<0 ) prints("<0\n"); else prints("0\n");

		cmp( "hello", "someth" )
		cmp( "hello", "soth" )
		cmp( "hello", "sth" )
		cmp( "xhello", "soth" )
		cmp( "xhlo", "soth" )
		cmp( "xlo", "soth" )

		return(0);
}
