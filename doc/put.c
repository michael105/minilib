#if 0  // has to be the first line
# mini_start is the start routine.
# Most possibly needed
mini_start

# define and compile puts
mini_puts

INCLUDESRC
# this is a comment.
# INCLUDESRC has to be defined for one sourcefile.
# without it only the defines, and no implementations are parsed.

SHRINKELF

LDSCRIPT onlytext.tiny

# return, and the #endif statement are the last lines of the config
return  
#endif

int main(int argc, char *argv[] ){
    puts("Hello, world!");
		return(0);
}
