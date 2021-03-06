//+doc read an unsigned integer from the stream F
// reads all digits until a nondigit is read.
//+depends fgetc
//+def
unsigned int fgetud(FILE* F){
		unsigned int ret = 0;
		char c = 0;

		while ( ( c = (char)fgetc(F) ) && isdigit(c) ){
				ret = ret*10 + (c-48);
		}

		return(ret);
}


