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

.PHONY: test combined header tools Makefile.minilib

define HELP

make targets:

all
  header compile-minicc doc examples test
	
examples
	make examples

header
	rebuild header files, also rebuild some of the generated documentation.

doc
	rebuild generated documentation: html files, minicc info

minicc
	rebuild the script minicc, pack ldscripts and config scripts

compile-minicc
	pack the gzipped (complete) minilib into minicc
	(run minicc --dump-minilib to extract the header to stdout)

unpack-minicc
	strip the gzipped minilib of minicc

combined
	compile minilibcompiled.h, minilibcompiled.h.gz (single header sourcefile)

devel
	make header combined compile-minicc

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


Most possibly you'll need: "make compile-minicc", and "make test"
Both run all needed other targets.

However, building with minilib is sort of transparent:
You can include the uncompiled "minilib.h", which will include
all other header files.
And you can include the compiled "minilib.h", as only dependency.

When compiling with minicc, minilib.h will be prepended to the sources,
automatically. Again, when minilib.h is compiled into minicc; these
sources will be used. When minilib.h is present as file, this will be preferred.
(Making development easier - no need to compile minicc every time)

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

all: header combined compile-minicc Makefile.minilib doc examples test syntaxcheck

devel: header combined compile-minicc Makefile.minilib

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

# ./minicc --config minilib.conf.all -E minilib.h -Wno-all -dD | sed -e 's/^# /\/\/ /;/^$$/d;/^[[:space:]]*from/d;/^\.\//,2d' &&\

doc: header
	cd doc && make

minicc: scripts/genconfig.sh ldscript
	@echo dbg. var: $^ 
	scripts/template.pl minicc genconfig scripts/genconfig.sh
	scripts/template.pl minicc genconf-macros minilib.genconf.h
	scripts/template.pl minicc headerguards include/headerguards.h
	sed -ie 's/^VERSION=.*/VERSION=$(NOW)/' minicc
	rm minicce


compile-minicc: minicc unpack-minicc
	gzip -c minilibcompiled.h >> minicc
	echo -e "\n#ENDGZ" >> minicc


unpack-minicc:
	sed '/^#MINILIBGZ#$$/q' minicc > minicc.tmp
	cp minicc.tmp minicc
	rm minicc.tmp


ldscript: ldscripts/ld.script*
	@echo dbg, ldscripts. var: $^ 
	echo "# Parsing" | scripts/template.pl minicc content-ldscript
	sh scripts/ldscripts.sh $^ 


			#echo -n "$(FILE)" | sed -e "s/.*\///" -e "s/\./_/g" && echo "='" | scripts/template.pl -insert minicc content-ldscript; echo J ) )  
	
	#| scripts/template.pl -insert minicc content-ldscript )  )   

tools:
	cd tools && make

combined: tools
	cp templates/LICENSE.tmpl minilibcompiled.h
	echo -e "#ifndef minilibcompiled_h\n#define minilibcompiled_h\n" > minilibcompiled.tmp2.h && \
			scripts/combinesources.pl minilib.h >> minilibcompiled.tmp2.h && \
			sed -e '$$d' minilibcompiled.tmp2.h | sed -e '$$d' > minilibcompiled.tmp.h && \
			echo -e "#endif\n#ifdef SHRINKELF" >> minilibcompiled.tmp.h && \
			cat tools/shrinkelf.c >> minilibcompiled.tmp.h &&\
			echo -e "#endif\n#ifdef SHRINKELF_MCONF" >> minilibcompiled.tmp.h &&\
			cat tools/shrinkelf.mconf >> minilibcompiled.tmp.h &&\
			echo -e "#endif\n" >> minilibcompiled.tmp.h
	cat minilibcompiled.tmp.h | ./tools/removeccomments | sed -E 's/(.*)\/\*.*\*\//\1/' | ./tools/stripblanks | scripts/stripundefs.pl >> minilibcompiled.h
	#cat minilibcompiled.tmp.h | ./tools/removeccomments | sed -E 's/(.*)\/\*.*\*\//\1/' | ./tools/stripblanklines | sed -E '/^#if 0/,/^#endif/d;'s/^\s*//' > minilibcompiled.h
#./tools/scc/scc minilibcompiled.tmp.h | sed '/^\s*$$/d' > minilibcompiled.h
#	gcc -fpreprocessed -P -dD -E minilibcompiled.tmp.h 2>/dev/null > minilibcompiled.h || true
#	cp templates/LICENSE.tmpl minilibcompiled.h
#	scripts/combinesources.pl include/minilib_header.h >> minilibcompiled.h
#	gzip -c minilibcompiled.c > minilibcompiled.c.gz
	sed -i '/^SYSDEF_syscall/d;/^DEF_syscall/d' minilibcompiled.h
	gzip -c minilibcompiled.h > minilibcompiled.h.gz


Makefile.minilib:
	echo generate Makefile.minilib
	sed -i -e 's/^VERSION:=.*/VERSION:=$(NOW)/' Makefile.minilib
	sed -i -e '/^#genconfig_start/r scripts/genconfig.sh' -e '/^#genconfig/p;/^#genconfig/,/^#genconfig/d' Makefile.minilib
	sed -i -e '/^#defaultvalues_start/e sed -n -e "/^#defaultvalues/,/^#defaultvalues/p" minicc' -e '/^#defaultvalues/,/^#defaultvalues/d' Makefile.minilib
	sed -i -e '/^#defaultvalues/,/^#defaultvalues/s/\$$/$$$$/g' Makefile.minilib
	sed -i -e '/^#genconfig/,/^#genconfig/s/\$$/$$$$/g' Makefile.minilib
	sed -i -n -e '0,/^#ldscripts_start/p' Makefile.minilib
	@$(foreach FILE,$(wildcard ldscripts/ld.script*), sh -c "echo define $(FILE) =;cat $(FILE);echo endef;" >> Makefile.minilib; )
	echo "#sha256sums" >> Makefile.minilib
	echo "define sha256sums =" > sign.tmp
	cat Makefile.minilib | sha256sum  | sed 's/\s$$//g' >> sign.tmp
	cat sign.tmp >> Makefile.minilib
	sha256sum minilibcompiled.h >> Makefile.minilib
	echo "endef" >> Makefile.minilib
	#$(foreach FILE,$(wildcard ldscripts/ld.script*), sh -c "echo '#'$(FILE);cat $(FILE);echo '#'$(FILE);" >> Makefile.minilib; )
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
	./minicc --dump-config minilib.conf.all > minilibcfg-syntaxcheck.h
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


