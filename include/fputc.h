#ifndef fputc_c
#define fputc_c


//+header stdio.h
//+depends fileno write
//+needs mini_fstream.h
//+def
static inline int volatile fputc(int c, FILE* F){
		write(fileno(F), &c, 1);
		return(c);
}

//+depends fputc
//+macro  putchar(c) fputc(c,stdout)

//+depends fputc
//+macro  putc(c,stream) fputc(c,stream)


#endif
