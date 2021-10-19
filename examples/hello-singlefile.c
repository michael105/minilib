#if 0
ifdef undef

# Save default. The minibuf is needed for malloc, printf, and file streams.
mini_buf 4000
# define headerguards, to prevent parsing the standard header
HEADERGUARDS

# Startup function
mini_start

# put the globals on stack. 
# (past the last used return address, but before the environment.
# there is more documentation in the readme/reference)
# reserves a fixed register as pointer to the globals
# globals_on_stack

# define var (#define var arg)
# DEFINE var arg

# optimization Flag. Os,O1,O2 might be save. O3 is known to cause sometimes trouble
OPTFLAG -Os

# (with debug info)
#OPTFLAG '-g -Og'

# stripflag ( defaults to -s)
#STRIPFLAG

# Build minilib source
INCLUDESRC

# the ldscript to use
# Can be one of: default, onlytext, textandbss, onlytext_tiny
LDSCRIPT default

# Shrink the compiled binary with shrinkelf
#SHRINKELF

# generate debug info (-Og -g). Overwrites OPTFLAG, STRIPFLAG and SHRINKELF
#DEBUG

# generate debug info, including the source of minilib itself. (-Og -g). 
# Overwrites OPTFLAG, STRIPFLAG and SHRINKELF
#FULLDEBUG


# function switches. Only functions named below will be compiled
COMPILE writes


return
#endif

//
// hello world
// compile with minimake hello-singlefile.c


int main(int argc, char **argv){
	writes("Hello world!\n");
	return(0);
}

