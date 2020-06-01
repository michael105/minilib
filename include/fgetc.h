#ifndef fgetc_h
#define fgetc_h




//+depends fileno read
//+needs mini_fstream.h
//+inline
static inline int fgetc(FILE *F){
		POINTER buf = 0;
		read(fileno(F), &buf, 1 );
		return((int)buf);
}


//+depends fgetc fileno read
//+macro getc(F) fgetc(F)

//+depends fgetc fileno read
//+macro getchar() fgetc(0)



#endif
