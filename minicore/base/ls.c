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

/*
enum shortopts { 
	opt_A,opt_B,opt_C,opt_D,opt_E,opt_F,opt_G,opt_H,opt_I,opt_J,opt_K,opt_L,opt_M,
	opt_N,opt_O,opt_P,opt_Q,opt_R,opt_S,opt_T,opt_U,opt_V,opt_W,opt_X,opt_Y,opt_Z,
	opt_a,opt_b,opt_c,opt_d,opt_e,opt_f,opt_g,opt_h,opt_i,opt_j,opt_k,opt_l,opt_m,
	opt_n,opt_o,opt_p,opt_q,opt_r,opt_s,opt_t,opt_u,opt_v,opt_w,opt_x,opt_y,opt_z
};*/

enum shortopts { 
	opt_A=01,opt_B=02,opt_C=04,opt_D=010,opt_E=020,opt_F=040,opt_G=0100,opt_H=0200,
	opt_I=0400,opt_J=01000,opt_K=02000,opt_L=04000,opt_M=010000,opt_N=020000,
	opt_O=040000,opt_P=0100000,opt_Q=0200000,opt_R=0400000,opt_S=01000000,
	opt_T=02000000,opt_U=04000000,opt_V=010000000,opt_W=020000000,opt_X=040000000,
	opt_Y=0100000000,opt_Z=0200000000,opt_a=0400000000,opt_b=01000000000,
	opt_c=02000000000,opt_d=04000000000,opt_e=010000000000,opt_f=020000000000,
	opt_g=040000000000,opt_h=0100000000000,opt_i=0200000000000,opt_j=0400000000000,
	opt_k=01000000000000,opt_l=02000000000000,opt_m=04000000000000,
	opt_n=010000000000000,opt_o=020000000000000,opt_p=040000000000000,
	opt_q=0100000000000000,opt_r=0200000000000000,opt_s=0400000000000000,
	opt_t=01000000000000000,opt_u=02000000000000000,opt_v=04000000000000000,
	opt_w=010000000000000000,opt_x=020000000000000000,opt_y=040000000000000000,
	opt_z=0100000000000000000 };

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

typedef struct listcolor{
	int mode;
	char* color;
	char c;
} _listcolor;

struct listcolor colors[] = {
	{S_IFDIR,AC_BLUE,'d'},
	{0111,AC_LGREEN,'-'}, // executable
	{S_IFIFO,AC_BROWN,'p'},
	{S_IFBLK,AC_YELLOW,'b'},
	{S_IFCHR,AC_YELLOW,'c'},
	{0},
};

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

//		if ( st.st_mode & 0111 ) //executable
//			color = AC_LGREEN;

#define FTYPE( type, colorname, c ) case type:	\
		color = colorname; permstring[0]=c;break
/*
		switch ( st.st_mode & S_IFMT ){
			FTYPE(S_IFDIR,AC_BLUE,'d');
			FTYPE(S_IFIFO,AC_BROWN,'p');
			FTYPE(S_IFBLK,AC_YELLOW,'b');
			FTYPE(S_IFCHR,AC_YELLOW,'c');
		}
*/
		for ( _listcolor *lc = colors; lc->mode!=0; lc++ ){
			if ( lc->mode & st.st_mode ){
				color = lc->color; permstring[0]=lc->c;
				break;
			}
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

	int (*cmp)(const void*,const void*)= 
		(int(*)(const void*,const void*))alphasort;

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
