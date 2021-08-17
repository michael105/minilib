PROGS=shrinkelf removeccomments stripblanks

all: $(PROGS)

%: %.c
	../mini-cc -mlc $<

shrinkelf: shrinkelf.c
	../mini-cc --config shrinkelf.mconf -o shrinkelf shrinkelf.c

clean:
	rm $(PROGS)
