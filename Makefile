ifndef PROG
#PROG=examples/hello
endif

ifndef RECURSE
#$(info Type 'make help' for help)
RECURSE=1
endif

ONLYTEXT=1
NOINCLUDE=1

NOW="$(shell date '+%Y%m%d')"
#NOW=$(shell echo `date '+%F %T'` )
#NOW=$(shell echo `date +%F` r$$[ `date +%s` - 1579400000 ] )

#include Makefile.template

.PHONY: test compiled/minilib.h header tools compiled/Makefile.minilib

define HELP

make targets:

all
  header compile-minimake doc examples test
	
examples
	make examples

header
	rebuild header files, also rebuild some of the generated documentation.

doc
	rebuild generated documentation: html files, minimake info

minimake
	rebuild the script minimake, pack ldscripts and config scripts

compile-minimake
	pack the gzipped (complete) minilib into minimake
	(run minimake --dump-minilib to extract the header to stdout)

unpack-minimake
	strip the gzipped minilib of minimake

compiled/minilib.h
	compile compiled/minilib.h, compiled/minilib.h.gz (single header sourcefile)

devel
	make header compiled/minilib.h compile-minimake

tools
	make tools in the dir ./tools
	(shrinkelf)

test
	make and run tests in ./test/

retest
	rebuild the tests in test, 
	run make test after that
	for rebuilding the expected output of the tests as well,
	please have a look into ./test/Makefile

syntaxcheck
  rebuild the file syntaxcheck.h,
  intended to be included for syntaxchecking plugins.
  All declarations of minilib are define there.

help
	show this help


Most possibly you'll need: "make compile-minimake", and "make test"
Both run all needed other targets.

However, building with minilib is sort of transparent:
You can include the uncompiled "minilib.h", which will include
all other header files.
And you can include the compiled "minilib.h", as only dependency.

When compiling with minimake, minilib.h will be prepended to the sources,
automatically. Again, when minilib.h is compiled into minimake; these
sources will be used. When minilib.h is present as file, this will be preferred.
(Making development easier - no need to compile minimake every time)

The included compat headers are not stable yet.
(stdio.h, stdlib.h, ...)
I leave them here. 
But better avoid them. 
Besides sometimes giving trouble, they define the functions and variables of the 
standard libc header files with the same name.
What will give neccessarily some bloat.

For using a syntaxchecker plugin there's the header file syntaxcheck.h
Just include this, to have all functions, macros and variables, minilib provides,
defined. 

To use it, either include it via 
#include "syntaxcheck.h"

Or, as me with vi syntaxchecker plugin, just add the syntaxcheck header to 
the includes sources of the plugin.

For further documentation please have a look into README.asc, and the folder ./doc/

Michael (misc) Myer, 2012-2021, all rights reserved. 
Free use with attribution. Please have a look into 
the file LICENSE for the licensing terms.
endef

help:
	$(info $(HELP)) 
	@echo -ne  # surpress status 



default: help

all: header compiled/minilib.h compile-minimake compiled/Makefile.minilib doc examples test syntaxcheck

devel: header compiled/minilib.h compile-minimake compiled/Makefile.minilib

examples:
	cd examples && make

test: 
	(cd test && make test) 2>&1 | tee test/make-test.log

testql: 
	cd test && make testql

testql-gcc9: 
	cd test && make testql-gcc9

testql-build: 
	cd test && make all

retest: 
	cd test && make retest

header:
	cd headers && make
	./scripts/genheaders.pl ./ minilib/include/*.h minilib/macros/*.h minilib/src/*/*.h minilib/src/*/*.c
	rm minilib.conf.tmp minilib.conf.all.tmp minilib.genconf.h.tmp
	sed -i '/^SYSDEF_syscall/d;/^DEF_syscall/d' minilib.h

# ./minimake --config minilib.conf.all -E minilib.h -Wno-all -dD | sed -e 's/^# /\/\/ /;/^$$/d;/^[[:space:]]*from/d;/^\.\//,2d' &&\

doc: header
	cd doc && make

minimake: scripts/genconfig.sh ldscript
	@echo dbg. var: $^ 
	scripts/template.pl minimake genconfig scripts/genconfig.sh
	scripts/template.pl minimake genconf-macros minilib.genconf.h
	scripts/template.pl minimake headerguards include/headerguards.h
	sed -ie 's/^VERSION=.*/VERSION=$(NOW)/' minimake
	rm minimakee


compile-minimake: minimake unpack-minimake
	gzip -c compiled/minilib.h >> minimake
	echo -e "\n#ENDGZ" >> minimake


unpack-minimake:
	sed '/^#MINILIBGZ#$$/q' minimake > minimake.tmp
	cp minimake.tmp minimake
	rm minimake.tmp


ldscript: ldscripts/ld.script*
	@echo dbg, ldscripts. var: $^ 
	echo "# Parsing" | scripts/template.pl minimake content-ldscript
	sh scripts/ldscripts.sh $^ 


			#echo -n "$(FILE)" | sed -e "s/.*\///" -e "s/\./_/g" && echo "='" | scripts/template.pl -insert minimake content-ldscript; echo J ) )  
	
	#| scripts/template.pl -insert minimake content-ldscript )  )   

tools:
	cd tools && make

