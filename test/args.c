#define mini_buf 4096
#define mini_strcmp
#define mini_printf
#define mini_getenv
#define mini_start
#define INCLUDESRC
#include "minilib.h"




int main(int argc, char **argv, char **env ){
		printf("argc: %d\n", argc);
		printf("argv: %s\n", argv[0]);
		printf("argv[argc-1]: %s\n", argv[argc-1]);
		for ( int a =0; env[a]; a++ ){
				if ( (env[a][0] == 'T') && (env[a][1] == 'T') && (env[a][2] == 'M') ){
						printf("env: %s\n", env[a]);
				}
		}
		char *c = getenv( "TERM");
		if ( c ){
				printf("mini_env: %s\n", c );
		}
		return(0);
}
