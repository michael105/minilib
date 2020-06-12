# makefile for the tests
#

#PROG=malloc select
PROG=hello

PROGCUSTOM=fopen malloc fprintf select fputs fgets


MINIGCC=rand sleep execve strdup

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

STRIP=1

#SHRINKELF=1

ONLYTEXT = hello-smallest hello-include fputs

ifndef GREEN
#colors..
GREEN="\033[00;32m"
LGREEN="\033[01;32m"
RED="\033[00;31m"
LRED="\033[01;31m"
YELLOW="\033[01;33m"
BROWN="\033[00;33m"
BLUE="\033[00;34m"
LBLUE="\033[01;36m"
#BLUE="\033[01;33m"
#LBLUE="\033[00;36m"
WHITE="\033[01;37m"
GREY="\033[02;37m"
endif


ifdef BUILDPROG
		PROG=$(BUILDPROG)
		include ../Makefile.minilib
else

$PROGLIST4="$(PROG) hello-combined failtest-segfault"

all: fputs hello-combined hello-include hello-smallest args build/minilib.o $(PROGCUSTOM)
	@$(foreach P,$(PROG) failtest-segfault,$(MAKE) BUILDPROG=$(P) && ) true
	@$(foreach P,$(MINIGCC) , (echo minilib/mini-gcc --config $(P).c -o $(P) $(P).c && minilib/mini-gcc --config $(P).c -o $(P) $(P).c ) && ) true

test-generated: 
	cd generated && make clean
	cd generated && make test

fopen: fopen.c
	minilib/mini-gcc --config fopen.c -o fopen fopen.c

build/minilib.o: minilib.conf
	minilib/mini-gcc --config minilib.conf -c -o build/minilib.o minilib.c -DINCLUDESRC

fprintf: fprintf.c
	minilib/mini-gcc --config fprintf.c -o fprintf fprintf.c


malloc: malloc.c
	minilib/mini-gcc --config malloc.mconf -o malloc malloc.c

select: select.c
	minilib/mini-gcc -o select select.c

fgets: fgets.c
	minilib/mini-gcc --config fgets.c -o fgets-bin fgets.c
	echo '#!/bin/sh' > fgets 
	echo 'echo -e "Xesting\nfgets\n" | ./fgets-bin' >> fgets
	chmod a+x fgets


args: args.c
	make BUILDPROG=args SINGLERUN=1 NOINCLUDE=1


hello-combined: hello-combined.c
	make BUILDPROG=hello-combined SINGLERUN=1 NOINCLUDE=1

fputs: fputs.c
	make BUILDPROG=fputs SINGLERUN=1 NOINCLUDE=1


hello-include: hello-include.c
	make BUILDPROG=hello-include SINGLERUN=1 NOINCLUDE=1

hello-smallest: hello-smallest.c
	make BUILDPROG=hello-smallest SINGLERUN=1 NOINCLUDE=1 ONLYTEXT=1

# collect the expected output of the applets
inittest: all
	@$(foreach P,$(PROG) $(PROGCUSTOM) $(MINIGCC) hello-combined, ./$(P) > results/$(P)-expect.stdout ; ) true
	
retest: test rebuild
	make test

test: all
	@rm -f failed.txt passed.txt
	@echo Test segfaulting && (./failtest-segfault && echo -e $(RED)Fail: No segfault$(WHITE) ) || echo -e $(GREEN)Pass:$(WHITE) got segfault
	@$(foreach P,$(PROG) hello-combined $(PROGCUSTOM) $(MINIGCC), \
			echo -e $(LBLUE)Test:$(WHITE) $(P) $(BLUE) && \
			(( sh -c 'export TTM1=check1;export TTM2="Checking different env values";export TTM3=Ok;\
			set -o pipefail; ./$(P) | \
			tee results/$(P)-test.stdout; exit $$PIPESTATUS'  ) && \
			echo -e $(GREEN)Exec:$(WHITE) Ok && \
				diff -q results/$(P)-expect.stdout results/$(P)-test.stdout 1>null && (echo -e $(GREEN)Pass:$(WHITE) $(P) && echo -e $(P) >> passed.txt) || (echo -e $(RED)Fail:$(WHITE) $(P) && echo -e $(P) >> failed.txt) \
			  ) || \
			( echo -e $(RED)Fail$(WHITE) && echo Fail > results/$(P)-test.stdout); ) true
	@(echo -e $(YELLOW)==============================\\n $(LGREEN)  PASSED: && cat passed.txt && echo -e $(WHITE) )
	@if [ -e failed.txt ]; then ( echo -e  $(RED)   FAILED: && cat failed.txt && echo -e $(WHITE) && false ); fi


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
