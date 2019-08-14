#if 0
mini_buf 256
mini_start
mini_printf
mini_rand
mini_srand
mini_itodec
mini_atoi
mini_fread
mini_fclose
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[] ){
		int i = rand();
		printf("Got: %d\n",i);

		srand(6621876);

		for ( int a=0; a<20; a++ ){
		for ( i=0; i<6; i++ ){
				printf("%u  ",rand());
		}
		printf("\n");
		}

		int t;
		//srand(time(t));// seems to work

		for ( int a=0; a<20; a++ ){
		for ( i=0; i<6; i++ ){
				printf("%u  ",rand());
		}
		printf("\n");
		}


		return(0);
}
