ifndef PROG
#PROG=examples/hello
endif

ifndef RECURSE
#$(info Type 'make help' for help)
RECURSE=1
endif

ONLYTEXT=1
NOINCLUDE=1

NOW=$(shell echo `date '+%F %T'` )
#NOW=$(shell echo `date +%F` r$$[ `date +%s` - 1579400000 ] )

#include Makefile.template

.PHONY: test combined header tools

define HELP

make targets:

all
  header compile-mini-gcc doc examples test
	
examples
	make examples

header
	rebuild header files, also rebuild some of the generated documentation.

doc
	rebuild generated documentation: html files, mini-gcc info

mini-gcc
	rebuild the script mini-gcc, pack ldscripts and config scripts

compile-mini-gcc
	pack the gzipped (complete) minilib into mini-gcc
	(run mini-gcc --dump-minilib to extract the header to stdout)

unpack-mini-gcc
	strip the gzipped minilib of mini-gcc

combined
	compile minilibcompiled.h, minilibcompiled.h.gz (single header sourcefile)

devel
	make header combined compile-mini-gcc

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

help
	show this help


Most possibly you'll need: "make compile-mini-gcc", and "make test"
Both run all needed other targets.

However, building with minilib is sort of transparent:
You can include the uncompiled "minilib.h", which will include
all other header files.
And you can include the compiled "minilib.h", as only dependency.

When compiling with mini-gcc, minilib.h will be prepended to the sources,
automatically. Again, when minilib.h is compiled into mini-gcc; these
sources will be used. When minilib.h is present as file, this will be preferred.
(Making development easier - no need to compile mini-gcc every time)

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

Michael (misc) Myer, 2012-2020, BSD 3clause
endef

help:
	$(info $(HELP)) 
	@echo -ne  # surpress status 



default: help

all: header combined compile-mini-gcc doc examples test syntaxcheck

devel: header combined compile-mini-gcc 

examples:
	cd examples && make

test: 
	cd test && make test

retest: 
	cd test && make retest

header:
	cd headers && make
	scripts/genheaders.pl ./ minilib/src/*.c minilib/include/*.h minilib/src/dirent/*.c minilib/macros/*.h
			rm minilib.conf.tmp minilib.conf.all.tmp minilib.genconf.h.tmp

# ./mini-gcc --config minilib.conf.all -E minilib.h -Wno-all -dD | sed -e 's/^# /\/\/ /;/^$$/d;/^[[:space:]]*from/d;/^\.\//,2d' &&\

doc: header
	cd doc && make

mini-gcc: scripts/genconfig.sh ldscript
	@echo dbg. var: $^ 
	scripts/template.pl mini-gcc genconfig scripts/genconfig.sh
	scripts/template.pl mini-gcc genconf-macros minilib.genconf.h
	scripts/template.pl mini-gcc headerguards include/headerguards.h
	sed -ie 's/^VERSION=.*/VERSION="GIT $(NOW)"/' mini-gcc
	rm mini-gcce


compile-mini-gcc: mini-gcc unpack-mini-gcc
	gzip -c minilibcompiled.h >> mini-gcc

unpack-mini-gcc:
	sed '/^#MINILIBGZ#$$/q' mini-gcc > mini-gcc.tmp
	cp mini-gcc.tmp mini-gcc
	rm mini-gcc.tmp


ldscript: ldscripts/ld.script*
	@echo dbg, ldscripts. var: $^ 
	echo "# Parsing" | scripts/template.pl mini-gcc content-ldscript
	sh scripts/ldscripts.sh $^ 


			#echo -n "$(FILE)" | sed -e "s/.*\///" -e "s/\./_/g" && echo "='" | scripts/template.pl -insert mini-gcc content-ldscript; echo J ) )  
	
	#| scripts/template.pl -insert mini-gcc content-ldscript )  )   

tools:
	cd tools && make

combined: tools
	cp templates/LICENSE.tmpl minilibcompiled.h
	echo -e "#ifndef minilibcompiled_h\n#define minilibcompiled_h\n" > minilibcompiled.tmp.h && \
			scripts/combinesources.pl minilib.h >> minilibcompiled.tmp.h && \
			echo "#endif" >> minilibcompiled.tmp.h
	cat minilibcompiled.tmp.h | ./tools/removeccomments | sed -E 's/(.*)\/\*.*\*\//\1/' | ./tools/stripblanks | scripts/stripundefs.pl >> minilibcompiled.h
	#cat minilibcompiled.tmp.h | ./tools/removeccomments | sed -E 's/(.*)\/\*.*\*\//\1/' | ./tools/stripblanklines | sed -E '/^#if 0/,/^#endif/d;'s/^\s*//' > minilibcompiled.h
#./tools/scc/scc minilibcompiled.tmp.h | sed '/^\s*$$/d' > minilibcompiled.h
#	gcc -fpreprocessed -P -dD -E minilibcompiled.tmp.h 2>/dev/null > minilibcompiled.h || true
#	cp templates/LICENSE.tmpl minilibcompiled.h
#	scripts/combinesources.pl include/minilib_header.h >> minilibcompiled.h
#	gzip -c minilibcompiled.c > minilibcompiled.c.gz
	gzip -c minilibcompiled.h > minilibcompiled.h.gz


hello-combinedb: hello-combined.c tools
	make SINGLERUN=1 PROG=hello-combined

#note
#cat hello-combined.c | gcc -o hh -static -nostdlib ../asm/start-osx.S -x c -


gitlog:
	git log | sed '/^commit/d;/^Author/d;/^Merge/d;s/^Date:/####/' > gitlog.md


syntaxcheck: 
	$(shell cp templates/syntaxcheck.h.top ./syntaxcheck.h) 
	$(shell ( ./mini-gcc --config minilib.conf.all -E minilib.h -Wno-all -DGENSYNTAXCHECK -dD | sed -e 's/^# /\/\/ /;/^$$/d' | sed '/stdc-predef/,/command-line/d;/<built-in>/,/\/\/ /d;/^SYSDEF/d' &&\
			cat templates/syntaxcheck.h.bottom ) |\
			sed -E '/optimization_fence/d;/^static.*\{$$/,/^\}$$/{s/(^static.*)\{/\1;/p;d}' | sed -E '/^const.*\{$$/,/^\}$$/{s/(^const.*)\{/\1;/p;d}' >> syntaxcheck.h )
	
