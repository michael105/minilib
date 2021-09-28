//+def
static int killpg( int pid, int signal ){
	return( kill( -pid, signal ) );
}

