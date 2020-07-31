

all: $(patsubst %.asc,html/%.html,$(wildcard *.asc))
	cp index.asc readme.asc

html/%.html: %.html %.asc
	mv $< ./html/

%.html: %.asc
	asciidoc -b html4 $< 
	sed -i -E 's/(href=.*)\.rst/\1.rst.html/g' $@
	sed -i -E 's/\.asc/.html/g' $@
	#sed -i -E 's/(href=.*)\.asc/\1.html/g' $@
	#rm $@e

once: 
	sed -i -E 's/(link:..\/)/\1..\//g' *.asc
	#sed -i -E 's/(link:.*)\.asc/\1.html/g' *.asc
