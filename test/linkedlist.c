#if 0
mini_start

mini_group_print
mini_group_printf
mini_buf 256

mini_perror
mini_errno
mini_mmap
mini_memset
mini_memcpy

mini_strcpy
INCLUDESRC

return
#endif

#include "../macros/linkedlist.c"

typedef struct {
		char s[32];
		int i;
} list_object;


int main( int argc, char **argv){

		DEFINE_LIST(char);

		list *l = newlist(-1);
		if ( ! l )
				perror("No list");

		list_object e;
		e.i=42;
		strcpy(e.s,"string 1");


		eappend(l,"String 1",8);

		strcpy(e.s,"string 2");
		eappend(l,"String 2",8);


		char *c = Lfirst_char(l);
		do {
			printsl(c);
		}	while ( c=Lnext_char(c) );

		return(0);
}

