#if 0
mini_start
mini_fopen
mini_fclose
mini_fprintf
mini_printf
mini_print
mini_itodec
mini_itohex
mini_fileno
mini_puts
mini_read
mini_strlen
mini_buf 1024

INCLUDESRC
BINARY testprintf
SOURCES $1 

return
#endif




int main( int argc, char *argv[] ){

	fprintf( stdout, "stdio.\n" );
	dprintf( 1, "Check d 12345 %d\n",12345 );
	fprintf( stdout, "Check d 12345 %d\n",12345 );

		printf("sizeof int: %d\n", sizeof(int));
		printf("sizeof long: %d\n", sizeof(long));
		printf("sizeof long long: %d\n", sizeof(long long int));

		printf("padded string:%10s","end\n");
		printf("padded string:%3s","e\n");

		printf("padded num: -%3d-\n",12);
		printf("padded num: -%03d-\n",12);
		printf("padded num 3301: -%010d-\n",3301);


	return(0);
}
