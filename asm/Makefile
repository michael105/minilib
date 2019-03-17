
#convert: *.asm $(wildcard *.c)
#	perl ./convert.pl $?
#
#


convert: start.c start-osx.c start-linux-x64.c

clean:
#	rm *.c

rebuild:
	make clean
	make

start.c: start.S
	perl ../tools/convertasm.pl start.S start.c
	echo Ok.
	
start-osx.c: start-osx.S
	perl ../tools/convertasm.pl start-osx.S start-osx.c
	echo Ok.

start-linux-x64.c: start-linux-x64.S
	perl ../tools/convertasm.pl start-linux-x64.S start-linux-x64.c
	echo Ok.
	
