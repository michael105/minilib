**make[1]: Entering directory '/home/micha/prog/minilib'**

**make targets:**

all
  header compile-minicc doc examples test
	
examples
	make examples

header
	rebuild header files, also rebuild some of the generated documentation.

doc
	rebuild generated documentation: html files, minicc info

minicc
	rebuild the script minicc, pack ldscripts and config scripts

compile-minicc
	pack the gzipped (complete) minilib into minicc
	(run minicc --dump-minilib to extract the header to stdout)

unpack-minicc
	strip the gzipped minilib of minicc

combined
	compile minilibcompiled.h, minilibcompiled.h.gz (single header sourcefile)

devel
	make header combined compile-minicc

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


Most possibly you'll need: "make compile-minicc", and "make test"
Both run all needed other targets.

However, building with minilib is sort of transparent:
You can include the uncompiled "minilib.h", which will include
all other header files.
And you can include the compiled "minilib.h", as only dependency.

When compiling with minicc, minilib.h will be prepended to the sources,
automatically. Again, when minilib.h is compiled into minicc; these
sources will be used. When minilib.h is present as file, this will be preferred.
(Making development easier - no need to compile minicc every time)

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
make[1]: Leaving directory '/home/micha/prog/minilib'
