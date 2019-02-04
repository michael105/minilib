PROG=vdso

	#strip -R .comment hello

	#strip -R .comment smallest # strip compiler info
	#strip -R .got.plt smallest # strip got section. seems to be a bug (	http://sourceware.org/bugzilla/show_bug.cgi?id=11812 )
	#strip -R .rel.plt smallest # by ld, they are not used for static linking.
	#strip -R .plt smallest # bug at least in ld<3.0



$(PROG): build/$(PROG).o build/minilib.o
	$(LD) $(LDFLAGS) -o $(PROG) build/$(PROG).o build/minilib.o



build/minilib.o: minilib.c minilib.h
	cd minilib/asm && $(MAKE) 
	$(GCC) $(CFLAGS) -c -o build/minilib.o minilib.c 
	

build/$(PROG).o: $(PROG).c
	$(GCC) $(CFLAGS) -c -o build/$(PROG).o $(PROG).c




