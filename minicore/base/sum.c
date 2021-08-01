#if 0
mini_start
mini_eprintsl
mini_writes
mini_fwrites
mini_prints
mini_strerror
mini_read
mini_write
mini_printf
mini_itodec
mini_open
mini_bsd_cksumblock

mini_buf 1024

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

#include "shortopts.h"


void usage(){
	writes("sum [-h]\n");
	exit(0);
}

#define BUFSIZE 1024

void sum(const char* file,long opts){
	int fd = 0;
	if ( file[0] != '-' )
		fd = open(file,O_RDONLY);
	if (fd<0){
		eprintsl("Couldn't open ",file);
		exit(1);
	}
	char buf[BUFSIZE];
	int ret;
	int blocks = 0;
	unsigned int hash = 0;

	while ( ret=read(fd,buf,BUFSIZE) ){
			blocks++;
			hash=bsd_cksumblock(hash,buf,ret);
			printf("blocks: %d  hash: %d  ret: %d\n",blocks,hash,ret);
	}

	printf("%u\t%d",hash,blocks);

}

int main(int argc, const char *argv[]){
	long opts = 0;
	// define to something other for parsing docu
#ifndef OPT
#define OPT(flag,desc,code) case QUOTE(flag): opts |= OPT_##flag; code; break;
//#define OPT(flag,desc,code) case flag: setopt(flag,&opts); code; break;
#endif

	for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
		for ( const char *c = argv[0]+1; *c != 0; c++ ){
			switch ( *c ){
				OPT(h,"Show usage",usage());
				OPT(r,"reverse order",);
				default:
					usage();
			} 
		} 
	}

	if ( *argv == 0 ){
		//usage();
		sum("-",opts);
		writes("\n");
		return(0);
	}

	for (;*argv; *argv++){
		sum(*argv,opts);
		prints("\t",*argv,"\n");
	}



	return 0;
}
