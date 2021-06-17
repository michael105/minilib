//+doc pushes one char back to the stream.
// Overwrites a previously pushed char
// (conforming to the posix spec) 
//+def
static int ungetc(int c, FILE *F){
		*F = (*F & ~UNGETC_MASK) | (c<<24);
		return(c);
}		


