#ifndef mini_fopen_c
#define mini_fopen_c

#include "include/filemodes.h"


//+header stdio.h
//+depends open
//+needs lseek.h
//+doc modes implemented: r, r+, w, w+, a, a+
//+def
FILE *fopen(const char* filename, const char* mode){
		int imode;

		switch (mode[0]){
				case 'r': imode = O_RDONLY;
									break;
				case 'w': imode = O_WRONLY | O_TRUNC | O_CREAT;
									break;
				case 'a': imode = O_APPEND | O_RDWR; // somehow only "a+" works. Not sure, why.
									break;
				default: return((FILE*)0); // hopefully a fd cannot be 0.? By reading the manual, 
								 // I conclude only stdin has the fildes 0. So It MIGHT be ok.
								  // Anyways, if someone's trying to open stdin via fopen and is wondering, what's going on..
								 // Here's the answer. But, regarding the bsd manuals, one shouldn't open stdin with fopen at all. so..
		}

		for ( int a=1; (mode[a] != 0) && ( a<6 ); a++ ){
 				if ( mode[a] == '+' ){ 
						imode = ( ( imode | O_RDWR ) & ~( O_WRONLY | O_RDONLY) );
				} else {
#if 0
				//printf("XXX: %c", mode[a]);
						switch (mode[0]){
								case 'r': //imode = O_RDONLY;
										break;
								case 'w': if ( mode[a] == 'x' )
															imode = imode & ( ~(O_CREAT | O_TRUNC) );
													break;
								case 'a': //imode = O_APPEND | O_RDWR; 
													break;
						}
#endif
				}
		}

		int a;
		if ( ml.pstream >= mini_FOPEN_MAX){ // Too many opened streams. Look for an empty storage location
			for ( a=3; ml.stream[a]>=0; a++ )
					if ( a >= mini_FOPEN_MAX ) // 
							return(0);
		} else {
				a = ml.pstream;
				ml.pstream++;
		}

		//printf("a: %d\n",a);
		FILE *f = &ml.stream[a];
		ml.stream[a] =  open( filename, imode, 0666 );
		return ( f ); // 
}

#endif
