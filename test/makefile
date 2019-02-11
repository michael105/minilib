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
GREEN="\033[00;32m"
RED="\033[00;31m"
YELLOW="\033[01;33m"
BLUE="\033[01;33m"
LBLUE="\033[00;36m"
WHITE="\033[01;37m"
GREY="\033[02;37m"
endif


ifdef BUILDPROG
		PROG=$(BUILDPROG)
		include ../makefile.include
else


all: hello-combined
	@$(foreach P,$(PROG),$(MAKE) BUILDPROG=$(P) && ) true

hello-combined: hello-combined.c
	SINGLERUN=1
	NOINCLUDE=1
	make BUILDPROG=hello-combined


inittest: all
	@$(foreach P,$(PROG), ./$(P) > results/$(P)-expect.stdout ; ) true
	

test: all
	@rm -f failed.txt passed.txt
	@$(foreach P,$(PROG), \
			echo $(LBLUE)Test:$(WHITE) $(P) $(GREY) && \
			(( sh -c 'set -o pipefail; ./$(P) | \
			tee results/$(P)-test.stdout; exit $$PIPESTATUS'  ) && \
			echo $(GREEN)Exec:$(WHITE) Ok && \
				diff -q results/$(P)-expect.stdout results/$(P)-test.stdout 1>null && (echo $(GREEN)Pass:$(WHITE) $(P) && echo $(P) >> passed.txt) || (echo $(RED)Fail:$(WHITE) $(P) && echo $(P) >> failed.txt) \
			  ) || \
			( echo $(RED)Fail$(WHITE) && echo Fail > results/$(P)-test.stdout); ) true


# @$(foreach P,$(PROG), diff -q results/$(P)-expect.stdout results/$(P)-test.stdout 1>null && (echo $(GREEN)Pass:$(WHITE) $(P) && echo $(P) >> passed.txt) || (echo $(RED)Fail:$(WHITE) $(P) && echo $(P) >> failed.txt)   ; ) true



clean:
	$(foreach P,$(PROG),$(MAKE) clean BUILDPROG=$(P) && ) true
	rm -f results/*-test.stdout

rebuild: clean all


endif
