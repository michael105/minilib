ifndef PROG
PROG=hello
endif

ONLYTEXT=1
NOINCLUDE=1


include Makefile.template

.PHONY: test combined header tools



test: 
	cd test && make test

retest: 
	cd test && make retest

tools:
	cd tools && make

combined: 
	cp templates/LICENSE.tmpl minilibcompiled.h
	echo -e "#ifndef minilibcompiled_h\n#define minilibcompiled_h\n" >> minilibcompiled.h && \
			scripts/combinesources.pl minilib.c >> minilibcompiled.h && \
			echo "#endif" >> minilibcompiled.h
#	cp templates/LICENSE.tmpl minilibcompiled.h
#	scripts/combinesources.pl include/minilib_header.h >> minilibcompiled.h
#	gzip -c minilibcompiled.c > minilibcompiled.c.gz
	gzip -c minilibcompiled.h > minilibcompiled.h.gz


hello-combinedb: hello-combined.c tools
	make SINGLERUN=1 PROG=hello-combined

#note
#cat hello-combined.c | gcc -o hh -static -nostdlib ../asm/start-osx.S -x c -
