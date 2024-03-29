**make[1]: Entering directory '/home/micha/prog/minilib'**

**make targets:**

all
  header compile-minimake doc examples test
	
examples
	make examples

header
	rebuild header files, also rebuild some of the generated documentation.

doc
	rebuild generated documentation: html files, minimake info

minimake
	rebuild the script minimake, pack ldscripts and config scripts

compile-minimake
	pack the gzipped (complete) minilib into minimake
	(run minimake --dump-minilib to extract the header to stdout)

unpack-minimake
	strip the gzipped minilib of minimake

compiled/minilib.h
	compile compiled/minilib.h, compiled/minilib.h.gz (single header sourcefile)

devel
	make header compiled/minilib.h compile-minimake

tools
	make tools in the dir ./tools
	(shrinkelf)

test
	make and run tests in ./test/

retest
	rebuild the tests in test, 
	run make test after that
	for rebuilding the expected output of the tests as well,
	please have a look into ./test/Makefile

syntaxcheck
  rebuild the file syntaxcheck.h,
  intended to be included for syntaxchecking plugins.
  All declarations of minilib are define there.

help
	show this help


Most possibly you'll need: "make compile-minimake", and "make test"
Both run all needed other targets.

However, building with minilib is sort of transparent:
You can include the uncompiled "minilib.h", which will include
all other header files.
And you can include the compiled "minilib.h", as only dependency.

When compiling with minimake, minilib.h will be prepended to the sources,
automatically. Again, when minilib.h is compiled into minimake; these
sources will be used. When minilib.h is present as file, this will be preferred.
(Making development easier - no need to compile minimake every time)

The included compat headers are not stable yet.
(stdio.h, stdlib.h, ...)
I leave them here. 
But better avoid them. 
Besides sometimes giving trouble, they define the functions and variables of the 
standard libc header files with the same name.
What will give neccessarily some bloat.

For using a syntaxchecker plugin there's the header file syntaxcheck.h
Just include this, to have all functions, macros and variables, minilib provides,
defined. 

To use it, either include it via 
#include "syntaxcheck.h"

Or, as me with vi syntaxchecker plugin, just add the syntaxcheck header to 
the includes sources of the plugin.

For further documentation please have a look into README.asc, and the folder ./doc/

Michael (misc) Myer, 2012-2021, all rights reserved. 
Free use with attribution. Please have a look into 
the file LICENSE for the licensing terms.

echo -ne  # surpress status 
make[1]: Leaving directory '/home/micha/prog/minilib'
