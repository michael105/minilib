// A variable length array.
//
// Allocate a page (or several, but this size is fixed, and
// has to be > PAGESIZE and must have a base of 2 ( 1<<x ) 
// In the first bytes of each area, metadata and a bitfield is stored.
// The bitfield show used and unused elements, for each element one
// bit is set ( or 0 ).
// -> free elements can be seeked for via vectorized operations;
// the count can be calculated via bitcnt (__builtin _bitcnt)
// For looking for an empty place, for each 8 Bytes (64bit)
// = the bits are set to 0 for used areas.
// For free areas, they are deleted. -> 
// look for a free area: if bitfield[0]>0 -> there's a free place.
// then, b split; andsoon. ( for exactly these ops there are also simd mmx
// instructions.)
// (would also work: if b < 0xffffffff then ...
// but needs at least one op more. (set the value 0xffffffff).
// 0: xor rax;rax. -> neg.
//
// To get from one element to the metadata, a simple bit shift is enough.
// There is the drawback of having to load the bitfield into the cacheline.
// When many elements are set/deleted; possibly cache the bitfield.
// would need benchmarking. This depends. Don't know
// how expensive the loading from the L2 (or L3?) Cache is exactly.
//
// The metadata: link to other areas. counter of free elements.
// As soon one page is full, use one whole page for the metadata. ?
// Or when more than 3 pages are full. One jump is needed anyways. then.
//

// an array could be a ** pointer to a pointer. ->
// when an array get's an parent, all pointers can get transparently updated.
// (transparent in the view of the array.)

typedef struct __array {
	int pfree; 
	// when elements have been deleted, point to the last removed free pos
	// when the removed element has been inserted again, make the value negative
	int last;
	int elementsize;
	struct	__array* parent; // next. alle zirkulaer verbunden. obwohl.
	// schlecht beim suchen nach einem bestimmten element.
	void* start; // where the entries start. between: bitfield. used/free
	// (important when moving the array metadata to somewhere else.)
	int size;
	int count;
	void* bitfield;
} array;

// ok. should always preallocate 1 page. 
// -> get the metadata: bitshift one element, read the pointer "parent"

// allocate a new array. uses mmap.
//
// preallocate: the number of pages to preallocate,
// for data and the internal structure.
// (1 page is 4kB here). when 0, one page is preallocated.
//
// The metadata has this size: 
// sizeof(pointer)*2 + 4*sizeof(int) + 
// (size-sizeof(pointer)*2+4*sizeof(int)) /elementsize/8
// In words, the overhead is one bit per element, 
// plus the storage of 2 pointers and 4 integers for the whole array.
//
array** newarray( int preallocate ){
		if ( preallocate == 0 )
				preallocate = PAGESIZE;
		array *a = mmap(0,preallocate,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
		if ( a<=0 )
				return(0); // errno already set by mmap

		memset(a,0,sizeof(array));
		a->size=preallocate*PAGESIZE;
		//a->parent = a;

		a->start = a + (sizeof(array)) + ( a->size/sizeof(char)/8 ); 
		memset(a->bitfield,0xFF,(a->start - a->bitfield)); // todo: set longs


		return(&a->parent);
}


char* insert(array *a, char* e){
		if ( a->pfree == 0 )
				return(0);
		long *b;
		for ( b=(long*)a->bitfield; b<(long*)a->start; b++ ){
				if ( *b>0 ){

				}
		}
		// no empty place left
		// create parent, and a new array.
}

char* first(array *a){
		return(

char* append(array *a, char*e){
		if ( a->last < a->size ){
				*(char*)(a+a->last) = *e;
				return((char*)(a+a->last));
		} 
		// array is full. (possibly sparse) 
		// create new array

}








