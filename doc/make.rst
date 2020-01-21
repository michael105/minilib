**make[1]: Entering directory '/home/micha/prog/minilib'**

**make targets:**

all
  header compile-mini-gcc doc examples test

header
	rebuild header files, also rebuild some of the generated documentation.

doc
	rebuild generated documentation: html files, mini-gcc info

mini-gcc
	rebuild the script mini-gcc, pack ldscripts and config scripts

compile-mini-gcc
	pack the gzipped (complete) minilib into mini-gcc
	(run mini-gcc --dump-minilib to extract the header to stdout)

unpack-mini-gcc
	strip the gzipped minilib of mini-gcc

combined
	compile minilibcompiled.h.gz (single header sourcefile)

tools
	make tools in the dir ./tools
	(shrinkelf)

test
	make and run tests in ./test/

retest
	rebuild the tests in test, (past changes to the tests)
	run make test after that

help
	show this help


Most possibly you'll need: "make compile-mini-gcc", and "make test"
Both run all needed other targets.

However, building with minilib is sort of transparent:
You can include the uncompiled "minilib.h", which will include
all other header files.
And you can include the compiled "minilib.h", as only dependency.

When compiling with mini-gcc, minilib.h will be prepended to the sources,
automatically. Again, when minilib.h is compiled into mini-gcc; these
sources will be used. When minilib.h is present as file, this will be preferred.
(Making development easier - no need to compile mini-gcc every time)

For using a syntaxchecker plugin there's the header file syntaxcheck.h
Just include this, to have all functions, macros and variables, minilib provides,
defined. 
You could either leave the include directive unchanged, when you guard the include
with an 
#ifndef MBLIB
#include "syntaxcheck.h"
#endif

Or, as me with vi syntaxchecker plugin, just add the syntaxcheck header to 
the includes sources of the plugin itself.

;o this whole thing get's more and more complex.
I have to somehow sort and categorize all the documentation.
May the source be with you, and have fun

Michael (misc) Myer, 2012-2020, BSD 3clause
make[1]: Leaving directory '/home/micha/prog/minilib'
