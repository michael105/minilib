#include "minilib.h"


int main(int argc, char **argv, char **env ){
		printf("argc: %d\n", argc);
		printf("argv: %s\n", argv[0]);
		printf("argv[argc-1]: %s\n", argv[argc-1]);
		for ( int a =0; env[a]; a++ )
				printf("env: %s\n", env[a]);
		return(0);
}
