

all: $(patsubst %.asc,html/%.html,$(wildcard *.asc))

html/%.html: %.html %.asc
	mv $< ./html/

%.html: %.asc
	asciidoc -b html4 $< 
	sed -i -E 's/(href=.*)\.rst/\1.rst.html/' $@
	sed -i -E 's/(href=.*)\.asc/\1.html/' $@
	#rm $@e


