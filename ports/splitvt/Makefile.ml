# This Makefile has been generated from the Configure script.
# Shareware copyright 1993, by Sam Lantinga


#CC = gcc
CC = $(pm)/mini-gcc --config minilib.mconf
PTYCHAR=\"\"
HEXDIGIT=\"\"
PTYOPTS = -DPTYCHAR=$(PTYCHAR) -DHEXDIGIT=$(HEXDIGIT)

CFLAGS =  -Os -DHAVE_UTHOST -DHAVE_TERMIO_H -DHAVE_UNISTD_H -DNEED_SELECT_H -DHAVE_WAIT4 -DSHELL=\"/bin/sh\" $(PTYOPTS) -static
LIBS = 
OBJS = videomem.o terminal.o vtmouse.o 
#OBJS = splitvt.o videomem.o terminal.o vtmouse.o 
#OBJS = splitvt.o misc.o vt100.o videomem.o terminal.o vtmouse.o
      # cut-paste.o

splitvt: $(OBJS) misc.c vt100.c
	#musl-gcc -o splitvt *.o -static -s -Os
	$(pm)/mini-gcc --config minilib.mconf -s -o $@ splitvt.c $(OBJS) $(LIBS) -DINCLUDESRC $(CFLAGS)

clean: 
	rm -f *.o core 

distclean: clean
	rm -f splitvt Makefile

install: install-man
	mv splitvt /usr/local/bin/splitvt
	mv examples/xsplitvt /usr/local/bin/xsplitvt

install-man:
	cp splitvt.man /usr/local/man/man1/splitvt.1
