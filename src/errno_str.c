
//+doc convert errno to str, with 3 chars length
// ending the string (global) 
// with two \0\0, when errno<100
// errnum must be <200.
//+def
static char *errno_str(int err){
		static char e[5]; 
		// = { '1','0','0','\n',0 }; blows up 4k. 
		// needs another section.
		char *p = e;
		if ( err>99 ){
				err-=100;
		} else {
				p++;
		}
		e[0] = '1';
		e[1]=(err/10)+'0';
		e[2]=(err%10)+'0';
		e[3]='\n';
		e[4]=0;

		return(p);
}



