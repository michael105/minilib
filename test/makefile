# makefile for the tests
#

PROG=hello malloc

# where to build object files
#BUILDDIR=.

# minilib's location
MLIBDIR=../

# Don't create obj files, include evrything in one gcc run.
SINGLERUN=1 

#Set the optimization flag (default: -O1)
#OPTFLAG=-Os

# GCC
GCC=gcc

# LD
#LD=ld


ifdef test
		PROG=$(test)
		include ../makefile.include
else


all:
	$(foreach P,$(PROG),$(MAKE) test=$(P) && ) true


clean:
	$(foreach P,$(PROG),$(MAKE) clean test=$(P) && ) true

rebuild: clean all


endif
