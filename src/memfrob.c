//+doc frob string; xor every char with 42
//+def
void* memfrob( void* s, int len ){
	while (len-->0)
		*s^=42;
	return(s);
}
