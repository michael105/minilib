//+doc frob string; xor every char with 42
//+ansi string.h
//+def
void* memfrob(void* s, unsigned int len){
	while (len-->0)
		*s^=42;
	return(s);
}
		
