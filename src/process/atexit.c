//+doc register functions, which are callen on exit in reverse order
// the switch mini_atexit takes a optional number,
// which defines the maximum numbers of functions to be registered.
// (defaults to 8)
//+depends globals
//+def
static int atexit( functionp* func ){
		int p=0;
		while( mlgl->atexitp[p] != 0 ){
				p++;
				if ( p>=ATEXIT_MAX )
						return( ENOMEM );
		}
		mlgl->atexitp[p] = func;
		if ( p<ATEXIT_MAX-1 )
				mlgl->atexitp[p+1] = 0;

		return(0);
}
