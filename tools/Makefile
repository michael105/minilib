.PHONY: all clean


ifndef PROG
PROG=shrinkelf
endif

# where to build object files (defaults to ./ )
BUILDDIR=.

# where should the binares go?
#BINDIR=./static_x64

# Where minilib is installed, or should be installed to
MLIBDIR=minilib

# Don't create obj files, include evrything in one gcc run.(yourself)
SINGLERUN=1

# Include everything yourself
NOINCLUDE=1

# include only the Text section in the resulting elf output
ONLYTEXT= true 

SHRINKELF=1

# Set the optimization flag (default: -O1)
# Be careful with that, -Os as well as -O2 seem to be problematic
# Maybe more functions need to be volatile ?
#
#OPTFLAG=-O1

# GCC
#GCC=gcc

# LD
#LD=ld

#( This is a recursive makefile and will call itself with this param)
ifdef with-minilib
include $(MLIBDIR)/makefile.include 
endif




default: shrinkelf.c
	$(if $(wildcard $(MLIBDIR)/makefile.include), make with-minilib=1, make native)
	
native:
	gcc -o shrinkelf shrinkelf.c -I /usr/include/skalibs/ -l skarnet -L /usr/lib64/skalibs


truem: true.c
	make with-minilib=1 PROG=true

shrinkelf32: shrinkelf32.c
	#gcc -o shrinkelf superstrip.c
	gcc -o shrinkelf32 superstrip.c -I /usr/include/skalibs/ -l skarnet -L /usr/lib64/skalibs

shrinkelf64: shrinkelf64.c
	gcc -o shrinkelf64 shrinkelf64.c -I /usr/include/skalibs/ -l skarnet -L /usr/lib64/skalibs

cleanm:
	rm superstrip
