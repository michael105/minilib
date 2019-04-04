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
	$(shell ( echo "// generated by make header. " &&\
			echo "// all macros and functions, defined by minilib." &&\
			echo "// intended to be parsed by (my) syntaxchecker plugin" &&\
			echo '#ifndef minilib_h' &&\
			./mini-gcc --config minilib.conf.all -E minilib.h  -dD | sed -e '/^# /d' -e '/^$$/d' &&\
			echo "#endif" )\
			> syntaxcheck.h )

mini-gcc: scripts/genconfig.sh ldscript
	@echo dbg. var: $^ 


ldscript: ldscripts/ld.script*
	@echo dbg, ldscripts. var: $^ 


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
