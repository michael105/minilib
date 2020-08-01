

doc: mini-gcc.rst make.rst html/*.html html/minilib-reference.html reference

reference: minilib-reference.asc
	cd reference && make once && make

minilib-reference.asc: templates/minilib-reference.asc.top build/minilib-reference.in build/minilib-reference.sortme.1
	./scripts/makereference.pl

html/minilib-reference.html: minilib-reference.asc
	 asciidoc -b html4 -n minilib-reference.asc && mv minilib-reference.html ./html/

# copy after changes build/minilib-reference.in.2 to minilib-reference.sortme.1
# minilib-reference.sortme.1 is for getting sorted into the categories by hand.
# build/minilib-reference.in.2 is there for not overwriting the file sortme,
# and possibly abort compilation.


make.rst: ../Makefile
	$(shell cd .. && make help > doc/make.rst)
	sed -i -e '1,3s/^\S.*/**\0**/' -e '4,/^help/s/^\S.*/\0/' make.rst


mini-gcc.rst: ../mini-gcc
	../mini-gcc --help > mini-gcc.rst
	sed -i -e '1s/mini-gcc/**\0**/; 2i\\n::\n' -e 's/\(^-.*\)\(:\)\s*$$/\1/' -e 's/^-.*/\0:/' -e "s/^\d040/\\\(/"  -e 's/^\t/  /g' mini-gcc.rst

html/%.html: %.rst
	rst2html5 -r 5 $< > $@

html/mlfunctions-shortref.html: mlfunctions-shortref.asc
	asciidoc -b html4 -n mlfunctions-shortref.asc
	sed -ie 's/.rst/.rst.html/' mlfunctions-shortref.html
	mv mlfunctions-shortref.html ./html/

html/README.html: README.md
	@echo "<html><body>" > README.html
	markdown -html5 README.md >> README.html
	@echo "</body></html>" >> README.html
	sed -i -e 's/\(href="m[^.]*\)\.[a|r]../\1.html/' README.html
	mv README.html ./html/

