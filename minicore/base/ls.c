#if 0
mini_start

mini_scandir
mini_malloc
mini_prints
mini_writes
mini_open
mini_errno
mini_readdir
mini_qsort
mini_alphasort

mini_match
mini_strcmp

mini_eprintfs

mini_buf 4096
mini_printf
mini_sprintf
mini_itodec
mini_ltodec
mini_free_brk

mini_ansicolors

OPTFLAG -Os

#LDSCRIPT 
INCLUDESRC
HEADERGUARDS

return
#endif


//enum shortopts { 
//A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
//a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z };

void setopt( char c, long *opts ){
	if ( c>= 'A' && c <= 'X' )
		*opts |= (long)1<<( c-'A');
	else if ( c>='a' && c<='z' )
		*opts |= ((long)1<<( c-'a'+26));
}

/*
int _opt( enum shortopts shortopt, long opts ){
	printf("opt: %d\n",shortopt);
	printf("opt: %ld\n",(long)1<<shortopt);
	printf("Opts: %ld\n",opts);
	printf("Opts: %d\n",opts>>32);


	return( opts & ( (long)1<<shortopt ) );
} */


int opt( char c, long opts ){
	if ( c>= 'A' && c <= 'X' )
		return(opts & (long)1<<( c-'A') ? 1 : 0 );
	return( opts & ((long)1<<( c-'a'+26)) ? 1 : 0 );
}



void usage(){
		writes("Usage: ls [-h]  \n");
		exit(1);
}

int de_match(const struct dirent *de){
		//if ( match(de->d_name,"*.c",0) == 0 )
		//		return(1);
		return(1);
}

void printlist(const char* path,struct dirent **list,int count,long opts){
	chdir(path);

	struct stat st;
	char *perms = "rwx";
	char *pp = perms;
	char permstring[12];
	permstring[11]=0;

	for ( int a=0; a<count; a++ ){
		int b = 1;

		stat(list[a]->d_name,&st);

		permstring[0]='-';

		for ( int perm = 0400; perm; perm >>= 1 ){
			if ( st.st_mode & perm )
				permstring[b] = *pp;
			else 
				permstring[b] = '-';
			b++;pp++;
			if ( *pp==0 ) pp = perms;
		}

		if ( st.st_mode & S_ISUID )
			permstring[3] = 'S';
		if ( st.st_mode & S_ISGID )
			permstring[6] = 'S';

		char *color="";

		if ( st.st_mode & 0111 ) //executable
			color = AC_LGREEN;

#define FTYPE( type, colorname, c ) case type:	\
		color = colorname; permstring[0]=c;\
		break;

		switch ( st.st_mode & S_IFMT ){
			case S_IFDIR:
				color = AC_BLUE;
				permstring[0]='d';
				break;
			case S_IFIFO: //fifo
				color = AC_YELLOW;
				permstring[0]='p';
				break;

		}




		prints(permstring);
		printf(" %s%s%s %d\n",color,list[a]->d_name,AC_NORM,st.st_size);
	}
}


//int revsort(void *list, int len, int size, int(*)(const void*,const void*) cmp){
//	return( qsort(list,len,size,rev(

int alphasort_r(const void *a,const void *b){
	return(-alphasort((const struct dirent**)a,(const struct dirent**)b));
}

typedef struct _direntry{
	struct dirent* dent;
	struct stat* st;
} direntry;


int listdir(const char* dir,long opts){
	// save heap start
	long addr = getbrk();

	struct dirent **list;
	int r = scandir(dir, &list, 0,0);

	if ( opt('S',opts ) ){


	}

	int (*cmp)(const void*,const void*)= (int(*)(const void*,const void*))alphasort;
	if ( opt( 'r', opts ) != 0 ){
		cmp=alphasort_r;
	}
	qsort( list, r, sizeof(POINTER), cmp );

	printlist(dir,list,r,opts);

	// free heap
	setbrk(addr);	

	return(0);
}

int main(int argc, char **argv){

	long opts = 0;
	// define to something other for parsing the docu
#ifndef OPT
#define OPT(flag,desc,code) case flag: setopt(flag,&opts); code; break;
#endif

	for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
		for ( char *c = argv[0]+1; *c != 0; c++ ){
			switch ( *c ){
				OPT('h',"Show usage",usage());
				OPT('r',"reverse order",);
				OPT('S',"Sort by size",);
				OPT('l',"Show extended info",);
				default:
					usage();
			} 
		} 
	}

	if ( *argv == 0 ){
		return(listdir(".",opts));
	}

	for (;*argv; *argv++){
		prints("\n",*argv,":\n");
		listdir(*argv,opts);
	}


	//	optimization_fence(*list);

	return(0);
}
