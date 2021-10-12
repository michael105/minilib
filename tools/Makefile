PROGS=shrinkelf removeccomments stripblanks

all: $(PROGS)

%: %.c
	../minimake $<

shrinkelf: shrinkelf.c
	../minimake --config shrinkelf.mconf -o shrinkelf shrinkelf.c

clean:
	rm $(PROGS)
