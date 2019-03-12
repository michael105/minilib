# A template makefile 
# Set Prog to the program's name
# unpack minilib to the "source dir/minilib"
# or set a link
# copy this makefile into the source dir
# done.

# Or: download the file minilibcombined.c
# have a look in minilib.h, which defines you need
# define your switches, and include 
# minilibcombined.c into one of your sourcefiles.
# 



ifndef PROG
PROG=elftrunc
endif

# where to build object files (defaults to ./ )
#BUILDDIR=build

# Where minilib is installed, or should be installed to
MLIBDIR=../

# Don't create obj files, include everything in one gcc run.
SINGLERUN=1

# Include everything yourself
NOINCLUDE=1

#Set the optimization flag (default: -O1)
OPTFLAG=-O1


# GCC
#GCC=gcc

# LD
#LD=ld



# configsettings ending here


#( This is a recursive makefile and will call itself with this param)
ifdef with-minilib
include $(MLIBDIR)/makefile.include 
endif

#Compile with minilib or without
# Will compile with minilib, if present and found in MLIBDIR
default: 
	$(if $(wildcard $(MLIBDIR)/makefile.include), make with-minilib=1, make native )


# build without minilib
# compile with dynamic loading, os native libs
native: $(PROG).c
	$(info call "make getminilib" to fetch and extract the "minilib" and compile $(PROG) static (recommended) )
	gcc -o $(PROG) $(PROG).c


# we haven't been callen recursive
ifndef with-minilib

ifndef BUILDDIR
		BUILDDIR=.
endif

rebuild:
	make clean
	make

clean:
	$(shell rm $(PROG))
	$(shell cd $(BUILDDIR) && rm *.o)

endif

getminilib: $(MLIBDIR)/minilib.h

$(MLIBDIR)/minilib.h:
	$(info get minilib)
	git clone https://github.com/michael105/minilib.git $(MLIBDIR) || (( (curl https://codeload.github.com/michael105/minilib/zip/master > minilib.zip) || (wget https://codeload.github.com/michael105/minilib/zip/master)) && unzip minilib.zip && mv minilib-master $(MLIBDIR))
	make rebuild

install: $(PROG)
	cp $(PROG) /usr/local/bin

