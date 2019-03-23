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

header:
	scripts/genheaders.pl ./minilib/generated minilib/src/*.c minilib/include/*.h

tools:
	cd tools && make

combined: 
	cp LICENSE.tmpl minilibcombined.c
	echo -e "#ifndef minilibcombined_c\n#define minilibcombined_c\n" >> minilibcombined.c && \
			tools/combinesources.pl minilib_implementation.c >> minilibcombined.c && \
			echo "#endif" >> minilibcombined.c 
	cp LICENSE.tmpl minilibcombined.h
	tools/combinesources.pl include/minilib_header.h >> minilibcombined.h
	gzip -c minilibcombined.c > minilibcombined.c.gz
	gzip -c minilibcombined.h > minilibcombined.h.gz


hello-combinedb: hello-combined.c tools
	make SINGLERUN=1 PROG=hello-combined

#note
#cat hello-combined.c | gcc -o hh -static -nostdlib ../asm/start-osx.S -x c -
