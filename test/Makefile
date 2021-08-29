# makefile for the tests
#

#PROG=malloc select
PROG=hello

PROGCUSTOM=fopen malloc fprintf select fputs

# ebedded config, mlcc, wildcard target
MAKEPROGS=fprintf fopen strchr strstr system environ static \
					hashes realloc div globals atexit \
					strerror mallocstack strtol putenv strcmp\
					getpwuid getgrgid getgrnam getgroups prints

FAILING=ltodec sigaction vfork vforked

MINIGCC=rand sleep execve strdup

TESTQL=getpwuid globals mallocstack strcmp strstr strtol \
		 getpwuid fputs globals



# where to build object files
#BUILDDIR=.

# minilib's location
MLIBDIR=../

# Don't create obj files, include evrything in one gcc run.
#SINGLERUN=1 

#Set the optimization flag (default: -O1)
OPTFLAG=-Os

# CC
GCC=clang

# LD
#LD=ld

STRIP=1

export STRIPFLAG=-I.

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


tpath=$(shell date '+%Y%m%d_%H%M')

ifdef BUILDPROG
		PROG=$(BUILDPROG)
		include Makefile.minilib.old
		#make -f ../Makefile.minilib CONF=$(BUILDPROG)
else

$PROGLIST4="$(PROG) hello-combined failtest-segfault"

all: fputs hello-combined hello-include hello-smallest args $(PROGCUSTOM) $(MAKEPROGS) common.conf
	@$(foreach P,$(PROG) failtest-segfault,$(MAKE) BUILDPROG=$(P) && ) true
	@$(foreach P,$(MINIGCC) , (echo minilib/mlcc --config $(P).c -o $(P) $(P).c && minilib/mlcc --config $(P).c -o $(P) $(P).c ) && ) true

test-generated: 
	cd generated && make clean
	cd generated && make test

%: %.c
	minilib/mlcc --config $< -o $@ $<

build/minilib.o: minilib.conf
	minilib/mlcc --config minilib.conf -c -o build/minilib.o minilib.c -DINCLUDESRC


malloc: malloc.c
	minilib/mlcc --config malloc.mconf -o malloc malloc.c

select: select.c
	minilib/mlcc -o select select.c -Iminilib/include -Iminilib/headers/common -Iminilib/headers/linux_x64 -Iminilib/macros -nostdinc

fgets: fgets.c
	minilib/mlcc --config fgets.c -o fgets-bin fgets.c
	echo '#!/bin/sh' > fgets 
	echo 'echo -e "Xest\nfgets\n" | ./fgets-bin' >> fgets
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
	@$(foreach P,$(PROG) $(MAKEPROGS) $(PROGCUSTOM) $(MINIGCC) hello-combined, ( if [ -x $(P).sh ]; then ./$(P).sh; else ./$(P); fi ) > results/$(P)-expect.stdout ; ) true
	
retest: test rebuild
	make test


