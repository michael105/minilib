#ifndef fgetc_h
#define fgetc_h




//+depends fileno read
//+after mini_fstream.h
//+inline
static inline int fgetc(FILE *F){
		int buf = 0;
		read(fileno(F), &buf, 1 );
		return(buf);
}


//+depends fgetc fileno read
//+macro getc(F) fgetc(F)


#endif
