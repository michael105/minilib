


include makefile.template

.PHONY: test combined

test: 
	cd test && make test


combined: 
	tools/combinesources.pl minilib_implementation.c > minilibcombined.c
	tools/combinesources.pl include/minilib_header.h > minilibcombined.h
	gzip -c minilibcombined.c > minilibcombined.c.gz
	gzip -c minilibcombined.h > minilibcombined.h.gz

#note
#cat hello-combined.c | gcc -o hh -static -nostdlib ../asm/start-osx.S -x c -
