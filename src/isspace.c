#ifndef isspace_c
#define isspace_c

int isspace(int c){
		switch (c){
				case ' ':
				case '\f':
				case '\n':
				case '\r':
				case '\t':
				case '\v':
						return(1);
		}
		return(0);
}




#endif

