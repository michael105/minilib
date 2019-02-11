
#convert: *.asm $(wildcard *.c)
#	perl ./convert.pl $?
#
#


convert: start.c start-osx.c

clean:
#	rm *.c

rebuild:
	make clean
	make

start.c: start.S
	perl ./convert.pl start.S start.c
	echo Ok.
	
start-osx.c: start-osx.S
	perl ./convert.pl start-osx.S start-osx.c
	echo Ok.

