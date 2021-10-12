PROGS=shrinkelf removeccomments stripblanks

all: $(PROGS)

%: %.c
	../minimake $<

shrinkelf: shrinkelf.c
	../minimake --config shrinkelf.mconf

clean:
	rm $(PROGS)
