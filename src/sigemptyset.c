#ifndef sigemptyset_c
#define sigemptyset_c
// copied from musl. 

//+header signal.h
//+include
//+def
static int sigemptyset(sigset_t *set){

		set->sig[0]=0;

		if ((8/sizeof(long)) > 1)
				set->sig[1]=0;

		return 0;
}

#endif

