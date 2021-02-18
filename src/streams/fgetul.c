//+doc read an unsigned long integer from the stream F
// reads all digits until a nondigit is read.
//+depends fgetc
//+def
unsigned long int fgetul(FILE* F){
		unsigned long int ret = 0;
		char c = 0;

		while ( ( c = (char)fgetc(F) ) && isdigit(c) ){
				ret = ret*10 + (c-48);
		}

		return(ret);
}


