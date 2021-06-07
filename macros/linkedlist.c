
//#ifdef X64
#define ISFREE 0x8000000000000000

// about malloc:
// setupmalloc: setup the ecpected usage of malloc,
// so the structures can be preallocated, 
// and the backing functions can get selected.
// setup the meta-usage. (wich counts of allocations
// of which sizes are to be expected)
//
// Assume malloc_minibuf per default.
// (Static allocation of the minibuf in the bss section,
// use one page for all dynamic data per default)
//
// If minibuf is used, but not defined, size it so it fits
// the bss section. (use 64Bytes + the empty space up to the next pagebreak)
// and issue a compiler warning about the selected size.
//
//
//





typedef struct __node {
		struct __node* next;
		// void* e; // commented this out. it is not needed.
		// e.g. with the alloc list, there is no element data needed,
		// just the pure node itself. (and the value of preallocate)
		// casting is needed in each case, so.
} node;


typedef struct __list {
		node *first;
		node *last; // point to the first empty node after list
		node *freenode_p;
		// >0: pointer to the first free (or previuosly free) node, 
		// more free nodes are (if present) always right of "freenode_p".
		// the skipping is cheap, but can spare quite some searching time.
		node *alloclist; // list with all mapped areas
		void* memend;
		int preallocate;
		int freenodecount;
		int nodecount;
		int align[3];
} list;

list* newlist(int preallocate){
		if ( preallocate == -1 )
				preallocate = PAGESIZE;
		//list *l = malloc(preallocate);
		list *l = mmap(0,preallocate,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
		if ( l<=0 )
				return(l);

		memset(l,0,sizeof(list));
		l->preallocate = preallocate;
		l->memend = preallocate + l; // - nodesize 
		l->first = l->last = (node*)((ulong)((node*)l+sizeof(list))); // | NEXTISFREE);
		l->first->next = 0;
		return(l);
}

#define DEFINE_LIST(type) \
	inline int __attribute__((always_inline))Lappend_##type( list *l, \
		type *element, int len ){ \
				type* tmp =(type*)_append(l,(void*)element,len); \
				*tmp = 0; \
	} \
\
	inline type* __attribute__((always_inline))Lfirst_##type(list *l){ \
				return((type*)_first(l));} \
\
	inline type* __attribute__((always_inline))Lnext_##type(type *current){ \
				return((type*)_next((node*)(current)));}

// doesn't look for free nodes within list
// return the nodecount on success, 0 on error (nomem)
// does a copy of the supplied element.
// if len of all elements is the same, (e.g.pointers)
// please use "array"
// get the metadata by modulo to the next pagebreak downwards.
// (store the metadata, and the link to the "main" metadatas there) 
// store len(and pos) of elements also there? better not.
// when iterating, the area would need to be loaded every time.
void* _append( list* l, void* e, int len ){
		if ( l->last + len + sizeof(node) > (node*)l->memend ){
				// alloc, set l->last and memend
		}
		l->last->next = (node*)(len+(sizeof(node)*2));
		memcpy(l->last+sizeof(node*),e,len);
		l->last = l->last->next;
		memset(l->last, 0, sizeof(node) );
		l->nodecount++;
		return( l->last+sizeof(node)  );
}

// internal. cast in the derived wrappers.
void* _first(list *l){
		return( l->first );
}

void* _next(void *n){
		return(((node*)n-sizeof(node))->next);
}
