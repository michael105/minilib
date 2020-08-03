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
} element;


int main( int argc, char **argv){

		list *l = newlist(sizeof(element),-1);
		if ( ! l )
				perror("No list");

		element e;
		e.i=42;
		strcpy(e.s,"string 1");

#define eappend(liste,elem) _append(liste,(void*)&elem)

		eappend(l,e);

		strcpy(e.s,"string 2");
		eappend(l,e);


		node *n = _first(l);
		do {
			printsl((char*)(n+sizeof(node*)));
		}	while ( n=_next(n) );

		return(0);
}

