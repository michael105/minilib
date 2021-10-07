PROGS=shrinkelf removeccomments stripblanks

all: $(PROGS)

%: %.c
	../minicc $<

shrinkelf: shrinkelf.c
	../minicc --config shrinkelf.mconf -o shrinkelf shrinkelf.c

clean:
	rm $(PROGS)
