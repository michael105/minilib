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
	scripts/genheaders.pl ./ minilib/src/*.c minilib/include/*.h

tools:
	cd tools && make

combined: 
	cp templates/LICENSE.tmpl minilibcombined.h
	echo -e "#ifndef minilibcombined_h\n#define minilibcombined_h\n" >> minilibcombined.h && \
			scripts/combinesources.pl minilib.c >> minilibcombined.h && \
			echo "#endif" >> minilibcombined.h
#	cp templates/LICENSE.tmpl minilibcombined.h
#	scripts/combinesources.pl include/minilib_header.h >> minilibcombined.h
#	gzip -c minilibcombined.c > minilibcombined.c.gz
	gzip -c minilibcombined.h > minilibcombined.h.gz


hello-combinedb: hello-combined.c tools
	make SINGLERUN=1 PROG=hello-combined

#note
#cat hello-combined.c | gcc -o hh -static -nostdlib ../asm/start-osx.S -x c -
