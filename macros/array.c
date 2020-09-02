// A variable length array.
// Performant for: append, remove last, iterating, 
// access per index.
// 
// Insertion and removement of elements within the array is not possible.
// (You could define a empty element for yourself, e.g. 0=empty, or one bit set euqals empty.
// Defining this within the array would either mean to have restrictions
// on the data, or to have some overhead)
//
// For the allocation of the memory either the submitted callback is used,
// or malloc.
//
// The metadata: link to other areas. counter of free elements.
// As soon one page is full, use one whole page for the metadata. ?
// Or when more than 3 pages are full. One jump is needed anyways. then.
//

// an array could be a ** pointer to a pointer. ->
// when an array get's an parent, all pointers can get transparently updated.
// (transparent in the view of the array.)

typedef struct __array {
	struct __array* current;
	struct __array* first;
  struct __array* next;	
  struct __array* previous;
	char* last; // index of the last element
	char* areaend;
	int preallocate;
	int align;
	char* data;
} array;
//typedef _array* array;

typedef struct __iter {
		struct __array* current;
		char* index;
		char* last;
} iter;

array* newarray( int preallocate ){
		if ( preallocate == 0 )
				preallocate = PAGESIZE;
		array *a = mmap(0,preallocate,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
		if ( a<=0 )
				return(0); // errno already set by mmap

		memset(a,0,sizeof(array));
		a->preallocate = preallocate;
		//a->parent = a;
		a->first = a;
		a->current = a;
		a->last = (char*)a+sizeof(array);
		a->areaend = (char*)a+preallocate;

		return(a);
}

iter getiter(array *a){
		iter i;
		i.current = a->first;
		i.index = (char*)(a->first)+sizeof(array);
		i.last =  (char*)(i.current->last); // or areaend, when there's another array appended

		return(i);
}

// set iterator to the first element,
// and return
char* first(iter *i){
		i->current = i->current->first;
		i->index = (char*)(i->current)+sizeof(array);
		return(i->index);
}

char* current(iter *i){
		if ( i->index >= i->last )
				return(0);
		return(i->index);
}


char* next(iter *i){
		i->index ++;
		if ( i->index < i->last )
				return( i->index );
		prints("last\n");
		// current array is at it's last element.
		// get the next array in line 

		return(0);
}

// append an element
// copies the data
char* push(array *a, char*e){
		if ( a->last < a->areaend ){
				*(char*)(a->last) = *e;
				a->last++;
				return((char*)(a->last));
		}
		prints("Full\n");
		// array is full.
		// append another memory area, when possible.
		// if not, create a new array, link it and update the "current" pointer.

		return(0);
}