.ONESHELL:
packtestresults:
	echo p: $(tpath) $$target
	mkdir "./$(tpath)"
	@$(foreach P,$(PROG) $(MAKEPROGS) $(PROGCUSTOM) $(MINIGCC) hello-combined, ( if [ -e $(P) ]; then cp $(P) ./$(tpath); fi;  ); ) true
	cp *.log ./$(tpath)
	cp results/*test.* ./$(tpath)
	gcc -dumpspecs > ./$(tpath)/gcc-dumpspecs
	ld --verbose > ./$(tpath)/ld.verbose
	clang -v > ./$(tpath)/clang-v
	ls /usr/bin | gzip > ./$(tpath)/usrbin.gz
	ls /bin | gzip > ./$(tpath)/bin.gz
	ls /sbin | gzip > ./$(tpath)/sbin.gz
	ls /usr/sbin | gzip > ./$(tpath)/usrsbin.gz
	tar -czf results-packed.tgz ./$(tpath)


.ONESHELL:
SHELL = /bin/bash
test: all
	@rm -f failed.txt passed.txt
	@echo Test segfaulting && (./failtest-segfault && echo -e $(RED)Fail: No segfault$(WHITE) ) || echo -e $(GREEN)Pass:$(WHITE) got segfault
	@$(foreach P,$(PROG) hello-combined $(MAKEPROGS) $(PROGCUSTOM) $(MINIGCC), \
			echo -e $(LBLUE)Test:$(WHITE) $(P) $(BLUE) && \
			(( sh -c 'export TTM1=check1;export TTM2="Checking different env values";export TTM3=Ok;\
			( if [ -x $(P).sh ]; then ./$(P).sh; else ./$(P); fi;\
			if [ $$? != 0 ]; then echo $(RED) Fail; fi )| \
			tee results/$(P)-test.stdout'  ) && \
			echo -e $(GREEN)Exec:$(WHITE) Ok && \
				diff -q results/$(P)-expect.stdout results/$(P)-test.stdout 1>null && (echo -e $(GREEN)Pass:$(WHITE) $(P) && echo -e $(P) >> passed.txt) || (echo -e $(RED)Fail:$(WHITE) $(P) && echo -e $(P) >> failed.txt) \
			  ) || \
			( echo -e $(RED)Fail$(WHITE) && echo Fail > results/$(P)-test.stdout); ) true
	@(echo -e $(YELLOW)==============================\\n $(LGREEN)  PASSED: && sort passed.txt && echo -e $(WHITE) )
	@if [ -e failed.txt ]; then ( echo -e  $(RED)   FAILED: && sort failed.txt && echo -e $(WHITE) && false ); fi



# ( if [ -x $(P).sh ]; then ./$(P).sh; else ./$(P); fi )| 
#set -o pipefail; ( if [ -x $(P).sh ]; then ./$(P).sh; else ./$(P); fi )| 



.ONESHELL:
testql: all
	@rm -f failed.txt passed.txt
	@echo Test segfaulting && (./failtest-segfault && echo -e $(RED)Fail: No segfault$(WHITE) ) || echo -e $(GREEN)Pass:$(WHITE) got segfault
	@$(foreach P,hello-combined $(TESTQL), \
			echo -e $(LBLUE)Test:$(WHITE) $(P) $(BLUE) && \
			(( sh -c 'export TTM1=check1;export TTM2="Checking different env values";export TTM3=Ok;\
			( if [ -x $(P).sh ]; then ./$(P).sh; else ./$(P); fi )| \
			tee results/$(P)-test.stdout; exit $$PIPESTATUS'  ) && \
			echo -e $(GREEN)Exec:$(WHITE) Ok && \
				diff -q results/$(P)-expect.stdout results/$(P)-test.stdout 1>null && (echo -e $(GREEN)Pass:$(WHITE) $(P) && echo -e $(P) >> passed.txt) || (echo -e $(RED)Fail:$(WHITE) $(P) && echo -e $(P) >> failed.txt) \
			  ) || \
			( echo -e $(RED)Fail$(WHITE) && echo Fail > results/$(P)-test.stdout); ) true
	@(echo -e $(YELLOW)==============================\\n $(LGREEN)  PASSED: && sort passed.txt && echo -e $(WHITE) )
	@if [ -e failed.txt ]; then ( echo -e  $(RED)   FAILED: && sort failed.txt && echo -e $(WHITE) && false ); fi





# @$(foreach P,$(PROG), diff -q results/$(P)-expect.stdout results/$(P)-test.stdout 1>null && (echo $(GREEN)Pass:$(WHITE) $(P) && echo $(P) >> passed.txt) || (echo $(RED)Fail:$(WHITE) $(P) && echo $(P) >> failed.txt)   ; ) true



clean:
	#$(foreach P,$(PROGLIST4),$(MAKE) clean BUILDPROG=$(P) && ) true
	$(foreach P,$(MAKEPROGS) $(MINIGCC), rm -f $(P) && ) true
	$(foreach P,$(PROGCUSTOM) fgets-bin, rm -f $(P) && ) true
	rm $(PROG) failtest-segfault hello-combined hello-smallest hello-include || true
	echo $(PROG) failtest-segfault hello-combined || true
	rm -f results/*-test.stdout
	rm -f build/*

rebuild: clean all


endif
