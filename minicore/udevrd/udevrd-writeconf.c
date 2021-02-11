#if 0
mini_start
mini_group_write
mini_group_printf
mini_strcpy


mini_dies_if
mini_die_if
mini_open
mini_mmap
mini_msync

mini_fgets
mini_fgetd
mini_fgetsn
mini_fgetsp

INCLUDESRC

return
#endif

#include "udevrd.conf.h"

void usage(){
		writes("\nudevrd-writeconf outputfile\n\n\
udevrd-writeconf updates udevrd.conf.bin,\n\
the configuration file for udevrd.\n\
It is intended to be callen from udevrd-update.sh\n\
\n\
(c) 2021 GPLv2 Michael (misc) Myer\n\n\n");
	exit(0);
}

// initial filesize
#define FILESIZE PAGESIZE


int main(int argc, char **argv){
				
		if ( argc<2 )
				usage();

		int fd = open( argv[1], O_RDWR | O_CREAT | O_TRUNC, 0640 );
		dies_if( fd<0, fd, "Couldn't open ", argv[1] );

		
		ftruncate(fd,FILESIZE);

		char* mapping = mmap(0,FILESIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0 );
		die_if( mapping<=(POINTER)0, (int)(POINTER)mapping, "Couldn't map into memory");

		int fsize = FILESIZE;
		int flen = 0;
		
		conf* config = (conf*) (mapping+sizeof(MAGICBYTES)); 
		dev* device = (dev*) (mapping+sizeof(conf)+sizeof(MAGICBYTES));
		
		write( fd, MAGICBYTES, sizeof(MAGICBYTES) );
		fgets(config->logprefix,31,stdin);

		//char buf[256];
		//fgets(buf,31,stdin);
		//write(fd,buf,32);

		int *pi = &config->loglevel;
		for ( int a = CONF_INTEGERS; (a-->0);){
			*pi = fgetd(stdin);
			pi++;
		}

		char *p = 0;
		pi++; // skip p_next

		while ( ( *pi = fgetd(stdin) ) ){
				for ( int a = DEV_INTEGERS-1; (a-->0);){
						*pi = fgetd(stdin);
						pi++;
				}
				flen = (char*)device - mapping;

				p = &device->stringsstart;

				for ( int a = DEV_STRINGS; a-->0; ){
						*pi = ( p - (char*)pi );
						p = fgetsp(p,256,stdin);
						p++; // skip 0 byte
						pi++;
				}

				device->p_next = p - (char*)&device->p_next;
				flen += device->p_next;
				device = (dev*)p;
				pi=(int*)p;
				pi++; // skip p_next
		}

		// mark end of file
		*p=0; // ending with p_next = 0
		flen++;
		printf("flen: %d\n",flen);


		msync(mapping,flen,MS_SYNC);
		munmap(mapping,flen);

		ftruncate(fd,flen);
		close(fd);











		return(0);
}
