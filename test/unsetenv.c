#if 0

mini_buf 2000


mini_start

COMPILE putenv setenv prints printsl unsetenv
COMPILE fprintf itodec 


INCLUDESRC

return
#endif

int _unsetenv( char *name){
	char **envp;
	int a;

	for ( envp=environ; *envp; envp++ ){
		for ( a=0; (envp[0][a] == name[a]); a++ ){}; 
		if ( envp[0][a] == '=' ){ // found
			for ( char **e = envp+1; ( *envp=*e ); e++,envp++ ){};
		}
	}
	return(0);
}

int main(){

	prints("start\n");

	printsl(getenv("SHELL"));

	putenv("SHELL=/bin/sh");
	printsl(getenv("SHELL"));


	printsl("xx1");
	setenv("SHELL","/bin/setenv",1);
	printsl("ok1");
	printsl(getenv("SHELL"));


	printsl("xx");
	setenv("TEST","/bin/setenv",1);
	printsl("ok");
	if (getenv("TEST"))
		printsl("TEST: ",getenv("TEST"));

	setenv("TEST","/bin/set",1);
	printsl("ok");
	if (getenv("TEST"))
		printsl("TEST: ",getenv("TEST"));


	unsetenv("TEST");
	printsl("ok");
	if (getenv("TEST"))
		printsl("TEST -2: ",getenv("TEST"));

	unsetenv("TEST");
	printsl("ok");
	if (getenv("TEST"))
		printsl("TEST -2: ",getenv("TEST"));

	setenv("TEST","/bin/setenv",1);
	printsl("ok");
	if (getenv("TEST"))
		printsl("TEST: ",getenv("TEST"));



	return(0);
}



