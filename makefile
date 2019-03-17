PROG=hello
ONLYTEXT=1

include makefile.template

.PHONY: test combined

test: 
	cd test && make test


combined: 
	cd asm && make
	cp LICENSE.tmpl minilibcombined.c
	echo -e "#ifndef minilibcombined_c\n#define minilibcombined_c\n" >> minilibcombined.c && \
			tools/combinesources.pl minilib_implementation.c >> minilibcombined.c && \
			echo "#endif" >> minilibcombined.c 
	#cat asm/start.c asm/start-osx.c >> minilibcombined.c && 
	cp LICENSE.tmpl minilibcombined.h
	tools/combinesources.pl include/minilib_header.h >> minilibcombined.h
	gzip -c minilibcombined.c > minilibcombined.c.gz
	gzip -c minilibcombined.h > minilibcombined.h.gz


hello-combinedb: hello-combined.c
	make PROG=hello-combined

#note
#cat hello-combined.c | gcc -o hh -static -nostdlib ../asm/start-osx.S -x c -
