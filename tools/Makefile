PROGS=shrinkelf removeccomments stripblanklines

all: $(PROGS)

%: %.c
	../mini-gcc -mlc $<

shrinkelf: shrinkelf.c
	../mini-gcc --config shrinkelf.mconf -o shrinkelf shrinkelf.c

clean:
	rm $(PROGS)
