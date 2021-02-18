#ifndef ino_dirs_h
#define ino_dirs_h

typedef unsigned int p_rel;

// how many directories per (preallocated) page
// -> (PAGESIZE/16) = 256 for 4kB pages.
// each path can be in the medium (PAGESIZE-4*256 - 20)/256 Bytes.
// The notify dirlist ist dynamically grown.
#define NOTIFY_DIRS (PAGESIZE/16)

// contains the nfd / directory keys
typedef struct _notify_dirs{
		p_rel path[NOTIFY_DIRS];
		struct _notify_dirs* next;
		int max;
		int subtract;
        // dynamic string section starts here
		char stringsstart[0];
} notify_dirs;


notify_dirs* ino_dir_init( notify_dirs *id );

void ino_dir_destroy( notify_dirs *nod, int nfd );

const char* ino_dir_get( int num, notify_dirs *nod );

void ino_dir_add( int num, const char* path, notify_dirs *nod );

// notes: 1 bit for a deleted string.
//  1 bit for a replaced string with different len.
// freelist. no. optimized for sequential insertion and 
// access by number.
// but should have a "prev" pointer. (looking backwards).
// skiplist? no. 
// len: return pnext - p. ( no scanning needed )
// -> also possible to use vectorized instructions. 
//    ( no access fault on scanning behind a string )
// -> besser als struct: union. no. 
//    accessor functions needed. so.
// name: str
//  char* getstr( strings, num )
//  char* appendstr(strings, const char*)
//  char* delstr
//  replacestr
//  insertstr
//  appendstr changes the reference of strings to the last node.
//   -> sequential appends are speeded up.
// 
//  define struct in a macro. ( size of mem to map, count of elements )
//  ( oder dyn array?)
//


#endif
