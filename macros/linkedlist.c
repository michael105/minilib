

typedef struct __node {
		struct __node* next;
		// void* e; // commented this out. it is not needed.
		// e.g. with the alloc list, there is no element data needed,
		// just the pure node itself. (and the value of preallocate)
		// casting is needed in each case, so.
} node;


typedef struct __list {
		node *first;
		node *last;
		node *freenode_p;
		// >0: pointer to the first free (or previuosly free) node, 
		// more free nodes are (if present) always right of "freenode_p".
		// the skipping is cheap, but can spare quite some searching time.
		node *alloclist; // list with all malloce'd areas
		void* memend;
		int nodesize;
		int esize;
		int preallocate;
		int freenodecount;
		int nodecount;
		int align[3];
} list;


static list* newlist(int elementsize, int preallocate){
		if ( preallocate == -1 )
				preallocate = PAGESIZE;
		//list *l = malloc(preallocate);
		list *l = mmap(0,preallocate,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
		if ( l<=0 )
				return(l);

		memset(l,0,sizeof(list));
		l->nodesize = elementsize+sizeof(node);
		l->esize = elementsize;
		l->preallocate = preallocate;
		l->memend = preallocate + l; // - nodesize 
		return(l);
}

// doesn't look for free nodes within list
// return the nodecount on success, 0 on error (nomem)
static int _append(list* l,void* e){
		if ( ! l->first ){
				l->first = l->last = (node*)l+sizeof(list);
		} else {
				node* t = l->last;
				l->last += l->nodesize;
				if ( l->last + l->nodesize > (node*)l->memend ){
						// alloc, set l->last and memend
				}
				t->next = l->last;
		}
		l->last->next = 0;
		l->nodecount++;
		
		memcpy(l->last+sizeof(node*),e,l->esize);
		
		return( l->nodecount );
}
		
node* _first(list *l){
		return( l->first );
}

node* _next(node *n){
		return(n->next);
}
