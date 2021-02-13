#if 0
mini_start
mini_group_write


mini_printf
mini_itohex
mini_ltodec
mini_printsl
mini_eprintsl
mini_itodec
mini_strlen
mini_dprints
mini_dies_if
mini_die_if
mini_open
mini_mmap
mini_msync

mini_fgets
mini_fgetud
mini_fgetsn
mini_fgetsp

mini_ALIGN

mini_buf 256
INCLUDESRC
SHRINKELF

source common.conf
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

		printsl("open ", argv[1]);
		int fd = open( argv[1], O_RDWR | O_CREAT | O_TRUNC, 0640 );
		dies_if( fd<0, fd, "Couldn't open ", argv[1] );

		
		ftruncate(fd,FILESIZE);

		char* mapping = mmap(0,FILESIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0 );
		die_if( mapping<=(POINTER)0, (int)(POINTER)mapping, "Couldn't map into memory");

		int fsize = FILESIZE;
		int flen = 0;

		conf* config = (conf*) (mapping+sizeof(MAGICINT)); 
		
		*(int*)mapping = MAGICINT;

		// config section
		uint *pi = &config->loglevel;
		for ( int a = CONF_INTEGERS; (a-->0);){
			*pi = fgetud(stdin);
			printf("pi: %d\n",*pi);
			pi++;
		}
		writesl("1");

		config->p_logprefix = (&config->stringsstart - (char*)&config->p_logprefix);
		char *p = fgetsp(&config->stringsstart,256,stdin);
		p++;
		config->p_devpath = ( p - (char*)&config->p_devpath );
		p = fgetsp(p,256,stdin);
		printsl("str ",&config->stringsstart);
		printsl("str ",getaddr(config->p_devpath));
		p++;
		config->p_devices = ( p - (char*)&config->p_devices );


		dev* device = (dev*) (p);

		writesl("2");
		pi = (uint*)p;
		// devices section
		while ( ( ( *pi = fgetud(stdin) ) != 0xff )  ){

				if ( fsize-flen < 1024 ){
						// enlarge file
						fsize += PAGESIZE;
						ftruncate(fd,fsize);
				}

				pi++; // skip p_next
				for ( int a = DEV_INTEGERS; (a-->0);){
						*pi = fgetud(stdin);
						printf( "pi: %d\n", *pi );
						pi++;
				}
				flen = (char*)device - mapping;

				p = &device->stringsstart;

				for ( int a = DEV_STRINGS; a-->0; ){
						*pi = ( p - (char*)pi );
						char *op = p;
						p = fgetsp(p,256,stdin);
						printsl(op);
						p++; // skip 0 byte
						pi++;
				}

				//p = (char*)(((( (long)p - (long)1 ) >> 2 ) << 2 ) +4); // align
				ALIGN_8(p);


				device->p_next = p - (char*)&device->p_next;
				flen += device->p_next;
				device = (dev*)p;
				pi=(uint*)p;
		}

		// test for correct end 
		if ( *pi != 0xff ){
				ewrites("Error reading stdin.\n");
				exit(1);
		}


		// mark end of file
		*pi=0; // ending with p_next = 0
		pi++;
		*pi=MAGICINT;
		flen+=2*sizeof(uint);


		printf("Wrote %d Bytes.\n\n",flen);

		printsl( "logpref: ", getstr(config->p_logprefix ) );
		printsl( "devpath: ",getstr(config->p_devpath ),"\n\nDevices:" );



		for ( device = firstdev(mapping);
					device; device = nextdev(device)){
						printf( "addr: %lx  %ld\n", device, device );
						printsl( " match: ", ( (char*)&device->p_match + device->p_match ) );
						printf(  "   uid: %d  gid: %d\n",device->owner, device->group);
		};


		msync(mapping,flen,MS_SYNC);
		munmap(mapping,flen);

		ftruncate(fd,flen);
		close(fd);

		return(0);
}
