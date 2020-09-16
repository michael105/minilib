#ifndef mini_userdb_c
#define mini_userdb_c

//+include
//+doc tokenizer for the passwd/group files.
// used by the group/user pwentry access functions.
//+def userdb

char *token_s( char **p ){
	char *ptmp = *p;
	while ( (*p<mlgl->passwdfile+mlgl->passwdfilesize) &&  **p) { 
		if ( **p == ':' || **p == '\n' ){
			**p = 0;
		} else {
			(*p)++; 
		}
	};// while (**p);
	(*p)++;
	return(ptmp);
}

int token_i( char **p ){
	int i = 0;

	while ( (*p<mlgl->passwdfile+mlgl->passwdfilesize) && **p>='0' && **p <= '9' ){
		//euid = euid*10 + (*puid-'0');
		i += i + (i<<3) + (**p-'0');
		(*p)++;
	}
	(*p)++;
	return(i);
}


#endif

