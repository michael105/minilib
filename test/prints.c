#if 0

mini_start
mini_writes
mini_prints
mini_INCLUDESRC

if [ -n "$CLANG" ]; then
# clang makes trouble with optimizations and strdup
	OPTFLAG -Os
fi

return
#endif


int main(int argc, char**argv, char** envp){

		char *c = "string.\n";

		write(1,c,8);
		writes("Calling prints\n");
		prints("prts: ",c,"\n");
		prints("prints2\n");

		return(0);
}
