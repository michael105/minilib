#if 0
mini_start
mini_writes
mini_pivot_root
INCLUDESRC
LDSCRIPT text_and_bss
HEADERGUARDS
shrinkelf
return
#endif


int main(int argc, char *argv[]){
		if ( argc != 3 ){
				writes("usage: pivot_root newroot put_oldroot\n");
				return(0);
		}
		return( pivot_root(argv[1], argv[2]) );
}
