#ifndef mini_userdb_c
#define mini_userdb_c

//+include
//+doc tokenizer for the passwd/group files.
// used by the group/user pwentry access functions.
// performance of subsequent calls could be improved by replacing all ':' and '\n'
// by 0's when loading the db file.
// it would be possible as well, testing not only single bytes, but
// integers of longs at once. However, in most cases, e.g.
// for big directories with many small files, in most cases 
// all files do have the same owner and group. Since the last result to calls
// of the access functions is cached,
// there wouldn't be an improvement by optimizing the tokenizing functions.
// So I'm leaving this for now, as it is.
// And most possibly it would be better to implement bsd's cached versions 
// of the user db access functions instead. 
//+def 
char *token_s( char **p ){
	char *ptmp = *p;
	while ( (*p < mlgl->passwdfile+mlgl->passwdfilesize) &&  **p) { 
		if ( **p == ':' || **p == '\n' ){
			**p = 0;
		} else {
			(*p)++; 
		}
	};// while (**p);
	(*p)++;
	return(ptmp);
}

//+def
int token_i( char **p ){
	int i = 0;

	while ( (*p < mlgl->passwdfile+mlgl->passwdfilesize) && **p>='0' && **p <= '9' ){
		//euid = euid*10 + (*puid-'0');
		i += i + (i<<3) + (**p-'0');
		(*p)++;
	}
	(*p)++;
	return(i);
}


#endif

