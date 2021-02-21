//+header stdio.h
//+depends fputs strerror strlen errno
//+def
void perror(const char *msg){
		if ( msg !=0 && msg[0] != '\0' )
				fputs( msg, stderr );

		fputs( strerror( errno ), stderr );
}


