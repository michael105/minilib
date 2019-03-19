# makefile for the tests
#

PROG=hello malloc args select

# where to build object files
#BUILDDIR=.

# minilib's location
MLIBDIR=../

# Don't create obj files, include evrything in one gcc run.
#SINGLERUN=1 

#Set the optimization flag (default: -O1)
OPTFLAG=-Os

# GCC
GCC=gcc

# LD
#LD=ld

#ELFTRUNC=1


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

$PROGLIST4="$(PROG) hello-combined failtest-segfault"

all: hello-combined hello-include hello-smallest
	@$(foreach P,$(PROG) failtest-segfault,$(MAKE) BUILDPROG=$(P) && ) true

hello-combined: hello-combined.c
	make BUILDPROG=hello-combined SINGLERUN=1 NOINCLUDE=1

hello-include: hello-include.c
	make BUILDPROG=hello-include SINGLERUN=1 NOINCLUDE=1

hello-smallest: hello-smallest.c
	make BUILDPROG=hello-smallest SINGLERUN=1 NOINCLUDE=1 ONLYTEXT=1

inittest: all
	@$(foreach P,$(PROG) hello-combined, ./$(P) > results/$(P)-expect.stdout ; ) true
	
malloc: malloc.c
	make BUILDPROG=malloc

test: all
	@rm -f failed.txt passed.txt
	@echo Test segfaulting && (./failtest-segfault && echo -e $(RED)Fail: No segfault$(WHITE) ) || echo -e $(GREEN)Pass:$(WHITE) got segfault
	@$(foreach P,$(PROG) hello-combined, \
			echo -e $(LBLUE)Test:$(WHITE) $(P) $(GREY) && \
			(( sh -c 'set -o pipefail; ./$(P) | \
			tee results/$(P)-test.stdout; exit $$PIPESTATUS'  ) && \
			echo -e $(GREEN)Exec:$(WHITE) Ok && \
				diff -q results/$(P)-expect.stdout results/$(P)-test.stdout 1>null && (echo -e $(GREEN)Pass:$(WHITE) $(P) && echo -e $(P) >> passed.txt) || (echo -e $(RED)Fail:$(WHITE) $(P) && echo -e $(P) >> failed.txt) \
			  ) || \
			( echo -e $(RED)Fail$(WHITE) && echo Fail > results/$(P)-test.stdout); ) true


# @$(foreach P,$(PROG), diff -q results/$(P)-expect.stdout results/$(P)-test.stdout 1>null && (echo $(GREEN)Pass:$(WHITE) $(P) && echo $(P) >> passed.txt) || (echo $(RED)Fail:$(WHITE) $(P) && echo $(P) >> failed.txt)   ; ) true



clean:
	#$(foreach P,$(PROGLIST4),$(MAKE) clean BUILDPROG=$(P) && ) true
	#$(foreach P,$(PROGLIST4), rm $(P) && ) true
	rm $(PROG) failtest-segfault hello-combined hello-smallest hello-include || true
	echo $(PROG) failtest-segfault hello-combined || true
	rm -f results/*-test.stdout
	rm -f build/*

rebuild: clean all


endif