compiled/minilib.h: tools
	cp templates/LICENSE.tmpl compiled/minilib.h
	echo -e "#ifndef compiled/minilib_h\n#define compiled/minilib_h\n" > compiled/minilib.tmp2.h && \
			scripts/combinesources.pl minilib.h >> compiled/minilib.tmp2.h && \
			sed -e '$$d' compiled/minilib.tmp2.h | sed -e '$$d' > compiled/minilib.tmp.h && \
			echo -e "#endif\n#ifdef SHRINKELF" >> compiled/minilib.tmp.h && \
			cat tools/shrinkelf.c >> compiled/minilib.tmp.h &&\
			echo -e "#endif\n#ifdef SHRINKELF_MCONF" >> compiled/minilib.tmp.h &&\
			cat tools/shrinkelf.mconf >> compiled/minilib.tmp.h &&\
			echo -e "#endif\n" >> compiled/minilib.tmp.h
	cat compiled/minilib.tmp.h | ./tools/removeccomments | sed -E 's/(.*)\/\*.*\*\//\1/' | ./tools/stripblanks | scripts/stripundefs.pl >> compiled/minilib.h
	#cat compiled/minilib.tmp.h | ./tools/removeccomments | sed -E 's/(.*)\/\*.*\*\//\1/' | ./tools/stripblanklines | sed -E '/^#if 0/,/^#endif/d;'s/^\s*//' > compiled/minilib.h
#./tools/scc/scc compiled/minilib.tmp.h | sed '/^\s*$$/d' > compiled/minilib.h
#	gcc -fpreprocessed -P -dD -E compiled/minilib.tmp.h 2>/dev/null > compiled/minilib.h || true
#	cp templates/LICENSE.tmpl compiled/minilib.h
#	scripts/combinesources.pl include/minilib_header.h >> compiled/minilib.h
#	gzip -c compiled/minilib.c > compiled/minilib.c.gz
	sed -i '/^SYSDEF_syscall/d;/^DEF_syscall/d' compiled/minilib.h
	gzip -c compiled/minilib.h > compiled/minilib.h.gz


compiled/Makefile.minilib:
	echo generate $@
	sed -i -e 's/^VERSION:=.*/VERSION:=$(NOW)/' $@
	sed -i -e '/^#genconfig_start/r scripts/genconfig.sh' -e '/^#genconfig/p;/^#genconfig/,/^#genconfig/d' $@
	sed -i -e '/^#defaultvalues_start/e sed -n -e "/^#defaultvalues/,/^#defaultvalues/p" minimake' -e '/^#defaultvalues/,/^#defaultvalues/d' $@
	sed -i -e '/^#defaultvalues/,/^#defaultvalues/s/\$$/$$$$/g' $@
	sed -i -e '/^#genconfig/,/^#genconfig/s/\$$/$$$$/g' $@
	sed -i -n -e '0,/^#ldscripts_start/p' $@
	@$(foreach FILE,$(wildcard ldscripts/ld.script*), sh -c "echo define $(FILE) =;cat $(FILE);echo endef;" >> $@; )
	echo "#sha256sums" >> $@
	echo "define sha256sums =" > sign.tmp
	cat $@ | sha256sum  | sed 's/\s$$//g' >> sign.tmp
	cat sign.tmp >> $@
	sha256sum compiled/minilib.h >> $@
	echo "endef" >> $@
	#$(foreach FILE,$(wildcard ldscripts/ld.script*), sh -c "echo '#'$(FILE);cat $(FILE);echo '#'$(FILE);" >> $@; )
	#echo "endif" >> Makefile.minilib


hello-combinedb: hello-combined.c tools
	make SINGLERUN=1 PROG=hello-combined

#note
#cat hello-combined.c | gcc -o hh -static -nostdlib ../asm/start-osx.S -x c -


gitlog:
	git log | sed '/^commit/d;/^Author/d;/^Merge/d;s/^Date:/####/' > gitlog.md


syntaxcheck: 
	$(info Generate syntaxcheck.h)
	cp templates/syntaxcheck.h.top ./syntaxcheck.h
	$(info echo copies)
	./minimake --dump-config minilib.conf.all > minilibcfg-syntaxcheck.h
	( gcc -include minilibcfg-syntaxcheck.h minilib.h -E -dD -DGENSYNTAXCHECK -I. -I./include -I./headers -nodefaultlibs -nostdlib -DMLIB -fno-builtin -DLINUX -DX64 | sed -e 's/^# /\/\/ /;/^$$/d' | sed '/stdc-predef/,/command-line/d;/<built-in>/,/\/\/ /d;/^SYSDEF/d' &&\
			cat templates/syntaxcheck.h.bottom ) |\
			sed -E '/optimization_fence/d;/^static.*\{$$/,/^\}$$/{s/(^static.*)\{/\1;/p;d}' | sed -E '/^const.*\{$$/,/^\}$$/{s/(^const.*)\{/\1;/p;d}' >> syntaxcheck.h 
	$(info Ok)


git-master:
	# update master repo at github
	git push origin devel-HEAD:devel
	cd ../minilib-master && \
		git fetch && \
		git pull && \
		git push github devel:master

git-devel:
	# update master repo at github
	git push origin devel-HEAD:devel
	cd ../minilib-devel \
		git fetch && \
		git pull && \
		git push github


packtestresults:
	cd test && make packtestresults


