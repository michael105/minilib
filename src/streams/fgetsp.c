//+doc read a line from F into buf with max chars size.
// Return a pointer to the terminating '0' byte.
// A terminating linebreak is not written to buf.
//
//+depends fgetc
//+def
char* fgetsp(char *buf, int size, FILE* F){

		while( --size >0 ){
				*buf = (char)fgetc(F);
				switch ( *buf ){
						case '\n':
								*buf=0;
						case 0:
								return(buf);
				}
				buf++;
		}
		*buf = 0;
		return(buf);
}


