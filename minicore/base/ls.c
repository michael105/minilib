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
mini_brk

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

// better let the praeprocessor do the work, than at runtime..
#define _LIT_A 'A'
#define _LIT_B 'B'
#define _LIT_C 'C'
#define _LIT_D 'D'
#define _LIT_E 'E'
#define _LIT_F 'F'
#define _LIT_G 'G'
#define _LIT_H 'H'
#define _LIT_I 'I'
#define _LIT_J 'J'
#define _LIT_K 'K'
#define _LIT_L 'L'
#define _LIT_M 'M'
#define _LIT_N 'N'
#define _LIT_O 'O'
#define _LIT_P 'P'
#define _LIT_Q 'Q'
#define _LIT_R 'R'
#define _LIT_S 'S'
#define _LIT_T 'T'
#define _LIT_U 'U'
#define _LIT_V 'V'
#define _LIT_W 'W'
#define _LIT_X 'X'
#define _LIT_Y 'Y'
#define _LIT_Z 'Z'
#define _LIT_a 'a'
#define _LIT_b 'b'
#define _LIT_c 'c'
#define _LIT_d 'd'
#define _LIT_e 'e'
#define _LIT_f 'f'
#define _LIT_g 'g'
#define _LIT_h 'h'
#define _LIT_i 'i'
#define _LIT_j 'j'
#define _LIT_k 'k'
#define _LIT_l 'l'
#define _LIT_m 'm'
#define _LIT_n 'n'
#define _LIT_o 'o'
#define _LIT_p 'p'
#define _LIT_q 'q'
#define _LIT_r 'r'
#define _LIT_s 's'
#define _LIT_t 't'
#define _LIT_u 'u'
#define _LIT_v 'v'
#define _LIT_w 'w'
#define _LIT_x 'x'
#define _LIT_y 'y'
#define _LIT_z 'z'

//  QUOTE(x) gets 'x'
#define QUOTE(a) _LIT_##a

#define OPT_A 01
#define OPT_B 02
#define OPT_C 04
#define OPT_D 010
#define OPT_E 020
#define OPT_F 040
#define OPT_G 0100
#define OPT_H 0200
#define OPT_I 0400
#define OPT_J 01000
#define OPT_K 02000
#define OPT_L 04000
#define OPT_M 010000
#define OPT_N 020000
#define OPT_O 040000
#define OPT_P 0100000
#define OPT_Q 0200000
#define OPT_R 0400000
#define OPT_S 01000000
#define OPT_T 02000000
#define OPT_U 04000000
#define OPT_V 010000000
#define OPT_W 020000000
#define OPT_X 040000000
#define OPT_Y 0100000000
#define OPT_Z 0200000000
#define OPT_a 0400000000
#define OPT_b 01000000000
#define OPT_c 02000000000
#define OPT_d 04000000000
#define OPT_e 010000000000
#define OPT_f 020000000000
#define OPT_g 040000000000
#define OPT_h 0100000000000
#define OPT_i 0200000000000
#define OPT_j 0400000000000
#define OPT_k 01000000000000
#define OPT_l 02000000000000
#define OPT_m 04000000000000
#define OPT_n 010000000000000
#define OPT_o 020000000000000
#define OPT_p 040000000000000
#define OPT_q 0100000000000000
#define OPT_r 0200000000000000
#define OPT_s 0400000000000000
#define OPT_t 01000000000000000
#define OPT_u 02000000000000000
#define OPT_v 04000000000000000
#define OPT_w 010000000000000000
#define OPT_x 020000000000000000
#define OPT_y 040000000000000000
#define OPT_z 0100000000000000000

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
	char c;
	//char align;
	char* color;
} _listcolor;

struct listcolor colors[] = {
	{S_IFDIR,'d',AC_BLUE},
	{0111,'-'   ,AC_LGREEN}, // executable
	{S_IFIFO,'p',AC_BROWN},
	{S_IFBLK,'b',AC_YELLOW},
	{S_IFCHR,'c',AC_YELLOW},
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



		//prints(permstring);
		printf("%s %s%s%s %d\n",permstring,color,list[a]->d_name,AC_NORM,st.st_size);
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

	if ( opts & OPT_r ){
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
	// define to something other for parsing docu
#ifndef OPT
#define OPT(flag,desc,code) case QUOTE(flag): opts |= OPT_##flag; code; break;
//#define OPT(flag,desc,code) case flag: setopt(flag,&opts); code; break;
#endif

	for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
		for ( char *c = argv[0]+1; *c != 0; c++ ){
			switch ( *c ){
				OPT(h,"Show usage",usage());
				OPT(l,"Show extended info",);
				default:
					usage();
			} 
		} 
	}

	if ( *argv == 0 ){
		usage();
	}

	for (;*argv; *argv++){
		prints("\n",*argv,":\n");
		cksum(*argv,opts);
	}


	//	optimization_fence(*list);

	return(0);
}
