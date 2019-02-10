# makefile for the tests
#

PROG=hello malloc failtest-segfault

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

ifndef GREEN
#colors..
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[01;33m"
BLUE="\033[01;33m"
WHITE="\033[01;37m"
endif


ifdef BUILDPROG
		PROG=$(BUILDPROG)
		include ../makefile.include
else


all:
	@$(foreach P,$(PROG),$(MAKE) BUILDPROG=$(P) && ) true

inittest: all
	@$(foreach P,$(PROG), ./$(P) > results/$(P)-expect.stdout ; ) true
	

test: all
	@$(foreach P,$(PROG), ./$(P) > results/$(P)-test.stdout || echo Fail > results/$(P)-test.stdout; ) true
	@rm -f failed.txt passed.txt
	@$(foreach P,$(PROG), diff -q results/$(P)-expect.stdout results/$(P)-test.stdout 1>null && (echo $(GREEN)Pass:$(WHITE) $(P) && echo $(P) >> passed.txt) || (echo $(RED)Fail:$(WHITE) $(P) && echo $(P) >> failed.txt)   ; ) true


clean:
	$(foreach P,$(PROG),$(MAKE) clean BUILDPROG=$(P) && ) true
	rm -f results/*-test.stdout

rebuild: clean all


endif
