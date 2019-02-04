
convert: *.asm $(wildcard *.c)
	perl ./convert.pl $?
#
#


convert: start.c

clean:
#	rm *.c

rebuild:
	make clean
	make

start.c: start.asm
	#perl ./convert.pl start.asm
	echo Ok.

