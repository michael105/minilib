


doc: mini-gcc.rst make.rst *.html


make.rst: ../Makefile
	$(shell cd .. && make help > doc/make.rst)
	sed -i -e '1,3s/^\S.*/**\0**/' -e '4,/^help/s/^\S.*/\0/' make.rst


mini-gcc.rst: ../mini-gcc
	../mini-gcc --help > mini-gcc.rst
	sed -i -e '1s/mini-gcc/**\0**/; 2i\\n::\n' -e 's/\(^-.*\)\(:\)\s*$$/\1/' -e 's/^-.*/\0:/' -e "s/^\d040/\\\(/"  -e 's/^\t/  /g' mini-gcc.rst

%.html: %.rst
	rst2html5 -r 5 $< > $@
