#ifndef strlen_c
#define strlen_c

//+header string.h

//+def
int strlen(const char*str){
		int a = 0;
		while ( str[a] != 0 ){
				a++;
		}
		return (a);
}


#endif
