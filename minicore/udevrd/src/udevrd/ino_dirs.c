
#include "../minilib/syntaxcheck.h"
#include "ino_dirs.h"


notify_dirs* ino_dir_init( notify_dirs *id ){
		id = mmap( 0, PAGESIZE, PROT_READ|PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		die_if( id < 0, ENOMEM, "Couldn't map memory");
		id->max = NOTIFY_DIRS;
		id->next = 0; // for clarity
		setaddr( id->path[0], id->stringsstart );
		OPTFENCE(id);
		return(id);
}


const char* ino_dir_get( int num, notify_dirs *nod ){
		num-=nod->subtract;
		
		if ( num<0 ) // happens for inotify_rm_watch events
				return(0); // closing the inotify fd didn't work out here
		// so every watch needs to be removed when reloading the config :/

		 while( ( num >= nod->max-1) ){ // or addr > map
				 num-= (nod->max-1);
				 if ( nod->next ){
					 	nod = nod->next;
				 } else { // append
						 //die(-14,"No such ino_dir");
						 return(0);
				 }
		 }

		return( getaddr( nod->path[num] ) );
}

void ino_dir_destroy( notify_dirs *nod, int nfd ){
		for (int a = nod->subtract;ino_dir_get(a,nod);a++){
				dbgf(CYAN"remove: %d\n"NORM, a );
				inotify_rm_watch(nfd,a);
		}
		do {
				dbg("unmap");
				char *tmp = (char*) nod;
				nod = nod->next;
				munmap( tmp, PAGESIZE );
		} while ( nod );
}

notify_dirs *ino_dir_addmapping( notify_dirs* nod ){
		dbg("addmapping");
		nod->next = (notify_dirs*)mmap( 0, PAGESIZE, PROT_READ|PROT_WRITE, 
						MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		nod = nod->next;
		nod->max = NOTIFY_DIRS;
		setaddr( nod->path[0], nod->stringsstart );
		return(nod);
}

// append a path. num MUST be sequential
void ino_dir_add( int num, const char* path, notify_dirs *nod ){

		dbgf("num: %d - %s\n",num,path);
		
		if ( !nod->subtract ){
				nod->subtract = num;
		}
		num-= nod->subtract;

		dbgf("num: %d\n",num);
		 while( ( num >= nod->max-1) ){
				 num-=nod->max-1;
				 if ( nod->next ){
					 	nod = nod->next;
				 } else { // append
						 dbg(RED"append mmap"NORM);
						 //goto newmap;
						 nod = ino_dir_addmapping(nod);
						 break;
				 }
		 }

		dbgf("num: %d\n",num);
		if ( nod->path[num+1] )
				dief(0,"ino_dirs: num %d already used!\n",num);
		dbg("0.1");
	
		if ( (int)( (nod->path[num] + 
										( sizeof(p_rel)*(NOTIFY_DIRS - num) ) + 
										// = rel pos of path[num] to stringsstart 
										strlen(path))) >= PAGESIZE ) {  
				dbg("1");
				nod->max = num+1; // addr > map
                num = 0;
				nod = ino_dir_addmapping(nod);
		}

		dbgf("pos: %d   len: %d\n", nod->path[num], strlen(path) );
		dbgf("s1: %d   s2: %d\n", sizeof(notify_dirs), sizeof(p_rel) );

				dbg("copy");
		char *p = stpcpy( getaddr( nod->path[num] ), path );
		p++;
		setaddr(nod->path[num+1],p);
		dbgs( "appended: ", getaddr( nod->path[num] ) );
}

