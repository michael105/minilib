#if 0
mini_start
mini_writes
mini_ewrites

mini_getresuid
mini_exit_errno

mini_buf 256
mini_printf
mini_itodec
mini_strlen


INCLUDESRC
SHRINKELF

return
#endif


void usage(){
	writes("getresuid\nGet the ruid, euid and suid\n");
	exit(0);
}

int main(int argc, char *argv[]){

	if ( argc > 1 )
		usage();

	if ( argc==1 ){
		uid_t ruid, euid, suid;
		int e;
		if ( (e=getresuid( &ruid, &euid, &suid )) != 0 ){
			printf("e: %d\n");
			exit_errno(e);
		}
		printf(" ruid  euid  suid\n%5d %5d %5d\n",ruid,euid,suid);

	}

	return(0);
}
