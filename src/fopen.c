#ifndef mini_fopen_c
#define mini_fopen_c

#include "include/filemodes.h"

#include "syntaxchecker.h"


#ifdef X64
union { FILE*F; int i,fd; } fl; // 
#else
//union { FILE*F; int fd; } fl; // 
#endif
//(untested for x32) better commenting this out for now.
//Might be better to find later
//also: endiannes.




//+header stdio.h
//+depends open
//+needs lseek.h
//+def
FILE *fopen(const char* filename, const char* mode){
		int imode;

		switch (mode[0]){
				case 'r': imode = O_RDONLY;
									break;
				case 'w': imode = O_WRONLY | O_TRUNC | O_CREAT;
									break;
				case 'a': imode = O_APPEND; // somehow only "a+" works. Not sure, why.
									break;
				default: return(0); // hopefully a fd cannot be 0.? By reading the manual, 
								 // I conclude only stdin has the fildes 0. So It MIGHT be ok.
								  // Anyways, if someone's trying to open stdin via fopen and is wondering, what's going on..
								 // Here's the answer. But, regarding the bsd manuals, one shouldn't open stdin with fopen at all. so..
		}

		for ( int a=1; (mode[a] != 0) && ( a<6 ); a++ ){
 				if ( mode[a] == '+' ){ 
						imode = imode | O_RDWR;
				} else {
						switch (mode[0]){
								case 'r': 
										break;
								case 'w': if ( mode[a] == 'x' )
															imode = imode & ( ~(O_CREAT | O_TRUNC) );
													break;
								case 'a': 
													break;
						}
				}
		}
		fl.fd =(int) open( filename, imode, 0666 );
		return ( fl.F ); // 
}

//+def
int fileno( FILE *f ){
		fl.F=f;
		return( fl.fd );
}


//+depends close fileno
//+def
int fclose( FILE* f ){
		return( close(fileno(f)) );
}





#endif
