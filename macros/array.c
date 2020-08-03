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
	struct	__array* parent; // next. alle zirkulaer verbunden. obwohl.
	// schlecht beim suchen nach einem bestimmten element.
	int size;
	int elementsize;
	int count;
	int start; // where the entries start. between: bitfield. used/free
	// here: bitfield
} array;


