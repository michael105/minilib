#if 0
mini_start
mini_open
mini_close
mini_write
mini_writes
mini_writesl
mini_ewrites
mini_ewritesl
mini_read
mini_group_printf

mini_print
mini_printl
mini_prints
mini_printfs
mini_strcat
mini_strcpy

mini_die_if
mini_dief_if
mini_dief
mini_opendir
mini_readdir
mini_errno

mini_mmap
mini_match
mini_ext_match
mini_ext_match2

mini_buf 4096
mini_GETOPTS
#LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
OPTFLAG -Os
return
#endif

#define PCIBUSDIRECTORY "/sys/bus/pci/devices"


// append, extract or replace data.
// read from stdin;
// write to stdout.

void writefile(int fd){
	char buf[4096];
	int l, len=0;
	while ( (l=read(0,buf,4096)) ){
		write(fd,buf,l);
		len+=l;
	}
	//fprintf(stderr,"wrote: %d\n",len);
	write(fd,(char*)&len,4);
	write(fd,"AP\0\0",4);
	close(fd);
}

int seekfile(int fd,int trunc){
	int size = lseek( fd, 0, SEEK_END );
	int fsize = lseek( fd, size-8, SEEK_SET );
	int len,c;
	read(fd,(char*)&len,4);
	int r = read(fd,(char*)&c,4);

	//fprintf(stderr,"len: %d\n",len);
	if ( r!=4 || ( len > fsize ) || c!=0x5041 ){
		return(-1);
	}

	lseek( fd, size-8-len, SEEK_SET );
	if ( trunc )
		ftruncate( fd,size-8-len );
	return(len);
}


char* mapmodalias(const char* fn){
	int fd = open(fn,O_RDONLY);
	struct stat ststat;
	fstat(fd,&ststat);

	dief_if(fd<=0,errno,"Couldn't open %s\n",fn);
	char *ret = mmap(0,ststat.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd,0);
	return(ret);
}

// using a static var instead of a closure.
// a closure would need an executable stack,
// and the trampoline code by gcc.
static char* stalias;
static char* stmodule;
typedef struct data {
	char* module;
	char alias[64];
	char* mappedalias;
};

void cb(int n, char *pos, int len){
	write(1,"cb\n",3);
	write(1,pos,len);
}

int cb2(int n, char *c, void* udata ){
	struct data* ud = udata;
	char *p=c;
	int len=0;
	while ( *p != ' ' ){
		len++;p++;
	}
	*p=0;
	int r = match( ud->alias,(c-4),0);
	if ( r==RE_MATCH ){
		write(1,c,len);
		*p=' ';
		p++;
		regex_match stmatch;
		match(p,"%\n",&stmatch);
		
		
		return(RE_MATCHEND);
	}
	
	*p=' ';
	//write(1,c,len);
	return(len+1);
	return(RE_NOMATCH);
}



char* grepalias(const char* mappedalias, const char* alias){
	write(1,mappedalias,20);
	regex_match stmatch;
  struct data udata;
	udata.mappedalias = mappedalias;
	udata.module = 0;
	int len = strlen(alias);
	strppy(udata.alias,alias);

	write(1,"1\n",2);

	int ret = ext_match( mappedalias, "*alias pci:&",0,cb2,&stmatch,(void*)&udata );	

	
	//int ret = ext_match( mappedalias, "alias *:",cb,0,&stmatch );	

	return(0);
}

char* getalias( const char* devpath, const struct dirent *de ){
	char path[1024];
	strcpy( path, devpath );
	strcat( path, de->d_name );
	char *p = (path+strlen(path));
	strcpy( p, "/modalias" ); 
	printfs( "Open: %s\n", path );
	int fd = open( path, O_RDONLY );
	dief_if( fd<=0, errno, "Couldn't open %s\n", path );

	char *buf = malloc(256);
	int r=read(fd,buf,256);
	write(1,buf,r);
	close(fd);

	//grepalias(buf);
	return(buf);
}

/*
int getmodaliasname(char *fn){
	struct old_utsname uts;
	uname(&uts);
	writesl("1");
	strcpy(fn,uts.release);
	printsl(uts.release);
	printsl(fn);
	writesl("1");
	return(1);
}
*/


int main(int argc, char **argv){
		int opts=0;
		char buf[4096];
		int ret = PARSEOPTS_short(opts, argv, (h+r+a+e), SETOPT_short(opts,h));

		if ( GETOPT_short(opts,h) ){
				writes("Usage: ap [-h] [-r] [-a] [-e] file\n\
-a append / -r replace / -e extract stdin to file / to stdout\n");
				return 0;
		} 

		char fn[256];
		strcpy(fn,"/lib/modules/");
		struct old_utsname uts;
		uname(&uts);
		strcat(fn,uts.release);
		strcat(fn,"/modules.alias");

		printsl(fn);
		
		char *mappedalias = mapmodalias( fn );

		printf("len: %d\n",strlen(mappedalias));

		DIR* dir=opendir( PCIBUSDIRECTORY );
		die_if( !dir, errno, "Couldn't open " PCIBUSDIRECTORY );

		struct dirent *de;

		while( (de = readdir( dir )) ){

			// skip . and ..
			if ( strlen( de->d_name ) < 5 )
				continue;

			writes("dir: ");
			printsl( de->d_name );

			char *alias = getalias( PCIBUSDIRECTORY "/", de );

			//char *module = grepalias( mappedalias, alias );


			free(alias);
		}


		char *module = grepalias( mappedalias, "pci:v00008086d00000116sv00001043sd000013C7bc03sc00i00" );

		exit(0);













		if ( GETOPT_short(opts,a)){
				int fd = open( argv[ret], O_RDWR | O_APPEND );
				if ( fd<=0 )
					return ( 1 );

				int size = lseek( fd, 0, SEEK_END );
				writefile(fd);

				return(0);
		} 

		if ( GETOPT_short(opts,r)){
				int fd = open( argv[ret], O_RDWR );
				if ( fd<=0 )
					return ( 1 );

				int len = seekfile(fd,1);
				writefile(fd);
				return(0);
		}



		if ( GETOPT_short(opts,e)){
				int fd = open( argv[ret], O_RDONLY );
				if ( fd<=0 )
					return ( 1 );

				int len = seekfile(fd,0);
				if ( len<0 ){
						ewrites("Error. Nothing appended.\n");
						exit(-1);
				}

				int l;
				do {
					l=len;

					if ( len > 4096 )
						l=4096;

					l=read(fd,buf,l);

					len-=l;
					write(1,buf,l);
				} while ( len>0 && l );

				if ( len ){
					ewrites("Error\n");
					return(3);
				}

				close(fd);
				return(0);
		} 


		return 0;
}
