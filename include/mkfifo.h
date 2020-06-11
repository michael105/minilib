//+header fcntl.h
//+inc
//+def
static int mkfifo( const char* path, mode_t mode ){
		return( mknod(path, mode | S_IFIFO, 0 ) );
}
